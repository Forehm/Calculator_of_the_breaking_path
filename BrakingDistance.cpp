#include <iostream>
#include <string>
#include <map>
#include <conio.h>
using namespace std;



class Parameters
{
public:
	double Speed;
	double Kt = 1;
	pair<double, string> Kc;
	double BrPath;



	Parameters()
	{
		Speed = 0;
		Kt = 1;
		Kc.first = 0.75;
		Kc.second = "Asphalt";
		BrPath = 0;
	}


	void UpdateParameters()
	{
		cout << endl << endl;
		cout << "Change Speed - 1" << endl;
		cout << "Change the road surface - 2" << endl;
		
		int a;
		cin >> a;
		switch (a)
		{
		case 1:
		{
			cout << "Print the new speed" << endl;
			cin >> Speed;
			break;
		}
		case 2:
		{
			cout << "Change the new road surface:" << endl;
			int b;
			cout << endl << endl;
			cout << "1) Asphalt" << endl;
			cout << "2) Gravel" << endl;
			cout << "3) Cablestone" << endl;
			cout << "4) Sand" << endl;
			cout << "5) Snow" << endl;
			cout << "6) Ice" << endl;
			cin >> b;
			switch (b)
			{
			case 1:
			{
				this->Kc.first = 0.75;
				this->Kc.second = "Asphalt";
				break;
			}
			case 2:
			{
				Kc.first = 0.65;
				Kc.second = "Gravel";
				break;
			}
			case 3:
			{
				Kc.first = 0.55;
				Kc.second = "Cablestone";
				break;
			}
			case 4:
			{
				Kc.first = 0.55;
				Kc.second = "Sand";
				break;
			}
			case 5:
			{
				Kc.first = 0.25;
				Kc.second = "Snow";
				break;
			}
			case 6:
			{
				Kc.first = 0.09;
				Kc.second = "Ice";
				break;
			}
			}
		}
		}
	}

	void ShowParameters()
	{
		system("cls");
		cout << "Speed:\t" << Speed << endl;
		cout << "Type of surface:\t" << Kc.second << endl;
		cout << "Breaking path:\t" << BrPath << " meters" << endl;
		
	}

	void Calculate()
	{
		BrPath = (Kt * (Speed * Speed)) / (254 * Kc.first);
	}

};


int main()
{
	Parameters a;
	while (true)
	{



		a.ShowParameters();

		int code = _getch();
		
		switch (code)
		{
		case 32:
		{
			a.UpdateParameters();
		}
		case 13:
		{
			a.Calculate();
		}
		}



	}
	return 0;
}
