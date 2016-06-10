.SUFFIXES:	# Delete the default suffixes
.SUFFIXES:	.cc .hh
.PHONY:		all clean astyle 

TARGET		= Sources/main
CC_FILES	= $(wildcard *.cc)
HH_FILES	= $(wildcard *.hh)
O_FILES = 	$(CC_FILES:%.cc=%.o)

default: all

all: $(TARGET)

$(TARGET):
	@(cd Sources && $(MAKE))

clean:
	@(cd Sources && $(MAKE) $@)
