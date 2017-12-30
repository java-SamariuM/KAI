#include <stdio.h>
#include <stdlib.h>
#include <math.h>

int notinHexagons(int n, int m, int places[31][7], int *hexagons[7][7]){
	int i, j;
	for(i = 4; i < 7; i++)
		for(j = 0; j < 7; j++){
			if(places[n][i] == -1)
				return 1;
			if(m == *hexagons[places[n][i]][j])
				return 0;
		}
	return 1;
}

int notinRows(int n, int m, int places[31][7], int *rows[3][7][7]){
	int i, j;
	for(i = 0; i < 3; i++)
		for(j = 0; rows[i][places[n][i + 1]][j] != NULL; j++){
			if(m == *rows[i][places[n][i + 1]][j])
				return 0;
		}
	return 1;
}

int SET(int n, int k, int *rows[3][7][7], int places[31][7], int *hexagons[7][7]){
	int i;
	if(places[n][0] == 0){
		for(i = 1; i <= k; i++){
			if(notinRows(n, i, places, rows) && notinHexagons(n, i, places, hexagons)){
				places[n][0] = i;
				if(n < 30){
					if(SET(n + 1, k, rows, places, hexagons))
						return 1;
				}
				else
					return 1;
				places[n][0] = 0;
			}
		}
		return 0;
	}
	else if(n < 30){
		if(SET(n + 1, k, rows, places, hexagons))
			return 1;
		else
			return 0;
	}
	else
		return 1;
}

int main(){
	int places[31][7], k, i;
	scanf("%d", &k);
	for(i = 0; i < 31; i++)
		scanf("%d", &places[i][0]);
	int *rows[3][7][7];
	rows[0][0][0] = places[0], rows[0][0][1] = places[1], rows[0][0][2] = NULL;
	rows[0][1][0] = places[2], rows[0][1][1] = places[3], rows[0][1][2] = places[4], rows[0][1][3] = places[5], rows[0][1][4] = places[6], rows[0][1][5] = NULL;
	rows[0][2][0] = places[7], rows[0][2][1] = places[8], rows[0][2][2] = places[9], rows[0][2][3] = places[10], rows[0][2][4] = places[11], rows[0][2][5] = places[12], rows[0][2][6] = NULL;
	rows[0][3][0] = places[13], rows[0][3][1] = places[14], rows[0][3][2] = places[15], rows[0][3][3] = places[16], rows[0][3][4] = places[17], rows[0][3][5] = NULL;
	rows[0][4][0] = places[18], rows[0][4][1] = places[19], rows[0][4][2] = places[20], rows[0][4][3] = places[21], rows[0][4][4] = places[22], rows[0][4][5] = places[23], rows[0][4][6] = NULL;
	rows[0][5][0] = places[24], rows[0][5][1] = places[25], rows[0][5][2] = places[26], rows[0][5][3] = places[27], rows[0][5][4] = places[28], rows[0][5][5] = NULL;
	rows[0][6][0] = places[29], rows[0][6][1] = places[30], rows[0][6][2] = NULL;
	rows[1][0][0] = places[6], rows[1][0][1] = places[12], rows[1][0][2] = NULL;
	rows[1][1][0] = places[1], rows[1][1][1] = places[5], rows[1][1][2] = places[11], rows[1][1][3] = places[17], rows[1][1][4] = places[23], rows[1][1][5] = NULL;
	rows[1][2][0] = places[0], rows[1][2][1] = places[4], rows[1][2][2] = places[10], rows[1][2][3] = places[16], rows[1][2][4] = places[22], rows[1][2][5] = places[28], rows[1][2][6] = NULL;
	rows[1][3][0] = places[3], rows[1][3][1] = places[9], rows[1][3][2] = places[15], rows[1][3][3] = places[21], rows[1][3][4] = places[27], rows[1][3][5] = NULL;
	rows[1][4][0] = places[2], rows[1][4][1] = places[8], rows[1][4][2] = places[14], rows[1][4][3] = places[20], rows[1][4][4] = places[26], rows[1][4][5] = places[30], rows[1][4][6] = NULL;
	rows[1][5][0] = places[7], rows[1][5][1] = places[13], rows[1][5][2] = places[19], rows[1][5][3] = places[25], rows[1][5][4] = places[29], rows[1][5][5] = NULL;
	rows[1][6][0] = places[18], rows[1][6][1] = places[24], rows[1][6][2] = NULL;
	rows[2][0][0] = places[2], rows[2][0][1] = places[7], rows[2][0][2] = NULL;
	rows[2][1][0] = places[0], rows[2][1][1] = places[3], rows[2][1][2] = places[8], rows[2][1][3] = places[13], rows[2][1][4] = places[18], rows[2][1][5] = NULL;
	rows[2][2][0] = places[1], rows[2][2][1] = places[4], rows[2][2][2] = places[9], rows[2][2][3] = places[14], rows[2][2][4] = places[19], rows[2][2][5] = places[24], rows[2][2][6] = NULL;
	rows[2][3][0] = places[5], rows[2][3][1] = places[10], rows[2][3][2] = places[15], rows[2][3][3] = places[20], rows[2][3][4] = places[25], rows[2][3][5] = NULL;
	rows[2][4][0] = places[6], rows[2][4][1] = places[11], rows[2][4][2] = places[16], rows[2][4][3] = places[21], rows[2][4][4] = places[26], rows[2][4][5] = places[29], rows[2][4][6] = NULL;
	rows[2][5][0] = places[12], rows[2][5][1] = places[17], rows[2][5][2] = places[22], rows[2][5][3] = places[27], rows[2][5][4] = places[30], rows[2][5][5] = NULL;
	rows[2][6][0] = places[23], rows[2][6][1] = places[28], rows[2][6][2] = NULL;
	int *hexagons[7][7] = {{places[0], places[1], places[3], places[4], places[5], places[9], places[10]}, {places[5], places[6], places[10], places[11], places[12], places[16], places[17]}, {places[2], places[3], places[7], places[8], places[9], places[13], places[14]}, {places[9], places[10], places[14], places[15], places[16], places[20], places[21]}, {places[16], places[17], places[21], places[22], places[23], places[27], places[28]}, {places[13], places[14], places[18], places[19], places[20], places[24], places[25]}, {places[20], places[21], places[25], places[26], places[27], places[29], places[30]},};
	places[0][1] = places[1][1] = 0;
	places[2][1] = places[3][1] = places[4][1] = places[5][1] = places[6][1] = 1;
	places[7][1] = places[8][1] = places[9][1] = places[10][1] = places[11][1] = places[12][1] = 2;
	places[13][1] = places[14][1] = places[15][1] = places[16][1] = places[17][1] = 3;
	places[18][1] = places[19][1] = places[20][1] = places[21][1] = places[22][1] = places[23][1] = 4;
	places[24][1] = places[25][1] = places[26][1] = places[27][1] = places[28][1] = 5;
	places[29][1] = places[30][1] = 6;
	places[6][2] = places[12][2] = 0;
	places[1][2] = places[5][2] = places[11][2] = places[17][2] = places[23][2] = 1;
	places[0][2] = places[4][2] = places[10][2] = places[16][2] = places[22][2] = places[28][2] = 2;
	places[3][2] = places[9][2] = places[15][2] = places[21][2] = places[27][2] = 3;
	places[2][2] = places[8][2] = places[14][2] = places[20][2] = places[26][2] = places[30][2] = 4;
	places[7][2] = places[13][2] = places[19][2] = places[25][2] = places[29][2] = 5;
	places[18][2] = places[24][2] = 6;
	places[2][3] = places[7][3] = 0;
	places[0][3] = places[3][3] = places[8][3] = places[13][3] = places[18][3] = 1;
	places[1][3] = places[4][3] = places[9][3] = places[14][3] = places[19][3] = places[24][3] = 2;
	places[5][3] = places[10][3] = places[15][3] = places[20][3] = places[25][3] = 3;
	places[6][3] = places[11][3] = places[16][3] = places[21][3] = places[26][3] = places[29][3] = 4;
	places[12][3] = places[17][3] = places[22][3] = places[27][3] = places[30][3] = 5;
	places[23][3] = places[28][3] = 6;
	places[0][4] = 0, places[0][5] = -1, places[0][6] = -1;
	places[1][4] = 0, places[1][5] = -1, places[1][6] = -1;
	places[2][4] = 2, places[2][5] = -1, places[2][6] = -1;
	places[3][4] = 0, places[3][5] = 2, places[3][6] = -1;
	places[4][4] = 0, places[4][5] = -1, places[4][6] = -1;
	places[5][4] = 0, places[5][5] = 1, places[5][6] = -1;
	places[6][4] = 1, places[6][5] = -1, places[6][6] = -1;
	places[7][4] = 2, places[7][5] = -1, places[7][6] = -1;
	places[8][4] = 2, places[8][5] = -1, places[8][6] = -1;
	places[9][4] = 0, places[9][5] = 2, places[9][6] = 3;
	places[10][4] = 0, places[10][5] = 1, places[10][6] = 3;
	places[11][4] = 1, places[11][5] = -1, places[11][6] = -1;
	places[12][4] = 1, places[12][5] = -1, places[12][6] = -1;
	places[13][4] = 2, places[13][5] = 5, places[13][6] = -1;
	places[14][4] = 2, places[14][5] = 3, places[14][6] = 5;
	places[15][4] = 3, places[15][5] = -1, places[15][6] = -1;
	places[16][4] = 1, places[16][5] = 3, places[16][6] = 4;
	places[17][4] = 1, places[17][5] = 4, places[17][6] = -1;
	places[18][4] = 5, places[18][5] = -1, places[18][6] = -1;
	places[19][4] = 5, places[19][5] = -1, places[19][6] = -1;
	places[20][4] = 3, places[20][5] = 5, places[20][6] = 6;
	places[21][4] = 3, places[21][5] = 4, places[21][6] = 6;
	places[22][4] = 4, places[22][5] = -1, places[22][6] = -1;
	places[23][4] = 4, places[23][5] = -1, places[23][6] = -1;
	places[24][4] = 5, places[24][5] = -1, places[24][6] = -1;
	places[25][4] = 5, places[25][5] = 6, places[25][6] = -1;
	places[26][4] = 6, places[26][5] = -1, places[26][6] = -1;
	places[27][4] = 4, places[27][5] = 6, places[27][6] = -1;
	places[28][4] = 4, places[28][5] = -1, places[28][6] = -1;
	places[29][4] = 6, places[29][5] = -1, places[29][6] = -1;
	places[30][4] = 6, places[30][5] = -1, places[30][6] = -1;
	SET(0, k, rows, places, hexagons);
	for(i = 0; i < 31; i++)
		printf("%d ", places[i][0]);
}
