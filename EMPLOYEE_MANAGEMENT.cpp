#include<iostream>
#include<iomanip>
#include<string>
using namespace std;
class Employee
{
    public:
        string ename;
        long int eid;
        long int salary;
}emp[100];
int main()
{
    int ch,i=0,n,j,choice,k=0,ch1;
    long int eid,sal=0;
    string name;
    do
    {
        cout<<"---------------------------------"<<endl;
        cout<<setw(30)<<left<<"| 1-ADD n RECORDS"<<setw(2)<<right<<"|"<<endl;
        cout<<setw(30)<<left<<"| 2-DISPLAY ALL THE RECORDS"<<setw(2)<<right<<"|"<<endl;
        cout<<setw(30)<<left<<"| 3-SEARCH BY EMPLOYEE NUMBER"<<setw(2)<<right<<"|"<<endl;
        cout<<setw(30)<<left<<"| 4-SEARCH BY EMPLOYEE NAME"<<setw(2)<<right<<"|"<<endl;
        cout<<setw(30)<<left<<"| 5-UPDATE THE RECORD"<<setw(2)<<right<<"|"<<endl;
        cout<<setw(30)<<left<<"| 6-DELETE A RECORD"<<setw(2)<<right<<"|"<<endl;
        cout<<setw(30)<<left<<"| 7-FIND HIGHEST PAID EMPLOYEE"<<setw(2)<<right<<"|"<<endl;
        cout<<setw(30)<<left<<"| 0-EXIT"<<setw(2)<<right<<"|"<<endl;
        cout<<"---------------------------------"<<endl;
        cout<<"Enter the choice from the given menu: ";
        cin>>ch;
        system("cls");
        switch(ch)
        {
        case 1:
            {
                cout<<"ENTER THE NUMBER OF EMPLOYEES WHOSE RECORD HAS TO BE ENTERED: ";
                cin>>n;
                for(j=1;j<=n;j++,i++)
                {
                    cout<<"ENTER THE NAME OF THE EMPLOYEE "<<(i+1)<<": ";
                    cin>>emp[i].ename;
                    cout<<"ENTER THE EMPLOYEE ID: ";
                    cin>>emp[i].eid;
                    cout<<"ENTER THE EMPLOYEE's SALARY: ";
                    cin>>emp[i].salary;
                    system("cls");
                }
            }
            break;
        case 2:
            {
                if(i==0)
                {
                    cout<<"THE FIELD IS EMPTY\nFIRST ENTER THE RECORD"<<endl;
                    break;
                }
                for(j=0;j<i;j++)
                {
                    cout<<"RECORD OF EMPLOYEE "<<(j+1)<<": "<<endl;
                    cout<<left<<setw(13)<<"NAME: "<<emp[j].ename<<endl;
                    cout<<left<<setw(13)<<"EMPLOYEE ID: "<<emp[j].eid<<endl;
                    cout<<left<<setw(13)<<"SALARY: "<<emp[j].salary<<endl<<endl;
                    cout<<"----------------------------"<<endl;
                }
            }
            break;
        case 3:
            {
                if(i==0)
                {
                    cout<<"THE FIELD IS EMPTY\nFIRST ENTER THE RECORD"<<endl;
                    break;
                }
                cout<<"ENTER THE EMPLOYEE's ID WHOM YOU WANT TO SEARCH: ";
                cin>>eid;
                for(j=0;j<i;j++)
                {
                    if(emp[j].eid==eid)
                    {
                        cout<<"----------------------------"<<endl;
                        cout<<left<<setw(13)<<"NAME: "<<emp[j].ename<<endl;
                        cout<<left<<setw(13)<<"EMPLOYEE ID: "<<emp[j].eid<<endl;
                        cout<<left<<setw(13)<<"SALARY: "<<emp[j].salary<<endl;
                        cout<<"----------------------------"<<endl;;
                        break;
                    }
                }
                if(j==i)
                    cout<<"RECORD NOT PRESENT"<<endl;
            }
            break;
        case 4:
            {
                if(i==0)
                {
                    cout<<"THE FIELD IS EMPTY\nPLEASE ENTER THE RECORD FIRST"<<endl;
                    break;
                }
                cout<<"ENTER THE NAME OF THE EMPLOYEE WHOM YOU WANT TO SEARCH: ";
                cin>>name;
                for(j=0;j<i;j++)
                {
                    if(name.compare(emp[j].ename)==0)
                    {
                        cout<<"----------------------------"<<endl;
                        cout<<left<<setw(13)<<"NAME: "<<emp[j].ename<<endl;
                        cout<<left<<setw(13)<<"EMPLOYEE ID: "<<emp[j].eid<<endl;
                        cout<<left<<setw(13)<<"SALARY: "<<emp[j].salary<<endl;
                        cout<<"----------------------------"<<endl;
                        break;
                    }
                }
                if(j==i)
                    cout<<"RECORD NOT PRESENT"<<endl;
            }
            break;
        case 5:
            {
                if(i==0)
                {
                    cout<<"THE FIELD IS EMPTY\nFIRST ENTER THE RECORD"<<endl;
                    break;
                }
                do
                {
                    cout<<"--------------------------------------------"<<endl;
                    cout<<setw(42)<<left<<"| 1-TO UPDATE BY SEARCHING THE NAME"<<setw(2)<<right<<"|"<<endl;
                    cout<<setw(42)<<left<<"| 2-TO UPDATE BY SEARCHING THE EMPLOYEE ID"<<setw(2)<<right<<"|"<<endl;
                    cout<<setw(42)<<left<<"| 0-TO END THIS TASK"<<setw(2)<<right<<"|"<<endl;
                    cout<<"--------------------------------------------"<<endl;
                    cout<<"ENTER YOU CHOICE FROM THE ABOVE LIST: ";
                    cin>>choice;
                    system("cls");
                    switch(choice)
                    {
                    case 1:
                        {
                            cout<<"ENTER THE NAME OF THE EMPLOYEE WHOSE RECORD HAS TO UPDATED: ";
                            cin>>name;
                            for(j=0;j<i;j++)
                            {
                                if(name.compare(emp[j].ename)==0)
                                {
                                    do
                                    {
                                        cout<<"1-TO UPDATE NAME"<<endl;
                                        cout<<"2-TO UPDATE SALARY"<<endl;
                                        cout<<"0-TO END TASK"<<endl;
                                        cout<<"ENTER YOUR CHOICE FROM THE MENU ABOVE: ";
                                        cin>>ch1;
                                        system("cls");
                                        switch(ch1)
                                        {
                                        case 1:
                                            {
                                                cout<<"ENTER THE UPDATED NAME OF THIS EMPLOYEE: ";
                                                cin>>emp[j].ename;
                                            }
                                            break;
                                        case 2:
                                            {
                                                cout<<"ENTER THE UPDATED SALARY OF THIS EMPLOYEE: ";
                                                cin>>emp[j].salary;
                                            }
                                        }
                                    }while(ch1!=0);
                                    break;
                                }
                            }
                            if(j==i)
                                cout<<"WRONG INPUT\nTRY AGAIN"<<endl;
                        }
                        break;
                    case 2:
                        {
                            cout<<"ENTER THE ID OF THE EMPLOYEE WHOSE RECORD HAS TO UPDATED: ";
                            cin>>eid;
                            for(j=0;j<i;j++)
                            {
                                if(eid==emp[j].eid)
                                {
                                    do
                                    {
                                        cout<<"1-TO UPDATE NAME"<<endl;
                                        cout<<"2-TO UPDATE SALARY"<<endl;
                                        cout<<"0-TO END TASK"<<endl;
                                        cout<<"ENTER YOUR CHOICE FROM THE MENU ABOVE: ";
                                        cin>>ch1;
                                        system("cls");
                                        switch(ch1)
                                        {
                                        case 1:
                                            {
                                                cout<<"ENTER THE UPDATED NAME OF THIS EMPLOYEE: ";
                                                cin>>emp[j].ename;
                                            }
                                            break;
                                        case 2:
                                            {
                                                cout<<"ENTER THE UPDATED SALARY OF THIS EMPLOYEE: ";
                                                cin>>emp[j].salary;
                                            }
                                        }
                                    }while(ch1!=0);
                                    break;
                                }
                            }
                            if(j==i)
                                cout<<"WRONG INPUT\nTRY AGAIN"<<endl;
                        }
                    }
                }while(choice!=0);
            }
            break;
        case 6:
            {
                if(i==0)
                {
                    cout<<"THE FIELD IS EMPTY\nENTER THE RECORD FIRST"<<endl;
                    break;
                }
                do
                {
                    cout<<"---------------------------------------------------------"<<endl;
                    cout<<setw(55)<<left<<"| 1-TO DELETE THE EMPLOYEE RECORD BY SEARCHING ITS NAME"<<setw(2)<<right<<"|"<<endl;
                    cout<<setw(55)<<left<<"| 2-TO DELETE THE EMPLOYEE RECORD BY SEARCHING ITS ID"<<setw(2)<<right<<"|"<<endl;
                    cout<<setw(55)<<left<<"| 0-TO END THIS TASK"<<setw(2)<<right<<"|"<<endl;
                    cout<<"---------------------------------------------------------"<<endl;
                    cout<<"ENTER YOU CHOICE FROM THE ABOVE LIST: ";
                    cin>>choice;
                    system("cls");
                    k=0;
                    switch(choice)
                    {
                    case 1:
                        {
                            cout<<"ENTER THE EMPLOYEE NAME WHOSE RECORD HAS TO BE DELETED: ";
                            cin>>name;
                            for(j=0;j<(i-1);j++)
                            {
                                if(name.compare(emp[j].ename)==0 || k==1)
                                {
                                    k=1;
                                    emp[j].ename=emp[j+1].ename;
                                    emp[j].eid=emp[j+1].eid;
                                    emp[j].salary=emp[j+1].salary;
                                }
                            }
                            if(k==1 || (name.compare(emp[j].ename)==0))
                            {
                                i--;
                                cout<<"RECORD HAS BEEN DELETED"<<endl;
                            }
                            else
                                cout<<"WRONG ENTRY"<<endl;
                        }
                        break;
                    case 2:
                        {
                            cout<<"ENTER THE EMPLOYEE ID WHOSE RECORD HAS TO BE DELETED: ";
                            cin>>eid;
                            for(j=0;j<(i-1);j++)
                            {
                                if(eid==emp[j].eid || k==1)
                                {
                                    k=1;
                                    emp[j].ename=emp[j+1].ename;
                                    emp[j].eid=emp[j+1].eid;
                                    emp[j].salary=emp[j+1].salary;
                                }
                            }
                            if(k==1 || eid==emp[j].eid)
                            {
                                i--;
                                cout<<"RECORD HAS BEEN DELETED"<<endl;
                            }
                            else
                                cout<<"WRONG ENTRY"<<endl;
                        }
                    }
                }while(choice!=0);
            }
            break;
        case 7:
            {
                if(i==0)
                {
                    cout<<"THE FIELD IS EMPTY\nENTER THE RECORD FIRST"<<endl;
                    break;
                }
                sal=emp[0].salary;
                for(j=0;j<i;j++)
                {
                    if(sal<emp[j].salary)
                    {
                        sal=emp[j].salary;
                        k=j;
                    }
                }
                cout<<"HIGHEST PAID EMPLOYEE IS:"<<endl;
                cout<<"----------------------------"<<endl;
                cout<<left<<setw(13)<<"NAME: "<<emp[k].ename<<endl;
                cout<<left<<setw(13)<<"EMPLOYEE ID: "<<emp[k].eid<<endl;
                cout<<left<<setw(13)<<"SALARY: "<<emp[k].salary<<endl;
                cout<<"----------------------------"<<endl;
            }
            break;
        }
    }while(ch!=0);
}
