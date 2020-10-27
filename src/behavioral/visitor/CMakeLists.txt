add_executable(visitor
        shape.hxx
        rectangle.cxx rectangle.hxx
        circle.cxx circle.hxx
        shape_visitor.cxx shape_visitor.hxx shape_visitor_tests.cxx
        )
if (MSVC)
    target_compile_definitions(visitor PRIVATE _USE_MATH_DEFINES)
endif ()
target_link_libraries(visitor gtest gtest_main)
add_test(visitor_tests COMMAND visitor)
