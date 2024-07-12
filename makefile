$(info [!] start make)

#make test
#make lib

BUILD_DIR=./build

C_SRCS := $(addprefix ./src/,$(shell cd src && find -name '*.c' -printf '%f\n') )
C_OBJS := $(C_SRCS:./src/%.c=$(BUILD_DIR)/%.o)
C_DEPS := $(C_OBJS:.o=.d)

.PHONY: lib

lib: $(BUILD_DIR)/lib.a
	@echo "[!] see build"

$(BUILD_DIR)/lib.a : $(C_OBJS)
	ar rcs $(BUILD_DIR)/lib.a $(C_OBJS)

$(BUILD_DIR)/%.o : src/%.c
	mkdir -p $(@D)
	$(CC) $(CFLAGS) -I./include -c $< -o $@ 

#-MMD -MP

$(BUILD_DIR)/%.d : src/%.c
	mkdir -p $(@D)
	$(CC) -E $(CFLAGS) -I./include $< -MM -MP -MT $(@:.d=.o) > $@

.PHONY: clean

clean:
	-rm build/*

ifeq (0, $(words $(findstring $(MAKECMDGOALS), $(NODEPS))))
$(info [!] include C_DEPS)
# it goes through the file twice
include $(C_DEPS)
endif

.PHONY: test

test: $(BUILD_DIR)/test
	@echo '[!] test start'
	@./$(BUILD_DIR)/test
	@echo -e '\n[!] test end'

$(BUILD_DIR)/test: $(BUILD_DIR)/test.o $(BUILD_DIR)/lib.a
	$(CC) $(CFLAGS) -I./include $< $(BUILD_DIR)/lib.a -o $@ 

$(BUILD_DIR)/test.o: test/test.c
	$(CC) $(CFLAGS) -I./include -c $< -o $@ 

$(BUILD_DIR)/test.d: test/test.c
	$(CC) -E $(CFLAGS) -I./include $< -MM -MP -MT $(@:.d=.o) > $@


ifeq (1, $(words $(findstring $(MAKECMDGOALS), test)))
$(info [!] include test.d)
include $(BUILD_DIR)/test.d
endif