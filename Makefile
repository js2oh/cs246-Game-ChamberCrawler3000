CXX = g++
CXXFLAGS = -std=c++14 -g -Wall -Werror -MMD
EXEC = cc3k

MAINOBJ = main.o
BOARDOBJ = board/cell.o board/chamber.o board/floor.o board/input.o board/textdisplay.o
ENEMYOBJ = character/enemy/dragon.o character/enemy/dwarf.o character/enemy/elf.o character/enemy/enemy.o character/enemy/enemyfactory.o character/enemy/halfling.o character/enemy/human.o character/enemy/merchant.o character/enemy/orc.o
PLAYEROBJ = character/player/drow.o character/player/goblin.o character/player/player.o character/player/shade.o character/player/troll.o
CHARACTEROBJ = character/character.o character/characterfactory.o
ITEMOBJ = item/item.o item/itemfactory.o
POTIONOBJ = item/potion/boostatk.o item/potion/boostdef.o item/potion/poison.o item/potion/potion.o item/potion/potionfactory.o item/potion/restore.o item/potion/woundatk.o item/potion/wounddef.o
TREASUREOBJ = item/treasure/gold.o item/treasure/treasurefactory.o

OBJECTS = ${MAINOBJ} ${BOARDOBJ} ${ENEMYOBJ} ${PLAYEROBJ} ${CHARACTEROBJ} ${ITEMOBJ} ${POTIONOBJ} ${TREASUREOBJ}
DEPENDS = ${OBJECTS:.o=.d}

${EXEC}: ${OBJECTS}
	${CXX} ${CXXFLAGS} ${OBJECTS} -o ${EXEC}

-include ${DEPENDS}

clean:
	rm ${OBJECTS} ${EXEC} ${DEPENDS}
.PHONY: clean