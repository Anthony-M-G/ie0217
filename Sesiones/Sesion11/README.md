# Sesión 11: SQL

## ¿Qué es SQL?

SQL (Structured Query Language) es un lenguaje estándar para gestionar y manipular bases de datos relacionales. Es esencial en el mundo del manejo de datos y se utiliza en una amplia variedad de aplicaciones y sistemas.

## ¿Para qué sirve SQL?

- Crear, modificar y eliminar estructuras de bases de datos
- Insertar, actualizar y eliminar datos
- Realizar consultas para recuperar información específica
- Administrar permisos de acceso a los datos
- Optimizar el rendimiento de las bases de datos
- Mantener la integridad y consistencia de los datos

## Componentes Básicos de una Base de Datos Relacional

### Tablas

- Son las unidades básicas de almacenamiento en una base de datos relacional
- Organizadas en filas (registros) y columnas (campos)
- Cada columna tiene un tipo de dato específico (por ejemplo, INTEGER, VARCHAR, DATE)

### Esquema

- Es la estructura que define cómo se organizan los datos en la base de datos
- Incluye la definición de tablas, relaciones, restricciones y otros elementos

## Tipos de Datos Comunes en SQL

- INTEGER: Números enteros
- DECIMAL/NUMERIC: Números con decimales
- VARCHAR/CHAR: Cadenas de texto
- DATE: Fechas
- BOOLEAN: Valores verdadero/falso
- BLOB: Datos binarios grandes (imágenes, archivos)

## Comandos SQL Fundamentales

1. SELECT: Recupera datos de una o más tablas

   ```sql
   SELECT nombre, edad FROM usuarios WHERE edad > 18;
   ```

2. INSERT: Añade nuevos registros a una tabla

   ```sql
   INSERT INTO usuarios (nombre, edad) VALUES ('Ana', 25);
   ```

3. UPDATE: Modifica registros existentes

   ```sql
   UPDATE usuarios SET edad = 26 WHERE nombre = 'Ana';
   ```

4. DELETE: Elimina registros de una tabla

   ```sql
   DELETE FROM usuarios WHERE nombre = 'Ana';
   ```

5. CREATE TABLE: Crea una nueva tabla

   ```sql
   CREATE TABLE productos (
       id INT PRIMARY KEY,
       nombre VARCHAR(100),
       precio DECIMAL(10, 2)
   );
   ```

6. ALTER TABLE: Modifica la estructura de una tabla existente

   ```sql
   ALTER TABLE productos ADD COLUMN categoria VARCHAR(50);
   ```

7. DROP TABLE: Elimina una tabla
   ```sql
   DROP TABLE productos;
   ```

## Llaves (Keys) y sus Tipos

Las llaves son fundamentales para mantener la integridad y establecer relaciones entre tablas.

1. Clave Primaria (Primary Key):

   - Identifica de forma única cada registro en una tabla
   - No puede contener valores NULL
   - Debe ser única para cada registro

   ```sql
   CREATE TABLE usuarios (
       id INT PRIMARY KEY,
       nombre VARCHAR(50)
   );
   ```

2. Clave Foránea (Foreign Key):

   - Establece relaciones entre tablas
   - Referencia la clave primaria de otra tabla
   - Mantiene la integridad referencial

   ```sql
   CREATE TABLE pedidos (
       id INT PRIMARY KEY,
       usuario_id INT,
       FOREIGN KEY (usuario_id) REFERENCES usuarios(id)
   );
   ```

3. Clave Compuesta:

   - Clave primaria que consta de dos o más columnas

   ```sql
   CREATE TABLE detalles_pedido (
       pedido_id INT,
       producto_id INT,
       cantidad INT,
       PRIMARY KEY (pedido_id, producto_id)
   );
   ```

4. Clave Única (Unique Key):
   - Garantiza que todos los valores en una columna sean diferentes
   - Puede contener un valor NULL (a diferencia de la clave primaria)
   ```sql
   CREATE TABLE empleados (
       id INT PRIMARY KEY,
       email VARCHAR(100) UNIQUE
   );
   ```

## JOINS: Combinando Datos de Múltiples Tablas

Los JOINS son operaciones cruciales en SQL que permiten combinar filas de dos o más tablas basándose en una condición relacionada.

1. INNER JOIN:

   - Retorna registros cuando hay coincidencias en ambas tablas

   ```sql
   SELECT usuarios.nombre, pedidos.id
   FROM usuarios
   INNER JOIN pedidos ON usuarios.id = pedidos.usuario_id;
   ```

2. LEFT JOIN (o LEFT OUTER JOIN):

   - Retorna todos los registros de la tabla izquierda y los coincidentes de la derecha

   ```sql
   SELECT usuarios.nombre, pedidos.id
   FROM usuarios
   LEFT JOIN pedidos ON usuarios.id = pedidos.usuario_id;
   ```

3. RIGHT JOIN (o RIGHT OUTER JOIN):

   - Retorna todos los registros de la tabla derecha y los coincidentes de la izquierda

   ```sql
   SELECT usuarios.nombre, pedidos.id
   FROM usuarios
   RIGHT JOIN pedidos ON usuarios.id = pedidos.usuario_id;
   ```

4. FULL JOIN (o FULL OUTER JOIN):

   - Retorna todos los registros cuando hay una coincidencia en cualquiera de las tablas

   ```sql
   SELECT usuarios.nombre, pedidos.id
   FROM usuarios
   FULL JOIN pedidos ON usuarios.id = pedidos.usuario_id;
   ```

5. CROSS JOIN:
   - Retorna el producto cartesiano de las dos tablas
   ```sql
   SELECT usuarios.nombre, productos.nombre
   FROM usuarios
   CROSS JOIN productos;
   ```

## Funciones de Agregación y GROUP BY

Las funciones de agregación realizan cálculos sobre un conjunto de valores y devuelven un único resultado.

- COUNT(): Cuenta el número de filas
- SUM(): Suma los valores de una columna
- AVG(): Calcula el promedio de los valores de una columna
- MAX(): Encuentra el valor máximo
- MIN(): Encuentra el valor mínimo

Ejemplo con GROUP BY:

```sql
SELECT categoria, COUNT(*) as total, AVG(precio) as precio_promedio
FROM productos
GROUP BY categoria
HAVING COUNT(*) > 5;
```

## Subconsultas

Las subconsultas son consultas anidadas dentro de otra consulta.

```sql
SELECT nombre
FROM usuarios
WHERE id IN (SELECT usuario_id FROM pedidos WHERE total > 1000);
```

## Índices

Los índices mejoran la velocidad de las operaciones de recuperación de datos.

```sql
CREATE INDEX idx_nombre ON usuarios(nombre);
```

## Vistas

Las vistas son consultas almacenadas que se pueden usar como tablas virtuales.

```sql
CREATE VIEW usuarios_activos AS
SELECT * FROM usuarios WHERE ultimo_acceso > DATE_SUB(NOW(), INTERVAL 30 DAY);
```

## Transacciones

Las transacciones garantizan que un conjunto de operaciones se complete en su totalidad o no se realice ninguna.

```sql
BEGIN TRANSACTION;
UPDATE cuentas SET saldo = saldo - 100 WHERE id = 1;
UPDATE cuentas SET saldo = saldo + 100 WHERE id = 2;
COMMIT;
```
