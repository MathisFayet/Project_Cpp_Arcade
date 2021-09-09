##
## EPITECH PROJECT, 2021
## B-OOP-400-BDX-4-1-arcade-mathis.fayet
## File description:
## Makefile
##

CC = g++

CFLAGS = -W -Wall -Wextra -I include/ -ldl

SRC =	src/main.cpp	\
	../Core.cpp

OBJ = $(SRC:.cpp=.o)

NAME = ../arcade

all:	$(NAME)

$(NAME):	$(OBJ)
		$(CC) -o $(NAME) $(CFLAGS) $(OBJ)

clean :
	rm -rf $(OBJ)

fclean : clean
	rm -rf arcade
	rm -rf ../arcade

re : fclean all

%.o: %.cpp
	$(CC) $(CXXFLAGS) -o $@ -c $<

.PHONY: re all clean fclean core games graphicals
