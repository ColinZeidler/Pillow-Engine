#include <iostream> //gives us cout and cin
#include <Windows.h>
#include <time.h>	// give us clock and clock_t 

using namespace std;

void main() {
	double timeStep = 20;
	cout << "Preparing to test delta function" <<endl;

	getchar();

	while(true) {
		clock_t t = clock();
		Sleep(100);	//this would be replaced with actual rendering
		t = clock() -t;
		cout << "the delta for render was: " << t<< endl;
		cout << "time step " << timeStep<<endl;
		cout << "Performing " << t / timeStep << " ops" << endl;

		Sleep(1000);

	}
}