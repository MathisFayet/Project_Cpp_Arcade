##
## EPITECH PROJECT, 2020
## Makefile
## File description:
## to make it
##

SRC	=	src/main.cpp		\
		src/SFML.cpp

SCR	=	src/SFML.cpp		\
		src/function_display.cpp	\
		src/init_structure.cpp		\
		src/saveScore.cpp

OBJ	=	$(SRC:.cpp=.o)

JBO	=	$(SCR:.cpp=.o)

NAME	=	Sfml

NAMESHARE	=	../../lib/arcade_sfml.so

CFLAGS	=	-W -Wall -Wextra -I./include/SFML -lsfml-graphics -lsfml-window -lsfml-audio -lsfml-system

CFLAGSHARE	=	-I./include/SFML -shared -fPIC -lsfml-graphics -lsfml-window -lsfml-audio -lsfml-system

all:	$(NAMESHARE)

sfml:	$(OBJ)
		@g++ -o $(NAME) $(OBJ) $(CFLAGS) && /bin/echo -e "\033[0;32m" "[OK]""\033[1;36m""  BUILD : Sfml" "\033[00m" || /bin/echo -e "\033[5;31m" "[ERROR] :" "\033[1;36m" "Sfml" "\033[00m"

$(NAMESHARE):	$(JBO)
		@g++ -o $(NAMESHARE) $(JBO) $(CFLAGSHARE) && /bin/echo -e "\033[0;32m" "[OK]""\033[1;36m""  BUILD : arcade_sfml.so" "\033[00m" || /bin/echo -e "\033[5;31m" "[ERROR] :" "\033[1;36m" $(NAMESHARE) "\033[00m"

.cpp.o:
	@g++ $(CFLAGSHARE) -c -o $@ $< && /bin/echo -e "\033[0;32m" "[OK]" "\033[1;36m" $< "--->" $@ "\033[00m" || /bin/echo -e "\033[5;31m" "[ERROR] doesn't exist" "\033[1;36m" $^ "\033[00m"



clean:
		@rm -f $(OBJ) && /bin/echo -e "\033[0;32m" "[OK] remove" "\033[1;36m" $(OBJ) "\033[00m" || /bin/echo -e "033[5;31m" "[ERROR] doesn't exist" "\033[1;36m" $(OBJ) "\033[00m"
		@rm -f $(JBO) && /bin/echo -e "\033[0;32m" "[OK] remove" "\033[1;36m" $(JBO) "\033[00m" || /bin/echo -e "033[5;31m" "[ERROR] doesn't exist" "\033[1;36m" $(JBO) "\033[00m"

fclean: 	clean
		@rm -f $(NAME) && /bin/echo -e "\033[0;32m" "[OK] remove" "\033[1;36m" "Sfml"  "\033[00m" || /bin/echo -e "033[5;31m" "[ERROR] doesn't exist" "\033[1;36m" "Sfml" "\033[00m"
		@rm -f $(NAMESHARE) && /bin/echo -e "\033[0;32m" "[OK] remove" "\033[1;36m" $(NAMESHARE)  "\033[00m" || /bin/echo -e "033[5;31m" "[ERROR] doesn't exist" "\033[1;36m" $(NAMESHARE) "\033[00m"

re:		fclean all

.PHONY:		all clean fclean re
