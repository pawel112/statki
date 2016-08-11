cmake_minimum_required (VERSION 2.6)
file(COPY ${CMAKE_CURRENT_SOURCE_DIR}/ustawienia.cfg
        DESTINATION ${CMAKE_CURRENT_BINARY_DIR})
file(COPY ${CMAKE_CURRENT_SOURCE_DIR}/zapis_gry.cfg
        DESTINATION ${CMAKE_CURRENT_BINARY_DIR})
SET (name Statki)
SET (sources ustawienia.cpp gra.cpp gra2.cpp menu.cpp zapis_odczyt.cpp glowny.cpp ruchy_komputera.cpp)
SET (headers gra.h gra2.h zapis_odczyt.h menu.h ustawienia.h ruchy_komputera.h)
project (${name})
add_executable (${name} ${sources} ${headers})