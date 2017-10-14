CC := g++-7.1
IDIR := include
CXXFLAGS := -Wall -std=c++1z -I$(IDIR) -MMD

SDIR := source
ODIR := obj

TARGET := test

SRCS := Endianess.cpp Serializable.cpp attributes/AttributeValue.cpp\
attributes/dates/Dates.cpp attributes/types/BasicDate.cpp\
attributes/types/BasicInteger.cpp attributes/types/Charset.cpp\
attributes/types/Enumerable.cpp attributes/types/LinkType.cpp\
attributes/types/List.cpp attributes/types/MimeType.cpp\
attributes/types/MimeTypeSuperset.cpp attributes/types/PossibleValueTypes.cpp\
attributes/types/Boolean.cpp attributes/types/TextAttribute.cpp\
attributes/integers/Integer.cpp\
Attribute.cpp attributes/NonStandardAttribute.cpp

OBJS := $(patsubst %.cpp, $(ODIR)/%.o, $(SRCS))

$(ODIR)/%.o: $(SDIR)/%.cpp
	mkdir -p $(patsubst %/.o,%, $(@D))
	$(CC) $(CXXFLAGS) -c $< -o $@

all: $(TARGET)
$(TARGET): $(OBJS)
	$(CC) $(CXXFLAGS) -o $@ $^
clean:
	rm -rf $(ODIR) $(TARGET)
	
.PHONY: all clean