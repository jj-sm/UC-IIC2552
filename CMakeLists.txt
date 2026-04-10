cmake_minimum_required(VERSION 3.28)
project(CP_Workspace CXX)

set(CMAKE_CXX_STANDARD 23)

# 1. Add a specific "Sanitize" configuration for crdb behavior
set(SANITIZE_FLAGS "-fsanitize=address,undefined -fno-omit-frame-pointer")

# 2. Add your executable (you can automate this with plugins later)
add_executable(solution main.cpp)

# 3. Apply Sanitizers only in Debug mode
target_compile_options(solution PRIVATE
    $<$<CONFIG:Debug>:${SANITIZE_FLAGS} -g>
    $<$<CONFIG:Release>:-O2>
)
target_link_options(solution PRIVATE
    $<$<CONFIG:Debug>:${SANITIZE_FLAGS}>
)
add_executable(C_Grafo_Revolucionario "problems/1004/A/C_Grafo_Revolucionario.cpp" "Codeforces - BFS/C_Grafo_Revolucionario.cpp")
add_executable(solcpp "problems/1004/A/solcpp.cpp")
add_executable(sol "problems/0410/A/sol.cpp")