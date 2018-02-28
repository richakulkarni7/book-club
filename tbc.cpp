#include "reglogin.h"
#include "lend.h"
//#include ""

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
                userdisplay();
                break;
            }
        case 'l':
            {
                cout<<endl<<"LOGIN:"<<endl;
                for(int i=4;i>=0;i--)
                {
                    if(login())
                    {
                        char loguser[20];
                        cout<<endl<<"CONGRATULATIONS! SUCCESFUL LOGIN. You are: "<<rloguser();
                        goto lend;

                    }

                    else
                        cout<<endl<<"Failed login. Try again. You have "<<i<<" more tries."<<endl;
                }
            }

        }
        cout<<endl<<"What next? ";
        cin>>choice;
    }

    lend:
    cout<<endl<<"LENDING SCREEN"<<endl;
    lend();
    cout<<endl<<"THANK YOU FOR LENDING."<<endl<<"List of books available:"<<endl;
    lenddisplay();
    return 0;

}
