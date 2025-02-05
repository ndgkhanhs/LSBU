#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include "stats.h"

// Main function to test the statistics library
int main() {
    double britishCoins[] = {1, 2, 5, 10, 20, 50};
    int size = sizeof(britishCoins) / sizeof(britishCoins[0]);

    // Use function to calculate
    double meanValue = mean(britishCoins, size);
    double medianValue = median(britishCoins, size);
    double kurtosisValue = kurtosis(britishCoins, size);
    double stdDevValue = standardDeviation(britishCoins, size);

    // Print value after calculate
    printf("Mean: %.2f\n", meanValue);
    printf("Median: %.2f\n", medianValue);
    printf("Kurtosis: %.2f\n", kurtosisValue);
    printf("Standard Deviation: %.2f\n", stdDevValue);

    return 0;
}
