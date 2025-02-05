#include <stdio.h>
#include <string.h>
#include <stdbool.h>

//function to check if the password complies with the format
bool checkPasswordCompliance(char password[]) {
    int length = strlen(password);
    //check the length of password
    if (length != 8)    {return false;}
    //check each character
    //check for uppercase letter in the first element of password
    if (!(password[0] >= 'A' && password[0] <= 'Z'))    {return false;}
    //check for number in the second element of password
    if (!(password[1] >= '0' && password[1] <= '9'))    {return false;}
    //check for the lower case letter in the third element of password
    if (!(password[2] >= 'a' && password[2] <= 'z'))    {return false;}
    //check dollar sign in the fourth element of password
    if (password[3] != '$')     {return false;}
    //check for lower case letter in the fifth element of password
    if (!(password[4] >= 'a' && password[4] <= 'z'))    {return false;}
    //check for number in the sixth element of password
    if (!(password[5] >= '0' && password[5] <= '9'))    {return false;}
    //check for number in the seventh element of password
    if (!(password[6] >= '0' && password[6] <= '9'))    {return false;}
    //check for lower case letter in the last element of the password
    if (!(password[7] >= 'a' && password[7] <= 'z'))    {return false;}
    //return true if non of the code above run
    return true;
}

int main() {
    //generate string
    char password[20];

    //print the format
    printf("Password format: 'L5e$e55e'\n");

    //enter the password
    printf("Enter the password: ");
    scanf("%s", password);

    //check the password and give output
    if(checkPasswordCompliance(password)) {
        //if the password is correct, print confirmation
        printf("The password complies with the specified rules.\n");
    }
    else{
        //if the password is incorrect, print the line
        printf("The password does not comply with the specified rules.\n");
    }
    return 0;
}
