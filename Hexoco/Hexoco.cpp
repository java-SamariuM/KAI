#include <iostream>

using namespace std;

int hexagon[10][10];
bool mark[10][10] = { false };

void reciever(void);

bool is0degree(int y, int num) {
	int ans = true;
	for (int i = 0; i < 10; i++) {
		if (mark[y][i]) {
			if (hexagon[y][i] == num) {
				ans = false;
			}
		}
	}
	return ans;
}

bool is30degree(int x , int num){
    int ans = true;
	for (int i = 0; i < 10; i++) {
		if (mark[i][x]) {
			if (hexagon[i][x] == num) {
				ans = false;
			}
		}
	}
	return ans;
}

bool is60degree(int x , int y, int num){
    int ans = true;
    int b = y - x;
	for (int i = -10; i < 10; i++) {
            if((i >= 0) && (i<10)){
                if (mark[i+b][i]) {
                    if (hexagon[i+b][i] == num) {
                        ans = false;
                    }
                }
            }
	}
	return ans;
}

bool iscentral(int x, int y, int num){

}

int main() {

	return 0;
}

void reciever(void) {
	for (int i = 1; i <= 2; i++) {
		mark[0][i] = true;
		cin >> hexagon[0][i];
	}
	for (int i = 0; i < 5; i++) {
		mark[1][i] = true;
		cin >> hexagon[1][i];
	}
	for (int i = 0; i < 6; i++) {
		mark[2][i] = true;
		cin >> hexagon[2][i];
	}
	for (int i = 1; i < 6; i++) {
		mark[3][i] = true;
		cin >> hexagon[3][i];
	}
	for (int i = 1; i < 7; i++) {
		mark[4][i] = true;
		cin >> hexagon[4][i];
	}
	for (int i = 2; i < 7; i++) {
		mark[5][i] = true;
		cin >> hexagon[5][i];
	}
	for (int i = 4; i < 6; i++) {
		mark[6][i] = true;
		cin >> hexagon[6][i];
	}

}

