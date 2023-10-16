#include <stdio.h>
#include <stdbool.h>
#include <string.h>


enum State {
    q0,
    q1,
    q2
};


bool acceptsString(char* input) {
    enum State currentState = q0;
    int length = strlen(input);

    for (int i = 0; i < length; i++) {
        char symbol = input[i];

        switch (currentState) {
            case q0:
                if (symbol == '0') {
                    currentState = q1;
               
                }
                else  {
                    currentState = q0;
                }
                break;
            case q1:
                if (symbol == '0') {
                    currentState = q2;
                } else  {
                    currentState = q0;
                }
                break;
            case q2:
                if (symbol == '0') {
                    currentState = q2;
                } else  {
                    currentState = q0;
                }
                break;
        }
    }

    
    return currentState == q2;
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