/*
 * Author: Navya Nittala
 * TA: Agraj Magotra
 */

#include <stdio.h>
#include <stdlib.h>

#define MONTHS 12

void printSalesReport(double sales[], char *months[]) {
    printf("Monthly sales report for 2022:\n");
    printf("Month\tSales\n");
    for (int i = 0; i < MONTHS; i++) {
        printf("%s\t$%.2f\n", months[i], sales[i]);
    }
    printf("\n");
}

void printSalesSummary(double sales[], char *months[]) {
    double minSales = sales[0];
    double maxSales = sales[0];
    double totalSales = 0;

    for (int i = 0; i < MONTHS; i++) {
        if (sales[i] < minSales) {
            minSales = sales[i];
        }
        if (sales[i] > maxSales) {
            maxSales = sales[i];
        }
        totalSales += sales[i];
    }

    double averageSales = totalSales / MONTHS;

    printf("Sales summary:\n");
    printf("Minimum sales: $%.2f (%s)\n", minSales, months[0]);
    printf("Maximum sales: $%.2f (%s)\n", maxSales, months[MONTHS - 1]);
    printf("Average sales: $%.2f\n\n", averageSales);
}

void printMovingAverage(double sales[], char *months[]) {
    printf("Six-Month Moving Average Report:\n");
    for (int i = 0; i < MONTHS - 6; i++) {
        double sum = 0;
        for (int j = 0; j < 6; j++) {
            sum += sales[i + j];
        }
        double movingAverage = sum / 6;
        printf("%s - %s $%.2f\n", months[i], months[i + 6], movingAverage);
    }
    printf("\n");
}

void printSalesReportDescending(double sales[], char *months[]) {
    printf("Sales Report (Highest to Lowest):\n");
    printf("Month\tSales\n");
    for (int i = MONTHS - 1; i >= 0; i--) {
        printf("%s\t$%.2f\n", months[i], sales[i]);
    }
}

int main() {
    double sales[MONTHS];
    char *months[MONTHS] = {
        "January", "February", "March", "April", "May", "June",
        "July", "August", "September", "October", "November", "December"
    };

    // Read sales data from the input file
    FILE *input = fopen("sales_input.txt", "r");
    if (input == NULL) {
        printf("Error: Cannot open input file.\n");
        return 1;
    }

    for (int i = 0; i < MONTHS; i++) {
        fscanf(input, "%lf", &sales[i]);
    }

    fclose(input);

    printSalesReport(sales, months);
    printSalesSummary(sales, months);
    printMovingAverage(sales, months);
    printSalesReportDescending(sales, months);

    return 0;
}