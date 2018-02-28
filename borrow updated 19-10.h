//BORROWING SCREEN
#include<iostream>
#include<fstream>
#include<string.h>
using namespace std;

/*typedef struct book
{
   // char [40] ID;
    char title[40];
    char author[40];

};*/

typedef struct bexchange
{
    char title[40];
    char author[40];
    char lender[40];
    char borrower[40];
    int days;
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

bexchange bcheck_book(char* name)
{
    bexchange exbook;
    ifstream lfilei;
    lfilei.open("book_list.dat", ios::in);
    book b;

    while(lfilei.read(reinterpret_cast<char*>(&b), sizeof(b))>0)
    {
        //cout<<"checking";
        if(strcmp(b.title,name)==0)
        {
            strcpy(exbook.title,b.title); //cout<<"hi title";
            strcpy(exbook.author,b.author); //cout<<"hi author";
            strcpy(exbook.lender,b.lender); //cout<<"hi lender";
            return exbook;
        }
    }

    strcpy(exbook.title,"dummybook");cout<<"hi";
    return exbook;
}

void borrow()
{

    char tryname[40];
    int choice;


    do
    {
        ofstream efileo;
        efileo.open("bexchange_list.dat", ios::app|ios::out);

        cout<<endl<<"What book would you like to read?";
        cin>>tryname;
        bexchange bex=bcheck_book(tryname);
        if(!strcmp(bex.title,"dummybook"))
        {
            cout<<endl<<"Sorry, not found. Enter 1 to try again, 0 to exit. ";
            cin>>choice;
        }
        else
        {
            cout<<"Book is available."<<endl<<"How many days for? ";
            int days;
            cin>> days;
            strcpy(bex.borrower,loguser);
            bex.days=days;//cout<<"hi days";
            efileo.write(reinterpret_cast<char*>(&bex), sizeof(bex));//cout<<"written";
            break;
        }

    }while(choice);


}

void borrowdisplay()
{
    ifstream efilei;
    efilei.open("bexchange_list.dat", ios::in);
    bexchange bex;
    cout<<left<<setw(20)<<"TITLE"<<left<<setw(20)<<"AUTHOR"<<left<<setw(20)<<"LENDER"
        <<setw(20)<<"BORROWER"<<setw(20)<<"Days"<<endl<<endl;
    while(efilei.read(reinterpret_cast<char*>(&bex), sizeof(bex))>0)
        cout<<setw(20)<<left<<bex.title<<setw(20)<<left<<bex.author<<setw(20)<<left<<bex.lender
            <<setw(20)<<left<<bex.borrower<<setw(20)<<left<<bex.days<<endl;
    efilei.close();
}

