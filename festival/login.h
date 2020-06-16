#include <iostream>
#include <fstream>
using namespace std;
class LoginManager
{
public:
    LoginManager()
    {
        accessGranted = 0;
    }
    int login()
    {
        cout << "User:";
        cin >> userNameAttempt;
        userName = getFile("users.txt");
        if(userNameAttempt == userName)
        {
            cout << "Parola:";
            cin >> passWordAttempt;
            passWord = getFile("pass.txt");
            if(passWordAttempt == passWord)
            {
                cout << "---- Artisti din fisier txt ---" << endl;
                printFile("artisti.txt");
                cout << "---- Filme din fisier txt ---" << endl;
                printFile("filme.txt");
                cout << "---- Artisti din fisier csv ---" << endl;
                printFile("artisti.csv");
                cout << "---- Filme din fisier csv ---" << endl;
                printFile("filme.csv");
                return 1;
            }
            else
            {
                cout << "Parola gresita." << endl;
                login();
            }
        }
        else
        {
            cout << "Credentiale gresite." << endl;
            login();
        }
    }
    string getFile(const char* p_fileName)
    {
        string line;
        fstream file;
        file.open(p_fileName, ios::in);
        if(file.is_open())
        {
            getline(file, line);
        }
        file.close();
        return line;
    }
    string printFile(const char* p_fileName)
    {
        std::ifstream f(p_fileName);
        std::string line;
        while(std::getline(f, line))
        std::cout << line << '\n';
    }

private:
    string passWord = "parola";
    string userName = "andrei";
    string userNameAttempt;
    string passWordAttempt;
    bool accessGranted;
};
