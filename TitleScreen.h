#include<iostream>
using namespace std;

/*************************TitleScreenClass**************************/
class TitleScreen
{
	string systemName;
	int wareHouseCode;
	string stockWareHouseLocation;
	
	public:
		// constructors
		TitleScreen()
		{
			systemName = "AMAZON PRODUCTS DATA MANIPULATION SYSTEM";
			stockWareHouseLocation = "SOUTHERN SAN FRANSISCO, CALIFORNIA";
			wareHouseCode = 12345;
		}
		// setters
		void setSystemName(string name)
		{
			systemName = name;
		}
		void setWareHouseCode(int code)
		{
			wareHouseCode = code;
		}
		void setWareHouseLocation(string location)
		{
			stockWareHouseLocation = location;
		}
		// getters
		string getSystemName()
		{
			return systemName;
		}
		string getWareHouseLocation()
		{
			return stockWareHouseLocation;
		}
		int getWareHouseCode()
		{
			return wareHouseCode;
		}
		// will print the Title screen widgets 
		void displayScreen()
		{
			cout<<"\n\n\t\t\t>>>>>>>>>>>  "<<systemName<<"  <<<<<<<<<<<";
			cout<<"\n\t\t\t------------------------------------------------------------------";
			cout<<"\n\n\t\t\t\t               "<<(char)04<<(char)04<<(char)04<<" WELCOME "<<(char)04<<(char)04<<(char)04<<"\n\n\n";
			cout<<"\n\n\t\t\t******************************************************************";
			cout<<"\n\n\t\t\tSTOCK WARE HOUSE CODE      : "<<wareHouseCode;
			cout<<"\n\n\t\t\t******************************************************************";
			cout<<"\n\n\t\t\tSTOCK WARE HOUSE LOCATION  : "<<stockWareHouseLocation;
			cout<<"\n\n\t\t\t******************************************************************";
		}		
};
