#include <screen.h>

Screen::Screen(int w, int h, Color bg) : width_(w), height_(h), bg_color_(bg)
{
    // init screen
    SDL_Init(SDL_INIT_VIDEO);
    window_ = SDL_CreateWindow("Test window", SDL_WINDOWPOS_UNDEFINED, SDL_WINDOWPOS_UNDEFINED, width_, height_, 0);
    renderer_ = SDL_CreateRenderer(window_, -1, SDL_RENDERER_ACCELERATED);
    f_layer_ = SDL_CreateTexture(renderer_, SDL_PIXELFORMAT_RGBA8888, SDL_TEXTUREACCESS_TARGET, width_, height_); //Creating a texture
    SDL_SetRenderDrawColor(renderer_, bg_color_.r, bg_color_.g, bg_color_.b, 0);
    SDL_SetRenderTarget(renderer_, f_layer_);
    SDL_RenderClear(renderer_);
    SDL_SetRenderTarget(renderer_, NULL);
    //
}
Screen::~Screen()
{
    SDL_DestroyRenderer(renderer_);
    SDL_DestroyWindow(window_);
    SDL_Quit();
}
void Screen::setColor(int r, int g, int b)
{
    SDL_SetRenderDrawColor(renderer_, r, g, b, 255);
}
void Screen::setColor(Color c)
{
    SDL_SetRenderDrawColor(renderer_, c.r, c.g, c.b, 255);
}
void Screen::update()
{
    SDL_RenderPresent(renderer_);
}
void Screen::putPixel(int x, int y)
{
    SDL_RenderDrawPoint(renderer_, x, y);
    // SDL_RenderPresent(renderer_);
}

void Screen::putPixels(std::vector<SDL_Point> positions)
{
    SDL_RenderDrawPoints(renderer_, &positions[0], positions.size());
    // SDL_RenderPresent(renderer_);
}

void Screen::line(int x1, int y1, int x2, int y2)
{
    SDL_RenderDrawLine(renderer_, x1, y1, x2, y2);
    // SDL_RenderPresent(renderer_);
}
void Screen::rectangle(int left, int top, int right, int bottom)
{
    SDL_Rect rect = {left, top, right - left, bottom - top};
    SDL_RenderDrawRect(renderer_, &rect);
    // SDL_RenderPresent(renderer_);
}
void Screen::bar(int left, int top, int right, int bottom)
{
    SDL_Rect rect = {left, top, right - left, bottom - top};
    SDL_SetRenderTarget(renderer_, NULL);
    SDL_RenderCopy(renderer_, f_layer_, NULL, NULL);
    SDL_RenderFillRect(renderer_, &rect);
    SDL_RenderCopy(renderer_, NULL, NULL, NULL);
    
    SDL_RenderPresent(renderer_);
}
void Screen::circle(int xc, int yc, int radius)
{
    const int32_t diameter = (radius * 2);

    int32_t x = (radius - 1);
    int32_t y = 0;
    int32_t tx = 1;
    int32_t ty = 1;
    int32_t error = (tx - diameter);

    while (x >= y)
    {
        //  Each of the following renders an octant of the circle
        SDL_RenderDrawPoint(renderer_, xc + x, yc - y);
        SDL_RenderDrawPoint(renderer_, xc + x, yc + y);
        SDL_RenderDrawPoint(renderer_, xc - x, yc - y);
        SDL_RenderDrawPoint(renderer_, xc - x, yc + y);
        SDL_RenderDrawPoint(renderer_, xc + y, yc - x);
        SDL_RenderDrawPoint(renderer_, xc + y, yc + x);
        SDL_RenderDrawPoint(renderer_, xc - y, yc - x);
        SDL_RenderDrawPoint(renderer_, xc - y, yc + x);

        if (error <= 0)
        {
            ++y;
            error += ty;
            ty += 2;
        }

        if (error > 0)
        {
            --x;
            tx += 2;
            error += (tx - diameter);
        }
    }
    //    SDL_RenderPresent(renderer_);
}
