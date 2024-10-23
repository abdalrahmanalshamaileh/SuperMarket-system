#include<iostream>
#include<fstream>

using namespace std;
class shopping
{
	int pcode;
	float price;
	float dis;
	string pname;
public:
	void menu();
	void admin();
	void buyer();
	void add();
	void edit();
	void rem();
	void list();
	void receipt();

};

void shopping::menu()
{
m:
	int choice;
	string email;
	string password;
	cout << "\t\t\t\t\t____________________________________\n";
	cout << "\t\t\t\t\t        Super Market Main Menu       \n";
	cout << "\t\t\t\t\t______________________________________\n";
	cout << "\t\t\t\t|  1) Adminstrator       |\n     ";
	cout << "\t\t\t\t|";
	cout << "\t\t\t\t| 2) Buyer               |\n      ";
	cout << "\t\t\t\t|";
	cout << "\t\t\t\t| 3) Exit                |\n";
	cin >> choice;

	switch (choice)
	{
	case 1:
	{
		cout << "\t\t\t\t Please Login \n";
		cout << "\t\t\t\t  Enter Email\n";
		cin >> email;
		cout << "\t\t\t\t Password\n";
		cin >> password;
		if (email == "robby@email.com" && password == "robby@123")
		{
			admin();
		}
		else
		{
			cout << "Invalid email/password " << endl;
		}
		break;
	}

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
		cout << "please select from the given options" << endl;

	}
	goto m;
	}
}
	

void shopping::admin()
{	
	    m:
		int choice;
		cout << "\n\n\n\n \t\t\t  Adminstrator Menu ";
		cout << "\n\t\t\t\t______1) Add the product ____|";
		cout << "\n\t\t\t\t|";
		cout << "\n\t\t\t\t______2) modify the product ____|";
		cout << "\n\t\t\t\t|";
		cout << "\n\t\t\t\t______3) delete the product ____|";
		cout << "\n\t\t\t\t|";
		cout << "\n\t\t\t\t______4) Back to the main menu ____|";
		cout << "\n\n\n\t Please enter your choice";
		cin >> choice;

		switch (choice)
		{
		case 1:
			add();
			break;
		case 2:
			edit();
			break;
		case 3:
			rem();
			break;
		case 4:
			menu();
			break;
		default:
			cout << "Invalid choice !";
	    }
		goto m;
}

void shopping::buyer()
{
	m:
	int choice;
	cout << "\t\t\t  Buyer \n ";
	cout << "\t\t\t\t____________\n";
	cout << "                      \n";
	cout << "\t\t\t 1) Buy Product  \n";
	cout << "                      \n";
	cout << "\t\t\t 2) Go back  \n";
	cout << "\t\t\t 1) Enter your choice  \n";
	cin >> choice;
	switch (choice)
	{
	case 1:
		receipt();
		break;
	case 2:
		menu();
		
	default:
		cout << "Invalid Choice" << endl;
	}
	goto m;
}
void shopping::add()
{
	m:
	fstream data;
	int c;
	int token = 0;
	float p;
	float d;
	string n;


	cout << "\n\n\t\t\t\t Add new product ";
	cout << "\n\n Product Code ";
	cin >> pcode;
	cout << "\n\n\t\t\t\t Name of product ";
	cin >> pname;
	cout << "\n\n\t\t\t\t Price of product ";
	cin >> price;
	cout << "\n\n\t\t\t\t Discount on the product ";
	cin >> dis;

	data.open("database.txt", ios::in);
	if (!data)
	{
		data.open("database.txt", ios::app | ios::out);
		data << " " << pcode << " " << pname << " " << price << " " << dis << "\n";
		data.close();
	}
	else
		data >> c >> n >> p >> d;
	while (!data.eof())
	{
		if (c==pcode)
		{
			token++;
		}
		data >> c >> n >> p >> d;
	}
	data.close();
	if (token == 1)
	{
		goto m;
	}	
	else
	{
		data.open("database.txt", ios::app | ios::out);
		data << " " << pcode << " " << pname << " " << price << " " << dis << "\n";
		data.close();
	}
	cout << "\n\n\t\t Record Inserted";
}

void shopping::edit()
{
	fstream data, data1;
	int pkey;
	int token = 0;
	int c;
	float p;
	float d;
	string n;
	cout << "\t\t\n\n\n Modify the record";
	cout << "\t\t\n\n\n Prodcut Code: ";
	cin >> pkey;
	data.open("database.txt", ios::in);
	if (!data)
	{
		cout << "\n \n File doesn't exist!";
	}
	else
	{
		data1.open("database1.txt", ios::app | ios::out);
		data >> pcode >> pname >> price >> dis;
		while (!data.eof())
		{
			if (pkey == pcode)
			{
				cout << "\n\t\t product New code: ";
				cin >> c;
				cout << "\n\t\t Name of the prodcut : ";
				cin >> n;
				cout << "\n\t\t Price: ";
				cin >> p;
				cout << "\n\t\t Discount: ";
				cin >> d;
				data1 << " " << c << " " << n << " " << p << " " << d << "\n";
				cout << "\n\n\t Record edited";
				token++;
			}
			else
			{
				data1 << " " << pcode << " " << pname << " " << price << " " << dis<<"\n";
			}
			data >> pcode >> pname >> price >> dis;
		}
		
		data.close();
		data1.close();
		
		
		remove ("database.txt");

		rename("database1.txt","database.txt");

		if (token == 0)
		{
			cout << "\n\n Record not found sorry!";
		}
	}
}
void shopping::rem()
{
	fstream data, data1;
	int pkey;
	int token = 0;
	cout << "\n\n\t Delete product ";
	cout << "\n\n\t product code :";
	cin >> pkey;
	data.open("database.txt", ios::in);
		if (!data)
		{
			cout << "File doesnt exist";
		}
		else
		{
			data1.open("database1.txt", ios::app | ios::out);
				data >> pcode >> pname >> price >> dis;
				while (!data.eof())
				{
					if (pcode == pkey)
					{
						cout << "\n\n\t Product deleted successfully";
						token++;
					}
					else
					{
						data1 << " " << pcode << " " << pname << " " << price << " " << dis << "\n";
					}
					data  >> pcode >>pname >>  price >>  dis ;
				}
				data.close();
				data1.close();
				remove("database.txt");
				rename("database1.txt","datatbase.txt");
		
				if (token == 0)
				{
					cout << "\n\n Record not found";
		        }
		}
}

void shopping::list()
{
	fstream data;
	data.open("database.txt", ios::in);
	cout << "\n\n|______________________________\n";
	cout << "ProNo\t\tName \t\tprice\n";
	cout << "\n\n|______________________________\n";
	data >> pcode >> pname >> price >> dis;
	while (!data.eof())
	{
		cout << pcode << "\t\t" << pname << "\t\t" << price << endl;
		data >> pcode >> pname >> price>>dis;

	}

	data.close();

}

void shopping::receipt()
{
	m:
	fstream data;
	int arrc[100];
	int arrq[100];
	char choice;
	int c = 0;
	float amount = 0;
	float dis = 0;
	float total = 0;
	cout << "\n\n\t\t\t RECEIPT ";
	data.open("database.txt", ios::in);
	if (!data)
	{
		cout << "\n\n Empty database";
	}
	else
	{
		data.close();
		list();
		cout << "\n__________________________\n";
		cout << "\n|                           \n";
		cout << "\n| Please Place The Order     \n";
		cout << "\n_____________________________\n";

		do
		{
			cout << "\n\n Enter product code :";
			cin >> arrc[c];
			cout << "\n\n Enter thr product quantity: ";
			cin >> arrq[c];
			for (int i = 0; i < c; i++)
			{
				if (arrc[c] == arrc[i])
				{
					cout << "\n\n Duplicate product code,please try again";
					goto m;
				}
			}
			c++;
			cout << "\n\n Do you want to buy another product? yes or no ?";
			cin >> choice;
		} 
		while (choice == 'y');
		cout << "\n\n\t\t____________________ RECEIPT_________\n";
		cout << "\nProduct number \t product name \t product quantity \t price\t amount with discount\n";
		for (int i = 0; i < c; i++)
		{
			data.open("database.txt",ios::in);
			data >> pcode >> pname >> price >> dis;
			while (!data.eof())
			{
				if (pcode == arrc[i])
				{
					amount = price * arrq[i];
					dis = amount - (amount * dis / 100);
					total += dis;
					cout << "\n" << pcode << "\t" << pname << "\t" << arrq[i] << "\t" << price << "\t" << amount << "\t" << dis;
				}
				data >> pcode >> pname >> price >> dis;

			}
		}
		data.close();
	}
	cout << "\n\n _________________________________";
	cout << "\n Total amount:" << total;
}

int main()
{
	shopping s;
	s.menu();
}