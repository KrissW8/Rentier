#include <iostream>

using namespace std;

class Flat
{
    private:
        double costOfPurchase;
        double sellingPrice;
        double costOfRenovate;
        double totalCosts;
        double rentalCost;
        double investmentPayOffTime;
        int type;
        int rent;
    public:
        Flat ();
        void getCosts();
        void calculateSellProfit();
        void calculateRentProfit();
        void investmentType();
        void calculateInvestmentProfit();
};

Flat:: Flat()
{
    costOfPurchase = 0;
    sellingPrice = 0;
}

void Flat:: getCosts()
{
    cout << "Choose what have you bought!";
    cout << "\n1 - flat";
    cout << "\n2 - house";
    cin >> type;
    switch(type)
    {
    case 1:
        break;
    case 2:
        break;
    }
    cout << "Enter how much did you pay for this flat: "; cin >> costOfPurchase;
    cout << "Enter how much did you spend for renovate this flat: "; cin >> costOfRenovate;
}

void Flat:: calculateSellProfit()
{
    cout << "So you want to sell a flat!";
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

void Flat:: calculateRentProfit()
{
    cout << "So you want to rent a flat!\n";
    cout << "Enter month rental cost: ";
    cin >> rentalCost;
    totalCosts = costOfPurchase + costOfRenovate;
    cout << "\n" << "\tTotal costs: " << totalCosts;
    cout << "your investment will pay off after: ";
    investmentPayOffTime = totalCosts/(rentalCost*12);
    cout << investmentPayOffTime << " years.";
}

void Flat:: investmentType()
{
    cout << "What do you want to do?";
    cout << "\n1 - Sell your flat";
    cout << "\n2 - Rent your flat\n";
    cin >> rent;
    switch(rent)
    {
        case 1: calculateSellProfit();
        break;
        case 2: calculateRentProfit();
        break;
        default:
            cout << "You're so indecisive. I will help you by calculating profit from selling this flat.";
            calculateSellProfit();
    }
}

void Flat:: calculateInvestmentProfit()
{
    getCosts();
    investmentType();
}

int main()
{
    cout << "Welcome in Rentier 0.2. Here you will find out if your investment were good choice!\n" << endl;
    Flat kawalerka1;
    kawalerka1.calculateInvestmentProfit();
    return 0;

}
