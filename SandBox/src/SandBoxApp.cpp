#include <Zengine.h>

class SandBoxApp : public Zengine::Application
{
public:
	SandBoxApp()
	{
	}

	~SandBoxApp()
	{
	}
};

Zengine::Application* Zengine::CreateApplication()
{
	return new SandBoxApp();
}