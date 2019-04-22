all:
	lex part1.l
	yacc part1.y
	cc -o part1 y.tab.c -ll -Ly
