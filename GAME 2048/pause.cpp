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

bool menu_pause(SDL_Renderer* renderer)
{
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

	int x1, y1;
	bool resume = true, ok;
	SDL_Rect rectt = { 0,0,1280,720 };
	SDL_Rect resumee = { 300, 210,300, 300 };
	SDL_Rect exit = { 680, 210,300, 300 };

	SDL_Event event;
	while (resume == true)
	{
		SDL_GetMouseState(&x1, &y1);
		while (SDL_PollEvent(&event))
		{
			if ((event.type == SDL_MOUSEBUTTONDOWN) && (event.button.button == SDL_BUTTON_LEFT) && (x1 > 680 && x1 < 980 && y1 > 210 && y1 < 510)) { resume = false; ok = false; }
			if ((event.type == SDL_MOUSEBUTTONDOWN) && (event.button.button == SDL_BUTTON_LEFT) && (x1 > 300 && x1 < 600 && y1 > 210 && y1 < 510)) { resume = false; ok = true; }
		}
		SDL_SetTextureAlphaMod(zalivka, 3);
		SDL_RenderCopy(renderer, zalivka, NULL, &rectt);
		SDL_RenderCopy(renderer, knopka_resume, NULL, &resumee);
		SDL_RenderCopy(renderer, knopka_exit_red, NULL, &exit);
		SDL_RenderPresent(renderer);
		SDL_Delay(16);
	}
	SDL_DestroyTexture(knopka_resume);
	SDL_DestroyTexture(knopka_exit_red);
	SDL_DestroyTexture(zalivka);
	return ok;
}