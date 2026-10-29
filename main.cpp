#include <iostream>
#include <cmath>
#include <vector>
using namespace std;

class E_Field
{
	protected:
		double eX;
		double eY;
		double eZ;
	public:
		E_Field();
		virtual ~E_Field();

		void setX(double x)
		{
			eX = x;
		}
		void setY(double y)
		{
			eY = y;
		}
		void setZ(double z)
		{
			eZ = z;
		}
		double getX() const
		{		
			return eX;
		}
		double getY() const
		{
			return eY;
		}
		double getZ() const
		{
			return eZ;
		}
};

E_Field::E_Field()
{
	eX = 0;
	eY = 0;
	eZ = 0;
}

E_Field::~E_Field();

int main()
{
	vector<E_Field*>efields;
	for(int i = 0; i < 3; i++)
		efields.push_back(new E_Field);
	efields[0]->setX(1);
	efields[0]->setY(1);
	efields[0]->setZ(1);

	efields[1]->setX(2);
	efields[1]->setY(2);
	efields[1]->setZ(2);

	efields[2]->setX(3);
	efields[2]->setY(3);
	efields[2]->setZ(3);

	for(int i = 0; i < (int)efields.size(); i++)
		cout << efields[i]->getX() << ", " << efields[i]->getY() << ", " << efields[i]->getZ() << "\n";
	for(int i = 0; i < (int)efields.size(); i++)
		delete efields[i];

	return 0;
}
