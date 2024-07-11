BUILD_DIR=./build

C_SRCS := $(addprefix ./src/,$(shell cd src && find -name '*.c') )
C_OBJS := $(C_SRCS:./src/%.c=$(BUILD_DIR)/%.o)
C_DEPS := $(C_OBJS:.o=.d)

$(BUILD_DIR)/exe : $(C_OBJS)
	$(CC) $(C_OBJS) -o $@ $(LDFLAGS)
	$(BUILD_DIR)/exe

$(BUILD_DIR)/%.o : src/%.c
	mkdir -p $(@D)
	$(CC) -MMD -MP $(CFLAGS) -I./include -c $< -o $@
#	#$(CC) -E -I../include $(CFLAGS) $< -MM -MT $(@:.o=.d) > $(@:.o=.d)

# добавить/придумать, как сделать чтобы оно внедрялось только когда надо
include $(C_DEPS)