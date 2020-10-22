#pragma once

#include "Core.h"

namespace Tamago {

	class TAMAGO_API Application
	{
	public:
		Application();
		virtual ~Application();

		void Run();
	};

	//TO BE DEFINED IN CLIENT!
	Application* CreateApplication();

}

