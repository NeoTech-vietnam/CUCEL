# Module-owned source and public include metadata.
list(APPEND NEO_MODULE_SOURCES
)
list(APPEND NEO_MODULE_INCLUDES
    "${CMAKE_CURRENT_LIST_DIR}/MemMap"
    "${CMAKE_CURRENT_LIST_DIR}/Platform"
    "${CMAKE_CURRENT_LIST_DIR}/Standard"
)
