/**
OpenPong ist ein Pong Clone mit Multiplayerfunktion

Copyright (C) 2009 MacGyver
Dieses Programm ist freie Software. Sie können es unter den Bedingungen der GNU General
Public License, wie von der Free Software Foundation veröffentlicht, weitergeben und/oder
modifizieren, entweder gemäß Version 3 der Lizenz oder (nach Ihrer Option) jeder späteren
Version.
Die Veröffentlichung dieses Programms erfolgt in der Hoffnung, daß es Ihnen von Nutzen
sein wird, aber OHNE IRGENDEINE GARANTIE, sogar ohne die implizite Garantie der MARKTREIFE
oder der VERWENDBARKEIT FÜR EINEN BESTIMMTEN ZWECK. Details finden Sie in der GNU General
Public License.
Sie sollten ein Exemplar der GNU General Public License zusammen mit diesem Programm
erhalten haben. Falls nicht, siehe <http://www.gnu.org/licenses/>.
**/

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
    if (Mix_PlayMusic(music, 0) == -1)
    {
        cout << "Kann Musik nicht Abspielen : "  << endl;
        cout << "Fehlermeldung : " << Mix_GetError() << endl;

        pFramework->Quit();
        exit(1);
    }
}//Ende Play
