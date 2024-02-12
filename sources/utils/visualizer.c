#include "utils.h"

static SDL_Color hsv2rgb(const float h, const float s, const float v) {

    float r, g, b;

    const int i = (int)(h * 6);
    const float f = h * 6 - i;
    const float p = v * (1 - s);
    const float q = v * (1 - f * s);
    const float t = v * (1 - (1 - f) * s);

    switch(i % 6) {
        case 0: r=v; g=t; b=p; break;
        case 1: r=q; g=v; b=p; break;
        case 2: r=p; g=v; b=t; break;
        case 3: r=p; g=q; b=v; break;
        case 4: r=t; g=p; b=v; break;
        case 5: r=v; g=p; b=q; break;
    }

    return (SDL_Color){r*255, g*255, b*255, SDL_ALPHA_OPAQUE};
}

void draw(int array[], const size_t size, SDL_Renderer* renderer) {

    if (renderer) {

        SDL_SetRenderDrawColor(renderer, 0x1A, 0x1A, 0x1A, SDL_ALPHA_OPAQUE);
        SDL_RenderClear(renderer);

        for (int i = 0; i < size; ++i) {

            const float hue = 0.6f + (float) i / size;
            const float saturation = 0.8f;
            const float value = 0.8f;

            SDL_Color color = hsv2rgb(hue, saturation, value);

            const int maximum_value = max(array, size);

            const float width = (float) WIDTH / size;
            const float height = (float) HEIGHT * array[i] / maximum_value;

            SDL_Rect rect = {
                .x = width * i,
                .y = HEIGHT - height,
                .w = width + 1,
                .h = height
            };

            SDL_SetRenderDrawColor(renderer, color.r, color.g, color.b, SDL_ALPHA_OPAQUE);
            SDL_RenderFillRect(renderer, &rect);
        }

        SDL_RenderPresent(renderer);
        SDL_Delay(100 / sqrt(size));
    }
}
