all: run

main: main.cpp
	g++ -g --std=c++17 $< -o $@

clean:
	rm main

db:
	gdb main

gui:
	ddd main

run: main
	./$<

.PHONY: clean db gui
