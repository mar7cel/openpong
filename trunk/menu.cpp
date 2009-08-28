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
    bServer = false;
    bClient = false;
    ip = false;
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
    else if (multiplayer == true)
    {
        Multiplayer();
        lastpos = pos3;
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
    pFramework->done = false;
    firstpos = pos1;
    if (yCursor > lastpos)
        yCursor = pos1;
    pFramework->Text("Open Pong", 360,80);
    pFramework->Text("Einzelspieler", 350,pos1);
    pFramework->Text("Spieler vs. Bot", 350,pos2);
    pFramework->Text("Multiplayer", 350,pos3);
    pFramework->Text("Optionen", 350,pos4);
    pFramework->Text("Exit", 350,pos5);

    pCursor->SetPos(300,yCursor);

    if ((yCursor == pos1) && (aktiv == true))
    {
        start = true;
        //Quit();
    }
    if ((yCursor == pos2) && (aktiv == true))
    {
        start = true;
        AI = true;
        //Quit();
    }
    if ((yCursor == pos3) && (aktiv == true))
    {
        multiplayer = true;
        main = false;
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
    pFramework->Text("Vollbild", 250,pos0);
    pFramework->Text("Ja", 500,pos0);
    pFramework->Text("Nein", 500,pos1);
    pFramework->Text("Computer KI", 250,pos2);
    pFramework->Text("Leicht", 500,pos2);
    pFramework->Text("Schwer", 500,pos3);
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
        cout << "FullScreen on" << endl;
    }
    if ((yCursor == pos1) && (aktiv == true) && (fullscreen == true))
    {
        SDL_WM_ToggleFullScreen(pScreen);
        fullscreen = false;
        cout << "FullScreen off" << endl;
    }
    if ((yCursor == pos2) && (aktiv == true))
    {
        AI_easy = true;
        AI_hard = false;
        cout << "AI Easy" << endl;
    }
    if ((yCursor == pos3) && (aktiv == true))
    {
        AI_hard = true;
        AI_easy = false;
        cout << "AI Hard" << endl;
    }
    if ((yCursor == pos4) && (aktiv == true))
    {
        iSpeed = 0;
        cout << "Geschwindigkeit Langsam" << endl;
    }
    if ((yCursor == pos5) && (aktiv == true))
    {
        iSpeed = 5;
        cout << "Geschwindigkeit Mittel" << endl;
    }
    if ((yCursor == pos6) && (aktiv == true))
    {
        iSpeed = 10;
        cout << "Geschwindigkeit Hoch" << endl;
    }
    if ((yCursor == pos7) && (aktiv == true))
    {
        main = true;
        option = false;
    }
    aktiv = false;

    if (fullscreen == true)
    {
        pFramework->Text("AKTIV",600,pos0);
    }
    else if (!fullscreen)
    {
        pFramework->Text("AKTIV",600,pos1);
    }
    if (AI_easy == true || (!AI_easy && !AI_hard))
    {
        pFramework->Text("AKTIV",600,pos2);
    }
    else if (AI_hard == true)
    {
        pFramework->Text("AKTIV",600,pos3);
    }
    if (iSpeed == 0)
    {
        pFramework->Text("AKTIV",600,pos4);
    }
    else if (iSpeed == 5)
    {
        pFramework->Text("AKTIV",600,pos5);
    }
    else if (iSpeed == 10)
    {
        pFramework->Text("AKTIV",600,pos6);
    }

}

//Multiplayer
//Aufgabe:Erstellt das Multiplayer Menü
void CMenu::Multiplayer()
{
    if (yCursor > lastpos)
        yCursor = pos1;
    firstpos = pos1;
    pFramework->Text("Multiplayer", 360,80);
    pFramework->Text("Server Starten", 360,pos1);
    pFramework->Text("Zum Server Verbinden", 360,pos2);
    pFramework->Text("Zurueck", 360,pos3);
    pCursor->SetPos(300,yCursor);

    if ((yCursor == pos1) && (aktiv == true))
    {
        start = true;
        bServer = true;
        pFramework->Text("Warten auf Client", 360,pos1);
    }

    if ((yCursor == pos2) && (aktiv == true))
    {
        //start = true;
        //bClient = true;
        ip = true;
    }
    if ((yCursor == pos3) && (aktiv == true))
    {
        multiplayer = false;
        main = true;
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
    if (yCursor < pos1)
        yCursor = pos1;
    pFramework->Text("Wirklich beenden ??", 325,80);
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
    //static bool key  = false;

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

    if (ip == true)
    {
        pFramework->Clear();
        pBack->Render();
        pFramework->Text("Multiplayer", 360,80);
        pFramework->Text("Bitte IP des Servers Eingeben!", 300,pos1);
        pFramework->Flip();
        int len=0,old;
        int done=0,i;
        for (i=0;i<101;i++)
		str[i]=0;
        while (!done)
        {
            while (SDL_PollEvent(&g_Event))
            {
                if (g_Event.type == SDL_KEYDOWN)
                {
                    old = len;
                    if (g_Event.key.keysym.sym == SDLK_RETURN)
                    {
                        done=1;
                    }
                    else if ((g_Event.key.keysym.sym <= 57 && g_Event.key.keysym.sym >= 48) ||
                             g_Event.key.keysym.sym == 46 ||
                             (g_Event.key.keysym.sym <= 90 && g_Event.key.keysym.sym >= 65) ||
                             (g_Event.key.keysym.sym <= 122 && g_Event.key.keysym.sym >= 97))
                    {
                        str[len]=g_Event.key.keysym.sym;
                        len++;
                    }
                    else if (g_Event.key.keysym.sym == SDLK_SEMICOLON && (KMOD_RSHIFT || KMOD_LSHIFT))
                    {
                        str[len]=58;
                        len++;
                    }
                    else if (g_Event.key.keysym.sym == SDLK_BACKSPACE)
                    {
                        len--;
                        str[len]=0;
                    }
                    else if (g_Event.key.keysym.sym == SDLK_ESCAPE)
                    {
                        done = true;
                        ip = false;
                        return;
                    }
                    if (len>=100) len=100;
                    if (old!=len)
                    {

                        pFramework->Clear();
                        pBack->Render();
                        pFramework->Text("Multiplayer", 360,80);
                        pFramework->Text("Bitte IP des Servers Eingeben!", 300,pos1);
                        pFramework->Text(str, 300 , pos3);
                        pFramework->Flip();
                    }
                }

            }
        }
        start = true;
        bClient = true;
    }

}//Ende Control


/*void CMenu::Quit()
{
    SAFE_DELETE (pBack);
    SAFE_DELETE (pCursor);
}*/
