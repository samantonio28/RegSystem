#include <iostream>
#include <fstream>
#include <string>
#include <vector>
//                   it's required to solve the "login = loGin" problem

using namespace std;

ofstream  putIn("logins.txt", ios_base::app);
ifstream getOut("logins.txt", ios_base::in);
vector<string> loginsNow(0);

void filling() {
	string log;
	int flag = 0;
	while (getOut >> log) {
		for (int i = 0; i < loginsNow.size(); i++) {
			if (log == loginsNow[i]) {
				flag = 1;
				break;
			}
		}
		if (flag == 0) {
			loginsNow.push_back(log);
		}
	}
}     

string isCorrect() {
	string login;
	cin >> login;
	int flag = 0;
	for (int i = 0; i < loginsNow.size(); i++) {
		if (login == loginsNow[i]) {
			flag = 1;
		}
	}
	if (flag == 1) {
		cout << "Try again\n";
		login = isCorrect();
	}
	else {
		putIn << login << "\n";
		filling();   
		return login;
	}
}

void SignUp() {
	cout << "Okay, you need to create your login and password\n";
	cout << "Please, type your login\n";
	string login = isCorrect();
	
	string filename;
	
	filename.push_back('d');
	filename.push_back('a');
	filename.push_back('t');
	filename.push_back('a');
	filename.push_back('/');
	for (int i = 0; i < login.size(); i++) {
		filename.push_back(login[i]);
	}
	filename.push_back('.');
	filename.push_back('t');
	filename.push_back('x');
	filename.push_back('t');
	cout << "Please, type your password\n";
	string password;
	cin >> password;
	ofstream fout(filename, ios_base::app);  // will be written at the end of file
	fout << "Your login is " << login << "\n";
	fout << "Your password is " << password << "\n";
}

void LogIn() {
	cout << "\nfunc LogIn\n";
}

int main() {
	filling();
	cout << "=============== SYSTEM OF REGISTRATION ===============\n";
	cout << "(please, write 'sign up' or 'log in') (thank you) :)\n";
	string one, two;
	cin >> one >> two;
	for (int i = 0; i < one.size(); i++) {
		if (isalpha(one[i])) {
			one[i] = toupper(one[i]);
		}
		else {
			return 1;
		}	
	}
	for (int i = 0; i < two.size(); i++) {
		if (isalpha(two[i])) {
			two[i] = toupper(two[i]);
		}
		else {
			return 1;
		}	
	}
	if ((one == "SIGN") and (two == "UP")) {
		SignUp();
	}
	else if ((one == "LOG") and (two == "IN")) {
		LogIn();
	}
	else {
		return 1;
	}
	return 0;
}