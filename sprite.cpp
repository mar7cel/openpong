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

#include "sprite.hpp"

CSprite::CSprite ()
{
    pScreen = pFramework->GetScreen ();
    pImage = NULL;
}

CSprite::~CSprite ()
{
    if (pImage)
    {
        SDL_FreeSurface(pImage);
        pImage = NULL;
    }
}

//Load
//Aufgabe:Laden des Sprites
void CSprite::Load (const string sFilename)
{
    pImage = SDL_LoadBMP(sFilename.c_str());

    if (pImage == NULL)
    {
        cout << "Fehler beim Laden von : " << sFilename.c_str() << endl;
        cout << "Fehlermeldung : " << SDL_GetError() << endl;

        pFramework->Quit();
        exit(1);
    }

    m_Rect.x = 0;
    m_Rect.y = 0;
    m_Rect.w = pImage->w;
    m_Rect.h = pImage->h;
}//Ende Load

//SetPos
//Aufgabe:Position des Sprites auf dem Bildschirm
void CSprite::SetPos(int iPosX, int iPosY)
{
    m_Rect.x = iPosX;
    m_Rect.y = iPosY;
}//Ende SetPos

//Render
//Aufgabe:Rendern des Sprites
void CSprite::Render ()
{
    if (SDL_BlitSurface(pImage, NULL, pScreen, &m_Rect) < 0)
        fprintf(stderr, "Error :  %s\n",SDL_GetError());
}//Ende Render

//SetColorKey
//Aufgabe:Transparens
void CSprite::SetColorKey(int R, int G, int B)
{
    SDL_SetColorKey(pImage, SDL_SRCCOLORKEY,
                    SDL_MapRGB(pImage->format, R, G, B));
}//Ende Colorkey
