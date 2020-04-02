#include "Controller.h"
#include <stdio.h>
#include <assert.h>

void testMedication()
{
	Medication *med = createMedication(1, "yes", "yas", 100);
	displayMedication(med);
	destroyMedication(med);
}

void testArray()
{
	MedicationArray *arr = createMedicationArray(100);
	Medication *med1 = createMedication(1, "yes", "yas", 100);
	Medication *med2 = createMedication(2, "yo", "lp", 20);
	Medication *med3 = createMedication(2, "pa", "bam", 20);
	addMedication(arr, med1);
	addMedication(arr, med2);
	listMedication(arr);
	updateMedication(arr, med3);
	listMedication(arr);
	deleteMedication(arr, 2);
	listMedication(arr);
	destroyMedication(med1);
	destroyMedication(med2);
	destroyMedication(med3);
	destroyMedicationArray(arr);
}

void testController()
{
	MedicationArray *arr = createMedicationArray(100);
	OperationsStack *oppStack = createOperationsStack();
	Controller *ctrl = createController(arr, oppStack);
	addMedicationController(ctrl, 10, "name", "man", 99, 0);
	int res = addMedicationController(ctrl, 1, "lala", "bob", 3, 0);
	assert(res == 1);
	res = addMedicationController(ctrl, 1, "lala", "bob", 3, 0);
	assert(res == 0);
	res = updateMedicationController(ctrl, 1, "ooo", "mj", 3, 0);
	assert(res == 1);
	res = updateMedicationController(ctrl, 8, "lala", "bob", 3, 0);
	assert(res == 0);
	res = deleteMedicationController(ctrl, 1, 0);
	assert(res == 1);
	res = deleteMedicationController(ctrl, 1, 0);
	assert(res == 0);

	listMedicationController(ctrl);
	destroyController(ctrl);
}