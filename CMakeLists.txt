cmake_minimum_required(VERSION 3.17)
project(rendelesek C)

set(CMAKE_C_STANDARD 99)

add_executable(rendelesek main.c fajlkezeles.h menu_nezetek.h menu_nezet_szinek.h menu_kezelo.h menu_nezetek.c menu_kecelo.c rendeles_lista.c etel.c rendeles_lista.h)