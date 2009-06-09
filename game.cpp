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

#include"game.hpp"
//CGame
//Aufgabe:Konstruktor
CGame::CGame()
{
    fullscreen = false;
}//CGame ende

//~CGame
//Aufgabe:Destruktor
CGame::~CGame()
{

}//~CGame ende

// Init
// Aufgabe:Initialisiert das Spiel
void CGame::Init()
{
    //Initialisiert das Spiel
    if (pFramework->Init(WWIDTH,WHEIGHT,WDEPTH, fullscreen) == false)
    {
        cout << "Spiel konnte nicht Gestartet werden !!" << endl;
        pFramework->Quit();
    }
    //Setzt die Fenster Beschriftung
    SDL_WM_SetCaption(WCAPTION, 0);
    //Timer für das Spiel
    iTimer = SDL_GetTicks();
    //Menu Initialisieren
    pMenu->Init();
    pMenu->fullscreen = fullscreen;
}//Init ende

//Menu
//Aufgabe:Menu des Spieles
void CGame::Menu()
{
    while (!pMenu->start)
    {
        pFramework->Clear();
        pMenu->Render();
        pMenu->Control();
        pFramework->Flip();
    }
    m_Player.Init();
    m_Player.iPlayer = 2;
}//Menu ende

//Play
//Aufgabe:Spiel Startet
void CGame::Play()
{
    if ( (SDL_GetTicks() - iTimer) >= FRAME_RATE )
    {
        pFramework->Clear();
        m_Player.Render();
        m_Player.Control();
        m_Player.MoveBall();
        iTimer = SDL_GetTicks();
        pFramework->Flip();
    }
}//Play ende
