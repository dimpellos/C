#include "Sound.h"

Sound::Sound() {
    if (Mix_Init(0) == -1) {
        throw SOUND_EXCEPTION("Failed to initialize SDL_mixer");
    }
    
    if (Mix_OpenAudio(44100, MIX_DEFAULT_FORMAT, 2, 1024) == -1) {
        Mix_Quit();
        throw SOUND_EXCEPTION("Failed to open audio");
    }

    backgroundMusic = Mix_LoadMUS("./sounds/BG.wav");
    if (!backgroundMusic) throw SOUND_EXCEPTION("Couldn't load BG.wav");

    clickSound = Mix_LoadWAV("./sounds/Click.wav");
    if (!clickSound) throw SOUND_EXCEPTION("Couldn't load Click.wav");

    optionClickSound = Mix_LoadWAV("./sounds/OptionClick.wav");
    if (!optionClickSound) throw SOUND_EXCEPTION("Couldn't load OptionClick.wav");

    duckSound = Mix_LoadWAV("./sounds/Duck.wav");
    if (!duckSound) throw SOUND_EXCEPTION("Couldn't load Duck.wav");

    errorSound = Mix_LoadWAV("./sounds/Error.wav");
    if (!errorSound) throw SOUND_EXCEPTION("Couldn't load Error.wav");

    victorySound = Mix_LoadWAV("./sounds/Victory.wav");
    if (!victorySound) throw SOUND_EXCEPTION("Couldn't load Victory.wav");
}

Sound::~Sound() {
	Mix_FreeMusic(backgroundMusic);
	Mix_FreeChunk(clickSound);
	Mix_FreeChunk(optionClickSound);
	Mix_FreeChunk(duckSound);
	Mix_FreeChunk(errorSound);
	Mix_FreeChunk(victorySound);
	Mix_CloseAudio();
	Mix_Quit();
}

void Sound::playChunk(Mix_Chunk* chunk, int volume) {
    if (!chunk) return;
    Mix_HaltChannel(-1);
    Mix_PlayChannel(-1, chunk, 0);
    Mix_VolumeChunk(chunk, volume);
}

void Sound::playBackgroundMusic() {
    Mix_HaltMusic();
    Mix_PlayMusic(backgroundMusic, -1);
    Mix_VolumeMusic(volume);
}

void Sound::playClickSound() {
	playChunk(clickSound, volume);
}

void Sound::playOptionClickSound() {
	playChunk(optionClickSound, volume);
}

void Sound::playDuckSound() {
	playChunk(duckSound, volume);
}

void Sound::playErrorSound() {
	playChunk(errorSound, volume);
}

void Sound::playVictorySound() {
	playChunk(victorySound, volume);
}


