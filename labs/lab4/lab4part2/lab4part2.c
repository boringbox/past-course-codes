    #include <stdio.h>
    int main(void){
    int Number, Test, NSevens = 0, Remainder = 0, NPrettyNumber = 0;
        do {
            NSevens = 0;
            Remainder = 0;
            printf("Input an integer (0 to stop): ");
            scanf("%d", &Number);
            Test = Number;
            do {
            Remainder = Test % 10; 
            if (Remainder == 7 || Remainder == -7){
                NSevens ++;
            }
            Test = Test / 10;
            } while (Test != 0);
            if (NSevens >= 3){
                NPrettyNumber ++;
            } 
        } while (Number != 0);
        printf("You entered %d pretty number(s)!\n", NPrettyNumber);
        return 0;
    }