#pragma once
#include "Medication.h"

typedef Medication* TElement;

typedef struct
{
	TElement* elements;
	int length, capacity;
}MedicationArray;

MedicationArray* createMedicationArray(int capacity);
void copyMedication(Medication *medication1, Medication *medication2);
void destroyMedicationArray(MedicationArray *medicationArray);
int addMedication(MedicationArray *medicationArray, Medication *newMedication);
int deleteMedication(MedicationArray *medicationArray, int id);
int updateMedication(MedicationArray *medicationArray, Medication *updatedMedication);
int findMedicationById(MedicationArray *medicationArray, int id);
void listMedication(MedicationArray *medicationArray);
void listMedicationWithName(MedicationArray *medicationArray, char *name);
void listMaxQuantity(MedicationArray *medicationArray, int quantityX);