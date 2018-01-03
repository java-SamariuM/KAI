#include <bits/stdc++.h>
#include <cstdio>

using namespace std;

//int whiteEdge = 150;
int StarSize = 1;

int R[810][810];
int G[810][810];
int B[810][810];
int MAP[810][810];
int subMAP[810][810];
pair <int, pair <int, int> > star[51];

bool mark[810][810];
int width, height , expected;
//int range = 10;

void recieveImage();

void makeBW();
// make pic black and white

void blurStar();

int blur(int h, int w);

int isStar(int h, int w, int whiteEdge);

int findStar(int whitedEdge); //return number of stars

void sortStar(int st, int en);


//double change(int x1, int y1, int x2, int y2);

//#define Debug

int main(){
    recieveImage();
    makeBW();
    blurStar();
    int starnum;
    int whiteEdge = 220;
    while( (starnum = findStar(whiteEdge)) < expected){
        whiteEdge -= 50;
    }
    sortStar(0, starnum);
    #ifdef Debug
/*    for(int i = 0; i < height; i++){ //hereeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeee  make < <=
        for(int j = 0; j < width; j++){
            printf("(%d, %d, %d) ", R[i][j], G[i][j], B[i][j]);
        }
    }

    printf("\n");
    for(int i = 0; i < height; i++){ //hereeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeee  make < <=
        for(int j = 0; j < width; j++){
            printf("(%d) ", MAP[i][j]);
        }
    }
    */
    printf("\n");
    for(int i = 0; i < starnum; i++){
        printf("%d (%d, %d)\n", star[i].first, star[i].second.first, star[i].second.second);
    }
    #endif // Debug
    printf("%d\n", expected);
    for(int i = 0; i < expected; i++){
        printf("%d %d\n", star[i].second.first+1, star[i].second.second+1);
    }

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



int isStar(int h, int w ,int whiteEdge){
    int counter = 0;
    if(!mark[h][w]){
        if(MAP[h][w] >= whiteEdge){
            counter++;
            mark[h][w] = true;
            for(int i = -1; i <= 1; i+=2){
                if(i+h>=0 && i+h<height)    counter+= isStar(h+i, w, whiteEdge);
                if(i+w>=0 && i+w<width)     counter+= isStar(h, w+i, whiteEdge);
            }
        }
        else{
            mark[h][w] = true;
        }
    }
    return counter;
}

int findStar(int whiteEdge){
    memset(mark, 0, 810*810);
    int counter = 0;
    for(int i = 0; i < height; i++){
        for(int j = 0; j < width; j++){
            int save;
            save = isStar(i, j, whiteEdge);
            if(save >= StarSize){
                star[counter].second.first = i;
                star[counter].second.second = j;
                star[counter++].first = save;
            }
        }
    }
    return counter;
}

void sortStar(int st, int en){
    for(int i = st; i < en; i++){
        for(int j = 0; j < en - st -1; j++){
            if(star[j].first < star[j+1].first){
                pair <int, pair<int, int> > subStar = star[j];
                star[j] = star[j+1];
                star[j+1] = subStar;
            }
        }
    }
    return;
}
/*
double change(int x1, int y1, int x2, int y2){
     int dR = R[x1] - R[x2];
     int dG = G[x1] - G[x2];
     int dB = B[x1] - B[x2];

}*/
