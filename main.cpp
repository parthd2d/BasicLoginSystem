#include <bits/stdc++.h>

using namespace std;

bool isLoggedIn()
{
    string username, password, un, pw;

    cout << "Enter username: ";
    cin >> username;

    cout << "Enter password: ";
    cin >> password;

    ifstream read(username + ".txt");
    getline(read, un);
    getline(read, pw);

    if (un == username and pw == password)
    {
        return true;
    }

    return false;
}

void registerID()
{
    string username, password;

    cout << "Enter a username: ";
    cin >> username;

    cout << "Enter a password: ";
    cin >> password;

    ofstream file;
    file.open(username + ".txt");
    file << username << "\n"
         << password;
    file.close();

    return;
}

int main()
{
    int choice;

    cout << "1. Register\n2. Login\nYour choice: ";
    cin >> choice;

    switch (choice)
    {
    case 1:
    {
        registerID();
        main();
        break;
    }
    case 2:
    {
        bool status = isLoggedIn();

        if (!status)
        {
            cout << "False login!!!\n";
            system("PAUSE");
            return 1;
        }
        else
        {
            cout << "Successfully logged in\n";
            system("PAUSE");
            return 0;
        }
        break;
    }
    default:
    {
        cout << "Enter proper choice!!!\n";
        break;
    }
    }

    return 0;
}