#include <iostream> 
#include <cstring> 
#include <fstream> 
using namespace std; 
 
int main() 
{ 
    string line, data; 
 
    ifstream fin;  
    cout << "====data in your file====" << endl; 
    while (getline(fin, line)) 
    { 
        data = data + line;    
        cout << line << endl; 
    } 
    line = ""; 
    for (int i = 0; i < data.length(); i++) 
    { 
        if (data[i] != 32) 
        { 
            line = line + data[i];  
        } 
    } 
    fin.close(); 
 
    ofstream fout;  
    fout.open("file2"); 
    fout << line; 
    fout.close(); 
 
    return 0;






elementsearchold.cpp
#include<iostream>
 using namespace std;
 
 int n,ele,beg,end;
 int bsearch(int arr[],int ele,int beg,int end){
 	if(beg>end){return -1;}
 	int mid=(beg+end)/2;
 	if(arr[mid]==ele)return mid;
 	else if(arr[mid]>ele){return bsearch(arr,ele,beg,mid-1);}
 	else{return bsearch(arr,ele,mid-1,end);}}

int main(){
	
 	cout<<"This program is to search an element from a set."<<endl;
 	
 	char ans='y';
    while (ans=='y' or ans=='Y'){
    	cout<<"Enter the number of elements in the set: ";cin>>n;cout<<"\nPlease enter elements in ascending order."<<endl;
    	int arr[n];
    	for(int i=0;i<n;i++){cout<<"Enter "<<i<<" element: ";cin>>arr[i];}
    	cout<<"Enter search element: ";cin>>ele;
    	beg=arr[0];
    	end=arr[n-1];
    	cout<<bsearch(arr,ele,beg,end)<<endl;
    	cout<<"\nDo you want to try with another set/element?(y/n) ";cin>>ans;}
    	return 0;
}







Prac1sumofn.cpp
// This program is to compute the sum of the first n terms of the series:
// S = 1 - 1/2^2 + 1/3^3 - 1/4^4 + --------------- 1/n^n
#include<iostream>
#include<cmath>
#include<typeinfo>
using namespace std;
int main()
{ 
    char ans='y';
    while (ans=='y' or ans=='Y')
    {
    	float sum=0;  // Initializing the sum as 0
    	int n;
    	cout<<"The series is 1-(1/2^2)+(1/3^3)-(1/4^4)+........."<<endl;
    	cout<<"Enter the no. of terms in the series you want to find sum of: ";
    	cin>>n;
		for(int i=1;i<=n;i++)
    	sum=sum+pow(-1,i+1)*1/pow(i,i); //Single statement in the for loop, thats why the sum is incremented every time i is incremented.
    	cout<<"The sum of the above series upto "<<n<<" is "<<sum<<endl;}
    	
    	cout<<"Do you want to continue(y/n)?";
    	cin>>ans;
	}
	return 0;
}






Prac2removeduplicatearray.cpp
 #include<iostream>
 using namespace std;
 
 int main(){
 	
 	cout<<"This program is to remove duplicates form an array."<<endl;
 	
 	char ans='y';
    while (ans=='y' or ans=='Y'){
    	
 	int n;
 	cout<<"Enter the no. of elements to be kept in the array: "; cin>>n;
    int arr[n];
    for (int i=0;i<n;i++){cout<<"Element"<<i+1<<":"; cin>>arr[i];}
	cout<<"Your array is "<<"[ "; 
	for (int i=0;i<n;i++)
	{ cout<<arr[i]<<" ";}
	cout<<"]"<<endl;
	
	for (int i=0;i<n;i++){
		for (int j=i+1;j<n;j++){
			if(arr[i]==arr[j]){
				for (int k=j;k<n;k++){
					arr[k]=arr[k+1];}n--;
    	j--;}
		}
	}
	cout<<"Array after removing duplicates : [ ";
	for (int i=0;i<n;i++){
		cout<<arr[i]<<" ";}
		cout<<"]\nDo you want to try with another array?(y/n) ";cin>>ans;}
		
		return 0;}




Prac3stringoccurence.cpp
#include<iostream>
#include<string>
using namespace std;

void count(string a){
	for(int i=0;i<a.length();i++){
		int g=0;
		for(int j=0;j<a.length();j++){
			if(j<i && a[i]==a[j]){break;}
			if(a[i]==a[j]){g++;}}
			if(g!=0){cout<<"("<<a[i]<<") Found"<<g<<" times."<<endl;}}
}

int main(){
	cout<<"This program is to show the number of occurences\nof each character in the text entered."<<endl;
	char ans='y';
    while (ans=='y' or ans=='Y')
    {
    cout<<"Enter the string/text: ";
	string str1;
	cin>>str1;
	count (str1);
	cout<<"Do you want to check the occurences in another string(y/n)?";
    cin>>ans;
	}
	return 0;
}



Prac5joinarray.cpp
#include<iostream>
#include<string>
 using namespace std;
 
 int main(){
 	
 	cout<<"This program is to merge two ordered arrays\nto get a single ordered array.\nPlease input ordered arrays."<<endl;
 	
 	char ans='y';
    while (ans=='y' or ans=='Y'){
    	int n1,n2;
    	cout<<"Enter the number of elements in 1st array: ";cin>>n1;
    	int arr1[n1];
    	for(int i=0;i<n1;i++){cout<<"Element"<<i<<":";cin>>arr1[i];}
    	cout<<"First array: ";
    	for(int i=0;i<n1;i++){cout<<arr1[i]<<" ";}
    	
    	cout<<"\nEnter the number of elements in 2nd array: ";cin>>n2;
    	int arr2[n2];
    	for(int i=0;i<n2;i++){cout<<"Element"<<i<<":";cin>>arr2[i];}
    	cout<<"Second array: ";
    	for(int i=0;i<n2;i++){cout<<arr2[i]<<" ";}
    	
    	int len=n1+n2;
    	int new_arr[len];
    	for(int i=0;i<n1;i++){new_arr[i]=arr1[i];}
    	for(int i=0;i<n2;i++){new_arr[i+n1]=arr2[i];}
    	cout<<"\nMerged array: ";
    	for(int i=0;i<len;i++){cout<<new_arr[i]<<" ";}
    	
    	for(int i=0;i<len;i++){
    		for(int j=i+1;j<len;j++){
    			if(new_arr[i]>new_arr[j]){
    				int temp=new_arr[i];
    				new_arr[i]=new_arr[j];
    				new_arr[j]=temp;}}}
    	
    	cout<<"\nMerged sorted array: ";
    	for(int i=0;i<len;i++){cout<<new_arr[i]<<" ";}
    	cout<<"\nDo you want to try with another array?(y/n) ";cin>>ans;}
    	return 0;
		}






Practical 4 string manipulation.cpp
#include <iostream>
#include<string.h>
using namespace std;

void displayAddress(const char* str);
void concatenateStrings(char* str1,char* str2);
int compareStrings(const char* str1,const char* str2);
int calculateLength(const char* str);
void convertLowercase(char* str);
void reverseString(char* str);
void insertString(char* mainstr,char* substr,int loc);

int main(){
	char ans='y';
	while(ans=='y'||ans=='Y')
	{
	int ch;
	cout<<"This is a menu driven program for string manipulations without using inbuilt functions.\n     ------------Menu------------     ";
	cout<<"\n1. Show address of each character in string";
	cout<<"\n2. Concatenate two strings";
	cout<<"\n3. Compare two strings";
	cout<<"\n4. Calculate length of the string";
	cout<<"\n5. Convert all lowercase characters to uppercase";
	cout<<"\n6. Reverse the string";
	cout<<"\n7. Insert a string in another string at a specified position";
	cout<<"\n8. Exit\n";
	cout<<"Enter your choice: ";cin>>ch;
	
	switch(ch){
		case 1:
			char s1[100];
			cout << "Enter the string: ";
			cin>>s1;
            displayAddress(s1);
			break;
		case 2:
			char s2[100];
			cout<<"Enter 1st string: ";
			cin>>s1;
			cout<<"Enter 2nd string: ";
			cin>>s2;
			concatenateStrings(s1,s2);
			break;
		case 3:
			char st1[100];
			char st2[100];
			cout<<"Enter 1st string: ";
			cin>>st1;
			cout<<"Enter 2nd string: ";
			cin>>st2;
			if(compareStrings(s1,s2)==0){
				cout<<"The strings are equal.";
			}
			else{
				cout<<"The strings are not equal.";
			}
			break;
		case 4:
			cout<<"\nEnter the string: ";
			cin>>s1;
			cout<<"The length of the string is:"<<calculateLength(s1)<<endl;
			break;
		case 5:
			cout<<"\nEnter the string: ";
			cin>>s1;
			convertLowercase(s1);
			cout<<"The converted string is:" <<s1<<endl;
			break;
		case 6:
			cout<<"\nEnter the string: ";
			cin>>s1;
			reverseString(s1);
			cout<<"Reversed string: "<<s1<<endl;
			break;
		case 7:
			cout<<"Enter the main string: ";
			cin>>s1;
			cout<<"Enter the sub-string: ";
			cin>>s2;
			int loc;
			cout<<"Enter the position at which the sub-string is to be added: ";
			cin>>loc;
			insertString(s1,s2,loc);
			cout<<"The modified string is: "<<s1<<endl;
			break;
		case 8:
			cout<<"Exiting the program."<<endl;
			break;
		default:
			cout<<"Invalid choice";					
	}
	cout<<"Do you want to do another sum of the series?(y/n) ";
	cin>>ans;
	}
}

//a.    Show address of each character in string
void displayAddress(const char* str){
	cout<<"Address of each character in the string: "<<endl;
	for(int i=0;str[i]!='\0';i++){
		cout<<str[i]<<" Address: "<<(void*)&str[i]<<endl;
	}
}

//b.	Concatenate two strings. 
void concatenateStrings(char* str1,char* str2){
	int len1=0;
	while(str1[len1] != '\0'){
		len1++;
	}
	int len2=0;
	while(str2[len2] != '\0'){
		len2++;
	}
	int i=0;
	while(str2[i]!='\0'){
		str1[len1+i]=str2[i];
		i++;
	}
	str1[len1+i]='\0';
	cout<<"string after concatenation: "<<str1<<endl;
}

//c.	Compare two strings 
int compareStrings(const char* str1,const char* str2){
	int i=0;
	while(str1[i]==str2[i]){
		if (str1[i]=='\0'){return 0;
		}
		i++;
	}
	return str1[i]-str2[i];
}

//d.	Calculate length of the string (use pointers) 
int calculateLength(const char* str){
	const char* ptr = str;
	int length=0;
	while(*ptr != '\0'){
		length++;
		ptr++;
	}
	return length++;
}

//e.	Convert all lowercase characters to uppercase 
void convertLowercase(char* str){
	char* ptr = str;
	while(*ptr != '\0'){
		if (*ptr >= 'a' && *ptr <= 'z'){
			*ptr=*ptr-('a'-'A');
		}
		ptr++;
	}
}

//f.	Reverse the string
void reverseString(char* str){
	char* start=str;
	char* end=str;
	while(*end!='\0'){
		end++;
	}
	end--;
	while(start<end){
		char temp=*start;
		*start=*end;
		*end=temp;
		start++;
		end--;
	}
} 

//g.	Insert a string in another string at a user specified position
void insertString(char* mainstr,char* substr,int loc){
	char temp[100];
	int i;
	for(i=0;substr[i] != '\0';i++){
		temp[i]=substr[i];
	}
	temp[i]='\0';
	int mlen;
	mlen=calculateLength(mainstr);
	for(int j=mlen;j>=loc;j--){
		mainstr[j+i]=mainstr[j];
	}
	for(int k=0;temp[k] != '\0';k++){
		mainstr[loc+k]=temp[k];
	}
}







Practical 7gcd.cpp
#include<iostream>
using namespace std;

int main(){
	char ans='y';
	while(ans=='y'||ans=='Y')
	{
	int n1,n2,gcd;
	cout<<"This program is to calculate GCD of 2 numbers.\nEnter the first number: ";
	cin>>n1;
	cout<<"Enter the second number: ";
	cin>>n2;
	
	for(int i=1; i<=n1 && i<=n2; i++){
		if(n1%i==0 && n2%i==0){
			gcd=i;
		}
	}
	cout<<"The Greatest Common Divisor is "<<gcd<<endl;
	cout<<"\n Do you want to try another?(y/n) ";
	cin>>ans;}
	return 0;
}





Practical 8matrix.cpp
#include<iostream>
using namespace std;

const int max_rows= 10;
const int max_coln=10;

class Matrix{
    private:
    	int n; 
    	int m;
        int data[max_rows][max_coln];
    	
	public:
		
		void setdim(int numrow, int numcol){
			n=numrow;
			m=numcol;
		}
		
		void setdata(){
			cout<<"Enter elements of the matrix: \n";
		for(int i=0;i<n;i++){
			for(int j=0;j<m;j++){
				cout<<"Enter the "<<i+1<<","<<j+1<<" element :";
				cin>>data[i][j];
		    }
	    }
	 }
	    void display(){
	    	for(int i=0;i<n;i++){
			for(int j=0;j<m;j++){
				cout<<data[i][j]<<" ";
			}
			cout<<endl;
		}
	}
	
	    Matrix add(Matrix oMatrix){
	    	Matrix result;
	    	result.setdim(n,m);
	    	for(int i=0;i<n;i++){
			for(int j=0;j<m;j++){
				result.data[i][j]=data[i][j]+oMatrix.data[i][j];
		    }
	    } return result;
    }
    
        Matrix multn(Matrix oMatrix){
        	Matrix result;
	    	result.setdim(n,oMatrix.m);
	    	for(int i=0;i<n;i++){
			for(int j=0;j<oMatrix.m;j++){
				result.data[i][j]=0;
				for(int k=0;k<oMatrix.n;k++){
					result.data[i][j] += data[i][k]*oMatrix.data[k][j];
				}
	        }
        } return result;
    }
     
        void transpose(){
        	Matrix result;
        	result.setdim(m,n);
        	for(int i=0;i<=n;i++){
			for(int j=0;j<=m;j++){
				result.data[i][j]=data[j][i];
				}
		    }
		    	result.display();
		}
	};
	

int main(){
	char ans='y';
	while(ans=='y'||ans=='Y')
	{
	int ch;
	cout<<"Menu";
	cout<<"\n1. Sum of two matrix.";
	cout<<"\n2. Product of two matrix";
	cout<<"\n3. Transpose of a matrix.";
	cout<<"\n4. Exit.\n";
	cout<<"Enter your choice: ";cin>>ch;
	
	Matrix matrix1,matrix2,result;
	int n,m,q;
	
	switch(ch){
		case 1:
			
			cout<<"Enter the number of rows of the matrices: ";cin>>n;
			cout<<"Enter the number of columns of the matrices: ";cin>>m;
			matrix1.setdim(n,m);
			matrix1.setdata();
			matrix2.setdim(n,m);
			matrix2.setdata();
			result=matrix1.add(matrix2);
			cout<<"Matrix after addition of your matrices:\n";
			result.display();
			break;
	    case 2:
	    	
			cout<<"Enter the number of rows of 1st matrix: ";cin>>n;
			cout<<"Enter the number of columnsof 1st matrix(=rows of 2nd): ";cin>>m;
			cout<<"Enter the number of columns of matrix2: ";cin>>q;
			matrix1.setdim(n,m);
			matrix1.setdata();
			matrix2.setdim(m,q);
			matrix2.setdata();
			result=matrix1.multn(matrix2);
			cout<<"Matrix after multiplication:\n";
			result.display();
	    	break;
	    case 3:
	    	
			cout<<"Enter the number of rows: ";cin>>n;
			cout<<"Enter the number of columns: ";cin>>m;
			matrix1.setdim(n,m);
			matrix1.setdata();
			matrix1.transpose();
			cout<<"Matrix after transposition:\n";
	        break;
	    case 4:
			
			cout<<"Exiting the program."<<endl;
			break;
	    default:
	    	cout<<"Invalid choice";
	    	break;
	    	}
	    	cout<<"\nDo you want to do another sum of the series?(y/n) ";
        	cin>>ans;
	        }
			return 0;
			}





Practical 9Person.cpp
#include <iostream>
#include <cstring>
using namespace std;

class Person {
protected:
    string name;
public:
    Person(const string& n) : name(n) {}
    virtual void display() {
        cout << "Name: " << name << endl;
    }
};

class Student : public Person {
private:
    string course;
    int marks;
    int year;
public:
    Student(const string& n, const string& c, int m, int y)
        : Person(n), course(c), marks(m), year(y) {}
    void display(){
         cout << "Name: " << name <<  endl;
         cout << "Course: " << course <<  endl;
         cout << "Marks: " << marks <<  endl;
         cout << "Year: " << year <<  endl;
    }
};

class Employee : public Person {
private:
     string department;
    double salary;
public:
    Employee(const  string& n, const  string& d, double s)
        : Person(n), department(d), salary(s) {}
    void display(){
         cout << "Name: " << name <<  endl;
         cout << "Department: " << department <<  endl;
         cout << "Salary: $" << salary <<  endl;
    }
};

int main() {
	char ans='y';
    while (ans=='y' or ans=='Y')
    {
	string n,c,N,D;
	int m,y,S;
	cout<<"Enter the name of the student: ";cin>>n;
	cout<<"Enter the course of the student: ";cin>>c;
	cout<<"Enter the marks of the student: ";cin>>m;
	cout<<"Enter the enrollment year of the student: ";cin>>y;
	cout<<"Enter the name of the employee: ";cin>>N;
	cout<<"Enter the department of the employee: ";cin>>D;
	cout<<"Enter the salary of the employee: ";cin>>S;
    Person* person1 = new Student(n,c,m,y);
    Person* person2 = new Employee(N,D,S);

    person1->display();
    cout << endl;
    person2->display();
    
    delete person1;
    delete person2;
    cout<<"Do you want to continue(y/n)?";
    cin>>ans;
	}

    return 0;
}





Practical 10triangle.cpp
#include <iostream>
#include <cmath>
using namespace std;

class Triangle {
private:
    double s1, s2, s3;

    bool valid() {
        return (side1 > 0 && side2 > 0 && side3 > 0) &&
               (side1 + side2 > side3) && (side2 + side3 > side1) && (side1 + side3 > side2);
    }

public:
    Triangle(double s1, double s2, double s3) : s1(s1), s2(s2), s3(s3) {
        if (!isValid()) {
            throw std::invalid_argument("Invalid sides for a triangle!");
        }
    }

    double calculateArea() {
        double s = (side1 + side2 + side3) / 2;
        return sqrt(s * (s - side1) * (s - side2) * (s - side3));
    }

    double calculateArea(double base, double height) {
        return (base * height) / 2;
    }
};

int main() {
    try {
        Triangle rightTriangle(3, 4, 5);
        double rightTriangleArea = rightTriangle.calculateArea(3, 4);
        std::cout << "Area of right-angled triangle: " << rightTriangleArea << std::endl;

        Triangle generalTriangle(5, 6, 7);
        double generalTriangleArea = generalTriangle.calculateArea();
        std::cout << "Area of general triangle: " << generalTriangleArea << std::endl;

        Triangle invalidTriangle(1, 2, 3);  // Invalid sides, will throw an exception
    } catch (const std::exception& e) {
        std::cerr << "Exception: " << e.what() << std::endl;
    }

    return 0;
}




Search element.txt
include <iostream> 
using namespace std; 
int inputarray(int *); 
int search(int *, int, int); 
int binarysearch(int *, int, int); 
void sortArr(int *, int); 
void read(int *, int); 
int main() 
{ 
char wish; 
do 
{ 
int len, result; 
int array[50]; 
len = (inputarray(array)); 
int ele; 
cout << "enter the element u want to search: "; 
        cin >> ele; 
        int choice; 
        cout << "1->linear search\n" 
             << "2->binary search\n" 
             << "3->quit\n" 
             << "Enter your choice:"; 
        cin >> choice; 
        if (choice == 1) 
            result = search(array, len, ele); 
        else if (choice == 2) 
        { 
 
            sortArr(array, len); 
            read(array, len); 
            result = binarysearch(array, len, ele); 
        } 
 
        else if (choice == 3) 
            break; 
        else 
            cout << "wrong choice:"; 
 
        if (result != -1) 
            cout << "\nYour element is found at " << result << " index" << endl; 
        else 
            cout << "\nElement not found"; 
        cout << "\ndo u want to continue?(y/n) : "; 
        cin >> wish; 
 
    } while (wish == 'y' | wish == 'Y'); 
} 
int binarysearch(int array[], int len, int ele) 
{ 
    int low = 0; 
    int high = len - 1; 
    int mid = (low + high) / 2; 
    while (high >= low) 
    { 
        int element = array[mid]; 
        if (element == ele) 
        { 
            return mid; 
        } 
        else if (element > ele) 
        { 
            high = mid - 1; 
        } 
        else 
        { 
            low = mid + 1; 
        } 
        mid = (low + high) / 2; 
    } 
    return -1; 
} 
 
int inputarray(int arr[]) 
{ 
    int len = 0; 
    char ask; 
    do 
    { 
        cout << "enter the number at " << len << " index : "; 
        cin >> arr[len]; 
        len++; 
        cout << "do u want add more element in array?(y/n) : "; 
        cin >> ask; 
    } while (ask == 'Y' || ask == 'y'); 
    return len; 
} 
int search(int arr[], int len, int ele) 
{ 
 
    for (int i = 0; i < len; i++) 
    { 
        if (arr[i] == ele) 
        { 
            return i; 
        } 
    } 
    return -1; 
} 
void sortArr(int Arr[], int len) 
{ 
    for (int i = 0; i < len; i++) 
    { 
        for (int j = i + 1; j < len; j++) 
        { 
            if (Arr[i] > Arr[j]) 
            { 
int a = Arr[i]; 
Arr[i] = Arr[j]; 
Arr[j] = a; 
} 
} 
} 
} 
void read(int array[], int len) 
{ 
for (int i = 0; i < len; i++) 
{ 
cout << array[i] << " "; 
} 
} 
