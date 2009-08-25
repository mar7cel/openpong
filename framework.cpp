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

# include "framework.hpp"

//  Init
//  Aufgabe:Framework Initialisieren
bool CFramework::Init(int iScreenWidth, int iScreenHeight,
                      int iColorDepth, bool bFullScreen)
{
    //Systeme der SDL Initialisieren
    if (SDL_Init (SDL_INIT_VIDEO | SDL_INIT_TIMER | SDL_INIT_AUDIO) == -1)
    {
        cout << "SDL konnte nicht Initialisiert werden!" << endl;
        cout << "Fehlermeldung: " << SDL_GetError() << endl;

        Quit();

        return(false);
    }
    if (bFullScreen == true)
    {
        pScreen = SDL_SetVideoMode (iScreenWidth, iScreenHeight, iColorDepth,
                                    SDL_HWSURFACE | SDL_DOUBLEBUF | SDL_FULLSCREEN);
    }
    else
    {
        pScreen = SDL_SetVideoMode (iScreenWidth, iScreenHeight, iColorDepth,
                                    SDL_HWSURFACE | SDL_DOUBLEBUF);
    }
    if (pScreen == NULL)
    {
        cout << "Videomodus konnte nicht gesetzt werden!" << endl;
        cout << "Fehlermeldung: " << SDL_GetError() << endl;

        Quit();

        return (false);
    }
    if (SDLNet_Init()==-1)
    {
        printf("SDLNet_Init: %s\n", SDLNet_GetError());
        exit(2);
    }
    if (TTF_Init()==-1)
    {
        printf("TTF_Init: %s\n", TTF_GetError());
        exit(2);
    }

    LoadFont("gfx/font/font.ttf",15);

    done = false;
    return (true);
} // Init Ende

//  Quit
//  Aufgabe:SDL beenden
void CFramework::Quit()
{
    TTF_CloseFont(pFont);
    SDLNet_Quit();
    SDL_Quit ();
} // Quit Ende

// Clear
// Aufgabe:Buffer Löschen
void CFramework::Clear ()
{
    SDL_FillRect (pScreen,NULL,SDL_MapRGB (pScreen->format, 0, 0, 0));
} // Clear Ende

//  Flip
//  Aufgabe:Surface flippen
void CFramework::Flip()
{
    SDL_Flip (pScreen);
} // Flip Ende

//LoadFont
//Aufgabe:Läd einen Font
void CFramework::LoadFont(const string sFilename, int size)
{
    pFont = TTF_OpenFont(sFilename.c_str(), size);

    if (pFont == NULL)
    {
        cout << " Fehler beim Laden des Font's " << endl;
        cout << " Fehlermeldung : " << SDL_GetError() << endl;
        TTF_CloseFont(pFont);
        pFramework->Quit();
        exit(1);
    }
}//Ende LoadFont

//Text
//Aufgabe:Darstellen des Textes
void CFramework::Text(string text, int iPosX, int iPosY)
{
    SDL_Color foreground  = {0,255,255};
    SDL_Color background  = {0,0,0};

    temp = TTF_RenderText_Shaded(pFont, text.c_str(), foreground, background);

    SDL_Rect destination = {iPosX, iPosY, 0, 0};

    assert(pScreen);
    pScreen = pFramework->GetScreen();
    SDL_BlitSurface(temp, NULL, pScreen, &destination);

    SDL_FreeSurface(temp);

}//Ende Text

