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
