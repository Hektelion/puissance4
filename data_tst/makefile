#############################
#	MAKEFILE ESCLAVE TEST	#
# 	  PROJET PUISSANCE4 	#
#############################

#############################
#		  VARIABLES			#
#############################

CC=gcc
CFLAGS=-W -Wall
LDFLAGS=
EXEC=test_puissance4

#############################
#		   REGLES			#
#############################

all: mrproper $(EXEC) clean

$(EXEC): ./obj/main.o
	@echo "Creation de l'executable $@"
	$(CC) -o $@ ./obj/main.o ./obj/tst_function.o $(LDFLAGS)

./obj/main.o: ./obj/tst_function.o
	@echo "Creation de $@"
	$(CC) -o $@ ./src/main.c -c $^ $(CFLAGS)

./obj/tst_function.o:
	@echo "Creation de $@"
	$(CC) -o $@ -c ./src/tst_function.c $(CFLAGS)

#############################
#		REGLES AUTRE		#
#############################

.PHONY: mrproper clean test

mrproper: clean
	rm ../$(EXEC)

clean:
	rm ./obj/*