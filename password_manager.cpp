#include<bits/stdc++.h>
using namespace std;

int choice{};
string RandomPassword(int n);
string EncryptMessage(string s);
string DecryptMessage(string s);
void DisplayWelcome();
void DisplayOption();
void Write_to_file(string s);
string ReadFromFile(int i=0);
void Write_crypt(string s ,string file);
string alphabet {"ABCDEFGHIJKLMNOPQRSTUVWXYZabcdefghijklmnopqrstuvwxyz1234567890"};
string key      {"F9ODXJR4Ybt7emEBl3S5HoTP2yxpLWf0aVQsgAhnKwM1CNUI6v8ujqGkZrdzci"};

int main(){
    while(true){
        DisplayWelcome();
        cin>>choice;
        cout<<"\n\t\t\t\t\t\t   ----------------------------------------------\n";
        if(choice == 4)
            break;
        else if(choice == 1){
			string pass;
			int n{};
			label_1_1:
	    	cout<<"\n\t\t\t\t\t\t\t   1.)Generate random length."
				<<"\n\t\t\t\t\t\t\t   2.)Enter Length of password."
				<<"\n\t\t\t\t\t\t\t      Enter your choice: ";
	    	cin>>choice;
	    	cout<<"\n\t\t\t\t\t\t   ----------------------------------------------\n";
			if(choice == 1){
				srand(time(nullptr));
				n = rand()%13 +  8;
			}
	    	else if(choice == 2){
           		cout<<"\t\t\t\t\t\t\t    Enter length of password: ";
            	cin>>n;
            	if(n<=8 || n>=20){
					cout<<"\t\t\t\t\t\t\tPlease Enter number betweeen 8 and 20\n";
					goto label_1_1;
	    		}
			}
			else{
				cout<<"\n\t\t\t\t\t\t\t    xxxxxxxxxxxxxxxxxxxxxxxx"
                    <<"\n\t\t\t\t\t\t\t     Choose a valid option: "
                    <<"\n\t\t\t\t\t\t\t    xxxxxxxxxxxxxxxxxxxxxxxx\n";
                goto label_1_1;
			}
            pass = RandomPassword(n);
            cout<<"\n\t\t\t\t\t\t   The Random Password generated is: "<<pass<<"\n"
                <<"\t\t\t\t\t   ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~\n";
            label_1_2:
            DisplayOption();
            if(choice == 1)
                Write_to_file(pass);
            	else if(choice == 2){
			}
            else{
                cout<<"\n\t\t\t\t\t\t\t    xxxxxxxxxxxxxxxxxxxxxxxx"
                    <<"\n\t\t\t\t\t\t\t     Choose a valid option: "
                    <<"\n\t\t\t\t\t\t\t    xxxxxxxxxxxxxxxxxxxxxxxx\n";
                goto label_1_2;
            }
        }

        else if(choice == 2){
            label_2_1:
            cout<<"\n\t\t\t\t\t\t\t        Would you like to : " 
                <<"\n\t\t\t\t\t\t\t   1.)Enter text to be encrypted."
                <<"\n\t\t\t\t\t\t\t   2.)Encrypt a text file.\n"
                <<"\n\t\t\t\t\t\t\t        Enter your choice: ";
            cin>>choice;
            cout<<"\n\t\t\t\t\t\t   ----------------------------------------------\n";
            string s;
            if(choice == 1){
                cout<<"\n\t\t\t\t\t\t\t Enter text to be Encrypted: ";
                cin.ignore(numeric_limits<streamsize>::max(), '\n');
                getline(cin,s);
                s = EncryptMessage(s);
                cout<<"\n\t\t\t\t\t\t\t Encrypted Text is: "<<s<<"\n"
		    <<"\t\t\t\t\t~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~\n";
            }
            else if(choice == 2){
                s = ReadFromFile(1);
				continue;
            }
            else{
                 cout<<"\n\t\t\t\t\t\t\t   xxxxxxxxxxxxxxxxxxxxxxxx"
                    <<"\n\t\t\t\t\t\t\t     Choose a valid option: "
                    <<"\n\t\t\t\t\t\t\t    xxxxxxxxxxxxxxxxxxxxxxxx\n";
                goto label_2_1;
            }
            label_2_2:
            DisplayOption();
            if(choice == 1)
                Write_to_file(s);
            else if(choice == 2){
            }
            else{
                 cout<<"\n\t\t\t\t\t\t\t   xxxxxxxxxxxxxxxxxxxxxxxx"
                    <<"\n\t\t\t\t\t\t\t     Choose a valid option: "
                    <<"\n\t\t\t\t\t\t\t    xxxxxxxxxxxxxxxxxxxxxxxx\n";
                goto label_2_2;
            }
        }
        else if(choice == 3){
            label_3_1:
            cout<<"\n\t\t\t\t\t\t\t        Would you like to : " 
                <<"\n\t\t\t\t\t\t\t   1.)Enter text to be decrypted."
                <<"\n\t\t\t\t\t\t\t   2.)Decrypt a text file.\n"
                <<"\n\t\t\t\t\t\t\t        Enter your choice: ";
            cin>>choice;
            cout<<"\n\t\t\t\t\t\t   ----------------------------------------------\n";
            string s;
            if(choice == 1){
                cout<<"\n\t\t\t\t\t\t\t Enter text to be decrypted: ";
                getline(cin,s);
                s = DecryptMessage(s);
            }
            else if(choice == 2){
                s = ReadFromFile(2);
		continue;
            }
            else{
                cout<<"\n\t\t\t\t\t\t\t    xxxxxxxxxxxxxxxxxxxxxxxx"
                    <<"\n\t\t\t\t\t\t\t     Choose a valid option: "
                    <<"\n\t\t\t\t\t\t\t    xxxxxxxxxxxxxxxxxxxxxxxx\n";
                goto label_3_1;
            }
            cout<<"\n\t\t\t\t\t\t\t Decrypted Text is: "<<s<<"\n"
		<<"\t\t\t\t\t~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~\n";
            label_3_2:
            DisplayOption();
            if(choice == 1){
                Write_to_file(s);
            }
            else if(choice == 2){
            }
            else{
                 cout<<"\n\t\t\t\t\t\t\t   xxxxxxxxxxxxxxxxxxxxxxxx"
                    <<"\n\t\t\t\t\t\t\t     Choose a valid option: "
                    <<"\n\t\t\t\t\t\t\t    xxxxxxxxxxxxxxxxxxxxxxxx\n";
                goto label_3_2;
            }
        }
        else{
             cout<<"\n\t\t\t\t\t\t\t    xxxxxxxxxxxxxxxxxxxxxxxx"
                 <<"\n\t\t\t\t\t\t\t     Choose a valid option: "
                 <<"\n\t\t\t\t\t\t\t    xxxxxxxxxxxxxxxxxxxxxxxx\n";
        }
    }
	cout<<"\n********************************************************************************************"
        <<"*************************************************************\n";
    return 0;
}

string RandomPassword(int n){
    srand(time(nullptr));
    string s;
    while(n--)
        s += (rand()%79+48);
    return s;
}
string EncryptMessage(string s){
    string encrypted_message;
    for(char &c: s){
        size_t position = alphabet.find(c);
        if(position != string::npos)
            encrypted_message += key.at(position);
        else
            encrypted_message += c;
    }
    return encrypted_message;
}
string DecryptMessage(string s){
    string decrypted_message;
    for(char c: s){
        size_t position = key.find(c);
        if(position != string::npos)
            decrypted_message += alphabet.at(position);
        else
            decrypted_message += c;
    }
    return decrypted_message;
}
void DisplayWelcome(){
    cout<<"\n*************************************************************Welcome to Password Manager"
        <<"*************************************************************\n"
        <<"\t\t\t\t\t\t\t     1.)Generate Random Password.\n"
        <<"\t\t\t\t\t\t\t     2.)Encrypt a message.\n"
        <<"\t\t\t\t\t\t\t     3.)Decrypt a message.\n"
        <<"\t\t\t\t\t\t\t     4.)Exit.\n"
        <<"\n\t\t\t\t\t\t\t    What would you like to do: ";
}
void DisplayOption(){
    cout<<"\n\t\t\t\t\t\t\t        Would you like to : \n" 
        <<"\n\t\t\t\t\t\t\t   1.)Save this Text(Encrypted)."
        <<"\n\t\t\t\t\t\t\t   2.)Don't Save.\n"
        <<"\n\t\t\t\t\t\t\t       Enter your choice: ";
	cin>>choice;
	cout<<"\n\t\t\t\t\t\t   ----------------------------------------------\n";
}
void Write_to_file(string s){
    string purpose{};
    cout<<"\n\t\t\t\t\t\t\t     What's this text for? ";
    cin.ignore(numeric_limits<streamsize>::max(), '\n');
    getline(cin,purpose);
    ofstream out_file{"./saved_text.txt",ios::app};
    if(out_file){
		time_t my_time = time(NULL);
		out_file << "\t  \t\t\tPURPOSE \t\t\t\t         \t\t\t TEXT\n";
		out_file<<"\n\t\t\t\t\t\t    "<<EncryptMessage("MODIFIED: ")<<EncryptMessage(ctime(&my_time));

        cout<<"\n\t\t\t\t\t\t The text has been sucessfully written to file : ./saved_text.txt"
            <<"\n\t\t\t\t\t        ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~\n";
    }
    else{
        cout<<"\n\t\t\t\t\t\t   _________________________FAILURE OPENING FILE_____________________\n";
    }
    out_file.close();
}
string ReadFromFile(int i){
    ifstream in_file;
    string filename;
    cout<<"\n\t\t\t\t\t\t\tEnter filename to be read from: ";
    cin >> filename;
    string str;
    in_file.open(filename);
    if(in_file){
        string line;
        while(getline(in_file,line))
            str += line + '\n';
    }
    else{
        cout<<"\n\t\t\t\t\t\t   _________________________FAILURE OPENING FILE_____________________\n";
    }
    if(i==1){
	str = EncryptMessage(str);
    	Write_crypt(str ,filename);
    }
    else if(i == 2){
		str = DecryptMessage(str);
		Write_crypt(str ,filename);
    }
	    
    in_file.close();
    return str;
}


void Write_crypt(string s ,string file){
    ofstream out_file{file};
    if(out_file){
        out_file << s<<endl;

        cout<<"\n\t\t\t\t\t\t The text has been sucessfully written to file :"<< file
            <<"\n\t\t\t\t\t        ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~\n";
    }
    else{
        cout<<"\n\t\t\t\t\t\t   _________________________FAILURE OPENING FILE_____________________\n";
    }
    out_file.close();
}