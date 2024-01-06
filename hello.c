#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct fareInfo {
	char startPoint[50];
	char endPoint[50];
	double baseFare;
	double additional;
};
// What if ito i struct prec?
/* struct fareInfo{
	char type_of_Jeep[20];
	double baseFare;
	double additional; */

float calculateFare_for_regularJeep( double baseFare, double additional, int PWD_Discount, int SeniorCitizen_Discount, int Student_Discount) {
    double baseFare = 13.0
    double result = baseFare - 4.0;
    double final_fare;

    if (result == 0) {
        final_fare = baseFare;
    }  if (result > 1) {
        double additional_fare = result * 1.80;
        final_fare = baseFare + additional_fare;
    }
    
    if (PWD_Discount, SeniorCitizen_Discount, Student_Discount){
         final_fare *= 0.8;
    }

    return final_fare;
}

int main(){

    struct FareInfo regularJeepney = {"Point A", "Point B", 13, 1.80}; // initialize variables
    struct FareInfo airconJeepney = {"Point A", "Point B", 15, 1.80}; // initialize variables
	
	// Then ganito natin pag use sa struct para isa nalang function for regular and aircon na jeep
	/* struct fareInfo Davao_Fares[2];

    strcpy(Davao_Fares[0].type_of_Jeep, "RegularJeep");
    Davao_Fares[0].baseFare = 13.0;
    Davao_Fares[0].additional = 1.80;

    strcpy(Davao_Fares[1].type_of_Jeep, "AirconditionedJeep");
    Davao_Fares[1].baseFare = 15.0;
    Davao_Fares[1].additional = 1.80;

        DifferentType_Of_Jeep_Fair(Davao_Fares, 2); */
    
    return 0;
}
