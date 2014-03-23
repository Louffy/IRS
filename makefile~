all: mysearch myindex
mysearch : query.o parser.o search.o index.o util.o indexreader.o searchmain.o
	g++ -g -o mysearch query.o parser.o search.o index.o util.o indexreader.o searchmain.o
myindex : index.o indexmain.o util.o
	g++ -g -o myindex index.o indexmain.o util.o
searchmain.o : ./main/searchmain.cpp
	g++ -g -c -Wall -O2 ./main/searchmain.cpp
parser.o : ./search/parser.cpp
	g++ -g -c -Wall -O2 ./search/parser.cpp
query.o : ./search/query.cpp
	g++ -g -c -Wall -O2 ./search/query.cpp
search.o : ./search/search.cpp
	g++ -g -c -Wall -O2 ./search/search.cpp
indexreader.o : ./search/indexreader.cpp
	g++ -g -c -Wall -O2 ./search/indexreader.cpp
index.o : ./index/index.cpp
	g++ -g -c -Wall -O2 ./index/index.cpp
indexmain.o : ./main/indexmain.cpp
	g++ -g -c -Wall -O2 ./main/indexmain.cpp
util.o : ./util/util.cpp
	g++ -g -c -Wall -O2 ./util/util.cpp
