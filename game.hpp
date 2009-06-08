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

#ifndef GAME_HPP_INCLUDED
#define GAME_HPP_INCLUDED

#include "player.hpp"
#include "menu.hpp"

class CGame
{
    public  :
                CGame();            //Konstruktor
                ~CGame();           //Destruktor
                void Init();        //Spiel Initialisieren
                void Menu();        //Menu Initialisieren
                void Play();        //Spielen
                CPlayer m_Player;   //Instanz vom Spieler erzeugen
                int iTimer;         //Ein Timer
    private :
                bool fullscreen;    //FullScreen ?
                SDL_Surface *screen;//Surface des Screens*
};


#endif // GAME_HPP_INCLUDED
