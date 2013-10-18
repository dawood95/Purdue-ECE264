GCC = gcc
TARGET = pa07
HEADER = pa07.h
CFLAGS = -g -Wall -Wshadow -Werror
OBJ = obj
OBJS = $(OBJ)/pa07.o $(OBJ)/answer07.o
OUT = output
INPUT = inputs
TESTN := $(shell seq 1 10)
TESTS := $(addprefix test,${TESTN})


.DEFAULT_GOAL := build
.PHONY := clean build enviornment testall

build: $(TARGET)

enviornment:
	@cd $(CURDIR)
	@mkdir -p $(OBJ)
	@mkdir -p $(OUT)

clean:
	@rm -rf $(OBJ) $(OUT)
	@rm -f $(TARGET)

$(OBJ)/%.o : %.c $(HEADER) | enviornment
	$(GCC) -c $(CFLAGS) $< -o $@

$(TARGET) : $(OBJS) | enviornment
	$(GCC) $(CFLAGS) $^ -o $@

testall : $(TESTS) 

${TESTS}: test%: $(TARGET) | enviornment
	@valgrind -q --tool=memcheck --log-file=$(OUT)/valgrind-0$* --leak-check=full --verbose ./$(TARGET) $(INPUT)/input$*_A $(INPUT)/input$*_B > $(OUT)/output$*
	@diff -q $(OUT)/output$* expected/expected$*
	@cat $(OUT)/valgrind-0$* | grep -q "ERROR SUMMARY: 0 errors from 0 context"
	@echo "Test$* Success"
