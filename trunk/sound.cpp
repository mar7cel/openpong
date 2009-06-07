
#include "sound.hpp"

CSound::CSound()
{
    Mix_OpenAudio(MIX_DEFAULT_FREQUENCY, AUDIO_S16, MIX_DEFAULT_CHANNELS, 512);
}

CSound::~CSound()
{
    Mix_FreeMusic(music);
    Mix_CloseAudio();
}

//LoadSound
//Aufgabe:Sound Laden
void CSound::LoadSound(const string sFilename)
{
    music = Mix_LoadMUS(sFilename.c_str());
    if (music == NULL)
    {
        cout << "Fehler beim Laden von : " << sFilename.c_str() << endl;
        cout << "Fehlermeldung : " << Mix_GetError() << endl;

        pFramework->Quit();
        exit(1);
    }
}//Ende LoadSound

//Play
//Aufgabe:Sound Abspielen
void CSound::Play()
{
    Mix_PlayMusic(music, 0);
    if(Mix_PlayMusic(music, 0) == -1)
    {
        cout << "Kann Musik nicht Abspielen : "  << endl;
        cout << "Fehlermeldung : " << Mix_GetError() << endl;

        pFramework->Quit();
        exit(1);
    }
}//Ende Play
