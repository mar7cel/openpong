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

#include "client.hpp"

CClient::CClient()
{

}
CClient::~CClient()
{
    SDLNet_TCP_Close(server);
    SDLNet_Quit();
}

void CClient::OpenClient()
{
//    char *s;
//    cout << "Bitte ip des Servers Eingeben : "<< endl;
//    cin >> s;

    if (SDLNet_ResolveHost (&addr, "192.168.2.1", 6699) < 0)
    {
        printf ("ERR ResolveHost: %s\n", SDLNet_GetError ());
        SDLNet_Quit ();
        exit (-1);
    }

    client = SDLNet_TCP_Open (&addr);

    if (client == NULL)
    {
        printf ("ERR TCP_Open: %s\n", SDLNet_GetError ());
        SDLNet_Quit ();
        exit (-1);
    }
}

int CClient::Recive()
{

    /*result = SDLNet_TCP_Recv(client , &recive, sizeof(int));

    Sint16 b = recive;

    return b;*/

    int recive[1];

    result = SDLNet_TCP_Recv(client , &recive, sizeof(int));

    Sint16 b = recive[0];

    return b;
}

void CClient::Send(Sint16 a)
{
    /*int result;

    int b = a;

    int  len=sizeof(b);

    result = SDLNet_TCP_Send (client, &b, sizeof(int));

    if (result<len)
    {
        printf("SDLNet_TCP_Send: %s\n", SDLNet_GetError());
    }*/

    int result;
    int b[1];
    b[0] = a;

    int  len=sizeof(b);

    result = SDLNet_TCP_Send (client, &b, sizeof(b));

    if (result<len)
    {
        printf("SDLNet_TCP_Send: %s\n", SDLNet_GetError());
    }
}
