#include <Tamago.h>

class Sandbox : public Tamago::Application {
public:
	Sandbox() {

	}

	~Sandbox() {

	}
};

Tamago::Application* Tamago::CreateApplication() {
	return new Sandbox();
}