#include"Animal.h"
#include"Beast.h"
#include"Bird.h"
#include"Aviary.h"
#include"AviaryException.h"

void main()
{
	Beast d("Dog", true, "With human", true);
	d.show();

	Bird h("Hen", false, 5, false);
	h.show();

	Beast w("Wolf", true, "Forest", false);
	w.show();

	Bird p("Penguin", true, 14, false);
	p.show();

	Aviary a(10);
	/*Aviary b(1);
	Aviary c(5);*/


	try
	{
		a.addAnimal(&d);
	}
	catch (AviaryException* obj)
	{
		obj->showMessage();
	}
	try
	{
		a.addAnimal(&h);
	}
	catch (AviaryException* obj)
	{
		obj->showMessage();
	}
	try
	{
		a.addAnimal(&w);
	}
	catch (AviaryException* obj)
	{
		obj->showMessage();
	}
	try
	{
		a.addAnimal(&p);
	}
	catch (AviaryException* obj)
	{
		obj->showMessage();
	}

	a.showAviary();


	/*        
			Animal #1

		Type: Beast
		Name: Dog
		Predator: Yes
		Habitat: With human
		Can be domestic animal: Yes

			Animal #2

		Type: Beast
		Name: Wolf
		Predator: Yes
		Habitat: Forest
		Can be domestic animal: No

			Animal #3

		Type: Bird
		Name: Penguin
		Predator: Yes
		Speed: 14
		Type of bird: Walking
	*/
}