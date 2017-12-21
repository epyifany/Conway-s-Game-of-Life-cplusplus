
CMP = g++
MAIN = lifemain
CLASS = lifeboard
EXEC = playlife

$(EXEC): $(MAIN).o $(CLASS).o
	$(CMP) $(MAIN).o $(CLASS).o -o $(EXEC)

$(MAIN).o: $(CLASS).h $(MAIN).cpp
	$(CMP) -c $(MAIN).cpp

$(CLASS).o: $(CLASS).h $(CLASS).cpp
	$(CMP) -c $(CLASS).cpp

clean:
	rm *.o
	rm $(EXEC)

