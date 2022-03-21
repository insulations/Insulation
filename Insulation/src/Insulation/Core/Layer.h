#pragma once

#include "Insulation/Event/Event.h"

namespace Insulation
{
	class Layer
	{
	public:
		Layer(const std::string&name = "Layer");
		virtual ~Layer();
		virtual void OnAttach() = 0; //��layer��ӵ�layer stack��ʱ�����ô˺������൱��Init����
		virtual void OnDetach() = 0; //��layer��layer stack�Ƴ���ʱ�����ô˺������൱��Shutdown����
		virtual void OnEvent(Event& e) = 0;
		virtual void OnUpdate() = 0;//render loop

	protected:
		bool isEnabled;	// ֵΪfasleʱ����Layer�ᱻ���ã�������ƻ��棬Ҳ��������¼�
		std::string m_DebugName;
	};

}