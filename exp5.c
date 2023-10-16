
#include <stdio.h>
#include <stdbool.h>
#include <string.h>
#include <ctype.h>


enum State {
    q0,
    q1,
    qo
};


bool acceptsString(char* input) {
    enum State currentState = q0;
    int length = strlen(input);

    for (int i = 0; i < length; i++) {
        char symbol = input[i];

        switch (currentState) {
            case q0:
                if (isalpha(symbol) || symbol == '_' ) {
                    currentState = q1;
               
                }
                else  {
                    currentState = qo;
                }
                break;
            case q1:
                if (isdigit(symbol) || isalpha(symbol) || symbol == '_') {
                    currentState = q1;
                } else  {
                    currentState = qo;
                }
                break;
        }
    }

    
    return currentState == q1;
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
