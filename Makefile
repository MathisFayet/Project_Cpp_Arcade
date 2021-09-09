##
## EPITECH PROJECT, 2021
## B-OOP-400-BDX-4-1-arcade-mathis.fayet
## File description:
## Makefile de clochard
##

all : graphicals core games

core :
	make -C ./core/

games :
	make -C ./games/Nibbler/

graphicals :
	make -C ./librari/SFML/
	make -C ./librari/SDL2/
	make -C ./librari/nCurse/

clean :
	make clean -C core/
	make clean -C librari/SFML/
	make clean -C librari/SDL2/
	make clean -C games/Nibbler/
	make clean -C ./librari/nCurse/

fclean : clean
	make fclean -C librari/SFML/
	make fclean -C librari/SDL2/
	make fclean -C core/
	make fclean -C games/Nibbler/
	make fclean -C ./librari/nCurse/

re : fclean all

.PHONY: re all clean fclean core games graphicals
