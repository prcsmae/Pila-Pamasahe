#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Structure to store fare-related information
struct FareInfo {
    char startPoint[50];
    char endPoint[50];
    char type_of_Jeep[20];
    double baseFare;
    double additionalRatePerKm;
};

// Function to calculate the final fare
double calculateFare(double distance, double baseFare, double additionalRate, int isDiscounted) {
	
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
    finalFare = baseFare + additionalFare;
    
    return finalFare;
}

int main(){

    // Initialize struct variables with fare information for regular and aircon jeepneys
    struct FareInfo regularJeepney = {"Point A", "Point B", "Regular", 13, 1.80};
    struct FareInfo airconJeepney = {"Point A", "Point B", "Aircon", 15, 1.80};
    
    // Variable Declaration
    char startPoint[50], endPoint[50], jeepneyType[20], isDiscountedStr[3];
    double distance;
    int isDiscounted;
    struct FareInfo *selectedJeepney;
    double finalFare;

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

        // Convert "Yes" or "No" to 1 or 0 for easier computation
        isDiscounted = (strcmp(isDiscountedStr, "Yes") == 0) ? 1 : 0; // Shorthand if-else

        // Select the fare information based on jeepney type
        selectedJeepney = (strcmp(jeepneyType, "Regular") == 0) ? &regularJeepney : &airconJeepney;

        // Calculate the final fare
    	finalFare = calculateFare(distance, (*selectedJeepney).baseFare, (*selectedJeepney).additionalRatePerKm, isDiscounted);

   		// Display the final fare calculation
    	printf("\nThe fare to travel from %s to %s is %.2lf\n", startPoint, endPoint, finalFare);
    	
    	// Ask if the user wants to calculate another fare
    	printf("\nDo you want to calculate another fare? (Yes or No): ");
    	scanf("%s", isDiscountedStr);
    	while (getchar() != '\n'); // Ensures that the program does not read a newline

        /* FILE CODES HERE */
    	
    	// Display the receipt for the last fare calculated
    	printf("-------------------------------------------\n");
    	printf("Receipt:\n");
    	printf("From: %s\n", startPoint);
    	printf("To: %s\n", endPoint);
    	printf("Jeepney Type: %s\n", jeepneyType);
    	printf("Student/Senior Citizen/PWD Disount: %s\n", (isDiscountedStr) ? "Yes" : "No");
    	printf("Distance: %.2lf km\n", distance);
    	printf("Base Fare: %.2lf\n", (*selectedJeepney).baseFare);
    	printf("Additional Fare: %.2lf\n", finalFare - (*selectedJeepney).baseFare);
    	printf("Final Fare: %.2lf\n", finalFare);
    	printf("-------------------------------------------\n");
    
    } while (strcmp(isDiscountedStr, "Yes") == 0); // Loop only terminates when the user enters "No" when they are asked to calculate another fare

    return 0;
}
