TARGET = clockwork-midori
BINDIR = bin
BUILDLIB_PATH = $(BINDIR)/lib
SRCDIR = src

vpath %.c src 
vpath %.cpp src 
vpath %.h include
vpath %.o bin/lib 

PSP_OBJECTS = \
	$(addprefix src/common/, \
		kernel_callback.o \
		inputs.o \
	)
APPLICATION_OBJECTS = \
	$(addprefix src/app/, \
		lifecycle.o \
		timer.o \
		logic.o \
	)

OBJECTS = \
	$(PSP_OBJECTS) \
	$(APPLICATION_OBJECTS)

OBJS = main.o $(OBJECTS)

INCDIR = include
CFLAGS = -O2 -G0 -Wall
CXXFLAGS = $(CFLAGS) -fno-exceptions -fno-rtti
ASFLAGS = $(CFLAGS)

LIBDIR = 
LIBS = -lm
LDFLAGS =

EXTRA_TARGETS = EBOOT.PBP
PSP_EBOOT_TITLE = Clockwork Midori
PSP_EBOOT_ICON = resources/icon0.png

PSPSDK=$(shell psp-config --pspsdk-path)
include $(PSPSDK)/lib/build.mak

