#include<iostream>
#include<cstdio>
#include<string>

using namespace std;

// Encrypting the plain text
void Encrypt(int key, string plaintext)
{
	char ciphertext;
	for (int i = 0; plaintext[i] != '\0'; i++)
	{
		if (plaintext[i] >= 'A' && plaintext[i] <= 'Z')
		{
			ciphertext = ((plaintext[i] - 'A') + key) % 26 + 'A';
			cout<< ciphertext; 
		}
		else if (plaintext[i] >= 'a' && plaintext[i] <= 'z')
		{
			ciphertext = ((plaintext[i] - 'a') + key) % 26 + 'a'; 
			cout<< ciphertext;
		}
		else
		{
			ciphertext = plaintext[i];
			cout<< ciphertext;
		}
	}
	cout<< endl;
}

// Decrypting the cipher text
void Decrypt(int key, string ciphertext)
{
	char plaintext;
	for (int i = 0; ciphertext[i] != '\0'; i++)
	{
		if (ciphertext[i] >= 'A' && ciphertext[i] <= 'Z')
		{
			plaintext = ((ciphertext[i] - 'Z') - key) % 26 + 'Z';
			cout<< plaintext; 
		}
		else if (ciphertext[i] >= 'a' && ciphertext[i] <= 'z')
		{
			plaintext = ((ciphertext[i] - 'z') - key) % 26 + 'z'; 
			cout<< plaintext;
		}
		else
		{
			plaintext = ciphertext[i];
			cout<< plaintext;
		}
	}
	cout<< endl;
}

int main()
{
	int k,x;
	string ptext, ctext;
	cout <<"Enter a Key : "; // Input the secret key
	cin>> k;

	if (k < 0)
	{
		cout <<"Enter a Positive Key." <<endl;
	}
	else
	{
		cout<< "1. Encrypt" <<endl;
		cout<< "2. Decrypt" <<endl;
		cout<< "Enter your choice : ";
		cin>> x;

		switch(x)
		{
			case 1:
				cin.ignore();
				cout<< "Plain Text : ";
				getline(cin, ptext);
				cout<< "Cipher Text : ";
				Encrypt(k, ptext);
				break;

			case 2:
				cin.ignore();
				cout<< "Cipher Text : ";
				getline(cin, ctext);
				cout<< "Plain Text : ";
				Decrypt(k, ctext);
				break;

			default:
				cout<< "Invalid Choice" <<endl;
				break;
		}	
	}
}