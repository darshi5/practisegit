#include <stdio.h>
#include <stdlib.h>

struct Node
{
    int row;
    int col;
    int value;
    struct Node *next;
} *first = NULL;

void create(int n)
{
    int i, num, g, k;
    struct Node *t, *last;
    first = (struct Node *)malloc(sizeof(struct Node));
    printf("Enter the 1st non zero element's value: ");
    scanf("%d", &num);

    printf("Enter the first non zero element's row no.");
    scanf("%d", &g);
    printf("Enter the first non zero element's col no.");
    scanf("%d", &k);
    first->row = g;
    first->col = k;
    first->value = num;
    first->next = NULL;
    last = first;

    for (int i = 2; i <= n; i++)
    {
        int j, u, e;
        t = (struct Node *)malloc(sizeof(struct Node));
        printf("Enter the %d elements value ", i);
        scanf("%d", &j);
        t->value = j;
        printf("Enter the %d element's row no. : ", i);
        scanf("%d", &u);
        t->row = u;
        printf("Enter the %d element's col no. : ", i);
        scanf("%d", &e);
        t->col = e;
        t->next = NULL;
        last->next = t;
        last = t;
    }
}

void Display(struct Node *p)
{

    while (p != NULL)
    {   
        printf("%d  %d  %d", p->row, p->col, p->value);

        p = p->next;
        printf("\n");
    }
}


int main()
{
    int k, r, c;
    printf("Enter the no. of rows: ");
    scanf("%d", &r);
    printf("Enter the no. of columns: ");
    scanf("%d", &c);
    printf("Enter no. of non zero elements: ");
    scanf("%d", &k);
    
    create(k);
    printf("\n");
    printf("Row  Col  Value");
    printf("\n");
    printf("%d  %d  %d", r, c, k);
    printf("\n");
        Display(first);

    return 0;
}