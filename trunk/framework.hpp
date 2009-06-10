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

#ifndef FRAMEWORK_HPP_INCLUDED
#define FRAMEWORK_HPP_INCLUDED

#include <SDL.h>
#include <SDL_net.h>
#include <SDL_ttf.h>
#include <SDL_mixer.h>

#include <iostream>
#include <time.h>
#include <sstream>
#include "singleton.hpp"

#define WCAPTION "OpenPong"
#define WWIDTH 800
#define WHEIGHT 600
#define WDEPTH 16
#define FRAMES 30
#define FRAME_RATE  1000/FRAMES
#define PWIDTH 100
#define PHEIGHT 20
#define BALLWH 20
#define RANDY 30
#define RANDX 20
#define SPEEDPLAYER 10
#define SAFE_DELETE(X) {if (X != NULL) {delete (X),X = NULL;}}

using namespace std;

#define pFramework CFramework::Get()

class CFramework    :   public OSingleton<CFramework>
{
    public  :
                bool Init   (int iScreenWidth, int iScreenHeight,
                            int iColorDepth, bool bFullSreen);      //Init für den Screen
                void Quit   ();                                     //SDL Quit
                void Clear  ();                                     //SDL Clear
                void Flip   ();                                     //SDL Flip
                SDL_Surface *GetScreen  ()  {return pScreen;}       //Gibt den Aktuellen Bildschirm zurück
                void LoadFont(const string sFontName, int size);    //Läd einen Font
                void Text(string text, int iPosX, int iPosY);       //Zeichnet einen Text an die Angegebene Position
                bool done;
    private :
                SDL_Surface *pScreen;                               //Surface für den Screen
                TTF_Font *pFont;                                    //Font
                SDL_Surface* temp;
};

#endif // FRAMEWORK_HPP_INCLUDED
