INCLUDE_DIRECTORIES(/usr/inlcude)

SET(SRC_LIST 
    dmo_add.cpp
    dmo_average.cpp
    dmo_datetime.cpp
    main.cpp
)

add_executable(test ${SRC_LIST})

target_link_libraries(test lua stdc++)

set(EXECUTABLE_OUTPUT_PATH ../)