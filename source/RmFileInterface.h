#pragma once
#include "RmlUi/Core.h"
#include <UnigineApp.h>
#include <UnigineConsole.h>
#include <UnigineEngine.h>
#include <UnigineInterface.h>
#include <UnigineLogic.h>
#include <UnigineStreams.h>
#include <UnigineWorld.h>

class RmFileInterface : public Rml::Core::FileInterface {
public:
	Rml::Core::FileHandle Open(const  Rml::Core::String& path) override;

	// Closes a previously opened file.
	void Close(Rml::Core::FileHandle file) override;

	// Reads data from a previously opened file.
	size_t Read(void* buffer, size_t size, Rml::Core::FileHandle file) override;

	// Seeks to a point in a previously opened file.
	bool Seek(Rml::Core::FileHandle file, long offset, int origin) override;

	// Returns the current position of the file pointer.
	size_t Tell(Rml::Core::FileHandle file) override;
};


