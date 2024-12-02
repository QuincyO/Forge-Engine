#pragma	once
#include "Platform/WIN32/IApplication.h"

class Application : public IApplication {
	


	//My Application

public:
	
	//Application Constructor
	
	
	Application();
	
	
	
	//Application Destructor
	
	
	~Application();


public:

	// Called to Initialize the Application

	VOID Initialize();

	/* Game Loop - Called on a loop while the application is running */

	VOID Update();



};