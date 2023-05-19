#include "SDL.h"
#include "stdlib.h"
#include <SDL_ttf.h>
#include <SDL_image.h>
#include <SDL_mixer.h>
#include <math.h>
#include <time.h>
#include <iostream>
#include "lvl_5_5.h"
#include "pause.h"
#include "massiv_drive.h"

using namespace std;

SDL_Texture* get_text_texture1(SDL_Renderer*& renderer, char* text1, TTF_Font* font1)
{
	SDL_Surface* textSurface = NULL;
	SDL_Color fore_color = { 0,0,0 };
	SDL_Color back_color = { 127,127,127 };
	textSurface = TTF_RenderText_Shaded(font1, text1, fore_color, back_color);
	SDL_Texture* texture = SDL_CreateTextureFromSurface(renderer, textSurface);
	SDL_FreeSurface(textSurface);
	return texture;
}

void draw_text1(SDL_Renderer*& renderer, SDL_Texture* texture)
{
	SDL_Rect rect_2 = { 1205,5, 60, 60 };
	SDL_RenderCopy(renderer, texture, NULL, &rect_2);
}

void draw_text_score1(SDL_Renderer*& renderer, SDL_Texture* texture)
{
	SDL_Rect rect_2 = { 1005,5, 195, 60 };
	SDL_RenderCopy(renderer, texture, NULL, &rect_2);
}

void draw_text_record1(SDL_Renderer*& renderer, SDL_Texture* texture)
{
	SDL_Rect rect_3 = { 1205,85, 60, 60 };
	SDL_RenderCopy(renderer, texture, NULL, &rect_3);
}

void draw_text_record_text1(SDL_Renderer*& renderer, SDL_Texture* texture)
{
	SDL_Rect rect_3 = { 1005,85, 195, 60 };
	SDL_RenderCopy(renderer, texture, NULL, &rect_3);
}

void functions_random_1(int** massiv, int& rand_1)
{
	bool ok = false;
	srand(time(NULL));
	for (int i = 0; i < 5; i++)
		for (int j = 0; j < 5; j++)
		{
			if (massiv[i][j] == 0) ok = true;
		}
	if (ok == true)
	{
		int rand_procent, rand_x, rand_y;
		rand_procent = rand() % 10;
		if (rand_procent <= 2) { rand_1 = 4; }
		if (rand_procent > 2) { rand_1 = 2; }
		do
		{
			rand_x = rand() % 4;
			rand_y = rand() % 4;
		} while (massiv[rand_x][rand_y] != 0);
		massiv[rand_x][rand_y] = rand_1;
	}
}

void functions_lvl_5_5(SDL_Renderer* renderer, bool& quit_1, int** massiv, TTF_Font* font, int* massiv_record)
{
	bool quit = false, pause = true, ok_1_kletka = false, ok_up = false, ok_down = false, ok_left = false, ok_right = false,
		ok = false, ok1 = false, ok2 = false, end = true, porachenie = false, pobeda = false;

	ifstream file("lvl_record.txt");

	if (!file) { cout << "Файл не открыт, попробуйте еще раз..."; quit = true; quit_1 = true; }
	else
	{
		for (int i = 0; i < 3; i++)
			file >> massiv_record[i];
	}

	file.close();

	srand(time(NULL));
	int size = 5;

	SDL_Texture* textTexture;
	SDL_Texture* textTexture_2;
	SDL_Texture* textTexture_3;
	SDL_Texture* textTexture_4;


	char text[10];
	char record[10];
	char text_score[10] = "score:";
	char text_record[10] = "record:";

	SDL_Surface* textura_12_kletlka_0 = IMG_Load("kletka_0.bmp");
	SDL_SetColorKey(textura_12_kletlka_0, SDL_TRUE, SDL_MapRGB(textura_12_kletlka_0->format, 255, 255, 255));
	SDL_Texture* kletka_0 = SDL_CreateTextureFromSurface(renderer, textura_12_kletlka_0);
	SDL_FreeSurface(textura_12_kletlka_0);

	SDL_Surface* textura_13_kletlka_4 = IMG_Load("kletka_4.bmp");
	SDL_SetColorKey(textura_13_kletlka_4, SDL_TRUE, SDL_MapRGB(textura_13_kletlka_4->format, 255, 255, 255));
	SDL_Texture* kletka_4 = SDL_CreateTextureFromSurface(renderer, textura_13_kletlka_4);
	SDL_FreeSurface(textura_13_kletlka_4);

	SDL_Surface* textura_14_kletlka_8 = IMG_Load("kletka_8.bmp");
	SDL_SetColorKey(textura_14_kletlka_8, SDL_TRUE, SDL_MapRGB(textura_14_kletlka_8->format, 255, 255, 255));
	SDL_Texture* kletka_8 = SDL_CreateTextureFromSurface(renderer, textura_14_kletlka_8);
	SDL_FreeSurface(textura_14_kletlka_8);

	SDL_Surface* textura_15_kletlka_16 = IMG_Load("kletka_16.bmp");
	SDL_SetColorKey(textura_15_kletlka_16, SDL_TRUE, SDL_MapRGB(textura_15_kletlka_16->format, 255, 255, 255));
	SDL_Texture* kletka_16 = SDL_CreateTextureFromSurface(renderer, textura_15_kletlka_16);
	SDL_FreeSurface(textura_15_kletlka_16);

	SDL_Surface* textura_16_kletlka_32 = IMG_Load("kletka_32.bmp");
	SDL_SetColorKey(textura_16_kletlka_32, SDL_TRUE, SDL_MapRGB(textura_16_kletlka_32->format, 255, 255, 255));
	SDL_Texture* kletka_32 = SDL_CreateTextureFromSurface(renderer, textura_16_kletlka_32);
	SDL_FreeSurface(textura_16_kletlka_32);

	SDL_Surface* textura_17_kletlka_64 = IMG_Load("kletka_64.bmp");
	SDL_SetColorKey(textura_17_kletlka_64, SDL_TRUE, SDL_MapRGB(textura_17_kletlka_64->format, 255, 255, 255));
	SDL_Texture* kletka_64 = SDL_CreateTextureFromSurface(renderer, textura_17_kletlka_64);
	SDL_FreeSurface(textura_17_kletlka_64);

	SDL_Surface* textura_18_kletlka_128 = IMG_Load("kletka_128.bmp");
	SDL_SetColorKey(textura_18_kletlka_128, SDL_TRUE, SDL_MapRGB(textura_18_kletlka_128->format, 255, 255, 255));
	SDL_Texture* kletka_128 = SDL_CreateTextureFromSurface(renderer, textura_18_kletlka_128);
	SDL_FreeSurface(textura_18_kletlka_128);

	SDL_Surface* textura_19_kletlka_256 = IMG_Load("kletka_256.bmp");
	SDL_SetColorKey(textura_19_kletlka_256, SDL_TRUE, SDL_MapRGB(textura_19_kletlka_256->format, 255, 255, 255));
	SDL_Texture* kletka_256 = SDL_CreateTextureFromSurface(renderer, textura_19_kletlka_256);
	SDL_FreeSurface(textura_19_kletlka_256);

	SDL_Surface* textura_20_kletlka_512 = IMG_Load("kletka_512.bmp");
	SDL_SetColorKey(textura_20_kletlka_512, SDL_TRUE, SDL_MapRGB(textura_20_kletlka_512->format, 255, 255, 255));
	SDL_Texture* kletka_512 = SDL_CreateTextureFromSurface(renderer, textura_20_kletlka_512);
	SDL_FreeSurface(textura_20_kletlka_512);

	SDL_Surface* textura_21_kletlka_1024 = IMG_Load("kletka_1024.bmp");
	SDL_SetColorKey(textura_21_kletlka_1024, SDL_TRUE, SDL_MapRGB(textura_21_kletlka_1024->format, 255, 255, 255));
	SDL_Texture* kletka_1024 = SDL_CreateTextureFromSurface(renderer, textura_21_kletlka_1024);
	SDL_FreeSurface(textura_21_kletlka_1024);

	SDL_Surface* textura_22_kletlka_2048 = IMG_Load("kletka_2048.bmp");
	SDL_SetColorKey(textura_22_kletlka_2048, SDL_TRUE, SDL_MapRGB(textura_22_kletlka_2048->format, 255, 255, 255));
	SDL_Texture* kletka_2048 = SDL_CreateTextureFromSurface(renderer, textura_22_kletlka_2048);
	SDL_FreeSurface(textura_22_kletlka_2048);

	SDL_Surface* textura_23_kletlka_2 = IMG_Load("kletka_2.bmp");
	SDL_SetColorKey(textura_23_kletlka_2, SDL_TRUE, SDL_MapRGB(textura_23_kletlka_2->format, 255, 255, 255));
	SDL_Texture* kletka_2 = SDL_CreateTextureFromSurface(renderer, textura_23_kletlka_2);
	SDL_FreeSurface(textura_23_kletlka_2);

	SDL_Surface* textura_24_fon_menu_play = IMG_Load("fon_menu_play.bmp");
	SDL_SetColorKey(textura_24_fon_menu_play, SDL_TRUE, SDL_MapRGB(textura_24_fon_menu_play->format, 255, 255, 255));
	SDL_Texture* fon_menu_play = SDL_CreateTextureFromSurface(renderer, textura_24_fon_menu_play);
	SDL_FreeSurface(textura_24_fon_menu_play);

	SDL_Surface* textura_25_knopka_menu_pause = IMG_Load("knopka_menu_pause.bmp");
	SDL_SetColorKey(textura_25_knopka_menu_pause, SDL_TRUE, SDL_MapRGB(textura_25_knopka_menu_pause->format, 255, 255, 255));
	SDL_Texture* knopka_menu_pause = SDL_CreateTextureFromSurface(renderer, textura_25_knopka_menu_pause);
	SDL_FreeSurface(textura_25_knopka_menu_pause);

	SDL_Surface* textura_26_zalivka = IMG_Load("zalivka.bmp");
	SDL_SetColorKey(textura_26_zalivka, SDL_TRUE, SDL_MapRGB(textura_26_zalivka->format, 255, 0, 255));
	SDL_Texture* zalivka = SDL_CreateTextureFromSurface(renderer, textura_26_zalivka);
	SDL_FreeSurface(textura_26_zalivka);

	SDL_Surface* textura_27_resume = IMG_Load("knopka_resume.bmp");
	SDL_SetColorKey(textura_27_resume, SDL_TRUE, SDL_MapRGB(textura_27_resume->format, 255, 0, 255));
	SDL_Texture* knopka_resume = SDL_CreateTextureFromSurface(renderer, textura_27_resume);
	SDL_FreeSurface(textura_27_resume);

	SDL_Surface* textura_28_exit = IMG_Load("knopka_exit_red.bmp");
	SDL_SetColorKey(textura_28_exit, SDL_TRUE, SDL_MapRGB(textura_28_exit->format, 255, 0, 255));
	SDL_Texture* knopka_exit_red = SDL_CreateTextureFromSurface(renderer, textura_28_exit);
	SDL_FreeSurface(textura_28_exit);

	SDL_Surface* textura_29_Win = IMG_Load("WIN.bmp");
	SDL_SetColorKey(textura_29_Win, SDL_TRUE, SDL_MapRGB(textura_29_Win->format, 255, 255, 255));
	SDL_Texture* Victory = SDL_CreateTextureFromSurface(renderer, textura_29_Win);
	SDL_FreeSurface(textura_29_Win);

	SDL_Surface* textura_30_go = IMG_Load("game_over.bmp");
	SDL_SetColorKey(textura_30_go, SDL_TRUE, SDL_MapRGB(textura_30_go->format, 255, 255, 255));
	SDL_Texture* Game_over = SDL_CreateTextureFromSurface(renderer, textura_30_go);
	SDL_FreeSurface(textura_30_go);

	SDL_Surface* textura_31_restart = IMG_Load("restart.bmp");
	SDL_SetColorKey(textura_31_restart, SDL_TRUE, SDL_MapRGB(textura_31_restart->format, 255, 0, 255));
	SDL_Texture* knopka_restart = SDL_CreateTextureFromSurface(renderer, textura_31_restart);
	SDL_FreeSurface(textura_31_restart);

	int x1, y1, x_x = 300, y_y = 100, rand_procent, rand_1, rand_2, rand_1_index_x, rand_1_index_y, rand_2_index_x, rand_2_index_y, rand_3;
	int score = 0;
	SDL_Rect rect = { 0,0,1280,720 };
	SDL_Rect rect_1 = { 0,0,100,100 };
	SDL_Rect massiv_draw = { 0,20,136,136 };
	SDL_Rect resume = { 300, 210,300, 300 };
	SDL_Rect exit = { 680, 210,300, 300 };
	SDL_Rect rect2 = { 300,40, 680, 130 };


	SDL_Event event;
	while (quit == false)
	{
		SDL_RenderCopy(renderer, kletka_0, NULL, &rect);
		SDL_RenderCopy(renderer, knopka_menu_pause, NULL, &rect_1);
		SDL_GetMouseState(&x1, &y1);

		if (ok_1_kletka == false)
		{
			rand_procent = rand() % 10;
			if (rand_procent <= 1) { rand_1 = 4; rand_2 = 4; }
			if (rand_procent > 1 and rand_procent <= 7) { rand_1 = 2; rand_2 = 2; }
			if (rand_procent > 7) { rand_1 = 2; rand_2 = 4; }
			do
			{
				rand_1_index_x = rand() % 4; rand_1_index_y = rand() % 4;
				rand_2_index_x = rand() % 4; rand_2_index_y = rand() % 4;
			} while (rand_1_index_x == rand_2_index_x and rand_1_index_y == rand_2_index_y);

			for (int i = 0; i < 4; i++)
				for (int j = 0; j < 4; j++)
				{
					if (i == rand_1_index_x and j == rand_1_index_y) massiv[i][j] = rand_1;
					if (i == rand_2_index_x and j == rand_2_index_y) massiv[i][j] = rand_2;
				}
			ok_1_kletka = true;
		}

		while (SDL_PollEvent(&event))
		{
			if ((event.type == SDL_MOUSEBUTTONDOWN) && (event.button.button == SDL_BUTTON_LEFT) && (x1 > 0 && x1 < 100 && y1 > 0 && y1 < 100)) { pause = menu_pause(renderer); }
			if ((event.type == SDL_KEYDOWN) && (event.key.keysym.sym == SDLK_UP)) { ok_up = true; }
			if ((event.type == SDL_KEYDOWN) && (event.key.keysym.sym == SDLK_DOWN)) { ok_down = true; }
			if ((event.type == SDL_KEYDOWN) && (event.key.keysym.sym == SDLK_LEFT)) { ok_left = true; }
			if ((event.type == SDL_KEYDOWN) && (event.key.keysym.sym == SDLK_RIGHT)) { ok_right = true; }
		}

		if (pause == false)
		{
			quit = true; quit_1 = true;
		}

		if (ok_up == true)
		{
			plus_up(massiv, size, score);
			ok_up = false;
			functions_random(massiv, rand_3);
		}

		if (ok_down == true)
		{
			plus_down(massiv, size, score);
			ok_down = false;
			functions_random(massiv, rand_3);
		}

		if (ok_right == true)
		{
			plus_right(massiv, size, score);
			ok_right = false;
			functions_random(massiv, rand_3);
		}


		if (ok_left == true)
		{
			plus_left(massiv, size, score);
			ok_left = false;
			functions_random(massiv, rand_3);
		}

		if (massiv_record[1] < score)
		{
			massiv_record[1] = score;
		}

		_itoa_s(score, text, 10);
		_itoa_s(massiv_record[1], record, 10);
		textTexture = get_text_texture1(renderer, text, font);
		textTexture_2 = get_text_texture1(renderer, text_score, font);
		textTexture_3 = get_text_texture1(renderer, record, font);
		textTexture_4 = get_text_texture1(renderer, text_record, font);

		for (int i = 0; i < 5; i++)
		{
			for (int j = 0; j < 5; j++)
			{
				if (massiv[i][j] == 0) { massiv_draw.x = 300 + 136 * j; massiv_draw.y = 20 + 136 * i; SDL_RenderCopy(renderer, kletka_0, NULL, &massiv_draw); }
				if (massiv[i][j] == 2) { massiv_draw.x = 300 + 136 * j; massiv_draw.y = 20 + 136 * i; SDL_RenderCopy(renderer, kletka_2, NULL, &massiv_draw); }
				if (massiv[i][j] == 4) { massiv_draw.x = 300 + 136 * j; massiv_draw.y = 20 + 136 * i; SDL_RenderCopy(renderer, kletka_4, NULL, &massiv_draw); }
				if (massiv[i][j] == 8) { massiv_draw.x = 300 + 136 * j; massiv_draw.y = 20 + 136 * i; SDL_RenderCopy(renderer, kletka_8, NULL, &massiv_draw); }
				if (massiv[i][j] == 16) { massiv_draw.x = 300 + 136 * j; massiv_draw.y = 20 + 136 * i; SDL_RenderCopy(renderer, kletka_16, NULL, &massiv_draw); }
				if (massiv[i][j] == 32) { massiv_draw.x = 300 + 136 * j; massiv_draw.y = 20 + 136 * i; SDL_RenderCopy(renderer, kletka_32, NULL, &massiv_draw); }
				if (massiv[i][j] == 64) { massiv_draw.x = 300 + 136 * j; massiv_draw.y = 20 + 136 * i; SDL_RenderCopy(renderer, kletka_64, NULL, &massiv_draw); }
				if (massiv[i][j] == 128) { massiv_draw.x = 300 + 136 * j; massiv_draw.y = 20 + 136 * i; SDL_RenderCopy(renderer, kletka_128, NULL, &massiv_draw); }
				if (massiv[i][j] == 256) { massiv_draw.x = 300 + 136 * j; massiv_draw.y = 20 + 136 * i; SDL_RenderCopy(renderer, kletka_256, NULL, &massiv_draw); }
				if (massiv[i][j] == 512) { massiv_draw.x = 300 + 136 * j; massiv_draw.y = 20 + 136 * i; SDL_RenderCopy(renderer, kletka_512, NULL, &massiv_draw); }
				if (massiv[i][j] == 1024) { massiv_draw.x = 300 + 136 * j; massiv_draw.y = 20 + 136 * i; SDL_RenderCopy(renderer, kletka_1024, NULL, &massiv_draw); }
				if (massiv[i][j] == 2048) { massiv_draw.x = 300 + 136 * j; massiv_draw.y = 20 + 136 * i; SDL_RenderCopy(renderer, kletka_2048, NULL, &massiv_draw); }

			}
		}

		SDL_SetRenderDrawColor(renderer, 0, 0, 0, 0);

		for (int i = 0; i <= 10; i++)
		{
			SDL_RenderDrawLine(renderer, 300, 20 + i, 300 + 680, 20 + i);
			SDL_RenderDrawLine(renderer, 300 + i, 20, 300 + i, 20 + 680);
			SDL_RenderDrawLine(renderer, 300 + 680 + i, 20, 300 + 680 + i, 20 + 680);
			SDL_RenderDrawLine(renderer, 300, 690 + i, 300 + 680, 690 + i);
		}

		for (int i = 0; i < 5; i++)
		{
			for (int j = 0; j <= 10; j++)
			{
				SDL_RenderDrawLine(renderer, 300, 20 + 136 + 136 * i - j, 300 + 680, 20 + 136 + 136 * i - j);
				SDL_RenderDrawLine(renderer, 300 + 136 + 136 * i + j, 20, 300 + 136 + 136 * i + j, 690);
			}
		}

		draw_text1(renderer, textTexture);
		SDL_DestroyTexture(textTexture);
		draw_text_score1(renderer, textTexture_2);
		SDL_DestroyTexture(textTexture_2);
		draw_text_record1(renderer, textTexture_3);
		SDL_DestroyTexture(textTexture_3);
		draw_text_record_text1(renderer, textTexture_4);
		SDL_DestroyTexture(textTexture_4);

		ofstream file("lvl_record.txt");
		for (int i = 0; i < 3; i++)
		{
			file << massiv_record[i] << " ";
		}
		file.close();

		int cnt = 0;
		ok1 = false, ok2 = false;
		for (int i = 0; i < size; i++)
		{
			for (int j = 0; j < size; j++)
			{
				if (massiv[i][j] != 0) { cnt += 1; }
				if (massiv[i][j] == 2048) { quit = true; pobeda = true; }
			}
		}
		if (cnt == 25 and quit != true)
		{
			for (int i = 0; i < size; i++)
			{
				for (int j = 0; j < size - 1; j++)
				{
					if (massiv[i][j] == massiv[i][j + 1]) ok1 = true;
				}
			}
			for (int i = 0; i < size - 1; i++)
			{
				for (int j = 0; j < size; j++)
				{
					if (massiv[i][j] == massiv[i + 1][j]) ok2 = true;
				}
			}

			if (ok1 == false and ok2 == false) { quit = true; porachenie = true; }
		}
		if (quit != true)
		{
			SDL_RenderPresent(renderer);
			SDL_Delay(16);
		}
		while (porachenie == true)
		{
			SDL_GetMouseState(&x1, &y1);
			while (SDL_PollEvent(&event))
			{
				if ((event.type == SDL_MOUSEBUTTONDOWN) && (event.button.button == SDL_BUTTON_LEFT) && (x1 > 680 && x1 < 980 && y1 > 210 && y1 < 510)) { porachenie = false; quit_1 = true; }
				if ((event.type == SDL_MOUSEBUTTONDOWN) && (event.button.button == SDL_BUTTON_LEFT) && (x1 > 300 && x1 < 600 && y1 > 210 && y1 < 510))
				{
					pobeda = false, porachenie = false; quit = false, ok_1_kletka = false, score = 0;
					for (int i = 0; i < 5; i++)
						for (int j = 0; j < 5; j++)
							massiv[i][j] = 0;
				}
			}
			SDL_SetTextureAlphaMod(zalivka, 3);
			SDL_RenderCopy(renderer, zalivka, NULL, &rect);
			SDL_RenderCopy(renderer, Game_over, NULL, &rect2);
			SDL_RenderCopy(renderer, knopka_restart, NULL, &resume);
			SDL_RenderCopy(renderer, knopka_exit_red, NULL, &exit);
			SDL_RenderPresent(renderer);
			SDL_Delay(16);
		}
		while (pobeda == true)
		{
			SDL_GetMouseState(&x1, &y1);
			while (SDL_PollEvent(&event))
			{
				if ((event.type == SDL_MOUSEBUTTONDOWN) && (event.button.button == SDL_BUTTON_LEFT) && (x1 > 680 && x1 < 980 && y1 > 210 && y1 < 510)) { pobeda = false; quit_1 = true; }
				if ((event.type == SDL_MOUSEBUTTONDOWN) && (event.button.button == SDL_BUTTON_LEFT) && (x1 > 300 && x1 < 600 && y1 > 210 && y1 < 510))
				{
					pobeda = false, porachenie = false, quit = false, ok_1_kletka = false, score = 0;
					for (int i = 0; i < 5; i++)
						for (int j = 0; j < 5; j++)
							massiv[i][j] = 0;
				}
			}
			SDL_SetTextureAlphaMod(zalivka, 3);
			SDL_RenderCopy(renderer, zalivka, NULL, &rect);
			SDL_RenderCopy(renderer, Victory, NULL, &rect2);
			SDL_RenderCopy(renderer, knopka_restart, NULL, &resume);
			SDL_RenderCopy(renderer, knopka_exit_red, NULL, &exit);
			SDL_RenderPresent(renderer);
			SDL_Delay(16);
		}
	}
	for (int i = 0; i < 5; i++)
		for (int j = 0; j < 5; j++)
			massiv[i][j] = 0;
	SDL_DestroyTexture(kletka_0);
	SDL_DestroyTexture(kletka_2);
	SDL_DestroyTexture(kletka_4);
	SDL_DestroyTexture(kletka_8);
	SDL_DestroyTexture(kletka_16);
	SDL_DestroyTexture(kletka_32);
	SDL_DestroyTexture(kletka_64);
	SDL_DestroyTexture(kletka_128);
	SDL_DestroyTexture(kletka_256);
	SDL_DestroyTexture(kletka_512);
	SDL_DestroyTexture(kletka_1024);
	SDL_DestroyTexture(kletka_2048);
	SDL_DestroyTexture(knopka_menu_pause);
	SDL_DestroyTexture(knopka_resume);
	SDL_DestroyTexture(knopka_exit_red);
	SDL_DestroyTexture(zalivka);
	SDL_DestroyTexture(fon_menu_play);
	SDL_DestroyTexture(Victory);
	SDL_DestroyTexture(Game_over);
}
