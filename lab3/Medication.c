#include "Medication.h"
#include <string.h>
#include <stdio.h>
#include <stdlib.h>

Medication* createMedication(int id, char *name, char *manufacturer, int quantity)
{
	Medication* medication = (Medication*)malloc(sizeof(Medication));

	medication->id = id;

	medication->name = (char*)malloc(sizeof(char) * (strlen(name) + 1));
	strcpy(medication->name, name);

	medication->manufacturer = (char*)malloc(sizeof(char) * (strlen(manufacturer) + 1));
	strcpy(medication->manufacturer, manufacturer);

	medication->quantity = quantity; 

	return medication;
}

void destroyMedication(Medication *medication)
{
	free(medication->name);
	free(medication->manufacturer);
	free(medication);
}

int getId(Medication *medication)
{
	return medication->id;
}

char* getName(Medication *medication)
{
	return medication->name;
}

char* getManufacturer(Medication *medication)
{
	return medication->manufacturer;
}

int getQuantity(Medication *medication)
{
	return medication->quantity;
}

void displayMedication(Medication *medication)
{
	printf("Id: %d \n", medication->id);
	printf("Name: %s \n", medication->name);
	printf("Manufacturer: %s \n", medication->manufacturer);
	printf("Quantity: %d \n", medication->quantity);
}