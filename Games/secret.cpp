// Guess My Number
// The classic number guessing game
#include <iostream>
#include <cstdlib>
#include <ctime>
using namespace std;

int main()
{
	srand(static_cast<unsigned int>(time(0))); //seed random number generator
	int nmax=100, nmin=1;
	int guess; //= rand() % nmax + nmin; // random number between nmin and nmax
	int tries = 0;
	int secret;
	cout << "\tWelcome to PC Guess My Number\n\n";
	cout<<"Enter the secret number:";
	cin>>secret;
	do
	{
		//cout << "Enter a secret number: ";
		//cin >> secret;
		cout<<"Guess=";
		guess=rand()%nmax+nmin;
		while(guess>nmax || guess<=nmin)
		{
			guess=rand()%nmax;
		}
		cout<<guess<<endl;
		++tries;
		if (guess > secret)
		{
			cout << "Too high!\n\n";
			nmax=guess;
		}
		else if (guess < secret)
		{	
			cout << "Too low!\n\n";
			nmin=guess;
		}
		else
		{
			cout << "\nThat’s it! You got it in " << tries << " guesses!\n";
		}
	} while (guess != secret);
	return 0;
}
