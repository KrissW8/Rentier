#include <iostream>

using namespace std;

class Flat
{
    private:
        double costOfPurchase;
        double sellingPrice;
        double costOfRenovate;
        double totalCosts;
    public:
        Flat ();
        void getCosts();
        void calculateProfit();
};

Flat:: Flat()
{
    costOfPurchase = 0;
    sellingPrice = 0;
}

void Flat:: getCosts()
{
    cout << "Enter how much did you pay for this flat: "; cin >> costOfPurchase;
    cout << "Enter how much did you spend for renovate this flat: "; cin >> costOfRenovate;
    cout << "Enter for how much you sold that flat: "; cin >> sellingPrice;
}

void Flat:: calculateProfit()
{
    totalCosts = costOfPurchase + costOfRenovate;
    cout << "\n" << "\tTotal costs: " << totalCosts;
    cout << "\n" << "\tYou sold your flat for: " << sellingPrice;
    if(sellingPrice > totalCosts)
    {
        cout << "\n\tNot bad - you make some profit.";
    }
    else if (sellingPrice < totalCosts)
    {
        cout << "\n\tYou should better stop investing.";
    }
    else
    {
        cout << "\n\tAt least you only lost your time...";
    }
}

int main()
{
    cout << "Welcome in Rentier 0.1. Here you will find out if your investment were good choice!\n" << endl;
    Flat kawalerka1;
    kawalerka1.getCosts();
    kawalerka1.calculateProfit();
    return 0;

}
