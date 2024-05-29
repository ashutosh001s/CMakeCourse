function(add_sanitizer_flags)
    if(NOT ${ENABLE_SANITIZER_ADDRESS} AND NOT ${ENABLE_SANITIZER_UNDEFINED})
        message(STATUS "Disabled sanitizers for ${TARGET}")
        return()
    endif()

    # only available on GNU Linux GCC Compiler not in windows mingw compiler
    if(CMAKE_CXX_COMPILER_ID MATCHES "GNU" OR CMAKE_CXX_COMPILER_ID MATCHES "GNU")
        add_compile_options("-fno-omit-frame-pointer")
        add_link_options("-fno-omit-frame-pointer")

        if(${ENABLE_SANITIZER_ADDRESS})
            add_compile_options("-fsanitize=address")
            add_link_options("-fsanitize=address")
        endif()

        if(${ENABLE_SANITIZER_UNDEFINED})
            add_compile_options("-fsanitize=undefined")
            add_link_options("-fsanitize=undefined")
        endif()

    # UNDEFINED SANITIZER FOR MSVC IS NOT IMPLEMENTED
    elseif(CMAKE_CXX_COMPILER_ID MATCHES "MSVC")
        if(${ENABLE_SANITIZER_ADDRESS})
            message(STATUS "Address sanitizer Enabled for MSVC")
            add_compile_options("/fsanitize=address")
        endif()

        if(${ENABLE_SANITIZER_UNDEFINED})
            message(STATUS "Undefined sanitizer not implemented for MSVC")
        endif()

    else()
        message(ERROR "Compiler not supported for Sanitizers")
    endif()
endfunction()
