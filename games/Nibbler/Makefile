##
## EPITECH PROJECT, 2021
## B-OOP-400-BDX-4-1-arcade-mathis.fayet
## File description:
## Makefile
##

SRC		=	src/Nibbler.cpp

OBJ		=	$(SRC:.cpp=.o)

NAME		=	../arcade_nibbler.so

CFLAGS	=	-shared -fPIC

all: $(NAME)

$(NAME):	$(OBJ)
		@g++ -o $(NAME) $(OBJ) $(CFLAGS)

.cpp.o:
		@g++ $(CFLAGS) -c -o $@ $< && /bin/echo -e "\033[0;32m" "[OK]" "\033[1;36m" $< "--->" $@ "\033[00m" || /bin/echo -e "\033[5;31m" "[ERROR] doesn't exist" "\033[1;36m" $^ "\033[00m"


clean:
		@rm -f $(OBJ)
fclean:	clean
		@rm -f $(NAME)

re: fclean all

.PHONY:		all clean fclean re
