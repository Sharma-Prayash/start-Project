#include<iostream>
#include<iomanip>
#include<string>
using namespace std;
class Bill
{
    public:
        string name;
        float mrp, dis_per, final_price;
        int qty;
}product[100];
int main()
{
    int i=0,c;
    float final_amount=0.0, amount_saved=0.0;
    string date;
    cout<<"Enter the date (format: dd-mm-yyyy): ";
    cin>>date;
//    cout<<"Enter the number of items customer has bought: ";
//    cin>>n;
//    Bill product[n];
    do
    {
        cout<<"Enter the name of the product: ";
        cin>>product[i].name;
        cout<<"Enter the MRP of the product: ";
        cin>>product[i].mrp;
        cout<<"Enter the Quantity of the product purchased: ";
        cin>>product[i].qty;
        cout<<"Enter the Discount (in percentage) if offered else enter 0: ";
        cin>>product[i].dis_per;
        product[i].final_price=(float)(product[i].mrp*product[i].qty)*((100-product[i].dis_per)/100);
        final_amount+=product[i].final_price;
        amount_saved+=(product[i].mrp*product[i].qty)*(product[i].dis_per/100);
        i++;
        cout<<"To add further more product(s) enter 1 else 0: ";
        cin>>c;
        system("cls");
    }while(c!=0);
    cout<<"-----------------------------------------------------------------------------------"<<endl;
    cout<<setw(35)<<""<<"ORPIT MART Pvt Ltd"<<endl;
    cout<<setw(30)<<""<<"SOBAL SHOPPING MALL, SOUTH BOPAL"<<endl;
    cout<<setw(38)<<""<<"GANDHINAGAR"<<endl;
    cout<<"==================================================================================="<<endl;
    cout<<setw(72)<<left<<"Bill_No:101"<<date<<endl;
    cout<<"==================================================================================="<<endl;
    cout<<setw(5)<<left<<"No."<<setw(17)<<left<<"Product Name"<<setw(15)<<right<<"Product-MRP"<<setw(12)<<right<<"Quantity"<<setw(17)<<right<<"Discount Per%"<<setw(15)<<right<<"Final Price"<<endl;
    cout<<"==================================================================================="<<endl;
    for(int j=0;j<i;j++)
    {
        cout<<setw(5)<<left<<(j+1)<<setw(17)<<left<<product[j].name<<setw(13)<<right<<product[j].mrp<<setw(11)<<right<<product[j].qty<<setw(13)<<right<<product[j].dis_per<<setw(22)<<right<<product[j].final_price<<endl;
    }
    cout<<"==================================================================================="<<endl;
    cout<<setw(56)<<""<<"TOTAL AMOUNT = "<<(final_amount+amount_saved)<<endl;
    cout<<setw(43)<<""<<"TOTAL AMOUNT SAVED ON MRP = "<<amount_saved<<endl;
    cout<<"==================================================================================="<<endl;
    cout<<setw(45)<<""<<"FINAL AMOUNT TO BE PAID = "<<final_amount<<endl;
    cout<<"==================================================================================="<<endl;
}
