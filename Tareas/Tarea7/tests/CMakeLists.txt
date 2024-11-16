# Agregar el ejecutable de pruebas
add_executable(run_tests tests.cpp)

# Enlazar GoogleTest y la biblioteca de la calculadora
target_link_libraries(run_tests gtest gtest_main main_lib)

# Agregar prueba a CMake
add_test(NAME tests COMMAND run_tests)