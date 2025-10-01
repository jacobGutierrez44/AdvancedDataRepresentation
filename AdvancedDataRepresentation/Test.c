#include <stdint.h>
#include <stdio.h>
#include <math.h>
#include <string.h>
#include <stdlib.h>
void oct_to_bin(const char *oct, char *out)
{
    int length = strlen(oct); 
    char buffer[33]; //stores the converted binary string
    int pos = 0; //tracks the position of the buffer pointer
    int counter = 0; //tracks which digit is being worked on from the oct char array

    while(length > 0) //converts oct to bin
    {
        int octal_digit = oct[counter];
        buffer[pos++] = (octal_digit >> 2) & 1 ? '1' : '0';
        buffer[pos++] = (octal_digit >> 1) & 1 ? '1' : '0';
        buffer[pos++] = (octal_digit >> 0) & 1 ? '1' : '0';
        length--;
        counter++;
    }
    buffer[pos++] = '\0'; //adds null terminator

    printf("%s", buffer);
}
void oct_to_hex(const char *in, char *out)
{
    char zArr[32];
    memset(zArr, '0', sizeof(zArr)); //initializes a char array of 0's
    zArr[32] = '\0';

    int length = strlen(in); 
    char buffer[33]; //stores the converted binary string
    int pos = 0; //tracks the position of the buffer pointer
    int counter = 0; //tracks which digit is being worked on from the oct char array

    while(length > 0) //converts oct to bin
    {
        int octal_digit = in[counter];
        buffer[pos++] = (octal_digit >> 2) & 1 ? '1' : '0';
        buffer[pos++] = (octal_digit >> 1) & 1 ? '1' : '0';
        buffer[pos++] = (octal_digit >> 0) & 1 ? '1' : '0';
        length--;
        counter++;
    }
    buffer[pos++] = '\0'; //adds null terminator
    printf("%s\n", buffer);

    length = strlen(buffer);
    counter = 0;
    while(length > -1)
    {
        zArr[strlen(zArr) - counter] = buffer[length];
        length--;
        counter++;
    }

    printf("%s\n", zArr);
    printf("%s\n", buffer);
    pos = 0;
    char hex[33];
    int hexPos = -1;
    int decimalValue = 0;
    while(pos < strlen(zArr))
    {
        pos--;
        if (zArr[pos++] == '1') decimalValue += 8;
        if (zArr[pos++] == '1') decimalValue += 4;
        if (zArr[pos++] == '1') decimalValue += 2;
        if (zArr[pos++] == '1') decimalValue += 1;
        //printf("%i", decimalValue);
        printf("%i ", decimalValue);
        if (decimalValue < 10){hex[hexPos++] = '0' + decimalValue;}
        else{hex[hexPos++] = 'A' + (decimalValue - 10);}
        
    decimalValue = 0;
    }
    printf("\n%s\n", zArr);
    printf("%s\n", hex);
}
void to_ones_complement(const char *in, char *out)
{
    
    char buffer[32];
    memset(buffer, '0', sizeof(buffer)); //initializes a char array of 0's
    buffer[32] = '\0';
    int pos = 0;

    int n = atoi(in);
    char temp[65]; //holds the binary array before its added to the buffer array
    double largestBase = 0;
    if(n == 0)
    {
        printf("%s", buffer);
        return;
    }
    while((n - pow(2, largestBase)) > 0){largestBase++;} //finds the largest power that can be subtracted from n
    if(n == 1){largestBase++;} //handles 1 case
    if(n == (int)round(pow(2,largestBase))){largestBase++;} //handles cases where the number is a power of the base
    largestBase--;

    while(largestBase > -1) //performs repeated base conversion by subtraction until the char array 'temp' is the final converted array
    {
        int rem = n % (int)round(pow(2,largestBase));
        //printf("n: %i largest: %i\n", n, (int)round(pow(base,largestBase)));
        n = n / pow(2, largestBase);
        //printf("quotient: %i\n", n);
        //printf("remainder: %i\n", rem);
        if (n < 10){temp[pos++] = '0' + n;}
        else{temp[pos++] = 'A' + (n - 10);}
        largestBase--;
        n = rem;
    }
    temp[pos++] = '\0';
    
    int length = strlen(temp);
    int counter = 0;
    while(length > -1)
    {
        buffer[strlen(buffer) - counter] = temp[length];
        length--;
        counter++;
    }
    length = strlen(buffer);
    while(length > -1)
    {
        if(buffer[length] == '0'){buffer[length] = '1';}
        else if(buffer[length] == '1'){buffer[length] = '0';}
        length--;
    }
    printf("%s", buffer);
    
}

int main()
{
    oct_to_bin("345", "0");
    oct_to_hex("345", "0");
    to_ones_complement("345", "0");
}
