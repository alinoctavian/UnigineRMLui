#include "RmFileInterface.h"
#include <fstream>

using namespace Unigine;

Rml::Core::FileHandle RmFileInterface::Open(const Rml::Core::String& path)
{
	std::ofstream myfile;
	myfile.open(path.c_str());
	
	return Rml::Core::FileHandle();
}

void RmFileInterface::Close(Rml::Core::FileHandle file)
{
}

size_t RmFileInterface::Read(void* buffer, size_t size, Rml::Core::FileHandle file)
{
	return size_t();
}

bool RmFileInterface::Seek(Rml::Core::FileHandle file, long offset, int origin)
{
	return false;
}

size_t RmFileInterface::Tell(Rml::Core::FileHandle file)
{
	return size_t();
}
