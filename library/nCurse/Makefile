##
## EPITECH PROJECT, 2021
## nCurse
## File description:
## Makefile
##

RM_F	=	rm -f

CC		= 	g++ -o

SRC		=	src/Ncurse.cpp

OBJ		=	$(SRC:.cpp=.o)

NAME	=	../../lib/arcade_ncurses.so

CFLAGS	=	-shared -fPIC -I./include/ -lncurses

all:	$(NAME)

$(NAME):	$(OBJ)
		@g++ -o $(NAME) $(OBJ) $(CFLAGS) && /bin/echo -e "\033[0;32m" "[OK]""\033[1;36m""  BUILD : Sfml" "\033[00m" || /bin/echo -e "\033[5;31m" "[ERROR] :" "\033[1;36m" "Sfml" "\033[00m"

.cpp.o:
		@g++ $(CFLAGS) -c -o $@ $< && /bin/echo -e "\033[0;32m" "[OK]" "\033[1;36m" $< "--->" $@ "\033[00m" || /bin/echo -e "\033[5;31m" "[ERROR] doesn't exist" "\033[1;36m" $^ "\033[00m"


clean:
	$(RM_F) $(OBJ)

fclean: clean
	$(RM_F) $(NAME)

re: fclean all

.PHONY:	all clean fclean re
