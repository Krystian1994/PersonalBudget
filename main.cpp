#include <iostream>

#include "PersonalBudget.h"

using namespace std;

char selectCharacterFromMainMenu()
{
    char choice;

    system("cls");
    cout << "    >>> MENU  GLOWNE <<<" << endl;
    cout << "---------------------------" << endl;
    cout << "1. Rejestracja" << endl;
    cout << "2. Logowanie" << endl;
    cout << "8. Koniec programu" << endl;
    cout << "---------------------------" << endl;
    cout << "Twoj wybor: ";
    choice = AuxiliaryMethods::loadCharacter();

    return choice;
}
char selectCharacterFromUserMenu()
{
    char choice;

    system("cls");
    cout << " >>> MENU UZYTKOWNIKA <<<" << endl;
    cout << "---------------------------" << endl;
    cout << "1. Dodaj dochod" << endl;
    cout << "2. Dodaj wydatek" << endl;
    cout << "3. Bilans z bierzacego miesiaca" << endl;
    cout << "4. Bilans z poprzedniego miesiaca" << endl;
    cout << "5. Bilans z wybranego okresu" << endl;
    cout << "---------------------------" << endl;
    cout << "6. Zmien haslo" << endl;
    cout << "7. Wyloguj sie" << endl;
    cout << "---------------------------" << endl;
    cout << "Twoj wybor: ";
    choice = AuxiliaryMethods::loadCharacter();

    return choice;
}
int main()
{
    PersonalBudget personalBudget("users.xml", "incomes.xml", "expenses.xml");

    char choice;

    while (true) {
        if (!personalBudget.isTheUserLoggedIn()) {
            choice = selectCharacterFromMainMenu();

            switch (choice) {
            case '1':
                personalBudget.registration();
                break;

            case '2':
                personalBudget.login();
                break;

            case '8':
                exit(0);
                break;

            default:
                cout << endl << "Nie ma takiej opcji w menu." << endl << endl;
                system("pause");
                break;
            }
        } else {
            if (personalBudget.isTheUserLoggedIn())

                choice = selectCharacterFromUserMenu();

            switch (choice) {
            case '1':
                personalBudget.addIncome();
                break;

            case '2':
                personalBudget.addExpense();
                break;

            case '3':
                personalBudget.balanceFromCurrentMonth();
                break;

            case '4':
                personalBudget.balanceFromPreviousMonth();
                break;

            case '5':
                personalBudget.balanceFromSelectedTerm();
                break;

            case '6':
                personalBudget.changePassword();
                break;

            case '7':
                personalBudget.logOutUser();
                break;
            }
        }
    }

    return 0;
}
