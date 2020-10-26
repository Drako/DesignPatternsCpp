add_executable(visitor
        shape.hxx
        rectangle.cxx rectangle.hxx
        circle.cxx circle.hxx
        shape_visitor.cxx shape_visitor.hxx shape_visitor_tests.cxx
        )
target_link_libraries(visitor gtest gtest_main)
add_test(visitor_tests COMMAND visitor)
