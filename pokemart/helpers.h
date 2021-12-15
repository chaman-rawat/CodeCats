// Helper function defined here
#include <iostream>
#include <fstream>
#include <iomanip>
#include "globals.h"
using namespace std;

// Clears console screen
void clrscr(void)
{
    // Compatible in both windows and unix based OSes
    cout << "\033[2J\033[1;1H";
}

// Take a character from user
void getch(void)
{
    cin.get();
    cin.get();
}

// Compares two strings
bool strcmp(char *s1, char *s2)
{
    while (*s1++ == *s2++)
        if (*s1 == '\0' && *s2 == '\0')
            return false; // Strings are equal
    return true;          // Strings aren't equal
}

// Set value to the 'contact_us' global variable
void setup_contact_us(void)
{
    ifstream infile;
    infile.open("data/contact_us.txt");
    if (!infile)
        cout << "Error Opening File!!!";
    infile >> contact_us;
    infile.close();
}

// Set value of global variable total_items
void count_total_items(void)
{
    ifstream fin("data/items.txt");
    char c;
    while (fin.get(c))
        if (c == '\n')
            total_items++;
    total_items++;
    return;
}

// Returns a pointer to all items array from the items.txt
struct Items *load_items(void)
{
    ifstream fin("data/items.txt");
    struct Items *items = new struct Items[total_items];
    for (int i = 0; !fin.eof(); i++)
    {
        items[i].item_id = i + 1;
        fin >> items[i].item_name;
        fin >> items[i].mrp;
        fin >> items[i].discount;
        fin >> items[i].gst;
        items[i].buy_price = items[i].mrp * (100 - items[i].discount) * (100 + items[i].gst) / 10000;
    }
    return items;
}

// Used for loading values from data files
void initial_setup(void)
{
    setup_contact_us();
    count_total_items();
    items = load_items();
    user_cart.cart_items = new int[total_items]();
}

// Checks if an given username already exists or not
bool is_user_exist(char *username)
{
    ifstream fin("data/users.txt");
    struct Users user;

    while (fin.read((char *)&user, sizeof(struct Users)))
        if (!strcmp(username, user.username))
        {
            fin.close();
            return true;
        }
    fin.close();
    return false;
}

// Hash function (for passwords)
unsigned long hash_me(const char *str)
{
    unsigned long hash = 1;
    do
    {
        hash *= (*str) * (*str + 1) * (*str + 2) * (*str + 3) + 1235456789;
        hash += *str;
    } while (*++str);
    hash = ((hash + hash) * hash) % 1234567890;
    return hash;
}

// Add a new user account to the users.txt file
void save_new_user(struct Users *user)
{
    ofstream fout("data/users.txt", ios::app);
    fout.write((char *)user, sizeof(struct Users));
    fout.close();
}

// Check credential of a given users (for login authentication)
bool validate_user(char *username, char *password)
{
    ifstream fin("data/users.txt");
    struct Users user;

    while (fin.read((char *)&user, sizeof(struct Users)))
        if (!strcmp(username, user.username))
            if (hash_me(password) == user.password_hash)
            {
                user_login.current_user = user;
                fin.close();
                return true;
            }
    fin.close();
    return false;
}

// Add given item to the user_cart
void add_to_cart(struct Items item)
{
    user_cart.total_sum += item.buy_price;
    items[item.item_id - 1] = item;
    user_cart.cart_items[item.item_id - 1]++;
    user_cart.is_empty = false;
}

// Resets user cart
void reset_cart(void)
{
    user_cart.is_empty = true;
    user_cart.total_sum = 0;
    for (int i = 0; i < total_items; i++)
        user_cart.cart_items[i] = 0;
}

// Store users order bill to the order.txt file
void place_order(void)
{
    ofstream fout("data/order.txt", ios::app);
    fout << "==================================================" << endl;
    fout << "||                ORDER PLACED                  ||" << endl;
    fout << "==================================================" << endl << endl;

    fout << "   Name : " << user_login.current_user.name << endl;
    fout << "   Total Amout: ₹" << user_cart.total_sum << endl;
    fout << "   Delivery Address : " << user_login.current_user.address << endl;
    fout << "   Phone no. : " << user_login.current_user.mobile_number << endl;
    fout << "   Email ID: " << user_login.current_user.email << endl << endl;

    fout << "             Contact Us: " << contact_us << endl << endl;
    fout << "==================================================" << endl << endl << endl;
    fout.close();

    reset_cart();

    clrscr();
    cout << "Your order is placed successfully." << endl;
}

// Deletes selected items from the cart
void delete_cart_item(void)
{
    clrscr();
    cout << "Item Id           Items           Price" << endl;
    cout << "-------       -------------       -----" << endl;
    for (int i = 0; i < total_items; i++)
    {
        if (!user_cart.cart_items[i])
            continue;
        cout << setw(4) << items[i].item_id << "\t";
        cout << setw(15) << items[i].item_name << " x " << user_cart.cart_items[i];
        cout << setw(10) << "₹" << items[i].buy_price;
        cout << endl;
    }

    int item_id;
    cout << endl << "Enter Item ID you want to remove: ";
    cin >> item_id;
    item_id--;
    if (!user_cart.cart_items[item_id] || item_id < 0 || item_id >= total_items)
    {
        cout << "Item ID doesn't found in your cart!!!" << endl;
        cout << endl << "-- Press Enter to try again --";
        getch();
        delete_cart_item();
        return;
    }

    user_cart.total_sum -= items[item_id].buy_price * user_cart.cart_items[item_id];
    user_cart.cart_items[item_id] = 0;
    user_cart.is_empty = true;

    for (int i = 0; i < total_items; i++)
        if (user_cart.cart_items[i])
            user_cart.is_empty = false;

    cout << "'" << items[item_id].item_name << "' Deleted from your cart." << endl;
    cout << endl << "-- Press Enter to continue --";
    getch();
}

// Frees the memory assigned to pointers
void free_memory(void)
{
    delete[] items;
    delete[] user_cart.cart_items;
}

// To list all accounts (for developers)
void get_all_user(void)
{
    ifstream fin("data/users.txt");
    int user_count = 0;
    struct Users user;
    while (fin.read((char *)&user, sizeof(struct Users)))
    {
        cout << ++user_count << ". " << user.username << "  |  ";
        cout << user.password_hash << endl;
    }
    fin.close();
}