#ifndef USER_H
#define USER_H
#include<string>
using namespace std;
class user
{
    private:
	string FName;
	string mName;
	string lName;
    string NationalID;
	string password;
	string Gender;
	string Age;
	string Country;
	string Governorate;
	string vaccinated;
	string NameOfVaccine;
	string NumOfDoses;
    static float NumOfUsers;
    static float NumOfMale;
    static float NumOfFemale;
    static float NumOfPfizer;
    static float NumOfAstraZeneca;
    static float NumOfJohnson;
    static float NumOfSinopharm;
    static float NumOfSinovac;
    static float NumOfFirstdose;
    static float NumOfSecdose;

public:
	user();
	void add_information();
	void counter();
	void Doses();
	string getFName();
	string getmName();
	string getlName();
	string getNationalID();
	string getpassword();
	string getGender();
	string getAge();
	string getCountry();
	string getGovernorate();
	string getNameOfVaccine();
	string getNumOfDoses();
	string getvaccinated();
    static int getNumOfUsers();
    static int getNumMale();
	static int getNumOfFemale();
	static int getNumOfPfizer();
	static int getNumOfAstraZeneca();
    static int getNumOfJohnson();
    static int getNumOfSinopharm();
    static int getNumOfSinovac();
    static int getNumOfFirstdose();
    static int getNumOfSecdose();
	static void delete_unvaccinated();
	static void ReturnValues();
	static bool check(string o);
	static void disply_usre(string id , string pass);
	static void disply_usrefor_admin(string id);
    static void displyAll();
    static void delete_usre();
    static void delete_all();
    static void login();
    static void update_data(string id);
    static void update_data2(string temp2);
    static void save();
    static void show_wating_list();
};

#endif // USER_H
