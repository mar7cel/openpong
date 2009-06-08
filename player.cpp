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

#include"player.hpp"

CPlayer::CPlayer()
{
    pPlayer = NULL;
    pComputer = NULL;
    pBall = NULL;
    pBack = NULL;
    pSoundPlayer = NULL;
    pSoundCpu = NULL;
    iPlayer = 0;
    host = false;
    guest = false;
    iPlayerPoint = 0;
    iCpuPoint = 0;
}

CPlayer::~CPlayer()
{
    delete (pPlayer);
    delete (pComputer);
    delete (pBall);
    delete (pBack);
    delete (pSoundPlayer);
    delete (pSoundCpu);
    delete (screen);
}

//Init
//Aufgabe:Initialisiert die Spieler und den Ball
void CPlayer::Init()
{
    pPlayer = new CSprite;
    pComputer = new CSprite;
    pBall = new CSprite;
    pBack = new CSprite;
    pSoundPlayer = new CSound;
    pSoundCpu = new CSound;

    pSoundPlayer->LoadSound("sound/pong1.wav");
    pSoundCpu->LoadSound("sound/pong2.wav");


        pPlayer->Load("gfx/game/player.bmp");
        pPlayer->SetColorKey(255,0,255);
        Player = pPlayer->GetRect();
        Player.x = (WWIDTH/2-PWIDTH/2);
        Player.y = RANDY;
        pPlayer->SetPos(Player.x,Player.y);

        pComputer->Load("gfx/game/player.bmp");
        pComputer->SetColorKey(255,0,255);
        Computer = pComputer->GetRect();
        Computer.x = (WWIDTH/2-PWIDTH/2);
        Computer.y = (WHEIGHT-PHEIGHT-RANDY);
        pComputer->SetPos(Computer.x,Computer.y);

        pBall->Load("gfx/game/ball.bmp");
        pBall->SetColorKey(255,0,255);
        Ball = pBall->GetRect();
        Ball.x = (WWIDTH/2-BALLWH/2);
        Ball.y = (WHEIGHT/2-BALLWH/2);
        pBall->SetPos(Ball.x,Ball.y);

        pBack->Load("gfx/game/back.bmp");
        pBack->SetPos(0,0);

        iBall_Speed_X = 0;
        iBall_Speed_Y = 13;

        if (host == true)
        {
            //server.OpenServer();
        }
        if (guest == true)
        {
            //client.OpenClient();
        }

}

//Render
//Aufgabe:Alles Rendern
void CPlayer::Render()
{
    pBack->Render();
    pPlayer->Render();
    pComputer->Render();
    pBall->Render();
    Points();
}

//Control
//Bewegungen der Spieler
void CPlayer::Control()
{
    screen = pFramework->GetScreen();

    static bool left_pressed_p1  = false;
	static bool right_pressed_p1 = false;
    static bool left_pressed_p2  = false;
    static bool right_pressed_p2 = false;
	if ( SDL_PollEvent(&g_Event) )
	{
		if (g_Event.type == SDL_QUIT)
		{
			pFramework->done = true;
			return;
		}

		if (g_Event.type == SDL_KEYDOWN)
		{
			if (g_Event.key.keysym.sym == SDLK_ESCAPE)
			{
			    if(pMenu->fullscreen == true)
			    {
			        SDL_WM_ToggleFullScreen(screen);
			    }
                pFramework->done = true;
				return;
			}
			if (g_Event.key.keysym.sym == SDLK_LEFT)
			{
				left_pressed_p1 = true;
			}
			if (g_Event.key.keysym.sym == SDLK_RIGHT)
			{
				right_pressed_p1 = true;
			}
			if (g_Event.key.keysym.sym == SDLK_j && (iPlayerPoint > 9 || iCpuPoint > 9))
			{
                iPlayerPoint = 0;
                iCpuPoint = 0;
                Reset();
                return;
			}
			if (g_Event.key.keysym.sym == SDLK_n && (iPlayerPoint > 9 || iCpuPoint > 9))
			{
                pFramework->done = true;
                return;
			}
		}
		if (g_Event.type == SDL_KEYUP)
		{
			if (g_Event.key.keysym.sym == SDLK_LEFT)
			{
				left_pressed_p1 = false;
			}
			if (g_Event.key.keysym.sym == SDLK_RIGHT)
			{
				right_pressed_p1 = false;
			}
		}
		if (g_Event.type == SDL_KEYDOWN && iPlayer == 2)
		{
		    if(g_Event.key.keysym.sym == SDLK_a)
		    {
		        left_pressed_p2 = true;
		    }
		    if(g_Event.key.keysym.sym == SDLK_d)
		    {
		        right_pressed_p2 = true;
		    }
		}
		if (g_Event.type == SDL_KEYUP && iPlayer == 2)
		{
		    if(g_Event.key.keysym.sym == SDLK_a)
		    {
		        left_pressed_p2 = false;
		    }
		    if(g_Event.key.keysym.sym == SDLK_d)
		    {
		        right_pressed_p2 = false;
		    }
		}

	}

	if (left_pressed_p1)
	{
			Player.x -= SPEEDPLAYER;
            pPlayer->SetPos(Player.x,Player.y);
            if (Player.x < RANDX)
            Player.x = RANDX;
	}
	if (right_pressed_p1)
	{
			Player.x += SPEEDPLAYER;
            pPlayer->SetPos(Player.x,Player.y);
            if (Player.x > WWIDTH - PWIDTH - RANDX)
            Player.x = WWIDTH - PWIDTH - RANDX;
	}
	if (left_pressed_p2)
	{
            Computer.x -= SPEEDPLAYER;
            pComputer->SetPos(Computer.x,Computer.y);
            if (Computer.x < RANDX)
            Computer.x = RANDX;
	}
	if (right_pressed_p2)
	{
			Computer.x += SPEEDPLAYER;
            pComputer->SetPos(Computer.x,Computer.y);
            if (Computer.x > WWIDTH - PWIDTH - RANDX)
            Computer.x = WWIDTH - PWIDTH - RANDX;
	}
	/*if(host == true)
	{
        Computer.x = server.Recive();
        pComputer->SetPos(Computer.x,Computer.y);
        server.Send(Player.x);
	}
	if(guest == true)
	{
        client.Send(Computer.x);
	    Player.x = client.Recive();
	    pPlayer->SetPos(Player.x,Player.y);
	}*/
}

bool CPlayer::Collision(SDL_Rect a , SDL_Rect b)
{
	/*if(b.x + b.w < a.x)return false; //Links
	if(b.x > a.x + a.w)return false; //Rechts
	if(b.y + b.h < a.y)return false; //Oben
	if(b.y > a.y + a.h)return false; //Unten*/

	if((b.x + b.w < a.x)||(b.x > a.x + a.w)||(b.y + b.h < a.y)||(b.y > a.y + a.h)) return false;

        /*    if  (( b.y < a.y + a.h ) && ( b.y + b.h > a.y ) &&
                ( b.x < a.x + a.w ) && ( b.x + b.w > a.x )) return true;*/
    return true;
}

//MoveBall
//Aufgabe:Ball Bewegen
void CPlayer::MoveBall()
{
    Ball.x += iBall_Speed_X;
	Ball.y += iBall_Speed_Y;

    if(Ball.x > WWIDTH - RANDX)
    {
        iBall_Speed_X *= -1;
    }
    if(Ball.x < 0)
    {
        iBall_Speed_X *= -1;
    }

    if(Ball.y > WHEIGHT)
    {
        Reset();
        iPlayerPoint++;
    }
    if(Ball.y < 0)
    {
        Reset();
        iCpuPoint++;
    }

    /*if(iBall_Speed_X > 0 && iBall_Speed_Y < 0 && (Ball.x + 10) < (Player.x + 20) && Collision(Player,Ball) == true)
    {
        iBall_Speed_X *= -1;
    }
    if(iBall_Speed_X < 0 && iBall_Speed_Y < 0 && (Ball.x + 10) > (Player.x + Player.w - 20) && Collision(Player,Ball) == true)
    {
        iBall_Speed_X *= -1;
    }
    if(iBall_Speed_X > 0 && iBall_Speed_Y < 0 && (Ball.x + 10) < (Computer.x + 20) && Collision(Computer,Ball) == true)
    {
        iBall_Speed_X *= -1;
        cout << " LINKS " << endl;
    }
    if(iBall_Speed_X < 0 && iBall_Speed_Y < 0 && (Ball.x + 10) > (Computer.x + Computer.w - 20) && Collision(Computer,Ball) == true)
    {
        iBall_Speed_X *= -1;
        cout << " RECHTS " << endl;
    }*/
    if(Collision(Player,Ball) == true)
    {
    	int paddle_center = Player.x + Player.w / 2;
    	int ball_center = Ball.x + Ball.w / 2;
    	int paddle_location = ball_center - paddle_center;
    	iBall_Speed_X = paddle_location / 5;
    	iBall_Speed_Y *= -1;
    	pSoundPlayer->Play();
    }
    if(Collision(Computer,Ball) == true)
    {
        int paddle_center = Computer.x + Computer.w / 2;
    	int ball_center = Ball.x + Ball.w / 2;
    	int paddle_location = ball_center - paddle_center;
    	iBall_Speed_X = paddle_location / 5;
    	iBall_Speed_Y *= -1;
    	pSoundCpu->Play();
    }

	pBall->SetPos(Ball.x,Ball.y);
}

void CPlayer::Reset()
{
    if(iPlayerPoint > 9 || iCpuPoint > 9)
    {
        iBall_Speed_X = 0;
        iBall_Speed_Y = 0;
        pFramework->Text("Nochmal Spielen ? (J)a / (N)ein",280,200);
    }
    else
    {
        Ball.x = (WWIDTH/2-BALLWH/2);
        Ball.y = (WHEIGHT/2-BALLWH/2);
        iBall_Speed_X = 0;
    }
    if (Ball.y > WHEIGHT)
    {
        iBall_Speed_Y = 13;
    }
    if (Ball.y < 0)
    {
        iBall_Speed_Y = -13;
    }
}



void CPlayer::Points()
{
    ostringstream p;
	ostringstream c;

	p << iPlayerPoint;
	c << iCpuPoint;

    string pla(p.str());
    string cpu(c.str());

    pFramework->Text("Player 1 : "+pla, 10,10);
    pFramework->Text("Player 2 : "+cpu, 10,570);

    if (host == true || guest == true)
    {
        pFramework->Text("Host : "+pla, 10,10);
        pFramework->Text("Client : "+cpu, 10,570);
    }
    if(iPlayerPoint > 9)
    {
        pFramework->Text("Player 1 hat Gewonnen! ", 10,10);
    }
    else if(iCpuPoint > 9)
    {
        pFramework->Text("Player 2 hat Gewonnen! ", 10,570);
    }

}
