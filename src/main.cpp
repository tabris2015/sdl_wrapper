
#include <SDL2/SDL.h>

#include "screen.h"


#define WINDOW_WIDTH 600



int main(void) {
    SDL_Event event;
    
	std::vector<SDL_Point> points = {{4,5},{4,6},{4,7},{4,8},{4,9},{4,10},{4,11}};
    
	Screen s(WINDOW_WIDTH, WINDOW_WIDTH, {0, 0, 0});

	s.setColor(255,0,0);
	s.bar(2, 2, 50, 50);
    
	s.setColor(0,255,0);
	s.bar(120, 120, 170, 170);
    
	// s.setColor(0,255,0);
	// s.bar(2, 2, 50, 50);
	// s.update();

	while (1) {
        if (SDL_PollEvent(&event) && event.type == SDL_QUIT)
            break;
    }
    return EXIT_SUCCESS;
}