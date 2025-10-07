#include <stdio.h>

int main(void) {
    double score;
    printf("Calculate Grade\n");
    printf("Enter your score (negative number to quit): ");

while (scanf("%lf", &score) == 1) {
    if (score < 0) {
        break;
    }

    printf("Your score is: %.2lf\n", score);
    if (score >= 90) {
        printf("Grade is A\n");
    } else if(score >= 80) {
        printf("Grade is B\n");
    } else if(score >= 70) {
        printf("Grade is C\n");
    } else if(score >= 60) {
        printf("Grade is D\n");
    } else {
        printf("Grade is F\n");
    }
    printf("Enter your score (negative number to quit): ");
}
    printf("End of calculation\n");
    return 0;
}