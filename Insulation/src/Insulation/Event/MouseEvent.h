// ALL MOUSE EVENTS ARE DEFINED HERE
#pragma once

#include "Event.h"

namespace Insulation
{
	class MouseMoveEvent : public Event
	{
	public:
		MouseMoveEvent(float MousePosX, float MousePosY)
			:m_MouseX(MousePosX), m_MouseY(MousePosY) {}

		inline float GetX() { return m_MouseX; };
		inline float GetY() { return m_MouseY; };

		std::string ToString() const override {
			std::stringstream ss;
			ss << "MouseMovedEvent: (" << m_MouseX << "," << m_MouseY << ")";
			return ss.str();
		}

		EVENT_CLASS_CATEGORY(EventCategoryInput | EventCategoryMouse)
			EVENT_CLASS_TYPE(MouseMoved)
	private:
		float m_MouseX, m_MouseY;
	};

	class MouseScrollEvent : public Event
	{
	public:
		MouseScrollEvent(float MouseXOffset, float MouseYOffset)
			:m_MouseXOffset(MouseXOffset), m_MouseYOffset(MouseYOffset) {}

		inline float GetMouseXOffset() { return m_MouseXOffset; };
		inline float GetMouseYOffset() { return m_MouseYOffset; };

		std::string ToString() const override {
			std::stringstream ss;
			ss << "MouseScrollEvent Offset: (" << m_MouseXOffset << "," << m_MouseYOffset << ")";
			return ss.str();
		}

		EVENT_CLASS_CATEGORY(EventCategoryInput | EventCategoryMouse)
			EVENT_CLASS_TYPE(MouseScrolled)
	private:
		float m_MouseXOffset, m_MouseYOffset;
	};

	class MouseButtonEvent : public Event
	{
	public:
		inline int GetMouseButton() const { return m_MouseButton; };

		EVENT_CLASS_CATEGORY(EventCategoryInput | EventCategoryMouse | EventCategoryMouseButton)

	protected:
		MouseButtonEvent(int mouseButton)
			:m_MouseButton(mouseButton) {}

		int m_MouseButton;
	};

	class MouseButtonPressedEvent : public MouseButtonEvent
	{
	public:
		MouseButtonPressedEvent(int button)
			:MouseButtonEvent(button) {}

		std::string ToString() const override {
			std::stringstream ss;
			ss << "MouseButtonPressedEvent: " << m_MouseButton;
			return ss.str();
		}

		EVENT_CLASS_TYPE(MouseButtonPressed)
	};

	class MouseButtonReleasedEvent : public MouseButtonEvent
	{
	public:
		MouseButtonReleasedEvent(int button)
			:MouseButtonEvent(button) {}

		std::string ToString() const override {
			std::stringstream ss;
			ss << "MouseButtonReleasedEvent: " << m_MouseButton;
			return ss.str();
		}

		EVENT_CLASS_TYPE(MouseButtonReleased)
	};
}