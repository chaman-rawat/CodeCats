// Main modules are defined here
#include "helpers.h"

int display_menu()
{
    clrscr();
    int choice;
    cout << "==========================================" << endl;
    cout << "||               POKEMART               ||" << endl;
    cout << "==========================================" << endl;
    cout << "|                                        |" << endl;
    cout << "|        1. Display Items                |" << endl;
    if (user_login.is_login)
    {
        cout << "|        2. Cart                         |" << endl;
        cout << "|        3. Signout                      |" << endl;
    }
    else
    {
        cout << "|        2. Login                        |" << endl;
        cout << "|        3. Signup                       |" << endl;
    }
    cout << "|        4. Exit                         |" << endl;
    cout << "|                                        |" << endl;
    cout << "|        Contact Us: " << contact_us << "          |" << endl;
    cout << "==========================================" << endl;
    if (user_login.is_login)
    {
        cout << endl
             << "Welcome, " << user_login.current_user.name << endl;
    }

    cout << endl
         << "Choose an option: ";
    cin >> choice;
    return choice;
}

void display_items(void)
{
    clrscr();
    cout << "======================================================================" << endl;
    cout << "||                             POKEMART                             ||" << endl;
    cout << "======================================================================" << endl;
    cout << "Item Id\t      Item Name\t      MRP       Discount    GST     Buy Price" << endl;
    cout << "-------\t      ---------\t      ---       --------    ---     ---------" << endl;

    for (int i = 0; i < total_items; i++)
    {
        cout << setw(4) << items[i].item_id << "\t";
        cout << setw(15) << items[i].item_name;
        cout << setw(10) << "₹" << items[i].mrp << "\t";
        cout << setw(5) << items[i].discount << '%' << "\t ";
        cout << setw(5) << items[i].gst << '%';
        cout << setw(8) << "₹" << items[i].buy_price;
        cout << endl;
    }
    cout << "======================================================================" << endl;

    if (user_login.is_login)
    {
        int item_id;
        char choice;
        do
        {
            cout << endl
                 << "Select Item Id: ";
            cin >> item_id;
            if (item_id < 1 || item_id > total_items)
            {
                cout << "Please select a valid Item Id." << endl;
                choice = 'Y';
                continue;
            }

            cout << "Do you want to add '" << items[item_id - 1].item_name << "', (Y / N) : ";
            cin >> choice;
            if (choice == 'Y' || choice == 'y')
            {
                add_to_cart(items[item_id - 1]);
                cout << "'" << items[item_id - 1].item_name << "' added to cart, ";
            }
            else
                cout << "'" << items[item_id - 1].item_name << "' discarded from cart, ";

            cout << "continue shopping, (Y / N) : ";
            cin >> choice;
        } while (choice == 'Y' || choice == 'y');
    }
    else
    {
        cout << endl
             << "Please login to add items to your cart!" << endl;
    }
}

void login(void)
{
    clrscr();
    cout << "==========================================" << endl;
    cout << "||               POKEMART               ||" << endl;
    cout << "==========================================" << endl;
    cout << "|                                        |" << endl;
    cout << "|                 SIGNIN                 |" << endl;
    cout << "|                                        |" << endl;
    cout << "|        Contact Us: " << contact_us << "          |" << endl;
    cout << "==========================================" << endl
         << endl;
    cout << "Enter the following detail: " << endl
         << endl;

    char username[50], password[50];
    int try_left = 3;

    cout << "Username: ";
    cin >> username;
    while (!is_user_exist(username))
    {
        cout << "Username not found, Try again!" << endl;
        cout << "Username: ";
        cin >> username;
    }

    cout << "Password: ";
    cin >> password;
    while (!validate_user(username, password) && try_left)
    {
        cout << "Password does not match, Try again!"
             << " (" << try_left-- << " try left)" << endl;
        cout << "Password: ";
        cin >> password;
    }
    if (try_left)
        user_login.is_login = true;
    clrscr();
    if (user_login.is_login)
        cout << "Succesfully Logged in" << endl;
    else
        cout << "Error Logging in!" << endl;
}

void cart(void)
{
    clrscr();
    cout << "==========================================" << endl;
    cout << "||               POKEMART               ||" << endl;
    cout << "==========================================" << endl;
    cout << "|                                        |" << endl;
    cout << "|                  CART                  |" << endl;
    cout << "|                                        |" << endl;
    cout << "|        Contact Us: " << contact_us << "          |" << endl;
    cout << "==========================================" << endl
         << endl;

    if (user_cart.is_empty)
    {
        cout << "No items in the cart!" << endl;
        return;
    }

    cout << "Item Id           Items           Price" << endl;
    cout << "-------       -------------       -----" << endl;
    int count_total_items = 0;
    for (int i = 0; i < total_items; i++)
    {
        if (!user_cart.cart_items[i])
            continue;
        cout << setw(4) << items[i].item_id << "\t";
        cout << setw(15) << items[i].item_name << " x " << user_cart.cart_items[i];
        cout << setw(10) << "₹" << items[i].buy_price;
        cout << endl;
        count_total_items += user_cart.cart_items[i];
    }
    cout << "\t      ---------------------------" << endl;
    cout << "\t       Total:   x " << count_total_items << "       ₹" << user_cart.total_sum << endl;
    cout << endl;

    // To do delete checkout pay tomorrow
    char choice;
    cout << "==========================================" << endl;
    cout << "|      1. Place Order                    |" << endl;
    cout << "|      2. Delete Item                    |" << endl;
    cout << "|      3. Go Back                        |" << endl;
    cout << "==========================================" << endl;
    cout << "Enter choice : ";
    cin >> choice;

    switch (choice)
    {
    case '1':
        place_order();
        break;

    case '2':
        delete_cart_item();
        cart();
        break;

    default:
        cout << endl
             << "Returning to the main menu." << endl;
        break;
    }
}

void signup(void)
{
    clrscr();
    cout << "==========================================" << endl;
    cout << "||               POKEMART               ||" << endl;
    cout << "==========================================" << endl;
    cout << "|                                        |" << endl;
    cout << "|                 SIGNUP                 |" << endl;
    cout << "|                                        |" << endl;
    cout << "|        Contact Us: " << contact_us << "          |" << endl;
    cout << "==========================================" << endl;
    cout << "Enter the following detail: " << endl;
    struct Users user;

    cout << "Name: ";
    cin.ignore(); // flushes the newline "\n" out of the buffer before using cin.getline
    cin.getline(user.name, sizeof(user.name));

    cout << "Address: ";
    cin.getline(user.address, sizeof(user.address));

    cout << "Mobile Number: ";
    cin >> user.mobile_number;

    cout << "Username: ";
    cin >> user.username;
    while (is_user_exist(user.username))
    {
        cout << "Username already taken, Try again!" << endl
             << endl;
        cout << "Username: ";
        cin >> user.username;
    }

    cout << "Email: ";
    cin >> user.email;

    char password[50];
    cout << "Password: ";
    cin >> password;

    user.password_hash = hash_me(password);

    save_new_user(&user);

    clrscr();
    cout << "Successfully Signed Up" << endl;
}

void logout(void)
{
    clrscr();
    user_login.is_login = false;
    if (!user_login.is_login)
        cout << "Successfully Logout" << endl;
    else
        cout << "Error Logging Out" << endl;
}