build: clean init 
	clear
	g++  -std=c++23 -fdiagnostics-color=always -ggdb src/parser.cpp src/lexer/lexer.cpp -o target/parser

init:
	mkdir -p target

clean:
	rm -rf target

run: build
	./target/parser 

test.all: test.comentario test.id test.lit test.num test.professora 

test.comentario: build
	./target/parser testes/teste_comentario.mgol

test.descricaoT1: build
	./target/parser testes/teste_descricaoT1.mgol

test.id: build
	./target/parser testes/teste_id.mgol

test.lit: build
	./target/parser testes/teste_lit.mgol

test.num: build
	./target/parser testes/teste_num.mgol

test.professora: build 
	./target/parser testes/teste_professora.mgol