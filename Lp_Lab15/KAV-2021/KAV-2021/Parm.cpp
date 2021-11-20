#include "stdafx.h"
#include "Parm.h"
#include "Error.h"

Parm::PARM Parm::getparm(int argc, char* argv[]) {
	auto result = std::make_unique<Parm::PARM>();
	std::string argument;
	for (auto index = 0; index < argc; ++index) {
		argument = argv[index];
		if (argument.substr(0, strlen(PARM_IN)).find(PARM_IN) != std::string::npos) result->in += argument.substr(strlen(PARM_IN));
		else if (argument.substr(0, strlen(PARM_OUT)).find(PARM_OUT) != std::string::npos) result->out += argument.substr(strlen(PARM_OUT));
		else if (argument.substr(0, strlen(PARM_LOG)).find(PARM_LOG) != std::string::npos) result->log += argument.substr(strlen(PARM_LOG));
	}
	if (result->in.empty()) {
		if (result->in.length() > PARM_MAX_SIZE) throw ERROR_THROW(104);
		if (result->out.empty()) {
			result->out += result->in + PARM_OUT_DEFAULT_EXT;
			if (result->out.length() > PARM_MAX_SIZE) throw ERROR_THROW(104);
		}
		if (result->log.empty()) {
			result->log += result->in + PARM_LOG_DEFAULT_EXT;
			if (result->log.length() > PARM_MAX_SIZE) throw ERROR_THROW(104);
		}
		return *result;
	}
	else {
		throw ERROR_THROW(100);
	}
}
