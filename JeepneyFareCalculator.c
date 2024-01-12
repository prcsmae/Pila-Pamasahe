/* CMSC 18 FINAL PROJECT - GROUP 3: Jomuad, Precious Mae E.	
									Gabano, Jodi C.
									Ceballos, Cristieneil J.
									Serion, Chello G. 		  */
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_JOURNEYS 10 // Create a constant for max journeys

// Declaration of user-defined functions
double calculateFare();
void writeReceiptToFile();

/* Structure to store fare-related information
   Save all the information to be displayed to the structure */
struct FareInfo {
    char startPoint[50];
    char endPoint[50];
    char type_of_Jeep[20];
    double baseFare;
    double additionalRatePerKm;
    double finalFare;
    int numPassengers;
    int isDiscounted;
    double distance;
};

int main() {
    // Initialize struct variables with fare information for regular and aircon jeepneys
    struct FareInfo regularJeepney = {"", "", "Regular", 13, 1.80, 0.0, 0, 0, 0.0};
    struct FareInfo airconJeepney = {"", "", "Aircon", 15, 1.80, 0.0, 0, 0, 0.0};

    // Variable declaration
    struct FareInfo *selectedJeepney;
    struct FareInfo journeys[MAX_JOURNEYS]; // struct array to keep track of each journey
    char startPoint[50], endPoint[50], jeepneyType[20] ="", isDiscountedStr[3];
    double distance;
    int isDiscounted, numPassengers;
    double totalFare = 0.0;
    int numPassengersArray[MAX_JOURNEYS]; // Array to store the number of passengers for each journey
    int journeyCount = 0; // Variable to keep track of the number of journeys

    printf("This Program Calculates The Jeepney Fare for Davao Routes.");
    printf("\n---------------------------------------------------------\n");

    do {
        while(1){
            printf("\nEnter the starting point (Point A): ");
            if (scanf(" %49[^\n]", startPoint) != 1) {
                printf("Invalid input. Please enter a valid starting point.\n");
                while (getchar() != '\n'); // Clear the buffer
                continue;
            }

            printf("Enter the ending point (Point B): ");
            if (scanf(" %49[^\n]", endPoint) != 1) {
                printf("Invalid input. Please enter a valid ending point.\n");
                while (getchar() != '\n'); // Clear the buffer
                continue;
            }

            do{
                printf("Enter the distance between the two points (in km): ");
                if (scanf("%lf", &distance) != 1 || distance < 0) {
                    printf("Invalid input. Please enter a valid distance.\n");
                    while (getchar() != '\n'); // Clear the buffer
                    continue;
                }
                else{
                    break;
                }
            } while(1);
            // Handle input for jeepney type
            do {
                printf("Enter the type of jeepney (Regular or Aircon): ");
                if (scanf(" %19[^\n]", jeepneyType) != 1) {
                    printf("Invalid input. Please enter a valid jeepney type.\n");
                    while (getchar() != '\n'); // Clear the buffer
                    continue;
                }
                
                if (strcmp(strlwr(jeepneyType), "regular") == 0 || strcmp(strlwr(jeepneyType), "aircon") == 0) {
                    // Since the variable is a pointer, the fare information is accessed by reference
                    selectedJeepney = (strcmp(strlwr(jeepneyType), "regular") == 0) ? &regularJeepney : &airconJeepney;
                    break; // Exit the loop if valid input is received
                } else {
                    printf("Invalid input. Please enter either Regular or Aircon.\n");
                }
                
            } while (1);
            // Error handling for input
            do {
                printf("Are you a Student or Senior Citizen or PWD? (Yes or No): ");
                if (scanf(" %3[^\n]", isDiscountedStr) != 1) {
                    printf("Invalid input. Please enter a valid answer.\n");
                    while (getchar() != '\n'); // Clear the buffer
                    continue;
                }

                if (strcmp(strlwr(isDiscountedStr), "yes") == 0 || strcmp(strlwr(isDiscountedStr), "no") == 0) {
                    // Convert "Yes" or "No" to 1 or 0 for easier computation
                    isDiscounted = (strcmp(strlwr(isDiscountedStr), "yes") == 0) ? 1 : 0; // Shorthand if-else
                    break; 
                } else {
                    printf("Invalid input. Please enter either Yes or No.\n");
                }
            } while (1);
            // Error handling for input
            do{
                printf("Enter the Number of Passengers: ");
                if (scanf("%d", &numPassengers) != 1 || numPassengers <= 0) {
                    printf("Invalid input. Please enter a valid number of passengers.\n");
                    while (getchar() != '\n'); // Clear the buffer
                    continue;
                } else{
                    break;
                }
            } while (1);
            break;
        }
        // Set the starting and ending points for the current journey
        strncpy((*selectedJeepney).startPoint, startPoint, sizeof((*selectedJeepney).startPoint) - 1);
        strncpy((*selectedJeepney).endPoint, endPoint, sizeof((*selectedJeepney).endPoint) - 1);

        		/* Specifies the maximum number of characters to copy and makes way for the terminating character */
        (*selectedJeepney).distance = distance; // Store the distance

        // Calculate the final fare by calling on the calculateFare function
        (*selectedJeepney).finalFare = calculateFare(distance, (*selectedJeepney).baseFare, (*selectedJeepney).additionalRatePerKm, isDiscounted, numPassengers);

        // Add the total fare cost if there are more than 1 journeys
        totalFare += (*selectedJeepney).finalFare;

        // Store the journey information for easier tracking and saving to the file
        journeys[journeyCount] = *selectedJeepney;
        numPassengersArray[journeyCount] = numPassengers;
        journeys[journeyCount].numPassengers = numPassengersArray[journeyCount];
        journeys[journeyCount].isDiscounted = isDiscounted;

        journeyCount++; // Increment journey count

         // Display the final fare calculation for the current journey
        printf("\nThe fare for Journey %d from %s to %s is ₱%.2lf for %d passenger/s.\n", journeyCount, (*selectedJeepney).startPoint, (*selectedJeepney).endPoint, (*selectedJeepney).finalFare, numPassengers);

        // Write receipt information to file by calling the writeReceiptToFile function
        writeReceiptToFile(selectedJeepney, journeyCount, totalFare, numPassengersArray);

        // Check if the user has reached the maximum amount of journeys
        if (journeyCount >= MAX_JOURNEYS) {
            printf("\nMaximum Journeys Reached.\n");
            break;
        }

        printf("\nDo you want to calculate another fare? (Yes or No): ");
        scanf(" %s", isDiscountedStr);

    } while (strcmp(strlwr(isDiscountedStr), "yes") == 0);
    /* Loop terminates once the user chooses not to calculate another fare */

    // Display the receipt in terminal
    printf("\nPrinting Receipt...\n");
    printf("\n-------------------------------------------");

    // Loop through the journeys array and display all the information
    for (int i = 0; i < journeyCount; i++) {
        printf("\nReceipt for Journey %d:\n", i + 1);
        printf("From: %s\n", journeys[i].startPoint);
        printf("To: %s\n", journeys[i].endPoint);
        printf("Jeepney Type: %s\n", journeys[i].type_of_Jeep);
        printf("Student/Senior Citizen/PWD Discount: %s\n", (journeys[i].isDiscounted) ? "Yes" : "No");
        printf("Number of Passengers: %d\n", numPassengersArray[i]);
        printf("Distance: %.2lf km\n", journeys[i].distance);
        printf("Base Fare: ₱%.2lf\n", journeys[i].baseFare);
        printf("Additional Fare: ₱%.2lf\n", journeys[i].finalFare - journeys[i].baseFare);
        printf("Final Fare Cost: ₱%.2lf\n", journeys[i].finalFare);
    }
    // Display the total fare if the user calculated more than 1 fare
    if (journeyCount > 1) {
        printf("\nTotal fare cost for all calculations: ₱%.2lf\n", totalFare);
    }
    printf("-------------------------------------------\n");

    return 0;
}

// Function to calculate the final fare
double calculateFare(double distance, double baseFare, double additionalRate, int isDiscounted, int numPassengers) {
    // Initialize variable
    double additionalFare = 0.0;
    double finalFare = 0.0;

    // Subtracts the base distance (4) from the input distance
    distance -= 4;

    // Calculate additional fare based on the distance
    if (distance == 0) {
        finalFare = baseFare;
    } else if (distance >= 1) {
        additionalFare = distance * additionalRate;
    }

    // Apply discount if applicable
    if (isDiscounted) {
        additionalFare *= 0.8;
    }

    // Calculate the final fare
    finalFare = (baseFare + additionalFare) * numPassengers;

    // Error handling
    if (finalFare < 0) {
        printf("Error calculating fare. Please check input values.\n");
        exit(EXIT_FAILURE);
    }

    return finalFare;
}


// Function for writing the receipt to an external text file
void writeReceiptToFile(struct FareInfo *journey, int journeyCount, double totalFare, int *numPassengersArray) {
    FILE *file = fopen("receipt.txt", "a");

    // Checks if file is opened
    if (file == NULL) {
        printf("Error opening file.");
        return;
    }

	// Print the information to the file
    fprintf(file, "\n-------------------------------------------\n");
    fprintf(file, "\nReceipt for Journey %d:\n", journeyCount);
    fprintf(file, "From: %s\n", (*journey).startPoint);
    fprintf(file, "To: %s\n", (*journey).endPoint);
    fprintf(file, "Jeepney Type: %s\n", (*journey).type_of_Jeep);
    fprintf(file, "Student/Senior Citizen/PWD Discount: %s\n", ((*journey).isDiscounted) ? "Yes" : "No");
    fprintf(file, "Distance: %.2lf km\n", (*journey).distance);
    fprintf(file, "Number of Passengers: %d\n", numPassengersArray[journeyCount - 1]); // Retrieve number of passengers from the array
    fprintf(file, "Base Fare: ₱%.2lf\n", (*journey).baseFare);
    fprintf(file, "Additional Fare: ₱%.2lf\n", (*journey).finalFare - (*journey).baseFare);
    fprintf(file, "Final Fare Cost: ₱%.2lf\n", (*journey).finalFare);

    // Display total fare in the file if there is more than one journey
    if (journeyCount > 1) {
        fprintf(file, "\nTotal fare cost for all calculations: ₱%.2lf\n", totalFare);
        fprintf(file, "-------------------------------------------\n");
    }

    fclose(file);
}
