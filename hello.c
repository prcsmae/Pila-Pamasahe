#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct fareInfo {
	char startPoint[50];
	char endPoint[50];
	double baseFare;
	double additional;
};
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
    
    return 0;
}
