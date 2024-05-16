#include<stdio.h>
#include<string.h>
#include<conio.h>
//---------------STRUCTURE------------------------------------------------------
struct Employee
{
    char name[50];
    int id;
    float sal;
    char dep[50];
}emp[10];
//-------------------MAIN FUNCTION----------------------------------------------------
void main()
{
    int n=0,i;
    for( ; ; )
   {
      printf("\nEnter the choice as:\n 1-Add Details\n 2-Search Record\n 3-Modify the record\n 4-Delete record\n 5-Display all the Employee details\n 6-Display Employee with highest salary\n 7-Exit from application\n");
      scanf("%d",&n);
      if(n==7)
      {
          printf("\nYou are now exit from the application");
          break;
      }
      switch(n)
      {
//----------------------------------ADD THE EMPLOYEE RECORD-------------------------------------------------------
         case 1:
             loop:
             for(i=0;i<10;i++)
                {
                    if(emp[i].id==0)
                      break;
                }
                if(i==10)
                    printf("\nDirectory is full\n");
                else
                {
                    fflush(stdin);
                    printf("\nEnter the Name, Department, Employee I_d and Salary\n");
                      gets((emp[i]).name);
                      gets((emp[i]).dep);
                      scanf("%d",&(emp[i]).id);
                      scanf("%f",&(emp[i]).sal);
                }
                int v=0;
                if(i<9)
                {
                    printf("\nEnter 1 to add further more Employees details otherwise enter 0 to exit from this process\n");
                    scanf("%d",&v);
                    if(v==1&&i!=10)
                    goto loop;
                }
             break;
//-----------------------------------SEARCH FOR THE EMPLOYEE RECORD-------------------------------------------------
         case 2:
             printf("\nEnter the Employee I_d for the employee to be searched\n");
             int tid;
            scanf("%d",&tid);
            for(i=0;i<10;i++)
                if(((emp[i]).id)==tid)
                    break;
            if(i==10)
                printf("\nRecord Not Present\n");
            else
            printf("\nRecord Present\n");
            break;
//-------------------------------------MODIFY THE EMPLOYEE RECORD-----------------------------------------------------
         case 3:
            printf("\nEnter the employee id which is to be modified\n");
            int t;
            scanf("%d",&t);
            for(i=0;i<10;i++)
            {
                if(t==emp[i].id)
                {
                    int n;
                    for(;;)
                    {
                        printf("\nEnter the number from the following to perform the specific task\n 1-To modify the name\n 2-To modify the salary\n 3-To modify the department\n 4-To exit\n");
                        scanf("%d",&n);
                        if(n==4)
                            break;
                        switch(n)
                        {
//------------------------MODIFY THE NAME OF THE EMPLOYEE-----------------------------------------------------------
                        case 1:
                            fflush(stdin);
                            printf("\nEnter the name\n");
                            gets((emp[i]).name);
                            break;
//-----------------------MODIFY THE SALARY--------------------------------------------------------------------------
                        case 2:
                            printf("\nEnter the salary\n");
                            scanf("%f",&emp[i].sal);
                            break;
//------------------------MODIFY THE DEPARTMENT------------------------------------------------------------------------
                        case 3:
                            fflush(stdin);
                            printf("\nEnter the department\n");
                            gets(emp[i].dep);
                            break;
                         }
                    }
                    break;
                }
            }
            if(i==10)
                printf("\nRecord not present\n");
            break;
//-------------------------------DELETE THE EMPLOYEE RECORD---------------------------------------------------------
         case 4:
            printf("\nEnter the employee id to be deleted\n");
            int td;
            scanf("%d",&td);
            for(i=0;i<10;i++)
            {
                if(td==emp[i].id)
                {
                    for(int j=i;j<9;j++)
                    {
                        emp[j].id=emp[j+1].id;
                        emp[j].sal=emp[j+1].sal;
                       for(int k=0;k<50;k++)
                       {
                            emp[j].name[k]=emp[j+1].name[k];
                            emp[j].dep[k]=emp[j+1].dep[k];
                       }
                    }
                    emp[10].id=0;
                    emp[10].sal=0.0;
                    for(int k=0;k<50;k++)
                       {
                            emp[10].name[k]='\0';
                            emp[10].dep[k]='\0';
                       }
                    break;
                }
            }
            if(i==10)
                printf("\nRecord not present\n");
            break;
//-------------------------------PRINT THE EMPLOYEE RECORDS--------------------------------------------------------
         case 5:
            for(i=0;i<10;i++)
            {
                if(emp[i].sal!=0.0)
                {
                    printf("\nName: ");
                    puts(emp[i].name);
                    printf("\nDepartment: ");
                    puts(emp[i].dep);
                    printf("\nEmployee I_d: %d",emp[i].id);
                    printf("\nSalary: %0.2f\n",emp[i].sal);
                }
            }
            if(emp[0].sal==0.0)
                printf("\nRecord not present\n");
            break;
//-----------------------------EMPPLOYEE WITH HIGHEST SALARY-----------------------------------------------------
         case 6:
             i=0;
            int j;
            float h=0;
            for(i=0;i<10;i++)
            {
                if(emp[i].sal>h)
                {
                    h=emp[i].sal;
                    j=i;
                }
            }
            if(emp[0].sal==0.0)
                printf("\nRecord not present\n");
            else
            {
                printf("\nEmployee with highest salary is:\n");
                 printf("\nName: ");
                 puts(emp[j].name);
                 printf("\nDepartment: ");
                 puts(emp[j].dep);
                 printf("\nEmployee I_d: %d",emp[j].id);
                 printf("\nSalary: %f",emp[j].sal);
            }
            break;
      }
   }
}
