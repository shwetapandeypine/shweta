#include<fstream>
#include<conio.h>
#include<stdio.h>
#include<process.h>
#include<string.h>
#include<iomanip>
#include<iostream>

using namespace std;



class book
{
	char bookid[6];
	char bookname[50];
	char author[20];
  public:
	void add_book()
	{
        cout<<"\nNEW BOOK ENTRY...\n";
        cout<<"\nEnter The book no.";
        cin>>bookid;
        cout<<"\n\nEnter The Name of The Book ";
        gets(bookname);
        cout<<"\n\nEnter The Author's Name ";
        gets(author);
        cout<<"\n\n\nBook Added..";
    }

    void show_book()
    {
        cout<<"\nBook no. : "<<bookid;
        cout<<"\nBook Name : ";
        puts(bookname);
        cout<<"Author Name : ";
        puts(author);
    }

    void modify_book()
    {
        cout<<"\nBook no. : "<<bookid;
        cout<<"\nModify Book Name : ";
        gets(bookname);
        cout<<"\nModify Author's Name of Book : ";
        gets(author);
    }

    char* return_bookid()
    {
        return bookid;
    }

    void report()
    {cout<<bookid<<setw(30)<<bookname<<setw(30)<<author<<endl;}


};




class student
{
    char regno[6];
    char studentname[20];
    char studentbookid[6];
    int token;
public:
    void add_student()
    {
        system("cls");
         cout<<"\nNEW STUDENT ENTRY...\n";
        cout<<"\nEnter The registration no. ";
        cin>>regno;
        cout<<"\n\nEnter The Name of The Student ";
        gets(studentname);
        token=0;
        studentbookid[0]='/0';
        cout<<"\n\nStudent Record Added..";
    }

    void show_student()
    {
        cout<<"\nRegistration no. : "<<regno;
        cout<<"\nStudent Name : ";
        puts(studentname);
        cout<<"\nNo of Book issued : "<<token;
        if(token==1)
            cout<<"\nBook No "<<studentbookid;
    }

    void modify_student()
    {
        cout<<"\nRegistration no. : "<<regno;
        cout<<"\nModify Student Name : ";
        gets(studentname);
    }

    char* return_regno()
    {
        return regno;
    }

    char* return_studentbookid()
    {
        return studentbookid;
    }

    int return_token()
    {
        return token;
    }

    void addtoken()
    {token=1;}

    void resettoken()
    {token=0;}

    void getstudentbookid(char t[])
    {
        strcpy(studentbookid,t);
    }

    void report()
    {cout<<"\t"<<regno<<setw(20)<<studentname<<setw(10)<<token<<endl;}

};





fstream fp,fp1;
book bk;
student st;



//*********write in file*******************8

void write_book()
{
    char ch;
    fp.open("book.dat",ios::out|ios::app);
    do
    {
        system("cls");
        bk.add_book();
        fp.write((char*)&bk,sizeof(book));
        cout<<"\n\nDo you want to add more record..(y/n?)";
        cin>>ch;
    }while(ch=='y'||ch=='Y');
    fp.close();
}

void write_student()
{
    char ch;
    fp.open("student.dat",ios::out|ios::app);
    do
    {
        st.add_student();
        fp.write((char*)&st,sizeof(student));
        cout<<"\n\ndo you want to add more record..(y/n?)";
        cin>>ch;
    }while(ch=='y'||ch=='Y');
    fp.close();
}



//**********read specific record from file****************8



void display_specificbook(char n[])
{
    cout<<"\nBOOK DETAILS\n";
    int flag=0;
    fp.open("book.dat",ios::in);
    while(fp.read((char*)&bk,sizeof(book)))
    {
        if(strcmpi(bk.return_bookid(),n)==0)
        {
            bk.show_book();
             flag=1;
        }
    }

    fp.close();
    if(flag==0)
        cout<<"\n\nBook does not exist";
    getch();
}

void display_specificstudent(char n[])
{
    cout<<"\nSTUDENT DETAILS\n";
    int flag=0;
    fp.open("student.dat",ios::in);
    while(fp.read((char*)&st,sizeof(student)))
    {
        if((strcmpi(st.return_regno(),n)==0))
        {
            st.show_student();
            flag=1;
        }
    }

    fp.close();
    if(flag==0)
            cout<<"\n\nStudent does not exist";
     getch();
}


//***************modify record of file********************


void modify_book()
{
    char n[6];
    int found=0;
    system("cls");
    cout<<"\n\n\tMODIFY BOOK REOCORD.... ";
    cout<<"\n\n\tEnter The book ID of The book";
    cin>>n;
    fp.open("book.dat",ios::in|ios::out);
    while(fp.read((char*)&bk,sizeof(book)) && found==0)
    {
        if(strcmpi(bk.return_bookid(),n)==0)
        {
            bk.show_book();
            cout<<"\nEnter The New Details of book"<<endl;
            bk.modify_book();
            int pos=-1*sizeof(bk);
                fp.seekp(pos,ios::cur);
                fp.write((char*)&bk,sizeof(book));
                cout<<"\n\n\t Record Updated";
                found=1;
        }
    }

        fp.close();
        if(found==0)
            cout<<"\n\n Record Not Found ";
        getch();
}


void modify_student()
{
    char n[6];
    int found=0;
    system("cls");
    cout<<"\n\n\tMODIFY STUDENT RECORD... ";
    cout<<"\n\n\tEnter registration no. of The student";
    cin>>n;
    fp.open("student.dat",ios::in|ios::out);
    while(fp.read((char*)&st,sizeof(student)) && found==0)
    {
        if(strcmpi(st.return_regno(),n)==0)
        {
            st.show_student();
            cout<<"\nEnter The New Details of student"<<endl;
            st.modify_student();
            int pos=-1*sizeof(st);
            fp.seekp(pos,ios::cur);
            fp.write((char*)&st,sizeof(student));
            cout<<"\n\n\t Record Updated";
            found=1;
        }
    }

    fp.close();
    if(found==0)
        cout<<"\n\n Record Not Found ";
    getch();
}


//*************delete record of file******************



void delete_student()
{
    char n[6];
    int flag=0;
    system("cls");
        cout<<"\n\n\n\tDELETE STUDENT...";
        cout<<"\n\nEnter The registration no. of the Student You Want To Delete : ";
        cin>>n;
        fp.open("student.dat",ios::in|ios::out);
        fstream fp2;
        fp2.open("Temp.dat",ios::out);
        fp.seekg(0,ios::beg);
        while(fp.read((char*)&st,sizeof(student)))
    {
        if(strcmpi(st.return_regno(),n)!=0)
                 fp2.write((char*)&st,sizeof(student));
        else
               flag=1;
    }

    fp2.close();
        fp.close();
        remove("student.dat");
        rename("Temp.dat","student.dat");
        if(flag==1)
             cout<<"\n\n\tRecord Deleted ..";
        else
             cout<<"\n\nRecord not found";
        getch();
}


void delete_book()
{
    char n[6];
    system("cls");
    cout<<"\n\n\n\tDELETE BOOK ...";
    cout<<"\n\nEnter The Book ID of the Book You Want To Delete : ";
    cin>>n;
    fp.open("book.dat",ios::in|ios::out);
    fstream fp2;
    fp2.open("Temp.dat",ios::out);
    fp.seekg(0,ios::beg);
    while(fp.read((char*)&bk,sizeof(book)))
    {
        if(strcmpi(bk.return_bookid(),n)!=0)
        {
            fp2.write((char*)&bk,sizeof(book));
        }
    }

    fp2.close();
        fp.close();
        remove("book.dat");
        rename("Temp.dat","book.dat");
        cout<<"\n\n\tRecord Deleted ..";
        getch();
}




//************display all students list*****************


void display_allstudent()
{
    system("cls");
         fp.open("student.dat",ios::in);
         if(!fp)
         {
               cout<<"ERROR!!! FILE COULD NOT BE OPEN ";
               getch();
               return;
         }

    cout<<"\n\n\t\tSTUDENT LIST\n\n";

    cout<<"\tRegistration No."<<setw(10)<<"Name"<<setw(20)<<"Book Issued\n";


    while(fp.read((char*)&st,sizeof(student)))
    {
        st.report();
    }

    fp.close();
    getch();
}



//***********display Books list********************


void display_allbook()
{
    system("cls");
    fp.open("book.dat",ios::in);
    if(!fp)
    {
        cout<<"ERROR!!! FILE COULD NOT BE OPEN ";
               getch();
               return;
         }

    cout<<"\n\n\t\tBook LIST\n\n";

    cout<<"Book ID"<<setw(20)<<"Book Name"<<setw(25)<<"Author\n";


    while(fp.read((char*)&bk,sizeof(book)))
    {
        bk.report();
    }
         fp.close();
         getch();
}




//****************issue book************************

void book_issue()
{
    char sn[6],bn[6];
    int found=0,flag=0;
    system("cls");
    cout<<"\n\nBOOK ISSUE ...";
    cout<<"\n\n\tEnter The student's registration no.";
    cin>>sn;
    fp.open("student.dat",ios::in|ios::out);
        fp1.open("book.dat",ios::in|ios::out);
        while(fp.read((char*)&st,sizeof(student)) && found==0)
           {
        if(strcmpi(st.return_regno(),sn)==0)
        {
            found=1;
            if(st.return_token()==0)
            {
                      cout<<"\n\n\tEnter the book ID ";
                cin>>bn;
                while(fp1.read((char*)&bk,sizeof(book))&& flag==0)
                {
                       if(strcmpi(bk.return_bookid(),bn)==0)
                    {
                        bk.show_book();
                        flag=1;
                        st.addtoken();
                        st.getstudentbookid(bk.return_bookid());
                               int pos=-1*sizeof(st);
                        fp.seekp(pos,ios::cur);
                        fp.write((char*)&st,sizeof(student));
                        cout<<"\n\n\t Book issued successfully\n\nPlease Note: Write current date in backside of book and submit within 15 days fine Rs. 1 for each day after 15 days period";
                    }
                    }
                  if(flag==0)
                        cout<<"Book no does not exist";
            }
                else
                  cout<<"You have not returned the last book ";

        }
    }
          if(found==0)
        cout<<"Student record not exist...";
    getch();
      fp.close();
      fp1.close();
}


//**************deposit book*****************

void book_deposit()
{
    char sn[6],bn[6];
    int found=0,flag=0,day,fine;
    system("cls");
    cout<<"\n\nBOOK DEPOSIT ...";
    cout<<"\n\n\tEnter The student's registration no.";
    cin>>sn;
    fp.open("student.dat",ios::in|ios::out);
    fp1.open("book.dat",ios::in|ios::out);
    while(fp.read((char*)&st,sizeof(student)) && found==0)
       {
        if(strcmpi(st.return_regno(),sn)==0)
        {
            found=1;
            if(st.return_token()==1)
            {
            while(fp1.read((char*)&bk,sizeof(book))&& flag==0)
            {
               if(strcmpi(bk.return_bookid(),st.return_studentbookid())==0)
            {
                bk.show_book();
                flag=1;
                cout<<"\n\nBook deposited in no. of days";
                cin>>day;
                if(day>15)
                {
                   fine=(day-15)*1;
                   cout<<"\n\nFine has to deposited Rs. "<<fine;
                }
                    st.resettoken();
                    int pos=-1*sizeof(st);
                    fp.seekp(pos,ios::cur);
                    fp.write((char*)&st,sizeof(student));
                    cout<<"\n\n\t Book deposited successfully";
            }
            }
          if(flag==0)
            cout<<"Book no does not exist";
              }
         else
            cout<<"No book is issued..please check!!";
        }
       }
      if(found==0)
    cout<<"Student record not exist...";
    getch();
  fp.close();
  fp1.close();
  }









//***************admin******************


void admin_menu()
{
    system("cls");
    int ch2;
    cout<<"\n\n\n\tADMINISTRATOR MENU";
    cout<<"\n\n\t1.ADD STUDENT RECORD";
    cout<<"\n\n\t2.DISPLAY ALL STUDENTS RECORD";
    cout<<"\n\n\t3.DISPLAY SPECIFIC STUDENT RECORD ";
    cout<<"\n\n\t4.MODIFY STUDENT RECORD";
    cout<<"\n\n\t5.DELETE STUDENT RECORD";
    cout<<"\n\n\t6.ADD BOOK ";
    cout<<"\n\n\t7.DISPLAY ALL BOOKS ";
    cout<<"\n\n\t8.DISPLAY SPECIFIC BOOK ";
    cout<<"\n\n\t9.MODIFY BOOK ";
    cout<<"\n\n\t10.DELETE BOOK ";
    cout<<"\n\n\t11.BACK TO MAIN MENU";
    cout<<"\n\n\tPlease Enter Your Choice (1-11) ";
    cin>>ch2;
    switch(ch2)
    {
            case 1: system("cls");
                write_student();break;
            case 2: display_allstudent();break;
            case 3:
                   char num[6];
                   system("cls");
                   cout<<"\n\n\tPlease Enter The Registration No. ";
                   cin>>num;
                   display_specificstudent(num);
                   break;
              case 4: modify_student();break;
              case 5: delete_student();break;
        case 6: system("cls");
            write_book();break;
        case 7: display_allbook();break;
        case 8: {
                   char num[6];
                   system("cls");
                   cout<<"\n\n\tPlease Enter The book No. ";
                   cin>>num;
                   display_specificbook(num);
                   break;
            }
              case 9: modify_book();break;
              case 10: delete_book();break;
             case 11: return;
              default:cout<<"\a";
       }
       admin_menu();
}



//****************main()*****************



int main()
{
    char ch;
    cout<<"\n\t\t\tLIBRARY MANAGEMENT SYSTEM\n\n\n";
    do
    {
        system("cls");
        cout<<"\n\n\n\tMAIN MENU";
        cout<<"\n\n\t01. BOOK ISSUE";
        cout<<"\n\n\t02. BOOK DEPOSIT";
          cout<<"\n\n\t03. ADMINISTRATOR MENU";
          cout<<"\n\n\t04. EXIT";
          cout<<"\n\n\tPlease Select Your Option (1-4) ";
          ch=getche();
          switch(ch)
          {
            case '1':system("cls");
                 book_issue();
                    break;
              case '2':book_deposit();
                     break;
              case '3':admin_menu();
                 break;
              case '4':exit(0);
              default :cout<<"Invalid Input";
        }
        }while(ch!='4');
        return 0;
}

