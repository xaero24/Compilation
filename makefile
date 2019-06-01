all:
	lex scanner.l
	yacc -d parser.y --debug --verbose 
	cc -o part2 y.tab.c -Ly -Ll -lfl
	./part2 <trycode.txt

	lex scanner.l
	yacc -d parser.y --debug --verbose 
	cc -o part2 y.tab.c -Ly -Ll -lfl
	./part2 <trycode1.txt


	
