#include <iostream>
using namespace std;

int recurrency_1(int);
int recurrency_2(int);
int y = 1;
int j = 1;
int main() {
	int a;
	cin >> a;
	cout << endl << endl << recurrency_1(a);
	cout << " - T(" << y << ")" << endl;
	cout << recurrency_2(a);
	cout << " - T(" << j << ")" << endl;
	
	
	return 0;
}

int recurrency_1(int x){	
	y++;
	if(x>=2){
		return(recurrency_1(x/2)+x);
	} else {
		return 1;
	}
}
int recurrency_2(int x){	
		j++;
		if(x>=1){
			return((2*recurrency_2(x-1))+x);
		} else {
			return 0;
		}
}
