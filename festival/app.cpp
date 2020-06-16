#include "login.h"
#include<iostream>
#include<vector>
#include<sstream>

int main()
{
    int logged;
    std::string artisti;
    LoginManager loginManagerObj;
    logged = loginManagerObj.login();
    if (logged)
    {
        cout << "Inca sunteti logat" << endl;
    }
    else {
        cout << "Nu sunteti logat" << endl;
        logged = loginManagerObj.login();
    }
    cout << "Apasa 0 pt delogare" << endl;
    cin >> logged;
    if (logged == 0)
        cout << "Nu mai sunteti logat" << endl;
        return 0;
}

