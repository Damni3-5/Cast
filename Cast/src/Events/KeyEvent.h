#pragma once

#include "Event.h"

class KeyEvent : public Event
{
public:
	KeyboardKey  GetKeyboardKey () const { return m_KeyboardKey ; }

	EVENT_CLASS_CATEGORY(EventCategoryKeyboard | EventCategoryInput)
protected:
	KeyEvent(const KeyboardKey  KeyboardKey )
		: m_KeyboardKey (KeyboardKey ) {}

	KeyboardKey  m_KeyboardKey ;
};

class KeyPressedEvent : public KeyEvent
{
public:
	KeyPressedEvent(const KeyboardKey  KeyboardKey , bool isRepeat = false)
		: KeyEvent(KeyboardKey ), m_IsRepeat(isRepeat) {}

	bool IsRepeat() const { return m_IsRepeat; }

	std::string ToString() const override
	{
		std::stringstream ss;
		ss << "KeyPressedEvent: " << m_KeyboardKey  << " (repeat = " << m_IsRepeat << ")";
		return ss.str();
	}

	EVENT_CLASS_TYPE(KeyPressed)
private:
	bool m_IsRepeat;
};

class KeyReleasedEvent : public KeyEvent
{
public:
	KeyReleasedEvent(const KeyboardKey  KeyboardKey )
		: KeyEvent(KeyboardKey ) {}

	std::string ToString() const override
	{
		std::stringstream ss;
		ss << "KeyReleasedEvent: " << m_KeyboardKey ;
		return ss.str();
	}

	EVENT_CLASS_TYPE(KeyReleased)
};

class KeyTypedEvent : public KeyEvent
{
public:
	KeyTypedEvent(const KeyboardKey  KeyboardKey )
		: KeyEvent(KeyboardKey ) {}

	std::string ToString() const override
	{
		std::stringstream ss;
		ss << "KeyTypedEvent: " << m_KeyboardKey ;
		return ss.str();
	}

	EVENT_CLASS_TYPE(KeyTyped)
};