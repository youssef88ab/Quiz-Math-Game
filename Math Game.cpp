#include <iostream>
#include <string>
#include <math.h>

using namespace std;


enum enLevel	 { EASY = 1, MEDIEUM = 2, HARD = 3 };

enum enOperation { ADD = 1, SUB = 2, MUL = 3, DIV = 4  };

int         Random_Number(int From, int To)
{
	return (rand() % (To - From + 1) + From);
}

// Save Result  & Print;

void        SaveResult_and_screen(bool Tab[10] , int index , bool Result )
{

	Tab[index] = Result;

	if (Result == true)
	{
		system("COLOR 2");
	}
	if (Result == false)
	{
		system("COLOR 4");
	}
}

void        Print_Results(bool Tab[10], int Rounds)
{
	int Win = 0;
	int Lose = 0;
	
	for (int i = 0; i < Rounds; i++)
	{
		if (Tab[i] == true) Win++;
		if (Tab[i] == false) Lose++;
	}

	system("COLOR 6");

	cout << "----------------------------------------------------------------------------" << endl;
	cout << "                                 GAME OVER                                  " << endl;
	cout << endl;
	cout << "                           YOU ANSEWRED " << Rounds << " QUESTIONS                 " << endl;
	cout << "\n                               YOU WIN " << Win << " TIMES                     " << endl;
	cout << "\n                               YOU LOSE " << Lose << " TIMES                    " << endl;

	cout << "----------------------------------------------------------------------------";
}

// Read INPUT ;

void        Read_Question(short &Question)
{	
	Question = 0;
	do
	{

		cout << "HOW MANY QUESTION YOU WANT : ";
		cin >> Question;

	} while (Question < 0);
}

enLevel	    Read_Level()    
{

	short  Level;

	cout << "-----------------------------------\n";

	do
	{

		cout << "ENTER LEVEL YOU WANT ; \n 1 : EASY \n 2 : MEDIUM \n 3 : HARD  \n----------------------------------\n CHOSE ONE : ";
		cin >> Level;

	} while (Level > 3);
	
	cout << "-----------------------------------\n";

	return (enLevel)Level;

}

enOperation Read_Operation()
{

	short  Operation;

	cout << "-----------------------------------\n";

	do
	{

		cout << "ENTER OPERATION YOU WANT ; \n 1 : ADD \n 2 : SUB \n 3 : MUL  \n 4 : DIV \n---------------------------------- \n CHOSE ONE : ";
		cin >> Operation;

	} while (Operation > 4);

	cout << "-----------------------------------\n";

	return (enOperation)Operation;

} 

// QUESTIONS BY TYPES;

bool Add_Question(enLevel Level)
{
	int A = 0, B = 0 , Result;

	// POSSIBLTIES ;

	if (Level == EASY)
	{
		A = Random_Number(1, 10);
		B = Random_Number(1, 10);
	}

	if (Level == MEDIEUM)
	{
		A = Random_Number(-100, 100);
		B = Random_Number(-100, 100);
	}

	if (Level == HARD)
	{
		A = Random_Number(-1000, 1000);
		B = Random_Number(-1000, 1000);
	}

	cout << A << " + " << B << " = ";
	cin  >> Result;

	if (Result == A + B) return true;
	else				 return false;


}

bool Sub_Question(enLevel Level)
{
	int A = 0 , B = 0, Result;

	// POSSIBLTIES ;

	if (Level == EASY)
	{
		A = Random_Number(1, 10);
		B = Random_Number(1, 10);
	}

	if (Level == MEDIEUM)
	{
		A = Random_Number(-100, 100);
		B = Random_Number(-100, 100);
	}

	if (Level == HARD)
	{
		A = Random_Number(-1000, 1000);
		B = Random_Number(-1000, 1000);
	}


	cout << A << " - " << B << " = ";
	cin >> Result;

	if (Result == A - B) return true;
	else				 return false;


}

bool Mul_Question(enLevel Level)
{
	int A = 0 , B = 0, Result;

	// POSSIBLTIES ;

	if (Level == EASY)
	{
		A = Random_Number(1, 10);
		B = Random_Number(1, 10);
	}

	if (Level == MEDIEUM)
	{
		A = Random_Number(-100, 100);
		B = Random_Number(-100, 100);
	}

	if (Level == HARD)
	{
		A = Random_Number(-1000, 1000);
		B = Random_Number(-1000, 1000);
	}

	cout << A << " * " << B << " = ";
	cin >> Result;

	if (Result == A * B) return true;
	else				 return false;


}

bool Div_Question(enLevel Level)
{
	int A = 0, B = 0, Result;

	// POSSIBLTIES ;

	if (Level == EASY)
	{
		A = Random_Number(1, 10);
		B = Random_Number(1, 10);
	}

	if (Level == MEDIEUM)
	{
		A = Random_Number(-100, 100);
		B = Random_Number(-100, 100);
	}

	if (Level == HARD)
	{
		A = Random_Number(-1000, 1000);
		B = Random_Number(-1000, 1000);
	}


	cout << A << " / " << B << " = ";
	cin >> Result;

	if (Result == A / B) return true;
	else				 return false;


}

void Questions(int Rounds , enLevel Level  , enOperation Operation)
{
	int Counter = 0 ;
	bool Tab[10];
	do
	{
		switch (Operation)
		{

		case enOperation::ADD :
		{
			cout << "Question [" << Counter + 1 << "] | ";
			SaveResult_and_screen(Tab,Counter,Add_Question(Level));
			Counter++;
		}
		break;

		case enOperation::SUB :
		{
			cout << "Question [" << Counter + 1 << "] | ";
			SaveResult_and_screen(Tab, Counter, Sub_Question(Level));
			Counter++;
		}
		break;

		case enOperation::MUL :
		{
			cout << "Question [" << Counter + 1 << "] | ";
			SaveResult_and_screen(Tab, Counter, Mul_Question(Level));
			Counter++;
		}
		break;

		case enOperation::DIV :
		{
			cout << "Question [" << Counter + 1 << "] |";
			SaveResult_and_screen(Tab, Counter, Div_Question(Level));
			Counter++;
		}
		break;

		
		}
	} while (Counter < Rounds);

	Print_Results(Tab,Rounds);
}


void Start_Game()
{
	short Rounds ;
	enLevel Level;
	enOperation Operation;

	cout << "----------------- WELCOME TO MATH GAME --------------------" << endl;
	cout << endl;
	cout << endl;

	// Reading Questions ;

	Read_Question(Rounds);
	Level = Read_Level();
	Operation = Read_Operation();

	// Answer Question And Check ;

	Questions(Rounds , Level , Operation);

}

int main()
{
	srand((unsigned)time(NULL));

	Start_Game();

	return 0;
}