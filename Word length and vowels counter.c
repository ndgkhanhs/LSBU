#include <stdio.h>
#include <string.h>
#include <ctype.h>

// function count number of the sports
int countVowels(char str[]) {
    // assign count = 0
    int count=0;
    //generate a for loop from i = 0 to last character in string str
    for (int i=0; str[i]!='\0'; i++) {
        //assign ch = function tolower of string str
        // tolower is a function to make the uppercase letter become lowercase letter
        char ch=tolower(str[i]);
        //if ch is vowel letter, count + 1
        if (ch=='a' || ch=='e' || ch=='i' || ch=='o' || ch=='u') {
            count++;
        }
    }
    return count;
}

// main function
int main() {
    // initialize variables
    char sports[10][50];
    char smallest[50], longest[50];
    int smallestVowels, longestVowels;
    int i;

    // get 10 sports name from user
    printf("Enter 10 sport names:\n");
    //generate for loop from i = 0 to 9
    for (i=0;i<10;i++){
        // ask user to enter the sport name
        printf("Sport %d: ", i + 1);
        fgets(sports[i], sizeof(sports[i]), stdin);
        sports[i][strcspn(sports[i], "\n")] = '\0';
    }

    // copy first name in sport string to smallest/longest string
    strcpy(smallest, sports[0]);
    strcpy(longest, sports[0]);

    // assign number of vowel to variable
    smallestVowels = countVowels(smallest);
    longestVowels = countVowels(longest);

    // for loop to find the smallest/longest sport name and the vowel
    for (i=0; i<10; i++){
        // generate variable to count vowel
        int currentVowels = countVowels(sports[i]);
        // compare the length of the sport i with the smallest
        if (strlen(sports[i])<strlen(smallest)){
            // copy the sport i to smallest
            strcpy(smallest, sports[i]);
            // count and assign number of vowel in sport i to variable smallestVowels
            smallestVowels = currentVowels;
        }
        // compare the length of the sport i with the longest
        if (strlen(sports[i])>strlen(longest)){
            // copy the sport i to longest
            strcpy(longest, sports[i]);
            // count and assign number of vowel in sport i to variable longestVowels
            longestVowels = currentVowels;
        }
    }

    // print the output
    printf("\nThe smallest word is: %s (Vowels: %d)\n", smallest, smallestVowels );
    printf("The largest word is: %s (Vowels: %d)\n", longest, longestVowels );

    // print the tie word if there are two sports with the same number of letter
    printf("\nTied words:\n");
    // for loop from 0 to 9
    for(i=0;i<10;++i){
        // if length of sport i equal to length of smallest and different to smallest
        if(strlen(sports[i])==strlen(smallest) && strcmp(sports[i],smallest)!=0){
            // count and assign number of vowel in sport i to variable smallestVowels
            smallestVowels = countVowels(sports[i]);
            // print output
            printf("Smallest: %s(Vowels: %d)\n", sports[i], smallestVowels);
        }
        // if length of sport i equal to length of longest and different to longest
        if(strlen(sports[i])==strlen(longest) && strcmp(sports[i],longest)!=0){
            // count and assign number of vowel in sport i to variable longestVowels
            longestVowels = countVowels(sports[i]);
            // print output
            printf("Longest: %s(Vowels: %d)\n", sports[i], longestVowels);
        }
    }
    return 0;
}
