CMP = g++ -std=c++11
MAIN1 = testBottleFinal
MAIN2 = testRowFinal
MAIN3 = testPharm
CLASS1 = Date
CLASS2 = Bottle
CLASS3 = Row
EXEC1 = testBottleFinalEX
EXEC2 = testRowFinalEX
EXEC3 = testPharmEX

COMP1 = $(CMP) $(MAIN1).cpp $(CLASS1).cpp $(CLASS2).cpp -o $(EXEC1)
COMP1MSG = $(info *** COMPILING testBottleFinalEX ***)

$(EXEC1): $(CLASS1).cpp $(CLASS1).h
	$(COMP1)
	$(COMP1MSG)

COMP2 = $(CMP) $(MAIN2).cpp $(CLASS1).cpp $(CLASS2).cpp -o $(EXEC2)
COMP2MSG = $(info *** COMPILING testRowFinalEX ***)

$(EXEC2): $(CLASS3).h
	$(COMP2)
	$(COMP2MSG)

COMP3 = $(CMP) $(MAIN3).cpp $(CLASS1).cpp $(CLASS2).cpp -o $(EXEC3)
COMP3MSG = $(info *** COMPILING testPharmEX ***)

$(EXEC3):
	$(COMP3)
	$(COMP3MSG)

ALLMSG = $(info *** MAKING ALL ***)

all:
	$(ALLMSG)
	$(COMP1)
	$(COMP2)
	$(COMP3)

CLEANMSG = $(info *** MAKING CLEAN ***)

clean:
	$(CLEANMSG)
	rm $(EXEC1) $(EXEC2) $(EXEC3) TryTwoEX

testProjEX:
	g++ -std=c++11 testProj.cpp Date.cpp Bottle.cpp -o testProjEX

