# Function to embed resources into a target
# Usage: embed_resources(TARGET <target> RESOURCES <resource1> [<resource2> ...])
function(embed_resources)
    # Parse arguments
    cmake_parse_arguments(EMBED "" "TARGET" "RESOURCES" ${ARGN})
    if(NOT EMBED_TARGET OR NOT EMBED_RESOURCES)
        message(FATAL_ERROR "Usage: embed_resources(TARGET <target> RESOURCES <resource1> [<resource2> ...])")
    endif()

    # Create output directory for generated files
    set(OUTPUT_DIR "${CMAKE_CURRENT_BINARY_DIR}/generated/resources")
    file(MAKE_DIRECTORY "${OUTPUT_DIR}")

    # Generated source and header files
    set(HEADER_FILE "${OUTPUT_DIR}/embedded_resources.h")
    set(SOURCE_FILE "${OUTPUT_DIR}/embedded_resources.cpp")

    # Start writing the header and source files
    file(WRITE "${HEADER_FILE}" "#pragma once\n#include <cstddef>\n#include <cstdint>\n\n")
    file(WRITE "${SOURCE_FILE}" "#include \"embedded_resources.h\"\n\n")

    # Process each resource
    foreach(RESOURCE ${EMBED_RESOURCES})
        # Get absolute path and sanitize resource name (e.g., "shaders/vert.glsl" → "shaders_vert_glsl")
        get_filename_component(RESOURCE_ABSOLUTE "${RESOURCE}" ABSOLUTE)
        string(REGEX REPLACE "[^a-zA-Z0-9_]" "_" RESOURCE_NAME "${RESOURCE}")

        # Read resource as binary data
        file(READ "${RESOURCE_ABSOLUTE}" RESOURCE_DATA BINARY)

        # Convert binary data to C++ hex array (e.g., 0xDE, 0xAD, 0xBE, 0xEF, ...)
        string(HEX "${RESOURCE_DATA}" HEX_DATA)
        string(LENGTH "${HEX_DATA}" HEX_LENGTH)
        math(EXPR NUM_BYTES "${HEX_LENGTH} / 2")
        set(ARRAY_DATA "")
        foreach(I RANGE 0 ${NUM_BYTES})
            math(EXPR POS "${I} * 2")
            string(SUBSTRING "${HEX_DATA}" ${POS} 2 HEX_BYTE)
            if(HEX_BYTE STREQUAL "")
                break()
            endif()
            set(ARRAY_DATA "${ARRAY_DATA}0x${HEX_BYTE}, ")
        endforeach()

        # Append null terminator for text resources (safe for binary too)
        set(ARRAY_DATA "${ARRAY_DATA}0x00")

        # Write header declarations
        file(APPEND "${HEADER_FILE}" "extern const uint8_t ${RESOURCE_NAME}_data[];\n")
        file(APPEND "${HEADER_FILE}" "extern const size_t ${RESOURCE_NAME}_size;\n\n")

        # Write source definitions
        file(APPEND "${SOURCE_FILE}" "const uint8_t ${RESOURCE_NAME}_data[] = { ${ARRAY_DATA} };\n")
        file(APPEND "${SOURCE_FILE}" "const size_t ${RESOURCE_NAME}_size = sizeof(${RESOURCE_NAME}_data) - 1; // Exclude null terminator\n\n")
    endforeach()

    # Add generated files to the target
    target_sources(${EMBED_TARGET} PRIVATE "${SOURCE_FILE}" "${HEADER_FILE}")

    # Include output directory so the header can be included
    target_include_directories(${EMBED_TARGET} PRIVATE "${OUTPUT_DIR}")
endfunction()