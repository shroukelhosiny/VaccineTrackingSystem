#include "user.h"
#include"BST.h"
#include"queuelist.cpp"
#include"linkedlist.cpp"
#include<iostream>
#include<fstream>
#include<string>
using namespace std;
float user::NumOfUsers = 0.0;
float user::NumOfMale = 0.0;
float user::NumOfFemale = 0.0;
float user::NumOfPfizer = 0.0;
float user::NumOfAstraZeneca = 0.0;
float user::NumOfJohnson = 0.0;
float user::NumOfSinopharm = 0.0;
float user::NumOfSinovac = 0.0;
float user::NumOfFirstdose=0.0;
float user::NumOfSecdose=0.0;


user::user() {
    ReturnValues();
	add_information();
	NumOfUsers++;
	counter();
	while(true){
	cout << "Already vaccinated ? (true\\false) " << endl;
	cin >> vaccinated;
	if (vaccinated == "true") {
		Doses();
		if(NumOfDoses=="1"){
            NumOfFirstdose++;
            break;
		}
		else if(NumOfDoses=="2"){
            NumOfSecdose++;
            break;
		}
		else
        cout << "Error ! Try again"<<endl;
	}
	else if (vaccinated == "false") {
		NameOfVaccine = "###";
		NumOfDoses = "###";
		break;
	}
}
cout << "enter your password" << endl;
cin >> password;
}
void user::ReturnValues() {
	ifstream information;
	information.open("information.txt");
	//if (information.is_open()) {
			information >> NumOfUsers>>  NumOfMale>>  NumOfFemale>> NumOfPfizer>> NumOfAstraZeneca>>
			 NumOfJohnson>> NumOfSinopharm>> NumOfSinovac>>NumOfFirstdose>>NumOfSecdose;
			information.close();
	//}
}
string user::getvaccinated() {
	return vaccinated;
}

void user::add_information() {
	cout << "enter your name(first , second , last) and id" << endl;
	cin >> FName >> mName >> lName;

	cin >> NationalID;


	while (NationalID.length() != 13)
	{
		cout << "invalid national id" << endl;
		cout << "enter national id contain 13 numbers" << endl;
		cin >> NationalID;
	}
	cout<<"enter your age"<<endl;
	cin >> Age;
	cout << "enter your gander(male / female)" << endl;
    while (true) {
        cin >> Gender;
        if (Gender == "male" || Gender == "female")
            break;
        else
            cout << "Enter 'male' or 'female'";

    }

	cout << "enter your country and governorate" << endl;
	cin >> Country >> Governorate;

	}

void user::counter() {
   if (Gender == "male" ) {
        NumOfMale++;
    }
    if (Gender == "female") {
        NumOfFemale++;
    }
}

void user::Doses() {
    while(true){
	cout << "what is the kind of vaccine ? (Pfizer ,Astrazeneca ,Johnson ,Sinopharm ,Sinovac)" << endl;
	cin >> NameOfVaccine;
	if (NameOfVaccine == "Pfizer" || NameOfVaccine == "pfizer") {
		NumOfPfizer++;
		cout << "received only one or both doses? (1\\2)" << endl;
		cin >> NumOfDoses;
		break;
	}
	else if (NameOfVaccine == "Astrazeneca" || NameOfVaccine == "astrazeneca") {
		NumOfAstraZeneca++;
		cout << "received only one or both doses? (1\\2)" << endl;
		cin >> NumOfDoses;
		break;
	}
	else if (NameOfVaccine == "Johnson" || NameOfVaccine == "johnson") {
		NumOfJohnson++;
		cout << "received only one or both doses? (1\\2)" << endl;
		cin >> NumOfDoses;
		break;
	}
	else if (NameOfVaccine == "Sinopharm" || NameOfVaccine == "sinopharm") {
		NumOfSinopharm++;
		cout << "received only one or both doses? (1\\2)" << endl;
		cin >> NumOfDoses;
		break;
	}
	else if (NameOfVaccine == "Sinovac" || NameOfVaccine == "sinovac") {
		NumOfSinovac++;
		cout << "received only one or both doses? (1\\2)" << endl;
		cin >> NumOfDoses;
		break;
	}
	else
        cout<<"enter valid kind "<<endl;
    }
}


string user::getFName() {
	//cout << FullName;
	return FName;
}
string user::getmName() {
	return mName;
}
string user::getlName() {
	return lName;
}
string user::getNationalID() {
	//cout << NationalID;

	return NationalID;
}
string user::getpassword() {
	//cout << password;
	return password;
}
string user::getGender() {
	//cout << Gender;
	return Gender;
}
string user::getAge() {
	//cout << Age;
	return Age;
}
string user::getCountry() {
	//cout << Country;
	return Country;
}
string user::getGovernorate() {
	//cout << Governorate;
	return Governorate;
}
string user::getNameOfVaccine() {
	//cout << NameOfVaccine;
	return NameOfVaccine;
}
string user::getNumOfDoses() {
	//cout << NumOfDoses;
	return NumOfDoses;
}
int user::getNumOfUsers() {
	//cout << NumOfUsers;
	return NumOfUsers;
}
int user::getNumMale() {
	//cout << NumOfMale;
	return NumOfMale;
}
int user::getNumOfFemale() {
	//cout << NumOfFemale;
	return NumOfFemale;
}
int user::getNumOfPfizer() {
	//cout << NumOfPfizer;
	return NumOfPfizer;
}
int user::getNumOfAstraZeneca() {
	//cout << NumOfAstraZeneca;
	return NumOfAstraZeneca;
}
int user::getNumOfJohnson() {
	//cout << NumOfJohnson;
	return NumOfJohnson;
}
int user::getNumOfSinopharm() {
	//cout << NumOfSinopharm;
	return NumOfSinopharm;
}
int user::getNumOfSinovac() {
	//cout << NumOfSinovac;
	return NumOfSinovac;
}
int user::getNumOfFirstdose(){
    //cout <<NumOfFirstdose;
	return NumOfFirstdose;
}
int user::getNumOfSecdose(){
	return NumOfSecdose;
}

bool user::check(string o) {
	BST b;
	fstream id;
	string s;
	id.open("id.txt");
	while (id >> s)
	{
		b.insert(s);

	}
	id.close();
	int v = b.contains(o);
	if (v == 1) {
		cout << "repeated national id" << endl;
		return false;
	}
	else
		fstream id;
	    id.open("id.txt", ios::app);
        id << o << endl;
	    id.close();
	return true;

}

void user::disply_usre(string id , string pass){
    linkedlist<string> users;
    string temp;
    ifstream vaccine;
	vaccine.open("vaccine.txt");
    while( vaccine>>temp){
      users.Append(temp);
    }
    vaccine.close();
bool notFound = true;
	while(notFound){
	for(int i=0; i< users.Length() ; i++ ){
        temp = users.At(i);
    if(temp.find(id) != std::string::npos &&temp.find(pass) != std::string::npos ){
        cout<<users.At(i)<<endl;
        notFound= false;
        break;
    }
}
    if(notFound==true){
        cout<<"not found"<<endl;
        break;
    }
	}
}

void user::disply_usrefor_admin(string id){
    linkedlist<string> users;
    string temp;
    ifstream vaccine;
	vaccine.open("vaccine.txt");
    while( vaccine>>temp){
      users.Append(temp);
    }
    vaccine.close();
bool notFound = true;
	while(notFound){
	for(int i=0; i< users.Length() ; i++ ){
        temp = users.At(i);
    if(temp.find(id) != std::string::npos){
        cout<<users.At(i)<<endl;
        notFound= false;
        break;
    }
}
    if(notFound==true){
        cout<<"not found"<<endl;
        break;
    }
	}
}

void user::displyAll(){
string temp;
ifstream vaccine;
	vaccine.open("vaccine.txt");
    while(  vaccine>>temp){
    cout<<temp<<endl;
    cout<<endl;
    }
    vaccine.close();
}



void user::delete_usre(){
linkedlist<string> users;
linkedlist<string> temp3;
linkedlist<string> temp4;
linkedlist<string> temp6;
    string temp1 , temp2 ,temp5, Id;
    cout << "Enter your ID: ";
	cin >> Id;
while (Id.length() != 13)
{
		cout << "invalid national id" << endl;
		cout << "enter national id contain 13 numbers" << endl;
		cin >> Id;

     }

    ifstream vaccine;
	vaccine.open("vaccine.txt");
    while(vaccine>>temp1){
    users.Append(temp1);
    }
    vaccine.close();
   bool notFound = true;
   while(notFound){
    for(int i=0; i< users.Length() ; i++ ){
     temp1 = users.At(i);
     if(temp1.find(Id) != std::string::npos){
        users.DeleteAt(i);
        notFound = false;
        ifstream id;
        id.open("id.txt");
        while(id>>temp2){
            temp3.Append(temp2);
                 }

        for(int j=0 ; j< temp3.Length() ; j++){
            temp2 = temp3.At(j);
            if(temp2 == Id){
                temp3.DeleteAt(j);
                break;
                    }
                 }
                 id.close();
        ifstream unvaccinated;
        unvaccinated.open("unvaccinated.txt");
        while(unvaccinated>>temp5){
            temp4.Append(temp5);
                 }

        for(int k=0 ; k< temp4.Length() ; k++){
            temp5 = temp4.At(k);
            if(temp5.find(Id) != std::string::npos){
                temp4.DeleteAt(k);
                break;
                    }
                 }
                 unvaccinated.close();
        ofstream tmp;
        tmp.open("tmp.txt");
        for(int j=0 ; j< temp1.length() ; j++){
         if(temp1.at(j) != '|'){
             tmp<<temp1.at(j);
           }
           else
            tmp<<endl;
           continue;
        }
        tmp.close();
               break;
              }
	  }
	  break;
	}
	   if(notFound==false){
        ofstream vaccine;
        vaccine.open("vaccine.txt");
        for(int k=0; k< users.Length() ; k++ ){
         temp2= users.At(k);
         vaccine<<temp2<<endl;
            }
        vaccine.close();
        ofstream id;
        id.open("id.txt");
        for(int l=0; l< temp3.Length() ; l++ ){
         temp2= temp3.At(l);
         id<<temp2<<endl;
            }
        id.close();
        ofstream unvaccinated;
        unvaccinated.open("unvaccinated.txt");
        for(int b=0; b < temp4.Length() ; b++ ){
         temp5= temp4.At(b);
         unvaccinated<<temp5<<endl;
            }
       unvaccinated.close();
       ifstream tmp;
       tmp.open("tmp.txt");
       while(tmp>> temp1){
            temp6.Append(temp1);
        }
        tmp.close();
        remove("tmp.txt");
        ReturnValues();
         NumOfUsers--;
       if(temp6.At(3)=="male"){
         NumOfMale--;
       }
       else if(temp6.At(3)=="female" ){
         NumOfFemale--;
       }
       if (temp6.At(6)== "Pfizer" ||temp6.At(6)== "pfizer"){
        NumOfPfizer--;
       }
       else if (temp6.At(6)== "Astrazeneca" ||temp6.At(6)== "astrazeneca"){
        NumOfAstraZeneca--;
       }
       else if (temp6.At(6)== "Johnson" ||temp6.At(6)== "johnson"){
        NumOfJohnson--;
       }
       else if (temp6.At(6)== "Sinopharm" ||temp6.At(6)== "sinopharm"){
        NumOfSinopharm--;
       }
       else if (temp6.At(6)== "Sinovac" ||temp6.At(6)== "sinovac"){
        NumOfSinovac--;
       }
       if (temp6.At(7)== "1"){
        NumOfFirstdose--;
       }
       else if (temp6.At(7)== "2"){
        NumOfSecdose--;
       }
       save();
        cout<<"  done!!  "<<endl;
	   }
	   if(notFound==true){
        cout<<"invalid national id"<<endl;
	   }
}




void user::delete_all(){
    ofstream vaccine("vaccine.txt");
    vaccine<<"";
    vaccine.close();
    ofstream unvaccinated("unvaccinated.txt");
    unvaccinated<<"";
    unvaccinated.close();
    ofstream id("id.txt");
    id<<"";
    id.close();
    ofstream information;
    information.open("information.txt");
    for(int i =0 ; i<=9 ; i++){
        information<<"0.0"<<endl;
    }
    information.close();
    cout<<" done!!"<<endl;
}






void user::login(){
linkedlist<string> users;
    string temp , id , pass;
    cout << "Enter your ID: ";
	cin >> id;
	while (id.length() != 13)
	{
		cout << "invalid national id" << endl;
		cout << "enter national id contain 13 numbers" << endl;
		cin >> id;
	}
	cout << "Enter your PASSWORD: ";
	cin>> pass;
    ifstream vaccine;
	vaccine.open("vaccine.txt");
    while(vaccine>>temp){
      users.Append(temp);
    }
    vaccine.close();
    bool notFound = true;
	while(notFound){
	for(int i=0; i< users.Length() ; i++ ){
        temp = users.At(i);
    if(temp.find(id) != std::string::npos &&temp.find(pass) != std::string::npos ){
        int x;
        while(true){
        cout<<"if you want to display your data press 1"<<endl;
        cout<<"if you want to update your data press 2"<<endl;
        cout<<"if you want to delete your data press 3"<<endl;
        cout<<"if you want to exit press 4"<<endl;
        cin>>x;
        if(x==1){
            disply_usre(id , pass);
        }
        else if(x==2){
            update_data(id);
        }
        else if(x==3){
            delete_usre();
        }
        else if(x==4){
            break;
        }
        else {
            cout<<"enter valid number"<<endl;
        }
        }
        notFound= false;
        break;
    }
}
    if(notFound==true){
        cout<<"not found"<<endl;
        break;
    }
	}

}

void user::update_data(string id){
linkedlist<string> users;
linkedlist<string> temp3;
string temp ,temp2 ;
fstream vaccine;
vaccine.open("vaccine.txt");
 while(vaccine>>temp){
      users.Append(temp);
    }
vaccine.close();
 bool notFound = true;
 while(notFound){
   for(int i=0; i< users.Length() ; i++ ){
      temp = users.At(i);
      if(temp.find(id) != std::string::npos){
          temp2 = temp;
         notFound = false;
         ofstream tmp;
	     tmp.open("tmp.txt");
         for(int j=0 ; j< temp.length() ; j++){
           if(temp.at(j) != '|'){
             tmp<<temp.at(j);
           }
           else
            tmp<<endl;
           continue;
        }
        tmp.close();
        users.DeleteAt(i);
        ofstream vaccine;
        vaccine.open("vaccine.txt");
        for(int s =0 ; s<users.Length() ; s++){
            vaccine<<users.At(s)<<endl;
        }
        vaccine.close();
         break;
    }

  }
 if( notFound == true){
           cout<<"not found"<<endl;
            break;
    }
 }
if(notFound == false){
  ifstream tmp;
  tmp.open("tmp.txt");
  for(int k=0 ; k<=9 ;k++){
    tmp>>temp;
    temp3.Append(temp);
  }
  tmp.close();
  remove("tmp.txt");
 int x;
    while(true){
  cout<<"you want to update in 1:name 2:id 3:age 4:gender 5:country 6:Governorate 7:NameOfVaccine 8:NumOfDoses 9:password 0:stop "<<endl;
   cin>>x;
   if(x==2){
         cout<<"enter your edit"<<endl;
        cin>>temp;
        while (temp.length() != 13)
	       {
	        	cout << "invalied national id" << endl;
		        cout << "enter national id contain 13 numbers" << endl;
		        cin >> temp;
	         }
       temp3.DeleteAt(1);
    temp3.InsertAt(1 , temp);
   }
  else if(x<=9 && x!=2 && x>0){
   cout<<"enter your edit"<<endl;
     cin>>temp;
     temp3.DeleteAt(x-1);
    temp3.InsertAt(x-1 , temp);
   }
else if(x==0){
    cout<<"done!!"<<endl;
    break;
}
else{
    cout<<"invalied choice"<<endl;
   }
 }
vaccine.open("vaccine.txt" , ios::app);

for(int n =0 ; n<9 ; n++){
    vaccine << temp3.At(n)<<"|";

        }
vaccine.close();

if(temp3.At(6) == "###"){
 update_data2(temp2);
 ofstream unvaccinated;
unvaccinated.open("unvaccinated.txt", ios::app);
for(int n =0 ; n<9 ; n++){
     unvaccinated << temp3.At(n)<<"|";
    }
     unvaccinated.close();
}
  }
}



void user::update_data2(string temp2){
string temp;
linkedlist<string> temp4;
fstream unvaccinated;
unvaccinated.open("unvaccinated.txt");
    while(unvaccinated>>temp){
       temp4.Append(temp);
    }
     delete_unvaccinated();
    unvaccinated.close();
  for(int q =0 ; q<temp4.Length() ; q++){
        temp =temp4.At(q);

    if(temp2 == temp){
       temp4.DeleteAt(q);
    }
      }
unvaccinated.open("unvaccinated.txt");
for(int i =0 ; i<temp4.Length() ; i++){
    unvaccinated<<temp4.At(i)<<endl;
}

unvaccinated.close();

}

void user::delete_unvaccinated(){
 ofstream unvaccinated("unvaccinated.txt");
    unvaccinated<<"";
    unvaccinated.close();
}

void user::save() {
	ofstream information;
	information.open("information.txt");
	information << user::getNumOfUsers()<< endl;
	information << user::getNumMale() << endl;
	information << user::getNumOfFemale() << endl;
	information << user::getNumOfPfizer() << endl;
    information << user::getNumOfAstraZeneca() << endl;
	information << user::getNumOfJohnson() << endl;
	information << user::getNumOfSinopharm() << endl;
	information << user::getNumOfSinovac() << endl;
	information << user::getNumOfFirstdose() << endl;
	information << user::getNumOfSecdose() << endl;
	information.close();

}

void user::show_wating_list(){
  string line;
  queuelist<string> q;
  ifstream unvaccinated;
  unvaccinated.open("unvaccinated.txt");
  while (unvaccinated >> line)
	{
      q.enqueue(line);
	}
 	unvaccinated.close();

   	while(!q.empty()){
        cout<<q.Front()<<endl;
        q.dequeue();
   	}
}
