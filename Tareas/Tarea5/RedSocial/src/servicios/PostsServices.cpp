#include "../../includes/servicios/PostsServices.h"
#include "./Utils.h"

void PostsServices::getPosts() { // Método para obtener todas las publicaciones
  try {
    auto posts = this->mongo_conn_.getCollection("posts").find(
        {}); // Obtener todas las publicaciones de la colección 'posts'
    if (posts.begin() == posts.end()) { // Verificar si no hay publicaciones
      throw std::runtime_error(
          "No hay publicaciones."); // Lanzar una excepción si no hay
                                    // publicaciones
      return;
    }
    postsView(posts); // Abstracción para mayor claridad en el código a la hora
                      // de imprimir en consola las publicaciones
  } catch (const std::exception &e) {
    std::cerr << e.what() << std::endl;
  }
}
void PostsServices::insertPost(
    const std::string &author,
    const std::string &content) { // Método para insertar una nueva publicación
  try {
    if (author.empty() ||
        content.empty()) { // Validación de campos obligatorios
      throw std::runtime_error(
          "Todos los campos son obligatorios."); // Lanzar una excepción si no
                                                 // se proporcionan todos los
                                                 // campos
      return;
    }

    auto builder = bsoncxx::builder::stream::document{}; // Crear un constructor
                                                         // de documentos BSON
    bsoncxx::document::value doc =
        builder
        << "autor" << author << "contenido" << content
        << "fecha" // Crear un documento BSON con los campos proporcionados
        << getCurrentDate() << "comentarios"
        << bsoncxx::builder::stream::open_array
        << bsoncxx::builder::stream::close_array
        << bsoncxx::builder::stream::finalize; // Finalizar la construcción del
                                               // documento

    auto result = this->mongo_conn_.getCollection("posts").insert_one(
        doc.view()); // Insertar el documento en la colección 'posts'

    std::cout << "Publicación creada con ID: "
              << result->inserted_id().get_oid().value.to_string() << std::endl;

  } catch (const std::exception &e) {
    std::cerr << "Error al crear post: " << e.what() << std::endl;
  }
}

void PostsServices::getPostsByAuthor(const std::string &author) {
  try {
    mongocxx::cursor posts =
        this->mongo_conn_.getCollection("posts")
            .find( // Obtener las publicaciones por autor de la colección
                   // 'posts'
                bsoncxx::builder::stream::document{}
                // se pasa como parametro de find un documento BSON con el campo
                // 'autor' y el valor proporcionado
                << "autor" << author << bsoncxx::builder::stream::finalize);
    if (posts.begin() == posts.end()) {
      throw std::runtime_error(
          "No hay publicaciones para el autor proporcionado."); // Lanzar una
                                                                // excepción si
                                                                // no hay
                                                                // publicaciones
                                                                // para el autor
      return;
    }
    postsView(posts); // Abstracción para mayor claridad en el código a la hora
                      // de imprimir en consola las publicaciones

  } catch (const std::exception &e) {
    std::cerr << "Error al obtener publicaciones por autor: " << e.what()
              << std::endl;
  }
}

void PostsServices::getPostsOrderedByDate(const std::string &date) {

  try {
    auto posts = this->mongo_conn_.getCollection("posts").find(
        bsoncxx::builder::stream::document{}
        // Obtener las publicaciones por fecha de la colección 'posts' pasando
        // como parametro un documento BSON con el campo 'fecha' y el valor
        // proporcionado
        << "fecha" << date << bsoncxx::builder::stream::finalize);
    if (posts.begin() == posts.end()) {
      throw std::runtime_error(
          "No hay publicaciones para la fecha proporcionada.");
      return;
    }
    postsView(posts);

  } catch (const std::exception &e) {
    std::cerr << "Error al obtener publicaciones por fecha: " << e.what()
              << std::endl;
  }
}

void PostsServices::addCommentToPost(const std::string &author,
                                     const std::string &date,
                                     const std::string &username,
                                     const std::string &content) {
  try {
    if (author.empty() || date.empty() || username.empty() ||
        content.empty()) { // Validación de campos obligatorios
      std::cerr << "Error: Todos los campos son obligatorios." << std::endl;
      return;
    }

    // Buscar el post por autor y fecha
    auto post_result = this->mongo_conn_.getCollection("posts").find_one(
        bsoncxx::builder::stream::document{}
        << "autor" << author << "fecha" << date
        << bsoncxx::builder::stream::finalize); // Obtiene el post por autor y
                                                // fecha

    if (!post_result) {
      throw std::runtime_error(
          "No se encontró el post para el autor y la fecha proporcionados.");
      return;
    }

    // Crear el documento del comentario
    auto builder = bsoncxx::builder::stream::document{};
    bsoncxx::document::value comment_doc =
        builder
        << "postId"
        << post_result->view()["_id"]
               .get_oid() // Le asigan el id del post al campo 'postId'
        << "username" << username << "content" << content << "date"
        << getCurrentDate()
        << bsoncxx::builder::stream::finalize; // La funcion getCurrentDate()
                                               // retorna la fecha actual en
                                               // formato dd/mm/yyyy
    // Insertar el comentario en la colección 'comments'
    auto add_comment =
        this->mongo_conn_.getCollection("comments")
            .insert_one(comment_doc.view()); // Insertar el
                                             // comentario en la
                                             // colección 'comments'
    if (!add_comment) {
      throw std::runtime_error("Error al agregar comentario.");
      return;
    }

    // Actualizar el post, agregando el comentario al array 'comentarios'
    auto result = this->mongo_conn_.getCollection("posts").update_one(
        bsoncxx::builder::stream::document{}
            << "_id" << post_result->view()["_id"].get_oid()
            << bsoncxx::builder::stream::finalize,
        bsoncxx::builder::stream::document{}
            // Actualiza el post agregando el comentario al array 'comentarios'
            << "$push" << bsoncxx::builder::stream::open_document
            << "comentarios"
            << comment_doc
                   .view() // comment_doc contiene el comentario a agregar en
                           // formato BSON document y el metodo view() lo
                           // convierte a BSON document view
            << bsoncxx::builder::stream::close_document // Cierre del documento
            << bsoncxx::builder::stream::finalize);

    if (result &&
        result->modified_count() > 0) { // Verificar si se ha modificado el post
      std::cout << "Comentario añadido con éxito." << std::endl;
    } else {
      throw std::runtime_error("Error al agregar comentario.");
    }
  } catch (const std::exception &e) {
    std::cerr << e.what() << std::endl;
  }
}

void PostsServices::updatePostContent(const std::string &author,
                                      const std::string &date,
                                      const std::string &newContent) {
  try {
    if (author.empty() || date.empty() || newContent.empty()) {
      throw std::runtime_error("Todos los campos son obligatorios.");
    }

    // Buscar el post por autor y fecha
    auto post_result = this->mongo_conn_.getCollection("posts").find_one(
        bsoncxx::builder::stream::document{}
        << "autor" << author << "fecha" << date
        << bsoncxx::builder::stream::finalize); // Obtiene el post por autor y
                                                // fecha

    if (!post_result) { // Verificar si no se ha encontrado el post
      throw std::runtime_error(
          "No se encontró el post para el autor y la fecha proporcionados.");
      return;
    }

    // Actualizar el contenido del post
    auto result = this->mongo_conn_.getCollection("posts").update_one(
        bsoncxx::builder::stream::document{}
            << "_id" << post_result->view()["_id"].get_oid()
            << bsoncxx::builder::stream::finalize,
        bsoncxx::builder::stream::document{}
            << "$set" << bsoncxx::builder::stream::open_document << "contenido"
            << newContent << bsoncxx::builder::stream::close_document
            << bsoncxx::builder::stream::finalize);

    if (result && result->modified_count() < 0) {
      throw std::runtime_error("Error al actualizar contenido.");
      return;
    }
    std::cout << "Contenido actualizado con éxito." << std::endl;
  } catch (const std::exception &e) {
    std::cerr << e.what() << std::endl;
  }
}

void PostsServices::deletePostByAuthorAndDate(const std::string &author,
                                              const std::string &date) {
  try {
    if (author.empty() || date.empty()) {
      throw std::runtime_error("Todos los campos son obligatorios.");

      return;
    }

    // Buscar el post por autor y fecha
    auto post_result = this->mongo_conn_.getCollection("posts")
                           .find_one( // Obtiene el post por autor y fecha
                               bsoncxx::builder::stream::document{}
                               << "autor" << author << "fecha" << date
                               << bsoncxx::builder::stream::finalize);

    if (!post_result) {
      throw std::runtime_error(
          "No se encontró el post para el autor y la fecha proporcionados.");
      return;
    }
    // Eliminar los comentarios asociados a ese post
    auto delete_comments =
        this->mongo_conn_.getCollection("comments")
            .delete_many(bsoncxx::builder::stream::document{}
                         // Elimina todos los que tengan el campo 'postId' con
                         // el valor del id del post
                         << "postId" << post_result->view()["_id"].get_oid()
                         << bsoncxx::builder::stream::finalize);

    // Eliminar el post
    auto result = this->mongo_conn_.getCollection("posts").delete_one(
        bsoncxx::builder::stream::document{}
        << "_id" << post_result->view()["_id"].get_oid()
        << bsoncxx::builder::stream::finalize);

    if (result && result->deleted_count() < 0) {
      throw std::runtime_error("Error al eliminar publicación.");
      return;
    }
    std::cout << "Publicación eliminada con éxito." << std::endl;
  } catch (const std::exception &e) {
    std::cerr << e.what() << std::endl;
  }
}

void PostsServices::markPostAsFeatured(const std::string &author,
                                       const std::string &date) {
  bool isFeatured = true;
  try {
    auto postAddIsFeatured =
        this->mongo_conn_.getCollection("posts").update_one(
            bsoncxx::builder::stream::document{}
                << "autor" << author << "fecha" << date
                << bsoncxx::builder::stream::finalize,
            bsoncxx::builder::stream::document{}
                << "$set" << bsoncxx::builder::stream::open_document
                << "esDestacado" << isFeatured
                << bsoncxx::builder::stream::close_document
                << bsoncxx::builder::stream::finalize);
    if (postAddIsFeatured && postAddIsFeatured->modified_count() > 0) {
      std::cout << "Publicación marcada como destacada." << std::endl;
    } else {
      std::cerr << "Error al marcar la publicación como destacada."
                << std::endl;
    }
  } catch (const std::exception &e) {
    std::cerr << "Error al marcar la publicación como destacada: " << e.what()
              << std::endl;
  }
}
