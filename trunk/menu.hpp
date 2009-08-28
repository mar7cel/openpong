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
#define pos1 275
#define pos2 300
#define pos3 325
#define pos4 350
#define pos5 375
#define pos6 400
#define pos7 425

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
                void Multiplayer(); //Multiplayer Menü
                void Option();      //Optionen für das Spiel
                void Exit();        //Exit Menü
                //void Quit();        //Fährt alles im Menü wieder runter
                bool start;         //Start
                bool fullscreen;    //Fullscreen
                bool exit;          //Exit
                bool AI;            //AI Aktiv
                bool AI_easy;       //AI Einfach
                bool AI_hard;       //AI Hard
                int iSpeed;         //Ball y Geschwindigkeit
                bool bServer;       //Server öffnen
                bool bClient;       //Client starten
                char str[101];
                char name[100];
                void SaveSetting();
                void LoadSetting();
                void InputName();
                bool bname;
    private :
                CSprite *pBack;     //Hintergrundbild
                CSprite *pCursor;   //Cursorbild
                SDL_Event g_Event;  //SDL Event
                SDL_Surface *pScreen;//Bildschirm auf den Gerendert wird
                int yCursor;        // Cursor Y Position
                int firstpos;       // Erste Position im Menü
                int lastpos;        // Letzte Position im Menü
                bool main;          // Welches Menü ist Aktiv
                bool multiplayer;   // Welches Menü ist Aktiv
                bool option;        // Welches Menü ist Aktiv
                bool aktiv;         // Ist die Auswahl im Menü auch Aktiviert
                bool ip;
};


#endif // MENU_HPP_INCLUDED
