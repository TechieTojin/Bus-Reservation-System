#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <windows.h>  // For Sleep function on Windows

// Define constants
#define MAX_BUSES 6
#define MAX_PASSENGERS 32
#define SEAT_NOT_BOOKED 0
#define TICKET_PRICE 200

// Global variables
char busNames[MAX_BUSES][30] = {"Rukma Travels", "K-Swift", "Airavat Express", "Yathra Travels", "SLS Travels", "Murahara Travels"};
char passengerNames[MAX_PASSENGERS][100] = {'\0'};
int seatNumbers[MAX_PASSENGERS] = {0};
int bookedSeats[MAX_BUSES][MAX_PASSENGERS] = {0};  // To track seats for each bus
int selectedBus;

// Function declarations
void login();
void showBusList();
void bookTickets();
void viewStatus();
void cancelBooking();
void getPassengerDetails(int numOfTickets, int busNumber);
void showStatus(int busNumber);

int main() {
    login();
    int choice;
    do {
        system("cls");  // Clear the screen for Windows
        printf("\n\n\n");
        printf("\033[1;32m====================================== WELCOME TO BUS SYSTEM ======================================\033[0m\n\n\n");
        printf("\t\t\t\t\t\033[1;34m[1] View Bus List\033[0m\n");
        printf("\t\t\t\t\t\033[1;34m[2] Book Tickets\033[0m\n");
        printf("\t\t\t\t\t\033[1;34m[3] Cancel Booking\033[0m\n");
        printf("\t\t\t\t\t\033[1;34m[4] Bus Status Board\033[0m\n");
        printf("\t\t\t\t\t\033[1;34m[5] Exit\033[0m\n");
        printf("===============================================================================================================\n\n");
        printf("\t\t\tEnter Your Choice: ");
        scanf("%d", &choice);
        switch (choice) {
            case 1:
                showBusList();
                break;
            case 2:
                bookTickets();
                break;
            case 3:
                cancelBooking();
                break;
            case 4:
                viewStatus();
                break;
            case 5:
                printf("\t----------------------------------------------------------------------------------------------------------\n");
                printf("\t\t\t\t\tThank You For Using This System\n");
                printf("\t----------------------------------------------------------------------------------------------------------\n");
                break;
            default:
                printf("Invalid choice. Please try again.\n");
                Sleep(1000);  // Wait 1 second before continuing
        }
    } while (choice != 5);

    return 0;
}

// Function to display the list of buses
void showBusList() {
    system("cls");
    printf("\n\n\n");
    printf("\033[1;36m=========================================== BUS LIST ============================================\033[0m\n\n\n");
    for (int i = 0; i < MAX_BUSES; i++) {
        printf("\t\t\t\t\t\033[1;33m[%d] %s\033[0m\n", i + 1, busNames[i]);
    }
    printf("\n\nPress any key to continue...");
    getchar();
    getchar();
}

// Function to book tickets
void bookTickets() {
    int numOfTickets;
    system("cls");
    showBusList();
    printf("Enter the Bus number: ");
    scanf("%d", &selectedBus);

    if (selectedBus < 1 || selectedBus > MAX_BUSES) {
        printf("Invalid bus number.\n");
        return;
    }

    printf("Your Bus Number is %d - %s\n", selectedBus, busNames[selectedBus - 1]);
    showStatus(selectedBus);

    printf("Enter number of tickets to book: ");
    scanf("%d", &numOfTickets);

    if (numOfTickets <= 0 || numOfTickets > MAX_PASSENGERS) {
        printf("Invalid number of tickets.\n");
        return;
    }

    getPassengerDetails(numOfTickets, selectedBus);

    printf("Booking successful. Total amount: %d\n", TICKET_PRICE * numOfTickets);
    printf("\n\nPress any key to continue...");
    getchar();
    getchar();
}

// Function to get passenger details
void getPassengerDetails(int numOfTickets, int busNumber) {
    for (int i = 0; i < numOfTickets; i++) {
        int seatNumber;
        printf("Enter seat number (1 to 32): ");
        scanf("%d", &seatNumber);

        if (seatNumber < 1 || seatNumber > 32) {
            printf("Invalid seat number. Please enter a seat number between 1 and 32.\n");
            i--;
            continue;
        }

        // Check if the seat is already booked
        if (bookedSeats[busNumber - 1][seatNumber - 1] != SEAT_NOT_BOOKED) {
            printf("Seat %d is already booked. Choose another seat.\n", seatNumber);
            i--;
            continue;
        }

        printf("Enter passenger name: ");
        scanf(" %[^\n]%*c", passengerNames[seatNumber - 1]);  // Read full line including spaces
        seatNumbers[seatNumber - 1] = seatNumber;
        bookedSeats[busNumber - 1][seatNumber - 1] = seatNumber;  // Mark seat as booked
    }
}

// Function to view the status of booked seats
void viewStatus() {
    system("cls");
    printf("Enter the bus number to view status: ");
    scanf("%d", &selectedBus);

    if (selectedBus < 1 || selectedBus > MAX_BUSES) {
        printf("Invalid bus number.\n");
        return;
    }

    showStatus(selectedBus);
    printf("\n\nPress any key to continue...");
    getchar();
    getchar();
}

// Function to show the status of a specific bus
void showStatus(int busNumber) {
    system("cls");
    printf("\033[1;36m=========================================== BUS STATUS ============================================\033[0m\n\n\n");
    printf("Bus Number: %d - %s\n", busNumber, busNames[busNumber - 1]);

    printf("Seat Details:\n");
    for (int i = 0; i < 32; i++) {
        if (bookedSeats[busNumber - 1][i] != SEAT_NOT_BOOKED) {
            printf("Seat %d: %s\n", i + 1, passengerNames[i]);
        }
    }
}

// Function to cancel a booking
void cancelBooking() {
    int seatNumber;
    system("cls");
    printf("Enter the bus number to cancel booking: ");
    scanf("%d", &selectedBus);

    if (selectedBus < 1 || selectedBus > MAX_BUSES) {
        printf("Invalid bus number.\n");
        return;
    }

    showStatus(selectedBus);

    printf("Enter the seat number to cancel (1 to 32): ");
    scanf("%d", &seatNumber);

    if (seatNumber < 1 || seatNumber > 32) {
        printf("Invalid seat number.\n");
        return;
    }

    if (bookedSeats[selectedBus - 1][seatNumber - 1] == SEAT_NOT_BOOKED) {
        printf("Seat %d is not booked.\n", seatNumber);
        return;
    }

    bookedSeats[selectedBus - 1][seatNumber - 1] = SEAT_NOT_BOOKED;  // Mark seat as unbooked
    strcpy(passengerNames[seatNumber - 1], "\0");  // Clear passenger name

    printf("Booking cancelled and %d Rs refunded.\n", TICKET_PRICE);
    printf("\n\nPress any key to continue...");
    getchar();
    getchar();
}

// Function to handle login
void login() {
    char username[10], password[10];
    int attempt = 0;

    do {
        system("cls");
        printf("\n======================== LOGIN FORM ========================\n");
        printf("Enter username: ");
        scanf("%s", username);
        printf("Enter password: ");
        scanf("%s", password);

        if ((strcmp(username, "2447253") == 0 && strcmp(password, "tojin") == 0) ||
            (strcmp(username, "2447221") == 0 && strcmp(password, "jaiby") == 0) ||
            (strcmp(username, "2447233") == 0 && strcmp(password, "mahalakshmi") == 0)) {
            printf("\nLogin successful. Loading...Enter any key!!!");
            for (int i = 0; i < 3; i++) {
                printf(".");
                Sleep(500);
            }
            break;
        } else {
            printf("\nInvalid username or password. Try again.");
            attempt++;
            getchar();  // Consume newline left in the input buffer
            getchar();
        }
    } while (attempt < 3);

    if (attempt == 3) {
        printf("\nToo many failed attempts. Exiting...");
        exit(1);
    }
}
