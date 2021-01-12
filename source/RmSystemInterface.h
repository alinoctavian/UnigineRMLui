#pragma once
#include "RmlUi/Core/SystemInterface.h"
#include "RmlUi/Core/Input.h"

#include <UnigineConsole.h>

class RmSystemInterface : public Rml::Core::SystemInterface
{


public:
	double GetElapsedTime() override;
	bool LogMessage(Rml::Core::Log::Type type, const Rml::Core::String& message) override;

};

