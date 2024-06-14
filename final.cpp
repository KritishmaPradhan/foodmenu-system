#include <iostream>
#include <fstream>
#include <string.h>
#include <conio.h>
#include <cstdio>
#include <stdlib.h>
#include <ctime>
#include <windows.h>
#include <dos.h>
#include <graphics.h>
#include <unistd.h>
using namespace std;
struct r
{
    string dish, price;
    string uname = "admin";
    string up_w = "admin";
    int key;

} r;
class Resturant
{
public:
    void add_menu();
    void display();
    void update();
    void admin();
    void change(string);
    void introduction();
    void write_file(string, string);
    void delete_rest(string);
    void viewrecords();
    void viewfeedbacks();
};

void Resturant::write_file(string id, string dprice)
{
    string fln = id + ".txt";
    ofstream o;
    o.open(fln);
    o << id << "\t"
      << dprice;
    o.close();
    fstream obj;
    obj.open("resturant.txt", ios::app);
    obj << id << "\t"
        << dprice << endl;

    obj.close();
}

void Resturant::add_menu()
{
    char a;
    int k;
    string strname, dprice;

    do
    {

        cin.ignore();
        cout << "ENTER THE DISH NAME: ";
    jk:
        getline(cin, r.dish);
        strname = r.dish;
        string dname = strname + ".txt";
        ifstream file(dname);
        if (!file)
        {
            // cin.ignore();
            cout << "ENTER THE DISH PRICE: ";
            cin >> r.price;
            dprice = r.price;
            write_file(strname, dprice);

            cout << " Do you want to add an other [y/n]: ";
            cin >> a;
        }
        else
        {
            cout << "This dish already exist! " << endl;
            cout << "RE-ENTER THE DISH NAME: ";
            goto jk;
        }

    } while (a == 'y' || a == 'Y');
}

void Resturant::display()
{
    string data;
    string filename = "resturant.txt";
    ifstream file(filename);
    if (file.peek() == ifstream::traits_type::eof())
    {
        cout << "List is empty" << endl
             << "No Dish to display" << endl;
    }
    else
    {
        cout << "________________________" << endl;
        cout << "Dish\tPrice(Rs.) " << endl;
        cout << "________________________" << endl
             << endl;

        while (getline(file, data))
        {
            cout << data << endl
                 << endl;
        }
    }
    file.close();
}

void Resturant::change(string a)
{
    char b;
    string del = a + ".txt";
    const char *flnn = del.c_str();
    /*  if (remove(flnn) != 0)
       {
           cout << endl
                << "Error updating dish!!!" << endl
                << endl
                << endl;
           cout << "Press any key to continue." << endl;
           _getch();
       }
       else
       {
   */
    string filename = "resturant.txt";
    string searchId = a;

    ifstream inputFile(filename);

    string line;
    int lineNumber = 0;
    bool found = false;

    while (getline(inputFile, line))
    {
        lineNumber++;

        if (line.find(searchId) != string::npos)
        {
            found = true;
            break;
        }
    }

    inputFile.close();

    int lineToDelete = lineNumber;

    ifstream in(filename);

    ofstream tempFile("temp.txt");

    string linee;
    int lineNum = 0;

    while (getline(in, linee))
    {
        lineNum++;

        if (lineNum != lineToDelete)
        {
            tempFile << linee << endl;
        }
    }

    in.close();
    tempFile.close();

    remove(filename.c_str());
    rename("temp.txt", filename.c_str());
    cout << "Dish updated sucessfully!!" << endl;
    cout << "Press any key to continue." << endl;
    _getch();
}

void Resturant::delete_rest(string a)
{
    char b;
    string del = a + ".txt";

    const char *flnn = del.c_str();

    if (remove(flnn) != 0)
    {
        cout << endl
             << "Error deleting dish!!!" << endl
             << endl
             << endl;
        cout << "Press any key to continue." << endl;
        _getch();
    }
    else
    {

        string filename = "resturant.txt";
        string searchId = a;

        ifstream inputFile(filename);

        string line;
        int lineNumber = 0;
        bool found = false;

        while (getline(inputFile, line))
        {
            lineNumber++;

            if (line.find(searchId) != string::npos)
            {
                found = true;
                break;
            }
        }

        inputFile.close();

        int lineToDelete = lineNumber;

        ifstream in(filename);

        ofstream tempFile("temp.txt");

        string linee;
        int lineNum = 0;

        while (getline(in, linee))
        {
            lineNum++;

            if (lineNum != lineToDelete)
            {
                tempFile << linee << endl;
            }
        }

        in.close();
        tempFile.close();

        remove(filename.c_str());
        rename("temp.txt", filename.c_str());
        cout << "Dish deleted sucessfully!!" << endl;
        cout << "Press any key to continue." << endl;
        _getch();
    }
}

void Resturant::update()
{
    int p, c = 0;
    string a, d_name, data, tempt;
    fstream obj;

    cout << "Enter the dish name:";

    cin.ignore();
add:
    getline(cin, a);
    d_name = a + ".txt";
    ifstream file(d_name);
    if (!file)
    {
        cout << "Enter the correct dish !!!!" << endl;
        goto add;
    }
    else
        obj.open(d_name, ios::in | ios::out);

    cout << endl;
    cout << "Dish"
         << "\t"
         << "Price" << endl;
    while (getline(obj, data))
    {
        cout << data << endl
             << endl;
    }
    obj.close();
    // cin.ignore();
    cout << "ENTER THE NEW PRICE:";
    cin >> r.price;
    tempt = r.price;

    change(a);
    write_file(a, tempt);
}

void Resturant::viewrecords()
{
    string data;
    string filename = "record.txt";
    ifstream file(filename);
    if (file.peek() == ifstream::traits_type::eof())
    {
        cout << "No Record to show." << endl;
    }
    else
    {
        cout << endl
             << endl;
        cout << "_______________________________________" << endl;
        cout << "BillNo\tCustomer  Total" << endl;
        cout << "_______________________________________" << endl
             << endl;

        while (getline(file, data))
        {
            cout << data << endl
                 << endl;
        }
    }

    file.close();
}

void Resturant::viewfeedbacks(){
    string data;
    string filename = "feedback.txt";
    ifstream file(filename);
    if (file.peek() == ifstream::traits_type::eof())
    {
        cout << "No Feedback to show." << endl;
    }
    else
    {
        cout << endl
             << endl;
        cout << "_____________________________________" << endl;
        cout << "Customers feedbacks"<< endl;
        cout<< "______________________________________" << endl
             << endl;

        while (getline(file, data))
        {
            cout << data << endl
                 << endl;
        }
    
        file.close();
    }
}

void Resturant::admin()
{
    char a;
    int kkkk;
    string get_uname, dn;
    cout << "Enter your user id : ";
login:
    cin.ignore();
    // getline(cin,get_uname);
    cin >> get_uname;
    if (get_uname == r.uname)
    {
        cout << "Enter your user password: ";
    pass:
        kkkk = getch();
        string enteredPin;
        while (kkkk != 13)
        {
            enteredPin.push_back((char)kkkk);
            cout << "*";
            kkkk = getch();
        }

        if (enteredPin == r.up_w)
        {
            cout << endl;
            do
            {
                SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 6);
                cout << "\t\t\t\t\t\t_________________________" << endl;
                cout << "\t\t\t\t\t\t|||||||||||||||||||||||||" << endl;
                cout << "\t\t\t\t\t\t|                       |" << endl;
                cout << "\t\t\t\t\t\t|  1) ADD DISH          |" << endl;
                cout << "\t\t\t\t\t\t|  2) VIEW MENU         |" << endl;
                cout << "\t\t\t\t\t\t|  3) UPDATE            |" << endl;
                cout << "\t\t\t\t\t\t|  4) DELETE            |" << endl;
                cout << "\t\t\t\t\t\t|  5) VIEW RECORD       |" << endl;
                cout << "\t\t\t\t\t\t|  6) VIEW FEEDBACKS    |" << endl;
                cout << "\t\t\t\t\t\t|  0) EXIT TO MAIN MANU |" << endl;
                cout << "\t\t\t\t\t\t|                       |" << endl;
                cout << "\t\t\t\t\t\t|_______________________|" << endl;
                cout << "\t\t\t\t\t\tSelect the key: ";
                cin >> a;
                switch (a)
                {
                case '0':
                    break;
                case '1':
                    system("CLS");
                    add_menu();
                    break;
                case '2':
                    system("CLS");
                    display();
                    break;

                case '3':
                    system("CLS");
                    update();
                    break;
                case '4':
                    system("CLS");
                    cout << "Enter the dish name:";
                    cin.ignore();
                    getline(cin, dn);
                    delete_rest(dn);
                    break;
                case '5':
                    system("CLS");
                    viewrecords();
                    break;
                case '6':
                    system("CLS");
                    viewfeedbacks();
                    break;
                }
            } while (a != '0');
        }
        else
        {
            cout << "\n\nEnter correct password!!: ";
            goto pass;
        }
    }
    else
    {
        cout << "\n\nEnter the correct username!!!!: ";
        goto login;
    }
}
struct
{
    char d[50];
    float p;
    int qty, pr, bill_no, amount, gtotal;
    string cust_name,feedback;

} rd;
class customer : public Resturant
{
public:
    string dta[100];
    void bill();
    void showbill();
    void dish_menu();
    void billnum();
    void read_file(string id);
    void split(string str);
    void records();
    void feedbacks();
};

void customer::billnum()
{
    string pp;
    ifstream file("billnum.txt");
    if (!file)
    {
        ofstream p("billnum.txt");
        p << 10001;
        p.close();

        ifstream ppp("billnum.txt");
        getline(ppp, pp);
        ppp.close();
        cout << "Bill no :" << pp << endl;
        rd.bill_no = stoi(pp);
        int b = stoi(pp);
        b++;
        p.open("billnum.txt");
        p << b;
        p.close();
    }
    else
    {
        ifstream ppp("billnum.txt");
        getline(ppp, pp);
        ppp.close();
        cout << "Bill no:" << pp << endl;
        rd.bill_no = stoi(pp);
        int b = stoi(pp);
        b++;
        ofstream p("billnum.txt");
        p << b;
        p.close();
    }

    cout << " Name: " << rd.cust_name << endl;
}

void customer::read_file(string id)
{
    ifstream p;
    string data, bb;

    p.open(id);
    getline(p, data);
    p.close();
    split(data);
    r.dish = dta[0];
    r.price = dta[1];
}

void customer ::split(string str)
{

    int a = 0;
    for (int i = 0; i < str.length(); i++)
    {
        string b = "";
        while (str[i] != '\t' && i < str.length())
        {
            b += str[i];
            i++;
        }
        dta[a] = b;
        a++;
    }
}

void customer::bill()
{
    int grandtotal;
    int a;
    string d_name, st_name, pr,feed;
    char ch,fb;
    float total = 0;
    fstream obj, obj1;
    display();
    obj1.open("bill.txt", ios::out | ios::binary);
    do
    {
        cin.ignore();
        cout << "Enter the dish name: ";
        getline(cin, d_name);
        st_name = d_name + ".txt";
        ifstream file(st_name);
        if (!file)
        {
            cout << "\nDish not found! \n";
        }
        else
        {

            read_file(st_name);
            cout << "Enter the quantity: ";
            cin >> rd.qty;
            rd.amount = rd.qty * stoi(r.price);
            cout << r.dish << "\t" << r.price << "\t" << rd.qty << "\t" << rd.amount << endl;
            total = total + rd.amount;
            grandtotal = total;
            rd.gtotal = grandtotal;
        }
        obj1 << "\t" << r.dish << "\t\t\t" << r.price << "\t\t" << rd.qty << "\t\t" << rd.amount << endl;

        cout << "Do you want to order more [y/n]? ";
        cin >> ch;
        obj.close();
    } while (ch == 'y' || ch == 'Y');
    obj1.close();

    if (total > 3000)
    {
        SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 2);
        cout << endl;
        cout << "Your order is more than 3000" << endl;
        cout << "FREE!!! 1 CONFECTIONERY  items" << endl;
        cout << "\t\t\t\t\t\t __________________" << endl;
        cout << "\t\t\t\t\t\t|    Bon Appetite  |" << endl;
        cout << "\t\t\t\t\t\t|__________________|" << endl;
        cout << "\t\t\t\t\t\t|                  |" << endl;
        cout << "\t\t\t\t\t\t|    1)waffles     |" << endl;
        cout << "\t\t\t\t\t\t|    2)macaroon    |" << endl;
        cout << "\t\t\t\t\t\t|    3)cupcake     |" << endl;
        cout << "\t\t\t\t\t\t|    4)pastry      |" << endl;
        cout << "\t\t\t\t\t\t|__________________|" << endl;
        cout << "\t\t\t\t\t\tSelect from the options: ";
    offer:
        cin >> a;
        switch (a)
        {
        case 1:
            cout << "\t\t\t~Enjoy your waffles~ " << endl;
            break;
        case 2:
            cout << "\t\t\t~Enjoy your macaroon~" << endl;
            break;
        case 3:
            cout << "\t\t\t~Enjoy your cupcake~" << endl;
            break;
        case 4:
            cout << "\t\t\t~Enjoy your pastry~" << endl;
            break;
        default:
            cout << "\t\t\t~Invalid option~" << endl
                 << "Enter the correct option:";
            goto offer;
        }
    }
    /* else if (total > 3000)
     {
         SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 2);
         cout << endl;
         cout << "Your order is more than 3000" << endl;
         cout << "5% discount on total purchase" << endl;
         grandtotal = total - (0.05 * total);
     }*/
    cout << "\n\n\nEnter the name: ";
    cin.ignore();
    getline(cin, rd.cust_name);

    SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 7);
    cout << "..............................GENERATING BILL.............................." << endl;

    for (int k = 3; k < 7; k++)
    {
        for (int x = k; x < 7; x++)
        {

            SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), x);
            cout << "  .";
            sleep(1);
        }
    }
    system("CLS");
    SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 4);
    cout << endl;
    billnum();

    cout << " ____________________________________________________________________________________________________________" << endl;
    cout << "|                                                                                                            |" << endl;
    cout << "| -----------------------------------------------------------------------------------------------------------|" << endl;
    cout << "|                                            JAKS FOOD HUB                                                   |" << endl;
    cout << "|                                                BILL                                                        |" << endl;
    cout << "|............................................................................................................|" << endl;
    showbill();
    cout << "|............................................................................................................|" << endl;
    cout << "|\t\t\t\t\t\t\t\t\tTOTAL=" << total << "  \t\t\t     |" << endl;
    cout << "|\t\t\t\t\t\t\t\t\tGRANDTOTAL=" << grandtotal << "  \t\t\t|" << endl;
    cout << "|------------------------------------------------------------------------------------------------------------|" << endl;
    cout << "|____________________________________________________________________________________________________________|" << endl;
    cout << "|                                   ~THANK YOU FOR USING OUR SERVICE~                                        |" << endl;
    cout << "|____________________________________________________________________________________________________________|" << endl;

    records();
    cout<<"Do you have feed back (y/n)? ";
    cin>>fb;
    if(fb == 'y' || fb == 'Y'){
        cout<<"Enter your Feedbacks:";
        cin.ignore();
        getline(cin,feed);
        rd.feedback=feed;
        feedbacks();
        cout<<"KEEP VISITING US !!"<<endl;
    }
    else
    cout<<"KEEP VISITING US !!"<<endl;
}

void customer::showbill()
{

    string data;
    fstream obj;
    obj.open("bill.txt", ios::in | ios::binary);
    cout << "\tDISH NAME\t\tPRICE\t\tQTY\t\tAMOUNT" << endl;

    while (getline(obj, data))
    {
        cout << data << endl
             << endl;
    }
    obj.close();
    remove("bill.txt");
}

void customer::records()
{
    ifstream file("record.txt", ios::app | ios::out);

    if (!file)
    {
        ofstream outfile("record.txt", ios::app | ios::out);

        outfile << rd.bill_no << "\t"
                << rd.cust_name << "\t"
                << rd.gtotal << endl;
        outfile.close();
    }
    else
    {
        ofstream file("record.txt", ios::app | ios::out);

        file << rd.bill_no << "\t"
             << rd.cust_name << "\t"
             << rd.gtotal << endl;
        file.close();
    }
}
void customer::feedbacks(){
     ifstream file("feedback.txt", ios::app | ios::out);

    if (!file)
    {
        ofstream outfile("feedback.txt", ios::app | ios::out);

        outfile << rd.feedback<< "\n";
               
        outfile.close();
    }
    else
    {
        ofstream file("feedback.txt", ios::app | ios::out);

        file << rd.feedback<< "\n";
        file.close();
    }

}

void Resturant::introduction()
{
    cout << "\t\t\t";
    for (int h = 3; h < 15; h++)
    {
        for (int x = h; x < 15; x++)
        {

            SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), x);
            cout << "*";
        }
    }
    cout << endl;
    SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 5);
    cout << "\t\t\t||                     Welcome to JAKS FOOD MENU                            ||" << endl;
    cout << "\t\t\t||                 .Innovation.Iniciative.Imagination.                      ||" << endl;
    cout << "\t\t\t||--------------------------------------------------------------------------||" << endl;
    cout << "\t\t\t||                                                                          ||" << endl;
    cout << "\t\t\t|| .MEMBERS.                                                                ||" << endl;
    cout << "\t\t\t||* Aryav                                                                   ||" << endl;
    cout << "\t\t\t||* Jagerna                                                                 ||" << endl;
    cout << "\t\t\t||* Kritishma                                                               ||" << endl;
    cout << "\t\t\t||* Shristi                                                                 ||" << endl;
    cout << "\t\t\t||--------------------------------------------------------------------------||" << endl;
    cout << "\t\t\t||                                                 Acme Engineering College ||" << endl;
    cout << "\t\t\t||                                                   Sitapaila,Kathmandu    ||" << endl;

    cout << "\t\t\t";
    for (int h = 3; h < 15; h++)
    {
        for (int x = h; x < 15; x++)
        {

            SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), x);
            cout << "*";
        }
    }
    cout << endl;
}

int main()
{

    char a;
    customer obj, obj2;
    system("CLS");
    obj2.introduction();

    do
    {
        SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 3);
        cout << "\t\t\t\t\t\t __________________" << endl;
        cout << "\t\t\t\t\t\t|    MAIN MENU     |" << endl;
        cout << "\t\t\t\t\t\t|__________________|" << endl;
        cout << "\t\t\t\t\t\t|                  |" << endl;
        cout << "\t\t\t\t\t\t|    1)Admin       |" << endl;
        cout << "\t\t\t\t\t\t|    2)Custmer     |" << endl;
        cout << "\t\t\t\t\t\t|    0)Exit        |" << endl;
        cout << "\t\t\t\t\t\t|__________________|" << endl;
        cout << "\t\t\t\t\t\tSelect the menu: ";
        cin >> a;
        switch (a)
        {
        case '0':
            break;
        case '1':
            system("CLS");
            obj.admin();
            break;
        case '2':
            system("CLS");
            time_t now = time(0);

            // convert now to string form
            char *dt = ctime(&now);
            SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 50);
            cout << "\t\t\t____________________________WELCOME TO JAKS FOOD MENU_______________________________________" << endl;
            cout << "\t\t\t\t\t\t\t" << dt << endl;

            char *k;
            strcpy(k, dt);
            string s = k; // constant char converted to std::string
            string l = s.substr(0, 3);
            const char *g = l.c_str(); // std::string converted to  constant char

            SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 5);

            if (strcmp(g, "Sun") == 0)
            {
                cout << "\t\t\t\t\t!!!!!!!!!!!!!!!!!SUNDAY OFFERS!!!!!!!!!!!" << endl;
                cout << "\t\t\t\t2 Burger,1 pack fries,500ml coke,crunchy fried chicken 1 piece" << endl;
                cout << "\t\t\t\t\t\t\tJust for Rs:900" << endl;
            }

            else if (strcmp(g, "Mon") == 0)
            {
                cout << "\t\t\t\t\t!!!!!!!!!!!!!!!!!!MONDAY OFFERS!!!!!!!!!!!" << endl;
                cout << "\t\t\t\t2 cocktail,1 pack fries,chicken momo,small meatlovers pizza" << endl;
                cout << "\t\t\t\t\t\t\tJust for Rs:900" << endl;
            }

            else if (strcmp(g, "Tue") == 0)
            {
                cout << "\t\t\t\t\t!!!!!!!!!!!!!!!!!!TUESDAY  OFFERS!!!!!!!!!!!" << endl;
                cout << "\t\t\t\t2 waffles,1 pack fries, salami bowl,small pepperoni pizza" << endl;
                cout << "\t\t\t\t\t\t\tJust for Rs:900" << endl;
            }

            else if (strcmp(g, "Wed") == 0)
            {
                cout << "\t\t\t\t\t!!!!!!!!!!!!!!!!!!WEDNESDAY OFFERS!!!!!!!!!!!" << endl;
                cout << "\t\t\t\t2 potato wedges,1 pack fries,mohito,crunchy fried chicken 1 piece" << endl;
                cout << "\t\t\t\t\t\t\tJust for Rs:900" << endl;
            }

            else if (strcmp(g, "Thu") == 0)
            {
                cout << "\t\t\t\t\t!!!!!!!!!!!!!!!!!THURSDAY OFFERS!!!!!!!!!!!" << endl;
                cout << "\t\t\t\t2 choupsey,1 pack fries,variety smoothie, burrittos" << endl;
                cout << "\t\t\t\t\t\t\tJust for Rs:900" << endl;
            }

            else if (strcmp(g, "Fri") == 0)
            {
                cout << "\t\t\t\t\t!!!!!!!!!!!!!!!!!!!!FRIDAY OFFERS!!!!!!!!!!!" << endl;
                cout << "\t\t\t\t2 Tacos,1 pack fries,iceream rolls,gourmet rice" << endl;
                cout << "\t\t\t\t\t\t\tJust for Rs:900" << endl;
            }

            else if (strcmp(g, "Sat") == 0)
            {
                cout << "\t\t\t\t\t!!!!!!!!!!!!!!!!!!!SATURDAY OFFERS!!!!!!!!!!!" << endl;
                cout << "\t\t\t\t\t\tBiryani,1 sandeko momo, coke, french salad" << endl;
                cout << "\t\t\t\t\t\t\tJust for Rs:900" << endl;
            }

            SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 5);

            // obj.display();

            obj.bill();
            break;
        }
    } while (a != '0');
}
