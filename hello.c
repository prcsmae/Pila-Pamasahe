#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct fareInfo {
	char type_of_Jeep[20];
	double baseFare;
	double additional; 
};
// Function to Calculate for Jeep Fare in Davao for regular and airconditioned jeep as well as the user's discount
float calculateFare( float Users_Distance_From_A_To_B, float baseFare, float additional, float PWD, float SeniorCitizen, float Student) {
    float result = Users_Distance_From_A_To_B - 4.0;
    float final_fare;
	double additional_fare; 
// Calculating final fare base on the result calculation 
    if (result == 0) {
        final_fare = baseFare;
    }  if (result > 1) {
	 additional_fare = result * additional;
        final_fare = baseFare + additional_fare;
    }
	
// Applying discounts if the user is eligible for discount(PWD, Students, Senior Citizen)   
    if (PWD_Discount, SeniorCitizen_Discount, Student_Discount){
         final_fare *= 0.8;
    }

    return final_fare;
}

int main(){
// Store Fare Information
struct fareInfo Davao_Fares[2];

// Fare Information for Regular and Airconditioned Jeep in Davao City 
    strcpy(Davao_Fares[0].type_of_Jeep, "RegularJeep");
    Davao_Fares[0].baseFare = 13.0;
    Davao_Fares[0].additional = 1.80;

    strcpy(Davao_Fares[1].type_of_Jeep, "AirconditionedJeep");
    Davao_Fares[1].baseFare = 15.0;
    Davao_Fares[1].additional = 1.80;

        DifferentType_Of_Jeep_Fare(Davao_Fares, 2); 
    
    return 0;
}
