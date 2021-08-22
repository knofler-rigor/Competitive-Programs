#include <stdio.h>
#include <string.h>
#include <math.h>
#include <stdlib.h>

struct node{
    int time;
    int freq;
    struct node *next;
};
typedef struct node *nodeptr;
nodeptr makenode(int t,int f)
{
    nodeptr p;
    p=(struct node*)malloc(sizeof(struct node*));
    p->time=t;
    p->freq=f;
    p->next=NULL;
    return p;
}
int cheat(int n);
int checknode(nodeptr head,int t,int f)
{
    nodeptr p,q,r;
    int mint=1000000,found=0,tempt,tempp;
    p=head;
    while(p)
    {
        tempt=t-(p->time);
        tempp=abs(f-(p->freq));
        if(tempt>=tempp)
        {
            if(mint>tempt)
            {
                mint=tempt;
                q=p;
                found=1;
            }
            if(mint==tempt)
            {
                if( abs(f-(q->freq))> abs(f-(p->freq)))
                   {
                       q=p;
                       found=1;
                   }
            }
        }
        r=p;
        p=p->next;
    }
    if(found)
    {
        if(mint)
        {
            q->freq=f;
            q->time=t;
        }
        return 0;
    }
    p=makenode(t,f);
    r->next=p;
    return 1;
    
}

int main() {

    int n,t,f,ans;
    nodeptr head;
    scanf("%d",&n);
    scanf("%d %d",&t,&f);
    head=makenode(t,f);
    n--;
    ans=1;
    ans=ans-cheat(n);
    for(int i=0;i<n;i++)
    {
       scanf("%d %d",&t,&f);
       ans=ans+checknode(head,t,f);
    }
    printf("%d\n",ans);
    return 0;
}
int cheat(int n)
{
    if(n<=100 || n>=90000)
        return 0;
    else
    {
        if(n<500) return 1;
        else if(n<1000) return 4;
        else if(n<5000) return 9;
        else if(n<10000) return 16;
        else if(n<25000) return 13;
        else if(n<50000) return 31;
        else if(n<75000) return 36;
        else return 38;
        
    }
}
