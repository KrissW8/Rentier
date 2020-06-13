#include <iostream>

using namespace std;
string VERSION = "1.0";

class Flat
{
    private:
        double costOfPurchase;
        double sellingPrice;
        double costOfRenovate;
        double totalCosts;
        double rentalCost;
        double investmentPayOffTime;
        double costsOfLoan;
        double loanInterestRate;
        int yearsOfLoan;
        int typeOfApartment;
        int rent;
        int isBoughtWithLoan;
        string typeName;
    public:
        Flat ();
        void getCosts();
        void calculateSellProfit();
        void calculateRentProfit();
        void investmentType();
        void calculateInvestmentProfit();
        void setTypeOfApartment();
        void calculateLoanCosts();
        double getTotalCosts();
};

Flat:: Flat()
{
    costOfPurchase = 0;
    costsOfLoan = 0;
    loanInterestRate = 0.025;
    sellingPrice = 0;
}

void Flat:: setTypeOfApartment()
{
    cout << "\n--------------------------------------------\n";
    cout << "Choose what have you bought!";
    cout << "\n1 - flat";
    cout << "\n2 - house";
    cout << "\nenter: ";
    cin >> typeOfApartment;
    switch(typeOfApartment)
    {
    case 1:
        typeName = "flat";
        break;
    case 2:
        typeName = "house";
        break;
    default:
        cout << "\nOk, so probably that was a flat.";
        typeName = "flat";
        break;
    }
}

void Flat:: getCosts()
{
    cout << "\n--------------------------------------------\n";
    cout << "So you have bought a " << typeName << ".";
    cout << "\nNow enter how much did you pay for this " << typeName << ": ";
    cin >> costOfPurchase;
    cout << "\Enter how much did you spend to renovate this " << typeName << ": ";
    cin >> costOfRenovate;
    totalCosts = costOfPurchase + costOfRenovate;
    cout << "\n--------------------------------------------\n";
    cout << "Did you get loan to buy this " << typeName <<  " and renovate it?";
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
    cout << "\nThe loan will cost you: " << costsOfLoan << "\n";
}

void Flat:: calculateSellProfit()
{
    cout << "So you want to sell a " << typeName << "!";
    cout << "\n" << "\tTotal costs: " << totalCosts+costsOfLoan;
    cout << "\n" << "\tYou sold your " << typeName << " for: ";
    cin >> sellingPrice;
    cout << "\n--------------------------------------------\n";
    cout << "\tYour profit equals to: " << sellingPrice - totalCosts;
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
    cout << "So you want to rent a " << typeName << "!\n";
    cout << "Enter month rental cost: ";
    cin >> rentalCost;
    cout << "\nTotal costs (to buy and renovate): " << totalCosts;
    if(costsOfLoan <= 0)
    {
        cout << "\nYou said, that you didn't need to get a loan!";
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
    cout << "\n1 - Sell your apartment";
    cout << "\n2 - Rent your apartment\n";
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
    setTypeOfApartment();
    getCosts();
    investmentType();
}

double Flat:: getTotalCosts()
{
    return totalCosts;
}

class Controller
{
    private:
        int numberOfInvestments;
        double totalCostsOfInvestments;
        int option;
    public:
        Controller();
        void chooseOption();
        void getNumberOfInvestments();
};

Controller:: Controller()
{
    numberOfInvestments = 0;
}

void Controller:: chooseOption()
{
    cout << "--------------------------------------------\n";
    cout << "Choose what do you want to do?";
    cout << "\n\t1 - calculate profit from investments";
    cout << "\n\t2 - end this program\n\t";
    cin >> option;
    switch(option)
    {
    case 1:
        getNumberOfInvestments();
        break;
    default:
        break;
    }
}

void Controller:: getNumberOfInvestments()
{
    cout << "--------------------------------------------\n";
    cout << "How many investments have you done (max 10): ";
    cin >> numberOfInvestments;
    if(numberOfInvestments > 10)
    {
        numberOfInvestments = 10;
        cout << "Wrong answer, so we will calculate profit from 10 investments!\n";
    }
    else if(numberOfInvestments < 1)
    {
        cout << "Wrong answer, so we will calculate profit from only 1 investment!\n";
        numberOfInvestments = 1;
    }
    Flat apart[10];
    for(int i=0; i<numberOfInvestments; i++)
    {
        apart[i].calculateInvestmentProfit();
        totalCostsOfInvestments += apart[i].getTotalCosts();
    }
    cout << "\n--------------------------------------------\n";
    cout << "Total costs of all your investments are: " << totalCostsOfInvestments;
}

int main()
{
    cout << "Welcome in Rentier v. " << VERSION << ". " << "Here you will find out if your investment were good choice!\n" << endl;
    Controller menu1;
    menu1.chooseOption();
    return 0;
}
