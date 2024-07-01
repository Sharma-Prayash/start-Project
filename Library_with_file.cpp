#include<iostream>
#include<fstream>
#include<string>
#include<sstream>
#include<windows.h>

using namespace std;

class LibraryItem
{
    string author, title, year, line;
    public:
    virtual void addInfo(ofstream& fout, const string category)
    {
        cout<<"Enter the name of the author: ";
        cin.ignore();
        getline(cin, author);
        cout<<"Enter the title of the book: ";
        //cin.ignore();
        getline(cin, title);
        cout<<"Enter the year of publication: ";
        //cin.ignore();
        getline(cin, year);
        fout<<category<<","<<title<<","<<author<<","<<year<<",";
    }
    virtual void displayInfo(ifstream& fin, stringstream& ss)
    {
        //stringstream ss(line);
        getline(ss, title, ','); //title
        getline(ss, author, ','); //author
        getline(ss, year, ',');  //year
        cout<<"\nAuthor: "<<author<<"\nTitle: "<<title<<"\nYear: "<<year<<endl;
    }
    virtual ~LibraryItem(){}
};
class Book: public LibraryItem
{
    string genre, publisher, runtime, director, category, line, issueNumber;
    int pages;
    public:
    void addInfo(ofstream &fout)
    {
        category = "Book";
        LibraryItem::addInfo(fout, category);
        cout<<"Enter the publisher: ";
        //cin.ignore();  //to ignore the newline character left in the Buffer
        getline(cin, publisher);
        cout<<"Enter the genre: ";
        //cin.ignore();
        getline(cin, genre);
        cout<<"Enter the number of pages: ";
        cin>>pages;
        fout<<publisher<<","<<genre<<","<<"N.A."<<","<<pages<<","<<"N.A."<<","<<"N.A."<<endl;
    }
    void displayInfo(ifstream &fin) 
    {
        while(getline(fin, line))
        {
            stringstream ss(line);
            getline(ss, category, ',');
            if(category == "Book")
            {   
                LibraryItem::displayInfo(fin, ss);
                getline(ss, publisher, ','); //publisher
                getline(ss, genre, ','); //genre
                getline(ss, director, ','); //director
                ss>>pages; //pages
                getline(ss, issueNumber, ','); //issueNumber
                getline(ss, runtime, ','); //runtime
                cout<<"\nCategory: "<<category<<"\nPublisher/Studio: "<<publisher<<"\nGenre: "<<genre<<"\nDirector: "<<director<<"\nPages: "<<pages<<"\nissueNumber: "<<issueNumber<<"\nRuntime: "<<runtime<<endl;
            }
        }
    }
};
class DVD: public LibraryItem
{
    string genre, studio, director, category, line, issueNumber;
    int pages, runtime;
    public:
    void addInfo(ofstream &fout)
    {
        category = "DVD";
        LibraryItem::addInfo(fout, category);
        cout<<"Enter the director: ";
        //cin.ignore();
        getline(cin, director);
        cout<<"Enter the genre: ";
        //cin.ignore();
        getline(cin, genre);
        cout<<"Enter the studio: ";
        //cin.ignore();
        getline(cin, studio);
        cout<<"Enter the runtime: ";
        cin>>runtime;
        fout<<studio<<","<<genre<<","<<director<<","<<"N.A."<<","<<"N.A."<<","<<runtime<<endl;
    }
    void displayInfo(ifstream &fin) 
    {
        while(getline(fin, line))
        {
            stringstream ss(line);
            getline(ss, category, ',');
            if(category == "DVD")
             {
                LibraryItem::displayInfo(fin, ss);
                getline(ss, studio, ','); //publisher
                getline(ss, genre, ','); //genre
                getline(ss, director, ','); //director
                ss>>pages; //pages
                getline(ss, issueNumber, ','); //issueNumber
                ss>>runtime; //runtime
                cout<<"\nCategory: "<<category<<"\nPublisher/Studio: "<<studio<<"\nGenre: "<<genre<<"\nDirector: "<<director<<"\nPages: "<<pages<<"\nissueNumber: "<<issueNumber<<"\nRuntime: "<<runtime<<endl;
            }
        }
    }
};
class Magazine: public LibraryItem
{
    string genre, publisher, runtime, director, category, line;
    int pages, issueNumber;
    public:
    void addInfo(ofstream& fout)
    {
        category = "Magazine";
        LibraryItem::addInfo(fout, category);
        cout<<"Enter the publisher: ";
        //cin.ignore();  //to ignore the newline character left in the Buffer
        getline(cin, publisher);
        cout<<"Enter the issue number: ";
        cin>>issueNumber;
        fout<<publisher<<","<<"N.A."<<","<<"N.A."<<","<<"N.A."<<","<<issueNumber<<","<<"N.A."<<endl;
    }
    void displayInfo(ifstream &fin) 
    {

        while(getline(fin, line))
        {
            stringstream ss(line);
            getline(ss, category, ',');
            if(category == "Magazine")
             {
                LibraryItem::displayInfo(fin, ss);
                getline(ss, publisher, ','); //publisher
                getline(ss, genre, ','); //genre
                getline(ss, director, ','); //director
                ss>>pages; //pages
                ss>>issueNumber; //issueNumber
                getline(ss, runtime, ','); //runtime
                cout<<"\nCategory: "<<category<<"\nPublisher/Studio: "<<publisher<<"\nGenre: "<<genre<<"\nDirector: "<<director<<"\nPages: "<<pages<<"\nissueNumber: "<<issueNumber<<"\nRuntime: "<<runtime<<endl;
            }
        }
    }
};
int main()
{
    int choice;
    Book book;
    Magazine magazine;
    DVD dvd;
    ofstream fout("d:/Library.csv", ios::app);
    fout<<"Category"<<","<<"Title"<<","<<"Author"<<","<<"Year"<<","<<"Publisher/Studio"<<","<<"Genre"<<","<<"Director"<<","<<"Pages"<<","<<"issueNumber"<<","<<"Runtime"<<endl;
    fout.close();
    do
    {
        cout << "1. Add a book\n2. Add a DVD\n3. Add a Magazine\n4. Display the Book(s) record\n5. Display the DVD(s) record\n6. Display the Magazine(s) record\n0. To terminate the program" << endl;
        cin>>choice;
        switch(choice)
        {
            case 1:
            {
                ofstream fout("d:/Library.csv",ios::app);
                book.addInfo(fout);
                fout.close();
            }
            break;
            case 2:
            {
                ofstream fout("d:/Library.csv",ios::app);
                dvd.addInfo(fout);
                fout.close();
            }
            break;
            case 3:
            {
                ofstream fout("d:/Library.csv",ios::app);
                magazine.addInfo(fout);
                fout.close();
            }
            break;
            case 4:
            {
                ifstream fin("d:/Library.csv");
                if(!fin){
                    cout<<"Error in opening the file...."<<endl;
                    choice = 0;
                    break;
                }
                book.displayInfo(fin);
                fin.close();
            }
            break;
            case 5:
            {
                ifstream fin("d:/Library.csv");
                if(!fin){
                    cout<<"Error in opening the file...."<<endl;
                    choice = 0;
                    break;
                }
                dvd.displayInfo(fin);
                fin.close();
            }
            break;
            case 6:
            {
                ifstream fin("d:/Library.csv");
                if(!fin){
                    cout<<"Error in opening the file...."<<endl;
                    choice = 0;
                    break;
                }
                magazine.displayInfo(fin);
                fin.close();
            }
            break;
            case 0:
                cout<<"Terminating...";
                Sleep(1000);
        }
    }while(choice!=0);
}