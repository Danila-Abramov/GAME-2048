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
#include "pause.h"
#include "massiv_drive.h"
#include<fstream>
#include<iostream>

using namespace std;
Mix_Music* fon = NULL;

SDL_Rect rect = { 0,0,1280,720 };
SDL_Rect Play = {420,110,440,100};
SDL_Rect Records = { 420,230,440,100 };
SDL_Rect settings = {420,350,440,100};
SDL_Rect Exit = { 420,470,440,100 };
SDL_Rect Play_play = { 420,120,440,150 };
SDL_Rect settings_settings = { 420,280,440,150 };
SDL_Rect Exit_Exit = { 420,440,440,150 };



void play_fon()
{
	Mix_PlayMusic(fon, -1);
}


void loadmusic()
{
	fon = Mix_LoadMUS("fon.wav");
}

void draw_settings_settings(SDL_Renderer*& renderer, SDL_Texture* texture)
{
	SDL_RenderCopy(renderer, texture, NULL, &settings_settings);
}

void draw_exit_exit(SDL_Renderer*& renderer, SDL_Texture* texture)
{
	SDL_RenderCopy(renderer, texture, NULL, &Exit_Exit);
}

void draw_play_play(SDL_Renderer*& renderer, SDL_Texture* texture)
{
	SDL_RenderCopy(renderer, texture, NULL, &Play_play);
}

void draw_exit_to_menu(SDL_Renderer*& renderer, SDL_Texture* texture)
{
	SDL_RenderCopy(renderer, texture, NULL, &Exit);
}

void draw_rect(SDL_Renderer*& renderer, SDL_Texture* texture)
{
	SDL_RenderCopy(renderer, texture, NULL, &rect);
}

void draw_play(SDL_Renderer*& renderer, SDL_Texture* texture)
{
	SDL_RenderCopy(renderer, texture, NULL, &Play);
}

void draw_Records(SDL_Renderer*& renderer, SDL_Texture* texture)
{
	SDL_RenderCopy(renderer, texture, NULL, &Records);
}

void draw_settings(SDL_Renderer*& renderer, SDL_Texture* texture)
{
	SDL_RenderCopy(renderer, texture, NULL, &settings);
}

void draw_exit(SDL_Renderer*& renderer, SDL_Texture* texture)
{
	SDL_RenderCopy(renderer, texture, NULL, &Exit);
}

int main(int argc, char** argv)
{
	bool quit = false, quit_2 = false, quit_3 = false, quit_4 = false, knopka_1 = true, knopka_2 = true, knopka_3 = true, knopka_4 = true, knopka_5 = true, ok_music = false, ok_music_yes = true, ok_music_no = false, FULLSCREEN = false, lvl_4_4 = false, lvl_5_5 = false, lvl_6_6 = false, ok_records = false;
	int x1, y1, cnt_music = 0, cnt_fullscrean = 0;
	int **massiv_4_4 = new int* [4];
	int **massiv_5_5 = new int* [5];
	int** massiv_6_6 = new int* [6];

	int massiv_record[3];

	for (int i = 0; i < 4; i++)
		massiv_4_4[i] = new int[4];
	for (int i = 0; i < 5; i++)
		massiv_5_5[i] = new int[5];
	for (int i = 0; i < 6; i++)
		massiv_6_6[i] = new int[6];

	TTF_Init();
	TTF_Font* my_font = TTF_OpenFont("shrift.ttf", 100);

	srand(time(NULL));
	SDL_Init(SDL_INIT_EVERYTHING);
	SDL_Window* window = SDL_CreateWindow("2048",
		SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED, 1280, 720,SDL_WINDOW_SHOWN);
	SDL_Event event;

	SDL_Renderer* renderer = SDL_CreateRenderer(window, -1, SDL_RENDERER_ACCELERATED || SDL_RENDERER_PRESENTVSYNC);

	SDL_Surface* textura_1_fon_menu = IMG_Load("fon_menu.bmp");
	SDL_SetColorKey(textura_1_fon_menu, SDL_TRUE, SDL_MapRGB(textura_1_fon_menu->format, 255, 255, 255));
	SDL_Texture* menu = SDL_CreateTextureFromSurface(renderer, textura_1_fon_menu);
	SDL_FreeSurface(textura_1_fon_menu);

	SDL_Surface* textura_2_play = IMG_Load("play.bmp");
	SDL_SetColorKey(textura_2_play, SDL_TRUE, SDL_MapRGB(textura_2_play->format, 255, 255, 255));
	SDL_Texture* knopka_play = SDL_CreateTextureFromSurface(renderer, textura_2_play);
	SDL_FreeSurface(textura_2_play);

	SDL_Surface* textura_3_records = IMG_Load("RECORDS.bmp");
	SDL_SetColorKey(textura_3_records, SDL_TRUE, SDL_MapRGB(textura_3_records->format, 255, 255, 255));
	SDL_Texture* knopka_records = SDL_CreateTextureFromSurface(renderer, textura_3_records);
	SDL_FreeSurface(textura_3_records);

	SDL_Surface* textura_4_settings = IMG_Load("settings.bmp");
	SDL_SetColorKey(textura_4_settings, SDL_TRUE, SDL_MapRGB(textura_4_settings->format, 255, 255, 255));
	SDL_Texture* knopka_settings = SDL_CreateTextureFromSurface(renderer, textura_4_settings);
	SDL_FreeSurface(textura_4_settings);

	SDL_Surface* textura_5_exit = IMG_Load("exit.bmp");
	SDL_SetColorKey(textura_5_exit, SDL_TRUE, SDL_MapRGB(textura_5_exit->format, 255, 255, 255));
	SDL_Texture* knopka_exit = SDL_CreateTextureFromSurface(renderer, textura_5_exit);
	SDL_FreeSurface(textura_5_exit);

	SDL_Surface* textura_6_krestik = IMG_Load("knopka_exit.bmp");
	SDL_SetColorKey(textura_6_krestik, SDL_TRUE, SDL_MapRGB(textura_6_krestik->format, 255, 255, 255));
	SDL_Texture* knopka_krestik = SDL_CreateTextureFromSurface(renderer, textura_6_krestik);
	SDL_FreeSurface(textura_6_krestik);

	SDL_Surface* textura_7_4_4 = IMG_Load("4_4.bmp");
	SDL_SetColorKey(textura_7_4_4, SDL_TRUE, SDL_MapRGB(textura_7_4_4->format, 255, 255, 255));
	SDL_Texture* knopka_4_4 = SDL_CreateTextureFromSurface(renderer, textura_7_4_4);
	SDL_FreeSurface(textura_7_4_4);

	SDL_Surface* textura_8_5_5 = IMG_Load("5_5.bmp");
	SDL_SetColorKey(textura_8_5_5, SDL_TRUE, SDL_MapRGB(textura_8_5_5->format, 255, 255, 255));
	SDL_Texture* knopka_5_5 = SDL_CreateTextureFromSurface(renderer, textura_8_5_5);
	SDL_FreeSurface(textura_8_5_5);

	SDL_Surface* textura_9_6_6 = IMG_Load("6_6.bmp");
	SDL_SetColorKey(textura_9_6_6, SDL_TRUE, SDL_MapRGB(textura_9_6_6->format, 255, 255, 255));
	SDL_Texture* knopka_6_6 = SDL_CreateTextureFromSurface(renderer, textura_9_6_6);
	SDL_FreeSurface(textura_9_6_6);

	SDL_Surface* textura_10 = IMG_Load("sound_on.bmp");
	SDL_SetColorKey(textura_10, SDL_TRUE, SDL_MapRGB(textura_10->format, 255, 255, 255));
	SDL_Texture* knopka_settings_sound_green = SDL_CreateTextureFromSurface(renderer, textura_10);
	SDL_FreeSurface(textura_10);

	SDL_Surface* textura_11 = IMG_Load("sound_settings.bmp");
	SDL_SetColorKey(textura_11, SDL_TRUE, SDL_MapRGB(textura_11->format, 255, 255, 255));
	SDL_Texture* knopka_settings_sound_red = SDL_CreateTextureFromSurface(renderer, textura_11);
	SDL_FreeSurface(textura_11);

	SDL_Surface* textura_12_FULL_ON = IMG_Load("FULL_ON.bmp");
	SDL_SetColorKey(textura_12_FULL_ON, SDL_TRUE, SDL_MapRGB(textura_12_FULL_ON->format, 255, 255, 255));
	SDL_Texture* FULL_ON = SDL_CreateTextureFromSurface(renderer, textura_12_FULL_ON);
	SDL_FreeSurface(textura_12_FULL_ON);

	SDL_Surface* textura_13_FULL_OFF = IMG_Load("FULL_OFF.bmp");
	SDL_SetColorKey(textura_13_FULL_OFF, SDL_TRUE, SDL_MapRGB(textura_13_FULL_OFF->format, 255, 255, 255));
	SDL_Texture* FULL_OFF = SDL_CreateTextureFromSurface(renderer, textura_13_FULL_OFF);
	SDL_FreeSurface(textura_13_FULL_OFF);

	Mix_Init(0);
	Mix_OpenAudio(22050, MIX_DEFAULT_FORMAT, 2, 1024);
	loadmusic();
	play_fon();

	for (int i = 0; i < 4; i++)
		for (int j = 0; j < 4; j++)
			massiv_4_4[i][j] = 0;

	for (int i = 0; i < 5; i++)
		for (int j = 0; j < 5; j++)
			massiv_5_5[i][j] = 0;

	for (int i = 0; i < 6; i++)
		for (int j = 0; j < 6; j++)
			massiv_6_6[i][j] = 0;


	while ((knopka_1 == true && knopka_2 == true))
	{
		quit = false;
		SDL_GetMouseState(&x1, &y1);
		SDL_SetRenderDrawColor(renderer, 0, 0, 0, 0);
		SDL_RenderClear(renderer);
		draw_rect(renderer, menu);
		draw_play_play(renderer, knopka_play);
		draw_settings_settings(renderer, knopka_settings);
		draw_exit_exit(renderer, knopka_exit);
		SDL_RenderPresent(renderer);
		SDL_Delay(16);
		while (SDL_PollEvent(&event))
		{
			if (event.type == SDL_QUIT) knopka_4 = false;
			if ((event.type == SDL_KEYDOWN) && (event.key.keysym.sym == SDLK_ESCAPE))  knopka_4 = false;
			if ((event.type == SDL_MOUSEBUTTONDOWN) && (event.button.button == SDL_BUTTON_LEFT) && (x1 > 420 && x1 < 860 && y1 > 120 && y1 < 270)) { knopka_1 = false; }
			if ((event.type == SDL_MOUSEBUTTONDOWN) && (event.button.button == SDL_BUTTON_LEFT) && (x1 > 420 && x1 < 860 && y1 > 280 && y1 < 430)) { knopka_2 = false; }
			if ((event.type == SDL_MOUSEBUTTONDOWN) && (event.button.button == SDL_BUTTON_LEFT) && (x1 > 420 && x1 < 860 && y1 > 440 && y1 < 590)) { knopka_3 = false; }
		}

		if (knopka_3 == false || knopka_4 == false) break;

		if (knopka_1 == false)
		{
			while (quit == false)
			{
				SDL_GetMouseState(&x1, &y1);
				while (SDL_PollEvent(&event))
				{
					if ((event.type == SDL_MOUSEBUTTONDOWN) && (event.button.button == SDL_BUTTON_LEFT) && (x1 > 420 && x1 < 860 && y1 > 110 && y1 < 210)) { lvl_4_4 = true; }
					if ((event.type == SDL_MOUSEBUTTONDOWN) && (event.button.button == SDL_BUTTON_LEFT) && (x1 > 420 && x1 < 860 && y1 > 220 && y1 < 320)) { lvl_5_5 = true; }
					if ((event.type == SDL_MOUSEBUTTONDOWN) && (event.button.button == SDL_BUTTON_LEFT) && (x1 > 420 && x1 < 860 && y1 > 440 && y1 < 540)) { quit = true; }
					if ((event.type == SDL_MOUSEBUTTONDOWN) && (event.button.button == SDL_BUTTON_LEFT) && (x1 > 420 && x1 < 860 && y1 > 330 && y1 < 430)) { lvl_6_6 = true; }
				}
				if (lvl_4_4 == true || lvl_5_5 == true || lvl_6_6 == true)
				{
					if (lvl_4_4 == true) 
					{
						functions_lvl_4_4(renderer,quit, massiv_4_4, my_font, massiv_record); lvl_4_4 = false; 
					}

					if (lvl_5_5 == true)
					{
						functions_lvl_5_5(renderer, quit, massiv_5_5, my_font, massiv_record); lvl_5_5 = false;
					}

					if (lvl_6_6 == true)
					{
						functions_lvl_6_6(renderer, quit, massiv_6_6, my_font, massiv_record); lvl_6_6 = false;
					}

				}
				else
				{
					draw_rect(renderer, menu);
					draw_play(renderer, knopka_4_4);
					draw_Records(renderer, knopka_5_5);
					draw_settings(renderer, knopka_6_6);
					draw_exit_to_menu(renderer, knopka_exit);
					SDL_RenderPresent(renderer);
					SDL_Delay(16);
				}

			}
		}

		if (knopka_4 == false)
		{
			while (quit == false)
			{
				SDL_GetMouseState(&x1, &y1);
				while (SDL_PollEvent(&event))
				{
					if ((event.type == SDL_MOUSEBUTTONDOWN) && (event.button.button == SDL_BUTTON_LEFT) && (x1 > 420 && x1 < 860 && y1 > 470 && y1 < 570)) quit = true;
					
				}
			}
		}

		if (knopka_2 == false)
		{
			while (quit == false)
			{
				SDL_GetMouseState(&x1, &y1);
				while (SDL_PollEvent(&event))
				{
					if ((event.type == SDL_MOUSEBUTTONDOWN) && (event.button.button == SDL_BUTTON_LEFT) && (x1 > 420 && x1 < 860 && y1 > 110 && y1 < 210)) { ok_records = true; }
					if ((event.type == SDL_MOUSEBUTTONDOWN) && (event.button.button == SDL_BUTTON_LEFT) && (x1 > 420 && x1 < 860 && y1 > 470 && y1 < 570)) quit = true;
					if ((event.type == SDL_MOUSEBUTTONDOWN) && (event.button.button == SDL_BUTTON_LEFT) && (x1 > 420 && x1 < 860 && y1 > 350 && y1 < 450)) { ok_music = true; cnt_music += 1; cout << cnt_music << endl; }
					if ((event.type == SDL_MOUSEBUTTONDOWN) && (event.button.button == SDL_BUTTON_LEFT) && (x1 > 420 && x1 < 860 && y1 > 230 && y1 < 330)) { FULLSCREEN = true; cnt_fullscrean += 1; }
				}
				if (FULLSCREEN == true and cnt_fullscrean == 1) { SDL_SetWindowFullscreen(window, SDL_WINDOW_FULLSCREEN); }

				if (FULLSCREEN == true and cnt_fullscrean == 2) { SDL_SetWindowFullscreen(window, 0); SDL_SetWindowSize(window, 1280, 720); FULLSCREEN = false; cnt_fullscrean = 0; }

				if (ok_music == true and cnt_music == 1) { Mix_PauseMusic(); ok_music = false; ok_music_yes = false; ok_music_no = true;
				}
				if (ok_music == true and cnt_music == 2) { Mix_ResumeMusic(); ok_music = false; cnt_music = 0; ok_music_yes = true; ok_music_no = false;
				}
				if (ok_records == true)
				{
					ofstream file("lvl_record.txt");
					for (int i = 0; i < 3; i++)
					{
						massiv_record[i] = 0;
						file << massiv_record[i] << " ";
					}
					file.close();
					ok_records = false;
				}

				SDL_SetRenderDrawColor(renderer, 0, 0, 0, 0);
				SDL_RenderClear(renderer);
				draw_rect(renderer, menu);
				draw_play(renderer, knopka_records);
				draw_exit_to_menu(renderer, knopka_exit);
				if (FULLSCREEN == true) { draw_Records(renderer, FULL_ON); }
				if (FULLSCREEN == false) { draw_Records(renderer, FULL_OFF); }
				if (ok_music_yes == true) { draw_settings(renderer, knopka_settings_sound_green); }
				if (ok_music_no == true) { draw_settings(renderer, knopka_settings_sound_red); }
				SDL_RenderPresent(renderer);
				SDL_Delay(16);

			}
		}
		knopka_1 = true; knopka_2 = true; knopka_3 = true;

	}

	for (int i = 0; i < 4; i++)
		delete[]massiv_4_4[i];
	delete[]massiv_4_4;

	for (int i = 0; i < 5; i++)
		delete[]massiv_5_5[i];
	delete[]massiv_5_5;

	for (int i = 0; i < 6; i++)
		delete[]massiv_6_6[i];
	delete[]massiv_6_6;

	Mix_FreeMusic(fon);
	Mix_CloseAudio();
	SDL_DestroyRenderer(renderer);
	SDL_DestroyWindow(window);
	SDL_DestroyTexture(knopka_settings_sound_red);
	SDL_DestroyTexture(knopka_settings_sound_green);
	SDL_DestroyTexture(knopka_6_6);
	SDL_DestroyTexture(knopka_5_5);
	SDL_DestroyTexture(knopka_4_4);
	SDL_DestroyTexture(knopka_krestik);
	SDL_DestroyTexture(knopka_exit);
	SDL_DestroyTexture(knopka_settings);
	SDL_DestroyTexture(knopka_records);
	SDL_DestroyTexture(knopka_play);

	SDL_Quit();
	return 0;
}
