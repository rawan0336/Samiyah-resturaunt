/*Group 4- Project 4
Najd Almutairi 2210002418
Rawan Aljeshi  2210002609
Nouf Alsagour 2200003277
Baneen Hassan 2210003017
Shahad AlSaeed 2210003008
*/

#include <iostream>
#include <stdlib.h>
#include <cstdlib>
#include <string>
#include <ctime>
#include <fstream>
using namespace std;

bool found;
int em_ID;
int add=0,del=0,update=0;
struct staff{
    int id;
    string name;
    int age;
    string Tele_num;
    string Emerg_num;
    string position;
    float salary;
};
// proto type
void login(string *&m,float *&p,staff *&s, int size);




//------------------------
void readMenuInfo(string *&Menu, float *&price)// to read MENU meals and price from file
{
    ifstream infile ;
    infile.open("Menu.text");
     if (infile.fail())
   {
       cout<< "Cant Open File "<<endl;
       exit(EXIT_FAILURE);
   }
       while (infile)
       {
           for(int i=0 ;i<15;i++) // from 0 to 14 read the values in the file 1 meal and its price at time
         {

         infile>>Menu[i] ;
           infile>>price[i];
       }
    
       }
       infile.close();
}
void readStaffInfo(staff *&StaffArray,int size)// to read STAFF INFORMATION from file  // the size of the array is dynamic not fixed thats why we pass the size each time so if there is and update by adding or deleting it affect the data in the file
{
    ifstream infile ;
    infile.open("Staff.text");
     if (infile.fail())
   {
       cout<< "Cant Open File "<<endl;
       exit(EXIT_FAILURE);
   }
       while (infile)
       {
           for(int i=0 ;i<size;i++)
         {         // take each row from the file that represent one employee  then fill the array element of that employee  then increment i to store the next employee

         infile>>StaffArray[i].id ;
              infile>>StaffArray[i].name ;
              infile>>StaffArray[i].age;
           infile>>StaffArray[i].position ;
              infile>>StaffArray[i].salary;
              infile>>StaffArray[i].Tele_num;
              infile>>StaffArray[i].Emerg_num ;
       }
    
       }
       infile.close();
}
void WriteMenuinfo(string *&Menu, float*& prices) // re write the menu and price array in the file after updating them the two arrays are passed by reference because all the functions can update thonse arrays
{
      ofstream OutToFile;
       OutToFile.open("Menu.text",ios::out);
   if (OutToFile.fail())
   {
       cout<< "Cant Open File "<<endl;
       exit(EXIT_FAILURE);
   }
   else
   for (int i =0 ;i<15;i++)// from 0 to 14 write the array content into  the file again
   {
       
       OutToFile <<Menu[i] << "  ";
    OutToFile<< prices[i]<< "  ";
       OutToFile<<endl;
   }
   OutToFile.close();
}
void WriteStaffinfo(staff *&StaffArray,int size) // re write the staff array in the file after updating them the size here represent number of rows in the file it is passed from main functions
{
      ofstream OutToFile;
       OutToFile.open("Staff.text",ios::out);
   if (OutToFile.fail())
   {
       cout<< "Cant Open File "<<endl;
       exit(EXIT_FAILURE);
   }
   else
   for (int i =0 ;i<size;i++)
   {   // write each element in the staff array into the file in one row then endl to go to new row
       
       OutToFile <<StaffArray[i].id << "  ";
    OutToFile<< StaffArray[i].name<< "  ";
    OutToFile<< StaffArray[i].age<< "  ";
    OutToFile<< StaffArray[i].position<< "  ";
    OutToFile<< StaffArray[i].salary<< "  ";
    OutToFile<< StaffArray[i].Tele_num<< "  ";
    OutToFile<< StaffArray[i].Emerg_num<< "  ";
       OutToFile<<endl;
   }
   OutToFile.close();
}


// function to food  menu
void dis_Rest_menue(string *&Menu, float *&price){//this function called in login() function  // parameters passed by reference form main function  apply any edit on the array like add or update or delete
         // read data from the file and fill the array with data to display the array after that
    cout<<endl;
    cout<<"=========================="<<endl<<endl;
    cout<<"    Main Dishes are:      "<<"\t"<<endl<<endl;
    cout<<"=========================="<<endl;
    for(int i =0 ; i<15;i++) { //display all 15 items in array menu and prices
    cout<<"("<<i+1<<")"<<Menu[i]<<":  "<< price[i]<<"SR"<<endl;
    }
     }
//-to search for an item in the array and display it
void search_menue(string *&Menu, float *&price){// search by  nymber in the menu
    int num=0;// the item code
    int stop=1;
    cout<<"Search for An Item in the menu by the code : "<<endl;
    do { // until the user press 0  keep doing the following
    cout<<"Enter the Code Number for the Item:";
    cin>>num;
    cout<<endl<<endl;
    
    if (num<=0 || num>15) // if the user entered a wrong number error message will be displayed
    {
        cout<< " This code is not available"<<endl<<endl;
    }
    num=num-1; // if the user enter 1 so its number 0 in the array
    cout<<Menu[num]<<" --- "<<price[num]<<" SR "<<endl<<endl;
    
    cout<<"Do you want to search for another dish?"<<endl<<" ( 1 ) for yes and ( 0 ) for no : ";
    cin>>stop;
} while (stop!=0);
}
//------------------------
void update_menue(string *&Menu, float *&price){ // update menu content
     int choice;
     int num;
     string name;
     int new_price;
     int stop;
     
    cout<<"Update an Item in the menu by the code : "<<endl;
    dis_Rest_menue(Menu,price); // show the menu to user to select a code
     do
     {
     cout<<"Enter the Code Number for the Item:"; // ask user to enter meal code to update it
     cin>>num;
     
     cout<<" To Update the dish Name Enter ( 0 ), the Price Enter ( 1 ) or Both Enter ( 2 )? \t"<<endl;
     cin>>choice;
     if (choice==0) // if user want to update only the name of this meal
      {
        cout<<"Enter the New dish name:  (note to replace spaces by ( - ) \n";
        cin.ignore(10,'\n');
        getline(cin,name);
         Menu[num-1]= name;
        cout<<"The new dish name is: "<<Menu[num-1]<<" and the price is: "<<price[num-1]<<endl;
      }
      
     else if (choice==1)// if user want to update only the price  of this meal
        {
        cout<<"Enter the New dish price:  (note to replace spaces by ( - ) \n";
        cin>>new_price;
        price[num-1]=new_price;
        cout<<"The new dish name is: "<<Menu[num]<<" and the price is: "<<price[num]<<endl;

                
       }
     else if (choice==2){// if user want to update the name  and price of this meal
         
        cout<<"Enter the New dish name:  (note to replace spaces by ( - ) \n";
        cin.ignore(10,'\n');
        getline(cin,name);
        
        Menu[num-1]= name;
        
        cout<<"Enter the NEW dish price: \n";
        cin>>new_price;
        price[num-1]=new_price;
                
        cout<<"The new dish name is: "<<Menu[num]<<" and the price is: "<<price[num]<<endl;
     }
     else
         {
          cout<<"Choice not available!"<<endl;
        }
          cout<<"The new menue is:\n";
     dis_Rest_menue(Menu,price); // to display the menu again after Updating it
     WriteMenuinfo(Menu,price);// write the new data in the file to read the new data next time
     cout<<"If you want to update more dishes click (1) and to stop click (0): ";
     cin>>stop;
     }
     while (stop!=0);
}
//------------------------
float dis_bill(float tot_cost1){ //function to display bill  tot_cost1 is a value passed from function bill()
    
    
    float Tax=0.15;
        int q=rand() % 100 +10;// creat randon number for the bill
    time_t now = time(0);
    char* date_time = ctime(&now);

    cout<<endl;
         cout <<"\t\t\t\t\t\t\t================================================"<<endl;
         cout <<"\t\t\t\t\t\t\t|                   Bill                       |"<<endl;
         cout <<"\t\t\t\t\t\t\t================================================"<<endl;
         cout <<"\t\t\t\t\t\t\t\t\t\t   Samiyah Fast Food     " <<endl;
         cout <<"\t\t\t\t\t\t\t\t\t1st Street , Dammam corniche , SA  "<<endl;
         cout <<"\t\t\t\t\t\t\t\t\t\t   Tel - 03-8365997     " <<endl;
         cout<<"\t\t\t\t\t\t\t- - - - - - - - - - - - - - - - - - - - - - - -";
         cout << endl;
         cout<<"\t\t\t\t\t\t\t  "<<date_time<<endl;
         cout << "\t\t\t\t\t\t\t Order : NB54"<<q<<endl;
         
         cout << "\t\t\t\t\t\t\t  Cashier :  Basil"<<endl;
         cout << endl;
         cout<<  "\t\t\t\t\t\t\t  Sub Total IS :"<<tot_cost1<<" sar."<<endl;
         cout<<  "\t\t\t\t\t\t\t  *VAT 15% : "<<tot_cost1*Tax<<endl;
         return tot_cost1*1.15;

}
//---------------------------
void bill(string *&Menu, float *&price,staff *&staffArr,int size){       //function to calculate bill

 int ord,qaunt,total=0;
 char ask,n;
 retry:
   dis_Rest_menue(Menu,price);// show the menu
 
    cout<<"Please order 1-15 (one order at a time): ";
    cin>>ord; // take meal number
    
    cout<<"Please Enter the Quantity  : ";
    cin>>qaunt;// take the quantity
    total+=price[ord-1]*qaunt; //calculate the total
    cout<<"Do you want to add more orders? (y or n)";
    cin>>ask;
    if(ask=='y'||ask=='Y')
    { goto retry; }
    else goto end;
end:
cout<<"Total bill without Tax: "<<total<<endl;
    
    
   float T= dis_bill(total);// send the total value to this function to calculate the tax and print the final bill
    cout<<   "\t\t\t\t\t\t\t  TOTAL BILL IS : "<<T;
    cout<<"\n\t\t\t\t\t\t\t================================================"<<endl;
    cout<<"\t\t\t\t\t\t\t______________THANK YOU FOR COMMING_____________"<<endl;
    cout<<"to Exit Main Menue enter ( 0 ) :"<<endl;
    cout<<"to create New Bill enter ( 1 ) :";
    cin>>n;
    if(n=='0'){
        login(Menu,price,staffArr,size);// go back to the main menu
    }
    if(n=='1'){
        bill(Menu,price,staffArr,size);// go back to make new order
    }
    
}
//------------------------
// staff Functions .
void  add_staff(staff *&s,int size )
 { // to add new employee in the array s  , the variable size is passed from satff_info that takes it from login() and login()takes size from the main that calculates it by counting number of rows in the file
  cout<<"Enter employee id"<<endl;
 cin>>s[size].id;
 cout<<"Enter employee name"<<endl;
 cin>>s[size].name;
 
 int age;
 do{
 cout<<"Enter employee age (20 to 50)"<<endl;
 cin>>age;
 }while(age<20 || age >50);
 s[size].age=age;

string PhoneNum;
 do{
 cout<<"Enter employee telephone number (10 digits only) "<<endl;
 cin>>PhoneNum;
 }while(PhoneNum.length()<10 ||PhoneNum.length()>10);
 s[size].Tele_num=PhoneNum;

string EmgNum;
 do{
 cout<<"Enter employee emergency number"<<endl;
 cin>>EmgNum ;
 }while(EmgNum.length()<10 ||EmgNum.length()>10);
 s[size].Emerg_num=EmgNum;


 cout<<"Enter employee position"<<endl;
 cin>>s[size].position;
 cout<<"Enter employee salary"<<endl;
 cin>>s[size].salary;
 cout<<" ____employee added_____ "<<endl;
}
//------------------------
void delete_staff(staff *&s,int size, int ID){
    found=false;
    for(int i=0;i<size;i++)
    {
    if(ID ==s[i].id)
     {  found=true;
         for(int j=i;j<size;j++)
         s[j]=s[j+1];
     }
    }
    if(found==false)
   { cout<<"employee not found"<<endl;}
   else {
          cout<<" ___The information that related to the employee has been daleted___"<<endl;
   }
}
//------------------------
void update_staff(staff *&s,int size, int ID)
{// the id is passed from staff_info function
found=false;
  for(int i=0;i<=size;i++)  // for all elements in the array     {
    if(ID ==s[i].id) // check if the id is equal to the id entered by user  if true take the new values .
    {  found=true;
        cout<<"enter new emplpyee name : ";
        cin>>s[i].name;

int age;
do{// to force the user to enter the correct age betwen 20 and 50 we made do while to repeat asking for the age if the user entered it less than 20 or greater than 50
cout<<"Enter employee age (20 to 50)"<<endl;
cin>>age;
}while(age<20 || age >50);
s[i].age=age;

string PhoneNum;
do{// to force the user to enter the correct Phone number with 10 digits only we made do while to repeat asking for the number if the user entered it less than 10 or greater than 10
cout<<"Enter employee telephone number (10 digits only) "<<endl;
cin>>PhoneNum;
}while(PhoneNum.length()<10 ||PhoneNum.length()>10);
s[i].Tele_num=PhoneNum;

string EmgNum;
do{// to force the user to enter the correct Phone number with 10 digits only we made do while to repeat asking for the number if the user entered it less than 10 or greater than 10
cout<<"Enter employee emergency number"<<endl;
cin>>EmgNum ;
}while(EmgNum.length()<10 ||EmgNum.length()>10);
s[i].Emerg_num=EmgNum;

        cout<<"enter new emplpyee Position : ";
        cin>>s[i].position;
        cout<<"enter new emplpyee salary : ";
        cin>>s[i].salary;
        cout<<"___Employee Info Updated___"<<endl;
        break;
        }
    }
//---------------Najd -------------------
void  Display_staff(staff *&s,int size ){
    readStaffInfo(s,size);// this function read from the file staff all the infromation and store each row in the file in staff array
    for( int i=0 ; i<size; i ++) //from 0 till the last element in the array print employees infromation // the size here represent number of rows in the file and number of elements in the array
    {    cout<< i<<"display"<<endl;
        cout << "Employee ID :"<< s[i].id<<endl;
        cout <<"Name :  "<<s[i].name <<endl;
        cout<<"Age :"<< s[i].age<<endl;
        cout<< "Telephone Number "<<s[i].Tele_num<<endl;
        cout<< "Emergency Number "<<s[i].Emerg_num<<endl;
        cout<< "Position "<<s[i].position<<endl;
        cout<< "Salary "<<s[i].salary<<endl;
        cout << "**********************************************************************************************"<<endl;
    }//for
}
//-------------Najd -----------
void search_staff(staff *&s,int size, int ID ){
       bool Found =false;
       for(int i=0;i<size;i++)// for all employees
       {
           if (ID==s[i].id) // if the entered id equals to the current id so the employee found
           {
               cout<<" Employee Name   : "<<s[i].name<<endl;// print all informatio employee.
               cout<<" Employee age : "<< s[i].age<<endl;
               cout<<" Employee Position : "<< s[i].position<<endl;
               cout<<" Employee salary : "<< s[i].salary<<endl;
               cout<<" Employee Phone number: "<< s[i].Tele_num<<endl;
               cout<<" Employee Emergency number : "<< s[i].Emerg_num<<endl;
               Found=true;
               break;
       }
}
       if (Found==false)
      {
        cout << "......... This Employee Doesn't exist............"<< endl;}
}
//------------------------
void sort_staff(staff *&s,int size)
{

    int counter=size;
    cout << "sorting Employees based on salary"<< endl;
    for (int j =counter-1 ;j>0 ;j--)  // using Bubble sort j is pointing on the last element in the array
    {
       for (int i =0 ; i <size-1;i++) // i pointing on first element on the array
         {
            if(s[i].salary >= s[i+1].salary)
              {
                  
                  swap(s[i].name , s[i+1].name);
                  swap(s[i].age,s[i+1].age);
                  swap(s[i].id,s[i+1].id);
                  swap(s[i].position,s[i+1].position);
                  swap(s[i].salary,s[i+1].salary);
                  swap(s[i].Tele_num,s[i+1].Tele_num);
                  swap(s[i].Emerg_num,s[i+1].Emerg_num );
        }
        
    }
    size--;
}

}
void staff_info(staff *&s,int  size ){
int n;
do{
    cout<<endl;
cout<<" staff information: ";
cout<<"\n 1:add an item ";
cout<<"\n 2:delete an item" ;
cout<<"\n 3:update an item ";
cout<<"\n 4:Display all items ";
cout<<"\n 5:Search For an item ";
cout<<"\n 6:Sort by Salary ";
cout<<"\n 0:Exit" <<endl;
cout<<" Enter Service number \n";
cin>>n;
switch(n)
{
    case 1:
           readStaffInfo(s,size);// read information from file into staff array
           add_staff(s,size);//add the new employee information to the array
           size++;// update the size
           WriteStaffinfo(s,size); //rewrite the array into file again
           add++;
           break;
    case 2:
       if (size>0){
        cout<<" enter employee ID to delete "<<endl;
        cin>>em_ID;
        readStaffInfo(s,size);
        delete_staff(s,size,em_ID);
        size--;
        WriteStaffinfo(s,size);
        del++;
        }
        else
        cout<<"there are no emlpoyees in this resturant. you can't delete"<<endl;
        break;
    case 3:
        if(size>=0)
        {
        cout<<" enter employee ID to update"<<endl;
        cin>>em_ID;
        readStaffInfo(s,size);
        update_staff(s,size,em_ID);
        WriteStaffinfo(s,size);
        update++;
        }
        else
        cout<<"there are no emlpoyees in this resturant. you can't update"<<endl;
        break;
    case 4:
        readStaffInfo(s,size);
        Display_staff(s,size);
        break;
    case 5:
        if(size>=0)
        {
        cout<<" enter employee ID to find Information "<<endl;
        cin>>em_ID;
        readStaffInfo(s,size);
        search_staff(s,size,em_ID);
        break;
    }
    case 6:
        if(size>=0)
        {
            readStaffInfo(s,size);
             sort_staff(s,size);
             WriteStaffinfo(s,size);
        }
        break;
    default:
    cout<<"INVALID CHOICE !!!";
}
cout<<"To go back the staff information enter (4) "<<endl;
cout<<"To exist enter (0) "<<endl;
cin>>n;
if(n=='4')
staff_info(s,size);
else if(n=='0')
break;
}while(n!=0);
}
//------------------------

void login(string *&Menu, float *&price ,staff *&staffArr,int size){ //to display main menue
    readMenuInfo(Menu,price);// read data from file and store it in the array before searching
    char x,s;
    cout<<endl<<endl;

    cout<<"\t\t\t|-------------------------------------------------|\n";
    cout<<"\t\t\t|                SAMIYAH Resturaunt               |\n";
    cout<<"\t\t\t|-------------------------------------------------|\n\n";
    cout<<endl;
    cout<<"Choose  a SURVICE number from the Following  : \t"<<endl;
    cout<<"1-Display Menu \t"<<endl;
    cout<<"2-Search in the Menu\t"<<endl;
    cout<<"3-Update the Menu\t "<<endl;
    cout<<"4-Calculate Bill \t"<<endl;
    cout<<"5-Staff Information \t"<<endl;
    cout<<"0-Exit\t"<<endl;
    
    cin>>x;
    if(x =='1')    {
          dis_Rest_menue(Menu,price);
        cout<<"Go back to Main Menu enter ( 0 ) :";
        cin>>s;
      if(s=='0')
      { login(Menu,price,staffArr,size); }
    }
    else if (x=='2'){
       cout<<endl;
        cout<<"\t\t\t|-------------------------------------------------|\n";
        cout<<"\t\t\t|        SAMIYAH Fast Food - Search Menue         |\n";
        cout<<"\t\t\t|-------------------------------------------------|\n\n";
        search_menue(Menu,price);
        cout<<"Go back to Main Menu enter ( 0 ) :";
        cin>>s;
        if(s=='0'){  login(Menu,price,staffArr,size);}
    }
       else if (x=='3'){
               cout<<endl;
        cout<<"\t\t\t|-------------------------------------------------|\n";
        cout<<"\t\t\t|      SAMIYAH Fast Food - Update Menue           |\n";
        cout<<"\t\t\t|-------------------------------------------------|\n\n";
         update_menue(Menu,price);
        cout<<"to Exit Main Menue enter ( 0 ) :";
        cin>>s;
       if(s=='0'){ login(Menu,price,staffArr,size); }
    }
    else if(x=='4'){
         cout<<endl;
        cout<<"\t\t\t|-------------------------------------------------|\n";
        cout<<"\t\t\t|      SAMIYAH Fast Food Ordering System          |\n";
        cout<<"\t\t\t|-------------------------------------------------|\n\n";
        bill(Menu,price,staffArr,size);
        cout<<"to Exit Main Menue enter ( 0 ) :";
        cin>>s;
       if(s=='0'){ login(Menu,price,staffArr,size); }
        }
       else if(x =='5'){
         cout<<"\t\t\t|-------------------------------------------------|\n";
        cout<<"\t\t\t|               Staff Information                 |\n";
        cout<<"\t\t\t|-------------------------------------------------|\n\n";
        staff_info(staffArr,size);
        cout<<"to Exit Main Menue enter ( 0 ) :";
        cin>>s;
       if(s=='0'){ login(Menu,price,staffArr,size); }
        }
}
// function takes  the values of delete update and add   and store it inside a report file  also data and time and number of staff in the staff file
void write_staff_Report(int add,int update, int del)    {
    //    built in functions that set the time now date and hours minutes and seconds
        time_t TimeNow ;
        struct tm TimeNowLocal;
        TimeNow=time(NULL);
        TimeNowLocal=*localtime(&TimeNow);
        
        // open staff file and count number of staff inside
        int staff_Count;
        string emp;
        ifstream infile ("Staff.text",ios::in);
             while ( getline(infile, emp) ){staff_Count++; }
             
        // now write the data into report file
      ofstream outfile;
       outfile.open("Report.text",ios::out);
   if (outfile.fail()){
       
       cout<< "Cant Open File "<<endl;
       exit(EXIT_FAILURE); }
       
   else   {
       outfile<<TimeNowLocal.tm_mday<<"-"<<TimeNowLocal.tm_mon+1<<"-"<<TimeNowLocal.tm_year+1900<<endl;
       outfile<<TimeNowLocal.tm_hour<<" "<< TimeNowLocal.tm_min<<" "<< TimeNowLocal.tm_sec<<" "<<endl;
       outfile<<staff_Count<<" "<<endl;
       outfile<< add<<" "<<endl;
       outfile<< update<<" "<<endl;
       outfile<<del<<" "<<endl;
         }
        
}
// read the report file data and print it
void ReadReport(){
     int AddCount;
     int DeleteCount;
     int UpdateCount;
     int Records;
     int Day;
     int Month;
     int Year;
     int Hours;
     int Minutes;
     int Seconds;
     int Add;
     int Delete;
     int Update;
     
    ifstream input ("Report.text",ios::in);
     if (input.fail())
   {
       cout<< "Cant Open File "<<endl;
       exit(EXIT_FAILURE);
   }
   else
   {
       while (input)
       {
           input>>Day;
           input>>Month;
           input>>Year;
           input>>Hours;
           input>>Minutes;
           input>>Seconds;
         input>>Records;
           input>>Add;
           input>>Update;
           input>>Delete;
    }
     input.close();
}
cout<< "*****************************Final Rport********************************"<<endl;
cout<< "Today is : "<<Day<<"-"<<Month<<"-"<<Year<<endl;
cout<< "Time : "<< Hours <<":"<<Minutes<<":"<<Seconds<<endl;
cout << "Number of Employees in the List  :" <<Records<<endl;
cout << "You Added:" <<Add<<" New Employee/s"<<endl;
 cout << "You Update:" <<Update<<" Employee/s"<<endl;
 cout << "You Deleted:" <<Delete<<" Employee/s"<<endl;
}

int main(){
    

           string* MenuArray; // define array menu its dynamic array that takes  15 records
        MenuArray= new string[15];
        float * PriceArray; // define array price its dynamic array that takes  15 values ;
        PriceArray= new float[15];
        
        // define a dynamic array of staff to store employees information
        int size;
        staff* staffArr;
        staffArr=new staff[size];
        
        // Take number of rows from the file
        int File_Records = 0;
        string Record;
        ifstream in("Staff.text");
        while ( getline(in, Record) )
            { File_Records++;}
        
            // give the number of rows to login function then this function will pass it to all the functions .
        login(MenuArray,PriceArray,staffArr,File_Records);// pass the arrays to login function to allow editing on it (pass by reference )
        write_staff_Report(add,update,del);
        ReadReport();
    return 0;
}
    



