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

using namespace std;

void smechenie_up(int** massiv, int& size)
{
	for (int i = 1; i < size; i++)
	{
		for (int j = 0; j < size; j++)
		{
			if (massiv[i][j] != 0)
			{
				for (int k = i; k > 0; --k)
				{
					if (massiv[k - 1][j] == 0)
					{
						massiv[k - 1][j] = massiv[k][j];
						massiv[k][j] = 0;
					}
				}
			}
		}
	}
}

void smechenie_down(int** massiv, int& size)
{
	for (int i = 0; i < size; i++)
	{
		for (int j = size - 2; j >= 0; j--)
		{
			if (massiv[j][i] != 0)
			{
				for (int k = j; k < size - 1; ++k)
				{
					if (massiv[k + 1][i] == 0)
					{
						massiv[k + 1][i] = massiv[k][i];
						massiv[k][i] = 0;
					}
				}
			}
		}
	}
}

void smechenie_left(int** massiv, int& size)
{
	for (int i = 0; i < size; i++)
	{
		for (int j = 1; j < size; j++)
		{
			if (massiv[i][j] != 0)
			{
				for (int k = j; k > 0; --k)
				{
					if (massiv[i][k - 1] == 0)
					{
						massiv[i][k - 1] = massiv[i][k];
						massiv[i][k] = 0;
					}
				}
			}
		}
	}
}

void smechenie_right(int** massiv, int& size)
{
	for (int i = 0; i < size; i++)
	{
		for (int j = size - 2; j >= 0; j--)
		{
			if (massiv[i][j] != 0) {
				for (int k = j; k < size - 1; ++k)
				{
					if (massiv[i][k + 1] == 0)
					{
						massiv[i][k + 1] = massiv[i][k];
						massiv[i][k] = 0;
					}
				}
			}
		}
	}
}

void plus_left(int** massiv, int &size, int &score) 
{

	smechenie_left(massiv, size);

	for (int i = 0; i < size; i++) {
		for (int j = 1; j < size; j++) {
			if (massiv[i][j] != 0) {
				if (massiv[i][j] == massiv[i][j - 1]) {
					massiv[i][j - 1] += massiv[i][j];
					score += massiv[i][j-1];
					massiv[i][j] = 0;
				}
			}
		}
	}
	smechenie_left(massiv, size);
}

void plus_right(int** massiv, int &size, int &score) {
	smechenie_right(massiv, size);

	for (int i = 0; i < size; i++) {
		for (int j = size - 2; j >= 0; j--) {
			if (massiv[i][j] != 0) {
				if (massiv[i][j] == massiv[i][j + 1]) {
					massiv[i][j + 1] += massiv[i][j];
					score += massiv[i][j+1];
					massiv[i][j] = 0;
				}
			}
		}
	}
	smechenie_right(massiv, size);
}

void plus_up(int** massiv, int &size, int &score) {
	smechenie_up(massiv, size);

	for (int i = 0; i < size; i++) {
		for (int j = size - 2; j >= 0; j--) {
			if (massiv[j][i] != 0) {
				if (massiv[j][i] == massiv[j + 1][i]) {
					massiv[j + 1][i] += massiv[j][i];
					score += massiv[j+1][i];
					massiv[j][i] = 0;
				}
			}
		}
	}
	smechenie_up(massiv, size);
}

void plus_down(int** massiv, int &size, int &score) {
	smechenie_down(massiv, size);

	for (int i = 1; i < size; i++) {
		for (int j = 0; j < size; j++) {
			if (massiv[i][j] != 0) {
				if (massiv[i - 1][j] == massiv[i][j]) {
					massiv[i - 1][j] += massiv[i][j];
					score += massiv[i - 1][j];
					massiv[i][j] = 0;

				}
			}
		}
	}
	smechenie_down(massiv, size);
}
