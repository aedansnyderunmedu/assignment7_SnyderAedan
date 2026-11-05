#include <iostream>
#include <cmath>
#include <vector>
using namespace std;

//Electric Field code!
class E_Field
{
	protected:
		double E*;
		double eX;//deprecated
		double eY;//
		double eZ;//
	public:
		E_Field()
		{
			E = new double[3];

			E[0] = 0.0; //new x, y, and z inside each array
			E[1] = 0.0;
			E[2] = 0.0;
		}
		
		E_Field(double x, double y, double z) //store x/y/z
		{
			E = new double[3];

			E[0] = x;
			E[1] = y;
			E[2] = z;
		}

		~E_Field() //decon
		{
			delete[] E; //new uses [], delete does too. 
		}
		//setters and getters
		void setX(double x)
		{
			E[0] = x;
		}
		void setY(double y)
		{
			E[1] = y;
		}
		void setZ(double z)
		{
			E[2] = z;
		}
		double getX() const
		{		
			return E[0];
		}
		double getY() const
		{
			return E[1];
		}
		double getZ() const
		{
			return E[2];
		}
		//data processing functions
		double getMag() //simple magnitude equation, using square root from cmath
		{
			return sqrt(E[0] * E[0] + E[1] * E[1] + E[2] * E[2]);
		}
		double getInnerp()
		{
			return E[0] * E[0] + E[1] * E[1] + E[2] * E[2];
		}
};

//Magnetic field code!
class M_Field
{
	protected:
		double *M;
	public:
		M_Field()
		{
			M = new double[3]; //same logic as E_Field

			M[0] = 0.0;
			M[1] = 0.0;
			M[2] = 0.0;
		}

		M_Field(double x, double y, double z)
		{
			M = new double[3];

			M[0] = x;
			M[1] = y;
			M[2] = z;
		}

		~M_Field() //deconstructor, same as above
		{
			delete[] M;
		}
		//setters and getters
		void setX(double x)
		{
			M[0] = x;
		}
		void setY(double y)
		{
			M[1] = y;
		}
		void setZ(double z)
		{
			M[2] = z;
		}
		double getX() const
		{
			return M[0];
		}
		double getY() const
		{
			return M[1];
		}
		double getZ() const
		{
			return M[2];
		}
		//process functions
		double getMag()
		{
			return sqrt(M[0] * M[0] + M[1] * M[1] + M[2] * M[2]);
		}
		void uVector()
		{
			double mag = getMag();
			if(mag == 0)
			{
				cout << "Undefined vector." << "\n";
				return; //void, so whatever. 
			}
			cout << "M unit vector: " << B[0]/mag << ", " << B[1]/mag << ", " << B[2]/mag << "\n";
		}
};

int main()
{
	//electric constructors
	E_Field E_default; //uses deault constructor
	
	E_Field E_comp(1e5, 10.9, 1.7e2); //3-number constructor
	
	E_default.setX(3.0);
	E_default.setY(4.0);
	E_default.setZ(12.0);
	//mag constructors
	M_Field M_default;

	M_Field M_comp(0.5, 1.2, 2.0);

	E_default.setX(1.0);
	E_default.setY(2.0);
	E_default.setZ(2.0);
	//cout chains
	
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
