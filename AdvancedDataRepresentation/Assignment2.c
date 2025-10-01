#include <stdint.h>
#include <stdio.h>
#include <math.h>
#include <string.h>
#include <stdlib.h>
#include <ctype.h>

static int testNum = 0;
static int passed = 0;

void oct_to_bin(const char *oct, char *out)
{
    char binary[33];
    int octDigit;
    int pos = 0;

    //This block will take a single digit from the input octal and convert it to a 3 bit long binary string and add it to the binary array
    //#####################################################################################################

    for(int i = 0; i < strlen(oct); i++)
    {
        octDigit = oct[i];
        binary[pos++] = (octDigit >> 2) & 1 ? '1' : '0';
        binary[pos++] = (octDigit >> 1) & 1 ? '1' : '0';
        binary[pos++] = (octDigit >> 0) & 1 ? '1' : '0';
    }

    //#####################################################################################################

    binary[pos++] = '\0';
    printf("Test %i: oct_to_bin(\"%s\") -> Expected: \"%s\", Got: \"%s\" ", testNum, oct, out, binary);
    if(strcmp(out, binary) == 0){printf("[PASS] "); passed++; printf("%i/%i\n", passed, testNum);} //checks whether the converted binary string matches expected output
}
void oct_to_hex(const char *oct, char *out)
{
    char hex[33]; memset(hex, '\0', sizeof(hex));
    char binary[33]; memset(binary, '\0', sizeof(binary)); //creates an array where the binary from the converted octal input will be stored before being added to the filled binary array
    char binaryFilled[33]; memset(binaryFilled, '0', sizeof(binaryFilled)); //creates and fills a char array with 0's
    binaryFilled[32] = '\0'; //adds null terminator to end of char array

    int hexPos = 0;
    int pos = 0;
    int octDigit;

    //if(atoi(oct) == 0){printf("Test %i: oct_to_hex(\"0\") -> Expected: \"0\", Got: \"0\" [PASS]\n", testNum); testNum++; return;} //handles 0 case

    //This block will take a single digit from the input octal and convert it to a 3 bit long binary string and add it to the binary array
    //#####################################################################################################

    for(int i = 0; i < strlen(oct); i++)
    {
        octDigit = oct[i];
        binary[pos++] = (octDigit >> 2) & 1 ? '1' : '0';
        binary[pos++] = (octDigit >> 1) & 1 ? '1' : '0';
        binary[pos++] = (octDigit >> 0) & 1 ? '1' : '0';
    }
    

    //#####################################################################################################

    //This block will take the binary array from the converted octal and append it to the end of the filled binary array
    //#####################################################################################################

    int lastPos = strlen(binaryFilled) - 1;
    for(int i = 0; i < strlen(binary); i++)
    {
        binaryFilled[lastPos--] = binary[strlen(binary) - i - 1] & 1 ? '1' : '0';
        //printf("%s\n", binaryFilled);
    } 

    //#####################################################################################################
    
    //This block will take groups of 4 bits, and convert them into a hexidecimal digit, which is then added to the hex array
    //#####################################################################################################

    pos = 0;
    int nibValue = 0;
    for(int i = 0; i < 8; i++) //iterates through all 8 nibbles of the array and adds values depending on whether or not there is a 1 in that position
    {
        if(binaryFilled[pos++] == '1'){nibValue+=8;}
        if(binaryFilled[pos++] == '1'){nibValue+=4;}
        if(binaryFilled[pos++] == '1'){nibValue+=2;}
        if(binaryFilled[pos++] == '1'){nibValue+=1;}
        if(nibValue != 0) //converts nibValue into a hex digit and adds it to the hex array
        {
            if (nibValue < 10){hex[hexPos++] = '0' + nibValue;}
            else{hex[hexPos++] = 'A' + (nibValue - 10);} 
        }
        else if(atoi(hex) > 0 || i == 7) //0 wont be added to hex array unless it comes after a different number or its the only number in the array
        {
            if (nibValue < 10){hex[hexPos++] = '0' + nibValue;}
            else{hex[hexPos++] = 'A' + (nibValue - 10);} 
        }
        nibValue = 0;
    }
    //#####################################################################################################

    printf("Test %i: oct_to_hex(\"%s\") -> Expected: \"%s\", Got: \"%s\" ", testNum, oct, out, hex);
    if(strcmp(out, hex) == 0){printf("[PASS] "); passed++; printf("%i/%i\n", passed, testNum);} //checks whether the converted hex string matches expected output
}
void hex_to_bin(const char *hex, char *out)
{
    char binary[33];
    int octDigit;
    int pos = 0;

    //This block will take a single digit from the input hex and convert it to a 4 bit long binary string and add it to the binary array
    //#####################################################################################################

    for(int i = 0; i < strlen(hex); i++)
    {
        if(hex[i] >= '0' && hex[i] <= '9'){octDigit = hex[i] - '0';} //converts the hex digit to a decimal digit 
        else{octDigit = toupper(hex[i]) - 'A' + 10;}
        binary[pos++] = (octDigit >> 3) & 1 ? '1' : '0';
        binary[pos++] = (octDigit >> 2) & 1 ? '1' : '0';
        binary[pos++] = (octDigit >> 1) & 1 ? '1' : '0';
        binary[pos++] = (octDigit >> 0) & 1 ? '1' : '0';
    }

    //#####################################################################################################

    printf("Test %i: hex_to_bin(\"%s\") -> Expected: \"%s\", Got: \"%s\" ", testNum, hex, out, binary);
    if(strcmp(out, binary) == 0){printf("[PASS] "); passed++; printf("%i/%i\n", passed, testNum);} //checks whether the converted binary string matches expected output
}
void to_sign_magnitude(const char *in, char *out)
{
    char binary[33]; memset(binary, '\0', sizeof(binary)); //where the binary string will be stored before being added to the binaryFilled array
    char binaryFilled[33]; memset(binaryFilled, '0', sizeof(binaryFilled)); binaryFilled[32] = '\0'; //creates and fills a char array with 0's
    
    int inNum = atoi(in);
    int largestBase = 0;
    int pos = -1;
    int rem;

    //This block will convert a given number into a binary string, and change the magnitude bit to '1' if it is negative
    //#####################################################################################################

    if(inNum > -1 & inNum != 1) //handles positives
    {
        while(pow(2, largestBase) < inNum){largestBase++;};
        while(largestBase > -1)
        {
            rem = inNum % (int) (pow(2, largestBase));
            inNum = inNum / (int) (pow(2, largestBase));
            binary[pos++] = inNum + '0';
            inNum = rem;
            largestBase--;
        }
        binaryFilled[32] = '\0';

            //This block will take the binary array from the converted decimal and append it to the end of the filled binary array
            //#####################################################################################################

            int lastPos = strlen(binaryFilled) - 1;
            for(int i = 0; i < strlen(binary); i++)
            {
                binaryFilled[lastPos--] = binary[strlen(binary) - i - 1] & 1 ? '1' : '0';
            } 

            //#####################################################################################################

        printf("Test %i: to_sign_magnitude(\"%s\") -> Expected: \"%s\", Got: \"%s\" ", testNum, in, out, binaryFilled);
        if(strcmp(out, binaryFilled) == 0){printf("[PASS] "); passed++; printf("%i/%i\n", passed, testNum);} //checks whether the converted binary string matches expected output
    }
    else if(inNum == 1) //handles 1 case
    {
        binaryFilled[31] = '1';
        printf("Test %i: to_sign_magnitude(\"%s\") -> Expected: \"%s\", Got: \"%s\" ", testNum, in, out, binaryFilled);
        if(strcmp(out, binaryFilled) == 0){printf("[PASS] "); passed++; printf("%i/%i\n", passed, testNum);} //checks whether the converted binary string matches expected output
    }
    else if(inNum == -1) //handles -1 case
    {
        binaryFilled[0] = '1';
        binaryFilled[31] = '1';
        printf("Test %i: to_sign_magnitude(\"%s\") -> Expected: \"%s\", Got: \"%s\" ", testNum, in, out, binaryFilled);
        if(strcmp(out, binaryFilled) == 0){printf("[PASS] "); passed++; printf("%i/%i\n", passed, testNum);} //checks whether the conv
    }
    else //handles negatives
    {
        inNum = inNum * -1;
        while(pow(2, largestBase) < inNum){largestBase++;};
        while(largestBase > -1)
        {
            rem = inNum % (int) (pow(2, largestBase));
            inNum = inNum / (int) (pow(2, largestBase));
            binary[pos++] = inNum + '0';
            inNum = rem;
            largestBase--;
        }
        binaryFilled[32] = '\0';

            //This block will take the binary array from the converted decimal and append it to the end of the filled binary array
            //#####################################################################################################

            int lastPos = strlen(binaryFilled) - 1;
            for(int i = 0; i < strlen(binary); i++)
            {
                binaryFilled[lastPos--] = binary[strlen(binary) - i - 1] & 1 ? '1' : '0';
            }
            binaryFilled[0] = '1';
            printf("Test %i: to_sign_magnitude(\"%s\") -> Expected: \"%s\", Got: \"%s\" ", testNum, in, out, binaryFilled);
            if(strcmp(out, binaryFilled) == 0){printf("[PASS] "); passed++; printf("%i/%i\n", passed, testNum);} //checks whether the converted binary string matches expected output

            //#####################################################################################################
    }

    //#####################################################################################################
    

    
}
void to_ones_complement(const char *in, char *out)
{
    char binary[33]; memset(binary, '\0', sizeof(binary)); //where the binary string will be stored before being added to the binaryFilled array
    char binaryFilled[33]; memset(binaryFilled, '0', sizeof(binaryFilled)); binaryFilled[32] = '\0'; //creates and fills a char array with 0's

    int inNum = atoi(in);
    int largestBase = 0;
    int pos = -1;
    int rem;

    //This block will convert a given number to its absolute value binary equivalent
    //#####################################################################################################

    inNum = abs(inNum);
    while(pow(2, largestBase) < inNum){largestBase++;};
    while(largestBase > -1)
        {
            rem = inNum % (int) (pow(2, largestBase));
            inNum = inNum / (int) (pow(2, largestBase));
            binary[pos++] = inNum + '0';
            inNum = rem;
            largestBase--;
        }
    binaryFilled[32] = '\0';

        //This block will take the binary array from the converted decimal and append it to the end of the filled binary array
            //#####################################################################################################

        int lastPos = strlen(binaryFilled) - 1;
        for(int i = 0; i < strlen(binary); i++)
            {
                binaryFilled[lastPos--] = binary[strlen(binary) - i - 1] & 1 ? '1' : '0';
            } 

        //#####################################################################################################
    
    if(atoi(in) == 1 || atoi(in) == -1){binaryFilled[31] = '1';} //handles 1 and -1 case

    //#####################################################################################################

    //This block will flip all of the bits in the binaryFilled array if the input number is negative
    //#####################################################################################################

    if(atoi(in) < 0)
    {
        for(int i = 0; i < strlen(binaryFilled); i++)
        {
            if(binaryFilled[i] == '1'){binaryFilled[i] = '0';}
            else{binaryFilled[i] = '1';}
        }
    }
    printf("Test %i: to_ones_complement(\"%s\") -> Expected: \"%s\", Got: \"%s\" ", testNum, in, out, binaryFilled);
    if(strcmp(out, binaryFilled) == 0){printf("[PASS] "); passed++; printf("%i/%i\n", passed, testNum);} //checks whether the converted binary string matches expected output

    //#####################################################################################################

}
void to_twos_complement(const char *in, char *out)
{
    char binary[33]; memset(binary, '\0', sizeof(binary)); //where the binary string will be stored before being added to the binaryFilled array
    char binaryFilled[33]; memset(binaryFilled, '0', sizeof(binaryFilled)); binaryFilled[32] = '\0'; //creates and fills a char array with 0's

    int inNum = atoi(in);
    int largestBase = 0;
    int pos = -1;
    int rem;

    //This block will convert a given number to its absolute value binary equivalent
    //#####################################################################################################

    inNum = abs(inNum);
    while(pow(2, largestBase) < inNum){largestBase++;};
    while(largestBase > -1)
        {
            rem = inNum % (int) (pow(2, largestBase));
            inNum = inNum / (int) (pow(2, largestBase));
            binary[pos++] = inNum + '0';
            inNum = rem;
            largestBase--;
        }
    binaryFilled[32] = '\0';

        //This block will take the binary array from the converted decimal and append it to the end of the filled binary array
            //#####################################################################################################

        int lastPos = strlen(binaryFilled) - 1;
        for(int i = 0; i < strlen(binary); i++)
            {
                binaryFilled[lastPos--] = binary[strlen(binary) - i - 1] & 1 ? '1' : '0';
            } 

        //#####################################################################################################
    
    if(atoi(in) == 1 || atoi(in) == -1){binaryFilled[31] = '1';} //handles 1 and -1 case

    //#####################################################################################################
    //This block will flip all of the bits in the binaryFilled array if the input number is negative
    //#####################################################################################################

    if(atoi(in) < 0)
    {
        for(int i = 0; i < strlen(binaryFilled); i++)
        {
            if(binaryFilled[i] == '1'){binaryFilled[i] = '0';}
            else{binaryFilled[i] = '1';}
        }
        if(binaryFilled[31] == '1')
        {
            for(int i = 0; i < strlen(binaryFilled); i++)
            {
                if(binaryFilled[strlen(binaryFilled) - i] == '1'){binaryFilled[strlen(binaryFilled) - i] = '0';}
                else{binaryFilled[strlen(binaryFilled - i)];}
            }
        } 
        else{binaryFilled[31] = '1';}
    }
    printf("Test %i: to_twos_complement(\"%s\") -> Expected: \"%s\", Got: \"%s\" ", testNum, in, out, binaryFilled);
    if(strcmp(out, binaryFilled) == 0){printf("[PASS] "); passed++; printf("%i/%i\n", passed, testNum);} //checks whether the converted binary string matches expected output

    //#####################################################################################################

}
int main()
{
    //This block will open a file and handle lines case by case
    //#####################################################################################################

    FILE *file = fopen("a2_test.txt", "r");
    char buffer[256]; //holds a single line read from the file
    char *func; //function parameter from line
    char *numIn; //input number parameter from line
    char *expected; //expected output parameter from line
    const char *delimiter = " ";    

    if (file == NULL){printf("Error: could not open file"); //handle null files
        return 1;}
    while(fgets(buffer, sizeof(buffer), file) != NULL) //while there is a next line, add it to buffer and delimit it into variables
    {
        if(buffer[0] != '#' && strlen(buffer) != 1)
        {
            //printf("%s", buffer);
            func = strtok(buffer, delimiter);
            numIn = strtok(NULL, delimiter);
            expected = strtok(NULL, "\n");
            //printf("function: %s input: %s expected: %s\n", func, numIn, expected);
        }
        if(strcmp(func, "oct_to_bin") == 0){testNum++; oct_to_bin(numIn, expected);} //handles 'oct_to_bin' call
        if(strcmp(func, "oct_to_hex") == 0){testNum++; oct_to_hex(numIn, expected);} //handles 'oct_to_hex' call
        if(strcmp(func, "hex_to_bin") == 0){testNum++; hex_to_bin(numIn, expected);} //handles 'hex_to_bin' call
        if(strcmp(func, "to_sign_magnitude") == 0){testNum++; to_sign_magnitude(numIn, expected);} //handles 'to_sign_magnitude' call
        if(strcmp(func, "to_ones_complement") == 0){testNum++; to_ones_complement(numIn, expected);} //handles 'to_ones_complement' call
        if(strcmp(func, "to_twos_complement") == 0){testNum++; to_twos_complement(numIn, expected);} //handles 'to_twos_complement' call
    }

    //#####################################################################################################
}