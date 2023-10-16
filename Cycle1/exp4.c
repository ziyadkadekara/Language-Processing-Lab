#include <stdio.h>
#include <stdbool.h>
#include <string.h>


enum State {
    q0,
    q1,
    q2,
    q3
};


bool acceptsString(char* input) {
    enum State currentState = q0;
    int length = strlen(input);

    for (int i = 0; i < length; i++) {
        char symbol = input[i];

        switch (currentState) {
            case q0:
                if (symbol == 'a') {
                    currentState = q1;
               
                }
                else  {
                    currentState = q0;
                }
                break;
            case q1:
                if (symbol == 'b') {
                    currentState = q2;
                } else if (symbol == 'a')  {
                    currentState = q1;
                } else  {
                    currentState = q0;
                }
                break;
            case q2:
                if (symbol == 'c') {
                    currentState = q3;
                } else if (symbol == 'a')  {
                    currentState = q1;
                } else  {
                    currentState = q0;
                }
                break;
            case q3:
                if (symbol == 'a') {
                    currentState = q3;
                } else  {
                    currentState = q3;
                }
                break;
        }
    }

    
    return currentState == q3;
}

int main() {
    char input[100];
    printf("Enter a string: ");
    scanf("%s", input);

    if (acceptsString(input)) {
        printf("Accepted\n");
    } else {
        printf("Rejected\n");
    }

    return 0;
}