#include <iostream>

using namespace std;

int hexagon[10][10];
bool mark[10][10] = { false };
bool counted[10][10] = {false};
int k;

void reciever(void);

void giver(void);


bool find0degreeline(int x, int y, int num);


bool find30degreeline(int x, int y , int num);


bool find60degreeline(int x , int y, int num);


bool checkcenter(int x, int y, int num);

bool isCenter(int x, int y);

bool findCenter(int x, int y, int num);

bool makeHexacon(int x, int y);


int main() {
    cin >> k;
    reciever();

    makeHexacon(1, 0);
    giver();
	return 0;

}

bool find0degreeline(int x, int y, int num){
	bool ans = true;
	for (int i = 0; i < 10; i++) {
		if (mark[y][i]) {
			if (hexagon[y][i] == num) {
				ans = false;
				break;
			}
		}
	}
	return ans;
}

bool find30degreeline(int x , int y,  int num){
    bool ans = true;
	for (int i = 0; i < 10; i++) {
		if (mark[i][x]) {
			if (hexagon[i][x] == num) {
				ans = false;
				break;
			}
		}
	}
	return ans;
}

bool find60degreeline(int x , int y, int num){
    bool ans = true;
    int b = y - x;
	for (int i = -10; i < 10; i++) {
            if((i >= 0) && (i<10)){
                if (mark[i+b][i]) {
                    if (hexagon[i+b][i] == num) {
                        ans = false;
                        break;
                    }
                }
            }
	}
	return ans;
}

bool checkcenter(int x, int y, int num){
    bool ans = true;
    for(int i = -1; i <= 1; i+=2){
        if((x+i)>=0 && (x+i)<10 && mark[y][x+i]){
            if(hexagon[y][x+i] == num){
                ans = false;
                break;
            }
        }
        if((y+i)>=0 && (y+i)<10 && mark[y+i][x]){
            if(hexagon[y+i][x] == num){
                ans = false;
                break;
            }
        }
        if((y+i)>=0 && (y+i)<10 && (x+i)>=0 && (x+i)<10 && mark[y+i][x+i]){
            if(hexagon[y+i][x+i] == num){
                ans = false;
                break;
            }
        }
    }
    return ans;
}

bool isCenter(int x, int y){
    if((x == 1) && (y == 2)){
        return true;
    }
    if((x == 2) && (y == 1)){
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


void reciever(void) {
    int input;
	for (int i = 1; i <= 2; i++) {
		mark[0][i] = true;
		cin >> input;
		hexagon[0][i] = input;
		if(input != 0){
            counted[0][i] = true;
		}
	}
	for (int i = 0; i < 5; i++) {
		mark[1][i] = true;
		cin >> input;
		hexagon[1][i] = input;
		if(input != 0){
            counted[1][i] = true;
		}
	}
	for (int i = 0; i < 6; i++) {
		mark[2][i] = true;
		cin >> input;
		hexagon[2][i] = input;
		if(input != 0){
            counted[2][i] = true;
		}
	}
	for (int i = 1; i < 6; i++) {
		mark[3][i] = true;
		cin >> input;
		hexagon[3][i] = input;
		if(input != 0){
            counted[3][i] = true;
		}
	}
	for (int i = 1; i < 7; i++) {
		mark[4][i] = true;
		cin >> input;
		hexagon[4][i] = input;
		if(input != 0){
            counted[4][i] = true;
		}
	}
	for (int i = 2; i < 7; i++) {
		mark[5][i] = true;
		cin >> input;
		hexagon[5][i] = input;
		if(input != 0){
            counted[5][i] = true;
		}
	}
	for (int i = 4; i < 6; i++) {
		mark[6][i] = true;
		cin >> input;
		hexagon[6][i] = input;
		if(input != 0){
            counted[6][i] = true;
		}
	}

}

bool findCenter(int x, int y, int num){
    for(int i = -1; i <= 1; i+=2){
        if((x+i)>=0 && (x+i)<10 && mark[y][x+i]){
            if(isCenter(y, x+i)){
                if(!checkcenter(x+i, y, num)){
                    return false;
                }
            }
        }
        if((y+i)>=0 && (y+i)<10 && mark[y+i][x]){
            if(isCenter(y+i, x)){
                if(!checkcenter(x+i, y+i, num)){
                    return false;
                }
            }
        }
        if((y+i)>=0 && (y+i)<10 && (x+i)>=0 && (x+i)<10 && mark[y+i][x+i]){
            if(isCenter(y+i, x+i)){
                if(!checkcenter(x+i, y+i, num)){
                    return false;
                }
            }
        }
    }
    return true;
}

bool makeHexacon(int x, int y){
    int nextX = x, nextY = y;
    if(mark[y][x+1] == true){
        nextX++;
    }
    else{
        if(x == 6 && y == 6){
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

    if(counted[y][x]){
            if(nextX == -1){
                return (find0degreeline(x,y,hexagon[y][x]) && find30degreeline(x,y,hexagon[y][x]) && find60degreeline(x,y,hexagon[y][x]) && findCenter(x,y,hexagon[y][x]));
            }
            else{
                return makeHexacon(nextX, nextY);
            }
    }
    else{
        for(int i = 1; i <= k; i++){
            if(findCenter(x, y, i) && find0degreeline(x,y,i) && find30degreeline(x,y,i) && find60degreeline(x,y,i)){
               counted[y][x] = true;
               hexagon[y][x] = i;
               if(makeHexacon(nextX, nextY)){
                    return true;
               }
            }
        }
        counted[y][x] = false;
        return false;
    }

}

void giver(void){
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
