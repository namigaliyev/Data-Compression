hepsi: derle calistir

derle:
	g++ -I ./include/ -o ./lib/Dugum.o -c ./src/Dugum.cpp
	g++ -I ./include/ -o ./lib/Huffman.o -c ./src/Huffman.cpp
	g++ -I ./include/ -o ./lib/bitChar.o -c ./src/bitChar.cpp
	g++ -I ./include/ -o ./bin/test ./lib/Huffman.o ./lib/Dugum.o ./lib/bitChar.o  ./src/test.cpp

calistir:
	./bin/test
