#pragma once
#include "MedicationDynamicArray.h"


typedef struct
{
	char *operationType;
	char *parameters;
} Operation;

Operation *createOperation(char *operationType, char *parameters);
void destroyOperation(Operation *operation);

typedef struct
{
	Operation* undoStack[100];
	Operation* redoStack[100];
	int undoLength, redoLength;
}OperationsStack;

OperationsStack *createOperationsStack();
void copyOperation(Operation *operation1, Operation *operation2);
void destroyOperationsStack(OperationsStack *operationsStack);
void addOperationsStack(OperationsStack *operationsStack, Operation *undoOperation, Operation *redoOperation);
Operation* getUndoOperation(OperationsStack *operationsStack);
Operation* getRedoOperation(OperationsStack *operationsStack);