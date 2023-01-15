
#include <bits/stdc++.h>
using namespace std;

bool isPalindrome(int num){
	int rev = 0, temp = num;
	while(temp != 0){
		rev = rev*10 + (temp%10);
		temp = temp/10;
	}
	return num == rev;
}

double SquareRoot(int num){
	double lo = 0, hi = num, eps = 1e-7;
	while(hi-lo > eps){
		double mid = (hi+lo)/2;
		if(mid * mid < num)
			lo = mid; 
		else
			hi = mid;
	}

	return lo;
}

void PrimeFactorisation(int n){
	vector<int> prime_factors;
	for(int i = 2; i*i <= n; i++){
		while(n % i == 0){
			prime_factors.push_back(i);
			n = n/i;
		}
	}
	if(n > 1)
		prime_factors.push_back(n);
	for(int i = 0; i < prime_factors.size(); i++)
		cout << prime_factors[i] << " ";
}

void Divisors(int n){
	for(int i = 1; i*i <= n; i++){
		if(n%i == 0){
			if(i*i != n)
				cout << "\n" << i << " " << n/i ;
			else
				cout << i << endl;
		}
	}
}

int gcd(int a, int b){
	if(b == 0) return a;
	return gcd(b,a%b);
}

int main(){
	ios::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);

	cout << "\n\nPLEASE ENTER A NUMBER(N) : ";

	int n;
	cin >> n;

	vector<bool> isPrime(n+1,true);

	isPrime[0] = isPrime[1] = false;
	for(int i = 2; i*i <= n; i++){
		if(isPrime[i]){
			for(int j = i*i; j <= n; j += i)
				isPrime[j] = false;
		}
	}

while(true){

	cout << "\nENTER THE OPTION YOU WISH TO KNOW ABOUT " << n << " : \n"; 
	cout << "1.Is " << n << " a prime number?\n";
	cout << "2.Is " << n << " a palindrome?\n";
	cout << "3.Square root of " << n << "?\n";
	cout << "4.List of prime numbers till " << n << ".\n";
	cout << "5.Prime factors of " << n << ".\n";
	cout << "6.Divisors of " << n << ".\n";
	cout << "7.What is the GCD of " << n << " and another given number?\n";
	cout << "8.What is the LCM of " << n << " and another given number?\n";
	cout << "9.Exit\n\n";

	int select;
	cin >> select;

	

	while(select > 9){
		cout << "\n\nPLEASE ENTER A VALID OPTION\n";
		cin >> select;
	}


	switch(select){
		case 1:
			if(isPrime[n])
				cout << "Yes, " << n << " is a prime number.";
			else
				cout << "No, " << n << " is not a prime number.";
			break;
		case 2 :
			if(isPalindrome(n))
				cout << "Yes, " << n << " is a palindrome.";
			else
				cout << "No, " << n << " is not a palindrome.";
			break;
		case 3:
			cout << "Square root of " << n << " is " << SquareRoot(n) << ".";
			break;
		case 4:
			cout << "Prime numbers till " << n << " are ";
			for(int i = 0; i <= n; i++){
				if(isPrime[i])
					cout << i << " ";
			}
			cout << ".";
			break;
		case 5:
			cout << "Prime factors of " << n << " are : ";
			PrimeFactorisation(n);
			cout << ".";
			break;
		case 6:
			cout << "Divisors of " << n << " are : ";
			Divisors(n);
			cout << ".";
			break;
		case 7:
			cout << "Please input the other number : ";
			int n2;
			cin >> n2;
			cout << "\nThe GCD of " << n << " and " << n2 << " is " << gcd(n,n2);
			break;
		case 8:
			cout << "Please input the other number : ";
			int n3;
			cin >> n3;
			cout << "\nThe LCM of " << n << " and " << n3 << " is " << (n*n3)/gcd(n,n3);
			break;
	}

	if(select == 9) break;

	cout << "\n\nWISH TO KNOW SOMETHING ELSE ABOUT "<< n << " ?\n";
	cout << "1.Yes\n2.No\n\n";

	int ans;
	cin >> ans;

	if(ans == 2)
		break;

}

	cout << "\n\nWANT TO TRY IT WITH ANOTHER NUMBER?\n";
	cout << "1.Yes\n2.No\n\n";
	int ans;
	cin >> ans;
	if(ans == 1){
		return main();
	}
	else
		cout << "\n\nTHANKYOU!!\n\n";

	return 0;
}
