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

#ifndef SPRITE_HPP_INCLUDED
#define SPRITE_HPP_INCLUDED

#include "framework.hpp"


class CSprite
{
    public  :
                CSprite ();         //Konstruktor
                ~CSprite ();        //Destruktor
                void Load   (const string sFilename);   //Lädt ein Bild
                void SetPos (int iPosX, int iPosY);     //Setzt das Bild auf diese Position
                void Render ();                         //Rendert das Bild
                void SetColorKey(int R, int G, int B);  //Macht das Bild Transparent
                SDL_Rect GetRect() {return m_Rect;}     //Gibt den Rect eines Bildes zurück

    private :
                SDL_Surface *pScreen;   //Bildschirm
                SDL_Surface *pImage;    //Bild
                SDL_Rect m_Rect;        //Ein Rect
};
#endif // SPRITE_HPP_INCLUDED
