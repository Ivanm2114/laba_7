#include <stdio.h>
#include <stdlib.h>
#include <Windows.h>
#include <string.h>
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
            printf("������� ����������� �����\n");
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
        printf("������� ������������� �����:\n");
        x=scanf("%f",&res);
        while (getchar()!='\n');
    }
    while(x<1||res<=0);
    return res;

}



void input_book(struct book *b){
    printf("�������� :  ");
    gets(b->title);
    printf("����:  ");
    b->price=input_natural_float();
    printf("����� :   ");
    gets(b->author);
    printf("���-�� ������� :  ");
    b->pages = input_natural_int();
    puts("������������:");
    printf("��� �������:   ");
    b->izdatelstvo.year=input_natural_int();
    printf("�����:  ");
    gets(b->izdatelstvo.city);
    printf("��������:  ");
    gets(b->izdatelstvo.name);

}



void output_book(struct book *b){
    printf("�������� :\t\t");
    puts(b->title);
    printf("����:\t\t\t");
    printf("%.2f\n", b->price);
    printf("����� :\t\t\t");
    puts(b->author);
    printf("���-�� ������� :\t");
    printf("%d\n",b->pages);
    puts("������������:");
    printf("��� �������: \t\t");
    printf("%d\n",b->izdatelstvo.year);
    printf("�����:\t\t\t");
    puts(b->izdatelstvo.city);
    printf("��������:\t\t");
    puts(b->izdatelstvo.name);

}


int function(struct book *a,int k, char b[lmax][lmax],char city[lmax], int year){
    int count=0;
    for(int i=0;i<k;i++){
        if(strcmp(a[i].izdatelstvo.city,city)==0 && a[i].izdatelstvo.year>year){
            strcpy(b[count++],a[i].title);
        }
    }
    return count;


}


int main(){
    struct book A[lmax];
    char titles[lmax][lmax];
    int k,year, count;
    char city[lmax];
    SetConsoleCP(1251);
    SetConsoleOutputCP(1251);
    k=input_natural_int();
    for(int i=0;i<k;i++){
        input_book(&A[i]);
    }
    puts("\n\n");
    for(int i=0;i<k;i++){
        output_book(&A[i]);
        puts("\n");
    }
    puts("������� �����");
    gets(city);
    puts("������� ���");
    year=input_natural_int();
    count=function(A,k,titles,city,year);
    if(count>0){
        printf("������� %d ����(�)\n",count);
    for(int i=0;i<count;i++){
        puts(titles[i]);
    }}
    else{
        printf("����� �� �������");
    }
    return 0;
}