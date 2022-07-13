#include<iostream>
#include<fstream>
#include<conio.h>
#include<windows.h>
#include "Product.h"

//*********************************************LOGIN CLASS***********************************************// 
class LogIn{
	int id;
	char password[9];
	
	public:
		LogIn()
		{
			id = 0;
			password[0] = '\0';
		}
		LogIn(int id, string pass)
		{
			setID(id);
			setPassword(pass);
		}
		// setters
		void setID(int id)
		{
			if(id > 0)
				this->id = id;
			else
				this->id = 0;
		}
		void setPassword(string n)
		{
			int len=n.size();
			if(len>8)
			{
			    cout<<"\n\t\t\tAlert!Password should be at max 8-letters.\n";
				typePassword();
			}
			else if(len==8)
			{
				n.copy(password,len);
				password[len]='\0';
			}
			else
			{
			    cout<<"\n\t\t\tAlert!Password should be atleast 8-letters.\n";
				typePassword();
			}
		}	
		// mutators
		int getID() { return id; } string getPassword() { return password; }
		
		
		void typePassword()
		{
			string pass="";
	    	char entry;
	    	cout<<"\n\t\t\tEnter Password: ";
	    	entry=getch();
	    	
	    	while(entry!=13)      //character 13 is 'ENTER KEY'
	    	{
	    		cout<<"*";
	    		pass += entry;    //BY-defualt overloading of string +=;
	         	entry=getch();
			}
			setPassword(pass);
		}
		void loginAdmin(){
			system("cls");
			cout<<"\n\n\t\t\t>>>>>>>>>>>  AMAZON PRODUCTS DATA MANIPULATION SYSTEM  <<<<<<<<<<<";
			cout<<"\n\t\t\t------------------------------------------------------------------";
			cout<<"\n\n\t\t\t\t               "<<(char)04<<(char)04<<(char)04<<" ADMIN LOGIN "<<(char)04<<(char)04<<(char)04<<"\n\n\n";
			
			 ifstream readAdmin("adminRecord.dat",ios::binary);
			 LogIn obj;
			 
			
			 
			 if(!readAdmin)
			 {
			 	cout<<"\n\t\tFile could not be open!\n";
			 	exit(1);    //unsuccessful result.
			 }
		
		  	static int remaining_try = 3;  //Static helps when function called multiple times. The remaining try keeps same.
		    readAdmin.seekg(0,ios::beg);
			while(remaining_try > 0)  //correct password and id show be asked three times only.
			{
				remaining_try--;
				
			 cout<<"\t\t\tEnter Login ID : ";
			 cin>>id;
			 // validates the integer type input
			 cinCheck(id,"Login ID");
			 typePassword();
		 	 	
			 
			 int check=0;
			 readAdmin.read(reinterpret_cast<char*>(&obj),sizeof(LogIn));
			 
			 while(!readAdmin.eof())
			 {
				if( (obj.getID() == id ) &&
					obj.getPassword() == password)
			 	{
			 		check=1;
			 		break;
				}
				else 
				{		
		    		readAdmin.read(reinterpret_cast<char*>(&obj),sizeof(LogIn));
				}
			 
			 }readAdmin.seekg(0,ios::beg); //resetting cursor position. 
			 
			 //after inner-while.
			 if(check == 1)
			 {
			 	cout<<"\n\n\t\t\tAccess Granted....";
			 	remaining_try = 3;
			 	break;
			 }
			 else if(check==0)
			 {
			 	cout<<"\n\t\t\tIncorrect details!    "<<(char)16<<(char)16<<" TRY REMAINING: "<<remaining_try<<" "<<(char)17<<(char)17;
			 	cout<<"\n\n\t Press Any Key... ";
			    getch();
			    loginAdmin(); // recursion
			 }
		}
		   //outside the outer while loop 
		   if( remaining_try == 0)
		   {
		   	cout<<"\n\n\t\t\tAll trys have been used....";
		   	cout<<"\n\n\t Press Enter to Go Back... ";			    	
		    getch();
			remaining_try=3;  // RESETTING it to again for 3.
			system("cls");
			display();
		   }
			//this will only run if account found otherwise programm moves toward display() function;
	        
		 	cout<<"\n\nPress Any Key...";
		    getch();
		    cout<<"\n\nLoading.....";
		    Sleep(2000);
		    system("cls");
		    categoryWindow();
		        
		}

		void display()
		{ 
			cout<<"\n\n\t\t\t>>>>>>>>>>>  AMAZON PRODUCTS DATA MANIPULATION SYSTEM  <<<<<<<<<<<";
			cout<<"\n\t\t\t------------------------------------------------------------------";
			cout<<"\n\n\t\t\t\t               "<<(char)04<<(char)04<<(char)04<<" WELCOME "<<(char)04<<(char)04<<(char)04<<"\n\n\n";
        	cout<<"\n\n\t\t\tEnter 1 : ADMIN LOGIN ";
			cout<<"\n\n\t\t\tEnter 0 : EXIT ";
			cout<<"\n\t\t\t------------------------------------------------------------------";
            cout<<"\n\n\n\t\t\tPlease Enter Your Choice : ";

                // Taking the action input
                int choice;
                do{
					cout<<"\n\t\t\tEnter the choice : ";
					cin>>choice;
                    cinCheck(choice," choice ");
			 	}
			 	while(choice < 0 || choice > 1);
                
                if(choice == 1)
                {
                	cout<<"\n\n\nLoading.......";
                	Sleep(2000);
                	system("cls");
                    loginAdmin();
				}
				else if(choice == 0)
				{
					cout<<"\n\n\nLoading.......";
                	Sleep(2000);
                	system("cls");
                	exit(0);
				}
		}
		void techWindow(){
 
			cout<<"\n\n\t\t\t>>>>>>>>>>>  AMAZON PRODUCTS DATA MANIPULATION SYSTEM  <<<<<<<<<<<";
			cout<<"\n\t\t\t------------------------------------------------------------------";
			cout<<"\n\n\t\t\t\t               "<<(char)04<<(char)04<<(char)04<<" TECHNOLOGY "<<(char)04<<(char)04<<(char)04<<"\n\n\n";
        	cout<<"\n\n\t\t\tEnter 1 : SOFTWARE";
			cout<<"\n\n\t\t\tEnter 2 : VIDEO GAMES";
			cout<<"\n\n\t\t\tEnter 3 : BACK";
			cout<<"\n\n\t\t\tEnter 4 : LOGOUT";
			cout<<"\n\n\t\t\tEnter 0 : EXIT ";
			cout<<"\n\t\t\t------------------------------------------------------------------";
            cout<<"\n\n\n\t\t\tPlease Enter Your Choice : ";

                // Taking the action input
                int choice;
                do{
					cout<<"\n\t\t\tEnter the choice : ";
					cin>>choice;
                    cinCheck(choice," choice ");
			 	}
			 	while(choice < 0 || choice > 4);
                
                if(choice == 1)
                {
                	cout<<"\n\n\nLoading.......";
                    // SOFT FUNCTION
                    Software sft;
					cout<<"\n\n\nLoading.......";
                	system("cls");
                    sft.displayFeatures();
                    
				}
				else if(choice == 2){
                	cout<<"\n\n\nLoading.......";
                    // VIDEO GAMES FUNCTION	
					VideoGames vg;
					cout<<"\n\n\nLoading.......";
                	system("cls");
					vg.displayFeatures();		
				}
				else if(choice == 3){
                	cout<<"\n\n\nLoading.......";
                	Sleep(2000);
                	system("cls");
                    categoryWindow();					
				}
				else if(choice == 4){
                	cout<<"\n\n\nLoading.......";
                	Sleep(2000);
                	system("cls");
                    display();					
				}
				else if(choice == 0)
				{
					cout<<"\n\n\nLoading.......";
                	Sleep(2000);
                	system("cls");
                	exit(0);
				}
		}			
		void entertainmentWindow(){
 
			cout<<"\n\n\t\t\t>>>>>>>>>>>  AMAZON PRODUCTS DATA MANIPULATION SYSTEM  <<<<<<<<<<<";
			cout<<"\n\t\t\t------------------------------------------------------------------";
			cout<<"\n\n\t\t\t\t               "<<(char)04<<(char)04<<(char)04<<" ENTERTAINMENT "<<(char)04<<(char)04<<(char)04<<"\n\n\n";
        	cout<<"\n\n\t\t\tEnter 1 : MOVIES AND TV";
			cout<<"\n\n\t\t\tEnter 2 : MUSIC OR SONGS";
			cout<<"\n\n\t\t\tEnter 3 : BACK";
			cout<<"\n\n\t\t\tEnter 4 : LOGOUT";
			cout<<"\n\n\t\t\tEnter 0 : EXIT ";
			cout<<"\n\t\t\t------------------------------------------------------------------";
            cout<<"\n\n\n\t\t\tPlease Enter Your Choice : ";

                // Taking the action input
                int choice;
                do{
					cout<<"\n\t\t\tEnter the choice : ";
					cin>>choice;
                    cinCheck(choice," choice ");
			 	}
			 	while(choice < 0 || choice > 4);
                
                if(choice == 1)
                {
                	cout<<"\n\n\nLoading.......";
                    // MOVIES AND TV FUNCTION
                    MoviesTV mt;
					cout<<"\n\n\nLoading.......";
                	system("cls");
                    mt.displayFeatures(true);
				}
				else if(choice == 2){
                	cout<<"\n\n\nLoading.......";
                    // MUSIC FUNCTION
					Music m;
					cout<<"\n\n\nLoading.......";
                	system("cls");
					m.displayFeatures(true);					
				}
				else if(choice == 3){
                	cout<<"\n\n\nLoading.......";
                	Sleep(2000);
                	system("cls");
                    categoryWindow();					
				}
				else if(choice == 4){
                	cout<<"\n\n\nLoading.......";
                	Sleep(2000);
                	system("cls");
                    display();					
				}
				else if(choice == 0)
				{
					cout<<"\n\n\nLoading.......";
                	Sleep(2000);
                	system("cls");
                	exit(0);
				}
		}			
		void categoryWindow(){
 
			cout<<"\n\n\t\t\t>>>>>>>>>>>  AMAZON PRODUCTS DATA MANIPULATION SYSTEM  <<<<<<<<<<<";
			cout<<"\n\t\t\t------------------------------------------------------------------";
			cout<<"\n\n\t\t\t\t               "<<(char)04<<(char)04<<(char)04<<" CATEGORIES "<<(char)04<<(char)04<<(char)04<<"\n\n\n";
        	cout<<"\n\n\t\t\tEnter 1 : TECHNOLOGY ";
			cout<<"\n\n\t\t\tEnter 2 : ENTERTAINMENT ";
			cout<<"\n\n\t\t\tEnter 3 : LOGOUT ";
			cout<<"\n\n\t\t\tEnter 0 : EXIT ";
			cout<<"\n\t\t\t------------------------------------------------------------------";
            cout<<"\n\n\n\t\t\tPlease Enter Your Choice : ";

                // Taking the action input
                int choice;
                do{
					cout<<"\n\t\t\tEnter the choice : ";
					cin>>choice;
                    cinCheck(choice," choice ");
			 	}
			 	while(choice < 0 || choice > 3);
                
                if(choice == 1)
                {
                	cout<<"\n\n\nLoading.......";
                	Sleep(2000);
                	system("cls");
                    // TECH FUNCTION
                    techWindow();
				}
				else if(choice == 2){
                	cout<<"\n\n\nLoading.......";
                	Sleep(2000);
                	system("cls");
                    // Entertainment FUNCTION
					entertainmentWindow();					
				}
				else if(choice == 3){
                	cout<<"\n\n\nLoading.......";
                	Sleep(2000);
                	system("cls");
					display();					
				}
				else if(choice == 0)
				{
					cout<<"\n\n\nLoading.......";
                	Sleep(2000);
                	system("cls");
                	exit(0);
				}
		}
};
