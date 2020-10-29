set(ddic_HEADER_PATH
        ${CMAKE_SOURCE_DIR}/contrib/ddic/src
        ${CMAKE_BINARY_DIR}/contrib/ddic/src
        )

add_library(noop_converter_plugin MODULE plugins/converters/noop_converter/noop_converter.cxx)
target_include_directories(noop_converter_plugin PRIVATE core/api ${ddic_HEADER_PATH})
target_link_libraries(noop_converter_plugin PRIVATE ddic::lib)

add_library(printer_plugin MODULE plugins/processors/printer/printer.cxx)
target_include_directories(printer_plugin PRIVATE core/api ${ddic_HEADER_PATH})
target_link_libraries(printer_plugin PRIVATE ddic::lib)

add_library(dummy_source_plugin MODULE plugins/sources/dummy_source/dummy_source.cxx)
target_include_directories(dummy_source_plugin PRIVATE core/api ${ddic_HEADER_PATH})
target_link_libraries(dummy_source_plugin PRIVATE ddic::lib)

add_library(list_buffer_plugin MODULE plugins/storage/list_buffer/list_buffer.cxx)
target_include_directories(list_buffer_plugin PRIVATE core/api ${ddic_HEADER_PATH})
target_link_libraries(list_buffer_plugin PRIVATE ddic::lib)

add_executable(data_processor
        core/main.cxx
        core/api/package.hxx
        core/api/data_source.hxx
        core/api/data_processor.hxx
        core/api/data_converter.hxx
        core/api/data_storage.hxx
        )
target_include_directories(data_processor PRIVATE ${ddic_HEADER_PATH})
target_link_libraries(data_processor PRIVATE ddic::lib)
add_dependencies(data_processor noop_converter_plugin printer_plugin dummy_source_plugin list_buffer_plugin)
