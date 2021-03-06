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


#ifndef __APP_SYSTEM_LOGIC_H__
#define __APP_SYSTEM_LOGIC_H__

#include <UnigineLogic.h>

#include <RmlUi/Debugger.h>

#include "RmSystemInterface.h"
#include "RmRenderInterface.h"

class AppSystemLogic : public Unigine::SystemLogic
{
	RmRenderInterface renderInterface;
	RmSystemInterface systemInterface;

	Rml::Core::Context* Context;
	Rml::Core::ElementDocument* Document;


	void* renderHandle;
public:
	AppSystemLogic();
	virtual ~AppSystemLogic();

	int init() override;

	int update() override;
	int postUpdate() override;

	int shutdown() override;


	void OnRender();
};

#endif // __APP_SYSTEM_LOGIC_H__
