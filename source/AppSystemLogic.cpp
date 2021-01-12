/* Copyright (C) 2005-2020, UNIGINE. All rights reserved.
 *
 * This file is a part of the UNIGINE 2 SDK.
 *
 * Your use and / or redistribution of this software in source and / or
 * binary form, with or without modification, is subject to: (i) your
 * ongoing acceptance of and compliance with the terms and conditions of
 * the UNIGINE License Agreement; and (ii) your inclusion of this notice
 * in any version of this software that you use or redistribute.
 * A copy of the UNIGINE License Agreement is available by contacting
 * UNIGINE. at http://unigine.com/
 */


#include "AppSystemLogic.h"
#include "UnigineApp.h"

using namespace Unigine;

// System logic, it exists during the application life cycle.
// These methods are called right after corresponding system script's (UnigineScript) methods.

AppSystemLogic::AppSystemLogic()
{
}

AppSystemLogic::~AppSystemLogic()
{
}

int AppSystemLogic::init()
{
	App::setBackgroundUpdate(true);

	Renderer.Initialize();
	
	Rml::Core::SetRenderInterface(&Renderer);
	Rml::Core::SetSystemInterface(&SystemInterface);

	if (!Rml::Core::Initialise())
		Log::error("RmlUI failed to initialize \n");

	Rml::Core::LoadFontFace("assets/Delicious-Bold.otf");
	Rml::Core::LoadFontFace("assets/Delicious-BoldItalic.otf");
	Rml::Core::LoadFontFace("assets/Delicious-Italic.otf");
	Rml::Core::LoadFontFace("assets/Delicious-Roman.otf");

	Context = Rml::Core::CreateContext("default",
		Rml::Core::Vector2i(App::getWidth(), App::getHeight()));

	Rml::Debugger::Initialise(Context);

	if (Context)
	{
		Log::message("Context loaded \n");
	}
	else
	{
		Log::error("Context is nullptr \n");
	}


	Document = Context->LoadDocument("assets/demo.rml");

	if (Document)
	{
		Document->Show();
		Log::message("Document loaded \n");
	}
	else
	{
		Log::error("Documment is nullptr \n");
	}

	return 1;
}

////////////////////////////////////////////////////////////////////////////////
// start of the main loop
////////////////////////////////////////////////////////////////////////////////

int AppSystemLogic::update()
{

	if (Context != nullptr) {
		Context->Render();

		
		Context->Update();
	}
	return 1;
}

int AppSystemLogic::postUpdate()
{
	// Write here code to be called after updating each render frame.
	return 1;
}

////////////////////////////////////////////////////////////////////////////////
// end of the main loop
////////////////////////////////////////////////////////////////////////////////

int AppSystemLogic::shutdown()
{
	Rml::Core::Shutdown();
	// Write here code to be called on engine shutdown.
	return 1;
}
