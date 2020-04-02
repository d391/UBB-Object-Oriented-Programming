#pragma once

typedef struct
{
	int id, quantity;
	char *manufacturer, *name;
} Medication;

Medication* createMedication(int id, char *name, char *manufacturer, int quantity);
int getId(Medication *medication);
char* getName(Medication *medication);
char* getManufacturer(Medication *medication);
int getQuantity(Medication *medication);
void displayMedication(Medication *medication);
void destroyMedication(Medication *medication);









