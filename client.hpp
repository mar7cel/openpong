/**
OpenPong ist ein Pong Clone mit Multiplayerfunktion

Copyright (C) 2009 MacGyver
Dieses Programm ist freie Software. Sie k�nnen es unter den Bedingungen der GNU General
Public License, wie von der Free Software Foundation ver�ffentlicht, weitergeben und/oder
modifizieren, entweder gem�� Version 3 der Lizenz oder (nach Ihrer Option) jeder sp�teren
Version.
Die Ver�ffentlichung dieses Programms erfolgt in der Hoffnung, da� es Ihnen von Nutzen
sein wird, aber OHNE IRGENDEINE GARANTIE, sogar ohne die implizite Garantie der MARKTREIFE
oder der VERWENDBARKEIT F�R EINEN BESTIMMTEN ZWECK. Details finden Sie in der GNU General
Public License.
Sie sollten ein Exemplar der GNU General Public License zusammen mit diesem Programm
erhalten haben. Falls nicht, siehe <http://www.gnu.org/licenses/>.
**/

#ifndef CLIENT_HPP_INCLUDED
#define CLIENT_HPP_INCLUDED

#include "framework.hpp"
#include "menu.hpp"

class CClient
{
    public  :
                CClient();
                ~CClient();
                void OpenClient(char *s);
                void Recive(Sint16 *a, bool *b);
                void ReciveSettings(int *a);
                void Send(Sint16 a, bool b);
    private :
                TCPsocket server;
                TCPsocket client;
                IPaddress addr;
                int result;
};

#endif // CLIENT_HPP_INCLUDED
