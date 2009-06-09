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

#ifndef PLAYER_HPP_INCLUDED
#define PLAYER_HPP_INCLUDED

#include "sprite.hpp"
#include "server.hpp"
#include "client.hpp"
#include "menu.hpp"
#include "sound.hpp"

class CPlayer
{
    public  :
                CPlayer();              //Konstruktor
                ~CPlayer();             //Destruktor
                void Init();            //Initialisiert die Spieler
                void Render();          //Rendert die Spieler und den Ball
                void Control();         //Steuerung der Spieler
                bool Collision(SDL_Rect a , SDL_Rect b);    //Kollisions Erkennung
                void MoveBall();        //Bewegt den Ball
                void Reset();           //Resetet das Spiel
                void Points();          //Berechnet Punkte der Spieler und gibt Sie aus
                short int iPlayer;      //Anzahl der Spieler
                int iBall_Speed_X;      //X Geschwindigkeit des Balles
                int iBall_Speed_Y;      //Y Geschwindigkeit des Balles
                //CServer server;
                //CClient client;
                bool host;
                bool guest;
    private :
                CSprite *pPlayer;       //Spieler Bild
                CSprite *pComputer;     //Spieler Bild
                CSprite *pBall;         //Ball Bild
                CSprite *pBack;         //Hintergrundbild
                CSound *pSoundPlayer;   //Sound für den Player
                CSound *pSoundCpu;      //Sound für den Computer
                SDL_Surface *pScreen;//Bildschirm auf den Gerendert wird
                SDL_Rect Player;        //Rect des Players
                SDL_Rect Computer;      //Rect des Players
                SDL_Rect Ball;          //Rect des Balles
                SDL_Rect m_Rect;        //Ein Rect
                SDL_Event g_Event;      //SDL Event
                int iPlayerPoint;       //Spieler Punkte
                int iCpuPoint;          //Spieler Punkte
                int paddle_center;      //Spieler Schläger mitte
                int ball_center;        //Ball mitte
                int paddle_location;    //Wo trifft der Ball auf den Schläger
                int paddle_center_cpu;  //CPU Schläger mitte
                int paddle_location_cpu;//Wo trifft der Ball auf den CPU Schläger
};
#endif // PLAYER_HPP_INCLUDED
