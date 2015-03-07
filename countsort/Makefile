all: countsort countsortcpp

countsortcpp: countsort.cpp
	g++ -O2 -std=c++11 -o countsortcpp countsort.cpp

countsort: countsort.c
	gcc -O2 -std=c11 -o countsort countsort.c

clean:
	rm -f countsort countsortcpp

