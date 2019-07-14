#pragma once
#include "Headers.h"
#include "IT.h"
#include "LT.h"

namespace Lex
{
	struct LEX
	{
		IT::IdTable idtable;;
		LT::LexTable lextable;
	};

	LEX lexAnaliz(Log::LOG log, In::IN in);
}