#include<iostream>
#include<iomanip> //For using setw(), setprecision(), ...
using namespace std;

int main(){	
	
	double loan,interestrate, payment;

	cout << "Enter initial loan: ";
	cin >> loan;
	cout << "Enter interest rate per year (%): ";
	cin >> interestrate;
	cout << "Enter amount you can pay per year: ";
	cin >> payment;

	//use 'setw' to set width of table and 'left' to set left-alignment
	//you can change input argument of 'setw()' to see the effect
	//Try to change from 'left' to 'right' and see the effect
	cout << setw(13) << left << "EndOfYear#"; 
	cout << setw(13) << left << "PrevBalance"; 
	cout << setw(13) << left << "Interest"; 
	cout << setw(13) << left << "Total";
	cout << setw(13) << left << "Payment";
	cout << setw(13) << left << "NewBalance";
	cout << "\n";

	int year = 1;
	double prevBalance = loan ;


	while (prevBalance){
		double interest = prevBalance*(interestrate/100);
		double total = prevBalance + interest ;
		double actualPayment;

		if (payment > total) {
    actualPayment = total;
	} else {
    actualPayment = payment;
	}

	double newBalance = total - actualPayment;
	
	
	//use 'fixed' and 'setprecision' to fix the number of decimal digits for displaying
	//you can change input argument of 'setprecision()' to see the effect
	cout << fixed << setprecision(2); 
	cout << setw(13) << left << year; 
	cout << setw(13) << left << prevBalance;
	cout << setw(13) << left << interest;
	cout << setw(13) << left << total ;
	cout << setw(13) << left << actualPayment;
	cout << setw(13) << left << newBalance;
	cout << "\n";	
	prevBalance = newBalance;
        year++;
		if (interest >= payment && prevBalance > 0) {
            cout << "--------------------------------------------\n";
            cout << "Warning: Payment is too low to cover interest!\n";
            break;
        }
}
	
	return 0;
}
