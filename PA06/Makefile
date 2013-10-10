GCC = gcc
TARGET = pa06
HEADER = pa06.h
CFLAGS = -g -Wall -Wshadow
OBJ = obj
OBJS = $(OBJ)/pa06.o $(OBJ)/answer06.o
OUT = output
INPUT = images
TESTN := $(shell seq 1 5)
TESTS := $(addprefix test,${TESTN})
SUCCESS = 0
# ===================================================================================

.DEFAULT_GOAL := build
.PHONY : clean build enviornment testall 

build : $(TARGET)

enviornment :
	@cd $(CURDIR)
	@mkdir -p $(OBJ)
	@mkdir -p $(OUT)

$(OBJ)/%.o : %.c $(HEADER) | enviornment 
	$(GCC) -c $(CFLAGS) $< -o $@

$(TARGET) : $(OBJS) | enviornment
	$(GCC) $(CFLAGS) $^ -o $@ 

testall: | $(TESTS) bad

clean :
	@rm -rf $(OBJ) $(OUT)
	@rm $(TARGET)

${TESTS}: test%: $(TARGET) | enviornment	
	@valgrind -q --tool=memcheck --log-file=$(OUT)/valgrind-0$* --leak-check=full --verbose ./$(TARGET) $(abspath $(INPUT)/0$**) $(OUT)/0$*-output.ppm  
	@diff -q $(OUT)/0$*-output.ppm $(abspath expected/0$**)
	@cat $(OUT)/valgrind-0$* | grep -q "ERROR SUMMARY: 0 errors from 0 context"
	@echo "Test $* Done"

bad: $(TARGET) | enviornment
	@ls images/corrupt-testcases | while read L ; do printf %s " && ! ./pa06 $$L outputs/dummy.ppm" ; done | sed 's,^,true ,' | bash

