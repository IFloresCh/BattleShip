/*
 * Battleship.c
 *
 *  Created on: 19 jan 2022
 *      Author: isaacflores
 */

#include <stdio.h>
#define ROWS 10
#define COLS 10

void main() {

	int diff = 0, intentos = 0, i = 0, j = 0, a_fila = 0, a_col = 0;
	int tablero[ROWS][COLS];
	printf("XXXXX   XXXX  XXXXXX XXXXXX XX     XXXXXX  XXXXX XX  XX XX XXXX\n");
	printf("XX  XX XX  XX   XX     XX   XX     XX     XX     XX  XX XX XX  XX\n");
	printf("XXXXX  XX  XX   XX     XX   XX     XXXX    XXXX  XXXXXX XX XXXX\n");
	printf("XX  XX XXXXXX   XX     XX   XX     XX         XX XX  XX XX XX\n");
	printf("XXXXX  XX  XX   XX     XX   XXXXXX XXXXXX XXXXX  XX  XX XX XX\n");
	printf("\n\n");
	printf("Escoge la dificultad:\n");
    printf("1. Fácil\n");
	printf("2. Medio\n");
	printf("3. Dificil\n");
	scanf("%d", &diff);
	//validar entre 1 y 3. Tambien los 3 intentos
	   if( diff > 3 || diff < 1){
	        while (intentos < 2){
	        	printf("Elige una opcion correcta!\n");
	            printf("1. Fácil\n");
	        	printf("2. Medio\n");
	        	printf("3. Dificil\n");
	            scanf("%d",&diff);
	            intentos += 1;
	        }
	    }



	switch (diff) {
	//no pide diferenciar entre dificultades asi que uso los case sin break
	case 1:
	case 2:
	case 3:
		if (diff == 1) {
			printf("Has escogido la dificultad Fácil\n");
		} else if (diff == 2) {
			printf("Has escogido la dificultad Medio\n");
		} else if (diff == 3) {
			printf("Has escogido la dificultad Dificil\n");
		}
//inicia el tablero en ceros
		for (i = 0; i <= ROWS; i++) {
			for (j = 0; j <= COLS; j++) {
				tablero[i][j] = 0;
			}
		}

//posicionando barcos segun la imagen de la practica
		for (i = 0; i <= ROWS; i++) {
			for (j = 0; j <= COLS; j++) {
				if (tablero[i][j] == 0) {
					tablero[1][8] = 1;
					tablero[2][8] = 1;
					tablero[3][8] = 1;
					tablero[2][2] = 1;
					tablero[3][2] = 1;
					tablero[4][2] = 1;
					tablero[2][4] = 1;
					tablero[2][5] = 1;
					tablero[5][4] = 1;
					tablero[5][5] = 1;
					tablero[5][6] = 1;
					tablero[5][7] = 1;
					tablero[8][2] = 1;
					tablero[8][3] = 1;
					tablero[8][4] = 1;
					tablero[8][5] = 1;
					tablero[8][6] = 1;
				}
			}
		}
//muestra el tablero en pantalla
		printf("\t[0]\t[1]\t[2]\t[3]\t[4]\t[5]\t[6]\t[7]\t[8]\t[9]\n");
		printf("      _____________________________________________________________________________\n");
		for (i = 0; i < ROWS; i++) {
			printf("[%d]  |", i);
			for (j = 0; j < COLS; j++) {
				printf("\t[ ]");
			}
			printf("\n");
		}

//donde vamos a atacar
		do {
			printf("Ingrese el numero de fila: ");
			scanf("%d", &a_fila);
		} while (a_fila < 0 || a_fila > 10);
		do {
			printf("Ingrese el numero de columna: ");
			scanf("%d", &a_col);

		} while (a_col < 0 || a_col > 10);

//verificar si esta un barco en la casilla
		if (tablero[a_fila][a_col] == 0) {
			printf("has fallado!\n");
			tablero[a_fila][a_col] = 2;
		} else if (tablero[a_fila][a_col] == 1) {
			printf("has acertado!\n");
			tablero[a_fila][a_col] = 2;
		} else if (tablero[a_fila][a_col] == 2) {
			printf("has fallado!\n");
			tablero[a_fila][a_col] = 2;
		}
// mostrar el tablero * para los barcos la X donde disparaste
		printf("\t[0]\t[1]\t[2]\t[3]\t[4]\t[5]\t[6]\t[7]\t[8]\t[9]\n");
		printf("      _____________________________________________________________________________\n");
		for (i = 0; i < ROWS; i++) {
			printf("[%d]  |", i);
			for (j = 0; j < COLS; j++) {
				if (tablero[i][j] == 1) {
					printf("\t[*]");
				} else if (tablero[i][j] == 2) {
					printf("\t X");
				} else if (tablero[i][j] == 0) {
					printf("\t[ ]");
				}
			}
			printf("\n");
		}

		break;

	}

}

