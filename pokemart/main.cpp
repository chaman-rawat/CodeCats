#include "modules.h"

int main()
{
    initial_setup();
    while (true)
    {
        int choice = display_menu();

        switch (choice)
        {
        case 1:
            display_items();
            break;

        case 2:
            if (user_login.is_login)
                cart();
            else
                login();
            break;

        case 3:
            if (user_login.is_login)
                logout();
            else
                signup();
            break;

        case 4:
            cout << endl
                 << "Thanks for visiting us, have a good day!" << endl;
            return 0;
            break;

        case 9:
            clrscr();
            cout << "All users list" << endl;
            cout << "-----------------" << endl;
            get_all_user();
            break;

        default:
            cout << "Enter a valid choice!" << endl;
            break;
        }

        cout << endl
             << "-- Press Enter to continue --";
        getch();
    }

    free_memory();
    return 0;
}