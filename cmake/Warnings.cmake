function(target_set_warnings TARGET ENABLE ENABLE_AS_ERROR)
    if(NOT ${ENABLE})
        message(STATUS "Disabled warnings for ${TARGET}")
        return()
    endif()

    set(MSVC_WARNINGS
    /W4
    /permissive-)

    set(CLANG_WARNINGS
    -Wall
    -Wextra
    -Wpedantic)

    set(GCC_WARNINGS
    ${CLANG_WARNINGS})

    if(${ENABLE_AS_ERROR})
        set(MSVC_WARNINGS ${MSVC_COMPILER} /WX)
        set(CLANG_WARNINGS ${CLANG_WARNINGS} -Werror)
        set(GCC_WARNINGS ${GCC_WARNINGS} -Werror)
    endif()

    if(CMAKE_CXX_COMPILER_ID MATCHES "MSVC")
        set(WARNINGS ${MSVC_WARNINGS})
        message("[Warning] Using MSVC warnings")
    elseif(CMAKE_CXX_COMPILER_ID MATCHES "CLANG")
        set(WARNINGS ${CLANG_WARNINGS})
        message("[Warning] Using clang warnings")
    elseif(CMAKE_CXX_COMPILER_ID MATCHES "GNU")
        set(WARNINGS ${GCC_WARNINGS})
        message("[Warning] Using gcc warnings")
    endif()

    target_compile_options(${TARGET} PRIVATE ${WARNINGS})
    message(STATUS ${WARNINGS})
endfunction()
