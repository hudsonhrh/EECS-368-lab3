//hudson headley 9/15/2021
#include <stdio.h>
#include <stdlib.h>

// print month name based on month number
void printMonthN(int monthN){
	if (monthN == 0){
		printf("  January      ");
	}
	else if (monthN == 1){
		printf("  February    ");
	}
	else if (monthN == 2){
		printf("  March        ");
	}
	else if (monthN == 3){
		printf("  April        ");
	}
	else if (monthN == 4){
		printf("  May          ");
	}
	else if (monthN == 5){
		printf("  June         ");
	}
	else if (monthN == 6){
		printf("  July         ");
	}
	else if (monthN == 7){
		printf("  August       ");
	}
	else if (monthN == 8){
		printf("  September    ");
	}
	else if (monthN == 9){
		printf("  October      ");
	}
	else if (monthN == 10){
		printf("  November     ");
	}
	else if (monthN == 11){
		printf("  December     ");
	}
}

void displayMonthlySalesReport(float monthData[], int lengthL){
	
	printf("\nMonthly sales report for 2022:\n\n");
	printf("  Month        Sales\n");
	
	for(int i=0; i < lengthL; i++){
		
		printMonthN(i);
		printf("$");
		printf("%.2f\n", monthData[i]); //this .2 rounds off the value after 2 decimals
	}
	
}



void calculateMinimumSales(float monthData[], int lengthL){
	int minimumIndex = 0;
	
	
	for(int i=0; i<lengthL;i++){
		if(monthData[i] < monthData[minimumIndex]){
			minimumIndex = i;
		}
	}
	printf("  Minimum sales: %.2f (", monthData[minimumIndex]);
	printMonthN(minimumIndex);
	printf(")\n");

}
void calculateMaximumSales(float monthData[], int lengthL){

	int maximumIndex = 0;
		
	for(int i=0; i<lengthL;i++){
		if(monthData[i] > monthData[maximumIndex]){
			maximumIndex = i;
		}
	}
	printf("  Maximum sales: %.2f (", monthData[maximumIndex]);
	printMonthN(maximumIndex);
	printf(")\n");

}

void calculateAverageSales(float monthData[], int lengthL){
	float sum = 0;
	
	for(int i=0; i<lengthL;i++){
		sum += monthData[i];
	}
	printf("  Average sales: %.2f ", sum/lengthL);

}

void displaySalesSummary(float monthData[]){
	printf("\nSales summary:\n\n");
	
	calculateMinimumSales(monthData, 12);
	calculateMaximumSales(monthData, 12);
	calculateAverageSales(monthData, 12);
	printf("\n");
}


void displayMAReport(float monthData[]){
	
	printf("\n Six-Month moving average report: \n\n");
	
	for (int i = 0; i < 7; i++){
			if (i == 0){
				printf("  January-June    ");
			}
			else if (i == 1){
				printf("  February-July   ");
			}
			else if (i == 2){
				printf("  March-August    ");
			}
			else if (i == 3){
				printf("  April-September ");
			}
			else if (i == 4){
				printf("  May-October     ");
			}
			else if (i == 5){
				printf("  June-November   ");
			}
			else if (i == 6){
				printf("  July-December   ");
			}
			float miniTotal = 0;
			for (int j = i; j < i + 6; j++){
				miniTotal += monthData[j];
			}
			printf("%.2f\n", miniTotal / 6);
		}

}

void displayOrderSalesReport(float monthData[], int listLength){

	printf("\nSales report:\n\n");
	
	printf("  Month        Sales\n");
		float max = 0;
		int useMax = 0;
		int maxmonth = -1;
		float maxAm = 0;
		int sort = 1;
		
		while (sort){
			maxAm = 0;
			maxmonth = -1;

			for (int i = 0; i < listLength; i ++){
				if (!useMax || monthData[i] < max){
					//check if this is valid
					if (maxmonth == -1 || monthData[i] > maxAm){
						maxAm = monthData[i];
						maxmonth = i;
					}
				}
			}
			if (maxmonth == -1){
				sort = 0;
				break;
			}
			
			printMonthN(maxmonth);
			printf("%.2f\n", maxAm);
			
			useMax = 1;
			max = maxAm;
		}
	}

int main(){

	FILE* input;
	
	input = fopen("input.txt", "r");
	float salesData[] = {0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0};
	const char monthArray[] = {"January", "February", "March", "April", "May", "June", "July", "August", "September", "October", "November", "December"};

	
	for (int i = 0; i < 12; i++){
		fscanf(input, "%f", &salesData[i]);
	}


	//runs function displaying everything in order
	displayMonthlySalesReport(salesData, 12);
	displaySalesSummary(salesData);
	displayMAReport(salesData);
	displayOrderSalesReport(salesData, 12);
	
	fclose(input);

	return 0;
	
}