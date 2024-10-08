#include <sqlite3.h>
#include <stdlib.h>
#include <string>

using namespace std;

static int callback(void *data, int argc, char **argv, char **azColName) {
  // Aquí estoy definiendo una función de callback que será llamada por SQLite.
  // La función toma varios parámetros, incluyendo un puntero a datos, el número
  // de columnas, un array de valores de las columnas y un array de nombres de
  // las columnas.

  fprintf(stderr, "%s: ", (const char *)data); // Imprimo el mensaje de datos.
  for (int i = 0; i < argc; i++) {
    // Recorro todas las columnas y las imprimo junto con sus valores.
    printf("%s = %s\n", azColName[i], argv[i] ? argv[i] : "NULL");
  }
  printf("\n");
  return 0; // Devuelvo 0 para indicar que todo salió bien.
}

int main(int argc, char *argv[]) {
  sqlite3 *db;       // Declaro un puntero a la base de datos.
  char *zErrMsg = 0; // Variable para almacenar mensajes de error.
  int rc;            // Variable para almacenar códigos de retorno.
  const char *data = "Callback function called"; // Mensaje que se pasará a la
                                                 // función de callback.
  string sql; // Variable para almacenar las consultas SQL.

  rc = sqlite3_open("test.db", &db); // Abro la base de datos.
  if (rc) {
    // Si hay un error al abrir la base de datos, imprimo el mensaje de error.
    fprintf(stderr, "Can't open database: %s\n", sqlite3_errmsg(db));
    return (0);
  } else {
    // Si la base de datos se abre correctamente, imprimo un mensaje de éxito.
    fprintf(stderr, "Opened database successfully\n");
  }

  // Defino una consulta SQL para crear una tabla llamada COMPANY.
  sql = "CREATE TABLE COMPANY("
        "ID INT PRIMARY KEY     NOT NULL,"
        "NAME           TEXT    NOT NULL,"
        "AGE            INT     NOT NULL,"
        "ADDRESS        CHAR(50),"
        "SALARY         REAL );";

  // Ejecuto la consulta SQL para crear la tabla.
  rc = sqlite3_exec(db, sql.c_str(), callback, 0, &zErrMsg);
  if (rc != SQLITE_OK) {
    // Si hay un error al ejecutar la consulta, imprimo el mensaje de error.
    fprintf(stderr, "SQL error: %s\n", zErrMsg);
    sqlite3_free(zErrMsg); // Libero la memoria del mensaje de error.
  } else {
    // Si la tabla se crea correctamente, imprimo un mensaje de éxito.
    fprintf(stdout, "Table created successfully\n");
  }

  // Defino una consulta SQL para insertar registros en la tabla COMPANY.
  sql = "INSERT INTO COMPANY (ID,NAME,AGE,ADDRESS,SALARY) "
        "VALUES (1, 'Paul', 32, 'California', 20000.00 ); "
        "INSERT INTO COMPANY (ID,NAME,AGE,ADDRESS,SALARY) "
        "VALUES (2, 'Allen', 25, 'Texas', 15000.00 ); "
        "INSERT INTO COMPANY (ID,NAME,AGE,ADDRESS,SALARY)"
        "VALUES (3, 'Teddy', 23, 'Norway', 20000.00 );"
        "INSERT INTO COMPANY (ID,NAME,AGE,ADDRESS,SALARY)"
        "VALUES (4, 'Mark', 25, 'Rich-Mond ', 65000.00 );";

  // Ejecuto la consulta SQL para insertar los registros.
  rc = sqlite3_exec(db, sql.c_str(), callback, (void *)data, &zErrMsg);
  if (rc != SQLITE_OK) {
    // Si hay un error al ejecutar la consulta, imprimo el mensaje de error.
    fprintf(stderr, "SQL error: %s\n", zErrMsg);
    sqlite3_free(zErrMsg); // Libero la memoria del mensaje de error.
  } else {
    // Si los registros se insertan correctamente, imprimo un mensaje de éxito.
    fprintf(stdout, "Records created successfully\n");
  }

  // Defino una consulta SQL para seleccionar todos los registros de la tabla
  // COMPANY.
  sql = "SELECT * from COMPANY";

  // Ejecuto la consulta SQL para seleccionar los registros.
  rc = sqlite3_exec(db, sql.c_str(), callback, (void *)data, &zErrMsg);
  if (rc != SQLITE_OK) {
    // Si hay un error al ejecutar la consulta, imprimo el mensaje de error.
    fprintf(stderr, "SQL error: %s\n", zErrMsg);
    sqlite3_free(zErrMsg); // Libero la memoria del mensaje de error.
  } else {
    // Si los registros se seleccionan correctamente, imprimo un mensaje de
    // éxito.
    fprintf(stdout, "Operation done successfully\n");
  }

  sqlite3_close(db); // Cierro la base de datos.
  return 0;          // Termino el programa.
}
