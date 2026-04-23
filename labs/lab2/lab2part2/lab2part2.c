#include <stdio.h>

int main(void){
    int EncryptedCombination, Thousands, Hundreds, Tens, Ones; /*Setups the input and each digits */
    printf("Enter an encrypted 4-digit combination: ");
    scanf("%d", &EncryptedCombination);

    Thousands = EncryptedCombination / 1000 % 10; /*This allows us to obtain the value of each digit since 8021/10 gives us 802 with a remainder of 1 , logic follows for all of them  */
    Hundreds = EncryptedCombination / 100 % 10;   /* but each time each digit is shifted to the right to perform this operation*/
    Tens = EncryptedCombination /10 % 10;
    Ones = EncryptedCombination % 10;

    Thousands = Ones + Thousands; /*This swaps the thousands and ones around */
    Ones = Thousands - Ones;
    Thousands = Thousands - Ones;

    Hundreds = 9 - Hundreds; /*Complimentary number and the digit will have sum of 9 so rearrange equation*/
    Tens = 9 - Tens;

    printf("The real combination is: %d%d%d%d \n", Thousands, Hundreds, Tens, Ones); //Output
    return 0;
}