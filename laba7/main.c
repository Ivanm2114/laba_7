#include <stdio.h>
#include <malloc.h>

struct node {
    int info;
    struct node *next;
};

struct node *form_stack(FILE *rfile) {
    struct node *lst, *p;
    int a, x;
    lst = NULL;
    while (!feof(rfile)) {
        x = fscanf(rfile, "%d\n", &a);
        p = (struct node *) malloc(sizeof(struct node));
        p->info = a;
        p->next = lst;
        lst = p;
    }
    return lst;
}

void print_stack(struct node *lst) {
    puts("The stack:");
    while (lst) {
        printf("%d ", lst->info);
        lst = lst->next;
    }
}

int input_A1() {
    int res, x, count;
    float temp;
    count = 0;
    while (count < 1) {
        do {
            printf("Введите A1\n");
            x = scanf("%f", &temp);
            while (getchar() != '\n');
        } while (x < 1 || temp <= 0);
        if ((int) temp == temp) {
            res = (int) temp;
            count++;
        }
    }
    return res;

}

void function_2(struct node* lst){

}

int main() {
    struct node *lst;
    int a1;
    FILE *rfile, *wfile;
    rfile = fopen("a.txt", "r");
    lst = form_stack(rfile);
    print_stack(lst);
    a1 = input_A1();


    return 0;
}
