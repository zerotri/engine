#include <2d>
#include <SDL.h>

struct game_window_s{
	SDL_Window* sdl_window;
  SDL_Surface* sdl_surface;
};

int window_create(char* title, int width, int height, game_window **window) {
	
	window = calloc( 1, sizeof(struct game_window_s) );
	struct game_window_s *window_p = (struct game_window_s*) window;

  //Initialize SDL
  if( SDL_Init( SDL_INIT_VIDEO ) < 0 ) {
      fprintf(stderr, "SDL could not initialize! SDL_Error: %s\n",
              SDL_GetError() );
      return -1;
  }
  else
    {
        //Create window
        window_p->sdl_window = SDL_CreateWindow( title,
                                          SDL_WINDOWPOS_UNDEFINED,
                                          SDL_WINDOWPOS_UNDEFINED,
                                          width, height, SDL_WINDOW_SHOWN );
        if( window_p->sdl_window == NULL )
        {
            printf( "Window could not be created! SDL_Error: %s\n", SDL_GetError() );
        }
        else
        {
            //Get window surface
            window_p->sdl_surface = SDL_GetWindowSurface( window_p->sdl_window );

            //Fill the surface white
            SDL_FillRect( window_p->sdl_surface, NULL, SDL_MapRGB( window_p->sdl_surface->format, 0xFF, 0xFF, 0xFF ) );
            
            //Update the surface
            SDL_UpdateWindowSurface( window_p->sdl_window );

            //Wait two seconds
            //SDL_Delay( 2000 );
        }
    }
    return 0;
}

int window_destroy(game_window **window) {
	if(!window) {
		fprintf( stderr, "Trying to destroy non-existent window\n" );
		return -1;
	}
	
	struct game_window_s *window_p = (struct game_window_s*) window;

	if(window_p->sdl_surface)
	if(window_p->sdl_window) SDL_DestroyWindow( window_p->sdl_window );
	
	free(window);

	return 0;
}
