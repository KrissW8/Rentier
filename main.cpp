#include <iostream>

using namespace std;
string VERSION = "0.5";

class Flat
{
    private:
        double costOfPurchase;
        double sellingPrice;
        double costOfRenovate;
        double totalCosts;
        double rentalCost;
        double investmentPayOffTime;
        double costsOfLoan = 0;
        double loanInterestRate = 0.025;
        int yearsOfLoan;
        int typeOfApartment;
        int rent;
        int isBoughtWithLoan;
    public:
        Flat ();
        void getCosts();
        void calculateSellProfit();
        void calculateRentProfit();
        void investmentType();
        void calculateInvestmentProfit();
        void setTypeOfApartment();
        void calculateLoanCosts();
};

Flat:: Flat()
{
    costOfPurchase = 0;
    sellingPrice = 0;
}

void Flat:: setTypeOfApartment()
{
    cout << "Choose what have you bought!";
    cout << "\n1 - flat";
    cout << "\n2 - house";
    cin >> typeOfApartment;
    switch(typeOfApartment)
    {
    case 1:
        break;
    case 2:
        break;
    }
}

void Flat:: getCosts()
{
    cout << "So you have bought a flat.";
    cout << "\nNow enter how much did you pay for this flat: "; cin >> costOfPurchase;
    cout << "\Enter how much did you spend to renovate this flat: "; cin >> costOfRenovate;
    totalCosts = costOfPurchase + costOfRenovate;
    cout << "Did you get loan to buy this flat and renovate it?";
    cout << "\n1 - yes";
    cout << "\n2 - no\n";
    cin >> isBoughtWithLoan;
    switch(isBoughtWithLoan)
    {
    case 1:
        calculateLoanCosts();
        break;
    case 2:
        break;
    default: break;
    }
}

void Flat:: calculateLoanCosts()
{
    cout << "\nEnter how long is your loan (in years): ";
    cin >> yearsOfLoan;
    costsOfLoan = (loanInterestRate)*totalCosts*yearsOfLoan;
    cout << "\nThe loan will cost you: " << costsOfLoan;
}

void Flat:: calculateSellProfit()
{
    cout << "So you want to sell a flat!";
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
    cout << "\nTotal costs (to buy and renovate): " << totalCosts;
    if(costsOfLoan <= 0)
    {
        cout << "\nYou didn't need to get a loan!";
    }
    else
    {
        cout << "\nCosts of loan: " << costsOfLoan;
    }
    cout << "\nYour investment will pay off after: ";
    investmentPayOffTime = (totalCosts+costsOfLoan)/(rentalCost*12);
    cout << investmentPayOffTime << " years,";
    cout << "\nwhich equals to: " << investmentPayOffTime*365 << " days";
    cout << "\nwhich equals to: " << investmentPayOffTime*365*24 << " hours.";
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
    cout << "Welcome in Rentier v. " << VERSION << ". " << "Here you will find out if your investment were good choice!\n" << endl;
    Flat kawalerka1;
    kawalerka1.calculateInvestmentProfit();
    return 0;

}
