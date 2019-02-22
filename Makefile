P=program1
ST=Star
PL=Planet
L=List
V=Vector
CFLAGS=-g -Wall -std=c++14

all: $(P)

$(P) : $(P).o $(V).o $(L).o $(ST).o $(PL).o
	g++ $(CFLAGS) $(P).o $(V).o $(L).o $(ST).o $(PL).o -o $(P)

$(P).o : $(P).cpp $(V).h $(L).h $(ST).h $(PL).h 
	g++ $(CFLAGS) -c $(P).cpp -o $(P).o

$(V).o : $(V).cpp  $(V).h $(PL).h
	g++ $(CFLAGS) -c $(V).cpp -o $(V).o

$(L).o : $(L).cpp  $(L).h $(PL).h
	g++ $(CFLAGS) -c $(L).cpp -o $(L).o

$(ST).o : $(ST).cpp $(ST).h $(PL).h
	g++ $(CFLAGS) -c $(ST).cpp -o $(ST).o

$(PL).o : $(PL).cpp $(PL).h
	g++ $(CFLAGS) -c $(PL).cpp -o $(PL).o


run: all
	./$(P)

clean:
	rm -rf *.o $(P)

		
