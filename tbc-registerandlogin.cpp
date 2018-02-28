#include<iostream>
#include<fstream>
#include<string.h>
using namespace std;

void addreaders(); //Allows users to register by giving a username - adds record to the file
void display(); //Displays contents of file - USE ONLY TO CHECK CONTENTS
bool login(); //Allows existing user to login
bool check_username(char*); //Checks if a username is already taken during registration, and is also used to find the correct record while login

typedef struct reader
{
    char username[20];
    char password[20];
};

void addreaders()
{
    ofstream rfileo;
    rfileo.open("reader_data.dat", ios::app|ios::out);
    char tryname[20];
    reader r;
    cout<<"Enter username: ";
    cin>>tryname;
    if(check_username(tryname))
    {
        cout<<"Username already exists. Try again."<<endl;

    }
    else
    {
        strcpy(r.username, tryname);
        cout<<"Enter password: ";
        cin>>r.password;
        rfileo.write(reinterpret_cast<char*>(&r), sizeof(r));
    }

    rfileo.close();
}

void display()
{
    ifstream rfilei;
    rfilei.open("reader_data.dat", ios::in);
    reader r;
    while(rfilei.read(reinterpret_cast<char*>(&r), sizeof(r))>0)
        cout<<"Username: "<<r.username<<", Password: "<<r.password<<endl;
    rfilei.close();
}

bool login()
{
    char name[20], pw[20];
    cout<<"Enter username: ";
    cin>>name;
    cout<<"Enter password: ";
    cin>>pw;
    ifstream rfilei;
    rfilei.open("reader_data.dat", ios::in);
    reader r;
    while(rfilei.read(reinterpret_cast<char*>(&r), sizeof(r))>0)
    {
        if(strcmp(r.username, name)==0)
        {
            if(strcmp(r.password, pw)==0)
            {
                rfilei.close();
                return true;
            }
            else
            {
                cout<<endl<<"Username or password is wrong."<<endl;
                return false;
            }
        }
        else
            continue;
    }
    rfilei.close();
    cout<<endl<<"Username or password is wrong."<<endl;
    return false;
    rfilei.close();

}
bool check_username(char* name)
{
    ifstream rfilei;
    rfilei.open("reader_data.dat", ios::in);
    reader r;
    while(rfilei.read(reinterpret_cast<char*>(&r), sizeof(r))>0)
    {
        if(strcmp(r.username, name)==0)
            return true;
    }
    return false;
}

int main()
{
    cout<<"Hi. Enter 'r' to register, 'd' to display users, 'l' to login, 's' to stop: ";
    char choice;
    cin>>choice;

    while(choice!='s')
    {

        switch(choice)
        {
        case 'r':
            {
                cout<<endl<<"REGISTRATON"<<endl;
                addreaders();
                break;
            }
        case 'd':
            {
                cout<<endl<<"EXISTING USERS ARE: "<<endl;
                display();
                break;
            }
        case 'l':
            {
                cout<<endl<<"LOGIN:"<<endl;
                for(int i=4;i>=0;i--)
                {
                    if(login())
                    {
                        cout<<endl<<"CONGRATULATIONS! SUCCESFUL LOGIN.";
                        return 0;
                    }

                    else
                        cout<<endl<<"Failed login. Try again. You have "<<i<<" more tries."<<endl;
                }
            }

        }
        cout<<endl<<"What next? ";
        cin>>choice;
    }

    return 0;

}
