#include<iostream>
#include<stdio.h>
#include<stdlib.h>
#include<fstream>
#include<string.h>
//#include<conio.h>
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
          void password();
          void add();
          void display(int);
          void list(int);
          void modify();
          void search(int);
          int branch(int);
          void issue();
          void der(char[],int,int);
          void fine(int,int,int,int,int,int);
};


//*************Addition of Book Detail**********************
void lib::add()
{
                    int i;
                    fflush(stdin);

                    cout<<"\n\t\tEnter the details :-\n";
                    cout<<"\n\t\tEnter Book's Name : ";
                    cin.getline(book,100);
                    for(i=0;book[i]!='\0';i++)
                    {
                    if(book[i]>='a'&&book[i]<='z')
                       book[i]-=32;
                    }

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
                b=branch(i);
                system("cls");
                ifstream intf("Booksdata.txt",ios::binary);
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
                //getch();
                system("cls");
                if(i==1)
                    student();
                else
                    librarian();
    }


//**************Modify Details**************
  void lib::modify()
  {
    char ch,st1[100];
    int i=0,b,cont=0;
    system("cls");
    cout<<"\n\t\t>>Make Changes According To :-\n";
    cout<<"\n\t\t1.Modification In Current Books\n\n\t\t2.Add New Book\n\n\t\t3.Delete A Book\n\n\t\t4.Go back\n";
    cout<<"\n\n\t\tEnter Option : ";
    cin>>i;
    if(i==1)
    {
                    system("cls");
                    b=branch(2);
                    ifstream intf1("Booksdata.txt",ios::binary);
                    if(!intf1)
                    {
                        cout<<"\n\t\tFile Not Found\n";
                        cout<<"\n\t\tPress any key to continue.....";
                        //getch();
                        system("cls");
                        librarian();
                    }
                        intf1.close();
                        system("cls");
                        cout<<"\n\t\tSearch by :-\n";
                        cout<<"\n\t\t1. Book Name\n\n\t\t2. Book ID\n";
                        cout<<"\n\t\tEnter Option : ";
                        cin>>i;
                        fflush(stdin);
                        if(i==1)
                            {
                                system("cls");
                                cout<<"\n\t\tEnter Book Name : ";
                                cin.getline(st1,100);
                                system("cls");
                                fstream intf("Booksdata.txt",ios::in|ios::out|ios::ate|ios::binary);
                                intf.seekg(0);
                                intf.read((char*)this,sizeof(*this));
                                while(!intf.eof())
                                    {
                                        for(i=0;b==B&&book[i]!='\0'&&st1[i]!='\0'&&(st1[i]==book[i]||st1[i]==book[i]+32);i++);
                                        if(book[i]=='\0'&&st1[i]=='\0')
                                            {
                                                cont++;
                                                add();
                                                intf.seekp(intf.tellp()-sizeof(*this));
                                                intf.write((char*)this,sizeof(*this));
                                                break;
                                            }
                                                     intf.read((char*)this,sizeof(*this));
                                    }
                                    intf.close();
                            }
                        else if(i==2)
                        {
                                cout<<"\n\t\tEnter Book ID : ";
                                cin.getline(st1,100);
                                system("cls");
                                fstream intf("Booksdata.txt",ios::in|ios::out|ios::ate|ios::binary);
                                intf.seekg(0);
                                intf.read((char*)this,sizeof(*this));
                                while(!intf.eof())
                                    {
                                        for(i=0;b==B&&bookid[i]!='\0'&&st1[i]!='\0'&&st1[i]==bookid[i];i++);
                                        if(bookid[i]=='\0'&&st1[i]=='\0')
                                            {
                                                cont++;
                                                add();
                                                intf.seekp(intf.tellp()-sizeof(*this));
                                                intf.write((char*)this,sizeof(*this));
                                                break;
                                            }
                                        intf.read((char*)this,sizeof(*this));
                                    }

                                intf.close();
                        }
                        else
                        {
                            cout<<"\n\t\t####Incorrect Input####(\n";
                            cout<<"\n\t\tPress any key to continue.....";
                            //getch();
                            system("cls");
                            modify();
                        }
                        if(cont==0)
                        {
                            cout<<"\n\t\t##Book Not Found##\n";
                            cout<<"\n\t\tPress any key to continue.....";
                            //getch();
                            system("cls");
                            modify();
                        }
                        else
                            cout<<"\n\t\t#######Update Successful#######\n";


    }
    else if(i==2)
    {
                    system("cls");
                    B=branch(2);
                    system("cls");
                    add();
                    ofstream outf("Booksdata.txt",ios::app|ios::binary);
                    outf.write((char*)this,sizeof(*this));
                    outf.close();
                    cout<<"\n\t\t######Book added Successfully########\n";
    }
    else if(i==3)
    {
                    system("cls");
                    b=branch(2);
                    ifstream intf1("Booksdata.txt",ios::binary);
                    if(!intf1)
                    {
                        cout<<"\n\t\tFile Not Found\n";
                        cout<<"\n\t\tPress any key to continue.....";
                        //getch();
                        intf1.close();
                        system("cls");
                        librarian();
                    }
                        intf1.close();
                        system("cls");
                        cout<<"\n\t\tDelete Book by:-\n";
                        cout<<"\n\t\t1. Book Name\n\n\t\t2. Book ID\n";
                        cout<<"\n\t\tEnter Option : ";
                        cin>>i;
                        fflush(stdin);
                        if(i==1)
                            {
                                system("cls");
                                cout<<"\n\t\tEnter Book Name : ";
                                cin.getline(st1,100);
                                ofstream outf("temp.txt",ios::app|ios::binary);
                                ifstream intf("Booksdata.txt",ios::binary);
                                intf.read((char*)this,sizeof(*this));
                                while(!intf.eof())
                                    {
                                        for(i=0;b==B&&book[i]!='\0'&&st1[i]!='\0'&&(st1[i]==book[i]||st1[i]==book[i]+32);i++);
                                        if(book[i]=='\0'&&st1[i]=='\0')
                                            {
                                                cont++;
                                                intf.read((char*)this,sizeof(*this));

                                            }
                                        else
                                        {
                                        outf.write((char*)this,sizeof(*this));
                                        intf.read((char*)this,sizeof(*this));
                                        }
                                    }

                    intf.close();
                    outf.close();
                    remove("Booksdata.txt");
                    rename("temp.txt","Booksdata.txt");
                            }
                        else if(i==2)
                        {
                                cout<<"\n\t\tEnter Book ID : ";
                                cin.getline(st1,100);
                                ofstream outf("temp.txt",ios::app|ios::binary);
                                ifstream intf("Booksdata.txt",ios::binary);
                                intf.read((char*)this,sizeof(*this));
                                while(!intf.eof())
                                    {
                                        for(i=0;b==B&&bookid[i]!='\0'&&st1[i]!='\0'&&st1[i]==bookid[i];i++);
                                        if(bookid[i]=='\0'&&st1[i]=='\0')
                                            {
                                                cont++;
                                                intf.read((char*)this,sizeof(*this));
                                            }
                                        else
                                        {
                                        outf.write((char*)this,sizeof(*this));
                                        intf.read((char*)this,sizeof(*this));
                                        }
                                    }
                    outf.close();
                    intf.close();
                    remove("Booksdata.txt");
                    rename("temp.txt","Booksdata.txt");
                        }
                        else
                        {
                            cout<<"\n\t\t###Incorrect Input###(\n";
                            cout<<"\n\t\tPress any key to continue.....";
                            //getch();
                            system("cls");
                            modify();
                        }
                        if(cont==0)
                        {
                            cout<<"\n\t\t####Book Not Found####\n";
                            cout<<"\n\t\tPress any key to continue.....";
                            //getch();
                            system("cls");
                            modify();
                        }
                        else
                            cout<<"\n\t\t#######Deletion Successful######\n";

    }
    else if(i==4)
    {
    system("cls");
    librarian();
    }
    else
    {
    cout<<"\n\t\t###Incorrect Input###\n";
    cout<<"\n\t\tPress any key to continue.....";
    //getch();
    system("cls");
    modify();
    }
    cout<<"\n\t\tPress any key to continue.....";
    //getch();
    system("cls");
    librarian();

  }

//**********Branch specification*****************
  int lib::branch(int x)
  {
      int i;
      cout<<"\n\t\t>>Select Branch :-\n";
      cout<<"\n\t\t1.CS\n\n\t\t2.EE\n\n\t\t3.EC\n\n\t\t4.CIVIL\n\n\t\t5.MECHANICAL\n\n\t\t6.1ST YEAR\n\n\t\t7.Go to menu\n";
      cout<<"\n\t\tEnter Option : ";
      cin>>i;
      switch(i)
      {
          case 1: return 1;
                  break;
          case 2: return 2;
                  break;
          case 3: return 3;
                  break;
          case 4: return 4;
                  break;
          case 5: return 5;
                  break;
          case 6: return 6;
                  break;
          case 7: system("cls");
                  if(x==1)
                  student();
                  else
                    librarian();
          default : cout<<"\n\t\t###Incorrect Input###";
                    //getch();
                    system("cls");
                    branch(x);
        }
  }

//***********Search********************
  void lib::search(int x)
  {
      int i,b,cont=0;
      char ch[100];
      system("cls");
      b=branch(x);
      ifstream intf("Booksdata.txt",ios::binary);
        if(!intf)
        {
            cout<<"\n\t\tFile Not Found.\n";
            cout<<"\n\t\t->Press any key to continue.....";
            //getch();
            system("cls");
            if(x==1)
            student();
            else
            librarian();
        }

      system("cls");
      cout<<"\n\t\tsearch By :-\n";
      cout<<"\n\t\t1. Book Name\n\n\t\t2. Book ID\n";
      cout<<"\n\t\tEnter Option : ";
      cin>>i;
      fflush(stdin);
      intf.read((char*)this,sizeof(*this));
      if(i==1)
      {
          cout<<"\n\t\tEnter Book's Name : ";
          cin.getline(ch,100);
          system("cls");
          while(!intf.eof())
          {
            for(i=0;b==B&&qty!=0&&book[i]!='\0'&&ch[i]!='\0'&&(ch[i]==book[i]||ch[i]==book[i]+32);i++);
            if(book[i]=='\0'&&ch[i]=='\0')
                {
                        cout<<"\n\t\tBook Found :-\n";
                        display(x);
                        cont++;
                        break;
                }
             intf.read((char*)this,sizeof(*this));
          }
      }
          else if(i==2)
          {
          cout<<"\n\t\tEnter Book's ID : ";
          cin.getline(ch,100);
          system("cls");
          while(!intf.eof())
          {
              for(i=0;b==B&&qty!=0&&bookid[i]!='\0'&&ch[i]!='\0'&&ch[i]==bookid[i];i++);
              if(bookid[i]=='\0'&&ch[i]=='\0')
                {
                            cout<<"\n\t\tBook Found :-\n";
                            display(x);
                            cont++;
                            break;
                }
               intf.read((char*)this,sizeof(*this));
          }

          }
          else
          {
             cont++;
             cout<<"\n\t\t###Incorrect Input###";
             //getch();
             system("cls");
             search(x);
          }
          intf.close();
          if(cont==0)
              cout<<"\n\t\tThis Book is not available :( \n";

    cout<<"\n\t\tPress any key to continue.....";
    //getch();
    system("cls");
    if(x==1)
    student();
    else
    librarian();


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
    //strcpy(st,sc);
    der(bookid,b,1);
    cout<<"\n\t\tEnter Student Name : ";
    cin.getline(stuname,100);
    cout<<"\n\t\tEnter Student's ID : ";
    cin.getline(stid,20);
    cout<<"\n\t\tEnter date : ";
    cin>>dd>>mm>>yy;
    ofstream outf("student.txt",ios::binary|ios::app);
    outf.write((char*)this,sizeof(*this));
    outf.close();
    cout<<"\n\n\t\tIssue Successfully.\n";
    }
    else if(i==2)
    {
    ifstream intf("student.txt",ios::binary);
    system("cls");
    cout<<"\n\t\tThe Details are :-\n";
    intf.read((char*)this,sizeof(*this));
    i=0;
    while(!intf.eof())
    {
    i++;
    cout<<"\n\t\t********** "<<i<<". ********** \n";
    cout<<"\n\t\tStudent Name : "<<stuname<<"\n\t\t"<<"Student's ID : "<<stid<<"\n\t\t"<<"Book Name : "<<book<<"\n\t\t"<<"Book's ID : "<<bookid<<"\n\t\t"<<"Date : "<<dd<<"/"<<mm<<"/"<<yy<<"\n";
    intf.read((char*)this,sizeof(*this));
    }
    intf.close();
    }
    else if(i==3)
    {
        system("cls");
        fflush(stdin);
        cout<<"\n\t\tEnter Details :-\n";
        cout<<"\n\n\t\tEnter Student Name : ";
        cin.getline(st,50);
        cout<<"\n\n\t\tEnter Student's ID : ";
        cin.getline(st1,20);
        system("cls");
        ifstream intf("student.txt",ios::binary);
        intf.read((char*)this,sizeof(*this));
        cont=0;
        while(!intf.eof())
        {
              for(i=0;stid[i]!='\0'&&st1[i]!='\0'&&st1[i]==stid[i];i++);
              if(stid[i]=='\0'&&st1[i]=='\0')
              {
                  cont++;
                  if(cont==1)
                  {
                      cout<<"\n\t\t->The Details are :-\n";
                      cout<<"\n\t\tStudent Name : "<<stuname;
                      cout<<"\n\t\tStudent's ID : "<<stid;
                  }
                  cout<<"\n\n\t\t******* "<<cont<<". Book details *******\n";
                  cout<<"\n\t\tBook Name : "<<book;
                  cout<<"\n\t\tBook's ID : "<<bookid;
                  cout<<"\n\t\tDate : "<<dd<<"/"<<mm<<"/"<<yy<<"\n";
              }
                      intf.read((char*)this,sizeof(*this));

        }
        intf.close();
        if(cont==0)
            cout<<"\n\t\tNo record found.";
    }
    else if(i==4)
    {
    system("cls");
    fflush(stdin);
    cout<<"\n\t\t Enter Details :-\n";
    cout<<"\n\n\t\tEnter Student's ID : ";
    cin.getline(st,50);
    cout<<"\n\t\tEnter Book's ID : ";
    cin.getline(st1,20);
    fstream intf("student.txt",ios::in|ios::out|ios::ate|ios::binary);
    intf.seekg(0);
    intf.read((char*)this,sizeof(*this));
    while(!intf.eof())
        {
            for(i=0;bookid[i]!='\0'&&st1[i]!='\0'&&st1[i]==st[i];i++);
            for(j=0;stid[j]!='\0'&&st[j]!='\0'&&st[j]==stid[j];j++);
            if(st[i]=='\0'&&stid[j]=='\0'&&st[j]=='\0'&&st1[i]=='\0')
                {
                    d=dd;
                    m=mm;
                    y=yy;
                    cout<<"\n\t\tEnter New Date : ";
                    cin>>dd>>mm>>yy;
                    fine(d,m,y,dd,mm,yy); //fn1
                    intf.seekp(intf.tellp()-sizeof(*this)); //fn3
                    intf.write((char*)this,sizeof(*this)); //fn5
                    cout<<"\n\n\t\tReissue successfully."; //fn3
                    break;
                }
                   intf.read((char*)this,sizeof(*this));
        }
        intf.close();
    }
    else if(i==5)
    {
    system("cls");
    b=branch(2);
    system("cls");
    fflush(stdin);
    cout<<"\n\t\tEnter Details :-\n";
    cout<<"\n\t\tEnter Book's ID : ";
    cin.getline(st1,20);
    der(st1,b,2);
    cout<<"\n\n\t\tEnter Student's ID : ";
    cin.getline(st,20);
    cout<<"\n\t\tEnter Present date : ";
    cin>>d>>m>>y;
    ofstream outf("temp.txt",ios::app|ios::binary);
    ifstream intf("student.txt",ios::binary);
    intf.read((char*)this,sizeof(*this));
    while(!intf.eof())
        {
            for(i=0;bookid[i]!='\0'&&st1[i]!='\0'&&st1[i]==bookid[i];i++);
            for(j=0;stid[j]!='\0'&&st[j]!='\0'&&st[j]==stid[j];j++);
            if(bookid[i]=='\0'&&stid[j]=='\0'&&st[j]=='\0'&&st1[i]=='\0'&&cont==0)
                {
                    cont++;
                    intf.read((char*)this,sizeof(*this));
                    fine(dd,mm,yy,d,m,y);
                    cout<<"\n\t\tReturned successfully.";
                }
            else
                {
                    outf.write((char*)this,sizeof(*this));
                    intf.read((char*)this,sizeof(*this));
                }
        }

    intf.close();
    outf.close();
    //getch();
    remove("student.txt");
    rename("temp.txt","student.txt");
    }
    else if(i==6)
    {
    system("cls");
    librarian();
    }
    else
        cout<<"\n\t\tWrong Input.\n";

    cout<<"\n\n\t\tPress any key to continue.....";
    //getch();
    system("cls");
    librarian();
}

//**************Fine**************
void lib::fine(int d,int m,int y,int dd,int mm,int yy)
{
    long int n1,n2;
    int years,l,i;
    const int monthDays[12] = {31, 28, 31, 30, 31, 30,31, 31, 30, 31, 30, 31};
    n1 = y*365 + d;
    for (i=0; i<m - 1; i++)
        n1 += monthDays[i]; //fn1353
    years = y;
    if (m <= 2)
    years--;
    l= years / 4 - years / 100 + years / 400;
    n1 += l;
    n2 = yy*365 + dd;
    for (i=0; i<mm - 1; i++)
        n2 += monthDays[i];
    years = yy;
    if (m <= 2)
    years--;
    l= years / 4 - years / 100 + years / 400;
    n2 += l;
    n1=n2-n1;
    n2=n1-15;
    if(n2>0)
    cout<<"\n\t\tThe Total Fine is : "<<n2;
    
}
void lib::der(char st[],int b,int x)
{
    int i,cont=0;
    fstream intf("Booksdata.txt",ios::in|ios::out|ios::ate|ios::binary);
    intf.seekg(0);
    intf.read((char*)this,sizeof(*this));
    while(!intf.eof())
    {
        for(i=0;b==B&&bookid[i]!='\0'&&st[i]!='\0'&&st[i]==bookid[i];i++);
        if(bookid[i]=='\0'&&st[i]=='\0')
        {
            cont++;
            if(x==1)
            {
                qty--;
            }
            else
            {
                qty++;
            }
            intf.seekp(intf.tellp()-sizeof(*this));
            intf.write((char*)this,sizeof(*this));
            break;
        }
        intf.read((char*)this,sizeof(*this));
    }
    if(cont==0)
    {
        cout<<"\n\t\tBook not found.\n";
        cout<<"\n\n\t\tPress any key to continue.....";
        //getch();
        system("cls");
        issue();
    }
    intf.close();
}

//***********Main Login Pannel******
void lib::info()
{
   int i;
        cout<<"\n\t*********** LIBRARY MANAGEMENT SYSTEM ***********\n"<<"\n\t\t\t    L M S C++\n";
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
            //getch();
            system("CLS");
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
                //getch();
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
    //ch=getch();
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
        //getch();
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
        cout<<"\n\t\t1.Display BookList\n\n\t\t2.Search Book\n\n\t\t3.Modify Book\n\n\t\t4.Issue Book\n\n\t\t5.Go to main menu\n\n\t\t6.Change Password\n\n\t\t7.Close Application\n";
        cout<<"\n\t\tEnter your choice : ";
        cin>>i;
        switch(i)
        {
            case 1:list(2);
                     break;
            case 2:search(2);
                     break;
            case 3:modify();
                     break;
            case 4:issue();
                     break;
            case 5:system("cls");
                     info();
                     break;
            case 6:password();
                    break;
            case 7:exit(0);
            default:cout<<"\n\t\t###Incorrect Input###";
            //getch();
            system("cls");
            librarian();
        }
}

//**********Change Password**********
void lib::password()
{
    int i=0,j=0;
    char ch,st[21],ch1[21]={"pass"};
    system("cls");
    cout<<"\n\n\t\tEnter Old Password : ";
    while(1)
    {
    //ch=getch();
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
    ifstream intf("password.txt");
    intf>>ch1;
    intf.close();
    for(i=0;st[i]==ch1[i]&&st[i]!='\0'&&ch1[i]!='\0';i++);
    if(st[i]=='\0'&&ch1[i]=='\0')
    {
        system("cls");
        cout<<"\n\t**The Password Should be less than 20 characters & don't use spaces**\n\n";
        cout<<"\n\t\tEnter New Password : ";
        fflush(stdin);
        i=0;
        while(1)
        {
        j++;
        //ch=getch();
        if(ch==13)
        {
            for(i=0;st[i]!=' '&&st[i]!='\0';i++);
            if(j>20 || st[i]==' ')
            {
                cout<<"\n\n\t\tYou did't follow the instruction \n\n\t\tPress any key for try again.....";
                //getch();
                system("cls");
                password();
                librarian();
            }
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
        ofstream outf("password.txt");
        outf<<st;
        outf.close();
        cout<<"\n\n\t\tYour Password has been changed Successfully.";
        cout<<"\n\t\tPress any key to continue......";
        //getch();
        system("cls");
        librarian();
    }
    else
    {
        cout<<"\n\n\t\tPassword is incorrect.....\n";
        cout<<"\n\t\t1.Retry\n\t\t2.Menu";
	cout<<"\n\t\tEnter Option : ";
        cin>>i;
        if(i==1)
        {
        system("cls");
        password();
        }
        else
        {
            system("cls");
            librarian();
        }
    }
}
int main()
{
    lib obj;
    obj.info();
    //getch();
    return 0;
}
