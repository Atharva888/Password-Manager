#include<bits/stdc++.h>
#include<stdio.h>
using namespace std;

double p,q,n,e,phi,d;
int k;

int gcd(int a, int b) {
	if(b == 0)
		return a;
	return gcd(b , a%b);

}

string Encrypt_message(string message){
	string encrypted_message;
  	for(char p : message){
    // Encryption c = (msg ^ e) % n 
    char c = pow(p, e); 
    c = fmod(c, n); 
    encrypted_message += c;; 
	}
    return encrypted_message;
}
string Decrypt_message(string message){
	string decrypted_message;
	for(auto c : message){
    // Decryption m = (c ^ d) % n 
    double m = pow(c, d); 
    m = fmod(m, n); 
    decrypted_message += m;
	}
	return decrypted_message;

}
void create_pair(){
	p = 7; 
    q = 11; 
  
    n = p*q; 
  
    e = 2; 
    phi = (p-1)*(q-1); 
    while (e < phi) { 
        if (gcd(e, phi)==1) break; 
        else e++; 
    } 
  
    // choosing d such that it satisfies d*e = 1 + k * totient 
    k = 2;  // A constant value 
    d = (1 + (k*phi))/e; 
  
}
int main() { 
	create_pair();
    string message;
	cin>>message;
	cout<<Encrypt_message(message)<<endl<<Decrypt_message(Encrypt_message(message));
	
	
    return 0; 
}
