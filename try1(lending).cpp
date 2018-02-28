//LENDING SCREEN
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

bool check_book(char* name)
{
    ifstream lfilei;
    lfilei.open("book_list.dat", ios::in);
    book b;
    while(lfilei.read(reinterpret_cast<char*>(&b), sizeof(b))>0)
    {
        cout<<"checking";
        if(strcmp(b.title,name)==0)
            return true;
    }
    return false;
}

void lend()
{
    ofstream lfileo;
    lfileo.open("book_list.dat", ios::app|ios::out);
    int n;
    cout<<"How many books do you want to lend? ";
    cin>>n;
    for(int i=0;i<n;i++)
    {
        book b;
        char tryname[20];
        cout<<"Enter title of book:";
        cin>>tryname;
        //cin.getline(tryname,19);
        if(check_book(tryname))
            cout<<tryname<<" Already there"<<endl;
        else
        {
            strcpy(b.title, tryname);
            cout<<"Enter author's name: ";
            cin>>b.author;

            lfileo.write(reinterpret_cast<char*>(&b), sizeof(b));
            //lfileo<<b.author;
            //cout<<"Thanks. Your book ID is: "<<
        }



    }
}

void display()
{
    ifstream lfilei;
    lfilei.open("book_list.dat", ios::in);
    book b;
    while(lfilei.read(reinterpret_cast<char*>(&b), sizeof(b))>0)
        cout<<"Title: "<<b.title<<", Author: "<<b.author<<endl;
    lfilei.close();
}

int main()
{
    lend();
    display();
}
