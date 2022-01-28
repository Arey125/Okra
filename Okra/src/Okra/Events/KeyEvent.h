#pragma once

#include "Event.h"

namespace okra
{
	class OKRA_API KeyEvent : public Event
	{
	public:
		inline int getKeyCode() const { return m_KeyCode; }

		EVENT_CLASS_CATEGORY(EventCategoryKeyboard | EventCategoryInput)
	protected:
		KeyEvent(int keycode)
			: m_KeyCode(keycode) {}

		int m_KeyCode;
	};

	class OKRA_API KeyPressedEvent : public KeyEvent
	{
	public:
		KeyPressedEvent(int keycode, int repeatCount)
			: KeyEvent(keycode), m_RepeatCount(repeatCount) {}

		inline auto getRepeatCount() const { return m_RepeatCount; }

		EVENT_CLASS_TO_STRING(KeyPressedEvent, m_KeyCode, " (",  m_RepeatCount, " repeats)")

		EVENT_CLASS_TYPE(KeyPressed)
	private:
		int m_RepeatCount;
	};

	class OKRA_API KeyReleasedEvent : public KeyEvent
	{
	public:
		KeyReleasedEvent(int keycode)
			: KeyEvent(keycode){}

		EVENT_CLASS_TO_STRING(KeyReleasedEvent, m_KeyCode)

		EVENT_CLASS_TYPE(KeyReleased)
	};
}