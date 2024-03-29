#include "pch.h"
#include "Headers.h"
#include <locale>
#include <cwchar>
#include <iostream>

#include "Div.h"
#include "Graphs.h"
#include "LexAnaliz.h"
#include "PolishNotation.h"

using namespace std;

int _tmain(int argc, _TCHAR* argv[])
{
	setlocale(LC_ALL, "rus");
	Log::LOG log = Log::INITLOG;
	try
	{
		Parm::PARM parm = Parm::getparm(argc, argv);
		log = Log::getlog(parm.log);
		In::IN in = In::getin(parm.in);
		Lex::LEX lex = Lex::lexAnaliz(log, in);
		bool rc = startPolishNotation(lex);
		if (rc)
			cout << "Польская запись построена" << endl;
		else
			cout << "Польская запись не построена" << endl;
		LT::showTable(lex.lextable, log);
		IT::showTable(lex.idtable);
		Log::Close(log);

	}
	catch (Error::ERROR e)
	{
		Log::WriteError(log, e);
	};
	system("notepad \\Mac\Home\Desktop\iap\lab14con\lab14con\in.txt.log");
	system("pause");
	return 0;
};
