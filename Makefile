# Comana Marian Georgian < georgiancomana1119@gmail.com>
# Copyright 2020


build:
	g++ -std=c++11 -Wall -Wextra -lm  bani.cpp -o bani
	g++ -std=c++11 -Wall -Wextra -lm  gard.cpp -o gard
	g++ -std=c++11 -Wall -Wextra -lm  bomboane.cpp -o bomboane
	g++ -std=c++11 -Wall -Wextra -lm  sala.cpp -o sala
run-p1:
	./bani
run-p2:
	./gard
run-p3:
	./bomboane
run-p4:
	./sala	
clean:
	rm -f bani bani.o gard gard.o bomboane bomboane.o