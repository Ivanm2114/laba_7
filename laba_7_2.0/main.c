#include <stdio.h>
#include <malloc.h>
#include <Windows.h>


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
    puts("");
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

int function_2(struct node *lst, struct node *add) {
    struct node *p, *temp;
    int flag = 0;
    while (lst) {
        if (lst->info > 0) {
            flag = 1;
            p = (struct node *) malloc(sizeof(struct node));
            p->info = add->info;
            p->next = lst->next;
            lst->next = p;
            lst = lst->next;
        }
        lst = lst->next;

    }
    return flag;
}

void function_3(struct node *lst) {
    struct node *first_positive = NULL, *comparing_to, *base;
    int temp;
    while (lst && !first_positive) {
        if (lst->info > 0) {
            first_positive = lst->next;
        }
    }
    base = first_positive;
    while (base) {
        comparing_to = base->next;
        while (comparing_to) {
            if (base->info > comparing_to->info) {
                temp = base->info;
                base->info = comparing_to->info;
                comparing_to->info = temp;
            }
            comparing_to = comparing_to->next;
        }
        base = base->next;
    }
}

int main() {
    struct node *lst, add;
    int a1, func_2;
    FILE *rfile, *wfile;
    SetConsoleCP(1251);
    SetConsoleOutputCP(1251);
    rfile = fopen("a.txt", "r");
    lst = form_stack(rfile);
    print_stack(lst);
    a1 = input_A1();
    add.info = a1;
    func_2 = function_2(lst, &add);
    printf("%d\n", func_2);
    if (func_2) {
        print_stack(lst);
        function_3(lst);
        print_stack(lst);
    } else {
        puts("Так как положительных нет задание 2 и 3 не может быть выполнено");
        print_stack(lst);
    }


    return 0;
}
