#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void printReceipt();

struct fareInfo {
	char startPoint[50];
	char endPoint[50];
	double baseFare;
	double additional;
};

int main(){

    struct fareInfo regularJeepney = {"Point A", "Point B", 13, 1.80}; // initialize variables
    struct fareInfo airconJeepney = {"Point A", "Point B", 15, 1.80}; // initialize variables
    
    return 0;
}

void printReceipt(){

}
