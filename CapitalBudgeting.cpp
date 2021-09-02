#include <iostream>
#include <iomanip>

using namespace std;

int main() {

    MENU:
    cout << "========== CAPITAL BUDGETING ==========\n" << endl;
    cout << "1. CASH PAYBACK TECHNIQUE" << endl;
    cout << "2. NET PRESENT VALUE (NPV)" << endl;
    cout << "3. INTERNAL RATE OF RETURN (IRR)" << endl;
    cout << "4. ANNUAL RATE OF RETURN (ARR)" << endl;
    cout << "\nSELECT AN OPTION :" << endl;

    cout << fixed << setprecision(0);

    int choice;
    cin >> choice;
    bool validInput = (choice >= 1 && choice <= 4);
    if(!validInput) {
        cout << "YOU MUST SELECT A VALID OPTION!!!\n" << endl;
        goto MENU;
    }

    if(choice == 1) {
        cout << "________________________________________________________\n" << endl;
        cout << "======= CASH PAYBACK TECHNIQUE CALCULATION =======" << endl;
        double capitalCost, netAnnualCashFlow;
        cout << "COST OF CAPITAL INVESTMENT :" << endl;
        cin >> capitalCost;
        cout << "NET ANNUAL CASH FLOW :" << endl;
        cin >> netAnnualCashFlow;
        cout << "CASH PAYBACK PERIOD = " << capitalCost / netAnnualCashFlow << " YEARS" << endl;
        cout << "________________________________________________________" << endl;
    } else if(choice == 2) {
        cout << "________________________________________________________\n" << endl;
        cout << "======= NET PRESENT VALUE (NPV) CALCULATION =======" << endl;
        double pv_netAnnualCashFlow, capitalInvestment;
        cout << "PRESENT VALUE OF NET ANNUAL CASH FLOW :" << endl;
        cin >> pv_netAnnualCashFlow;
        cout << "CAPITAL INVESTMENT :" << endl;
        cin >> capitalInvestment;
        double npv = pv_netAnnualCashFlow - capitalInvestment;
        cout << "NET PRESENT VALUE = " << pv_netAnnualCashFlow - capitalInvestment << endl;
        printf("THE PROPOSAL %s\n", (npv < 0) ? "SHOULD BE REJECTED" : "IS ACCEPTABLE" );
        cout << "________________________________________________________" << endl;
    } else if(choice == 3) {
        cout << "________________________________________________________\n" << endl;
        cout << "======= INTERNAL RATE OF RETURN (IRR) CALCULATION =======" << endl;
        double requiredRateOfReturn, capitalInvestment, netAnnualCashFlow;
        cout << "REQUIRED RATE OF RETURN :" << endl;
        cin >> requiredRateOfReturn;
        cout << "CAPITAL INVESTMENT :" << endl;
        cin >> capitalInvestment;
        cout << "NET ANNUAL CASH FLOW :" << endl;
        cin >> netAnnualCashFlow;
        double irr = capitalInvestment / netAnnualCashFlow;
        cout << "INTERNAL RATE OF RETURN FACTOR = " << irr << "%" << endl;
        printf("THE PROPOSAL %s\n", (irr < requiredRateOfReturn) ? "SHOULD BE REJECTED" : "IS ACCEPTABLE" );
        cout << "________________________________________________________" << endl;
    } else {
        cout << "________________________________________________________\n" << endl;
        cout << "======= ANNUAL RATE OF RETURN (ARR) CALCULATION =======" << endl;
        double requiredRateOfReturn, originalInvestment, endValue, expectedAnnualNetIncome;
        cout << "REQUIRED RATE OF RETURN (IN PERCENTAGE) :" << endl;
        cin >> requiredRateOfReturn;
        cout << "ORIGINAL INVESTMENT :" << endl;
        cin >> originalInvestment;
        cout << "VALUE AT THE END OF USEFUL LIFE :" << endl;
        cin >> endValue;
        double avgInvestment = (originalInvestment + endValue) / 2;
        cout << "AVERAGE INVESTMENT = " << avgInvestment << endl;
        cout << "EXPECTED ANNUAL NET INCOME :" << endl;
        cin >> expectedAnnualNetIncome;
        double arr = (expectedAnnualNetIncome / avgInvestment) * 100;
        cout << "EXPECTED ARR = " << arr << "%" << endl;
        printf("THE PROPOSAL %s\n", (arr < requiredRateOfReturn) ? "SHOULD BE REJECTED" : "IS ACCEPTABLE" );
        cout << "________________________________________________________" << endl;
    }

    return 0;
}
