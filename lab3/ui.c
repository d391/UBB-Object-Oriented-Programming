#include "ui.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

UI *createUI(Controller *controller)
{
	UI *ui = (UI*)malloc(sizeof(UI));
	ui->controller = controller;
	return ui;
}

void destroyUI(UI *ui)
{
	destroyController(ui->controller);
	free(ui);
}

void displayMenu()
{
	printf("Type: \n");
	printf("	add <id>, <manufacturer>, <name>, <quantity> - to add a new medication\n");
	printf("	update <id>, <newManufacturer>, <newName>, <newQuantity> - to update the medication with that id\n");
	printf("	delete <id> - to delete the medication with that id\n");
	printf("	list - to see all the medications\n");
	printf("	list <name> - to see the medication with that name\n");
	printf("	list <quantity> - to see the medication which has a quantitiy less than a given one\n");
	printf("	exit - to exit the aplication\n");
}

int processAddCommand(UI *ui, char *parameters, int undoRedoUsed)
{
	char parametersSeparator[] = ", ";
	char paramMatrix[4][30], *parameterToken, index = 0;
	parameterToken = strtok(parameters, parametersSeparator);
	while (parameterToken != NULL)
	{
		strcpy(paramMatrix[index], parameterToken);
		index++;
		parameterToken = strtok(NULL, parametersSeparator);
	}
	return addMedicationController(ui->controller, atoi(paramMatrix[0]), paramMatrix[1], paramMatrix[2], atoi(paramMatrix[3]), undoRedoUsed);
}

int processDeleteCommand(UI *ui, char *parameter, int undoRedoUsed)
{
	int id = atoi(parameter);
	return deleteMedicationController(ui->controller, id, undoRedoUsed);
}

int processUpdateCommand(UI *ui, char *parameters, int undoRedoUsed)
{
	char parametersSeparator[] = ", ";
	char paramMatrix[4][30], *parameterToken, index = 0;
	parameterToken = strtok(parameters, parametersSeparator);
	while (parameterToken != NULL)
	{
		strcpy(paramMatrix[index], parameterToken);
		index++;
		parameterToken = strtok(NULL, parametersSeparator);
	}
	return updateMedicationController(ui->controller, atoi(paramMatrix[0]), paramMatrix[1], paramMatrix[2], atoi(paramMatrix[3]), undoRedoUsed);
}


void processCommand(UI *ui, char *commandType, char *parameters, int undoRedoUsed)
{
	int success = -1;
	if (strcmp(commandType, "add") == 0)
	{
		success = processAddCommand(ui, parameters, undoRedoUsed);
		if (success == 1)
			printf("Operation complete!\n");
		else
			printf("Medication already existent! No modifications were made.\n");
	}
	else if (strcmp(commandType, "delete") == 0)
	{
		success = processDeleteCommand(ui, parameters, undoRedoUsed);
		if (success == 1)
			printf("Operation complete!\n");
		else
			printf("Non-existent id! No modifications were made.\n");
	}
	else if (strcmp(commandType, "update") == 0)
	{
		success = processUpdateCommand(ui, parameters, undoRedoUsed);
		if (success == 1)
			printf("Operation complete!\n");
		else
			printf("Non-existent id! No modifications were made.\n");
	}
	else if (strcmp(commandType, "list") == 0)
		if (strchr("0123456789", parameters[0]))
			listMaxQuantityController(ui->controller, atoi(parameters));
		else
			listMedicationWithNameController(ui->controller, parameters);
	else
		printf("Invalid command! ");
}


void startUI(UI *ui)
{
	char command[60], copyCommand[60], *commandType, spaceSeparator[] = " ";
	int sizeOfCommand = -1;
	while (1)
	{
		displayMenu();
		scanf("%[^\n]%*c", command);
		if (strcmp(command, "exit") == 0)
			return;
		else if (strcmp(command, "list") == 0)
			listMedicationController(ui->controller);
		else if (strcmp(command, "undo") == 0)
		{
			Operation *operation = getUndoOperationController(ui->controller);
			processCommand(ui, operation->operationType, operation->parameters, 1);
			destroyOperation(operation);
		}
		else if (strcmp(command, "redo") == 0)
		{
			Operation *operation = getRedoOperationController(ui->controller);
			processCommand(ui, operation->operationType, operation->parameters, 1);
			destroyOperation(operation);
		}
		else
		{
			strcpy(copyCommand, command);
			commandType = strtok(copyCommand, spaceSeparator);
			char *parameters = (char*)malloc((strlen(command + strlen(commandType)) + 2) * sizeof(char));
			strcpy(parameters, command + strlen(commandType) + 1);
			processCommand(ui, commandType, parameters, 0);
			free(parameters);
		}
	}
}