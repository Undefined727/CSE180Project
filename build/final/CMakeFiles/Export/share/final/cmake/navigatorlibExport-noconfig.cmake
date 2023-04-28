#----------------------------------------------------------------
# Generated CMake target import file.
#----------------------------------------------------------------

# Commands may need to know the format version.
set(CMAKE_IMPORT_FILE_VERSION 1)

# Import target "final::final" for configuration ""
set_property(TARGET final::final APPEND PROPERTY IMPORTED_CONFIGURATIONS NOCONFIG)
set_target_properties(final::final PROPERTIES
  IMPORTED_LINK_INTERFACE_LANGUAGES_NOCONFIG "CXX"
  IMPORTED_LOCATION_NOCONFIG "${_IMPORT_PREFIX}/lib/libfinal.a"
  )

list(APPEND _IMPORT_CHECK_TARGETS final::final )
list(APPEND _IMPORT_CHECK_FILES_FOR_final::final "${_IMPORT_PREFIX}/lib/libfinal.a" )

# Commands beyond this point should not need to know the version.
set(CMAKE_IMPORT_FILE_VERSION)
