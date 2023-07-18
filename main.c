#define _CRT_SECURE_NO_DEPRECATE 1
#include <stdio.h>
#include <Windows.h>
#include <time.h>
#include <stdlib.h>
#include <stdbool.h>

/***************************


	PBM Generation visualize

by kkrainer
****************************/

int main(void) {
    srand(time(NULL)); // start RNG

	//mark start for use in a loop
	start: ;

	//set vars
    int width = 0; 
    int height = 0;
    int start[5];// = {0, 0, 107, 206, 400};
	int starty[5];
	int rerun;
    int loops = 0;
	char goagain;

	

	rerun = 0;

	//request starter value (-5 || -10)
	printf("\n-10 == RAND\n-5 == Preset\n=> ");
	scanf("%d", &start[0]);
	getchar();

	//if preset chosen
	if(start[0] == -5){
		//set preset vars
		start[0] = 10;
		start[1] = 25;
		start[2] = 40;
		start[3] = 35;
		start[4] = 5;
		starty[0] = 10;
		starty[1] = 25;
		starty[2] = 40;
		starty[3] = 35;
		starty[4] = 5;
		width = 50;
		height = 50;
		loops = 150;
		//print out for user
		printf("start[0] = %d\n\
		start[1] = %d\n\
		start[2] = %d\n\
		start[3] = %d\n\
		start[4] = %d\n\
		\nstarty[0] = %d\
		\nstarty[1] = %d\
		\nstarty[2] = %d\
		\nstarty[3] = %d\
		\nstarty[4] = %d\n\
		\nwidth = %d\
		\nheight = %d\
		\nloops = %d\n Pressione [ENTER]\n",
		start[0], start[1], start[2], start[3],
		start[4], starty[0], starty[1], starty[2],
		starty[3], starty[4], height, width, loops);
		getchar();
	}
	//if random was chosen
	else if(start[0] == -10){
		//set rerun to 1 so the loop can restart later
		rerun++;
		//set width and height. Ceiling = 70,  Floor = 15
		width = rand() % (70 + 1 - 15) + 15;
		height = rand() % (70 + 1 - 15) + 15;
		//set other cars based off of that one
		start[0] = rand() % width;
		start[1] = rand() % width;
		start[2] = rand() % width;
		start[3] = rand() % width;
		start[4] = rand() % width;
		starty[0] = rand() % height;
		starty[1] = rand() % height;
		starty[2] = rand() % height;
		starty[3] = rand() % height;
		starty[4] = rand() % height;

		//fixed loop value
		loops = 150;

		system("cls");

		//print var values to user
		printf("start[0] = %d\
		\nstart[1] = %d\
		\nstart[2] = %d\
		\nstart[3] = %d\
		\nstart[4] = %d\
		\nstarty[0] = %d\
		\nstarty[1] = %d\
		\nstarty[2] = %d\
		\nstarty[3] = %d\
		\nstarty[4] = %d\n\
		\nwidth = %d\
		\nheight = %d\
		\nloops = %d\nPressione [ENTER]\n",
		start[0], start[1], start[2], start[3],
		start[4], starty[0], starty[1], starty[2],
		starty[3], starty[4], height, width, loops);
		getchar();
	}

	//generate array
	int arr[100][100] = {0};
	
	//if start is equal to -1 it will be ignored, else the respective coord will be set to 1
	if(start[0] != -1) arr[start[0]][starty[0]] = 1;
	if(start[1] != -1) arr[start[1]][starty[1]] = 1;
	if(start[2] != -1) arr[start[2]][starty[2]] = 1;
	if(start[3] != -1) arr[start[3]][starty[3]] = 1;
	if(start[4] != -1) arr[start[4]][starty[4]] = 1;	
	
	//start loop while l less than maxLoops
	for(int l = 0; l < loops; l++){

		//while less than height
		for(int h = 0; h < height; h++){
			
			//and less than width
			for(int x = 0; x < width; x++){
				
				//if not at the last line and the current pixel is one
				if(arr[h][x] == 1 && h != height - 1){

					//while b less than 2
					for(int b = -1; b < 2; b++){
						
						//50% chance for x+b h+1 (diagonal down) to be 1
						if(rand() % 2 == 1) arr[x+b][h + 1] = 1;
						else arr[x+b] [h + 1] = 0; 
					}
				}
			}
		}

		//printing loop
		for(int h = 0; h < height; h++){

			//print '[' at the start of a line
			printf("[ ");
			for(int w = 0; w != width; w++){ 						

				//if currentPos is 1 print O if 0 print '. ' (101 will be "[O . O]")
				(arr[w][h] == 1) ? printf("O ") : printf(". ");
			}

			//print ']' at the end of lines
			printf(" ]\n");
		}

		//display ammount of loops
		printf("\nLoops: %d", l);

		//rest screen
		Sleep(10);

		//clear
		system("cls");

	}

	//If the input chose random (30% chance itll be ass)
	if(rerun == 1){

		//Ask if start over
		printf("\nGo again? [Y/N]: ");
		scanf("%c", &goagain);
		getchar();

		//if yes go to the start: ; tag
		if(goagain == 'y' || goagain == 'Y') goto start;

		//else exit
		else exit(0);
	}

    return 0;
}