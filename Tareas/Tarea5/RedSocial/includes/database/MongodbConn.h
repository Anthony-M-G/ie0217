#ifndef MONGODB_CONN_H
#define MONGODB_CONN_H

#include "mongocxx/collection-fwd.hpp"
#include <mongocxx/client.hpp>
#include <mongocxx/collection.hpp>
#include <mongocxx/database.hpp>
#include <mongocxx/instance.hpp>
#include <mongocxx/uri.hpp>
#include <mongocxx/v_noabi/mongocxx/client.hpp>
#include <mongocxx/v_noabi/mongocxx/database.hpp>
#include <mongocxx/v_noabi/mongocxx/instance.hpp>

using namespace mongocxx;

/**
 * @class MongoConnection
 * @brief Esta clase maneja la conexión a una base de datos MongoDB y
 * proporciona métodos para interactuar con ella.
 *
 * La clase `MongoConnection` se encarga de inicializar la instancia de MongoDB,
 * crear el cliente para conectarse a la base de datos y proporcionar acceso a
 * las colecciones de la base de datos.
 */
class MongoConnection {
public:
  /**
   * @brief Constructor de la clase MongoConnection.
   *
   * Inicializa una nueva instancia de MongoDB y establece la conexión con la
   * base de datos.
   */
  MongoConnection();

  /**
   * @brief Obtiene una colección específica de la base de datos.
   *
   * @param collection_name El nombre de la colección a la que se desea acceder.
   * @return Un objeto `mongocxx::collection` que representa la colección.
   */
  mongocxx::collection getCollection(const std::string &collection_name);

  /**
   * @brief Destructor de la clase MongoConnection.
   *
   * Cierra la conexión a la base de datos y limpia los recursos utilizados.
   */
  ~MongoConnection();

private:
  mongocxx::instance
      instance_; ///< Instancia de MongoDB para iniciar la biblioteca.
  mongocxx::client client_; ///< Cliente que maneja la conexión a MongoDB.
  mongocxx::database db_;   ///< Base de datos MongoDB.
};

#endif // MONGODB_CONN_H
