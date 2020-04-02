#include "MedicationDynamicArray.h"
#include <stdio.h>
#include <stdlib.h>


MedicationArray* createMedicationArray(int capacity)
{
	/*
	Allocates memory for a dynamic array with Medications as elements
	Input: 
		-capacity: integer
	Output:
		-medicationArray: MedicationArray
	*/
	MedicationArray *medicationArray = (MedicationArray*)malloc(sizeof(MedicationArray));
	medicationArray->capacity = capacity;
	medicationArray->length = 0;
	medicationArray->elements = (TElement*)malloc(capacity * sizeof(TElement));
	return medicationArray;
}

void copyMedication(Medication *medication1, Medication *medication2)
{
	medication1->id = medication2->id;
	strcpy(medication1->manufacturer, medication2->manufacturer);
	strcpy(medication1->name, medication2->name);
	medication1->quantity = medication2->quantity;
}

void destroyMedicationArray(MedicationArray *medicationArray)
{
	/*
	Deallocates memory of an array of type MedicationArray
	Input:
		-medicationArray: MedicationArray
	Output: -
	*/
	for (int index = 0; index < medicationArray->length; index++)
		destroyMedication(medicationArray->elements[index]);

	free(medicationArray->elements);
	medicationArray->elements = NULL;
	free(medicationArray);
}

int findMedicationById(MedicationArray *medicationArray, int id)
{
	/*
	Searches for a medication by id
	Input: 
		-medicationArray: MedicationArray
	Output:
		-index: the position of the element we were searching for
		or
		- -1: if the element does not exist
	*/
	for (int index = 0; index < medicationArray->length; index++)
		if (id == medicationArray->elements[index]->id)
			return index;
	return -1;
}

int addMedication(MedicationArray *medicationArray, Medication *newMedication)
{
	/*
	Adds a new medication to the medicationArray
	Input:
		-medicationArray: MedicationArray
		-newMedication: Medication
	Output:
		- 1: if the operation was successful (the element does not exist already)
		or
		- 0: otherwise
	*/
	int verifyExistence = findMedicationById(medicationArray, newMedication->id);
	if (verifyExistence != -1)
		return 0;
	medicationArray->elements[medicationArray->length] = createMedication(newMedication->id, newMedication->name, newMedication->manufacturer, newMedication->quantity);
	medicationArray->length++;
	return 1;
}

int deleteMedication(MedicationArray *medicationArray, int id)
{
	/*
	Removes a medication with a given id from the array
	Input:
		-medicationArray: MedicationArray
		-id: integer
	Output:
		- 1: if the operation was successful (the element existed already)
		or
		- 0: otherwise
	*/
	int positionToDelete = findMedicationById(medicationArray, id);
	if (positionToDelete == -1)
		return 0;
	destroyMedication(medicationArray->elements[positionToDelete]);
	for (int index = positionToDelete; index < medicationArray->length - 1; index++)
		medicationArray->elements[index] = medicationArray->elements[index + 1];
	medicationArray->length--;
	return 1;
}	

int updateMedication(MedicationArray *medicationArray, Medication *updatedMedication)
{
	/*
	Updates the information of a medication with a given id
	Input:
		-medicationArray: MedicationArray
		-updatedMedication: Medication
	Output:
		- 1: if the operation was successful (the element existed already)
		or
		- 0: otherwise
	*/
	int positionToUpdate = findMedicationById(medicationArray, updatedMedication->id);
	if (positionToUpdate == -1)
		return 0;
	destroyMedication(medicationArray->elements[positionToUpdate]);
	medicationArray->elements[positionToUpdate] = createMedication(updatedMedication->id, updatedMedication->name, updatedMedication->manufacturer, updatedMedication->quantity);
	copyMedication(medicationArray->elements[positionToUpdate], updatedMedication);
	return 1;
}

void listMedication(MedicationArray *medicationArray)
{
	/*
	Prints in the console the array of medications
	Input:
		-medicationArray: MedicationArray
	Output: -
	*/
	for (int index = 0; index < medicationArray->length; index++)
	{
		displayMedication(medicationArray->elements[index]);
		printf("\n");
	}		
}

void listMedicationWithName(MedicationArray *medicationArray, char *name)
{
	/*
	Prints in the console the medications of a given name
	Input:
		-medicationArray: MedicationArray
		-name: string
	Output: -
	*/
	for (int index = 0; index < medicationArray->length; index++)
		if (strstr(medicationArray->elements[index]->name, name))
		{
			displayMedication(medicationArray->elements[index]);
			printf("\n");
		}
}

void listMaxQuantity(MedicationArray *medicationArray, int quantityX)
{
	for (int index = 0; index < medicationArray->length; index++)
		if (medicationArray->elements[index]->quantity < quantityX)
		{
			displayMedication(medicationArray->elements[index]);
			printf("\n");
		}
}