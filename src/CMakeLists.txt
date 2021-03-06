include_directories(.)

include_directories (/usr/local/opt/llvm/include)


find_package (boost COMPONENTS filesystem REQUIRED)
include_directories (${Boost_INCLUDE_DIR})
link_directories(/usr/local/lib)

add_executable (oonalysis-test test_main.cc)
add_executable (oonalysis-cli cli_main.cc)
add_executable (oonalysis-gui gui_main.cc)

# ===========================
# Subdirectories
# ===========================
add_subdirectory (util)
add_subdirectory (db)
add_subdirectory (metrics)
add_subdirectory (core)
add_subdirectory (graph)
add_subdirectory (gui)
add_subdirectory (cli)

# ===========================
# Tests
# ===========================
target_link_libraries (oonalysis-test core sqlite3 util)

# ===========================
# CLI
# ===========================
target_link_libraries (oonalysis-cli cli)
target_link_libraries (oonalysis-cli util)
target_link_libraries (oonalysis-cli sqlite3)
target_link_libraries (oonalysis-cli core)
target_link_libraries (oonalysis-cli metrics)

# ===========================
# GUI
# ===========================
target_link_libraries(oonalysis-gui gui)
target_link_libraries(oonalysis-gui sqlite3)
target_link_libraries(oonalysis-gui core)
target_link_libraries(oonalysis-gui util)
target_link_libraries(oonalysis-gui graph)
target_link_libraries(oonalysis-gui gvc)
target_link_libraries(oonalysis-gui cgraph)

