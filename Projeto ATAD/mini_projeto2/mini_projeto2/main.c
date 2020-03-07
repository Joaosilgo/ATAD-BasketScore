/* MINI-PROJETO 2 ATAD 2018
* Identificacao dos Alunos:
*
*      Numero: ######### | Nome: Miguel Pires
*      Numero: ######### | Nome: João Gomes
*
*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "Commands.h"
#include <Windows.h>

/* definicao de prototipos de funcoes, definidas depois do main() */

void printCommandsMenu();
void test();
//...

void loader();
void bigLoader();
void createdBy();

/*
* Descrição do Programa
*/

int main(int argc, char** argv) {
	
	/* declaracao de variaveis */
	PtList lista = listCreate(1000);

	/* interpretador de comandos */
	char command[21];
	int quit = 0;
	while (!quit) {

		printCommandsMenu();
		fseek(stdin, 0, SEEK_END);
		fgets(command, sizeof(command), stdin);
		/* descartar 'newline'. Utilizar esta técnica sempre que for lida uma
		* string para ser utilizada, e.g., nome de ficheiro, chave, etc.. */
		command[strlen(command) - 1] = '\0';
		
		if (equalsStringIgnoreCase(command, "QUIT")) {
			quit = 1; 
			createdBy();
			listDestroy(&lista);
			/* vai provocar a saída do interpretador */
		}
		else if (equalsStringIgnoreCase(command, "LOAD")) {
			loader();
			importPlayers(lista);
		}
		else if (equalsStringIgnoreCase(command, "CLEAR")) {
			CLEAR(lista);
		}
		else if (equalsStringIgnoreCase(command, "SHOW")) {
			SHOW(lista);
		}
		else if (equalsStringIgnoreCase(command, "SORT")) {
			SORT(lista);
		}
		else if (equalsStringIgnoreCase(command, "AVG")) {
			AVG(lista);
		}
		else if (equalsStringIgnoreCase(command, "NORM")) {
			NORM(lista);
		}
		else if (equalsStringIgnoreCase(command, "TYPE")) {
			TYPE(lista);
		}
		else if (equalsStringIgnoreCase(command, "CHECKTYPE")) {
			CHECKTYPE(lista);
		}
		else { 
			printf("Comando nao encontrado.\n");
		}
	}

	system("pause");
	return (EXIT_SUCCESS);
}





void printCommandsMenu() {
	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), FOREGROUND_INTENSITY | 3);
	printf("\n                ===================================================================================\n");
	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), FOREGROUND_INTENSITY | 14);
	printf("                                           MINI-PROJECT2: Basket Scores2                                 ");
	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), FOREGROUND_INTENSITY | 3);
	printf("\n                ===================================================================================");
	printf("\n                        A. LOAD");
	printf("\n                        B. CLEAR");
	printf("\n                        C. SHOW");
	printf("\n                        D. SORT");
	printf("\n                        E. AVG");
	printf("\n                        F. TYPE");
	printf("\n                        G. CHECKTYPE");
	printf("\n                        H. KMEANS");
	printf("\n                        I. QUIT\n\n");
	printf("                  COMMAND> ");
	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), FOREGROUND_INTENSITY | 8);
}















void loader() {
	int i;
	char str[] = "               LOADING                  ";
	for (i = 0; i <= 40; i++) {
		printf("\r[%s]", str);
		str[i] = '|';
		Sleep(100);
	}
	
}



void bigLoader() {
	int i;
	char str[] = "                                      DATA DUMPING                                                  ";
	for (i = 0; i <= 100; i++) {
		printf(" \r         [%s]", str);
		str[i] = '|';
		Sleep(100);
	}
}



void createdBy()
{
	system("cls");
	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 3);
	printf("\n        ===================================================================================\n");
	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 14);
	printf("                                   MINI-PROJECT2: Basket Scores 2                                ");
	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 3);
	printf("\n        ===================================================================================");
	printf("\n        * Autores: 150221028 - Miguel Pires  ");
	printf("\n        * Autores: 150221001 - João da Silva Gomes");
	printf("\n        * Data[11 / 06 / 2018] ");
	printf("\n        * Docente	Anibal Pontes \n\n");
	printf("\nSaiu do programa!....See You Soon!! \n");
	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), FOREGROUND_INTENSITY | 8);
	bigLoader();


}

