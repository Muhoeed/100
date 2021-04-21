CXXFLAGS       = -Wall -Werror
CXXFLAGS_TEST  = -Wall

BINDIR           = bin
SRCDIR           = src
TESTDIR          = test
BUILD_SRCDIR     = build/src
BUILD_TESTDIR    = build/test

OBJECT          = $(patsubst $(SRCDIR)/%.cpp,  $(BUILD_SRCDIR)/%.o,  $(wildcard $(SRCDIR)/*.cpp))
OBJECT_TEST     = $(patsubst $(TESTDIR)/%.cpp, $(BUILD_TESTDIR)/%.o, $(wildcard $(TESTDIR)/*.cpp))
TARGET          = $(BINDIR)/100
TARGET_TEST     = $(BINDIR)/100test

.PHONY: all test clean

all: $(TARGET)
	$(TARGET)

$(TARGET): $(OBJECT)
	$(CXX) $(CXXFLAGS) -o $@ $^

$(BUILD_SRCDIR)/%.o: $(SRCDIR)/%.cpp $(SRCDIR)/100matches.hpp
	$(CXX) $(CXXFLAGS) -c $< -o $@

test: $(TARGET_TEST)
	$(TARGET_TEST)

$(TARGET_TEST): $(OBJECT_TEST)
	$(CXX) -o $@ $^

$(BUILD_TESTDIR)/%.o: $(TESTDIR)/%.cpp thirdparty/ctest.h
	$(CXX) -c $< -o $@

cln:
	rm -f $(TARGET) $(OBJECT)

tcln:
	rm -f $(TARGET_TEST) $(OBJECT_TEST)