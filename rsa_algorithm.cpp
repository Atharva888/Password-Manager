#include<bits/stdc++.h>
#include <iostream>
#include <stdlib.h>
using namespace std;

long int p, q, n, t, temp[100], j;
long int decryptedText[100], encryptedText[100], i, len;
bool flag;
string msg;

void enerypt(long int);
void decrypt(long int);
long int gcalculateD(long int a, long int b);
bool isPrime(long int);
long int calculateE();
long int calculateD(long int);

bool isPrime(long int pr)
{
    int i;
    j = (long int)sqrt((long double)pr);
    for (int i = 2; i <= j; i++)
    {
        if (pr % i == 0)
            return false;
    }
    return true;
}

long int calculateE()
{
    for (i = 2; i < t; i++)
    {
        if (gcalculateD(i, t) == 1)
            return i;
    }
    return -1;
}

long int calculateD(long int x)
{
    long long k = 1;
    while (1)
    {
        k = k + t;
        if (k % x == 0)
            return (k / x);
    }
}

long int gcalculateD(long int a, long int b)
{
    return (b == 0) ? a : gcalculateD(b,a%b);
}

void encrypt(long long e)
{
    long long pt, ct, key = e, k;
    i = 0;
    len = msg.size();
    while (i != len)
    {
        pt = decryptedText[i];
        pt = pt - 97;
        k = 1;
        for (j = 0; j < key; j++)
        {
            k = k * pt;
            k = k % n;
        }
        temp[i] = k;
        ct = k + 97;
        encryptedText[i] = ct;
        i++;
    }
    encryptedText[i] = -1;
    cout << "\nTHE ENCRYPTED MESSAGE IS \n";
    for (i = 0; i < len; i++)
    {
        printf("%c", encryptedText[i]);
    }
}

void decrypt(long int d)
{
    long int pt, ct, key = d, k;
    i = 0;
    while (encryptedText[i] != -1)
    {
        ct = temp[i];
        k = 1;
        for (j = 0; j < key; j++)
        {
            k = k * ct;
            k = k % n;
        }
        pt = k + 97;
        decryptedText[i] = pt;
        i++;
    }
    decryptedText[i] = -1;
    cout << "\nTHE DECRYPTED MESSAGE IS \n";
    for (i = 0; i < len; i++)
    {
        printf("%c", decryptedText[i]);
    }
    printf("\n");
}

int main()
{

    cout << "Welcome To our RSA progrom" << endl;

    do
    {
        cout << "Enter a Prime number P :" << endl;
        cin >> p;
        flag = isPrime(p);

        if (flag == false)
        {
            cout << "\nWRONG INPUT\n";
        }
    } while (flag == 0);

    do
    {
        cout << "Enter a Prime number Q :" << endl;
        cin >> q;
        flag = isPrime(q);

        if (flag == false)
        {
            cout << "\nWRONG INPUT\n";
        }
    } while (flag == 0);

    cout << "\nEnter message to be Encrypted : \n";
    fflush(stdin);

    getline(cin, msg);
    for (int i = 0; msg[i] != '\0'; i++)
    {
        decryptedText[i] = msg[i];
    }

    n = p * q;
    t = (p - 1) * (q - 1);
    long int e = calculateE();
    long int d = calculateD(e);

    encrypt(e);
    decrypt(d);

    system("PAUSE");

    return 0;
}
