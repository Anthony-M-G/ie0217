#ifndef POSTS_SERVICES_H
#define POSTS_SERVICES_H

#include "../database/MongodbConn.h"
#include <bsoncxx/builder/stream/document.hpp>
#include <bsoncxx/json.hpp>
#include <ctime>
#include <mongocxx/client.hpp>
#include <mongocxx/instance.hpp>
#include <string>

/**
 * @class PostsServices
 * @brief Clase que maneja las operaciones relacionadas con las publicaciones en
 * una red social.
 *
 * La clase `PostsServices` proporciona métodos para gestionar publicaciones
 * en una base de datos MongoDB, permitiendo insertar, consultar, actualizar,
 * eliminar publicaciones, y manejar comentarios.
 */
class PostsServices {
public:
  /**
   * @brief Constructor por defecto.
   *
   * Inicializa un nuevo servicio de publicaciones.
   */
  PostsServices() = default;

  /**
   * @brief Obtiene todas las publicaciones.
   *
   * Recupera todas las publicaciones de la base de datos.
   */
  void getPosts();

  /**
   * @brief Inserta una nueva publicación en la base de datos.
   *
   * @param author El nombre del autor de la publicación.
   * @param content El contenido de la publicación.
   */
  void insertPost(const std::string &author, const std::string &content);

  /**
   * @brief Obtiene publicaciones de un autor específico.
   *
   * @param author El nombre del autor cuyas publicaciones se desean obtener.
   */
  void getPostsByAuthor(const std::string &author);

  /**
   * @brief Obtiene publicaciones ordenadas por fecha.
   *
   * @param date La fecha utilizada para ordenar las publicaciones.
   */
  void getPostsOrderedByDate(const std::string &date);

  /**
   * @brief Agrega un comentario a una publicación existente.
   *
   * @param author El nombre del autor de la publicación.
   * @param date La fecha de la publicación.
   * @param username El nombre de usuario que agrega el comentario.
   * @param content El contenido del comentario.
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
   */
  void updatePostContent(const std::string &author, const std::string &date,
                         const std::string &newContent);

  /**
   * @brief Elimina una publicación por autor y fecha.
   *
   * @param author El nombre del autor de la publicación.
   * @param date La fecha de la publicación.
   */
  void deletePostByAuthorAndDate(const std::string &author,
                                 const std::string &date);

  /**
   * @brief Marca una publicación como destacada.
   *
   * @param author El nombre del autor de la publicación.
   * @param date La fecha de la publicación.
   */
  void markPostAsFeatured(const std::string &author, const std::string &date);

private:
  MongoConnection mongo_conn_; ///< Conexión a la base de datos MongoDB.
};

#endif // POSTS_SERVICES_H
