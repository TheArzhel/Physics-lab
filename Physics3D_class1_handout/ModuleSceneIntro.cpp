#include "Globals.h"
#include "Application.h"
#include "ModuleSceneIntro.h"
#include "Primitive.h"

ModuleSceneIntro::ModuleSceneIntro(Application* app, bool start_enabled) : Module(app, start_enabled)
{
}

ModuleSceneIntro::~ModuleSceneIntro()
{}

// Load assets
bool ModuleSceneIntro::Start()
{
	LOG("Loading Intro assets");
	bool ret = true;

	// TODO 2: Place the camera one unit up in Y and one unit to the right
	// experiment with different camera placements, then use LookAt()
	// to make it look at the center
	vec3 vector(0,0,0);
	App->camera->Position.x=1;

	App->camera->Position.y=1;

	App->camera->LookAt(vector);
	return ret;
}

// Load assets
bool ModuleSceneIntro::CleanUp()
{
	LOG("Unloading Intro scene");

	return true;
}

// Update: draw background
update_status ModuleSceneIntro::Update()
{
	// TODO 1: Create a Plane primitive. This uses the plane formula
	// so you have to express the normal of the plane to create 
	// a plane centered around 0,0. Make that it draw the axis for reference

	Plane plane(1,1,1,-3);
	plane.axis = true;
	plane.Render();


	// TODO 6: Draw a sphere of 0.5f radius around the center
	// Draw somewhere else a cube and a cylinder in wireframe

	Sphere pokeball(0.5);
	pokeball.Render();

	Cube minecraft(1, 1, 1);
	minecraft.wire = true;
	minecraft.SetPos(1,1,1);
	minecraft.Render();

	Cylinder cylinder(1,3);
	cylinder.wire = true;
	cylinder.SetPos(1,-1,-1);
	cylinder.Render();

	return UPDATE_CONTINUE;
}

