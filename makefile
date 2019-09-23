#############################
#	   MAKEFILE MAITRE		#
# 	  PROJET PUISSANCE4 	#
#############################

#############################
#		  VARIABLES			#
#############################

CC=gcc
CFLAGS=-W -Wall
LDFLAGS=
EXEC=puissance4

#UTILISER WILDCARD

#############################
#		   REGLES			#
#############################

all: mrproper $(EXEC) clean

$(EXEC): ./obj/main.o
	@echo "Creation de l'executable $@"
	$(CC) -o $@ ./obj/main.o ./obj/function.o $(LDFLAGS)

./obj/main.o: ./obj/function.o
	@echo "Creation de $@"
	$(CC) -o $@ ./src/main.c -c $^ $(CFLAGS)

./obj/function.o:
	@echo "Creation de $@"
	$(CC) -o $@ -c ./src/function.c $(CFLAGS)

test:
	@echo "Creation de l'executable de test"
	make --directory=data_tst all

#############################
#		REGLES AUTRE		#
#############################

.PHONY: mrproper clean test

mrproper: clean
	rm -f $(EXEC)

clean:
	rm -f ./obj/*