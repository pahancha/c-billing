#include<iostream>
#include<fstream>

using namespace std;

class shopping
{
    private:
        int product_code;
        float price;
        float discount;
        string product_name;

    public:
        void menu();
        void administration();
        void buyer();
        void add();
        void edit();
        void remove();
        void list();
        void receipt();
};

void shopping :: menu()
{
    int choice;
    string email;
    string password;

    cout<<"Welcome to the supermarket Main Menu\n";
    cout<<"1 - Administration\n";
    cout<<"2 - Buyer\n";
    cout<<"3 - Exit\n";
    cout<<"Please select a option. \n";

    switch(choice)
    {
        m:
        case 1:
            cout<<"Please login. \n";
            cout<<"Enter Email. \n";
            cin>>email;
            cout<<"Enter Password. \n";
            cin>>password;

            if(email=="admin@billing.com" && password=="admin123")
            {
                administration();
            }
            else
            {
                cout<<"Invalid email or password. \n";
            }
            break;

        case 2:
            {
                buyer();
            }
        
        case 3:
            {
                exit(0);
            }

        default:
            {
                cout<<"Please select from the given options above. \n";
            }

    }

    goto m;

}

void shopping:: administration()
{
    m:
    int choice;
    cout<<"Administration Menu\n";
    cout<<"1 - Add a new product. \n";
    cout<<"2 - Modify a existing product. \n";
    cout<<"3 - Delete a axisting product. \n";
    cout<<"4 - Back to the main menu. \n";

    cout<<"Please enter your choice. \n";
    cin>>choice;

    switch (choice)
    {
    case 1:
        add()
        break;

    case 2:
        edit();
        break;
    
    case 3:
        remove();
        break;

    case 4:
        menu();
        break;
    
    default:
        cout<<"Invalid choice. Please try again. \n";
    }
    goto m;
}

void shopping::buyer()
{
    m:
    int choice;
    cout<<"Customer Menu. \n";
    cout<<"1 - Buy products. \n";
    cout<<"2 - Go Back to the main menu. \n"

    cout<<"Enter your choice. \n";
    cin>>choice;

    switch (choice)
    {
    case 1:
        receipt();
        break;

    case 2:
        menu();
    
    default:
        cout<<"Invalid choice. Please try again.";
    }
    goto m;
}

void shopping::add()
{
    fstream data;
    int c;
    int token = 0;
    float p;
    float d;
    string n;

    cout<<"Add new product. \n";
    
    cout<<"Product code of the product. \n";
    cin>>product_code;
    cout<<"Product name.\n";
    cin>>product_name;
    cout<<"Price of the product.\n";
    cin>>price;
    cout<<"Discount on product. \n";

    data.open("database.txt", ios::in);

    if (!data)
    {
        data.open("database.txt", ios::app|ios::out);
        data<<" "<< product_code << " " << price << " " << discount << "\n";
        data.close();
    }
    else
    {
        data>>c>>n>>p>>d;

        while (!data.eof())
        {
            if (c == product_code)
            {
                token++;
            }
            data>>c>>n>>p>>d;
        }
        data.close();
        
    }

    if (token == 1)
    {
        goto m;
    }
    else
    {
        data.open("database.txt", ios::app|ios::out);
        data<<" "<< product_code << " " << price << " " << discount << "\n";
        data.close();
    }

    cout<<"Record Inserted. \n"
}

void shopping ::edit()
{
    fstream data,data1;
    int product_key;
    int token = 0;
    int c;
    float p;
    float d;
    string n;

    cout<<"\n Edit the record. \n"

    cout<<"Enter the product code. \n";
    cin>>product_code;

    data.open("database.txt", ios::in);
    if (!data)
    {
        cout<<"File does not exist. \n";
    }
    else
    {
        data1.open("database1.txt",ios::app|ios::out);
        data>>product_code>>product_name>>discount;
        while (!data.eof())
        {
            if (product_key == product_code)
            {
                cout<<"New product code. \n";
                cin>>c;
                cout<<"Name of the product. \n";
                cin>>n;
                cout<<"Price\n";
                cin>>p;
                cout<<"Discount \n"
                cin>>d;
                data1<<" "<< c << " " << p << " " << d << "\n";
                
                cout<<"The record has been edited.\n";
                token++;
            }
            else
            {
                data1<<" "<<product_code<<" "<<product_name<<" "<<price<<" "<< discount<<"\n";
            }
            data>>product_code>>price>>discount;
        }
        data.close();
        data1.close();

        remove("database.txt");
        rename("database1.txt","database.txt");

        if (token == 0)
        {
            cout<<"Record not found. Please try again. \n"
        }      
    }   
}

void shopping::remove()
{
    fstream data, data1;
    int product_key;
    int token = 0;
    cout<<"Delete Product \n";
    cout<<"Please enter the product key. \n";
    cin>>product_key;
    data.open("database.txt", ios::in);

    if (!data)
    {
        cout<<"The file does not exist in the database. \n"
    }
    else
    {
        data1.open("database.txt", ios::app|ios::out);
        data>>product_code>>product_name>>price>>discount;

        while (!data.eof())
        {
            if (product_code ==product_key)
            {
                cout<<"Product has been deleted.\n";
                token++;
            }
            else
            {
                data<<" "<< product_code << " " << product_name << " " << price << " " << discount << "\n";
            }
            data>>product_code>>product_name>>price>>discount;
        }
        data.close();
        data1.close();
        remove("database.txt");
        rename("database1.txt","database.txt");

        if (token == 0)
        {
            cout<<"Record can not found. \n";
        }
    }
    
}

void shopping:: list()
{
    fstream data;
    data.open("database.txt", ios::in);
    cout<<"\n LIST OF PRODUCTS \n";
    cout<<"productNo\t\tName\t\tPrice.\n"
    data>>product_code>>product_name>>price>>discount;

    while (!data.eof())
    {
        cout<<product_code<<"\t\t"<<product_name<<"\t\t"<<price<<"\n";
        data>>product_code>>product_name>>price>>discount;
    }
    data.close();
}

void shopping::receipt()
{
    fstream data;

    int arrc[100];
    int arrq[100];
    char choice;
    int c = 0;
    float amount = 0;
    float discount = 0;
    float total = 0;

    cout<<"RECEIPT \n";
    data.open("database.txt", ios::in);

    if (!data)
    {
        cout<<"No Data Found in the Database. \n";
    }
    else
    {
        data.close();
        list();
        cout<<"Please continue your order. \n\n";

        do
        {
            cout<<"Enter the product code. \n";
            cin>>arrc[c];
            cout<<"Enter the pruct quantity. \n";
            cin>>arrq[c];

            for (i = 0; i < c; i++)
            {
                if (arrc[c] == arrc[i])
                {
                    cout<<"Duplicate Product Code. Please Check and Try Again.\n";
                    goto m;
                }
                count++;
                cout<<"Do you want to buy another product? If yes press y. Else n \n";
                cin>>choice;
            }
            
        } while (choice=="y");

        cout<<"RECEIPT\n"
        cout<<"Product No.\tProduct Name\t Product Quantity \t Price\tAmont with Discount";

        for (i = 0; i < c; i++)
        {
            data.open("database.txt", ios::in);
            data>>product_code>>product_name>>price>>discount;

            while (!data.eof())
            {
                if (product_code == arrc[i])
                {
                    amount = price * arrq[i];
                    discount = amount - (amount*discount/100);
                    total = total + discount;
                    cout<<"\n"<<product_code<<"\t\t"<<product_name<<"\t\t"<<arrq[i]<<"\t\t"<<price<<"\t"<<amount<<"\t\t"discount;
                }
                data>>product_code>>product_name>>price>>discount;
            }
            
        }
        data.close();
                
    }

    cout<<"\n Total Amount :"<< total;
}

int main
{
    shopping s;
    s.menu();
}