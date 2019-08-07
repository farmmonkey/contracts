project(farmmonkey)

set(EOSIO_WASM_OLD_BEHAVIOR "Off")
find_package(eosio.cdt)

add_contract( farmmonkey farmmonkey farmmonkey.cpp )
target_include_directories( farmmonkey PUBLIC ${CMAKE_SOURCE_DIR}/../include )
target_ricardian_directory( farmmonkey ${CMAKE_SOURCE_DIR}/../ricardian )