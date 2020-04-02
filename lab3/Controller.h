#pragma once
#include "MedicationDynamicArray.h"
#include "Operations.h"
#include <stdio.h>

typedef struct
{
	MedicationArray* medicationArray;
	OperationsStack* operationsStack;
}Controller;

Controller * createController(MedicationArray *medicationArray, OperationsStack *operationsStack);
void destroyController(Controller* controller);
int addMedicationController(Controller* controller, int id, char *name, char *manufacturer, int quantity, int undoRedoUsed);
int deleteMedicationController(Controller* controller, int id, int undoRedoUsed);
int updateMedicationController(Controller* controller, int id, char *newName, char *newManufacturer, int newQuantity, int undoRedoUsed);
void listMedicationController(Controller *controller);
void listMedicationWithNameController(Controller *controller, char *name);
void listMaxQuantityController(Controller *controller, int quantityX);
Operation* getUndoOperationController(Controller *controller);
Operation* getRedoOperationController(Controller *controller);
