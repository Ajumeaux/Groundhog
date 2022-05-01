##
## EPITECH PROJECT, 2022
## Groundhog
## File description:
## Makefile
##

SRC =		Groundhog.cpp

CXX =		g++
CXXFLAGS =	-W -Wall -Wextra -g
NAME =		Groundhog

OBJ =		$(SRC:.cpp=.o)

all: $(OBJ)
	$(CXX) -o $(NAME) $(OBJ) $(LDFLAGS)

clean:
	$(RM) $(OBJ)

fclean: clean
	$(RM) $(NAME)

re: fclean all

test:
	re
	./tests/test1.sh