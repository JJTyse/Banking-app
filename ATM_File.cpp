#include <iostream>
#include <sstream>
#include <fstream>
#include <string>
#include <vector>
#include <cstddef>
#include <algorithm>


std::string Random_Acc_Num_Generator(std::string Name){
    std::string initial_input = Name;

    int i;
    char c;
    int ascii_conversion;
    std::string ascii_string;
    std::string ascii_compiled;
    std::string ascii_randomed;
    std::string ascii_six_letter;
    std::string Rand_Acc_Num;

    for(i = 0; i < initial_input.length(); i++){
        c = initial_input[i];
        ascii_conversion = int(c);
        ascii_string = std::to_string(ascii_conversion);
        ascii_compiled.append(ascii_string);
        }

    ascii_randomed = ascii_compiled;
    std::random_shuffle(ascii_randomed.begin(), ascii_randomed.end());
    ascii_six_letter = ascii_randomed.substr(0,6);

    Rand_Acc_Num = ascii_six_letter;

    return Rand_Acc_Num;
}

bool Account_Num_Check(std::string Account_Number){

    int length_Account_Number = Account_Number.length();
    bool Is_Account_Number_Valid;

    std:: string num_values = "0123456789";
    std:: size_t look = Account_Number.find_first_not_of(num_values);

    if(length_Account_Number == 6 && look == std::string::npos){
        Is_Account_Number_Valid = true;
        }else{
        Is_Account_Number_Valid = false;
        }
    return Is_Account_Number_Valid;
}

bool PIN_Check(std::string PIN){

    int length_PIN = PIN.length();
    bool Is_PIN_Valid;

    std:: string num_values = "0123456789";
    std:: size_t look = PIN.find_first_not_of(num_values);

    if(length_PIN == 4 && look == std::string::npos){
        Is_PIN_Valid = true;
        }else{
        Is_PIN_Valid = false;
        }
    return Is_PIN_Valid;
}

bool Acc_Name_Check (std::string Acc_Name){

    int length_Acc_Name = Acc_Name.length();
    bool Is_Acc_Name_Valid;

    if(length_Acc_Name >= 3 && length_Acc_Name < 64){
        Is_Acc_Name_Valid = true;
        }else{
        Is_Acc_Name_Valid = false;
        }
    return Is_Acc_Name_Valid;
}

class Bank_Account{
    private:
        std::string PIN;
        std::string Account_Num;

    public:
        std::string Account_Name;
        double Account_Balance;
        Bank_Account(std::string aAccount_Name, std::string aAccount_Num, double aAccount_Balance, std::string aPIN){
            Account_Name = aAccount_Name;
            Account_Balance = aAccount_Balance;
            Input_Pin(aPIN);
            Input_Account_Num(aAccount_Num);

        }
    void Input_Pin(std::string aPIN){
            bool Is_Valid_PIN = PIN_Check(aPIN);
            if(Is_Valid_PIN){
                PIN = aPIN;
            }else{
                PIN = "Incorrect PIN";
                }
    }

    void Input_Account_Num(std::string aAccount_Num){
            bool Is_Valid_Account_Num = Account_Num_Check(aAccount_Num);
            if(Is_Valid_Account_Num){
                Account_Num = aAccount_Num;
            }else{
                Account_Num = "Incorrect Account Number";
            }
        }


    void printname(){
        if(Account_Num == "Incorrect Account Number" && PIN == "Incorrect PIN"){
            std::cout << "Account number and PIN error. Please input account number with 6 digits and no characters\nand a PIN with 4 digits and no characters." << std::endl;
        }else if (Account_Num == "Incorrect Account Number"){
            std::cout << "Account number error. Please input number with 6 digits and no characters." << std::endl;
        }else if(PIN == "Incorrect PIN"){
            std::cout << "PIN error. Please input number with 4 digits and no characters." << std::endl;
        }
        else{
            std::cout << "Account Name: " << Account_Name << std::endl;
            std::cout << "Account Number: " << Account_Num << std::endl;
            std::cout << "Balance: " << Account_Balance << std::endl;
            std::cout << "PIN: " << PIN << std::endl;

            }

        }
    std::string getDetails();

};

Bank_Account Account_Set_up(){
    std::string Acc_Name;
    std::string Acc_Num;
    double Balance;
    std::string PIN;

    std::cout << "Account Setup" << std::endl;
    std::cout << std::endl;

    do{
    std::cout << "Enter Account Name (Must be between 3 and 64 letters in length):" << std::endl;
    std::getline(std::cin, Acc_Name);
    std::cout << std::endl;
   }
    while(Acc_Name_Check(Acc_Name) == 0);

    std::cout << "Enter your Starting Balance (This must be a number):" << std::endl;
    std::cin >> Balance;
    std::cout << std::endl;

    do{
    std::cout << "Choose your 4 digit Pin it must only contain numbers:" << std::endl;
    std::cin >> PIN;
    std::cout << std::endl;
    }
    while(PIN_Check(PIN) == 0);

    Acc_Num = Random_Acc_Num_Generator(Acc_Name);

    Bank_Account Acc_Obj(Acc_Name, Acc_Num, Balance, PIN);

    Bank_Account result = Acc_Obj;

    Acc_Obj.printname();

    return result;
}

std::string Bank_Account::getDetails(){
    std::string details = "Account Name: "+Account_Name+" Account Number: "+Account_Num+" Balance: "+std::to_string(Account_Balance)+" PIN "+PIN;
    return details;
}

int main(){

    std::cout << "Banking App" << std::endl;
    std::vector<Bank_Account> Acc_Database;

    Bank_Account Joe = Account_Set_up();
    Acc_Database.push_back(Joe);

    Bank_Account John= Account_Set_up();
    Acc_Database.push_back(John);

    for (std::size_t i = 0; i <= Acc_Database.size();++i){
        std::cout << Acc_Database.at(i).getDetails() << "," << std::endl;
    }

    //One.printname();

    return 0;

}
