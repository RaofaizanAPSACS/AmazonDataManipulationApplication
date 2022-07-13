#include<iostream>
using namespace std;   
   
   template<class T>
   void cinCheck(T& data,string msg)
   {
        while(cin.fail())
	       {
	 	     cout<<"\n\n\t\t\tWrong DataType Input!";
	 	
	    	 cin.clear();fflush(stdin); //clearing buffer.
	 	
		     cout<<"\n\t\t\tEnter " <<msg<< " again  : ";
	         cin>>data;
	        }
    }
