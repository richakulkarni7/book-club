//BORROWING SCREEN
#include<iostream>
#include<fstream>
#include<string.h>
using namespace std;

typedef struct book
{
   // char [20] ID;
    char title[20];
    char author[20];

};

void display()
{
    ifstream lfilei;
    lfilei.open("book_list.dat", ios::in);
    book b;
    while(lfilei.read(reinterpret_cast<char*>(&b), sizeof(b))>0)
        cout<<"Title: "<<b.title<<", Author: "<<b.author<<endl;
    lfilei.close();
}

bool check_book(char* name)
{
    ifstream lfilei;
    lfilei.open("book_list.dat", ios::in);
    book b;
    while(lfilei.read(reinterpret_cast<char*>(&b), sizeof(b))>0)
    {
        //cout<<"checking";
        if(strcmp(b.title,name)==0)
            return true;
    }
    return false;
}

void borrow()
{

    char tryname[20];
    int choice;


    do
    {
        cout<<endl<<"What book would you like to read?";
        cin>>tryname;
        if(!check_book(tryname))
        {
            cout<<endl<<"Sorry, not found. Enter 1 to try again, 0 to exit. ";
            cin>>choice;
        }
        else
        {
            cout<<"Book is available."<<endl<<"How many days for? ";
            int days;
            cin>> days;
            cout<<"Successful!";
            break;
        }

    }while(choice);


}

