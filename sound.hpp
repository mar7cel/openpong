#ifndef SOUND_HPP_INCLUDED
#define SOUND_HPP_INCLUDED

#include "framework.hpp"

class CSound
{
    public  :
                CSound();
                ~CSound();
                void LoadSound(const string sFilename); //Lädt den Angegeben Sound
                void Play();                            //Spielt den geladen Sound

    private :
                Mix_Music *music;          //Datentyp für die Musik
};

#endif // SOUND_HPP_INCLUDED
