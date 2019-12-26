#ifndef SCREEN_H
#define SCREEN_H

#include <SDL2/SDL.h>
#include <SDL2/SDL_ttf.h>

#include <vector>
struct Color
{
	int r;
	int g;
	int b;
};
class Screen
{
private:
	/* data */
	const int width_;
	const int height_;
	Color bg_color_;

	SDL_Renderer *renderer_;
    SDL_Window *window_;
    SDL_Texture *f_layer_;
public:
	Screen(int w, int h, Color bg);
	~Screen();
    void setColor(int r, int g, int b);
    void setColor(Color color);
    void update();
	void putPixel(int x, int y);
    void putPixels(std::vector<SDL_Point> positions);
    void line(int x1, int y1, int x2, int y2);
    void rectangle(int left, int top, int right, int bottom);
    void bar(int left, int top, int right, int bottom);
    void circle(int xc, int yc, int radius);
};

#endif // SCREEN_H