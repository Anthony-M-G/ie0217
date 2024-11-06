# Agregar el ejecutable de pruebas
add_executable(run_tests testCalculator.cpp)

# Enlazar GoogleTest y la biblioteca de la calculadora
target_link_libraries(run_tests gtest gtest_main calculator_lib)

# Agregar prueba a CMake
add_test(NAME CalculatorTests COMMAND run_tests)