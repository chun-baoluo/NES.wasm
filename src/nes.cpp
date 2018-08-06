#include <SDL2/SDL.h>
#include <emscripten.h>

struct context
{
    SDL_Renderer *renderer;
};

extern "C"
{
    void EMSCRIPTEN_KEEPALIVE processRom(int slot)
    {
        long filesize;
        const char buffer[] = "/rom";
        FILE* fp = fopen(buffer, "r+b");
        
        if (fp == 0) {
            printf("Failed to open file!\n");
        }
        	
        fseek(fp, 0, SEEK_END);
        filesize = ftell(fp);
        printf("Length: %ld\n", filesize);
        fclose(fp);
    }
}

void mainloop(void *arg)
{
    context *ctx = static_cast<context*>(arg);
    SDL_Renderer *renderer = ctx->renderer;
    
    SDL_SetRenderDrawColor(renderer, 0, 0, 0, 255);
    SDL_RenderClear(renderer);

    SDL_RenderPresent(renderer);
}

int main()
{
    context ctx;
    
    SDL_Init(SDL_INIT_VIDEO);
    SDL_Window *window;
    SDL_Renderer *renderer;
    SDL_CreateWindowAndRenderer(255, 255, 0, &window, &renderer);

    ctx.renderer = renderer;

    emscripten_set_main_loop_arg(mainloop, &ctx, -1, 1);
    
    SDL_DestroyRenderer(renderer);
    SDL_DestroyWindow(window);
    SDL_Quit();

    return EXIT_SUCCESS;
}