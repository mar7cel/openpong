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

#include "server.hpp"

CServer::CServer()
{
    server = NULL;
    client = NULL;
}
CServer::~CServer()
{
    SAFE_DELETE (remoteIP);
    SDLNet_TCP_Close(server);
    SDLNet_Quit();
}


void CServer::OpenServer()
{

    if (SDLNet_ResolveHost (&addr, NULL, 6699) < 0)
    {
        printf ("ERR ResolveHost: %s\n", SDLNet_GetError ());
        SDLNet_Quit ();
        exit (-1);
    }

    server = SDLNet_TCP_Open (&addr);

    if (server == NULL)
    {
        printf ("ERR TCP_Open: %s\n", SDLNet_GetError ());
        SDLNet_Quit ();
        exit (-1);
    }

    client = SDLNet_TCP_Accept (server);
    cout << "Server wurde auf Port 6699 geoeffnet!" << endl;
    cout << "Warten auf Client!" << endl;

    while (client == NULL)
    {
        SDL_Delay (1000);
        client = SDLNet_TCP_Accept (server);
    }
    cout << "Client hat Verbunden!" << endl;

}

void CServer::Recive(Sint16 a, bool b)
{
    int array[1];
    result = SDLNet_TCP_Recv(client , &array, sizeof(array));
    a = array[0];
    b = array[1];

    //a=(Sint16) SDLNet_Read16(data);
    //b=(Sint16) SDLNet_Read16(data+4);

    //return b;
}

void CServer::Send(Sint16 a, bool b)
{
    int array[1];
    //SDLNet_Write16((Uint16)a,data);
    //SDLNet_Write16((Uint16)b,data+4);
    array[0] = a;
    array[1] = b;
    int  len=sizeof(array);

    result = SDLNet_TCP_Send (client, &array, sizeof(array));

    if (result<len)
    {
        printf("SDLNet_TCP_Send: %s\n", SDLNet_GetError());
    }
}
