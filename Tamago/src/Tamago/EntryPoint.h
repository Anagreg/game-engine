#pragma once

#ifdef TG_PLATFORM_WINDOWS

extern Tamago::Application* Tamago::CreateApplication();

int main(int argc, char** argv) {
	Tamago::Log::Init();
	TG_CORE_INFO("Initialized Log");
	int val = 12;
	TG_CLIENT_CRITICAL("Fatal number {0}", val);

	auto app = Tamago::CreateApplication();
	app->Run();
	delete app;
}

#endif