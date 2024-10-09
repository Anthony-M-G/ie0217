#include "./includes/ProductoRepositorioImpl.hpp"
#include "includes/Producto.hpp"
#include <iostream>

// No utlizo esta función callback porque no la necesito ya que hago la consulta
// desde un método de la clase ProductoRepositorioImpl

// static int callback(void *NotUsed, int argc, char **argv, char **azColName) {
//   for (int i = 0; i < argc; i++) {
//     std::cout << azColName[i] << ": " << (argv[i] ? argv[i] : "NULL")
//               << std::endl;
//   }
//   return 0;
// }

int main() {
  sqlite3 *db;
  char *errMsg = 0;
  int rc;
  // Abre o crea la base de datos
  rc = sqlite3_open("inventario.db", &db);
  if (rc) {
    std::cerr << "No se pudo abrir la base de datos: " << sqlite3_errmsg(db)
              << std::endl;
    return (0);
  } else {
    std::cout << "Base de datos abierta con éxito" << std::endl;
  }
  // Crea la tabla Productos
  const char *sql = "CREATE TABLE IF NOT EXISTS Productos ("
                    "id INTEGER PRIMARY KEY AUTOINCREMENT,"
                    "nombre TEXT NOT NULL,"
                    "precio INT NOT NULL,"
                    "cantidad REAL NOT NULL);";
  rc = sqlite3_exec(db, sql, nullptr, 0, &errMsg);
  if (rc != SQLITE_OK) {
    std::cerr << "Error al crear la tabla: " << errMsg << std::endl;
    sqlite3_free(errMsg);
  } else {
    std::cout << "Tabla creada con éxito" << std::endl;
  }

  ProductoRepositorioImpl *repo = new ProductoRepositorioImpl(db);
  Producto laptop("Laptop", 1000.50, 10);
  Producto teclado("Teclado", 20.99, 50);
  Producto mouse("Mouse", 15.50, 30);

  repo->guardarProducto(laptop);
  repo->guardarProducto(teclado);
  repo->guardarProducto(mouse);
  repo->mostrarProductos();

  repo->actualizarProducto(1, "Mouse", 15.50, 25);
  repo->eliminarProducto(2);

  repo->mostrarProductos();

  delete repo; // Destructor de la clase que cierra la conexión a la base de
               // datos
  sqlite3_close(db); // Por si
  return 0;
}