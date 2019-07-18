CMP = g++ -std=c++11
MAIN = testBottle
MAIN2 = testRow
CLASS = Date
CLASS2 = Bottle
CLASS3 = Row
EXEC1 = testBottleEX
EXEC2 = testRowEX

$(EXEC1): $(MAIN).o $(CLASS).o $(CLASS2).o
	$(CMP) $(MAIN).o $(CLASS).o $(CLASS2).o -o $(EXEC1)

$(EXEC2): $(MAIN2).o $(CLASS).o $(CLASS2).o $(CLASS3).o
	$(CMP) $(MAIN2).o $(CLASS).o $(CLASS2).o $(CLASS3).o -o $(EXEC2)

$(MAIN).o: $(MAIN).cpp $(CLASS).h $(CLASS2).h
	$(CMP) -c $(MAIN).cpp 

$(MAIN2).o: $(MAIN2).cpp $(CLASS).h $(CLASS2).h $(CLASS3).h
	$(CMP) -c $(MAIN2).cpp 

$(CLASS).o: $(CLASS).cpp $(CLASS).h
	$(CMP) -c $(CLASS).cpp $(CLASS).h

$(CLASS2).o: $(CLASS2).cpp $(CLASS2).h
	$(CMP) -c $(CLASS2).cpp $(CLASS2).h 

$(CLASS3).o: $(CLASS3).cpp $(CLASS3).h
	$(CMP) -c $(CLASS3).cpp $(CLASS3).h 

clean:
	rm *.o
	rm *.h.gch
	rm $(EXEC1) $(EXEC2)
