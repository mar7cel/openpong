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

#ifndef MENU_HPP_INCLUDED
#define MENU_HPP_INCLUDED

#include "framework.hpp"
#include "sprite.hpp"

#define pos0 250
#define pos1 300
#define pos2 350
#define pos3 400
#define pos4 450

#define pMenu CMenu::Get()

class CMenu     :   public OSingleton<CMenu>
{
    public  :
                CMenu();            //Konstruktor
                ~CMenu();           //Destruktor
                void Init();        //Initialisiert das Menü
                void Render();      //Rendert das Menü
                void Control();     //Steuerung für das Menü
                void MainMenu();    //Hauptmenü
                void Option();      //Optionen für das Spiel
                void Exit();        //Exit Menü
                bool start;         //Start
                bool fullscreen;    //Fullscreen
                bool exit;          //Exit
    private :
                CSprite *pBack;     //Hintergrundbild
                CSprite *pCursor;   //Cursorbild
                SDL_Event g_Event;  //SDL Event
                SDL_Surface *screen;//Bildschirm auf den Gerendert wird
                int yCursor;        // Cursor Y Position
                int firstpos;       // Erste Position im Menü
                int lastpos;        // Letzte Position im Menü
                bool main;          // Welches Menü ist Aktiv
                bool multiplayer;   // Welches Menü ist Aktiv
                bool option;        // Welches Menü ist Aktiv
                bool aktiv;         // Ist die Auswahl im Menü auch Aktiviert

};


#endif // MENU_HPP_INCLUDED
