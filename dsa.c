#include<stdio.h>
#include<stdlib.h>

struct Node{
    int data;
    struct Node*next;
    }*first=NULL, *second=NULL, *third=NULL;
    
    void create1stlist( int n)
    {
        int i, num ;
        struct Node *t, *last;
        first=(struct Node *)malloc(sizeof(struct Node));
        printf("--Welcome to the first list--");
        printf("\n");
        printf("Enter the 1st node: ");
        scanf("%d", &num);
        first->data= num;
        first->next=NULL;
        last=first;

        for( int i=2; i<=n ; i++){
            int  j;
            t=(struct Node*)malloc(sizeof(struct Node));
            printf("Enter the %d node: " , i);
            scanf("%d",&j);
            t->data=j;
            t->next=NULL;
            last->next=t;
            last=t;
        }
    }

    void Display(struct Node*p){
           while(p!=NULL){
            printf("%d",p->data);
           
            p=p->next;
            printf("->");
            }
    
    }
     void create2ndlist( int n)
    {
        int i, num ;
        struct Node *t, *last;
        second=(struct Node *)malloc(sizeof(struct Node));
        printf(" --Welcome to the 2nd linked list-- ");
        printf("\n");
        printf("Enter the 1st node: ");
        scanf("%d", &num);
        second->data= num;
        second->next=NULL;
        last=second;

        for( int i=2; i<=n ; i++){
            int  j;
            t=(struct Node*)malloc(sizeof(struct Node));
            printf("Enter the %d node: " , i);
            scanf("%d",&j);
            t->data=j;
            t->next=NULL;
            last->next=t;
            last=t;
        }
    }

    void Concatenate(struct Node*p , struct Node*q)
    {
        third=p;

        while(p->next!=NULL){
            p=p->next;
           }
            p->next=q;
        
    }

    void Merge(struct Node*p, struct Node*q){
        struct Node*last;
        if(p->data<q->data){
            third=last=p;
            p=p->next;
            third->next=NULL;
        }
        else{
            third=last=q;
            q=q->next;
            third->next=NULL;

        }
        while(p && q){
            if(p->data<q->data)
            {
              last->next=  p;
              last=p;
              p=p->next;
              last->next=NULL;
            }
            else
            {
              last->next=  q;
              last=q;
              q=q->next;
              last->next=NULL;
            }
        }
        if(p){
            last->next=p;
        }
        else{
            last->next=q;
        }
    }

    
    


int main()
{
    int k , l;
    printf("Enter no. of nodes of 1st list: " );
    scanf("%d", &k);
    create1stlist(k);
    

    printf("\n");
    printf("\n");

    printf("Enter no. of nodes of 2nd list: " );
    scanf("%d", &l);
    create2ndlist(l);

    printf("\n");
    printf("\n");
    //Concatenate(first,second);

   // printf(" Concatinated list ");
    //printf("\n");
   // Display(third);

   Merge(first,second);
   Display(third);

    


     


    return 0;

    
}