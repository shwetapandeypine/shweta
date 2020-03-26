#include<iostream>
#include<stdio.h>
#include<stdlib.h>
#include<fstream>
#include<string.h>
#include<conio.h>
using namespace std;
class lib
{
   public:
       char book[100],author[50],bookid[20],publication[50], stuname[100], stid[20];
       int qty,B,price;
       lib()
       {
           strcpy(book,"NO Book Name");
	   strcpy(stuname,"NO Student Name");
	   strcpy(stid,"NO Studebt ID");
           strcpy(author,"No Author Name");
           strcpy(bookid,"No Book ID");
           strcpy(publication,"No Book Publication");
           qty=0;
           B=0;
           price=0;
       }
	  void info();
          void student();
          void lib_pass();
          void librarian();
          void add();
          void display(int);
          void list(int);
	  void issue();
	  void fine(int,int,int,int,int,int);
};



int main()
{
    lib obj;
    obj.info();
    
    return 0;
}



//***********Main Login Pannel******

void lib::info()
{
   int i;
        cout<<"\n\t*********** LIBRARY MANAGEMENT SYSTEM ***********\n"<<"\n\n";
        cout<<"\n\t\tLogin As :- \n";
        cout<<"\n\t\t1.Student\n\n\t\t2.Librarian\n\n\t\t3.Close Application\n";
        cout<<"\n\t\tEnte Option : ";
        cin>>i;
        if(i==1)
        {
            system("cls");
            student();
        }
        else if(i==2)
            lib_pass();

        else if(i==3)
            exit(0);
        else
        {
            cout<<"\n\t\t###Incorrect Input###";
            
            system("cls");
           info();
        }
}


//*************Student Login and Work Pannel**************
void lib::student()
{
    int i;
        cout<<"\n\t************ WELCOME STUDENT ************\n";
        cout<<"\n\t\tSelect Option:\n";
        cout<<"\n\t\t1.View BookList\n\n\t\t2.Search for a Book\n\n\t\t3.Go to main menu\n\n\t\t4.Close Application\n";
        cout<<"\n\t\tEnter your choice : ";
        cin>>i;
            if(i==1)
                list(1);
            else if(i==2)
                search(1);
            else if(i==3)
            {
                system("cls");
                info();
            }
            else if(i==4)
                exit(0);
            else
            {
                cout<<"\n\t\t###Incorrect Input###";
                
                system("cls");
                student();
            }
}





//************Librarian Login***********
void lib::lib_pass()
{
    int i=0;
    char ch,st[21],ch1[21]={"pass"};
    cout<<"\n\t\tEnter Password : ";
    while(1)
    {
   
    if(ch==13)
    {
        st[i]='\0';
        break;
    }
    else if(ch==8&&i>0)
    {
        i--;
        cout<<"\b \b";
    }
    else
    {
    cout<<"*";
    st[i]=ch;
    i++;
    }
    }
    ifstream inf("password.txt");
    inf>>ch1;
    inf.close();
    for(i=0;st[i]==ch1[i]&&st[i]!='\0'&&ch1[i]!='\0';i++);
    if(st[i]=='\0'&&ch1[i]=='\0')
    {
        system("cls");
        librarian();
    }
    else
    {
        cout<<"\n\n\t\t###########Wrong Password###########\n\n\t\tTry Again.....\n";
       
        system("cls");
        info();
    }
}

//*********Librarian Work Pannel**********
void lib::librarian()
{
    int i;
        cout<<"\n\t************ WELCOME LIBRARIAN ************\n";
        cout<<"\n\t\tSelect Option:\n";
        cout<<"\n\t\t1.Display BookList\n\n\t\t2.Search Book\n\n\t\t3.Issue Book\n\n\t\t4.Go to main menu\n\n\t\t5.Change Password\n\n\t\t6.Close Application\n";
        cout<<"\n\t\tEnter your choice : ";
        cin>>i;
        switch(i)
        {
            case 1:list(2);
                     break;
            case 2:search(2);
                     break;
            case 3:issue();
                     break;
            case 4:system("cls");
                     info();
                     break;
            case 5:password();
                    break;
            case 6:exit(0);
            default:cout<<"\n\t\t###Incorrect Input###";
            
            system("cls");
            librarian();
        }
}




//*************Addition of Book Detail**********************
void lib::add()
{
                    int i;
                    fflush(stdin);

                    cout<<"\n\t\tEnter the details :-\n";
                    cout<<"\n\t\tEnter Book's Name : ";
                    cin.getline(book,100);
		cout<<"\n\t\tEnter Author's Name : ";
                    cin.getline(author,50);

                    cout<<"\n\t\tEnter Publication name : ";
                    cin.getline(publication,50);

                    cout<<"\n\t\tEnter Book's ID : ";
                    cin.getline(bookid,20);

                    cout<<"\n\t\tEnter Book's Price : ";
                    cin>>price;

                    cout<<"\n\t\tEnter Book's Quantity : ";
                    cin>>qty;
}

//***************display detail**************
void lib::display(int i)
{
    cout<<"\n\t\tBook Name : "<<book<<endl;
    cout<<"\n\t\tAuthor Name : "<<author<<endl;
    cout<<"\n\t\tBook ID : "<<bookid<<endl;
    cout<<"\n\t\tPublication : "<<publication<<endl;
    if(i==2)
    {
        cout<<"\n\t\tPrice : "<<price<<endl;
        cout<<"\n\t\tQuantity : "<<qty<<endl;
    }
}


//*************display list******************
void lib::list(int i)
  {
                int b,r=0;
                system("cls");
               
                system("cls");
                ifstream intf("Book.txt",ios::binary);
                if(!intf)
                    cout<<"\n\t\tFile Not Found.";
                else
                {
                    cout<<"\n\t    ************ Book List ************ \n\n";
                    intf.read((char*)this,sizeof(*this));
                while(!intf.eof())
                {
                    if(b==B)
                    {
                        if(qty==0 && i==1)
                        {

                        }
                        else
                            {
                                r++;
                                cout<<"\n\t\t********** "<<r<<". ********** \n";
                                display(i);
                            }
                    }
                    intf.read((char*)this,sizeof(*this));
                }
                }
                cout<<"\n\t\tPress any key to continue.....";
          
                system("cls");
                if(i==1)
                    student();
                else
                    librarian();
    }



//**************Fine**************
void lib::fine(int d,int m,int y,int dd,int mm,int yy)
{
    long int n1,n2;
    int year,l,i;
    const int mmdd[12] = {31, 28, 31, 30, 31, 30,31, 31, 30, 31, 30, 31};
    n1 = y*365 + d;
    for (i=0; i<m - 1; i++)
        n1 += mmdd[i]; 
    year = y;
    if (m <= 2)
    year--;
    l= year / 4 - year / 100 + year / 400;
    n1 += l;
    n2 = yy*365 + dd;
    for (i=0; i<mm - 1; i++)
        n2 += mmdd[i];
    year = yy;
    if (m <= 2)
    year--;
    l= year / 4 - year / 100 + year / 400;
    n2 += l;
    n1=n2-n1;
    n2=n1-15;
    if(n2>0)
    cout<<"\n\t\tThe Total Fine is : "<<n2;
    
}




//***********Issue***************
void lib::issue()
{
    char st[50],st1[20];
    int b,i,j,d,m,y,dd,mm,yy,cont=0;
    system("cls");
    cout<<"\n\t\t-Option List :-\n";
    cout<<"\n\t\t1.Issue Book\n\n\t\t2.View Issued Book\n\n\t\t3.Search student who issued books\n\n\t\t4.Reissue Book\n\n\t\t5.Return Book\n\n\t\t6.Go back to menu";
    cout<<"\n\n\t\tEnter Option : ";
    cin>>i;
    fflush(stdin);
    if(i==1)
    {
    system("cls");
    b=branch(2);
    system("cls");
    fflush(stdin);
    cout<<"\n\t\tEnter Details :-\n";
    cout<<"\n\t\tEnter Book Name : ";
    cin.getline(book,100);
    cout<<"\n\t\tEnter Book ID : ";
    cin.getline(bookid,20);
    
   
    cout<<"\n\t\tEnter Student Name : ";
    cin.getline(stuname,100);
    cout<<"\n\t\tEnter Student's ID : ";
    cin.getline(stid,20);
    cout<<"\n\t\tEnter date : ";
    cin>>dd>>mm>>yy;



          

