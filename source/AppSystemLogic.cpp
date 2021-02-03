#include "AppSystemLogic.h"
#include "UnigineApp.h"

using namespace Unigine;


AppSystemLogic::AppSystemLogic()
{
}

AppSystemLogic::~AppSystemLogic()
{
}

int AppSystemLogic::init()
{
	renderInterface.Init();

	Rml::Core::SetRenderInterface(&renderInterface);
	Rml::Core::SetSystemInterface(&systemInterface);

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


	/*renderInterface.Init();*/

	if (Document)
	{
		Document->Show();
		Log::message("Document loaded \n");
	}
	else
	{
		Log::error("Documment is nullptr \n");
	}

	renderHandle = Render::addCallback(Render::CALLBACK_END_SCREEN, MakeCallback(this, &AppSystemLogic::OnRender));

	// Write here code to be called on engine initialization.
	return 1;
}

int AppSystemLogic::update()
{

	return 1;
}

void AppSystemLogic::OnRender() {

	if (Context != nullptr) {
		Context->Render();


		Context->Update();
	}
}

int AppSystemLogic::postUpdate()
{
	// Write here code to be called after updating each render frame.
	return 1;
}

int AppSystemLogic::shutdown()
{
	Rml::Core::Shutdown();
	return 1;
}
