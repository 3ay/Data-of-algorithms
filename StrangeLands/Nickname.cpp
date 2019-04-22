#include "Nickname.h"
#include "iostream"
#include "VAR.h"
using namespace std;

void Nickname::nick()
{
	char Namep[10];
	cin >> Namep;
	//scanf("%s", & Name); вылет!!!
	printf("%Потому что, %s теперь в тебе часть артефакта Древних.Во время 'Вихря смерти' он раскололся, и один из осколков попал в тебя.Он часть тебя.А ты часть ордена.\n", Namep);
	cout << "Ты-наследие Древних,  маг и воин одновременно..." << endl;
}
