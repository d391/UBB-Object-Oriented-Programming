#include "Subject.h"



Subject::Subject()
{
}


void Subject::notify()
{
	for (Observer* obs : this->vectObs)
		obs->update();
}

Subject::~Subject()
{
}
