cmake_minimum_required(VERSION 3.8)
project(etapa5)

set(CMAKE_C_STANDARD 99)

set(SOURCE_FILES main.c scanner.l symbol_table.c lex.yy.c y.tab.c parser.y ast.c semantic.c semantic.h tac.c tac.h assembler.c assembler.h)
add_executable(etapa5 ${SOURCE_FILES})