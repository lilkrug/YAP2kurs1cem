#include "stdafx.h"
#include "Error.h"
#include "Parm.h"
#include "Log.h"
#include "LT.h"
#include "IT.h"
#include "Lex.h"

int main(int argc, char* argv[])
{
	setlocale(LC_ALL, "rus");
	Log::LOG log = Log::INITLOG;
	try
	{
		Parm::PARM parm = Parm::getparm(argc, argv);
		log = Log::getlog(parm.log);
		Log::WriteLog(log);
		Log::WriteParm(log, parm);
		In::IN in = In::getin(parm.in);
		Log::WriteIn(log, in);
		IT::IdTable idTable = IT::Create(in.size);
		LT::LexTable lexTable = LT::Create(in.size);
		Lex::Scan(lexTable, idTable, in, parm, log);
		LT::ShowTable(lexTable, log.stream);
		IT::ShowTable(idTable, log.stream);
		Log::Close(log);
	}
	catch (Error::ERROR e)
	{
		Log::WriteLine(log, "Teñò: ", "");
		Log::WriteError(log, e);
		Log::Close(log);
	};
}