# Tarea 5 - Estructuras Abstractas de Datos y Algoritmos para Ingeniería

## Instrucciones de Ejecución

1. Clona el repositorio en tu máquina local.
2. Navega hasta la carpeta necesaria y revisa el readme.

## Respuestas Parte Teórica

### 1. Diferencias entre bases de datos relacionales y no relacionales

- **Estructura de datos**: Las bases de datos relacionales almacenan datos en tablas con filas y columnas, mientras que las no relacionales pueden usar estructuras como documentos, grafos o pares clave-valor.
- **Casos de uso**: Relacionales para transacciones complejas (ERP, CRM); no relacionales para aplicaciones con grandes volúmenes de datos semi o no estructurados (redes sociales, análisis en tiempo real).
- **Escalabilidad**: Las bases de datos relacionales escalan verticalmente (aumentando la capacidad de un solo servidor), mientras que las no relacionales suelen escalar horizontalmente (añadiendo más servidores).

### 2. SQL y su importancia en bases de datos relacionales

SQL (Structured Query Language) permite gestionar y manipular datos en bases relacionales. Operaciones comunes:

- **SELECT**: Consulta datos.
- **INSERT**: Agrega nuevos registros.
- **UPDATE**: Modifica registros existentes.

### 3. Componentes de una tabla SQL

- **Columnas**: Definen el tipo de datos.
- **Filas**: Cada fila representa un registro.
- **Clave primaria**: Identifica de manera única cada fila.

### 4. Operaciones CRUD en bases de datos

- **CREATE**: Inserta datos.
- **READ**: Lee datos.
- **UPDATE**: Modifica datos.
- **DELETE**: Borra datos.
  Implementadas en SQL para bases relacionales y en consultas específicas para bases no relacionales.

### 5. Comandos SQL básicos

- **SELECT**: `SELECT * FROM productos WHERE categoria = 'Electrónica';`
- **INSERT**: `INSERT INTO productos (nombre, precio) VALUES ('Laptop', 999.99);`
- **DELETE**: `DELETE FROM productos WHERE id = 1;`

### 6. Comandos SQL intermedios/avanzados

- **JOIN**: Relaciona tablas. Ejemplo: `SELECT * FROM productos INNER JOIN categorias ON productos.categoria_id = categorias.id;`
- **GROUP BY**: Agrupa resultados. Ejemplo: `SELECT categoria, COUNT(*) FROM productos GROUP BY categoria;`
- **HAVING**: Filtra resultados agrupados. Ejemplo: `SELECT categoria, AVG(precio) FROM productos GROUP BY categoria HAVING AVG(precio) > 100;`

### 7. JOIN y tipos en SQL

- **INNER JOIN**: Retorna solo coincidencias.
- **LEFT JOIN**: Incluye todos los registros de la tabla izquierda y las coincidencias de la derecha.
- **RIGHT JOIN**: Similar al LEFT JOIN, pero con la tabla derecha.

### 8. Consulta con la tabla Productos

```sql
SELECT nombre, precio AS costo FROM Productos WHERE categoria IN ('Electrónica', 'Deportes') AND en_stock = true AND precio < 300 ORDER BY precio ASC;
```

### 9. Consulta de productos color "azul" y menos de 1 kg

```sql
SELECT nombre FROM Productos WHERE detalles_color = 'Azul' AND detalles_peso < 1 ORDER BY nombre ASC;
```

### 10. Consulta para obtener el precio promedio de productos en "Hogar"

```sql
SELECT AVG(precio) AS precio_promedio FROM Productos WHERE categoria = 'Hogar' AND en_stock = true;
```

### 11. SQL Injection y cómo prevenirlo

SQL Injection es un ataque que permite ejecutar código malicioso en la base de datos mediante entradas inseguras. Prevención:

- **Consultas preparadas**.
- **Validación y escape de entradas**.
- **Uso de ORM para abstracción segura**.

### 12. Rol de servidor y cliente en un DBMS

- **Servidor**: Almacena y administra la base de datos.
- **Cliente**: Envia solicitudes para acceder a los datos.
- **Interacción**: Cliente envía consultas SQL al servidor, que responde con los datos.

### 13. Motor de bases de datos y ejemplos

Un motor de bases de datos es el software que permite operaciones CRUD en la base de datos. Ejemplos:

- **MySQL**
- **PostgreSQL**
- **SQLite**

### 14. Uso recomendado de MySQL

Adecuado para bases de tamaño mediano-grande, datos estructurados y aplicaciones web con un esquema definido.

### 15. Características de SQLite

SQLite es conveniente para aplicaciones locales, sin servidor, con almacenamiento de datos liviano y una configuración mínima.

### 16. Tipos de bases de datos NoSQL

- **Clave-valor**: Rápido y escalable. Ejemplo: Redis.
- **Familia de columnas**: Optimizado para datos agregados. Ejemplo: Cassandra.
- **Grafos**: Modela relaciones complejas. Ejemplo: Neo4j.
- **Documentales**: Almacena datos semi-estructurados. Ejemplo: MongoDB.

### 17. Colección en MongoDB vs. tabla SQL

Una colección en MongoDB es un conjunto de documentos, mientras que una tabla SQL contiene registros estructurados en filas y columnas.

### 18. Diferencias de rendimiento y escalabilidad SQL vs. NoSQL

- **SQL**: Escalabilidad vertical y mayor consistencia.
- **NoSQL**: Escalabilidad horizontal y rendimiento superior en grandes volúmenes de datos no estructurados.

## Documentación de Ejercicios Prácticos

- Ingrese a las carpetas de los proyetcos en cuestión y encontrará la documentación necesaria e instrucciones de ejecución.
