#include "SDL.h"
#include "stdlib.h"
#include <SDL_ttf.h>
#include <SDL_image.h>
#include <SDL_mixer.h>
#include <math.h>
#include <time.h>
#include <iostream>
#include "lvl_4_4.h"
#include "lvl_5_5.h"
#include "lvl_6_6.h"

void smechenie_up(int **massiv, int& size);
void smechenie_down(int **massiv, int& size);
void smechenie_left(int **massiv, int& size);
void smechenie_right(int **massiv, int& size);
void plus_left(int** massiv, int& size,int& score);
void plus_right(int** massiv, int& size , int& score);
void plus_up(int** massiv, int& size, int& score);
void plus_down(int** massiv, int& size, int& score);
