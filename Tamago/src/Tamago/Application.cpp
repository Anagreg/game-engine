#include "tgpch.h"
#include "Application.h"

#include "Tamago/Events/ApplicationEvent.h"
#include "Tamago/Log.h"



namespace Tamago {
	Application::Application() {

	}

	Application::~Application() {

	}

	void Application::Run() {

		WindowResizeEvent e(1280, 720);
		if (e.IsInCategory(EventCategoryApplication))
		{
			TG_CLIENT_TRACE(e);
		}
		if (e.IsInCategory(EventCategoryInput))
		{
			TG_CLIENT_TRACE(e);
		}

		while (true);
	}
}
