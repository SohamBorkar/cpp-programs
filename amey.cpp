#include <string.h>
#include <conio.h>
#include <iostream>
#include <iomanip>
using namespace std;

class Item
{
protected:
    int n = 0;
    struct item
    {
        char name[15];
        float price;
        int qty;
        int code;
    } I[50];

public:
    Item()
    {
        strcpy(I[n].name, "Pen");
        I[n].code = 45;
        I[n].qty = 0;
        I[n].price = 10.00;
        n++;
        strcpy(I[n].name, "Book");
        I[n].code = 89;
        I[n].qty = 0;
        I[n].price = 120.00;
        n++;
    }
    void showInventory();
};

class DealerMenu : public Item
{
public:
    bool actions(int);
    void addItem();
    void deleteItem();
};

class CustomerMenu : public Item
{
public:
    // CustomerMenu();
    bool actions(int);
    void addToCart();
    void showCart();
    void removeFromCart();
    void checkout();
};

class MainMenu : public DealerMenu, public CustomerMenu
{
public:
    bool actions(int);
};

void Item::showInventory()  
{
    if (n > 0)
    {
        cout << "\n\n===================================================\n";
        cout << "Item name\tItem code\tItem price" << endl;
        cout << "===================================================\n";
        for (int i = 0; i < n; i++)
        {
            cout << I[i].name;
            cout << setw(18);
            cout << I[i].code;
            cout << setw(18);
            cout << I[i].price;
            cout << endl;
        }
        cout << "===================================================\n";
        getch();
    }
    else
    {
        cout << "\n\n\n\t\tInventory is Empty!!";
        getch();
    }
}

bool CustomerMenu::actions(int ch)
{
    switch (ch)
    {
    case 0:
        return false;
    case 1:
        addToCart();
        break;
    case 2:
        showCart();
        break;
    case 3:
        removeFromCart();
        break;
    case 4:
        checkout();
        break;
    default:
        cout << "\n\n\n\t\tPlease Enter a valid input!";
        getch();
        break;
    }
    return true;
}

void CustomerMenu::addToCart()
{
    showInventory();
    int a;
Start:
    cout << "\n\t\tEnter item code which you want to purchase: ";
    cin >> a;

    for (int i = 0; i < n; i++)
    {
        if (a == I[i].code)
        {
            char ch;
            cout << "\t\tDo you want to purchase '" << I[i].name << "' (y/n)? ";
            cin >> ch;
            if (ch == 'y' || ch == 'Y')
            {
            Qty:
                cout << "\t\tPrice = " << I[i].price << " Rs\n\t\tEnter quantity: ";
                cin >> I[i].qty;
                cout << "\t\tTotal cost: " << I[i].qty * I[i].price << " Rs";

                if (I[i].qty > 0)
                {
                    cout << "\n\n\t\tItem added to your cart!!";
                    getch();
                    return;
                }
                else
                {
                    cout << "\n\t\tPlease enter valid quantity!!";
                    goto Qty;
                }
            }
            else
            {
                system("cls");
                cout << "\n\n\n\t\tProcess cancled!!";
                getch();
            }
            return;
        }
    }
    cout << "\n\t\tNo item found with code " << a << "!!" << endl;
    goto Start;
}

void CustomerMenu::showCart()
{  
    int count = 0;

    cout << "\n\n=============================================================\n";
    cout << "Item name\tItem code\tQuantity \tItem price" << endl;
    cout << "=============================================================\n";
    for (int i = 0; i < n; i++)
    {
        if (I[i].qty > 0)
        {
            cout << I[i].name;
            cout << setw(18);
            cout << I[i].code;
            cout << setw(18);
            cout << I[i].qty;
            cout << setw(15);
            cout << I[i].qty * I[i].price << " Rs";
            cout << endl;
            count++;
        }
    }
    if (count == 0)
    {
        cout << "\n\t\tYour shopping cart is empty!!\n\n";
    }
    cout << "=============================================================\n";
    getch();
}

void CustomerMenu::removeFromCart()
{
    showCart();
    int del;
    cout << "\n\tEnter the item code you want to delete form the cart: ";
    cin >> del;
    for (int i = 0; i < n; i++)
    {
        if (I[i].qty > 0)
        {
            if (del == I[i].code)
            {
                char ch;
                cout << "\tDo you want to delete '" << I[i].name << "' from your cart(y/n)? ";
                cin >> ch;
                if (ch == 'y' || ch == 'Y')
                {
                    I[i].qty = 0;
                    system("cls");
                    cout << "\n\n\n\t\tItem removed!!";
                    getch();
                    return;
                }
                else
                {
                    system("cls");
                    cout << "\n\n\n\t\tProcess cancled!!";
                    getch();
                    return;
                }
            }
        }
    }
    system("cls");
    cout << "\n\n\n\t\tNo item found with code " << del << " in your cart!!" << endl;
    getch();
    return;
}

void CustomerMenu::checkout()
{
    showCart();
    int total = 0;
    for (int i = 0; i < n; i++)
        if (I[i].qty > 0)
            total = total + (I[i].qty * I[i].price);
    if (total > 0)
    {
        cout << "\t\t\tTOTAl = " << total << " Rs." << endl;
        cout << "=============================================================\n";
        char ch;
        cout << "Do you want to conform your purchase(y/n)?";
        cin >> ch;
        if (ch == 'y' || ch == 'Y')
        {
            for (int i = 0; i < n; i++)
                if (I[i].qty > 0)
                    I[i].qty = 0;
            system("cls");
            cout << "\n\n\n\t\tplease pay " << total << " Rs at counter.\n\n\t\t\tTHANK YOU!!";
            getch();
            return;
        }
        else
        {
            system("cls");
            cout << "\n\n\n\t\tProcess cancled!!";
            getch();
            return;
        }
    }
}

bool DealerMenu::actions(int ch)
{
    switch (ch)
    {
    case 0:
        return false;
    case 1:
        addItem();
        break;
    case 2:
        showInventory();
        break;
    case 3:
        deleteItem();
        break;
    default:
        cout << "\n\n\n\t\tPlease Enter a valid input!";
        getch();
        break;
    }
    return true;
}
void DealerMenu::addItem()
{
    cout << "\n\n\t\tEnter item name: ";
    cin >> I[n].name;
    cout << "\n\t\tEnter item code: ";
    cin >> I[n].code;
    cout << "\n\t\tEnter item price: ";
    cin >> I[n].price;
    I[n].qty = 0;
    n++;
    system("cls");
    cout << "\n\n\n\t\tItem added to inventory!!";
    getch();
}
void DealerMenu::deleteItem()
{
    showInventory();
    if (n > 0)
    {
        int del;
        cout << "\n\tEnter the item code you want to delete: ";
        cin >> del;
        for (int i = 0; i < n; i++)
        {
            if (del == I[i].code)
            {
                char ch;
                cout << "\tDo you want to delete '" << I[i].name << "' (y/n)? ";
                cin >> ch;
                if (ch == 'y' || ch == 'Y')
                {
                    for (int j = i; j < n - 1; j++)
                    {
                        strcpy(I[j].name, I[j + 1].name);
                        I[j].code = I[j + 1].code;
                        I[j].price = I[j + 1].price;
                        I[j].qty = I[j + 1].qty;
                    }
                    n--;
                    system("cls");
                    cout << "\n\n\n\t\tItem removed!!";
                    getch();
                    return;
                }
                else
                {
                    system("cls");
                    cout << "\n\n\n\t\tProcess cancled!!";
                    getch();
                }
                return;
            }
        }
        cout << "\n\t\tNo item found with code " << del << "!!" << endl;
        getch();
    }
    return;
}

bool MainMenu::actions(int ch)
{
    switch (ch)
    {
    case 0:
        cout << "\n\n\n\t\tThank You, For using our system!!" << endl;
        getch();
        return false;
    case 1:
        int dch;
        do
        {
            system("cls");
            cout << "\n\n\t\t\tDELEAR MENU\n\t==========================================";
            cout << "\n\n\t\t[0] Return to Main menu\n\t\t[1] Add item to Inventory\n\t\t[2] Show Inventory\n\t\t[3] Delete item from Inventory\n\n\t\tInput: ";
            cin >> dch;
            system("cls");
        } while (DealerMenu::actions(dch));

        break;
    case 2:
        int cch;
        do
        {
            system("cls");
            cout << "\n\n\t\t\tCUSTOMER MENU\n\t==========================================";
            cout << "\n\n\t\t[0] Return to Main menu\n\t\t[1] Add item to Cart\n\t\t[2] View Cart\n\t\t[3] Delete item from Cart\n\t\t[4] Checkout/Buy \n\n\t\tInput: ";
            cin >> cch;
            system("cls");
        } while (CustomerMenu::actions(cch));
        break;
    default:
        cout << "\n\n\n\t\tPlease Enter a valid input!";
        getch();
        break;
    }
    return true;
}

int main()
{
    cout << "\n\n\n\t\t***Welcome to Inventory Management System!*";
    cout << "\n\n\t\t\t(press any key to continue...)";
    getch();
    system("cls");

    MainMenu M;
    int ch;
    do
    {
        system("cls");
        cout << "\n\n\t\t\tMAIN MENU\n\t==========================================";
        cout << "\n\n\t\t[0] Exit program\n\t\t[1] Dealer Menu\n\t\t[2] Customear Menu\n\n\t\tInput: ";
        cin >> ch;
        system("cls");
    } while (M.actions(ch));

    return 0;
}