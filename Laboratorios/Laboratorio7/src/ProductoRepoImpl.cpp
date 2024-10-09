#include "../includes/ProductoRepositorioImpl.hpp"
#include <string>

ProductoRepositorioImpl::ProductoRepositorioImpl(sqlite3 *db) { this->db = db; }

void ProductoRepositorioImpl::guardarProducto(
    Producto &producto) { // Recibe un objeto de tipo Producto
  std::string sql = "INSERT INTO productos (nombre, precio, cantidad) VALUES "
                    "(?, ?, ?);"; // Query para insertar un producto
  sqlite3_stmt *stmt; // Declara un objeto de tipo sqlite3_stmt que será el que
                      // se encargue de ejecutar la query
  int rc = sqlite3_prepare_v2(
      this->db, sql.c_str(), -1, &stmt,
      NULL); // Prepara la query para ser ejecutada evitando inyecciones SQL
  if (rc != SQLITE_OK) { // Si la query no se prepara correctamente muestra un
                         // mensaje de error
    std::cerr << "Error al insertar el producto" << std::endl;
    return;
  }

  // Los sqlite3_bind_* se encargan de asignar los valores a la sentencia SQL
  // que antes tenía '?'.
  sqlite3_bind_text(stmt, 1, producto.getNombre().c_str(), -1,
                    SQLITE_STATIC); // SQLITE_STATIC indica que el valor es
                                    // estático y no se modificará
  sqlite3_bind_double(stmt, 2, producto.getPrecio());
  sqlite3_bind_int(stmt, 3, producto.getCantidad());

  rc = sqlite3_step(stmt); // Ejecuta la query
  if (rc != SQLITE_DONE) { // Si la query no se ejecuta correctamente muestra un
                           // mensaje de error
    std::cerr << "Error al ejecutar la inserción del producto" << std::endl;
    sqlite3_finalize(stmt);
    return;
  }

  sqlite3_finalize(stmt); // Libera la memoria utilizada por la sentencia
  std::cout << "Producto insertado correctamente" << std::endl;
}

void ProductoRepositorioImpl::actualizarProducto(int id, std::string nombre,
                                                 float precio, int cantidad) {
  if (id == 0 || typeid(id) != typeid(int)) {
    std::cerr << "No se puede actualizar el producto" << std::endl;
    return;
  }
  std::string sql = "UPDATE productos SET nombre = ?, precio = ?, cantidad = ? "
                    "WHERE id = ?;";

  sqlite3_stmt *stmt;
  int rc = sqlite3_prepare_v2(this->db, sql.c_str(), -1, &stmt, NULL);
  if (rc != SQLITE_OK) {
    std::cerr << "Error al actualizar el producto" << std::endl;
    return;
  }
  sqlite3_bind_text(stmt, 1, nombre.c_str(), -1, SQLITE_STATIC);
  sqlite3_bind_double(stmt, 2, precio);
  sqlite3_bind_int(stmt, 3, cantidad);
  sqlite3_bind_int(stmt, 4, id);

  rc = sqlite3_step(stmt);
  if (rc != SQLITE_DONE) {
    std::cerr << "Error al ejecutar la actualización del producto" << std::endl;
    sqlite3_finalize(stmt);
    return;
  }

  sqlite3_finalize(stmt);
  std::cout << "Producto actualizado correctamente" << std::endl;
}

void ProductoRepositorioImpl::eliminarProducto(int id) {
  if (id == 0 || typeid(id) != typeid(int)) {
    std::cerr << "No se puede eliminar el producto" << std::endl;
    return;
  }
  std::string sql = "DELETE FROM productos WHERE id = ?;";
  sqlite3_stmt *stmt;
  int rc = sqlite3_prepare_v2(this->db, sql.c_str(), -1, &stmt, NULL);
  if (rc != SQLITE_OK) {
    std::cerr << "Error al eliminar el producto" << std::endl;
    return;
  }
  sqlite3_bind_int(stmt, 1, id);

  rc = sqlite3_step(stmt);
  if (rc != SQLITE_DONE) {
    std::cerr << "Error al ejecutar la eliminación del producto" << std::endl;
    sqlite3_finalize(stmt);
    return;
  }

  sqlite3_finalize(stmt);
  std::cout << "Producto eliminado correctamente" << std::endl;

  return;
}

void ProductoRepositorioImpl::mostrarProductos() {
  std::string sql = "SELECT * FROM productos;";
  sqlite3_stmt *stmt;
  int rc = sqlite3_prepare_v2(this->db, sql.c_str(), -1, &stmt, NULL);
  if (rc != SQLITE_OK) {
    sqlite3_finalize(stmt);
    std::cerr << "Error al consultar los productos" << std::endl;
    return;
  }

  while ((rc = sqlite3_step(stmt)) == SQLITE_ROW) {
    int id = sqlite3_column_int(stmt, 0);
    const unsigned char *nombre = sqlite3_column_text(stmt, 1);
    float precio = sqlite3_column_double(stmt, 2);
    int cantidad = sqlite3_column_int(stmt, 3);
    Producto producto(std::string(reinterpret_cast<const char *>(nombre)),
                      precio, cantidad);
    producto.setId(id);
    std::cout << producto << std::endl;
  }

  sqlite3_finalize(stmt);
}

ProductoRepositorioImpl::~ProductoRepositorioImpl() {
  sqlite3_close(this->db);
} // Destructor de la clase que cierra la conexión a la base de datos
