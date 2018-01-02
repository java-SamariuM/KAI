#include <bits/stdc++.h>
#include <cstdio>

using namespace std;

#define whiteEdge 220

int R[810][810];
int G[810][810];
int B[810][810];
int MAP[810][810];
int subMAP[810][810];
int star[50][3];
int width, height , expected;
int range = 10;

void recieveImage();

void makeBW();
// make pic black and white

void blurStar();

int blur(int h, int w);

int findStar();


//double change(int x1, int y1, int x2, int y2);

#define Debug

int main(){
    recieveImage();
    makeBW();
    #ifdef Debug
    for(int i = 0; i < height; i++){ //hereeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeee  make < <=
        for(int j = 0; j < width; j++){
            printf("(%d, %d, %d) ", R[i][j], G[i][j], B[i][j]);
        }
    }
    #endif // Debug

}

void recieveImage(){
    cin >> height >> width >> expected;
    //scanf("\n");
    for(int i = 0; i < height; i++){  //hereeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeee make < <=
        for(int j = 0; j < width; j++){
            scanf("%*[^0-9]%d%*[^0-9]%d%*[^0-9]%d", &R[i][j], &G[i][j], &B[i][j]);
        }
        //if(i != h-1)scanf("\n");
    }
    return;
}

void makeBW(){
    for(int i = 0; i < height; i++){
        for(int j = 0; j < width; j++){
            double ans = R[i][j] * 0.3;
            ans += G[i][j] * 0.59;
            ans += B[i][j] * 0.21;
            MAP[i][j] = ans;
        }
    }
    return;
}

void blurStar(){
    for(int i = 0; i < height; i++){
        for(int j = 0; j < width; j++){
            if((i == 0) || (j == 0) || (i == height - 1) || (j == width - 1)){
                subMAP[i][j] = 0;
            }
            else{
                subMAP[i][j] = blur(i, j);
            }
        }
    }
    memcpy(MAP, subMAP, 4*810*810); //maybe need change
    return;
}

int blur(int h, int w){
    double ans = 0;
    for(int i = -1; i <= 1; i++){
        for(int j = -1; j <= 1; j++){
            ans += MAP[h + i][w + j];
        }
    }
    ans /=9;
    return ((int)ans);
}

int findStar(){

}

/*
double change(int x1, int y1, int x2, int y2){
     int dR = R[x1] - R[x2];
     int dG = G[x1] - G[x2];
     int dB = B[x1] - B[x2];

}*/
