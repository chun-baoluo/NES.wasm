#include <SDL2/SDL.h>
#include <emscripten.h>

#include "NES.h"

NES* nes = new NES();

struct context
{
    SDL_Renderer *renderer;
};

extern "C"
{
    void EMSCRIPTEN_KEEPALIVE start()
    {
        nes->start();
    }

    void EMSCRIPTEN_KEEPALIVE stop()
    {
        nes->stop();
    }
}

void mainloop(void *arg)
{
    context *ctx = static_cast<context*>(arg);
    SDL_Renderer *renderer = ctx->renderer;

    SDL_SetRenderDrawColor(renderer, 0, 0, 0, 255);
    SDL_RenderClear(renderer);

    SDL_RenderPresent(renderer);

    if(nes->isReady()) {
        nes->nextFrame();
    }

}

int main()
{
    context ctx;

    SDL_Init(SDL_INIT_VIDEO);
    SDL_Window *window;
    SDL_Renderer *renderer;
    SDL_CreateWindowAndRenderer(341, 262, 0, &window, &renderer);

    ctx.renderer = renderer;

    emscripten_set_main_loop_arg(mainloop, &ctx, -1, 1);

    SDL_DestroyRenderer(renderer);
    SDL_DestroyWindow(window);
    SDL_Quit();

    return EXIT_SUCCESS;
}
