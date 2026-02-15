include("${CMAKE_CURRENT_LIST_DIR}/rule.cmake")
include("${CMAKE_CURRENT_LIST_DIR}/file.cmake")

set(PIC_TPBoard_Blinky_default_library_list )

# Handle files with suffix (s|as|asm|AS|ASM|As|aS|Asm), for group default-XC8
if(PIC_TPBoard_Blinky_default_default_XC8_FILE_TYPE_assemble)
add_library(PIC_TPBoard_Blinky_default_default_XC8_assemble OBJECT ${PIC_TPBoard_Blinky_default_default_XC8_FILE_TYPE_assemble})
    PIC_TPBoard_Blinky_default_default_XC8_assemble_rule(PIC_TPBoard_Blinky_default_default_XC8_assemble)
    list(APPEND PIC_TPBoard_Blinky_default_library_list "$<TARGET_OBJECTS:PIC_TPBoard_Blinky_default_default_XC8_assemble>")

endif()

# Handle files with suffix S, for group default-XC8
if(PIC_TPBoard_Blinky_default_default_XC8_FILE_TYPE_assemblePreprocess)
add_library(PIC_TPBoard_Blinky_default_default_XC8_assemblePreprocess OBJECT ${PIC_TPBoard_Blinky_default_default_XC8_FILE_TYPE_assemblePreprocess})
    PIC_TPBoard_Blinky_default_default_XC8_assemblePreprocess_rule(PIC_TPBoard_Blinky_default_default_XC8_assemblePreprocess)
    list(APPEND PIC_TPBoard_Blinky_default_library_list "$<TARGET_OBJECTS:PIC_TPBoard_Blinky_default_default_XC8_assemblePreprocess>")

endif()

# Handle files with suffix [cC], for group default-XC8
if(PIC_TPBoard_Blinky_default_default_XC8_FILE_TYPE_compile)
add_library(PIC_TPBoard_Blinky_default_default_XC8_compile OBJECT ${PIC_TPBoard_Blinky_default_default_XC8_FILE_TYPE_compile})
    PIC_TPBoard_Blinky_default_default_XC8_compile_rule(PIC_TPBoard_Blinky_default_default_XC8_compile)
    list(APPEND PIC_TPBoard_Blinky_default_library_list "$<TARGET_OBJECTS:PIC_TPBoard_Blinky_default_default_XC8_compile>")

endif()


# Main target for this project
add_executable(PIC_TPBoard_Blinky_default_image_fR0pu0M9 ${PIC_TPBoard_Blinky_default_library_list})

set_target_properties(PIC_TPBoard_Blinky_default_image_fR0pu0M9 PROPERTIES
    OUTPUT_NAME "default"
    SUFFIX ".elf"
    ADDITIONAL_CLEAN_FILES "${output_extensions}"
    RUNTIME_OUTPUT_DIRECTORY "${PIC_TPBoard_Blinky_default_output_dir}")
target_link_libraries(PIC_TPBoard_Blinky_default_image_fR0pu0M9 PRIVATE ${PIC_TPBoard_Blinky_default_default_XC8_FILE_TYPE_link})

# Add the link options from the rule file.
PIC_TPBoard_Blinky_default_link_rule( PIC_TPBoard_Blinky_default_image_fR0pu0M9)


