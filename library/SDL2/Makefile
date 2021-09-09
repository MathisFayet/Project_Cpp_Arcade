##
## EPITECH PROJECT, 2021
## B-OOP-400-BDX-4-1-arcade-mathis.fayet
## File description:
## Makefile
##

SRC	=	src/main.cpp	\
		src/OneForAll.cpp

SCR	=	src/OneForAll.cpp	\
		src/function_display.cpp	\
		src/init_structure.cpp

OBJ	=	$(SRC:.cpp=.o)

JBO	=	$(SCR:.cpp=.o)

NAME	=	SDL2

NAMESHARE	=	../../lib/arcade_sdl2.so

CFLAGS	=	-W -Wall -Wextra -I./include -lSDL2 -lSDL2_ttf -lSDL2_image -g

CFLAGSHARE	=	-I./include -shared -fPIC  -lSDL2 -lSDL2_ttf -lSDL2_image

all:	$(NAMESHARE)

sdl:	$(OBJ)
		@g++ -o $(NAME) $(OBJ) $(CFLAGS) && /bin/echo -e "\033[0;32m" "[OK]""\033[1;36m""  BUILD : SDL" "\033[00m" || /bin/echo -e "\033[5;31m" "[ERROR] :" "\033[1;36m" "SDL" "\033[00m"

$(NAMESHARE):	$(JBO)
		@g++ -o $(NAMESHARE) $(JBO) $(CFLAGSHARE) && /bin/echo -e "\033[0;32m" "[OK]""\033[1;36m""  BUILD : arcade_sdl2.so" "\033[00m" || /bin/echo -e "\033[5;31m" "[ERROR] :" "\033[1;36m" "SDL" "\033[00m"

.cpp.o:
		@g++ $(CFLAGSHARE) -c -o $@ $< && /bin/echo -e "\033[0;32m" "[OK]" "\033[1;36m" $< "--->" $@ "\033[00m" || /bin/echo -e "\033[5;31m" "[ERROR] doesn't exist" "\033[1;36m" $^ "\033[00m"

clean:
		@rm -f $(OBJ) && /bin/echo -e "\033[0;32m" "[OK] remove" "\033[1;36m" $(OBJ) "\033[00m" || /bin/echo -e "033[5;31m" "[ERROR] doesn't exist" "\033[1;36m" $(OBJ) "\033[00m"
		@rm -f $(JBO) && /bin/echo -e "\033[0;32m" "[OK] remove" "\033[1;36m" $(JBO) "\033[00m" || /bin/echo -e "033[5;31m" "[ERROR] doesn't exist" "\033[1;36m" $(JBO) "\033[00m"

fclean: 	clean
		@rm -f $(NAME) && /bin/echo -e "\033[0;32m" "[OK] remove" "\033[1;36m" "SDL"  "\033[00m" || /bin/echo -e "033[5;31m" "[ERROR] doesn't exist" "\033[1;36m" "SDL" "\033[00m"
		@rm -f $(NAMESHARE) && /bin/echo -e "\033[0;32m" "[OK] remove" "\033[1;36m" $(NAMESHARE)  "\033[00m" || /bin/echo -e "033[5;31m" "[ERROR] doesn't exist" "\033[1;36m" $(NAMESHARE) "\033[00m"
re:		fclean all

.PHONY:		all clean fclean re
