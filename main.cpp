#include<iostream>
#include<fstream>
#include<string>
#include "user.h"
using namespace std;
void AddToFile();
void first_dose_percentage();
void sec_dose_percentage();
void unvaccinated_percentage();
void precentage_of_gender();
void precentage_of_typesofvaccine();
void userr();
void admin();
int main()
{
    string answer;
    cout << "Hello !" <<endl <<" you are admin press \"1\" or user press \"2\"" << endl;
      cin>>answer;
    while (answer != "1" && answer != "2" ) {
        cout << " Invalid choise ... please try again \n" << endl;
        cout << " your choice: >> ";
        cin >> answer;
    }
    if(answer== "1"){
       admin();
    }

    else if(answer== "2"){
        userr();
     }
	return 0;
}


void AddToFile() {
	user x;
	if (x.check(x.getNationalID())) {
		fstream vaccine;
		vaccine.open("vaccine.txt", ios::app);
		vaccine <<x.getFName()<<"." << x.getmName()<<"." << x.getlName()<<"|";
		vaccine << x.getNationalID()<<"|";
		vaccine << x.getAge()<<"|";
		vaccine << x.getGender()<<"|";
		vaccine << x.getCountry()<<"|";
		vaccine  << x.getGovernorate()<<"|";
		vaccine << x.getNameOfVaccine()<<"|";
		vaccine  << x.getNumOfDoses()<<"|";
        vaccine << x.getpassword()<<"|" << endl;
		vaccine.close();
        user::save();
		if (x.getvaccinated() == "False" || x.getvaccinated() == "false") {
			fstream unvaccinated;
			unvaccinated.open("unvaccinated.txt", ios::app);
			cin.ignore();
			unvaccinated << x.getFName()<<"." << x.getmName()<<"."<< x.getlName()<<"|";
			unvaccinated << x.getNationalID()<<"|";
			unvaccinated <<  x.getAge()<<"|";
			unvaccinated << x.getGender()<<"|";
			unvaccinated <<x.getCountry()<<"|";
			unvaccinated <<x.getGovernorate()<<"|";
			unvaccinated << x.getNameOfVaccine()<<"|";
			unvaccinated << x.getNumOfDoses()<<"|";
			unvaccinated << x.getpassword() << endl;
			unvaccinated.close();
		}
}
}



void first_dose_percentage() {
     user::ReturnValues();
    float percentage=(user::getNumOfFirstdose()*100 )/ user::getNumOfUsers();
	cout<< "first dose percentage:"<<percentage <<"%"<<endl;
}
void sec_dose_percentage() {
     user::ReturnValues();
	cout<<"seconde dose percentage:"<<(user::getNumOfSecdose()*100) / user::getNumOfUsers()<<"%"<<endl;
}
void unvaccinated_percentage() {
     user::ReturnValues();
     int x;
     x = user::getNumOfUsers()-(user::getNumOfSecdose() + user::getNumOfFirstdose());
	cout<<"unvaccinated percentage:"<<(x*100) / user::getNumOfUsers()<<"%"<<endl;
}

void precentage_of_gender() {
     user::ReturnValues();
     cout<<"males percentage:"<<(user::getNumMale() * 100) / user::getNumOfUsers()<<"%"<<endl;
     cout<<"females percentage:"<<(user::getNumOfFemale() * 100)/ user::getNumOfUsers()<<"%"<<endl;
}

void precentage_of_typesofvaccine() {
     user::ReturnValues();
     cout<<"Pfizer percentage:"<<(user::getNumOfPfizer() * 100 )/ user::getNumOfUsers()<<"%"<<endl;
     cout<<"AstraZeneca percentage:"<<(user::getNumOfAstraZeneca() * 100) / user::getNumOfUsers()<<"%"<<endl;
     cout<<"Johnson percentage:"<<(user::getNumOfJohnson() * 100) / user::getNumOfUsers()<<"%"<<endl;
     cout<<"Sinopharm percentage:"<<(user::getNumOfSinopharm()  * 100 )/ user::getNumOfUsers()<<"%"<<endl;
     cout<<"Sinovac percentage:"<<(user::getNumOfSinovac() * 100)/ user::getNumOfUsers()<<"%"<<endl;
}

void admin(){
   string adminpass = "1111";
    cout << "enter the admin password" << endl;
    string x;
    cin >> x;
    while (true)
    {
        if (x == adminpass) {
            while (true) {
                cout << endl;
                cout<< "Choose what do you want.\n1- Percentage of registered for the first dose.\n2- Percentage of registered for the second dose.\n3- Percentage of unvaccinated.\n4- Percentage of gender.\n5- Percentage of types of vaccine.\n";
                cout <<"6- show all users.\n7- show specific user.\n8- delete all users.\n9- delete specific user.\n#- display wating list.\n0- exite."<< endl;
                string x;
                cin >> x;
                if (x == "1") {
                    first_dose_percentage();
                }
                else if (x == "2") {
                    sec_dose_percentage();
                }
                else if (x == "3") {
                    unvaccinated_percentage();
                }
                else if (x == "4") {
                    precentage_of_gender();
                }
                else if (x == "5") {
                    precentage_of_typesofvaccine();
                }
                else if (x == "6") {
                    user::displyAll();
                }
                else if (x == "7") {
                    cout << "enter the national id :" << endl;
                    string id;
                    cin >> id;
                    user::disply_usrefor_admin(id);
                }
                else if (x == "8") {
                    user::delete_all();
                }
                else if (x == "9") {
                    user::delete_usre();
                }
                else if (x == "#") {
                    user::show_wating_list();
                }
                else
                    break;
            }
            break;
        }
        else {
            cout << "Incorrect password try again" << endl;
        }
        cin >> x;
    }
}

void userr(){
 while(true) {
        cout << "if you want to register now press 1" << endl;
        cout << "if you want to login press 2" << endl;
        cout << "if you want to exit press 3" << endl;
        int x;
        cin >> x;

        if (x == 1) {
            AddToFile();
            break;
        }
        else if (x == 2) {
            user::login();
            break;
        }
        else if (x == 3) {
            break;
        }

        else {
            cout << "invalid choice" << endl;
        }

    }
}


