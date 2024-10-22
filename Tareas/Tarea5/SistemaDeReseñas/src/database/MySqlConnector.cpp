#include "../../includes/database/MySqlConnector.h"

using namespace std;

MySQLConnector::MySQLConnector() : driver(nullptr), connection(nullptr) {
  try {
    this->host = "tcp://autorack.proxy.rlwy.net:16240"; // Base de datos
                                                        // deployada en railway
    this->user = "root";
    this->password = "MhLVbFIjSwYtwkiikuemdPISBRvImRlZ";
    this->database = "SistemaResenas";

    this->driver = sql::mysql::get_mysql_driver_instance();

    this->connection = driver->connect(this->host, this->user, this->password);
    this->connection->setSchema(this->database);

  } catch (sql::SQLException &e) {
    cout << "Error de MySQL: " << e.getErrorCode() << " - " << e.what() << endl;
    cout << "SQLState: " << e.getSQLState() << endl;
    this->connection = nullptr;
    this->driver = nullptr;
  }
}

sql::Connection *MySQLConnector::getConnection() { return this->connection; }

MySQLConnector::~MySQLConnector() { delete this->connection; }
