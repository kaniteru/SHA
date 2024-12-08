cmake_minimum_required(VERSION 3.29)
project(SHA)

file(GLOB_RECURSE INC_FILES
        "${PROJECT_SOURCE_DIR}/include/**.hpp"
)

file(GLOB_RECURSE SRC_FILES
        "${PROJECT_SOURCE_DIR}/src/SHA256.cpp"
        "${PROJECT_SOURCE_DIR}/src/SHA384.cpp"
        "${PROJECT_SOURCE_DIR}/src/SHA512.cpp"
)

# static lib
add_library(SHA STATIC "${INC_FILES}" "${SRC_FILES}")
add_library(SHA::static ALIAS SHA)

# shared lib
add_library(SHA_SHARED SHARED "${INC_FILES}" "${SRC_FILES}")
add_library(SHA::shared ALIAS SHA_SHARED)

# example
add_executable(ShaExample "${PROJECT_SOURCE_DIR}/src/example.cpp")

target_include_directories(SHA
        PUBLIC "${PROJECT_SOURCE_DIR}/include"
)

target_include_directories(SHA_SHARED
        PUBLIC "${PROJECT_SOURCE_DIR}/include"
)

target_link_libraries(ShaExample
        PRIVATE SHA::static
)
