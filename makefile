SHELL = bash

BIN = Bin
SOURCE = Source
TEMP = Temp
TESTS = Tests

TESTING_UTILITIES_NAME = TestingUtilities
TESTS_NAME = Tests

TESTS_EXE := $(BIN)/$(TESTS_NAME).exe

HEADERS_WILDCARD = ../*/Header
HEADERS := $(subst $() , -I , $(wildcard $(HEADERS_WILDCARD)))

All: $(TESTS_EXE) 
	$(TESTS_EXE)

$(TESTS_EXE): $(HEADERS_WILDCARD)/*.h $(TESTS)/$(TESTS_NAME).c
	gcc -c $(HEADERS) $(TESTS)/$(TESTS_NAME).c -o $(TEMP)/$(TESTS_NAME).o
	gcc $(TEMP)/$(TESTS_NAME).o -o $(TESTS_EXE)

Clean:
	rm $(BIN)/*.dll $(BIN)/*.exe
	rm $(TEMP)/*.o