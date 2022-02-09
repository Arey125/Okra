#pragma once
#include "okrapch.h"

#include "Okra/Core.h"

namespace okra
{
	enum class EventType
	{
		None = 0,
		WindowClose, WindowResize, WindowFocus, WindowMoved,
		AppTick, AppUpdate, AppRender,
		KeyPressed, KeyReleased, KeyTyped,
		MouseButtonPressed, MouseButtonReleased, MouseMoved, MouseScrolled
	};

	enum EventCategory
	{
		None = 0,
		EventCategoryApp			= BIT(0),
		EventCategoryInput			= BIT(1),
		EventCategoryKeyboard		= BIT(2),
		EventCategoryMouse			= BIT(3),
		EventCategoryMouseButton	= BIT(4)
	};

#define EVENT_CLASS_TYPE(type)	static EventType getStaticType() { return EventType::##type; }\
								virtual EventType getEventType() const override { return getStaticType(); }\
								virtual const char* getName() const override { return #type; }

#define EVENT_CLASS_CATEGORY(category) virtual int getCategoryFlags() const override { return category; }

	template <typename ... Args>
	void insertIntoStringStream(std::stringstream& ss, Args ... args)
	{
		(ss << ... << args);
	}

#define EVENT_CLASS_TO_STRING(className, ...)	std::string toString() const override\
												{\
													std::stringstream ss;\
													insertIntoStringStream(ss, #className, ": ", __VA_ARGS__);\
													return ss.str();\
												}

	class OKRA_API Event
	{
		friend class EventDispatcher;
	public:
		virtual EventType getEventType() const = 0;
		virtual const char* getName() const = 0;
		virtual int getCategoryFlags() const = 0;
		virtual std::string toString() const { return getName(); }

		inline bool isInCategory(EventCategory category)
		{
			return getCategoryFlags() & category;
		}
		bool handled = false;
	protected:
	};

	class EventDispatcher
	{
		template<typename T>
		using EventFn = std::function<bool(T&)>;
	public:
		EventDispatcher(Event& event)
			: m_Event(event) {}

		template<typename T>
		bool dispatch(EventFn<T> func)
		{
			if (m_Event.getEventType() == T::getStaticType())
			{
				m_Event.handled = func(*(T*)&m_Event);
				return true;
			}
			return false;
		}

	private:
		Event& m_Event;
	};

	template<typename OStream>
	inline OStream& operator<<(OStream& os, const Event& e)
	{
		return os << e.toString();
	}
}