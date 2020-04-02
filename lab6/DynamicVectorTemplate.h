#pragma once

template <typename T>
class DynamicVectorTemplate
{
private:
	T* elements;
	int size = 0, capacity;

public:
	DynamicVectorTemplate<T>(int capacity = 100);
	int getSize() const { return this->size; };
	T* getAllElements() const { return this->elements; };
	void setSize(int newSize);
	void setElements(T* elements);
	void addElement(T elementToAdd);
	void deleteElement(int positionToDelete);
	void updateElement(int indexOfElementToUpdate, T updatedElement);
	~DynamicVectorTemplate<T>();

private:
	void resize();
};

template <typename T>
DynamicVectorTemplate<T>::DynamicVectorTemplate(int capacity)
{
	this->size = 0;
	this->capacity = capacity;
	this->elements = new T[capacity];
}

template <typename T>
void DynamicVectorTemplate<T>::setSize(int newSize)
{
	this->size = newSize;
}

template <typename T>
void DynamicVectorTemplate<T>::setElements(T* elements)
{
	for (int index = 0; index < this->size; index++)
		this->elements[index] = elements[index];
}

template <typename T>
void DynamicVectorTemplate<T>::addElement(T elementToAdd)
{
	if (this->size == this->capacity)
		this->resize();
	this->elements[this->size] = elementToAdd;
	this->size++;
}

template <typename T>
void DynamicVectorTemplate<T>::deleteElement(int positionToDelete)
{
	for (int index = positionToDelete; index < this->size - 1; index++)
		this->elements[index] = this->elements[index + 1];
	this->size--;
}

template <typename T>
void DynamicVectorTemplate<T>::updateElement(int indexOfElementToUpdate, T updatedElement)
{
	this->elements[indexOfElementToUpdate] = updatedElement;
}

template <typename T>
void DynamicVectorTemplate<T>::resize()
{
	T *auxArray = new T[this->capacity * 2];
	for (int index = 0; index < this->size; index++)
		auxArray[index] = this->elements[index];
	delete[] this->elements;
	this->elements = auxArray;
	this->capacity = this->capacity * 2;
}

template <typename T>
DynamicVectorTemplate<T>::~DynamicVectorTemplate()
{
	//delete[] this->elements;
}