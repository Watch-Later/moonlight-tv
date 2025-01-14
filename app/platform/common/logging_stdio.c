#include "util/logging.h"

#include <stdio.h>
#include <string.h>

#include <SDL.h>

static SDL_mutex *mutex;

void app_logvprintf(applog_level_t lvl, const char *tag, const char *fmt, va_list args) {
    Uint32 ticks = SDL_GetTicks();
    SDL_LockMutex(mutex);
    printf("%06ld.%03ld [%s][%s] ", ticks / 1000L, ticks % 1000L, tag, applog_level_str[lvl]);
    size_t len = strlen(fmt);
    vprintf(fmt, args);
    if (len && fmt[len - 1] != '\n')
        printf("\n");
    fflush(stdout);
    SDL_UnlockMutex(mutex);
}

void app_loginit() {
    mutex = SDL_CreateMutex();
}