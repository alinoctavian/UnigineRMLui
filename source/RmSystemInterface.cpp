#include "RmSystemInterface.h"
#include <UnigineApp.h>

double RmSystemInterface::GetElapsedTime()
{
	return Unigine::App::getFps();
}

bool RmSystemInterface::LogMessage(Rml::Core::Log::Type type, const Rml::Core::String& message)
{

	Rml::Core::String lString = message;
	lString += " \n";

	if (type == Rml::Core::Log::LT_WARNING)
		Unigine::Log::warning(lString.c_str());
	else if (type == Rml::Core::Log::LT_ERROR)
		Unigine::Log::error(lString.c_str());
	else
		Unigine::Log::message(lString.c_str());

	return true;
}
