#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <conio.h>   // for kbhit() and getch()
#include <windows.h> // for Sleep()

int main() {
    double balance;
    printf("Enter starting balance: $");
    scanf("%lf", &balance);
    getchar(); // consume newline

    srand((unsigned int)time(NULL)); // seed RNG

    while (balance > 0) {
        printf("\nBalance: $%.2f\n", balance);
        double bet;
        printf("Enter bet: $");
        scanf("%lf", &bet);
        getchar(); // consume newline

        if (bet <= 0 || bet > balance) {
            printf("Invalid bet\n");
            continue;
        }

        double multiplier = 1.0;
        int cashed_out = 0;

        printf("\nBalloon inflating! Press ENTER anytime to cash out...\n");
        printf("========================================\n");

        const double STEP_SIZE = 0.04;
        const int DELAY_MS = 450; // 0.45 seconds

        while (1) {
            printf("Current: %.2fx\r", multiplier);
            fflush(stdout);
            Sleep(DELAY_MS);

            if (_kbhit()) {
                int key = _getch();
                if (key == 13) { // ENTER key
                    cashed_out = 1;
                    break;
                }
            }

            multiplier += STEP_SIZE;

            // 5% chance to burst
            if ((rand() % 100) < 5) {
                break;
            }
        }

        if (cashed_out) {
            double winnings = bet * multiplier;
            balance += winnings - bet;
            printf("\nCashed out at %.2fx! +$%.2f\n", multiplier, winnings - bet);
        } else {
            balance -= bet;
            printf("\n💥 BURST at %.2fx! Lost $%.2f\n", multiplier, bet);
        }

        if (balance <= 0) {
            printf("\n💰 Game over - balance depleted!\n");
            break;
        }

        char choice;
        printf("\nPlay again? (y/n): ");
        scanf(" %c", &choice);
        getchar(); // consume newline
        if (choice != 'y' && choice != 'Y') break;
    }

    printf("\nFinal balance: $%.2f\n", balance);
    return 0;
}
