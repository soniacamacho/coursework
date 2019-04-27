#include <iostream>
#include <string>
#include <cmath>

using namespace std;

int main() {
	float current_offer = 0;
    float future_offer = 0;
    float ir = 0;
    float m = 1;
    float n = 0; 
    float res; 
    float val;
    float decimal;
	string input = "";
	int i;
    int count;
	bool flag;
	cout << "It looks like you have two offers. Let's calculate which one is worth more." << endl;
	do{
		cout << "Please provide the current offer amount: ";
		getline(cin, input);
		flag = false;
		int count = 0;
		for(int i=0; i<input.length(); i++){
			if (input[i] < '0' || input[i] > '9') {
				if (input[i] == '.') {
					count++;
					if (count > 1) {
						flag = true;	
					}	
				}
				else {
					flag = true;
				}	
			} 	
		}
	}
     while (flag){
	
	for(i = 0; i < input.length(); i++) {
		if (input[i] == '.')
			break;	
	}
	res = 0;
	val = 0;
	for(int j = i-1; j >= 0; j--) {
		val = ((int) input[j]) -48;
		res += val * pow(10, (i - 1 - j));
	}
	decimal = 0;
	count = 1;
	for(int k = i+1; k < input.length(); k++) {
		val = ((int) input[k]) - 48;
		decimal += val * pow(10, (-count));
		count++;
	}
	
	current_offer = res + decimal;
	
	do{
		cout << "Please provide the future offer amount: ";
		getline(cin, input);
		flag = false;
		int count = 0;
		for(int i=0; i<input.length(); i++){
			if (input[i] < '0' || input[i] > '9') {
				if (input[i] == '.') {
					count++;
					if (count > 1) {
						flag = true;	
					}	
				}
				else {
					flag = true;
				}	
			} 	
		}
	} while (flag);
	
	for(i = 0; i < input.length(); i++) {
		if (input[i] == '.')
			break;	
	}
	res = 0;
	val = 0;
	for(int j = i-1; j >= 0; j--) {
		val = ((int) input[j]) -48;
		res += val * pow(10, (i - 1 - j));
	}
	
	decimal = 0;
	count = 1;
	for(int k = i+1; k < input.length(); k++) {
		val = ((int) input[k]) - 48;
		decimal += val * pow(10, (-count));
		count++;
	}
	
	future_offer = res + decimal;
	
	do{
		cout << "Please provide the interest rate: ";
		getline(cin, input);
		flag = false;
		int count = 0;
		for(int i=0; i<input.length(); i++){
			if (input[i] < '0' || input[i] > '9') {
				if (input[i] == '.') {
					count++;
					if (count > 1) {
						flag = true;	
					}	
				}
				else {
					flag = true;
				}	
			} 	
		}
	} while (flag);
	
	for(i = 0; i < input.length(); i++) {
		if (input[i] == '.')
			break;	
	}
	res = 0;
	val = 0;
	for(int j = i-1; j >= 0; j--) {
		val = ((int) input[j]) -48;
		res += val * pow(10, (i - 1 - j));
	}
	
	decimal = 0;
	count = 1;
	for(int k = i+1; k < input.length(); k++) {
		val = ((int) input[k]) - 48;
		decimal += val * pow(10, (-count));
		count++;
	}
	
	ir = res + decimal;
	cout << "Please provide the amount of time in years between the current offer and future offer: ";
	cin >> n;
	
	do{
		cout << "Please provide the amount of time in years between the current offer and future offer: ";
		getline(cin, input);
		flag = false;
		int count = 0;
		for(int i=0; i<input.length(); i++){
			if (input[i] < '0' || input[i] > '9') {
				flag = true;	
			}
		}
	} while (flag);
	
	for(int i = (input.length()-1); i >= 0; i--) {
		val = ((int) input[i]) - 48;
		res +=  val * pow(10,(input.length() - i -1));
	}
	n = res;

	float val_current_offer = current_offer*(pow((1+(ir/m)),(n*m)));	
	float val_future_offer = future_offer/(pow((1+(ir/m)), (n*m))); 
	
	if (val_current_offer > val_future_offer) {
		cout << "Take the current offer" << endl;	
	}
	else if (val_current_offer < val_future_offer) {
		cout << "Take the future offer" << endl;	
	}	
	else {
		cout << "Choose which ever" << endl;	
	}
	

	return 0;	
}
