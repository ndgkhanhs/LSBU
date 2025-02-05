#define STATS_H

//initialize function
double mean(const double arr[], int size);
double median(double arr[], int size);
double kurtosis(const double arr[], int size);
double standardDeviation(const double arr[], int size);

// comparison function for qsort
int compareDoubles(const void *a, const void *b) {

    // compare value of a and b
    // if values are equal, return 0
    // if values a is greater, return 1
    // if values b is greater, return -1
    return (*(double *)a > *(double *)b) - (*(double *)a < *(double *)b);
}

// implementations of functions in stats.h
double mean(const double arr[], int size){

    //initialize sum
    double sum = 0;

    // for loop to calculate the sum
    for (int i = 0; i < size; ++i) {
        sum += arr[i];
    }

    //return mean
    return sum / size;
}

double median(double arr[], int size) {

    // sort arr string
    qsort(arr, size, sizeof(double), compareDoubles);

    // if size is even, find the average of two middle values
    if (size % 2 == 0) {
        //return median
        return (arr[size / 2 - 1] + arr[size / 2]) / 2.0;
    } else {
        // if size is odd
        //return meadian
        return arr[size / 2];
    }
}

double standardDeviation(const double arr[], int size) {
    // calculate meanValue
    double meanValue = mean(arr, size);

    // initialize sum
    double sum = 0;

    // for loop to find difference from mean in arr size
    for (int i = 0; i < size; ++i) {
        sum += pow(arr[i] - meanValue, 2);
    }

    // return standard deviation
    return sqrt(sum / size);
}

double kurtosis(const double arr[], int size) {

    // calculate mean and standard deviation
    double meanValue = mean(arr, size);
    double stdDevValue = standardDeviation(arr, size);

    // initialize variables
    double sum = 0;

    // calculate the score for each element based on mean and standard deviation
    // raise score to the fourth power, adds it to sum
    for (int i = 0; i < size; ++i) {
        double score = (arr[i] - meanValue) / stdDevValue;
        sum += pow(score, 4);
    }
    // return kurtosis
    return sum/size;
}


