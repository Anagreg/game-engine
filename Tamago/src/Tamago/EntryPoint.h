#pragma once

#ifdef TG_PLATFORM_WINDOWS

extern Tamago::Application* Tamago::CreateApplication();

int main(int argc, char** argv) {
	auto app = Tamago::CreateApplication();
	app->Run();
	delete app;
}

#endif