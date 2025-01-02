#include<iostream>
#include<string>
#include<stdlib.h>
#include<fstream>
using namespace std;
class Shipment
{
	string date;
	string timeoforder;
	string timeofreachexpected;
	float weight;
	int quantity;
	double price;
	static int count;
public:
	Shipment()
	{
		quantity = 0;
		price = 0.0;
		weight = 0;
		count++;
	}
	Shipment(string d, string too, string tor, float w, int q, double p)
	{
		date = d;
		timeoforder = too;
		timeofreachexpected = tor;
		weight = w;
		quantity = q;
		price = p;
		count++;
	}


	void setdate(string d)
	{
		date = d;
	}
	void settimeoforder(string too)
	{
		timeoforder = too;
	}
	void settimeofreachexpected(string tor)
	{
		timeofreachexpected = tor;
	}
	void setweight(float w)
	{
		weight = w;
	}
	void setquantity(int q)
	{
		quantity = q;
	}
	void setprice(double p)
	{
		price = p;
	}
	void getcount()
	{
		cout << "Number of shipments = " << count;
	}
	string getdate()
	{
		return date;
	}
	string gettimeoforder()
	{
		return timeoforder;
	}
	string gettimeofreachexpected()
	{
		return timeofreachexpected;
	}
	float getweight()
	{
		return weight;
	}
	int getquantity()
	{
		return quantity;
	}
	double getprice()
	{
		return price;
	}
	void printdetailsofshipment()
	{
		cout << "Date: " << date << endl;
		cout << "Time of Order: " << timeoforder << endl;
		cout << "Time of reach expected: " << timeofreachexpected << endl;
		cout << "Weight of shipment: " << weight << endl;
		cout << "Quantity of shipment: " << quantity << endl;
		cout << "price of shipment: " << price << endl;
	}
};
int Shipment::count = 0;
class Sender :public Shipment
{
private:
	string name;
	string companyname;
	string country;
public:
	Sender()
	{
		name = "unknown";
		companyname = "unknown";
		country = "unknown";

	};
	Sender(string name, string companyname, string country, string time, string d, string too, string tor, float w, int q, int p) :name(name), companyname(companyname), country(country), Shipment(d, too, tor, w, q, p)
	{

	}
	void setname(string name) {
		this->name = name;
	}
	string getname() {
		return name;
	}
	void setcompanyname(string companyname) {
		this->companyname = companyname;
	}
	string getcompanyname() {
		return companyname;
	}
	void setcountry(string country) {
		this->country = country;
	}
	string getcountry() {
		return country;
	}
};
class Receiver : public Shipment
{
private:
	string name;
	string companyname;
	string country;
public:
	Receiver()
	{
		name = "unknown";
		companyname = "unknown";
		country = "unknown";
	}
	Receiver(string name, string companyname, string country, string d, string too, string tor, float w, int q, int p) : Shipment(d, too, tor, w, q, p) {
		this->name = name;
		this->companyname = companyname;
		this->country = country;
	}
	void setname(string name1) {
		this->name = name1;
	}
	string getname() {
		return name;
	}
	void setcompanyname(string companyname1) {
		this->companyname = companyname1;
	}
	string getcompanyname() {
		return companyname;
	}
	void setcountry(string country1) {
		this->country = country1;
	}
	string getcountry() {
		return country;
	}
};

class Transport
{
	string shipmentType;
	double transportCharges;
	int status;
public:
	Transport()
	{
		shipmentType = "Unknown";
		transportCharges = 0;
		status = 0;
	}
	Transport(string shipmentType, double transportCharges)
	{
		this->shipmentType = shipmentType;
		this->transportCharges = transportCharges;
		status = 0;
	}
	void setShipmentType(string shipmentType)
	{
		this->shipmentType = shipmentType;
	}
	void setTransportCharges(double transportCharges)
	{
		this->transportCharges = transportCharges;
	}
	string getShipmentType()
	{
		return shipmentType;
	}
	double getTansportCharges()
	{
		return transportCharges;
	}
	void CheckDeliveryStatus()
	{
		if (status == 0)
		{
			cout << "\nOrder Processing.\n";
			status += 1;
		}
		else if (status == 1)
		{
			cout << "\nParcel is being packed.\n";
			status += 1;
		}
		else if (status == 2)
		{
			cout << "\nParcel is ready to be shipped.\n";
			status += 1;
		}
		else if (status == 3)
		{
			cout << "\nParcel has been shipped.\n";
			status += 1;
		}
		else if (status == 4)
		{
			cout << "\nParcel is arrived in your country.\n";
			status += 1;
		}
		else if (status == 5)
		{
			cout << "\nParcel is out for delivery to the receiver.\n";
			status += 1;
		}
		else
		{
			cout << "\nParcel Delivered.\n";
		}
	}
};
class Payment
{
	double totalpayment;
	double givenpayment;
	double remainingpayment;
	string paymentmethod;
public:
	Payment()
	{
		totalpayment = 0;
		givenpayment = 0;
		remainingpayment = 0;
		paymentmethod = "unknown";
	}
	void settotalpayment(Shipment& shipment, Transport& transport)
	{
		totalpayment = shipment.getprice() + transport.getTansportCharges();
	}
	void setgivenpayment(double givenPayment)
	{
		this->givenpayment = givenPayment;
	}
	void setRemainingPayment()
	{
		remainingpayment = totalpayment - givenpayment;
	}
	void setpaymentMethod(string paymentmethod)
	{
		this->paymentmethod = paymentmethod;
	}
	double gettotalpayment()
	{
		return totalpayment;
	}
	double getgivenpayment()
	{
		return givenpayment;
	}
	double getRemainingpayment()
	{
		return remainingpayment;
	}
	string getPaymentmethod()
	{
		return paymentmethod;
	}
};
int main()
{
	cout << "------------------------------------------------------------------------------------------------------------------------";
	cout << "\n---------------------------------------------|Welcome to the Import/Export Management System|---------------------------";
	cout << "\n------------------------------------------------------------------------------------------------------------------------";
	//for now username="OOP PROJECT" and password="1234";
	string password, username;
	string input, input1;
	int input2;
	double input3;
	float input4;
	fstream os;
	os.open("OOP PROJECT.txt", ios::out | ios::in);
	Shipment shipment[50];
	Receiver receiver[50];
	Sender sender[50];
	Transport transport[50];
	Payment payment[50];
	int i = 0;
	while (1) {
		cout << "\n\n\n\nUsername: ";
		getline(cin, username);
		if (username == "OOP PROJECT") {
			while (1) {
				cout << "\nEnter Password: ";
				getline(cin, password);
				if (password == "1234")
				{
					while (1) {
						system("cls");
						cout << "------------------------------------------------------------------------------------------------------------------------";
						cout << "\n---------------------------------------------|Welcome to the Import/Export Management System|---------------------------";
						cout << "\n------------------------------------------------------------------------------------------------------------------------";
						cout << "\n-----------------------------------------------------------------|MENU|-------------------------------------------------\n";
						fflush(stdin);
						cout << "\n\n\n\n\t\t\t\t1. Enter Data\n\t\t\t\t2. check Data\n\t\t\t\t3.About Creators\n\t\t\t\t4.Exit\n\n\n\n\n\n\n\n\n\n";
						cin >> input2;
						if (input2 == 1)
						{
							system("cls");
							cout << "------------------------------------------------------------------------------------------------------------------------";
							cout << "\n------------------------------------------|Welcome to the Import/Export Management System|------------------------------";
							cout << "\n------------------------------------------------------------------------------------------------------------------------";
							cout << "\n----------------------------------------------------------|ENTER DATA|--------------------------------------------------";
							cout << "\n------------------------------------------------------------------------------------------------------------------------";
							cout << "\n\n\n---------------------------------------------------|Enter Sender Data|------------------------------------------------\n";
							cout << "\n\nEnter Sender Name: ";
							getline(cin >> ws, input);
							sender[i].setname(input);
							cout << "Enter Sender Country: ";
							getline(cin >> ws, input);
							sender[i].setcountry(input);
							cout << "Enter Sender Company Name: ";
							getline(cin >> ws, input);
							sender[i].setcompanyname(input);
							cout << "\nSENDER DETAILS ENTERED SUCCESSFULLY.\n";
							cout << "\n\n\n--------------------------------------------------|Enter Receiver Data|------------------------------------------------\n";
							cout << "\n\nEnter Receiver Name: ";
							getline(cin >> ws, input);
							receiver[i].setname(input);
							cout << "Enter Receiver's Country: ";
							getline(cin >> ws, input);
							receiver[i].setcountry(input);
							cout << "Enter Receiver Company Name: ";
							getline(cin >> ws, input);
							receiver[i].setcompanyname(input);
							cout << "\nRECEIVER DETAILS ENTERED SUCCESSFULLY.\n";
							cout << "\n\n\n--------------------------------------------------|Enter Shipment Data|------------------------------------------------\n";
							cout << "Enter Shipment Weight In KG/s: ";
							cin >> input4;
							shipment[i].setweight(input4);
							cout << "Enter shipment's Product Quantity: ";
							cin >> input2;
							shipment[i].setquantity(input2);
							cout << "Enter shipment's product price: ";
							cin >> input3;
							shipment[i].setprice(input3);
							cout << "Enter Shipment Date(00/00/0000): ";
							getline(cin >> ws, input1);
							while (1) {
								if ((((input1[0] - '0') * 10) + ((input1[1] - '0') * 1)) > 30)
								{
									cout << "\nINCORRECT DATE ENTERED PLEASE RE-ENTER: ";
									getline(cin >> ws, input1);
								}
								else if ((((input1[3] - '0') * 10) + ((input1[4] - '0') * 1)) > 12)
								{
									cout << "\nINCORRECT DATE ENTERED PLEASE RE-ENTER: ";
									getline(cin >> ws, input1);
								}
								else
								{
									break;
								}
							}
							shipment[i].setdate(input1);
							cout << "Enter Shipment Time(00:00:00(24 hours format)): ";
							getline(cin >> ws, input1);
							while (1) {
								if ((((input1[0] - '0') * 10) + ((input1[1] - '0') * 1)) > 23)
								{
									cout << "\nINCORRECT TIME ENTERED PLEASE RE-ENTER: ";
									getline(cin >> ws, input1);
								}
								else if ((((input1[3] - '0') * 10) + ((input1[4] - '0') * 1)) > 59)
								{
									cout << "\nINCORRECT DATE ENTERED PLEASE RE-ENTER: ";
									getline(cin >> ws, input1);
								}
								else if ((((input1[6] - '0') * 10) + ((input1[7] - '0') * 1)) > 59)
								{
									cout << "\nINCORRECT DATE ENTERED PLEASE RE-ENTER: ";
									getline(cin >> ws, input1);
								}
								else
								{
									break;
								}
							}
							shipment[i].settimeoforder(input1);
							cout << "Enter Shipment Expected Date to reach(00/00/0000): ";
							getline(cin >> ws, input1);
							while (1) {
								if ((((input1[0] - '0') * 10) + ((input1[1] - '0') * 1)) > 30)
								{
									cout << "\nINCORRECT TIME ENTERED PLEASE RE-ENTER: ";
									getline(cin >> ws, input1);
								}
								else if ((((input1[3] - '0') * 10) + ((input1[4] - '0') * 1)) > 12)
								{
									cout << "\nINCORRECT DATE ENTERED PLEASE RE-ENTER: ";
									getline(cin >> ws, input1);
								}
								else
								{
									break;
								}
							}
							shipment[i].settimeofreachexpected(input1);
							cout << "\nSHIPMENT DETAILS ADDED SUCCESSFULLY.\n";
							cout << "\n\n\n--------------------------------------------------|Enter TRANSPORT Data|------------------------------------------------\n";
							cout << "\nEnter Shipment Transport Type: ";
							getline(cin >> ws, input1);
							transport[i].setShipmentType(input1);
							cout << "\nEnter Transport Charges: ";
							cin >> input3;
							transport[i].setTransportCharges(input3);
							cout << "\nTRANSPORT DETAILS ADDED SUCCESSFULLY.\n";
							cout << "\n\n\n--------------------------------------------------|Enter PAYMENT Data|------------------------------------------------\n";
							cout << "\nEnter Payment Method: ";
							getline(cin >> ws, input1);
							payment[i].setpaymentMethod(input1);
							cout << "\nEnter Given Payment: ";
							cin >> input3;
							payment[i].setgivenpayment(input3);
							payment[i].settotalpayment(shipment[i], transport[i]);
							payment[i].setRemainingPayment();
							cout << "\n\nWHOLE DATA ENTERED SUCCESSFULLY: ";
							os << "\n-----------------------------------------|DETAILS|--------------------------------------\n\n";
							os << "\n\n--------------------------------------|Sender DETAILS|----------------------------------\n\n";
							os << "\nSender name: " << sender[i].getname();
							os << "\nSender Country: " << sender[i].getcountry();
							os << "\nSender Company Name: " << sender[i].getcompanyname();
							os << "\n\n-------------------------------------|RECEIVER DETAILS|----------------------------------\n\n";
							os << "\nReceiver name: " << receiver[i].getname();
							os << "\nReceiver Country: " << receiver[i].getcountry();
							os << "\nReceiver Company Name: " << receiver[i].getcompanyname();
							os << "\n\n-------------------------------------|SHIPMENT DETAILS|----------------------------------\n\n";
							os << "\nShipment Product Weight: " << shipment[i].getweight() << " kgs";
							os << "\nShipment Product Quantity: " << shipment[i].getquantity();
							os << "\nShipment Product Date Of Ordering: " << shipment[i].getdate();
							os << "\nShipment Product Time OF Ordering: " << shipment[i].gettimeoforder();
							os << "\nShipment Product Expected Date Of Reaching: " << shipment[i].gettimeofreachexpected();
							os << "\nShipment Product Price:  " << shipment[i].getprice() << " Dollars";
							os << "\n\n-------------------------------------|TRANSPORT DETAILS|----------------------------------\n\n";
							os << "\nTransport Type: " << transport[i].getShipmentType();
							os << "\nTransport Price: " << transport[i].getTansportCharges();
							os << "\n\n-------------------------------------|PAYMENT DETAILS|----------------------------------\n\n";
							os << "\nPAYMENT METHOD: " << payment[i].getPaymentmethod();
							os << "\nTOTAL PAYMENT: " << payment[i].gettotalpayment();
							os << "\nGIVEN PAYMENT: " << payment[i].getgivenpayment();
							os << "\nREMAINING PAYMENT: " << payment[i].getRemainingpayment() << "\n\n";
							os << "\n-----------------------------------------------------------------------------------------------\n\n\n";
							i++;
						}
						if (input2 == 2)
						{
							system("cls");
							char search;
							while (!os.eof())
							{
								os.get(search);
								cout << search;
							}
							return 0;
						}
						if (input2 == 3)
						{
							cout << "\n MY DEVELOPERS ARE: \n";
							cout << "Warun Kumar[22K-4721]\nHammad Alam[22K-4675]\nAadarsh Kumar[22K-4758]\n";
						}
						if (input2 == 4)
						{
							cout << "\nTHANKYOU FOR USING THIS MANAGEMENT SYSTEM, HAVE A NICE DAY.";
							return 0;
						}
					}
				}
				else
				{
					cout << "Invalid Password.Please Enter Correct Password.";
				}
			}
		}
		else
		{
			cout << "\nInvalid Usename.Please Enter Correct UserName";
		}
	}
}