#include <bits/stdc++.h>


using namespace std;

int hexagon[10][10];
bool mark[10][10] = { false }; //if it is a part of hexagon
bool defaultNum[10][10] = {false}; //if it is a valued thing
bool has0degreeline[10][32]= {false};
bool has30degreeline[10][32] = {false};
bool has60degreeline[20][32] = {false};
bool hasHexagon[10][10][32] = {false};
pair <int,int> hexFinderGraf[10][10][3];
int hexCount[10][10]={0};
int k;

void reciever(void);

void giver(void);

void makeGraf(void);

bool isCenter(int x, int y);

bool putInPlace(int x, int y, int num);

bool removeFromPlace(int x, int y, int num);

bool makeHexoco(int x, int y);

//#define Debug

int main() {
    cin >> k;
    reciever();
    makeGraf();
    #ifdef Debug
    cout << "isCenter and makeGraf function check:" << endl<< hexCount[4][4] <<endl;
    for(int i = 0; i < hexCount[4][4]; i++){
        cout << hexFinderGraf[4][4][i].first <<" "<< hexFinderGraf[4][4][i].second<<endl;
    }

    putInPlace(3, 4, 8);
    cout << "putInPlace fuction check:\n" << "hexagon[3][4] is " << hexagon[4][3] <<endl;
    cout << "has0degreeline[4][8] is " << has0degreeline[4][8] << endl;
    cout << "has30degreeline[3][8] is " << has30degreeline[3][8] << endl;
    cout << "has60degreeline[4-3+10][8] is " << has60degreeline[11][8] <<endl;
    cout << "hasHexagon[3][3][8] is " << hasHexagon[3][3][8] <<endl;

    cout << "has0degreeline[1][8] is " << has0degreeline[1][8] << endl;
    cout << "has30degreeline[1][8] is " << has30degreeline[1][8] << endl;
    cout << "has60degreeline[10][8] is " << has60degreeline[10][8] <<endl;
    cout << "hasHexagon[3][3][8] is " << hasHexagon[2][1][8] <<endl;

    removeFromPlace(3, 4, 8);
    cout << "removeFromPlace fuction check:\n" << "hexagon[3][4] is " << hexagon[4][3] <<endl;
    cout << "has0degreeline[4][8] is " << has0degreeline[4][8] << endl;
    cout << "has30degreeline[3][8] is " << has30degreeline[3][8] << endl;
    cout << "has60degreeline[4-3+10][8] is " << has60degreeline[11][8] <<endl;
    cout << "hasHexagon[3][3][8] is " << hasHexagon[3][3][8] <<endl;

    cout << "has0degreeline[1][8] is " << has0degreeline[1][8] << endl;
    cout << "has30degreeline[1][8] is " << has30degreeline[1][8] << endl;
    cout << "has60degreeline[10][8] is " << has60degreeline[10][8] <<endl;
    cout << "hasHexagon[3][3][8] is " << hasHexagon[2][1][8] <<endl;
    #endif // Debug
    makeHexoco(1, 0);
    giver();
	return 0;

}

bool isCenter(int x, int y){ //ok
    if((x == 1) && (y == 2)){
        return true;
    }
    if((x == 2) && (y == 1)){
        return true;
    }
    if((x == 3) && (y == 3)){
        return true;
    }
    if((x == 2) && (y == 4)){
        return true;
    }
    if((x == 4) && (y == 2)){
        return true;
    }
    if((x == 4) && (y == 5)){
        return true;
    }
    if((x == 5) && (y == 4)){
        return true;
    }
    return false;
}

void makeGraf(void){  //ok
    for(int j = 0; j < 10; j++){
        for(int i = 0; i < 10; i++){
            if(mark[j][i]){
                if(isCenter(i, j)){
                    hexCount[j][i] = 1;
                    hexFinderGraf[j][i][0].first = i;
                    hexFinderGraf[j][i][0].second = j;
                    continue;
                }
                else{
                    for(int t = -1; t <= 1; t+=2){
                        if(isCenter(i+t, j)){
                            hexFinderGraf[j][i][ hexCount[j][i] ].first = i+t;
                            hexFinderGraf[j][i][ hexCount[j][i] ].second = j;
                            hexCount[j][i]++;
                        }
                        if(isCenter(i, j+t)){
                            hexFinderGraf[j][i][ hexCount[j][i] ].first = i;
                            hexFinderGraf[j][i][ hexCount[j][i] ].second = j+t;
                            hexCount[j][i]++;
                        }
                        if(isCenter(i+t, j+t)){
                            hexFinderGraf[j][i][ hexCount[j][i] ].first = i+t;
                            hexFinderGraf[j][i][ hexCount[j][i] ].second = j+t;
                            hexCount[j][i]++;
                        }

                    }
                }
            }
        }
    }
}

bool putInPlace(int x, int y, int num){ //ok
    if( (!has0degreeline[y][num]) && (!has30degreeline[x][num]) && (!has60degreeline[y-x+10][num]) ){
        for(int i = 0; i < hexCount[y][x]; i++){
            if(hasHexagon[hexFinderGraf[y][x][i].second][hexFinderGraf[y][x][i].first][num]){
                return false;
            }
        }
        hexagon[y][x] = num;
        has0degreeline[y][num] = true;
        has30degreeline[x][num] = true;
        has60degreeline[y-x+10][num] = true;
        for(int i = 0; i < hexCount[y][x]; i++){
            hasHexagon[hexFinderGraf[y][x][i].second][hexFinderGraf[y][x][i].first][num] = true;
        }
        return true;
    }
    return false;
}

bool removeFromPlace(int x, int y, int num){ //ok
    hexagon[y][x] = 0;
    has0degreeline[y][num] = false;
    has30degreeline[x][num] = false;
    has60degreeline[y-x+10][num] = false;
    for(int i = 0; i < hexCount[y][x]; i++){
        hasHexagon[hexFinderGraf[y][x][i].second][hexFinderGraf[y][x][i].first][num] = false;
    }
    return true;
}

void reciever(void) {   //ok
    int input;
	for (int i = 1; i <= 2; i++) {
		mark[0][i] = true;
		cin >> input;
		hexagon[0][i] = input;
        has0degreeline[0][input] = true;
        has30degreeline[i][input] = true;
        has60degreeline[0-i+10][input] = true;
        for(int t = 0; t < hexCount[0][i]; t++){
            hasHexagon[hexFinderGraf[0][i][t].second][hexFinderGraf[0][i][t].first][input] = true;
        }
		if(input != 0){
            defaultNum[0][i] = true;
		}
	}
	for (int i = 0; i < 5; i++) {
		mark[1][i] = true;
		cin >> input;
		hexagon[1][i] = input;
        has0degreeline[1][input] = true;
        has30degreeline[i][input] = true;
        has60degreeline[1-i+10][input] = true;
        for(int t = 1; t < hexCount[1][i]; t++){
            hasHexagon[hexFinderGraf[1][i][t].second][hexFinderGraf[1][i][t].first][input] = true;
        }
		if(input != 0){
            defaultNum[1][i] = true;
		}
	}
	for (int i = 0; i < 6; i++) {
		mark[2][i] = true;
		cin >> input;
		hexagon[2][i] = input;
        has0degreeline[2][input] = true;
        has30degreeline[i][input] = true;
        has60degreeline[2-i+10][input] = true;
        for(int t = 0; t < hexCount[2][i]; t++){
            hasHexagon[hexFinderGraf[2][i][t].second][hexFinderGraf[2][i][t].first][input] = true;
        }
		if(input != 0){
            defaultNum[2][i] = true;
		}
	}
	for (int i = 1; i < 6; i++) {
		mark[3][i] = true;
		cin >> input;
		hexagon[3][i] = input;
        has0degreeline[3][input] = true;
        has30degreeline[i][input] = true;
        has60degreeline[3-i+10][input] = true;
        for(int t = 0; t < hexCount[3][i]; t++){
            hasHexagon[hexFinderGraf[3][i][t].second][hexFinderGraf[3][i][t].first][input] = true;
        }
		if(input != 0){
            defaultNum[3][i] = true;
		}
	}
	for (int i = 1; i < 7; i++) {
		mark[4][i] = true;
		cin >> input;
		hexagon[4][i] = input;
        has0degreeline[4][input] = true;
        has30degreeline[i][input] = true;
        has60degreeline[4-i+10][input] = true;
        for(int t = 0; t < hexCount[4][i]; t++){
            hasHexagon[hexFinderGraf[4][i][t].second][hexFinderGraf[4][i][t].first][input] = true;
        }
		if(input != 0){
            defaultNum[4][i] = true;
		}
	}
	for (int i = 2; i < 7; i++) {
		mark[5][i] = true;
		cin >> input;
		hexagon[5][i] = input;
        has0degreeline[5][input] = true;
        has30degreeline[i][input] = true;
        has30degreeline[5-i+10][input] = true;
        for(int t = 0; t < hexCount[5][i]; t++){
            hasHexagon[hexFinderGraf[5][i][t].second][hexFinderGraf[5][i][t].first][input] = true;
        }
		if(input != 0){
            defaultNum[5][i] = true;
		}
	}
	for (int i = 4; i < 6; i++) {
		mark[6][i] = true;
		cin >> input;
		hexagon[6][i] = input;
        has0degreeline[6][input] = true;
        has60degreeline[i][input] = true;
        has60degreeline[6-i+10][input] = true;
        for(int t = 0; t < hexCount[6][i]; t++){
            hasHexagon[hexFinderGraf[6][i][t].second][hexFinderGraf[6][i][t].first][input] = true;
        }
		if(input != 0){
            defaultNum[6][i] = true;
		}
	}

}

bool makeHexoco(int x, int y){
    int nextX = x, nextY = y;
    if(mark[y][x+1] == true){
        nextX++;
    }
    else{
        if((x == 5) && (y == 6)){
            nextX = -1;
            nextY = -1;
        }
        else{
            nextY++;
            nextX = 0;
            while(!mark[nextY][nextX]){
                nextX++;
            }
        }
    }

    if(defaultNum[y][x]){
            if(nextX == -1){
                return true;
            }
            else{
                return makeHexoco(nextX, nextY);
            }
    }
    else{
        if(nextX == -1){
            for(int i = 1; i <= k; i++){
                if(putInPlace(x, y, i)){
                   return true;
                }
            }
            return false;
        }
        else{
            for(int i = 1; i <= k; i++){
                //cout <<"hi"<<endl;
                if(putInPlace(x, y, i)){

                    if(makeHexoco(nextX, nextY)){
                        return true;

                    }
                    else{
                        removeFromPlace(x,y,i);
                    }
                }

            }
            return false;
        }
    }

}

void giver(void){   //ok
    for (int i = 1; i <= 2; i++) {
//		mark[0][i] = true;
		cout << hexagon[0][i] << " ";
	}
	for (int i = 0; i < 5; i++) {
//		mark[1][i] = true;
		cout << hexagon[1][i] << " ";
	}
	for (int i = 0; i < 6; i++) {
//		mark[2][i] = true;
		cout << hexagon[2][i] << " ";
	}
	for (int i = 1; i < 6; i++) {
//		mark[3][i] = true;
		cout << hexagon[3][i] << " ";
	}
	for (int i = 1; i < 7; i++) {
//		mark[4][i] = true;
		cout << hexagon[4][i] << " ";
	}
	for (int i = 2; i < 7; i++) {
//		mark[5][i] = true;
		cout << hexagon[5][i] << " ";
	}
	for (int i = 4; i < 6; i++) {
//		mark[6][i] = true;
		cout << hexagon[6][i] << " ";
	}
}
