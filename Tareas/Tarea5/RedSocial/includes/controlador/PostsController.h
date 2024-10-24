#ifndef POSTS_CONTROLLER_H
#define POSTS_CONTROLLER_H
#include "../servicios/PostsServices.h"
#include <string>

/**
 * @class PostsController
 * @brief Controlador para manejar las solicitudes relacionadas con las
 * publicaciones.
 *
 * La clase `PostsController` es responsable de recibir y procesar solicitudes
 * para gestionar las publicaciones en la red social. Llama a los métodos de
 * `PostsServices` para interactuar con la base de datos.
 */
class PostsController {
private:
  PostsServices postsServices; ///< Servicio que maneja la lógica de negocio de
                               ///< las publicaciones.

public:
  /**
   * @brief Constructor por defecto.
   *
   * Inicializa un nuevo controlador de publicaciones.
   */
  PostsController() = default;

  /**
   * @brief Destructor por defecto.
   *
   * Destruye el controlador de publicaciones.
   */
  ~PostsController() = default;

  /**
   * @brief Obtiene todas las publicaciones.
   *
   * Llama al servicio para recuperar todas las publicaciones de la base de
   * datos.
   */
  void getPosts();

  /**
   * @brief Inserta una nueva publicación.
   *
   * @param author El nombre del autor de la publicación.
   * @param content El contenido de la publicación.
   *
   * Llama al servicio para insertar una nueva publicación en la base de datos.
   */
  void insertPost(const std::string &author, const std::string &content);

  /**
   * @brief Obtiene publicaciones por autor.
   *
   * @param author El nombre del autor cuyas publicaciones se desean obtener.
   *
   * Llama al servicio para recuperar las publicaciones de un autor específico.
   */
  void getPostsByAuthor(const std::string &author);

  /**
   * @brief Obtiene publicaciones ordenadas por fecha.
   *
   * @param date La fecha utilizada para ordenar las publicaciones.
   *
   * Llama al servicio para obtener publicaciones ordenadas cronológicamente.
   */
  void getPostsOrderedByDate(const std::string &date);

  /**
   * @brief Agrega un comentario a una publicación existente.
   *
   * @param author El nombre del autor de la publicación.
   * @param date La fecha de la publicación.
   * @param username El nombre de usuario que agrega el comentario.
   * @param content El contenido del comentario.
   *
   * Llama al servicio para agregar un comentario a una publicación.
   */
  void addCommentToPost(const std::string &author, const std::string &date,
                        const std::string &username,
                        const std::string &content);

  /**
   * @brief Actualiza el contenido de una publicación por autor y fecha.
   *
   * @param author El nombre del autor de la publicación.
   * @param date La fecha de la publicación.
   * @param newContent El nuevo contenido para la publicación.
   *
   * Llama al servicio para actualizar el contenido de una publicación.
   */
  void updatePostContent(const std::string &author, const std::string &date,
                         const std::string &newContent);

  /**
   * @brief Elimina una publicación por autor y fecha.
   *
   * @param author El nombre del autor de la publicación.
   * @param date La fecha de la publicación.
   *
   * Llama al servicio para eliminar una publicación específica de la base de
   * datos.
   */
  void deletePostByAuthorAndDate(const std::string &author,
                                 const std::string &date);

  /**
   * @brief Marca una publicación como destacada.
   *
   * @param author El nombre del autor de la publicación.
   * @param date La fecha de la publicación.
   *
   * Llama al servicio para marcar una publicación como destacada.
   */
  void markPostAsFeatured(const std::string &author, const std::string &date);
};

#endif // POSTS_CONTROLLER_H
