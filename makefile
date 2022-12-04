all: run

main: main.o matrix.o
	g++ -g --std=c++17 -I. $^ -o $@

%.o : %.cpp
	g++ -g --std=c++17 -I. -c $< -o $@

run: main
	./$<

.PHONY: clean db gui run
clean:
	rm main *.o

db:
	gdb main

gui:
	ddd main

