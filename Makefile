PROJECT_NAME = Crypto.geso
CC=g++
PROJECT_SRC = .
vpath %.cpp $(PROJECT_SRC)

########################################################################
SRCS = Node.cpp
SRCS += StakePool.cpp User.cpp


########################################################################
INC_DIRS = Include
INCLUDE = $(addprefix -I ,$(INC_DIRS))
########################################################################

CFLAGS= -Wall \
        -pedantic \
	   		-g


LDFLAGS=

########################################################################

all: $(PROJECT_NAME)

$(PROJECT_NAME): $(SRCS)
	$(CC) $(INCLUDE) $(CFLAGS) $^ -o $@ $(LDFLAGS)

run:
	./$(PROJECT_NAME)

%.o: %.cpp
	$(CC) $< -c $(INCLUDE) $(CFLAGS)

clean:
	rm -f *.o $(PROJECT_NAME)
