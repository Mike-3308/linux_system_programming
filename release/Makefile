CC = gcc
INCLUDE = ./../include/
SOURCE = ./../source/

macro_fork:
	@$(CC) $(SOURCE)main.c $(SOURCE)fork.c -I $(INCLUDE) -D MACRO_FORK -o ./fork.out
	@echo build fork complete

macro_wait:
	@$(CC) $(SOURCE)main.c $(SOURCE)wait.c -I $(INCLUDE) -D MACRO_WAIT -o ./wait.out
	@echo build fork complete

clean:
	@rm -rf ./*.out
	@echo clean complete
