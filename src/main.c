#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>
#include "hello-world.h"

int main(int argc, const char *argv)
{
    hello_world();

    float valueOne = 4.5;
    float valueTwo = 3;
    char operator = '^';
    float answer;

    // printf("Enter calculation:\n\n");
    // scanf("%f %c %f", &valueOne, &operator, & valueTwo);

    switch (operator)
    {
    case '/':
        answer = valueOne / valueTwo;
        break;
    case '*':
        answer = valueOne * valueTwo;
        break;
    case '+':
        answer = valueOne + valueTwo;
        break;
    case '-':
        answer = valueOne - valueTwo;
        break;
    case '^':
        answer = pow(valueOne, valueTwo);
        break;
    // case ' ':
    //     answer = sqrt(valueTwo);
    //     break;
    default:
        goto fail;
    }
    printf("%.9g%c%.9g =  %.6g\n\n", valueOne, operator, valueTwo, answer);
    goto exit;
fail:
    printf("Fail.\n");
exit:
    return 0;
}