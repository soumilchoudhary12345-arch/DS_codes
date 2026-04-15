#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// 🔹 Node structure
typedef struct node {
    int id;
    char name[50];
    float basic, hra, da, deduction, net;
    int leaves;
    struct node *next;
} node;

// 🔹 Linked List structure
typedef struct LL {
    node *start;
} LL;

// 🔹 Count nodes
int count(LL *l) {
    node *p = l->start;
    int c = 0;

    while (p != NULL) {
        c++;
        p = p->next;
    }
    return c;
}

// 🔹 Create node
node* createNode(int id, char name[], float basic, int leaves) {
    node *newrec = (node*)malloc(sizeof(node));

    newrec->id = id;
    strcpy(newrec->name, name);
    newrec->basic = basic;
    newrec->leaves = leaves;

    // Salary calculation
    newrec->hra = 0.20 * basic;
    newrec->da  = 0.10 * basic;

    float perDay = basic / 30;
    newrec->deduction = perDay * leaves;

    newrec->net = basic + newrec->hra + newrec->da - newrec->deduction;

    newrec->next = NULL;

    return newrec;
}

// 🔹 Insert at end
void insertend(LL *l) {
    int id, leaves;
    char name[50];
    float basic;

    printf("Enter ID: ");
    scanf("%d", &id);
    printf("Enter Name: ");
    scanf(" %[^\n]", name);
    printf("Enter Basic Salary: ");
    scanf("%f", &basic);
    printf("Enter Leaves: ");
    scanf("%d", &leaves);

    node *newrec = createNode(id, name, basic, leaves);

    if (l->start == NULL) {
        l->start = newrec;
    } else {
        node *p = l->start;
        while (p->next != NULL)
            p = p->next;

        p->next = newrec;
    }

    printf("Employee Added!\n");
}

// 🔹 Display
void display(LL *l) {
    node *p;

    if (l->start == NULL) {
        printf("\nList is empty...\n");
    } else {
        p = l->start;
        while (p != NULL) {
            printf("\nID: %d\nName: %s\nBasic: %.2f\nLeaves: %d\nHRA: %.2f\nDA: %.2f\nDeduction: %.2f\nNet: %.2f\n",
                   p->id, p->name, p->basic, p->leaves,
                   p->hra, p->da, p->deduction, p->net);
            p = p->next;
        }
    }
}

// 🔹 Search
void search(LL *l) {
    int id;
    printf("Enter ID to search: ");
    scanf("%d", &id);

    node *p = l->start;

    while (p != NULL) {
        if (p->id == id) {
            printf("Found: %s | Net Salary: %.2f\n", p->name, p->net);
            return;
        }
        p = p->next;
    }

    printf("Not Found\n");
}

// 🔹 Update
void update(LL *l) {
    int id;
    printf("Enter ID to update: ");
    scanf("%d", &id);

    node *p = l->start;

    while (p != NULL) {
        if (p->id == id) {
            printf("Enter new name: ");
            scanf(" %[^\n]", p->name);
            printf("Enter new basic: ");
            scanf("%f", &p->basic);
            printf("Enter leaves: ");
            scanf("%d", &p->leaves);

            // Recalculate
            p->hra = 0.20 * p->basic;
            p->da  = 0.10 * p->basic;

            float perDay = p->basic / 30;
            p->deduction = perDay * p->leaves;

            p->net = p->basic + p->hra + p->da - p->deduction;

            printf("Updated!\n");
            return;
        }
        p = p->next;
    }

    printf("Not Found\n");
}

// 🔹 Delete by ID
void deleteEmp(LL *l) {
    int id;
    printf("Enter ID to delete: ");
    scanf("%d", &id);

    node *p = l->start, *q = NULL;

    if (p != NULL && p->id == id) {
        l->start = p->next;
        free(p);
        printf("Deleted!\n");
        return;
    }

    while (p != NULL && p->id != id) {
        q = p;
        p = p->next;
    }

    if (p == NULL) {
        printf("Not Found\n");
        return;
    }

    q->next = p->next;
    free(p);
    printf("Deleted!\n");
}

// 🔹 Main
int main() {
    LL l;
    l.start = NULL;

    int choice;

    while (1) {
        printf("\n--- Payroll System ---\n");
        printf("1. Add Employee\n");
        printf("2. Display\n");
        printf("3. Search\n");
        printf("4. Update\n");
        printf("5. Delete\n");
        printf("6. Count\n");
        printf("7. Exit\n");

        printf("Enter choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1: insertend(&l); break;
            case 2: display(&l); break;
            case 3: search(&l); break;
            case 4: update(&l); break;
            case 5: deleteEmp(&l); break;
            case 6: printf("Total: %d\n", count(&l)); break;
            case 7: exit(0);
            default: printf("Invalid choice\n");
        }
    }

    return 0;
}