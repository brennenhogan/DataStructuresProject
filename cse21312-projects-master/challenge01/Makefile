CMP = g++ -std=c++11
MAIN = testDate
CLASS = Date
EXEC = runit

$(EXEC): $(MAIN).o $(CLASS).o
	$(CMP) $(MAIN).o $(CLASS).o -o $(EXEC)

$(MAIN).o: $(MAIN).cpp $(CLASS).h
	$(CMP) -c $(MAIN).cpp 

$(CLASS).o: $(CLASS).cpp $(CLASS).h
	$(CMP) -c $(CLASS).cpp $(CLASS).h

clean:
	rm *.o
	rm $(EXEC)

