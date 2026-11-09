#include <iostream>
#include <cmath>
#include <vector>
using namespace std;

//Electric Field code!
class E_Field
{
	private:
		double *E;
		//double eX;//deprecated
		//double eY;//
		//double eZ;//
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
		double getX()
		{		
			return E[0];
		}
		double getY()
		{
			return E[1];
		}
		double getZ()
		{
			return E[2];
		}
		//data processing functions
		double getMag() //simple magnitude equation, using square root from cmath
		{
			return sqrt(E[0]*E[0] + E[1]*E[1] + E[2]*E[2]);
		}
		double getInnerp()
		{
			return E[0]*E[0] + E[1]*E[1] + E[2]*E[2];
		}
};

//Magnetic field code!
class M_Field
{
	private:
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
		double getX()
		{
			return M[0];
		}
		double getY()
		{
			return M[1];
		}
		double getZ()
		{
			return M[2];
		}
		//process functions
		double getMag()
		{
			return sqrt(M[0]*M[0] + M[1]*M[1] + M[2]*M[2]);
		}
		void uVector()
		{
			double mag = getMag();
			if(mag == 0.0)
			{
				cout << "Undefined vector." << "\n"; //error print.
				return; //void, so whatever. 
			}
			cout << "Magnetic Field unit vector: " << M[0]/mag << ", " << M[1]/mag << ", " << M[2]/mag << "\n";
		}
};

int main()
{
	//electric constructors
	E_Field E_default; //uses deault constructor for testing. 
	
	E_Field E_comp(1e5, 10.9, 1.7e2); //3-number constructor. taking COMPONENTS from assignment rubric. 
	
	E_default.setX(3.0); //test numbers. 
	E_default.setY(4.0);
	E_default.setZ(12.0);
	//mag constructors
	M_Field M_default; //as above

	M_Field M_comp(0.5, 1.2, 2.0);

	M_default.setX(1.0); //assignment didn't give values for magnetic field.
	M_default.setY(2.0);
	M_default.setZ(2.0);
	//cout chains
	cout << "|Electric Field TEST|: " << E_default.getMag() << "\n";
	cout << "|Electric Field magnitude|: " << E_comp.getMag() << "\n";
	cout << "|Mag Field magnitude|: " << M_comp.getMag() << "\n";
	cout << "Electric Field Inner product: " << E_comp.getInnerp() << "\n";
	//M_default.uVector(); --> Was for testing. 
	M_comp.uVector();

	return 0;
}
