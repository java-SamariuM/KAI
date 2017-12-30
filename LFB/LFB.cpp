#include <bits/stdc++.h>
#include "riazat.h"
#include <time.h>

void init(){
	srand(time(0));
}

int next(int previous_opponent_move){
	if(previous_opponent_move == 0)
		if(rand() * 1.0 / RAND_MAX < 2.0 / 3)
			return 2;
		else
			return 0;
	if(previous_opponent_move == 1)
		if(rand() * 1.0 / RAND_MAX < 2.0 / 3)
			return 0;
		else
			return 1;
	if(previous_opponent_move == 2)
		if(rand() * 1.0 / RAND_MAX < 2.0 / 3)
			return 1;
		else
			return 2;
	return rand() % 3;
}
