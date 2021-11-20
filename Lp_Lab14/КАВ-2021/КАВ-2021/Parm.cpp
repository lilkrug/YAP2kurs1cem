#include "stdafx.h"
#include "Parm.h"
#include "Error.h"

void offset(char* str, int len) {
	for (int i = 0; i < len; ++i) {
		for (int j = 0; j < strlen(str); ++j) {
			str[j] = str[j + 1];
		}
	}
}

Parm::PARM Parm::getparm(int argc, char* argv[]) {
	auto result = std::make_unique<Parm::PARM>();
	std::string argument;
	for (auto index = 0; index < argc; ++index) {
		argument = argv[index];
		if (argument.find(PARM_IN) != std::string::npos) result->in += argument.substr(strlen(PARM_IN));
		else if (argument.find(PARM_OUT) != std::string::npos) result->out += argument.substr(strlen(PARM_OUT));
		else if (argument.find(PARM_LOG) != std::string::npos) result->log += argument.substr(strlen(PARM_LOG));
	}
	if (result->in.length() != 0) {
		if (result->in.length() > PARM_MAX_SIZE) throw ERROR_THROW(104);
		if (result->out.length() == 0) {
			result->out += result->in + PARM_OUT_DEFAULT_EXT;
			if (result->out.length() > PARM_MAX_SIZE) throw ERROR_THROW(104);
		}
		if (result->log.length() == 0) {
			result->log += result->in + PARM_LOG_DEFAULT_EXT;
			if (result->log.length() > PARM_MAX_SIZE) throw ERROR_THROW(104);
		}
		return *result;
	}
	else {
		throw ERROR_THROW(100);
	}
}
