#include<iostream>
#include<fstream>
#include<conio.h>
#include "cinCheck.h"
#include<windows.h>
#include "Bptree.h"

using namespace std;

// declared as global helper back functions 
void techWindow();
void entertainmentWindow();
void categoryWindow();

// Abstract class of the amazon product and later will be generaziled with specefic products
class Product{
	protected:
		BPTree<string> productRecords;
	public:
		void displayFeatures(bool);
		void staticHeader(string);
		virtual void topProducts() = 0;
		virtual void bestPricingProducts() = 0;
		virtual void searchProducts() = 0;
		virtual void worstProducts() = 0;
		virtual void displayAllProducts() = 0;
};
		
void categoryWindow(){

	cout<<"\n\n\t\t\t>>>>>>>>>>>  AMAZON PRODUCTS DATA MANIPULATION SYSTEM  <<<<<<<<<<<";
	cout<<"\n\t\t\t------------------------------------------------------------------";
	cout<<"\n\n\t\t\t\t               "<<(char)04<<(char)04<<(char)04<<" CATEGORIES "<<(char)04<<(char)04<<(char)04<<"\n\n\n";
	cout<<"\n\n\t\t\tEnter 1 : TECHNOLOGY ";
	cout<<"\n\n\t\t\tEnter 2 : ENTERTAINMENT ";
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
		while(choice < 0 || choice > 2);
		
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
		}
		else if(choice == 0)
		{
			cout<<"\n\n\nLoading.......";
			Sleep(2000);
			system("cls");
			exit(0);
		}
}
void Product::staticHeader(string msg){
	cout<<"\n\n\t\t\t>>>>>>>>>>>  AMAZON PRODUCTS DATA MANIPULATION SYSTEM  <<<<<<<<<<<";
	cout<<"\n\t\t\t------------------------------------------------------------------";
	cout<<"\n\n\t\t\t\t               "<<(char)04<<(char)04<<(char)04<<" "<<msg<<" "<<(char)04<<(char)04<<(char)04<<"\n\n\n";
        	
}
void Product::displayFeatures(bool backCheck = false){
			cout<<"\n\n\t\t\t>>>>>>>>>>>  AMAZON PRODUCTS DATA MANIPULATION SYSTEM  <<<<<<<<<<<";
			cout<<"\n\t\t\t------------------------------------------------------------------";
			cout<<"\n\n\t\t\t\t               "<<(char)04<<(char)04<<(char)04<<" FEATURES "<<(char)04<<(char)04<<(char)04<<"\n\n";
			cout<<"\n\n\t\t\tEnter 1 : TOP PRODUCTS ";
			cout<<"\n\n\t\t\tEnter 2 : WORST PRODUCTS ";
			cout<<"\n\n\t\t\tEnter 3 : BEST PRICE PRODUCTS ";
			cout<<"\n\n\t\t\tEnter 4 : SEARCH PRODUCTS ";
			cout<<"\n\n\t\t\tEnter 5 : DISPLAY ALL PRODUCTS ";
			cout<<"\n\n\t\t\tEnter 6 : BACK ";
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
			 	while(choice < 0 || choice > 6);
		        
		        if(choice == 1)
		        {
		        	cout<<"\n\n\nLoading.......";
		        	Sleep(2000);
		        	system("cls");
		       		topProducts();
		            
				}
				else if(choice == 2){
		        	cout<<"\n\n\nLoading.......";
		        	Sleep(2000);
		        	system("cls");
		       		worstProducts();
		            					
				}
				else if(choice == 3){
		        	cout<<"\n\n\nLoading.......";
		        	Sleep(2000);
		        	system("cls");	
					bestPricingProducts();				
				}
				else if(choice == 4){
		        	cout<<"\n\n\nLoading.......";
		        	Sleep(2000);
		        	system("cls");	
					searchProducts();				
				}
				else if(choice == 5){
		        	cout<<"\n\n\nLoading.......";
		        	Sleep(2000);
		        	system("cls");
					displayAllProducts();					
				}
				else if(choice == 6){
		       	cout<<"\n\n\nLoading.......";
		       	Sleep(2000);
		       	system("cls");
		       	
				if(backCheck == false){
					system("cls");
					techWindow();
					system("cls");
				}
				else{
					system("cls");
					entertainmentWindow();	
					system("cls");
					}
				}
				else if(choice == 0)
				{
					cout<<"\n\n\nLoading.......";
		        	Sleep(2000);
		        	system("cls");
		        	exit(0);
				}
}

class Software : public Product{
	public:
		Software(){
			MAX = 20;
			productRecords.setLocation("datasets/UpdatedSoftware");
			productRecords.insertCsvData();
		}
		void bestPricingProducts(){
			system("cls");
			staticHeader("Best Price Products");
			vector<SortedProduct> sorted;
			productRecords.setLocation("datasets/UpdatedSoftware");
			// productRecords.insertCsvData();
			// node.AllProduct("UpdatedSoftware.csv",sorted);
			productRecords.topProduct("datasets/UpdatedSoftware.csv", true,sorted, true);
			
			
			int count=0; 
			for(int i=0;i<sorted.size() && count <= 10;i++){
				count++;
				int min = i;
				for(int j=i+1;j < sorted.size() && count <= 10;j++){
					if(sorted[min].filePrice >  sorted[j].filePrice){
						min = j;
						// cout<<"Working";
					}
				}
				if(count < 10){
				SortedProduct temp = sorted[i];
				sorted[i] = sorted[min];
				sorted[min] = temp;
				}
			}

			cout<<endl;
			if(count >= 10){

			for(int  i=0;i<10;i++){
				cout<<endl;
				cout<<"Product ID      :"<<sorted[i].data<<endl;
				cout<<"Product Title  :"<<sorted[i].title<<endl;
				cout<<"Product Rating  :"<<sorted[i].rating<<endl;
				cout<<"Product Price  :"<<sorted[i].filePrice<<"$"<<endl;
			}
		}
		else if(count < 10){
				for(int  i=0;i<sorted.size();i++){
				cout<<endl;
				cout<<"Product ID      :"<<sorted[i].data<<endl;
				cout<<"Product Title  :"<<sorted[i].title<<endl;
				cout<<"Product Rating  :"<<sorted[i].rating<<endl;
				cout<<"Product Price  :"<<sorted[i].filePrice<<"$"<<endl;
				}
			}
			cout<<"\nPress any key to go Back...";
			getch();
			cout<<"\nLoading...";
			Sleep(2000);
			system("cls");
			displayFeatures();
		}
		void displayAllProducts(){
			system("cls");
			vector<SortedProduct> sorted;
			staticHeader("ALL Products");
			productRecords.AllProduct("datasets/UpdatedSoftware.csv",sorted);

			cout<<"\nPress any key to go Back...";
			getch();
			cout<<"\nLoading...";
			Sleep(2000);
			system("cls");
			displayFeatures();
		}
		void searchProducts(){
			system("cls");
			staticHeader("Search Software");
			string id;
			cout<<"\n\t\t\tEnter the Product ID to search (e.g B00029J1SG): ";
			cin>>id;cinCheck(id, "Product ID ");
			productRecords.search(id);

			cout<<"\nPress any key to go Back...";
			getch();
			cout<<"\nLoading...";
			Sleep(2000);
			system("cls");
			displayFeatures();
		}
		void topProducts(){
			system("cls");
			vector<SortedProduct> sorted;
			staticHeader("Top Products");
			productRecords.topProduct("datasets/UpdatedSoftware.csv", true,sorted, false);

			cout<<"\nPress any key to go Back...";
			getch();
			cout<<"\nLoading...";
			Sleep(2000);
			system("cls");
			displayFeatures();

		}
		void worstProducts(){
			system("cls");
			vector<SortedProduct> sorted;
			staticHeader("Worst Products");
			productRecords.topProduct("datasets/UpdatedSoftware.csv", false,sorted, false);

			cout<<"\nPress any key to go Back...";
			getch();
			cout<<"\nLoading...";
			Sleep(2000);
			system("cls");
			displayFeatures();
		}

};

class VideoGames : public Product{
	public:
		VideoGames(){
			MAX = 30;
			productRecords.setLocation("datasets/UpdatedVideo_Games");
			productRecords.insertCsvData();
		}
//		void displayFeatures();
//		void topProducts();
		void bestPricingProducts(){
			system("cls");
			staticHeader("Best Price Products");
			vector<SortedProduct> sorted;
			productRecords.setLocation("datasets/UpdatedVideo_Games");
			// productRecords.insertCsvData();
			// node.AllProduct("UpdatedSoftware.csv",sorted);
			productRecords.topProduct("datasets/UpdatedVideo_Games.csv", true,sorted, true);
			
			
			int count=0; 
			for(int i=0;i<sorted.size() && count <= 10;i++){
				count++;
				int min = i;
				for(int j=i+1;j < sorted.size() && count <= 10;j++){
					if(sorted[min].filePrice >  sorted[j].filePrice){
						min = j;
						// cout<<"Working";
					}
				}
				if(count < 10){
				SortedProduct temp = sorted[i];
				sorted[i] = sorted[min];
				sorted[min] = temp;
				}
			}

			cout<<endl;
			if(count >= 10){

			for(int  i=0;i<10;i++){
				cout<<endl;
				cout<<endl;
				cout<<"Product ID      :"<<sorted[i].data<<endl;
				cout<<"Product Title  :"<<sorted[i].title<<endl;
				cout<<"Product Rating  :"<<sorted[i].rating<<endl;
				cout<<"Product Price  :"<<sorted[i].filePrice<<"$"<<endl;
			}
		}
		else if(count < 10){
				for(int  i=0;i<sorted.size();i++){
				cout<<endl;
				cout<<"Product ID      :"<<sorted[i].data<<endl;
				cout<<"Product Title  :"<<sorted[i].title<<endl;
				cout<<"Product Rating  :"<<sorted[i].rating<<endl;
				cout<<"Product Price  :"<<sorted[i].filePrice<<"$"<<endl;
				}
			}
			cout<<"\nPress any key to go Back...";
			getch();
			cout<<"\nLoading...";
			Sleep(2000);
			system("cls");
			displayFeatures();
		}
		void displayAllProducts(){
			system("cls");
			vector<SortedProduct> sorted;
			staticHeader("ALL Products");
			productRecords.AllProduct("datasets/UpdatedVideo_Games.csv", sorted);

			cout<<"\nPress any key to go Back...";
			getch();
			cout<<"\nLoading...";
			Sleep(2000);
			system("cls");
			displayFeatures();
		}
		void searchProducts(){
			system("cls");
			staticHeader("Search Video Game");
			string id;
			cout<<"\n\t\t\tEnter the Product ID to search (e.g B00029J1SG): ";
			cin>>id;cinCheck(id, "Product ID ");
			productRecords.search(id);

			cout<<"\nPress any key to go Back...";
			getch();
			cout<<"\nLoading...";
			Sleep(2000);
			system("cls");
			displayFeatures();
		}
		void topProducts(){
			system("cls");
			vector<SortedProduct> sorted;
			staticHeader("Top Products");
			productRecords.topProduct("datasets/UpdatedVideo_Games.csv", true,sorted, false);

			cout<<"\nPress any key to go Back...";
			getch();
			cout<<"\nLoading...";
			Sleep(2000);
			system("cls");
			displayFeatures();

		}
		void worstProducts(){
			system("cls");
			vector<SortedProduct> sorted;
			staticHeader("Worst Products");
			productRecords.topProduct("datasets/UpdatedVideo_Games.csv", false,sorted, false);

			cout<<"\nPress any key to go Back...";
			getch();
			cout<<"\nLoading...";
			Sleep(2000);
			system("cls");
			displayFeatures();
		}

};

class MoviesTV : public Product{
	public:
		MoviesTV(){
			MAX = 30;
			productRecords.setLocation("datasets/UpdatedMovies_&_TV");
			productRecords.insertCsvData();
		}
//		void displayFeatures();
//		void topProducts();
		void bestPricingProducts(){
			system("cls");
			staticHeader("Best Price Products");
			vector<SortedProduct> sorted;
			productRecords.setLocation("datasets/UpdatedMovies_&_TV");
			// productRecords.insertCsvData();
			// node.AllProduct("UpdatedSoftware.csv",sorted);
			productRecords.topProduct("datasets/UpdatedMovies_&_TV.csv", true,sorted, true);
			
			
			int count=0; 
			for(int i=0;i<sorted.size() && count <= 10;i++){
				count++;
				int min = i;
				for(int j=i+1;j < sorted.size() && count <= 10;j++){
					if(sorted[min].filePrice >  sorted[j].filePrice){
						min = j;
						// cout<<"Working";
					}
				}
				if(count < 10){
				SortedProduct temp = sorted[i];
				sorted[i] = sorted[min];
				sorted[min] = temp;
				}
			}

			cout<<endl;
			if(count >= 10){

			for(int  i=0;i<10;i++){
				cout<<endl;
				cout<<"Product ID      :"<<sorted[i].data<<endl;
				cout<<"Product Title  :"<<sorted[i].title<<endl;
				cout<<"Product Rating  :"<<sorted[i].rating<<endl;
				cout<<"Product Price  :"<<sorted[i].filePrice<<"$"<<endl;
			}
		}
		else if(count < 10){
				for(int  i=0;i<sorted.size();i++){
				cout<<endl;
				cout<<"Product ID      :"<<sorted[i].data<<endl;
				cout<<"Product Title  :"<<sorted[i].title<<endl;
				cout<<"Product Rating  :"<<sorted[i].rating<<endl;
				cout<<"Product Price  :"<<sorted[i].filePrice<<"$"<<endl;
				}
			}
			cout<<"\nPress any key to go Back...";
			getch();
			cout<<"\nLoading...";
			Sleep(2000);
			system("cls");
			displayFeatures();

		}
		void displayAllProducts(){
			system("cls");
			vector<SortedProduct> sorted;
			staticHeader("ALL Products");
			productRecords.AllProduct("datasets/UpdatedMovies_&_TV.csv", sorted);

			cout<<"\nPress any key to go Back...";
			getch();
			cout<<"\nLoading...";
			Sleep(2000);
			system("cls");
			displayFeatures();
		}
		void searchProducts(){
			system("cls");
			staticHeader("Search Movies And TV");
			string id;
			cout<<"\n\t\t\tEnter the Product ID to search (e.g B00029J1SG): ";
			cin>>id;cinCheck(id, "Product ID ");
			productRecords.search(id);

			cout<<"\nPress any key to go Back...";
			getch();
			cout<<"\nLoading...";
			Sleep(2000);
			system("cls");
			displayFeatures(true);
		}
		void topProducts(){
			system("cls");
			vector<SortedProduct> sorted;
			staticHeader("Top Products");
			productRecords.topProduct("datasets/UpdatedMovies_&_TV.csv", true,sorted, false);

			cout<<"\nPress any key to go Back...";
			getch();
			cout<<"\nLoading...";
			Sleep(2000);
			system("cls");
			displayFeatures();

		}
		void worstProducts(){
			system("cls");
			vector<SortedProduct> sorted;
			staticHeader("Worst Products");
			productRecords.topProduct("datasets/UpdatedMovies_&_TV.csv", false,sorted, false);

			cout<<"\nPress any key to go Back...";
			getch();
			cout<<"\nLoading...";
			Sleep(2000);
			system("cls");
			displayFeatures();	
		}
};

class Music : public Product{
	public:
		Music(){
			MAX = 500;
			productRecords.setLocation("datasets/UpdatedMusic");
			productRecords.insertCsvData();
		}
		void bestPricingProducts(){

			system("cls");
			staticHeader("Best Price Products");
			vector<SortedProduct> sorted;
			productRecords.setLocation("datasets/UpdatedMusic");
			// productRecords.insertCsvData();
			// node.AllProduct("UpdatedSoftware.csv",sorted);
			productRecords.topProduct("datasets/UpdatedMusic.csv", true,sorted, true);
			
			
			int count=0; 
			for(int i=0;i<sorted.size() && count <= 10;i++){
				count++;
				int min = i;
				for(int j=i+1;j < sorted.size() && count <= 10;j++){
					if(sorted[min].filePrice >  sorted[j].filePrice){
						min = j;
						// cout<<"Working";
					}
				}
				if(count < 10){
				SortedProduct temp = sorted[i];
				sorted[i] = sorted[min];
				sorted[min] = temp;
				}
			}

			cout<<endl;
			if(count >= 10){

			for(int  i=0;i<10;i++){
				cout<<endl;
				cout<<"Product ID      :"<<sorted[i].data<<endl;
				cout<<"Product Title  :"<<sorted[i].title<<endl;
				cout<<"Product Rating  :"<<sorted[i].rating<<endl;
				cout<<"Product Price  :"<<sorted[i].filePrice<<"$"<<endl;
			}
		}
		else if(count < 10){
				for(int  i=0;i<sorted.size();i++){
				cout<<endl;
				cout<<"Product ID      :"<<sorted[i].data<<endl;
				cout<<"Product Title  :"<<sorted[i].title<<endl;
				cout<<"Product Rating  :"<<sorted[i].rating<<endl;
				cout<<"Product Price  :"<<sorted[i].filePrice<<"$"<<endl;
				}
			}
			cout<<"\nPress any key to go Back...";
			getch();
			cout<<"\nLoading...";
			Sleep(2000);
			system("cls");
			displayFeatures();
		}
		void displayAllProducts(){
			system("cls");
			vector<SortedProduct> sorted;
			staticHeader("ALL Products");
			productRecords.AllProduct("datasets/UpdatedMusic.csv",sorted);

			cout<<"\nPress any key to go Back...";
			getch();
			cout<<"\nLoading...";
			Sleep(2000);
			system("cls");
			displayFeatures();
		}
		void searchProducts(){
			system("cls");
			staticHeader("Search Music");
			string id;
			cout<<"\n\t\t\tEnter the Product ID to search (e.g B00029J1SG): ";
			cin>>id;cinCheck(id, "Product ID ");
			productRecords.search(id);
			
			cout<<"\nPress any key to go Back...";
			getch();
			cout<<"\nLoading...";
			Sleep(2000);
			system("cls");
			displayFeatures(true);
		}
		void topProducts(){
			system("cls");
			vector<SortedProduct> sorted;
			staticHeader("Top Products");
			productRecords.topProduct("datasets/UpdatedMusic.csv", true,sorted, false);

			cout<<"\nPress any key to go Back...";
			getch();
			cout<<"\nLoading...";
			Sleep(2000);
			system("cls");
			displayFeatures();

		}
		void worstProducts(){
			system("cls");
			vector<SortedProduct> sorted;
			staticHeader("Worst Products");
			productRecords.topProduct("datasets/UpdatedMusic.csv", false,sorted, false);

			cout<<"\nPress any key to go Back...";
			getch();
			cout<<"\nLoading...";
			Sleep(2000);
			system("cls");
			displayFeatures();
		}

};
void techWindow(){

	cout<<"\n\n\t\t\t>>>>>>>>>>>  AMAZON PRODUCTS DATA MANIPULATION SYSTEM  <<<<<<<<<<<";
	cout<<"\n\t\t\t------------------------------------------------------------------";
	cout<<"\n\n\t\t\t\t               "<<(char)04<<(char)04<<(char)04<<" TECHNOLOGY "<<(char)04<<(char)04<<(char)04<<"\n\n\n";
	cout<<"\n\n\t\t\tEnter 1 : SOFTWARE";
	cout<<"\n\n\t\t\tEnter 2 : VIDEO GAMES";
	cout<<"\n\n\t\t\tEnter 3 : BACK";
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
			system("cls");				
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
		else if(choice == 0)
		{
			cout<<"\n\n\nLoading.......";
			Sleep(2000);
			system("cls");
			exit(0);
		}
}			
