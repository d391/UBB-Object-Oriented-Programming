#include "Controller.h"
#include "Operations.h"
#include <stdio.h>
#include <string.h>
#include <stdlib.h>

Controller * createController(MedicationArray *medicationArray, OperationsStack* operationsStack)
{
	Controller *controller = (Controller*)malloc(sizeof(Controller));
	controller->medicationArray = medicationArray;
	controller->operationsStack = operationsStack;
	return controller;
}

void destroyController(Controller* controller)
{
	destroyMedicationArray(controller->medicationArray);
	destroyOperationsStack(controller->operationsStack);
	free(controller);
}

int addMedicationController(Controller* controller, int id, char *name, char *manufacturer, int quantity, int undoRedoUsed)
{
	Medication *medication = createMedication(id, name, manufacturer, quantity);
	int operationSuccess = addMedication(controller->medicationArray, medication);

	if (operationSuccess == 1 && undoRedoUsed == 0)
	{
		char charId[3] = " ", charQuantity[10] = " ";
		char parameters[100] = "";
		strcat(parameters, _itoa(id, charId, 10));
		strcat(parameters, ", ");
		strcat(parameters, manufacturer);
		strcat(parameters, ", ");
		strcat(parameters, name);
		strcat(parameters, ", ");
		strcat(parameters, _itoa(quantity, charQuantity, 10));
		Operation *redoOperation = createOperation("add", parameters);
		Operation *undoOperation = createOperation("delete", _itoa(id, charId, 10));
		addOperationsStack(controller->operationsStack, undoOperation, redoOperation);
		destroyOperation(undoOperation);
		destroyOperation(redoOperation);
	}

	destroyMedication(medication);
	return operationSuccess;
}

int deleteMedicationController(Controller* controller, int id, int undoRedoUsed)
{
	int auxIndex = findMedicationById(controller->medicationArray, id), operationSuccess = 0;
	if (auxIndex != -1 && undoRedoUsed == 0)
	{
		Medication *auxMedication = controller->medicationArray->elements[auxIndex];
		char charId[3] = " ", charQuantity[10] = " ";
		char parameters[100] = "";
		strcat(parameters, _itoa(id, charId, 10));
		strcat(parameters, ", ");
		strcat(parameters, auxMedication->manufacturer);
		strcat(parameters, ", ");
		strcat(parameters, auxMedication->name);
		strcat(parameters, ", ");
		strcat(parameters, _itoa(auxMedication->quantity, charQuantity, 10));
		operationSuccess = deleteMedication(controller->medicationArray, id);
	
		Operation *undoOperation = createOperation("add", parameters);
		Operation *redoOperation = createOperation("delete", _itoa(id, charId, 10));
		addOperationsStack(controller->operationsStack, undoOperation, redoOperation);
		destroyOperation(undoOperation);
		destroyOperation(redoOperation);

	}
	if (undoRedoUsed == 1)
		operationSuccess = deleteMedication(controller->medicationArray, id);

	return operationSuccess;
}

int updateMedicationController(Controller* controller, int id, char *newName, char *newManufacturer, int newQuantity, int undoRedoUsed)
{
	Medication *newMedication = createMedication(id, newName, newManufacturer, newQuantity);
	char charId[3] = " ", charQuantity[10] = " ";
	char parameters[100] = "";
	strcat(parameters, _itoa(id, charId, 10));
	int auxIndex = findMedicationById(controller->medicationArray, id), operationSuccess = 0;
	if (auxIndex != -1 && undoRedoUsed == 0)
	{
		strcat(parameters, ", ");
		strcat(parameters, controller->medicationArray->elements[auxIndex]->manufacturer);
		strcat(parameters, ", ");
		strcat(parameters, controller->medicationArray->elements[auxIndex]->name);
		strcat(parameters, ", ");
		strcat(parameters, _itoa(controller->medicationArray->elements[auxIndex]->quantity, charQuantity, 10));
		Operation *undoOperation = createOperation("update", parameters);

		operationSuccess = updateMedication(controller->medicationArray, newMedication);

		strcpy(parameters, "");
		strcat(parameters, _itoa(id, charId, 10));
		strcat(parameters, ", ");
		strcat(parameters, newManufacturer);
		strcat(parameters, ", ");
		strcat(parameters, newName);
		strcat(parameters, ", ");
		strcat(parameters, _itoa(newQuantity, charQuantity, 10));
		Operation *redoOperation = createOperation("update", parameters);

		addOperationsStack(controller->operationsStack, undoOperation, redoOperation);
		destroyOperation(undoOperation);
		destroyOperation(redoOperation);
	}
	if (undoRedoUsed == 1)
		operationSuccess = updateMedication(controller->medicationArray, newMedication);
	destroyMedication(newMedication);
	return operationSuccess;
}

void listMedicationController(Controller *controller)
{
	listMedication(controller->medicationArray);
}

void listMedicationWithNameController(Controller *controller, char *name)
{
	listMedicationWithName(controller->medicationArray, name);
}

void listMaxQuantityController(Controller *controller, int quantityX)
{
	listMaxQuantity(controller->medicationArray, quantityX);
}

Operation* getUndoOperationController(Controller *controller)
{
	return getUndoOperation(controller->operationsStack);
}

Operation* getRedoOperationController(Controller *controller)
{
	return getRedoOperation(controller->operationsStack);
}