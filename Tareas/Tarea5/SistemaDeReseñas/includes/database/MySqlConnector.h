#ifndef MYSQLCONNECTOR_H_
#define MYSQLCONNECTOR_H_

#include <iostream>
using namespace std;

#include <mysql_connection.h>
#include <mysql_driver.h>

/**
 * @class MySQLConnector
 * @brief Clase para manejar la conexión a una base de datos MySQL.
 *
 * Esta clase proporciona métodos para establecer y obtener una conexión a una base de datos MySQL.
 * Utiliza el controlador MySQL de la biblioteca `mysqlcppconn`.
 *
 * @note Asegúrese de tener la biblioteca `mysqlcppconn` correctamente instalada y configurada.
 *
 * @var sql::mysql::MySQL_Driver* MySQLConnector::driver
 * Puntero al controlador MySQL.
 *
 * @var sql::Connection* MySQLConnector::connection
 * Puntero a la conexión de la base de datos.
 *
 * @var std::string MySQLConnector::host
 * Dirección del host de la base de datos.
 *
 * @var std::string MySQLConnector::user
 * Nombre de usuario para la conexión a la base de datos.
 *
 * @var std::string MySQLConnector::password
 * Contraseña para la conexión a la base de datos.
 *
 * @var std::string MySQLConnector::database
 * Nombre de la base de datos a la que se conectará.
 *
 * @fn MySQLConnector::MySQLConnector()
 * @brief Constructor de la clase MySQLConnector.
 *
 * Inicializa los parámetros necesarios para establecer una conexión a la base de datos.
 *
 * @fn sql::Connection* MySQLConnector::getConnection()
 * @brief Obtiene la conexión a la base de datos.
 *
 * @return Puntero a la conexión de la base de datos.
 *
 * @fn MySQLConnector::~MySQLConnector()
 * @brief Destructor de la clase MySQLConnector.
 *
 * Libera los recursos asociados con la conexión a la base de datos.
 */
class MySQLConnector {
private:
  sql::mysql::MySQL_Driver *driver;
  sql::Connection *connection;
  string host;
  string user;
  string password;
  string database;

public:
  MySQLConnector();

  sql::Connection *getConnection();

  ~MySQLConnector();
};

#endif // PERSISTENCY_MYSQLCONNECTOR_H_