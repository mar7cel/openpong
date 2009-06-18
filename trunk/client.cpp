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

void CClient::Recive(Sint16 a, bool b)
{

    result = SDLNet_TCP_Recv(client , &recive, sizeof(int));


    a=(Sint16) SDLNet_Read16(recive);
    b=(bool) SDLNet_Read16(recive+4);
}

void CClient::Send(Sint16 a, bool b)
{
    char data[8];
    SDLNet_Write16((Uint16)a,data);
    SDLNet_Write16((Uint16)b,data+4);
    cout << data << endl;

    int  len=sizeof(data);

    result = SDLNet_TCP_Send (client, &data, sizeof(data));

    if (result<len)
    {
        printf("SDLNet_TCP_Send: %s\n", SDLNet_GetError());
    }
}
