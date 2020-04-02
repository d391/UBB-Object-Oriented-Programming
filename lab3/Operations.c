#include "Operations.h"
#include <stdlib.h>
#include <stdio.h>

Operation *createOperation(char *operationType, char *parameters)
{
	Operation* operation = (Operation*)malloc(sizeof(Operation));
	operation->operationType = (char*)malloc((strlen(operationType) + 1) * sizeof(char));
	strcpy(operation->operationType, operationType);
	operation->parameters = (char*)malloc((strlen(parameters) + 1) * sizeof(char));
	strcpy(operation->parameters, parameters);
	return operation;
}

void copyOperation(Operation *operation1, Operation *operation2)
{
	strcpy(operation1->operationType, operation2->operationType);
	strcpy(operation1->parameters, operation2->parameters);
}

void destroyOperation(Operation *operation)
{
	free(operation->operationType);
	free(operation->parameters);
	free(operation);
}

OperationsStack *createOperationsStack()
{
	OperationsStack *operationStack = (OperationsStack*)malloc(sizeof(OperationsStack));
	operationStack->undoLength = 0;
	operationStack->redoLength = 0;
	return operationStack;
}

void destroyOperationsStack(OperationsStack *operationsStack)
{
	for (int index = 0; index < operationsStack->undoLength; index++)
		destroyOperation(operationsStack->undoStack[index]);
	for (int index = 0; index < operationsStack->redoLength; index++)
		destroyOperation(operationsStack->redoStack[index]);
	free(operationsStack);
}

void addOperationsStack(OperationsStack *operationsStack, Operation *undoOperation, Operation *redoOperation)
{
	operationsStack->undoStack[operationsStack->undoLength] = createOperation(undoOperation->operationType, undoOperation->parameters);
	operationsStack->redoStack[operationsStack->redoLength] = createOperation(redoOperation->operationType, redoOperation->parameters);
	copyOperation(operationsStack->undoStack[operationsStack->undoLength], undoOperation);
	copyOperation(operationsStack->redoStack[operationsStack->redoLength], redoOperation);
	operationsStack->undoLength++;
	operationsStack->redoLength++;
}

Operation* getUndoOperation(OperationsStack *operationsStack)
{
	operationsStack->undoLength--;
	return operationsStack->undoStack[operationsStack->undoLength];
}

Operation* getRedoOperation(OperationsStack *operationsStack)
{
	operationsStack->redoLength--;
	return operationsStack->redoStack[operationsStack->redoLength];
}
