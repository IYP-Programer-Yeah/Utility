project(Test CXX)

file(GLOB CPP_FILES ${REPO_ROOT}/${PROJECT_NAME}/Source/*.cpp)
add_executable(${PROJECT_NAME} ${CPP_FILES})
target_link_libraries(${PROJECT_NAME} gtest gtest_main Utility)

if (MSVC)
    set(CMAKE_CXX_FLAGS_RELEASE "${CMAKE_CXX_FLAGS_RELEASE} /MT")
    set(CMAKE_CXX_FLAGS_DEBUG "${CMAKE_CXX_FLAGS_DEBUG} /MTd")
endif()

if(WIN32)
    install(TARGETS ${PROJECT_NAME}
            LIBRARY DESTINATION Lib
            RUNTIME DESTINATION Bin
            ARCHIVE DESTINATION Lib)
else()
    install(TARGETS ${PROJECT_NAME}
            LIBRARY DESTINATION lib
            RUNTIME DESTINATION bin
            ARCHIVE DESTINATION lib)
endif()

