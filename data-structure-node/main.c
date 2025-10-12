#include <stdio.h>
#include <stdlib.h>
#include <conio.h>

typedef struct dataNode {
    int number;
    struct  dataNode *next;
} data;

data *headA = NULL, *prevA = NULL;
data *headB = NULL, *prevB = NULL;
data *headC = NULL, *prevC = NULL;
data *deposit = NULL, *prevDeposit = NULL;

int main() {
    data *tmp;
    int ch, number;

    do {
        system("cls");
        printf("\n\tPlease select an option \n");
        printf("\n 1 Add number set A\n");
        printf(" 2 Add number set B\n");
        printf(" 3 Members of set A\n");
        printf(" 4 Members of set B\n");
        printf(" 5 Search for member set A\n");
        printf(" 6 Search for member set B\n");
        printf(" 7 Delete member from set A\n");
        printf(" 8 Delete member from set B\n");
        printf(" 9 C = A - B\n");
        printf(" 0 Exit\n");
        printf("\n\tEnter choice : ");
        scanf("%d", &ch);

        switch (ch) {
            case 1:
                printf("\n\tEnter number Set A: ");
                scanf("%d", &number);
                break;
            case 2:
                printf("\n\tEnter number Set B: ");
                scanf("%d", &number);
                break;
            case 3:
                if (headA != NULL) {

                } else {

                }
                break;
            case 0:
                break;

            default:
                printf("\n------------------ Please try again ------------------\n");
        }

    } while (ch != 0);

    return 0;
}

void printNode(data *node) {
    printf(" %3d\t", node->number);
}

void printList(data *node) {
    int i = 0;
    while (node != NULL) {
        printNode(node);
        if (++i == 10) {
            printf("\n");
            i = 0;
        }
        node = node->next;
    }
}

data* searchNode(int keyword, data *head) {
    data *ptr = head;
    while (ptr != NULL) {
        if (ptr->number == keyword)
            return ptr;
        ptr = ptr->next;
    }
    return NULL;
}

data* newNode(int number) {
    data *tmp = (data *)malloc(sizeof(data));
    if (tmp == NULL) {
        return NULL;
    }
    tmp->number = number;
    tmp->next = NULL;
    return tmp;
}