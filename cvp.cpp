#include <iostream>
#include <iomanip>

using namespace std;

double unit_contribution_margin(double, double);
double contribution_margin_ratio(double, double);
void cvp_analysis(double, double, double, double);
void break_even_analysis(double, double, double);
void target_net_income_analysis(double, double, double, double);
void margin_of_safety(double, double, double, double);

int main() {

    MENU:
    cout << "========== CVP ANALYSIS ==========\n" << endl;
    cout << "1. COST-VOLUME-PROFIT (CVP) ANALYSIS" << endl;
    cout << "2. BREAK-EVEN ANALYSIS" << endl;
    cout << "3. TARGET-NET-INCOME ANALYSIS" << endl;
    cout << "4. MARGIN OF SAFETY" << endl;
    cout << "5. CALCULATE ALL" << endl;
    cout << "\nSELECT AN OPTION :" << endl;

    //set precision point according to needs
    cout << fixed << setprecision(0);

    int choice;
    cin >> choice;
    bool validInput = (choice >= 1 && choice <= 5);
    if(!validInput) {
        cout << "YOU MUST SELECT A VALID OPTION!!!\n" << endl;
        goto MENU;
    }

    cout << "======== ENTER THE FOLLOWING VALUES ========" << endl;
    double unitPrice, unitVariableCost, fixedCost, unitSold, targetNetIncome, expectedSale;
    cout << "UNIT SELLING PRICE :" << endl;
    cin >> unitPrice;
    cout << "UNIT VARIABLE COST :" << endl;
    cin >> unitVariableCost;
    cout << "FIXED COST :" << endl;
    cin >> fixedCost;
    cout << "TOTAL UNITS SOLD :" << endl;
    cin >> unitSold;
    cout << "TARGET NET INCOME VALUE :" << endl;
    cin >> targetNetIncome;
    cout << "ACTUAL/EXPECTED SELL VALUE :" << endl;
    cin >> expectedSale;


    switch(choice) {

        case 1:
            cvp_analysis(unitPrice, unitVariableCost, fixedCost, unitSold);
            break;
        case 2:
            break_even_analysis(unitPrice, unitVariableCost, fixedCost);
            break;
        case 3:
            target_net_income_analysis(unitPrice, unitVariableCost, fixedCost, targetNetIncome);
            break;
        case 4:
            margin_of_safety(unitPrice, unitVariableCost, fixedCost, expectedSale);
            break;
        case 5:
            cvp_analysis(unitPrice, unitVariableCost, fixedCost, unitSold);
            break_even_analysis(unitPrice, unitVariableCost, fixedCost);
            target_net_income_analysis(unitPrice, unitVariableCost, fixedCost, targetNetIncome);
            margin_of_safety(unitPrice, unitVariableCost, fixedCost, expectedSale);
        default:
            //do nothing
            break;
    }
    cout << "________________________________________" << endl;

    return 0;
}

double unit_contribution_margin(double unitPrice, double unitVariableCost) {
    return unitPrice - unitVariableCost;
}

double contribution_margin_ratio(double unitPrice, double unitVariableCost) {
    return unit_contribution_margin(unitPrice, unitVariableCost) / unitPrice;
}

void cvp_analysis(double unitPrice, double unitVariableCost, double fixedCost, double unitSold) {
    cout << "________________________________________" << endl;
    cout << "\n===== BASIC CVP CALCULATION =====" << endl;
    cout << "SALES (" << unitSold << " UNITS) = $" << unitPrice * unitSold << endl;
    cout << "VARIABLE COSTS = $" << unitVariableCost * unitSold << endl;
    cout << "-------------------------------" << endl;
    double contributionMargin = unit_contribution_margin(unitPrice, unitVariableCost) * unitSold;
    cout << "CONTRIBUTION MARGIN = $" << contributionMargin << endl;
    cout << "FIXED COSTS = $" << fixedCost << endl;
    cout << "-------------------------------" << endl;
    cout << "NET INCOME = $" << contributionMargin - fixedCost << endl;
    double contributionMarginRatio = contribution_margin_ratio(unitPrice, unitVariableCost) * 100;
    cout << "\nCONTRIBUTION MARGIN RATIO = " << contributionMarginRatio << "%" << endl;
}

void break_even_analysis(double unitPrice, double unitVariableCost, double fixedCost) {
    cout << "________________________________________" << endl;
    cout << "\n===== BREAK-EVEN POINT CALCULATION =====" << endl;
    double bepUnits = fixedCost / unit_contribution_margin(unitPrice, unitVariableCost);
    cout << "BREAK-EVEN POINT IN UNITS = " << bepUnits << " UNITS" << endl;
    double bepSales = fixedCost / contribution_margin_ratio(unitPrice, unitVariableCost);
    cout << "BREAK-EVEN POINT IN DOLLARS = $" << bepSales << endl;
}

void target_net_income_analysis(double unitPrice, double unitVariableCost, double fixedCost, double targetNetIncome) {
    cout << "________________________________________" << endl;
    cout << "\n===== TARGET NET INCOME CALCULATION =====" << endl;
    double bepUnits = (fixedCost + targetNetIncome) / unit_contribution_margin(unitPrice, unitVariableCost);
    cout << "REQUIRED SALES IN UNITS = " << bepUnits << " UNITS" << endl;
    double bepDollar = (fixedCost + targetNetIncome) / contribution_margin_ratio(unitPrice, unitVariableCost);
    cout << "REQUIRED SALES IN DOLLARS = $" << bepDollar << endl;
}

void margin_of_safety(double unitPrice, double unitVariableCost, double fixedCost, double expectedSale) {
    cout << "________________________________________" << endl;
    cout << "\n===== MARGIN OF SAFETY CALCULATION =====" << endl;
    double bepSales = fixedCost / contribution_margin_ratio(unitPrice, unitVariableCost);
    cout << "MARGIN OF SAFETY = $" << expectedSale - bepSales << endl;
}
