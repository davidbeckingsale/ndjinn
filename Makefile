BUILDDIR := build
PRODUCT := ngine

SRCDIR := src

HDRS := $(wildcard $(SRCDIR)/*.h)
SRCS := $(wildcard $(SRCDIR)/*.C)
OBJS := $(SRCS:$(SRCDIR)/%.C=$(BUILDDIR)/%.o)

BINARY := $(PRODUCT)

CXX := g++
CXXFLAGS_DEBUG := -g
CXXFLAGS_OPT := -O3 -fast -fno-alias

LD := $(CXX)

# select optimized or debug
#CXXFLAGS := $(CXXFLAGS_OPT) $(CPPFLAGS)
CXXFLAGS := $(CXXFLAGS_DEBUG) $(CPPFLAGS)

all : $(BINARY)

$(BINARY) : $(OBJS)
	@echo linking $@
	$(maketargetdir)
	$(LD) -o $@ $^ $(LDFLAGS)

$(BUILDDIR)/%.o : $(SRCDIR)/%.C
	@echo compiling $<
	$(maketargetdir)
	$(CXX) $(CXXFLAGS) $(CXXINCLUDES) -c -o $@ $<

define maketargetdir
	-@mkdir -p $(dir $@) > /dev/null 2>&1
endef

clean :
	rm -f $(BINARY) $(OBJS) $(DEPS)
