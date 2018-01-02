#include <bits/stdc++.h>
#include <cstdio>

using namespace std;

int R[810][810];
int G[810][810];
int B[810][810];
int BW[810][810];
int w, h , expected;
int range = 10;

void recieveImage();

void makeBW();

//double change(int x1, int y1, int x2, int y2);

#define Debug

int main(){
    recieveImage();
    //makeBW();
    #ifdef Debug
    for(int i = 0; i < h; i++){ //hereeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeee  make < <=
        for(int j = 0; j < w; j++){
            printf("(%d, %d, %d) ", R[i][j], G[i][j], B[i][j]);
        }
    }
    #endif // Debug

}

void recieveImage(){
    cin >> h >> w >> expected;
    //scanf("\n");
    for(int i = 0; i < h; i++){  //hereeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeee make < <=
        for(int j = 0; j < w; j++){
            scanf("%*[^0-9]%d%*[^0-9]%d%*[^0-9]%d", &R[i][j], &G[i][j], &B[i][j]);
        }
        //if(i != h-1)scanf("\n");
    }
}

void makeBW(){
    for(int i = 0; i < h; i++){
        for(int j = 0; j < w; j++){
            double ans = R[i][j] * 0.3;
            ans += G[i][j] * 0.59;
            ans += B[i][j] * 0.21;
            BW[i][j] = ans;
        }
    }
}
/*
double change(int x1, int y1, int x2, int y2){
     int dR = R[x1] - R[x2];
     int dG = G[x1] - G[x2];
     int dB = B[x1] - B[x2];

}*/
