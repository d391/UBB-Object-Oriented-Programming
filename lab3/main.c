#include "ui.h"
#include "tests.h"
#include <crtdbg.h>
#include <stdio.h>
#include <crtdbg.h>


int main()
{
	MedicationArray *medicationArray = createMedicationArray(100);
	OperationsStack *operationsStack = createOperationsStack();
	Controller *controller = createController(medicationArray, operationsStack);
	//testMedication();
	//testArray();
	//testController();
	UI* ui = createUI(controller);

	startUI(ui);
	destroyUI(ui);
	_CrtDumpMemoryLeaks();
	return 0;
}