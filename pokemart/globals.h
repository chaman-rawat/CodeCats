// All global variable defined here
char contact_us[20];
int total_items;

struct Users
{
    char name[50];
    char address[100];
    char mobile_number[20];
    char username[30];
    char email[30];
    unsigned long password_hash;
};

struct Login
{
    bool is_login = false;
    struct Users current_user;
} user_login;

struct Items
{
    unsigned int item_id;
    char item_name[50];
    float mrp;
    short discount;
    short gst;
    float buy_price;
} * items;

struct Cart
{
    bool is_empty = true;
    float total_sum;
    int *cart_items;
} user_cart;