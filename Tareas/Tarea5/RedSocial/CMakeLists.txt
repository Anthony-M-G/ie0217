cmake_minimum_required(VERSION 3.10)

project(social_network)

# Incluir las rutas de las bibliotecas instaladas
find_package(mongocxx REQUIRED)
find_package(bsoncxx REQUIRED)

# Añadir las rutas de inclusión manualmente si es necesario
include_directories(/usr/local/include/mongocxx/v_noabi)
include_directories(/usr/local/include/bsoncxx/v_noabi)
include_directories(/usr/local/include/bsoncxx/v_noabi/bsoncxx/third_party/mnmlstc/core)
include_directories(/usr/local/include/bsoncxx/v_noabi/bsoncxx/stdx)
include_directories(/usr/local/include/mongocxx/v_noabi/mongocxx/stdx)

# Añadir las rutas de las bibliotecas manualmente si es necesario
link_directories(/usr/local/lib)

add_executable(main main.cpp ./src/servicios/PostsServices.cpp ./src/controlador/PostsController.cpp ./src/database/MongodbConn.cpp ./src/validadores/Validadores.cpp)

# Vincular las bibliotecas compartidas
target_link_libraries(main PRIVATE bsoncxx mongocxx)