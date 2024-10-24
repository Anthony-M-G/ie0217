#include "../../includes/database/MongodbConn.h"
#include "mongocxx/collection-fwd.hpp"
#include "mongocxx/database-fwd.hpp"

// Constructor
MongoConnection::MongoConnection()
    : client_{mongocxx::uri{
          // Inicialización de la conexión a la base de datos con la URI de
          // conexión definida
          "mongodb+srv://antony:<contraseña>@cluster0.kao1onk.mongodb.net/"
          "?retryWrites=true&w=majority&appName=Cluster0"}},
      db_{client_["social_network"]}, instance_{} {
  std::cout << "Conexión a MongoDB establecida." << std::endl;
}

// Método para obtener una colección
mongocxx::collection MongoConnection::getCollection(
    const std::string &collection_name) { // Función para obtener una colección
                                          // según el nombre de la misma
  return this->db_[collection_name];
}

// Destructor
MongoConnection::~MongoConnection() {
  std::cout << "Conexión a MongoDB cerrada." << std::endl;
}
