Bus Ticket Booking System
Description
The Bus Ticket Booking System is a console-based C application designed to manage bus ticket reservations efficiently. It enables users to view available buses, book tickets, cancel bookings, and check seat statuses in real-time. With a simple login feature, the system ensures secure access for authorized users.

Features
Login System

Secure login for users with predefined credentials.
Prevents unauthorized access with a maximum of three attempts.
Bus List

Displays a list of available buses with unique names.
Ticket Booking

Allows users to book tickets for selected buses.
Validates seat numbers and ensures no double bookings.
Collects passenger details for each booked seat.
Calculates the total cost of tickets.
Seat Status View

Displays current booking status for each bus.
Shows passenger names and their booked seat numbers.
Cancel Booking

Enables users to cancel a reservation by seat number.
Updates the seat status and clears passenger details.
Pricing

Fixed ticket price per seat (₹200).
Refund provided on successful cancellations.
Requirements
Operating System: Windows (due to Sleep() and cls commands).
Compiler: GCC or any C compiler compatible with standard libraries.
Setup Instructions
Clone the repository or download the source code.
Compile the code using a C compiler. Example:
bash

gcc bus_system.c -o bus_system
Run the compiled executable:
bash

./bus_system
Usage
Launch the program.
Log in with valid credentials:
Username: 2447253, Password: tojin
Username: 2447221, Password: jaiby
Username: 2447233, Password: mahalakshmi
Choose from the menu:
View Bus List
Book Tickets
Cancel Booking
Bus Status Board
Exit
Menu Options
1. View Bus List
Displays the names of all available buses.
2. Book Tickets
Choose a bus by entering its number.
Specify the number of tickets to book.
Enter seat numbers and passenger details.
Confirm booking to see the total cost.
3. Cancel Booking
Select a bus and enter the seat number to cancel.
Refund issued for successfully canceled bookings.
4. Bus Status Board
View the list of booked and available seats for a specific bus.
Displays passenger details for booked seats.
5. Exit
Safely exits the system.
Code Structure
Global Variables

Stores bus names, passenger details, seat numbers, and booked seat status.
Functions

login(): Handles user authentication.
showBusList(): Displays the list of buses.
bookTickets(): Facilitates ticket booking.
viewStatus(): Shows the status of booked and available seats.
cancelBooking(): Manages ticket cancellation.
getPassengerDetails(): Collects and stores passenger details.
showStatus(): Displays the status of a specific bus.
Main Function

Handles the program flow and user interaction through a menu-driven interface.
Sample Data
Bus Names:

Rukma Travels
K-Swift
Airavat Express
Yathra Travels
SLS Travels
Murahara Travels
Ticket Price: ₹200 per seat

Maximum Buses: 6

Maximum Passengers: 32 per bus

Advantages
User-friendly interface with clear menu options.
Efficient seat booking and management.
Real-time seat status updates.
Secure login for user authentication.
Limitations
Fixed seat capacity of 32 per bus.
Designed specifically for Windows OS due to the use of system commands.
No database integration; data resets after the program exits.
Future Enhancements
Integrate database for persistent data storage.
Add dynamic pricing and discounts.
Develop a graphical user interface (GUI).
Expand features for online payment and multi-language support.
Author
Tojin Varkey
Feel free to reach out at: tojin.simson@mca.christuniversity.in

License
This project is licensed under the MIT License. Feel free to use and modify the code.