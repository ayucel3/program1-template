P=program1
ST=Star
PL=Planet
V=List
CFLAGS=-g -Wall -std=c++14

all: $(P)

$(P) : $(P).o $(V).o $(ST).o $(PL).o
	g++ $(CFLAGS) $(P).o $(V).o $(ST).o $(PL).o -o $(P)

$(P).o : $(P).cpp $(V).h $(ST).h $(PL).h 
	g++ $(CFLAGS) -c $(P).cpp -o $(P).o

$(V).o : $(V).cpp  $(V).h $(ST).h $(PL).h
	g++ $(CFLAGS) -c $(V).cpp -o $(V).o

$(ST).o : $(ST).cpp $(ST).h $(PL).h
	g++ $(CFLAGS) -c $(ST).cpp -o $(ST).o

$(PL).o : $(PL).cpp $(PL).h
	g++ $(CFLAGS) -c $(PL).cpp -o $(PL).o


run: all
	./$(P)

clean:
	rm -rf *.o $(P)

		
