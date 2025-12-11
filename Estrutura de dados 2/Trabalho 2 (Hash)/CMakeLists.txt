cmake_minimum_required(VERSION 3.18)

# Nome do projeto e linguagem
project(atividade-sobre-hash-time255 LANGUAGES CXX)

# Configurar o padrão de C++
set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED True)
set(CMAKE_CXX_FLAGS "-g -O2")  # Use -O2 se quiser alguma otimização, ou -O0 para nada



# Adicionar o executável principal
add_executable (
    main main.cpp 
    src/tabelahash.cpp 
    src/registro.cpp 
    src/KMP.cpp 
    src/AlgForcaBruta.cpp
    src/BMH.cpp
    src/LZW.cpp
    src/RLE.cpp
    src/LZW_IA.cpp
)

target_include_directories(main PRIVATE include)

#----- ABAIXO, COMENTADA, A PARTE USADA PARA A EXECUÇÃO DO ARQUIVO DE BENCHMARK.-----# 
#----- SÓ FUNCIONA COM A BIBLIOTECA INSTALADA NOS DIRETÓRIOS ESPECÍFICOS -----#


#include_directories(include)

#find_package(benchmark REQUIRED)

#add_executable(benchmarks 
#    benchmark_algoritmos.cpp  
#    src/tabelahash.cpp 
#    src/registro.cpp 
#    src/KMP.cpp 
#    src/BMH.cpp
#    src/AlgForcaBruta.cpp
# )


# target_link_libraries(benchmarks benchmark::benchmark pthread)
#target_link_libraries(main pthread)