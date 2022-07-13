// C++ program for implementing B+ Tree
#include <climits>
#include <fstream>
#include <iostream>
#include <sstream>
#include <string>
#include <queue>
#include <vector>
#include <stack>
using namespace std;
int MAX = 60;

class SortedProduct{
	public:
		double filePrice;
		string data;
		double rating;
		string title;
		SortedProduct(string id, string title, double p, double rat){
			filePrice = p;
			data = id;
			rating = rat;
			this->title = title;
		}
};

template <typename T>
class keys
{
  public:
  T data;
  vector<streampos> keyReview;

  void displayReview()
  {
	  for(int i=0;i<keyReview.size();i++)
	  {
		  cout<<keyReview[i]<<"  ";
	  }
	  cout<<endl;
  }
};

// BP Node<T>
template <typename T>
class Node {
    public:
    int size;
	bool IS_LEAF;
	keys<T> *keyData;
	Node** ptr;
	Node* nextPtr;
	Node();
};

// BP tree
template <typename T>
class BPTree {
	public:
	Node<T>* root;
	string fileLocation;

	BPTree();
	BPTree(string);
	Node<T>* findParent(Node<T>*, Node<T>*);
	void insertInternal(T,Node<T>*,Node<T>*);
	void search(string);
	void insert(T,streampos);
	void display(Node<T>*);
	Node<T>* getRoot();
    void insertCsvData();


	void displayReview(keys<T> ptr,streampos location, string fileLocation, vector<SortedProduct> &sorted, bool shouldSort){
      
       fstream fOpen;
	   string whole;
	   fOpen.open(fileLocation, ios::in);
	    
       string headings[]={"Product/ProductId","Product/Title","Product/Price","Product/Rating"};
	   string Id,Title,data;
	   double price;
	   double rating;

	   int headingNumberInFile[]={2,3,4,7};
	   int size=sizeof(headingNumberInFile)/sizeof(headingNumberInFile[0]);
	  
	   fOpen.seekg(location);
	   getline(fOpen,whole);
       
	   stringstream obj(whole);
        
        for(int i=1; i<=headingNumberInFile[size-1]+1;i++)
		{
            if(i==1)
			{
				getline(obj,Id,',');
				// cout<<endl<<Id<<endl;
			}
            else if(i<=2)
			{
				getline(obj,Id,',');
			}
            else if(i==3)
			{
	     		   getline(obj,Title,',');
			}
            else if(i==4)
			{
	     		   getline(obj,data,',');
					price=stod(data);
			}
            else if(i==8)
			{
	     		   getline(obj,data,',');
					rating=stod(data);
			}
			else{
	     		   getline(obj,data,',');
			}

		}
		if(shouldSort){
			SortedProduct obj1(Id, Title, price, rating);
			sorted.push_back(obj1);
		}
		else if(!shouldSort){


        cout<<endl;
		cout<<headings[0]<<":  "<<Id<<endl;
		cout<<headings[1]<<":  "<<Title<<endl;
		cout<<headings[2]<<":  "<<price<<endl;
		cout<<headings[3]<<":  "<<rating<<endl;
        cout<<endl;
		}
   }

    void setLocation(string loc){
        fileLocation = loc;
    }
	void topProduct(string fileLocation, bool istop,vector<SortedProduct> &sorted,bool shouldSort, int howMuch=50)
{
	int count = 0;
	stack<Node<T>*> st;
	vector<keys<T>> add;
    st.push(root);
	while(!st.empty())
	{
		Node<T>* tmp = st.top();
		st.pop();

		if(tmp->IS_LEAF==false) 
		{
			for(int i = 0; i<=tmp->size; i++)
			{
				st.push(tmp->ptr[i]);
			}
		}
			
		if(count==howMuch)
		{
			break;
		}

       if(tmp->IS_LEAF==true)
		{
			for(int j=0; j<tmp->size; j++)
			{
				for(int k=0; k<tmp->keyData[j].keyReview.size() && count<howMuch; k++)
				{
					fstream fOpen;
						string whole;
					fOpen.open(fileLocation, ios::in);
					fOpen.seekg(tmp->keyData[j].keyReview[k],ios::beg);

					getline(fOpen,whole);
					stringstream obj(whole);
					double value;

				for(int b=0;b<8 && count<howMuch;b++) {
					if(b==7)
					{
						obj>>value;
						break;
					}
					getline(obj,whole,',');
					}

				if(istop && value>=4.9)
				{
						bool flag = false;
						for(int m=0;m<add.size();m++)
						{
							if(add[m].data==tmp->keyData[j].data)
							{
								flag = true;
								break;
							}
						}
					if(flag)
						continue;
					count++;	
					// cout<<"Value found"<<count;
					add.push_back(tmp->keyData[j]);
					displayReview(tmp->keyData[j],tmp->keyData[j].keyReview[k], fileLocation,sorted, shouldSort);
				}
				else if(!istop && value< 1.1)
				{
						bool flag = false;
						for(int m=0;m<add.size();m++)
						{
							if(add[m].data==tmp->keyData[j].data)
							{
								flag = true;
								break;
							}
						}
					if(flag)
						continue;

					count++;
					// cout<<"Value found"<<count;
					add.push_back(tmp->keyData[j]);
					displayReview(tmp->keyData[j],tmp->keyData[j].keyReview[k], fileLocation,sorted, false);
				}
				
				}
			}
		}
 
	}
  
}
	void AllProduct(string fileLocation, vector<SortedProduct> &sorted, int howMuch=200)
{
	int count = 0;
	stack<Node<T>*> st;
	vector<keys<T>> add;
    st.push(root);
	while(!st.empty())
	{
		Node<T>* tmp = st.top();
		st.pop();

		if(tmp->IS_LEAF==false) 
		{
			for(int i = 0; i<=tmp->size; i++)
			{
				st.push(tmp->ptr[i]);
			}
		}
			
		if(count==howMuch)
		{
			break;
		}

       if(tmp->IS_LEAF==true)
		{
			for(int j=0; j<tmp->size; j++)
			{
				for(int k=0; k<tmp->keyData[j].keyReview.size() && count<howMuch; k++)
				{
					fstream fOpen;
						string whole;
					fOpen.open(fileLocation, ios::in);
					fOpen.seekg(tmp->keyData[j].keyReview[k],ios::beg);

					getline(fOpen,whole);
					stringstream obj(whole);
					double value;

				for(int b=0;b<8 && count<howMuch;b++) {
					if(b==7)
					{
						obj>>value;
						break;
					}
					getline(obj,whole,',');
					}

				if(value>=1.9 &&  value <= 5.0)
				{
						bool flag = false;
						for(int m=0;m<add.size();m++)
						{
							if(add[m].data==tmp->keyData[j].data)
							{
								flag = true;
								break;
							}
						}
					if(flag)
						continue;
					count++;	
					// cout<<"Value found"<<count;
					add.push_back(tmp->keyData[j]);
					displayReview(tmp->keyData[j],tmp->keyData[j].keyReview[k], fileLocation, sorted, false);
				}
				
				}
			}
		}
 
	}
  
}
    void display()
	{
		queue<Node<T>*> q;
		queue<string> level;
        string arr[]={"a", "b","c","d","e","f","g","h","i","j","k","l","m","n","o","p","q","r","s","t","u","v","w","k","l","m","n","o","p","q","r","s","t","u","v","w"};

		 q.push(root);
		 level.push("1");

        while(!q.empty())
		
		{
			Node<T>* tmp=q.front();
			q.pop();
            
			string lev=level.front();
			cout<<"\n\t\tLEVEL IS:"<<lev<<endl;
			level.pop();

		  if(tmp->IS_LEAF==false)
		  {
			for(int i=0;i<tmp->size;i++)
			{
					cout<<tmp->keyData[i].data<<":  ";
					q.push(tmp->ptr[i]);
					int str=lev[0]-48+1;
					string str2=to_string(str)+arr[i];
					level.push(str2);
					tmp->keyData[i].displayReview();
			}
			cout<<endl<<endl;
			int str=lev[0]-48+1;
			string str2=to_string(str)+arr[tmp->size];
			level.push(str2);
			q.push(tmp->ptr[tmp->size]);
		  }
		  else{
			  for(int i=0;i<tmp->size;i++)
			{
					cout<<tmp->keyData[i].data<<": ";
					tmp->keyData[i].displayReview();
			}
			cout<<endl<<endl;
		  }
		}
	}


   void displayReview(keys<T> ptr){
      
         
       fstream fOpen;
	   string whole;
	   fOpen.open(fileLocation+".csv", ios::in);
	    
       string headings[]={"Product/ProductId","Product/Title","Product/Price"};
	   string Id,Title,data,RecordId;
	   double price;

	   int headingNumberInFile[]={2,3,4};
	   int size=sizeof(headingNumberInFile)/sizeof(headingNumberInFile[0]);
	  
	   fOpen.seekg(ptr.keyReview[0], ios::beg);
	   getline(fOpen,whole);
       
	   stringstream obj(whole);
        
        for(int i=1; i<=headingNumberInFile[size-1];i++)
		{
            if(i==1)
			{
				getline(obj,RecordId,',');
			}
            else if(i<=2)
			{
				getline(obj,Id,',');
			}
            else if(i==3)
			{
	     		getline(obj,Title,',');
			}
            else if(i==4)
			{
	     		getline(obj,data,',');
				price=stod(data);
			}
		}

        cout<<endl;
		cout<<"\t\t\tRecord ID      :"<<RecordId<<endl;
		cout<<"\t\t\tProduct ID     :"<<Id<<endl;
		cout<<"\t\t\tProduct Title  :"<<Title<<endl;
		cout<<"\t\t\tProduct Price  :"<<price<<"$"<<endl;
        cout<<"\t\t\tReview Summary : "<<endl;
		cout<<endl<<"\t\t\tAll Reviews..."<<endl;
		for(int i = 0;i <ptr.keyReview.size() ; i++)
		{
			fOpen.seekg(ptr.keyReview[i], ios::beg);
          	getline(fOpen,whole);
			string word,temp;
			stringstream newObj(whole);
			for(int j=1; j<=9;j++)
			{
				getline(newObj,temp,',');
				if(j==9)
				{
					getline(newObj,word,',');
					cout<<"\n\t\t\t"<<i<<" - {"<<word<<"}"<<endl;
				}
			}// end for

		} // end review for
   }



};

// Constructor of Node<T>

template <typename T>
Node<T>::Node()
{
	keyData=new keys<T>[MAX];
	ptr = new Node<T>*[MAX + 1];
	nextPtr=NULL;
}

// Initialise the BPTree Node<T>

template <typename T>
BPTree<T>::BPTree()
{
	root = NULL;

}
template <typename T>
BPTree<T>::BPTree(string loc)
{
	fileLocation = loc;
	root = NULL;
	
}

// Function to find any element
// in B+ Tree

template <typename T>
void BPTree<T>::search(string x)
{

	// If tree is empty
	if (root == NULL) {
		cout << "Tree is empty\n";
	}

	// Traverse to find the value
	else {

		Node<T>* cursor = root;

		// Till we reach leaf Node<T>
		while (cursor->IS_LEAF == false) {

			for (int i = 0;i < cursor->size; i++) {

				// If the element to be
				// found is not present
				if (x > cursor->keyData[i].data) {
					cursor = cursor->ptr[i];
					break;
				}

				// If reaches end of the
				// cursor Node<T>
				if (i == cursor->size - 1) {
					cursor = cursor->ptr[i + 1];
					break;
				}
			}
		}

		// Traverse the cursor and find
		// the Node<T> with value x
		for (int i = 0;i < cursor->size; i++) {

			// If found then return
			if (cursor->keyData[i].data == x) {
				cout<<"\t\t\tFound Record!!!"<<endl<<endl;
				displayReview(cursor->keyData[i]);
				return;
			}
		}

		// Else element is not present
		cout << "Not found\n";
	}
}



template <typename T>
void BPTree<T>::insert(T x,streampos location)
{

	// If root is null then return
	// newly created Node<T>
	if (root == NULL) {
		root = new Node<T>();

		root->keyData->data = x;
		root->keyData->keyReview.push_back(location);
		root->IS_LEAF = true;
		root->size = 1;
		return;
	}

	// Traverse the B+ Tree
	else {
		Node<T>* cursor = root;
		Node<T>* parent;

		// Till cursor reaches the
		// leaf Node<T>
		while (cursor->IS_LEAF== false) {
			parent = cursor;

			for (int i = 0;i < cursor->size;	i++) {

				// If found the position
				// where we have to insert
				// Node<T>
				if (x > cursor->keyData[i].data) {
					cursor= cursor->ptr[i];
					break;
				}

				// If reaches the end
				if (i == cursor->size - 1) {
					cursor= cursor->ptr[i + 1]; //it will move the cursor to its last child
					break;
				}
			}
		}

		if (cursor->size <= MAX) {
			int i = 0;
			while (i < cursor->size&&x < cursor->keyData[i].data && x!= cursor->keyData[i].data) {
				i++;
			}

			//adding a new review.
			if(x==cursor->keyData[i].data) {
				cursor->keyData[i].keyReview.push_back(location);
				  return;
			}

           else if(cursor->size<MAX)
		   {
				//forward moving data.
				for (int j = cursor->size;j > i; j--) {
					cursor->keyData[j] = cursor->keyData[j-1];
					cursor->keyData[j-1].keyReview.clear();
				}
				cursor->keyData[i].data = x;
				cursor->size++;
				//**ADDING REVIEW
					cursor->keyData[i].keyReview.push_back(location);
                //****
				cursor->ptr[cursor->size]= cursor->ptr[cursor->size - 1];
				cursor->ptr[cursor->size - 1] = NULL;
				return;
		   }    
		}

			// Create a newLeaf Node<T>
			Node<T>* newLeaf = new Node<T>;
			keys<T> virtualNode[MAX + 2];

			// Update cursor to virtual
			// Node<T> created
			for (int i = 0; i < MAX; i++) {
				virtualNode[i]= cursor->keyData[i];
			}
			int i = 0, j;

			// Traverse to find where the new
			// Node<T> is to be inserted
			while (i < MAX && x < virtualNode[i].data ) {
				i++;
			}
			
			unsigned long long int hold=location;

			// Update the current virtual
			// Node<T> to its previous
			for (int j = MAX + 1;j > i; j--) {
				virtualNode[j]= virtualNode[j - 1];
				virtualNode[j-1].keyReview.clear();
			}

			virtualNode[i].data = x;
			virtualNode[i].keyReview.push_back(hold);
			newLeaf->IS_LEAF = true;

			cursor->size = (MAX + 1) / 2;
			newLeaf->size= MAX + 1 - (MAX + 1) / 2;

			cursor->ptr[cursor->size]= newLeaf;
			newLeaf->ptr[newLeaf->size]= cursor->ptr[MAX];
			cursor->ptr[MAX] = NULL;

			// Update the current virtual
			// Node<T>'s key to its previous
			for (i = 0;i < cursor->size; i++) {
				cursor->keyData[i]= virtualNode[i];
			}
			
			//here inserted...
            //  cursor->nextPtr=newLeaf;
			
			// Update the newLeaf key to
			// virtual Node<T>
			for (i = 0, j = cursor->size;i < newLeaf->size;i++, j++) {
				newLeaf->keyData[i]= virtualNode[j];
			}

			// If cursor is the root Node<T>
			if (cursor == root) {

				// Create a new Node<T>
				Node<T>* newRoot = new Node<T>();

				// Update rest field of
				// B+ Tree Node<T>
				newRoot->keyData[0].data = newLeaf->keyData[0].data;
				newRoot->ptr[0] = cursor;
				newRoot->ptr[1] = newLeaf;
				newRoot->IS_LEAF = false;
				newRoot->size = 1;
				root = newRoot;
			}
			else {

				// Recursive Call for
				// insert in internal
				insertInternal(newLeaf->keyData[0].data,parent,newLeaf);
			}
	}
}

// Function to implement the Insert
// Internal Operation in B+ Tree

template <typename T>
void BPTree<T>::insertInternal(T x,Node<T>*cursor,Node<T>* child)
{

	// If we doesn't have overflow
	if (cursor->size < MAX) {
		int i = 0;

		// Traverse the child Node<T>
		// for current cursor Node<T>
		while ( i < cursor->size&&x < cursor->keyData[i].data) {
			i++;
		}

		// Traverse the cursor Node<T>
		// and update the current key
		// to its previous Node<T> key
		for (int j = cursor->size;j > i; j--) {
				cursor->keyData[j] = cursor->keyData[j-1];
				cursor->keyData[j-1].keyReview.clear();
		}

		// Traverse the cursor Node<T>
		// and update the current ptr
		// to its previous Node<T> ptr
		for (int j = cursor->size + 1;j > i + 1; j--) {
			cursor->ptr[j]= cursor->ptr[j - 1];
		}

		cursor->keyData[i].data = x;
		cursor->size++;
		cursor->ptr[i + 1] = child;
	}

	// For overflow, break the Node<T>
	else {

		// For new Interval
		Node<T>* newInternal = new Node<T>();
		keys<T> virtualKey[MAX + 2];
		Node<T>* virtualPtr[MAX + 3];

		// Insert the current list key
		// of cursor Node<T> to virtualKey
		for (int i = 0; i < MAX; i++) {
			virtualKey[i] = cursor->keyData[i];
		}

		// Insert the current list ptr
		// of cursor Node<T> to virtualPtr
		for (int i = 0; i < MAX + 1; i++) {
			virtualPtr[i] = cursor->ptr[i];
		}

		int i = 0, j;

		// Traverse to find where the new
		// Node<T> is to be inserted
		while ( i < MAX&& x < virtualKey[i].data ) {
			i++;
		}

		// Traverse the virtualKey Node<T>
		// and update the current key
		// to its previous Node<T> key
		for (int j = MAX + 1;j > i; j--) {

			virtualKey[j]= virtualKey[j - 1];
			virtualKey[j-1].keyReview.clear();
		}

		virtualKey[i].data = x;

		// Traverse the virtualKey Node<T>
		// and update the current ptr
		// to its previous Node<T> ptr
		for (int j = MAX + 2;j > i + 1; j--) {
			virtualPtr[j]= virtualPtr[j - 1];
		}

		virtualPtr[i + 1] = child;
		newInternal->IS_LEAF = false;

		cursor->size= (MAX + 1) / 2;

		newInternal->size= MAX - (MAX + 1) / 2;

		// Insert new Node<T> as an
		// internal Node<T>
		for (i = 0, j = cursor->size + 1;i < newInternal->size;i++, j++) {

			newInternal->keyData[i]= virtualKey[j];
		}

		for (i = 0, j = cursor->size + 1;i < newInternal->size + 1;i++, j++) {

			newInternal->ptr[i]= virtualPtr[j];
		}

		// If cursor is the root Node<T>
		if (cursor == root) {

			// Create a new root Node<T>
			Node<T>* newRoot = new Node<T>;

			// Update key value
			newRoot->keyData[0].data= cursor->keyData[cursor->size].data;

			// Update rest field of
			// B+ Tree Node<T>
			newRoot->ptr[0] = cursor;
			newRoot->ptr[1] = newInternal;
			newRoot->IS_LEAF = false;
			newRoot->size = 1;
			root = newRoot;
		}

		else {

			// Recursive Call to insert
			// the data
			insertInternal(cursor->keyData[cursor->size].data,findParent(root,cursor),newInternal);
		}
	}
}

// Function to find the parent Node<T>
template<class T>
Node<T>* BPTree<T>::findParent(Node<T>* cursor,
						Node<T>* child)
{
	Node<T>* parent;

	// If cursor reaches the end of Tree
	if (cursor->IS_LEAF
		|| (cursor->ptr[0])->IS_LEAF) {
		return NULL;
	}

	// Traverse the current Node<T> with
	// all its child
	for (int i = 0;
		i < cursor->size + 1; i++) {

		// Update the parent for the
		// child Node<T>
		if (cursor->ptr[i] == child) {
			parent = cursor;
			return parent;
		}
		else {
			parent
				= findParent(cursor->ptr[i],
							child);
	if (parent != NULL)
				return parent;
		}
	}

	// Return parent Node<T>
	return parent;
}

// Function to get the root Node<T>
template<class T>
Node<T>* BPTree<T>::getRoot()
{
	return root;
}

template<class T>
void BPTree<T>::insertCsvData(){
	fstream fin;
	string line;

	fin.open(fileLocation +".csv", ios::in);
	streampos prev=fin.tellg();
        getline(fin, line);


     while(!fin.eof())
	 {
		 prev=fin.tellg();
        getline(fin, line);
		streampos current=fin.tellg();

        if(line!="")
		{
		stringstream s(line);
		getline(s, line, ',');
		getline(s, line, ',');
        this->insert(line,prev);
		}
	 }
}

// int main()
// {
// 	vector<SortedProduct> sorted;


//     BPTree<string> node;
// 	node.setLocation("UpdatedSoftware");
// 	node.insertCsvData();
// 	// node.AllProduct("UpdatedSoftware.csv");
// 	node.topProduct("UpdatedSoftware.csv", true,sorted, true);
	
	
// 	int count=0; 
// 	for(int i=0;i<sorted.size() && count <= 10;i++){
// 		count++;
// 		int min = i;
// 		for(int j=i+1;j < sorted.size() && count <= 10;j++){
// 			if(sorted[min].filePrice >  sorted[j].filePrice){
// 				min = j;
// 				cout<<"Working";
// 			}
// 		}
// 		if(count < 10){
// 		SortedProduct temp = sorted[i];
// 		sorted[i] = sorted[min];
// 		sorted[min] = temp;
// 		}
// 	}

// 	cout<<endl;
// 	if(count >= 10){

// 	for(int  i=0;i<10;i++){
// 		cout<<endl;
// 		cout<<sorted[i].filePrice<<"  ";
// 		cout<<sorted[i].data<<"  ";
// 		cout<<sorted[i].rating<<"  ";
// 		cout<<sorted[i].title<<"  ";
// 	}
// }
// else if(count < 10){
// 		for(int  i=0;i<sorted.size();i++){
// 		cout<<endl;
// 		cout<<sorted[i].filePrice<<"  ";
// 		cout<<sorted[i].data<<"  ";
// 		cout<<sorted[i].rating<<"  ";
// 		cout<<sorted[i].title<<"  ";
// 	}
// }
// // node.search("B000077CE8");
//     // node.display();
// 	// node.topProduct(fileLocation);
// // node.search("B00002S87P",fileLocation);

// 	return 0;
// }