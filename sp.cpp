#include <fstream>
#include<string>
#include<iostream>
#include <windows.h>

using namespace std;
class store
{
    protected:
    int price;
    int code;
    int quantity;
    string name;
    public:
    int menu();
};
class buyer:public store
{

    public :
        void addcart();//
        void removecart();//
        void seecart();//
        void seelist();/////
        void buyremenu();////
        void recept();///
};
class owner : public store
{
public:

    void addp();
    void removep();
    void editp();
  //  void adddis();
    void ownermenu();
};
void owner::ownermenu()
{
    n:
        system("cls");
          system("Color 0C");

    string id,did="kavan@mail.com",pass,dpass="kavan_2003";
    cout <<"ENTER LOGIN ID:->";
    cin>>id;
    cout<<"ENTER PASSWORD:->";
    cin>>pass;
    if (pass==dpass&id==did)
    {
        p:
            buyer z;
                system("cls");
                            z.seelist();

           //   system("Color 0C");
        m:
     cout<<"_____________________________________\n";
     cout<<"|                                   |\n";
     cout<<"|           WELCOME OWNER           |\n";
     cout<<"|                                   |\n";
     cout<<"_____________________________________\n";
     cout <<"enter 1 for adding product"<<endl;
    cout <<"enter 2 for removing product"<<endl;
    cout <<"enter 3 for editing product"<<endl;
    cout <<"enter 4 to exit"<<endl;
        cout <<"\n\t\tENTER CHOICE:";
    int choice;
    cin>>choice;
    switch (choice)
{
    case 1:
    {
        addp();
        goto m;
    }
    break;
case 2:
    {
        removep();
        goto m;
    }
    break;
case 3:
    {
        editp();
        goto m;
    }
    break;
case 4:
    exit(0);
default:
 {
        cout<<"invalid choice"<<endl;
        goto p;
 }
}

    }
    else if (pass!=dpass||id!=did)
    {
        cout<<"\nLOGIN ERROR\n";
        goto n;
    }
}
void buyer::buyremenu()
{
    m:
    seelist();
          system("Color 0B");
     cout<<"_____________________________________\n";
     cout<<"|                                   |\n";
     cout<<"|           WELCOME BUYER           |\n";
     cout<<"|                                   |\n";
     cout<<"_____________________________________\n";
     cout <<"enter 1 for adding product to cart"<<endl;
    cout <<"enter 2 for removing product from cart"<<endl;
    cout <<"enter 3 to see the cart list"<<endl;
    cout<< "enter 4 to exit";
    cout <<"\n\t\tENTER CHOICE:";
    int choice;
    cin>>choice;
    switch (choice)
    {
    case 1:
            {
            addcart();
            goto m;
            }
        break ;
    case 2:
        {
            removecart();
            goto m;
        }
        break;
    case 3:
        {
            seecart();
            cout<<"\nenter yes to go back to menu-->"<<endl;
            cout<<"enter buy to print recept-->";
            string s1;
            cin>>s1;
            if (s1=="yes")
                goto m;
            if (s1=="buy")
                recept();
        }
        break;
    case 4:
        exit(0);
        break;
    default:
        cout << "invalid choice";
        goto m;

    }

}
int  store::menu()
{
        m:
             COORD c;
    c.X = 40;
    c.Y = 16;
     SetConsoleCursorPosition(
        GetStdHandle(STD_OUTPUT_HANDLE), c);

        system("cls");
        system("color 09");

    int choice;
     cout<<"_____________________________________\n";
     cout<<"|                                   |\n";
     cout<<"|            Shopping Menu          |\n";
     cout<<"|                                   |\n";
     cout<<"_____________________________________\n";
     cout<<"Enter 1. for owner \n";
     cout<<"Enter 2. for buyer \n";
     cout<<"Enter 3. for exit   \n";
     cout<<"\n\t\tchoice:";
     cin >>choice;
         switch (choice)
{

    case 1:
        {
        owner o2;
        o2.ownermenu();
        }
    break;
    case 2:
        {
        buyer b2;
           b2.buyremenu();
        }
        break;
    case 3:
    return 0;
    break;
    default:
    {
     cout << "\t\tEnter a valid choice\n";
     goto m;
    }
}
return 0;

}
void owner ::addp()
{
    system("cls");

        m:
        cout<<"Enter product code:";
        cin>>code;
        cout<<"Enter product name:";
        cin>>name;
        cout<<"Enter product price:";
        cin>>price;
        cout<<"Enter quantity :";
        cin>>quantity;
        fstream data;
        data.open("menu.txt",ios::app|ios::out);
        data<<" \n"<<code<<" \t"<<name<<"\t "<<price<<" \t"<<quantity;
        data.close();
        cout<<"Do you want add another product YES / NO enter:-";
        string str;
        cin >>str;
        if(str=="yes")
            goto m;
}

void buyer::seelist()
{
   // system("color 0E");
    system("cls");
        int coun=0;
    fstream infile;
    infile.open("menu.txt",ios::in);
     cout<<"|___________________________________|\n";
     cout<<"|                                   |\n";
     cout<<"|                 MENU              |\n";
     cout<<"|                                   |\n";
     cout<<"|___________________________________|\n";
     cout <<"CODE\tNAME\tPRICE\tQUANTITY(grams/ml)";
  while(!infile.eof())
        {
            coun++;
                      infile>>code>>name>>price>>quantity;

            cout<<" \n"<<code<<" \t"<<name<<"\t "<<price<<" \t"<<quantity;

        }
        infile.close();
        cout <<endl;
}

void owner :: removep()
{
        system("cls");

    cout << "\nENTER THE CODE OF PRODUCT TO BE REMOVED:";
    int code2;
    cin>>code2;
        int coun=0;
    fstream infile;
    fstream of;
      infile.open("menu.txt",ios::in);
      of.open("menu2.txt",ios::out);
  while(!infile.eof())
        {
            coun++;
                      infile>>code>>name>>price>>quantity;
                      if (code!=code2)
            of<<" \n"<<code<<" \t"<<name<<"\t "<<price<<" \t"<<quantity;
        }
        infile.close();
        of.close();
        remove("menu.txt");
        rename("menu2.txt", "menu.txt");

}
void owner ::editp()
{
       //    system("cls");

    cout << "\nENTER THE CODE OF PRODUCT TO BE EDITED";
    int code2;
    cin>>code2;
        int coun=0;
    fstream infile;
    fstream of;
      infile.open("menu.txt",ios::in);
      of.open("menu2.txt",ios::out);
  while(!infile.eof())
        {
            coun++;
                      infile>>code>>name>>price>>quantity;
                      if (code!=code2)
            of<<" \n"<<code<<" \t"<<name<<"\t "<<price<<" \t"<<quantity;
                   else
                    {
        cout<<"Enter product name:";
        cin>>name;
        cout<<"Enter product price:";
        cin>>price;
        cout<<"Enter quantity :";
        cin>>quantity;
        of<<" \n"<<code<<" \t"<<name<<"\t "<<price<<" \t"<<quantity;                    }
        }
        infile.close();
        of.close();
        remove("menu.txt");
        rename("menu2.txt", "menu.txt");

}

void buyer :: addcart()
{
        m:
    seelist();
  cout <<"\nENTER CODE OF PRODUCT YOU WANT TO BUY";
  int cno;
  cin>>cno;
   fstream infile;
    fstream of;
      infile.open("menu.txt",ios::in);
      of.open("cart.txt",ios::app|ios::out);
  while(!infile.eof())
        {
          infile>>code>>name>>price>>quantity;
          if (code== cno)
            {
                of<<" \n"<<code<<" \t"<<name<<"\t "<<price<<" \t"<<quantity;

            }
        }
        cout<<"DO YOU WANT TO ADD ANOTHER PRODUCT TO CART yes/no::";
        string s;
        cin>>s;
        if (s=="yes")
        goto m;
        infile.close();
        of.close();

}
void buyer::seecart()
{
    system("cls");
            int coun=0;
    fstream infile;
    infile.open("cart.txt",ios::in);
     cout<<"\n|___________________________________|\n";
     cout<<"|                                   |\n";
     cout<<"|            cart list              |\n";
     cout<<"|                                   |\n";
     cout<<"|___________________________________|\n";
     cout <<"CODE\tNAME\tPRICE\tQUANTITY(grams/ml)";
  while(!infile.eof())
        {
            coun++;
                      infile>>code>>name>>price>>quantity;

            cout<<" \n"<<code<<" \t"<<name<<"\t "<<price<<" \t"<<quantity;
         //   cout<<"\n"<<price<<endl;
          //  pricetotal=pricetotal+price;
        }
        infile.close();
     //  cout<<"\nYOUR TOTAL BILLING AMOUNT IS="<<pricetotal<<endl;
       // cout << "DO YOU WANT TO C";

}
void buyer::recept()
{
      system("cls");
      //int price=0;
      int pricetotal=0;
      double gst;
     fstream infile;
     cout <<"**************************************************\n";
     cout <<"**************************************************\n";
     cout <<"                     RECEPT                       \n";
     cout <<"**************************************************\n";
     cout <<"**************************************************\n";
     cout <<" CODE\t  NAME\t  PRICE\t  QUANTITY(grams/ml)";

    infile.open("cart.txt",ios::in);

     while(!infile.eof())
        {
           // coun++;
                      infile>>code>>name>>price>>quantity;

            cout<<" \n  "<<code<<" \t  "<<name<<"\t   "<<price<<" \t  "<<quantity;
         //   cout<<"\n"<<price<<endl;
            pricetotal=pricetotal+price;
        }
        infile.close();
        gst=(18*pricetotal)/100.00;
         cout<<"\nYOUR TOTAL price="<<pricetotal<<endl;
         cout <<"\n\tGST(18%)=="<<gst<<endl;
         cout<<"\nYOUR TOTAL PAYBLE AMOUNT="<<pricetotal+gst<<endl;
}
void buyer::removecart()
{
    seecart();
     cout << "\nENTER THE CODE OF PRODUCT TO BE REMOVED";
    int code2;
    cin>>code2;
        int coun=0;
    fstream infile;
    fstream of;
      infile.open("cart.txt",ios::in);
      of.open("menu2.txt",ios::out);
  while(!infile.eof())
        {
            coun++;
                      infile>>code>>name>>price>>quantity;
                      if (code!=code2)
            of<<" \n"<<code<<" \t"<<name<<"\t "<<price<<" \t"<<quantity;
        }
        infile.close();
        of.close();
        remove("cart.txt");
        rename("menu2.txt", "cart.txt");
}
int main ()
{



     //   system("Color 09");
    store s1;
    s1.menu();
   // owner o2;
   // o2.ownermenu();

    remove("cart.txt");
    return 0;
}
