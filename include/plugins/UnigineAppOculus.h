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

// DO NOT EDIT DIRECTLY. This is an auto-generated file. Your changes will be lost.

#pragma once

#include <UnigineMathLib.h>
#include <UnigineEngine.h>

namespace Unigine
{
namespace Plugins
{
class AppOculus
{
protected:
	virtual ~AppOculus(){}
public:
	UNIGINE_INLINE static AppOculus *get() { return Unigine::Engine::get()->getPlugin<AppOculus>("AppOculus"); }

	enum VIEWPORT
	{
		VIEWPORT_BLACK_SCREEN,
		VIEWPORT_MONO,
		VIEWPORT_STEREO,
		VIEWPORT_STEREO_FINAL,
	};

	enum DEVICE
	{
		DEVICE_HMD,
		DEVICE_CONTROLLER_LEFT,
		DEVICE_CONTROLLER_RIGHT,
	};

	enum BUTTON
	{
		BUTTON_A = 1,
		BUTTON_B = 2,
		BUTTON_RTHUMB = 4,
		BUTTON_RSHOULDER = 8,
		BUTTON_X = 256,
		BUTTON_Y = 512,
		BUTTON_LTHUMB = 1024,
		BUTTON_LSHOULDER = 2048,
		BUTTON_UP = 65536,
		BUTTON_DOWN = 131072,
		BUTTON_LEFT = 262144,
		BUTTON_RIGHT = 524288,
		BUTTON_ENTER = 1048576,
		BUTTON_BACK = 2097152,
		BUTTON_VOLUP = 4194304,
		BUTTON_VOLDOWN = 8388608,
		BUTTON_HOME = 16777216,
	};

	enum TOUCH
	{
		TOUCH_A = 1,
		TOUCH_B = 2,
		TOUCH_RTHUMB = 4,
		TOUCH_RTHUMB_REST = 8,
		TOUCH_RINDEX_TRIGGER = 16,
		TOUCH_RINDEX_POINTING = 32,
		TOUCH_RTHUMB_UP = 64,
		TOUCH_X = 256,
		TOUCH_Y = 512,
		TOUCH_LTHUMB = 1024,
		TOUCH_LTHUMB_REST = 2048,
		TOUCH_LINDEX_TRIGGER = 4096,
		TOUCH_LINDEX_POINTING = 8192,
		TOUCH_LTHUMB_UP = 16384,
	};

	enum AXIS
	{
		AXIS_INDEX_TRIGGER,
		AXIS_HAND_TRIGGER,
		AXIS_THUMBSTICK,
		AXIS_INDEX_TRIGGER_NO_DEADZONE,
		AXIS_HAND_TRIGGER_NO_DEADZONE,
		AXIS_THUMBSTICK_NO_DEADZONE,
	};
	virtual void setEnabled(bool enabled) = 0;
	virtual bool isEnabled() const = 0;
	virtual void setViewportMode(AppOculus::VIEWPORT mode) = 0;
	virtual AppOculus::VIEWPORT getViewportMode() const = 0;
	virtual void setPositionScale(float scale) = 0;
	virtual float getPositionScale() const = 0;
	virtual void setHeadPositionLock(bool lock) = 0;
	virtual void setHeadRotationLock(bool lock) = 0;
	virtual bool isHeadPositionLocked() const = 0;
	virtual bool isHeadRotationLocked() const = 0;
	virtual Math::mat4 getDevicePose(AppOculus::DEVICE device) = 0;
	virtual Math::vec3 getDeviceVelocity(AppOculus::DEVICE device) = 0;
	virtual Math::vec3 getDeviceAngularVelocity(AppOculus::DEVICE device) = 0;
	virtual bool isDeviceConnected(AppOculus::DEVICE device) = 0;
	virtual bool isPoseValid(AppOculus::DEVICE device) = 0;
	virtual bool getControllerButtonPressed(AppOculus::BUTTON button) = 0;
	virtual bool getControllerButtonTouched(AppOculus::TOUCH button) = 0;
	virtual Math::vec2 getControllerAxis(AppOculus::DEVICE device, AppOculus::AXIS axis) = 0;
	virtual void setControllerVibration(AppOculus::DEVICE device, unsigned short duration, float amplitude) = 0;
};

} // namespace Plugins
} // namespace Unigine
