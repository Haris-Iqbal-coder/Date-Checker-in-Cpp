all: date

date: date.cpp
	g++ date.cpp -o date

clean:
	rm *.o date