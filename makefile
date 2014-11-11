ExperimentalAverage: ExperimentalAverage.o
	gcc -o ExperimentalAverage ExperimentalAverage.o
ExperimentalAverage.o: ExperimentalAverage.c
	gcc -c ExperimentalAverage.c
clean:
	rm *.o
