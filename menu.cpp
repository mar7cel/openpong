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

#include "menu.hpp"

CMenu::CMenu()
{
    pBack = NULL;
    pCursor = NULL;
    main = true;
    multiplayer = false;
    option = false;
    exit = false;
    aktiv = false;
    start = false;
    fullscreen = false;
    yCursor = 300;
    firstpos = pos1;
    lastpos = 0;
    AI = false;
    AI_easy = false;
    AI_hard = false;
    iSpeed = 0;
}
CMenu::~CMenu()
{
    SAFE_DELETE (pBack);
    SAFE_DELETE (pCursor);
}

//Init
//Aufgabe:Initialisiert alles was man für das Menü braucht
void CMenu::Init()
{
    pBack = new CSprite;
    pCursor = new CSprite;

    assert(pBack);
    pBack->Load("gfx/gui/back.bmp");
    pBack->SetPos(0,0);

    assert (pCursor);
    pCursor->Load("gfx/game/ball.bmp");
    pCursor->SetColorKey(255,0,255);
}//Ende Init

//Render
//Aufgabe:Rendert das Menü
void CMenu::Render()
{
    pBack->Render();
    pCursor->Render();
    if (main == true)
    {
        MainMenu();
        lastpos = pos5;
    }
    else if (exit == true)
    {
        Exit();
        lastpos = pos2;
    }
    else if (option == true)
    {
        Option();
        lastpos = pos7;
    }
    SDL_Delay(2);
}//Ende Render

//MainMenu
//Aufgabe:Erstellt das Hauptmenü
void CMenu::MainMenu()
{
    firstpos = pos1;
    if (yCursor > lastpos)
        yCursor = pos1;
    pFramework->Text("Open Pong", 360,80);
    pFramework->Text("Singelplayer", 350,pos1);
    pFramework->Text("Player vs. Bot", 350,pos2);
    pFramework->Text("Multiplayer geht noch nicht", 350,pos3);
    pFramework->Text("Optionen", 350,pos4);
    pFramework->Text("Exit", 350,pos5);

    pCursor->SetPos(300,yCursor);

    if ((yCursor == pos1) && (aktiv == true))
    {
        start = true;
        Quit();
    }
    if ((yCursor == pos2) && (aktiv == true))
    {
        start = true;
        AI = true;
        Quit();
    }
    if ((yCursor == pos4) && (aktiv == true))
    {
        option = true;
        main = false;
    }
    if ((yCursor == pos5) && (aktiv == true))
    {
        exit = true;
        main = false;
    }
    aktiv = false;
}//Ende MainMenu

//Optionen
//Aufgabe:Einstellungen für das Spiel vornehmen
void CMenu::Option()
{
    pScreen = pFramework->GetScreen();

    firstpos = pos0;

    if (yCursor > lastpos)
        yCursor = pos0;

    pFramework->Text("Optionen", 370,80);
    pFramework->Text("FullScreen", 250,pos0);
    pFramework->Text("Ja", 500,pos0);
    pFramework->Text("Nein", 500,pos1);
    pFramework->Text("Computer KI", 250,pos2);
    pFramework->Text("Easy", 500,pos2);
    pFramework->Text("Hard", 500,pos3);
    pFramework->Text("Ball Geschwindigkeit", 250,pos4);
    pFramework->Text("Normal", 500,pos4);
    pFramework->Text("Mittel", 500,pos5);
    pFramework->Text("2Fast4You", 500,pos6);
    pFramework->Text("Zurueck", 500,pos7);

    pCursor->SetPos(450,yCursor);

    if ((yCursor == pos0) && (aktiv == true) && (fullscreen == false))
    {
        SDL_WM_ToggleFullScreen(pScreen);
        fullscreen = true;
    }
    if ((yCursor == pos1) && (aktiv == true) && (fullscreen == true))
    {
        SDL_WM_ToggleFullScreen(pScreen);
        fullscreen = false;
    }
    if ((yCursor == pos2) && (aktiv == true))
    {
        AI_easy = true;
        AI_hard = false;
    }
    if ((yCursor == pos3) && (aktiv == true))
    {
        AI_hard = true;
        AI_easy = false;
    }
    if ((yCursor == pos4) && (aktiv == true))
    {
        iSpeed = 0;
    }
    if ((yCursor == pos5) && (aktiv == true))
    {
        iSpeed = 5;
    }
    if ((yCursor == pos6) && (aktiv == true))
    {
        iSpeed = 10;
    }
    if ((yCursor == pos7) && (aktiv == true))
    {
        main = true;
        option = false;
    }
    aktiv = false;
}

//Exit
//Aufgabe:Erstellt das Exit Menü
void CMenu::Exit()
{
    firstpos = pos1;
    if (yCursor > pos2)
        yCursor = pos1;
    pFramework->Text("Wirklich beenden ??", 225,80);
    pFramework->Text("Ja", 350,pos1);
    pFramework->Text("Nein", 350,pos2);

    pCursor->SetPos(300,yCursor);

    if ((yCursor == pos1) && (aktiv == true))
    {
        start = true;
        if (fullscreen == true)
        {
            pScreen = pFramework->GetScreen();
            SDL_WM_ToggleFullScreen(pScreen);
        }
        pFramework->done = true;
    }
    if ((yCursor == pos2) && (aktiv == true))
    {
        main = true;
        exit = false;
    }
    aktiv = false;
}//Ende Exit

//Control
//Aufgabe:Steuerung im Menü
void CMenu::Control()
{
    static bool up_pressed  = false;
    static bool down_pressed = false;
    static bool return_pressed = false;


    if ( SDL_PollEvent(&g_Event) )
    {
        if (g_Event.type == SDL_QUIT)
        {
            start = true;
            pFramework->done = true;
        }

        if (g_Event.type == SDL_KEYDOWN)
        {
            if (g_Event.key.keysym.sym == SDLK_ESCAPE)
            {
                exit = true;
                main = false;
            }
            if (g_Event.key.keysym.sym == SDLK_UP)
            {
                up_pressed = true;
            }
            if (g_Event.key.keysym.sym == SDLK_DOWN)
            {
                down_pressed = true;
            }
            if (g_Event.key.keysym.sym == SDLK_RETURN)
            {
                return_pressed = true;
                aktiv = true;

            }
        }
        if (g_Event.type == SDL_KEYUP)
        {
            if (g_Event.key.keysym.sym == SDLK_UP)
            {
                up_pressed = false;
            }
            if (g_Event.key.keysym.sym == SDLK_DOWN)
            {
                down_pressed = false;
            }
            if (g_Event.key.keysym.sym == SDLK_RETURN)
            {
                return_pressed = false;
                aktiv = false;
            }
        }

    }

    if (up_pressed)
    {
        yCursor -= 25;
        if (yCursor < firstpos)
        {
            yCursor = firstpos;
        }
        up_pressed = false;
    }
    if (down_pressed)
    {
        yCursor += 25;
        if (yCursor > lastpos)
        {
            yCursor = lastpos;
        }
        down_pressed = false;

    }
    if (return_pressed)
    {
        return_pressed = false;
    }
    /*switch (g_Event.type)
    {
      	case SDL_KEYDOWN:
              string s = SDL_GetKeyName(g_Event.key.keysym.sym);
              cout << "Taste : " << s+s << endl;
    break;
    }*/
}//Ende Control

void CMenu::Quit()
{
    SAFE_DELETE (pBack);
    SAFE_DELETE (pCursor);
}
