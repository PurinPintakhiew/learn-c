#include <stdio.h>
#include <stdlib.h>
#include <conio.h>

typedef struct datanode {
    int number;
    struct datanode *next;
} data;

data *headA = NULL, *endA = NULL;
data *headB = NULL, *endB = NULL;
data *headC = NULL, *endC = NULL;
data *deposit = NULL, *endDeposit = NULL;

data* newNode(int n);
void insertNode(data* ptr, data **head, data **end);
void printNode(data *ptr);
void printList(data *ptr);
data* searchNode(int keyword, data *head);
void deleteNode(data *ptr, data **head, data **end);
void unionNode(data* headA, data* headB);

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
                printf("Enter Number Set A : ");
                scanf("%d", &number);
                tmp = newNode(number);
                insertNode(tmp, &headA, &endA);
                insertNode(newNode(number), &headC, &endC);
                break;

            case 2:
                printf("Enter Number Set B : ");
                scanf("%d", &number);
                tmp = newNode(number);
                insertNode(tmp, &headB, &endB);
                insertNode(newNode(number), &headC, &endC);
                getch();
                break;

            case 3:
                if (headA != NULL)
                    printList(headA);
                else
                    printf("\n { }\n");
                printf("\n--------------Press any key--------------");
                getch();
                break;

            case 4:
                if (headB != NULL)
                    printList(headB);
                else
                    printf("\n { }\n");
                printf("\n--------------Press any key--------------");
                getch();
                break;

            case 5:
                printf("Enter Keyword Set A : ");
                scanf("%d", &number);
                tmp = searchNode(number, headA);
                if (tmp == NULL)
                    printf("Search %d not found\n", number);
                else
                    printNode(tmp);
                printf("\n--------------Press any key--------------");
                getch();
                break;

            case 6:
                printf("Enter Keyword Set B : ");
                scanf("%d", &number);
                tmp = searchNode(number, headB);
                if (tmp == NULL)
                    printf("Search %d not found\n", number);
                else
                    printNode(tmp);
                printf("\n--------------Press any key--------------");
                getch();
                break;

            case 7:
                printf("Enter keyword in set A : ");
                scanf("%d", &number);
                tmp = searchNode(number, headA);
                if (tmp == NULL)
                    printf("Search %d not found\n", number);
                else {
                    deleteNode(tmp, &headA, &endA);
                    printf("\n  Delete complete\n");
                }
                printf("\n--------------Press any key--------------");
                getch();
                break;

            case 8:
                printf("Enter keyword in set B : ");
                scanf("%d", &number);
                tmp = searchNode(number, headB);
                if (tmp == NULL)
                    printf("Search %d not found\n", number);
                else {
                    deleteNode(tmp, &headB, &endB);
                    printf("\n  Delete complete\n");
                }
                printf("\n--------------Press any key--------------");
                getch();
                break;

            case 9:
                if (headC != NULL)
                    printList(headC);
                else
                    printf("{ }");
                printf("\n--------------Press any key--------------");
                getch();

                headC = NULL;
                endC = NULL;
                deposit = NULL;
                endDeposit = NULL;
                break;

            case 0:
                break;

            default:
                printf("\n------------------Please try again----------------------");
                getch();
        }
    } while (ch != 0);

    return 0;
}

data* newNode(int number) {
    data *tmp = (data*)malloc(sizeof(data));
    if (tmp == NULL)
        return NULL;
    tmp->number = number;
    tmp->next = NULL;
    return tmp;
}

void insertNode(data* ptr, data **head, data **end) {
    data *start, *prev;

    if (*head == NULL) {
        *head = ptr;
        *end = ptr;
        return;
    }

    start = *head;
    while (start != NULL) {
        if (start->number == ptr->number) {
            free(ptr);
            return;
        }
        start = start->next;
    }

    start = *head;
    while (start != NULL && start->number < ptr->number)
        start = start->next;

    if (start == *head) {
        ptr->next = *head;
        *head = ptr;
    } else {
        prev = *head;
        while (prev->next != start)
            prev = prev->next;
        prev->next = ptr;
        ptr->next = start;
        if (*end == prev)
            *end = ptr;
    }
}

void printNode(data *ptr) {
    printf(" %3d\t", ptr->number);
}

void printList(data *ptr) {
    int i = 0;
    while (ptr != NULL) {
        printNode(ptr);
        if (++i == 10) {
            printf("\n");
            i = 0;
        }
        ptr = ptr->next;
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

void deleteNode(data *ptr, data **head, data **end) {
    data *start = *head, *prev = NULL;

    while (start != NULL && start != ptr) {
        prev = start;
        start = start->next;
    }

    if (start == NULL)
        return;

    if (prev == NULL)
        *head = start->next;
    else
        prev->next = start->next;

    if (*end == start)
        *end = prev;

    free(start);
}
