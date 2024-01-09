#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_JOURNEYS 10 // maximum amount of journeys allowed to be calculated

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

// Function to calculate the final fare
double calculateFare(double distance, double baseFare, double additionalRate, int isDiscounted, int numPassengers) {
	
    // Initialize variables
    double additionalFare = 0.0;
    double finalFare = 0.0;
    
    // Subtract 4 from the distance
    distance -= 4;
    
    // Calculate if distance is not over 4km
    if (distance == 0) {
    	finalFare = baseFare;
	}
    
    // Calculate additional fare based on the distance
    if (distance > 1) {
        additionalFare = distance * additionalRate;
    }
    
    // Apply discount if applicable
    if (isDiscounted) {
        additionalFare *= 0.8; // 20% discount
    }
    
    // Calculate the final fare
    finalFare = (baseFare + additionalFare) * numPassengers;
    
    return finalFare;
}

// Function to write receipt information to "receipt.txt" file
void writeReceiptToFile(struct FareInfo *journey, int journeyCount, double totalFare, int *numPassengersArray) {
    FILE *file = fopen("receipt.txt", "a"); // Open file in append mode to update the file with new input after every run

	// Check for possible null encounters
    if (file == NULL) {
        printf("Error opening file for writing!\n");
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
    fprintf(file, "Base Fare: %.2lf\n", (*journey).baseFare);
    fprintf(file, "Additional Fare: %.2lf\n", (*journey).finalFare - (*journey).baseFare);
    fprintf(file, "Final Fare Cost: %.2lf\n", (*journey).finalFare);

    // Display total fare in the file if there is more than one journey
    if (journeyCount > 1) {
        fprintf(file, "\nTotal fare cost for all calculations: %.2lf\n", totalFare);
        fprintf(file, "-------------------------------------------\n");
    }

    fclose(file);
}

int main(){

    // Initialize struct variables with fare information for regular and aircon jeepneys
    struct FareInfo regularJeepney = {"", "", "Regular", 13, 1.80, 0.0, 0, 0, 0.0};
    struct FareInfo airconJeepney = {"", "", "Aircon", 15, 1.80, 0.0, 0, 0, 0.0};
                                // Both points are left blank to make way for the user input

    // Variable Declaration
    struct FareInfo *selectedJeepney;
    struct FareInfo journeys[MAX_JOURNEYS]; // struct array to keep track of each journey
    char startPoint[50], endPoint[50], jeepneyType[20], isDiscountedStr[3];
    double distance;
    int isDiscounted, numPassengers;
    double totalFare = 0.0;
    int numPassengersArray[MAX_JOURNEYS]; // Array to store the number of passengers for each journey
    int journeyCount = 0; // Variable to keep track of the number of journeys

    // Print Program Description
    printf("This Program Calculates The Jeepney Fare for Davao Routes.");
    printf("\n---------------------------------------------------------\n");
    
    // Using a loop to get user input
    do {
        // Get user input
        printf("\nEnter the starting point (Point A): ");
        scanf("%49[^\n]", startPoint); // Scans up to 49 characters to include the terminating character

        printf("Enter the ending point (Point B): ");
        scanf(" %[^\n]", endPoint);

        printf("Enter the distance between the two points (in km): ");
        scanf("%lf", &distance);

        printf("Enter the type of jeepney (Regular or Aircon): ");
        scanf("%s", jeepneyType);

        printf("Are you a Student or Senior Citizen or PWD? (Yes or No): ");
        scanf("%3s", isDiscountedStr);

        printf("Enter the Number of Passengers: ");
        scanf("%d", &numPassengers);

        // Convert "Yes" or "No" to 1 or 0 for easier computation
        isDiscounted = (strcmp(isDiscountedStr, "Yes") == 0) ? 1 : 0; // Shorthand if-else

        // Select the fare information based on jeepney type
        selectedJeepney = (strcmp(jeepneyType, "Regular") == 0) ? &regularJeepney : &airconJeepney; // Since the variable is a pointer, the fare information is accessed by reference

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
        numPassengersArray[journeyCount] = numPassengers; // Store the number of passengers for the current journey
        journeys[journeyCount].numPassengers = numPassengersArray[journeyCount];
        journeys[journeyCount].isDiscounted = isDiscounted;

        // Increment the journey count
        journeyCount++;

        // Display the final fare calculation for the current journey
        printf("\nThe fare for Journey %d from %s to %s is %.2lf for %d passenger/s.\n", journeyCount, (*selectedJeepney).startPoint, (*selectedJeepney).endPoint, (*selectedJeepney).finalFare, numPassengers);

        // Write receipt information to file by calling the writeReceiptToFile function
        writeReceiptToFile(selectedJeepney, journeyCount, totalFare, numPassengersArray);

        // Ask if the user wants to calculate another fare
        printf("\nDo you want to calculate another fare? (Yes or No): ");
        scanf("%s", isDiscountedStr);
        while (getchar() != '\n'); // Clear the buffer and ignore the newline

    } while (strcmp(isDiscountedStr, "Yes") == 0 && journeyCount < MAX_JOURNEYS);
	/* Loop terminates once the user chooses not to calculate another fare and journey count is less than the max amount of journeys */
    	
    // Display receipt for the fare(s)
    printf("\n-------------------------------------------");
    for (int i = 0; i < journeyCount; i++) {
        printf("\nReceipt for Journey %d:\n", i + 1);
        printf("From: %s\n", journeys[i].startPoint);
        printf("To: %s\n", journeys[i].endPoint);
        printf("Jeepney Type: %s\n", journeys[i].type_of_Jeep);
        printf("Student/Senior Citizen/PWD Discount: %s\n", (journeys[i].isDiscounted) ? "Yes" : "No");
        printf("Number of Passengers: %d\n", numPassengersArray[i]);
        printf("Distance: %.2lf km\n", journeys[i].distance);
        printf("Base Fare: %.2lf\n", journeys[i].baseFare);
        printf("Additional Fare: %.2lf\n", journeys[i].finalFare - journeys[i].baseFare);
        printf("Final Fare Cost: %.2lf\n", journeys[i].finalFare);
    }
    // Display the total fare if the user calculated more than 1 fare
    if (journeyCount > 1) {
        printf("\nTotal fare cost for all calculations: %.2lf\n", totalFare);
    }
    printf("-------------------------------------------\n");

    return 0;
}
