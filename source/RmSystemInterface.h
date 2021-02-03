#pragma once
#include <RmlUi/Core.h>

#include <UnigineConsole.h>
#include <UnigineApp.h>

class RmSystemInterface : public Rml::Core::SystemInterface
{
public:
	double GetElapsedTime() override;
	bool LogMessage(Rml::Core::Log::Type type, const Rml::Core::String& message) override;
};

