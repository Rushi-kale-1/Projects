#include <iostream>
#include <fstream>
#include <sstream>
#include <string>
#include <vector>

using namespace std;

int main(){
    bool login= false;
    int user_choice;
    string username,user_line,pass_line,login_password,login_username,password,user_word, pass_word, pass_change_main,pass_change_confirm;
    vector<string >user;
    vector<string>pass;

    cout << "  ******  *******  *******  *     *  *******  ******* "<<endl;
    cout << "  *       *        *        *     *  *     *  *       "<<endl;
    cout << "  ******  *****    *        *     *  *******  *****   "<<endl;
    cout << "       *  *        *        *     *  *  *     *       "<<endl;
    cout << "  ******  *******  *******  *******  *     *  ******* "<<endl;


    cout<<"__________Welcome to security system by Rushikesh kale________"<<endl<<endl;


    do{
        cout<<"|||||||||||||||||||||||||||||||||||||"<<endl;
        cout<<"         1. New Registration"<<endl;
        cout<<"-------------------------------------"<<endl;
        cout<<"         2. Login"<<endl;
        cout<<"-------------------------------------"<<endl;
        cout<<"         3. Change Password"<<endl;
        cout<<"-------------------------------------"<<endl;
        cout<<"         4. End Program"<<endl<<endl;
        cout<<"|||||||||||||||||||||||||||||||||||||"<<endl<<endl;
        cout<<"         Enter your choice         "<<endl;

        cin>>user_choice;

        switch(user_choice){

            case 1 : {
                cout<<"Registration Initiated"<<endl<<endl;
                cout << "Enter Username for registration" << endl;
                cin >> username;
                cout << "Enter password" << endl;
                cin >> password;

                ofstream of1;
                of1.open("user.txt");

                ofstream of2;
                of2.open("pass.txt");

                if (of1.is_open() && of2.is_open()) {
                    of1 << username << "\n";
                    of2 << password << "\n";
                    cout << "<-----Registration Successful----->" << endl<<endl;
                }

                of1.close();
                of2.close();
                break;
            }

            case 2: {
                login= false;
                int i=0;
                cout<<"Login Initiated"<<endl<<endl;
                cout << "Enter Username" << endl;
                cin >> login_username;
                cout << "Enter Password" << endl;
                cin >> login_password;

                ifstream if1;
                if1.open("user.txt");

                ifstream  if2;
                if2.open("pass.txt");



                if(if1.is_open() && if2.is_open()){
                    while(!if1.eof() && !login){
                        while (getline(if1, user_line), getline(if2, pass_line)){
                            istringstream iss_user(user_line);
                            iss_user >> user_word;
                            istringstream  iss_pass(pass_line);
                            iss_pass>> pass_word;


                            if(login_username == user_word && login_password == pass_word){

                                login = true;

                                break;
                            }

                        }
                    }
                    if(login){
                        cout<<"<----- Login successful----->"<<endl<<endl;
                        cout<<"+++++++++++++++++++++++++++++++++++++++++"<<endl;
                        cout<<"+++++++++++++++++++++++++++++++++++++++++"<<endl;

                        cout<<login_username<<", Now you have access to system."<<endl;


                        cout<<"+++++++++++++++++++++++++++++++++++++++++"<<endl;
                        cout<<"+++++++++++++++++++++++++++++++++++++++++"<<endl<<endl;

                    }
                    else{
                        cout<<"<----- Invalid Credential ----->"<<endl<<endl;
                    }
                }
                break;
            }
            case 3:

                if(login){
                    ofstream of2;
                    of2.open("pass.txt");

                    if(of2.is_open()){
                        cout<<"------Changing of Password Initiated------"<<endl<<endl;

                        cout<<"------Enter new password------"<<endl;

                        cin>>pass_change_main;
                        cout<<"------Confirm password------"<<endl<<endl;
                        cin>>pass_change_confirm;
                        if(pass_change_main==pass_change_confirm){
                            of2<<pass_change_confirm<<"\n";
                            cout<<"<-----Password Changed Successfully----->"<<endl<<endl;

                        }
                        else{
                            cout<<"<-----Password not matching :: Unsuccesful------>"<<endl<<endl;
                        }

                    }
                }
                else{
                    cout<<"------First login with old password (Enter 2)------"<<endl<<endl;

                }

                break;

            case 4:
                return 0;

                break;
            default:
                cout<<"------Enter valid choice------"<<endl;
                break;
        }

    }
    while(user_choice!=4 );

}