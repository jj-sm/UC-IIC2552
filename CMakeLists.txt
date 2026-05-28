cmake_minimum_required(VERSION 3.23)
project(UC_IIC2552 CXX)
set(CMAKE_CXX_STANDARD 23)

set(ACTIVE_DIRS
    "problems/0410"
)

foreach(DIR ${ACTIVE_DIRS})
    file(GLOB_RECURSE CURRENT_CPPS "${DIR}/*.cpp")
    foreach(FILE ${CURRENT_CPPS})
        string(REPLACE "/" "_" EXEC_NAME ${FILE})
        add_executable(${EXEC_NAME} ${FILE})
    endforeach()
endforeach()
add_executable(sol "problems/0417/B/sol.cpp" "problems/0417/A/sol.cpp" "problems/0410/C/sol.cpp" "problems/0410/B/sol.cpp" "problems/0410/A/sol.cpp")

add_executable(B_Sushi_para_Dos "contests/I1/B/B_Sushi_para_Dos.py" "contests/I1/B/B_Sushi_para_Dos.cpp")
add_executable(G_Conecta_Nlogonia "contests/I1/G/G_Conecta_Nlogonia.cpp")
add_executable(sol_g "contests/I1/G/sol_g.cpp")
add_executable(A_Hello_Fortnite "problems/0515/A_Hello_Fortnite.cpp")
add_executable(B_Distraccin "problems/0515/B_Distraccin.cpp")
add_executable(C_Pijama "problems/0515/C_Pijama.cpp")