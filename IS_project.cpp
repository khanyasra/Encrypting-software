#include <iostream>
#include <fstream>
#include <bitset>
#include <string>
#include <cstdlib>
#include <cmath>
#include <array>
//#include<windows.h>

using namespace std;

//checking if the number is prime or not/

int primenum() {
    long int a;
    int isprime = 0;
    while (isprime == 0) {
        a = rand() % 10000;
        if (a == 0 || a == 1) {
            isprime = 0;
            continue;
        } else {
            isprime = 1;
            for (int i = 2; i <= a / 2; i++) {
                if (a % i == 0) {
                    isprime = 0;
                    break;
                }
            }
        }
    }
    return a;
}

// Original Set of letters
string plaintext = "ABCDEFGHIJKLMNOPQRSTUVWXYZ";

class encryption {
private:
    int key;
    string keyword;
    string msg;
    double p = primenum();
    double q = primenum();
    double c[1000]{};
    double m[1000]{};
    double emsg[1000]{};

public:
    //SETTING PRIVATE VARIABLES
    void keysetter(int x) { key = x % 26; }
    int keygetter() { return key; }
    void keywordsetter(string p) { keyword = p; }
    string keywordgetter() { return keyword; }
    void msgsetter(string m) { msg = m; }
    string msggetter() { return msg; }
    double p_getter() { return p; }
    double q_getter() { return q; }

    //DONE SETTING PRIVATE VARIABLES
    int asciicode(double arr[], string message) {
        int i = 0;
        for (char c : message) {
            int decimalValue = static_cast<int>(c);
            *(arr + i) = decimalValue;
            i++;
        }
        return i;
    }

    // find gcd
    int gcd(int a, int b) {
        int t;
        while (1) {
            t = a % b;
            if (t == 0) {
                return b;
            }
            a = b;
            b = t;
        }
    }

    //FUNCTIONS TO BE IMPLEMENTED
    /* 1 */
    // For Encryption
    string caesar_cipher_en(string message) {
        int key;
        cout << "\n\t\tEnter key: ";
        cin >> key; //take the key as input
        keysetter(key);
        char ch;
        for (int i = 0; i < message.length(); ++i) {
            ch = message[i];
				//lower case encrypt
				if (ch >= 'a' && ch <= 'z') {
				    ch = ((ch - 'a' + key) % 26) + 'a';
				    message[i] = ch;
				} 
				//upercase encrypt
				else if (ch >= 'A' && ch <= 'Z') {
				    ch = ((ch - 'A' + key) % 26) + 'A';
				    message[i] = ch;
				}
        }

        cout << "\n\t\tEncrypted message: " << message << endl << endl;
        return message;
    }

    // For Decryption
    string caesar_cipher_den(string message) {
        char ch;
        int key = keygetter();
        
        for (int i = 0; i < message.length(); ++i) {
            ch = message[i];
           message[i] = ch;
			//lower case decrypt
			if (ch >= 'a' && ch <= 'z') {
			    ch = ((ch - 'a' - key + 26) % 26) + 'a';
			    message[i] = ch;
			} 
			//upper case decrypt
			else if (ch >= 'A' && ch <= 'Z') {
			    ch = ((ch - 'A' - key + 26) % 26) + 'A';
			    message[i] = ch;
			}
        }
        cout << "\n\t\tDecrypted message: " << message << endl << endl;
        return message;
    }

    /* 2 */
    string keyword_picker(string keyword) {
        //to convert keyword into uppercase
        for (int i = 0; i < keyword.length(); i++) {
            keyword[i] = toupper(keyword[i]);
        }
        //generating alphabet with keyword
        string temp = "";
        for (int i = 0; i < keyword.length(); i++) {
            temp += keyword[i];
        }
        for (int i = 0; i < 26; i++) {
            temp += static_cast<char>(i + 65);
        }
        //removing letters of keyword from alphabets
        keyword = ""; // Clear the previous value of 'keyword'
        for (int i = 0; i < temp.length(); i++) {
            bool found = false;
            for (int j = 0; j < keyword.length(); j++) {
                if (temp[i] == keyword[j]) {
                    found = true;
                    break;
                }
            }
            if (found == false) {
                keyword += temp[i];
            }
        }
        //cout<<keyword;
        return keyword;
    }

    //for encrypting the message
    string keyword_cipher_en(string keyword, string message, string plaintext) {
        string ph = keyword_picker(keyword);
        //message to uppercase
        for (int i = 0; i < message.length(); i++) {
            message[i] = toupper(message[i]);
        }
        string encrypttext = "";
        for (int i = 0; i < message.length(); i++) {
            if (message[i] == ' ') {
                encrypttext += " ";
            } else {
                int counter = 0;
                for (int j = 0; j < plaintext.length(); j++) {
                    if (message[i] == plaintext[j]) {
                        encrypttext += ph[counter];
                        break;
                    } else {
                        counter++;
                    }
                }
            }
        }
        cout << "\n\t\tEncrypted Text: " << encrypttext << endl << endl;
        return encrypttext;
    }

    //for decrypting message
    string keyword_cipher_den(string keyword, string message, string plaintext) {
        string ph = keyword_picker(keyword);
        //message to uppercase
        for (int i = 0; i < message.length(); i++) {
            message[i] = toupper(message[i]);
        }
        string decrypttext = "";
        for (int i = 0; i < message.length(); i++) {
            if (message[i] == ' ') {
                decrypttext += " ";
            } else {
                int counter = 0;
                for (int j = 0; j < ph.length(); j++) {
                    if (message[i] == ph[j]) {
                        decrypttext += plaintext[counter];
                        break;
                    } else {
                        counter++;
                    }
                }
            }
        }
        cout << "\n\t\tDecrypted Text: " << decrypttext << endl << endl;
        return decrypttext;
    }

    /* 3 */
    string RSA_en(double array[], double e, int length) {
        double n = p * q;
        string en_msg;
        for (int i = 0; i < length; i++) {
            c[i] = static_cast<double>(std::pow(array[i], e)); // encrypt the message
            emsg[i] = fmod(c[i], n);
            en_msg += to_string(static_cast<int>(emsg[i]));
        }
        return en_msg;
    }

    string RSA_den(double d, int length) {
        double n = p * q;
        string den_msg;
        for (int i = 0; i < length; i++) {
            m[i] = std::pow(c[i], d);
            char ascii_to_char = static_cast<char>(m[i] + 1);
            den_msg += ascii_to_char;
        }
        return den_msg;
    }
};

// Main Function
int main() {
    char choice;
   do {
		cout <<"\t\t\t\t\t\t\tTEXTCRYPT\n\n";
		cout << "\n\t\tDo you want to perform  Text  Encryption\n\t\t1. Yes(Y)\n\t\t2. No(N)\n\t\t3.Quit(Q)\n\t\tChoice: ";
	
		cin >> choice;
	
		if (choice == 'y' || choice == 'Y') {
			cout << "\n\t\tWhat type of Encryption you want to perform\n\t\t1. Ceaser Cipher(C)\n\t\t2. Keyword cipher(K)\n\t\t3. RSA(R)\n\t\tChoice: ";
	
			cin >> choice;

			if (choice == 'C' || choice == 'c') {
				encryption c1;
				string n;
			
				cout << "\n\t\tEnter a msg: ";
			
				cin.ignore();
				getline(cin, n);
				n = c1.caesar_cipher_en(n);
			
				cout << "\t\tDo you want to Decrypt the msg(Y/N): ";
			
				cin >> choice;
				if (choice == 'Y' || choice == 'y') {
					c1.caesar_cipher_den(n);
				}
		
				cout << "\n\n\t\tDO you want to continue[Y/N]: ";
			
				cin >>choice;
			
				if (choice == 'N' || choice == 'n') {
					cout << "\n\t\tQuitting..." << endl;
					choice='Q';
				}
				system("cls");
			}
			else if (choice == 'K' || choice == 'k') {
				encryption p1;
				string msg;
				string ph;
				cout << "\n\t\tEnter a msg: ";
				
				cin.ignore();
				getline(cin, msg);
			
				cout << "\n\t\tEnter The keyword and make sure no letter repeats itself: ";
				
				getline(cin, ph);
				msg = p1.keyword_cipher_en(ph, msg, plaintext);
				
				cout << "\n\t\tDo you want to Decrypt the msg(Y/N): ";
			
				cin >> choice;
				if (choice == 'Y' || choice == 'y') {
					p1.keyword_cipher_den(ph, msg, plaintext);
				}
			
				cout << "\n\n\t\tDO you want to continue[Y/N]: ";
			
				cin >> choice;
			
				if (choice == 'N' || choice == 'n') {
					cout << "\n\t\tQuitting..." << endl;
					choice = 'Q';
				}
				system("cls");
			}
			else if (choice == 'R' || choice == 'r') {
				encryption r1;
				double track;
				double phi = (r1.p_getter() - 1) * (r1.q_getter() - 1); //calculate phi
				double e = 5;
				//for checking that 1 < e < phi(n) and gcd(e, phi(n)) = 1; i.e., e and phi(n) are coprime.
				while (e < phi) {
					track = r1.gcd(e, phi);
					if (track == 1) {
						break;
					}
					else {
						e++;
					}
				}
				double array[100000];
				string msg;
				cout << "\n\t\tEnter a message: ";
			
				cin.ignore();
				getline(cin, msg);
				int len = r1.asciicode(array, msg);
				string encrypted_msg = r1.RSA_en(array, e, len);
			
				cout << "\n\t\tEncrypted Message: ";
		
				cout<< encrypted_msg << endl;
				
				cout << "\n\t\tDo you want to Decrypt the msg(Y/N): ";
			
				cin >> choice;
				if (choice == 'Y' || choice == 'y') {
					double d = 1 / e;
					string decrypted_msg = r1.RSA_den(d, len);
					
					cout << "\n\t\tDecrypted Message: ";
				
					cout<< decrypted_msg << endl;
				}
			
				cout << "\n\n\t\tDO you want to continue[Y/N]: ";
			
				cin >> choice;
			
				if (choice == 'N' || choice == 'n') {
					cout << "\n\t\tQuitting..." << endl;
					choice = 'Q';
				}
				system("cls");
			}
			else {
			
				cout << "\n\t\tInvalid choice!" << endl;
				system("cls");
			}
		}
	
		else if (choice == 'Q' || choice == 'q') {
		
			cout << "\n\t\tQuitting..." << endl;
		}
		else {
		
			cout << "\n\t\tInvalid choice!" << endl;
			system("cls");
		}
	} while (choice != 'Q' && choice != 'q');
	return 0;
}
