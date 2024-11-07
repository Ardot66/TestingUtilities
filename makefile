SHELL = cmd

BIN = Bin
SOURCE = Source
TEMP = Temp
TESTS = Tests

TESTING_UTILITIES_NAME = TestingUtilities
TESTS_NAME = Tests

TESTS_EXE := $(BIN)/$(TESTS_NAME).exe

HEADERS := $(abspath $(wildcard */*.h))
INCLUDE := $(dir $(addprefix -I,$(HEADERS)))

All: $(TESTS_EXE) 
	$(TESTS_EXE)

$(TESTS_EXE): $(HEADERS) $(TESTS)/$(TESTS_NAME).c
	gcc -c $(INCLUDE) $(TESTS)/$(TESTS_NAME).c -o $(TEMP)/$(TESTS_NAME).o
	gcc $(TEMP)/$(TESTS_NAME).o -o $(TESTS_EXE)

Clean:
	DEL /Q $(BIN)\*.dll $(BIN)\*.exe
	DEL /Q $(TEMP)\*.o