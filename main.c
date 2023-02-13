#include <stdio.h>
#include <stdlib.h>
#include <Windows.h>
#include <stddef.h>
#define lmax 200

struct izdat{
    int year;
    char name[lmax];
    char city[lmax];
};

struct book{
    int pages;
    float price;
    char author[lmax];
    char title[lmax];
    struct izdat izdatelstvo;
};


int input_natural_int()
{
    int res,x,count;
    float temp;
    count=0;
    while (count<1)
    {
        do
        {
            printf("Введите натуральнео число\n");
            x=scanf("%f",&temp);
            while (getchar()!='\n');
        }
        while(x<1||temp<=0);
        if((int)temp==temp)
        {
            res=(int)temp;
            count++;
        }
    }
    return res;

}

float input_natural_float()
{
    int x;
    float res;
    do
    {
        printf("Введите положительное число:\n");
        x=scanf("%f",&res);
        while (getchar()!='\n');
    }
    while(x<1||res<=0);
    return res;

}



void input_book(struct book *b){
    puts("Название :\t\t");
    gets(b->title);
    puts("Цена:\t\t");
    b->price=input_natural_float();
    puts("Автор :\t\t");
    gets(b->author);
    puts("Кол-во страниц :\t\t");
    b->pages = input_natural_int();
    puts("Издательство:");
    puts("Год издания: \t\t");
    b->izdatelstvo.year=input_natural_int();
    puts("Город:\t\t");
    gets(b->izdatelstvo.city);
    puts("Название:\t\t");
    gets(b->izdatelstvo.name);

}



void output_book(struct book *b){
    puts("Название :\t\t");
    puts(b->title);
    puts("Цена:\t\t");
    printf("%f\n", b->price);
    puts("Автор :\t\t");
    puts(b->author);
    puts("Кол-во страниц :\t\t");
    printf("%d\n",b->pages);
    puts("Издательство:");
    puts("Год издания: \t\t");
    printf("%d\n",b->izdatelstvo.year);
    puts("Город:\t\t");
    puts(b->izdatelstvo.city);
    puts("Название:\t\t");
    puts(b->izdatelstvo.name);

}





int main(){
    struct book A[lmax];
    int k;
    SetConsoleCP(1251);
    SetConsoleOutputCP(1251);
    k=input_natural_int();
    for(int i=0;i<k;i++){
        input_book(&A[i]);
    }

    return 0;
}