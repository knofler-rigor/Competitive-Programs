#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define HASH_SIZE 1234555
typedef struct _node{
  int t;
  int i;
  int c;
  int a;
  struct _node *next;
} node;
typedef struct _lnode{
  int x;
  int w;
  struct _lnode *next;
} lnode;
int abss(int x);
void insert_edge(int x,int y,int w);
void dfs(int x,int c);
void sort_a2(int*a,int*b,int size);
void merge2(int*a,int*left_a,int*right_a,int*b,int*left_b,int*right_b,int left_size, int right_size);
void sort_a_ad(int*a,int*c,int size,int*new_size);
void merge_ad(int*a,int*left_a,int*right_a,int*c,int*left_c,int*right_c,int left_size, int right_size,int*new_size);
void insert(int target,int idx,int c,int a);
int search(int target,int idx,int *c);
int solve(int target,int target2,int idx);
void clean_table();
int N,w,b,ngs,*cans,*cdiff,*c,idx[200000],*trace,mark[200000]={0},diff[200000],f[200000],s[200000],*remain;
lnode **table;
node *hash[HASH_SIZE]={0};

int main(){
  int M,x,y,gs,sum,ans,target,i,j,k;
  scanf("%d%d",&N,&M);
  table=(lnode**)malloc(N*sizeof(lnode*));
  memset(table,0,N*sizeof(lnode*));
  for(i=0;i<M;i++){
    scanf("%d%d",&x,&y);
    insert_edge(x-1,y-1,1);
  }
  trace=(int*)malloc(N*sizeof(int));
  memset(trace,0,N*sizeof(int));
  for(i=gs=0;i<N;i++)
    if(!trace[i]){
      w=b=0;
      dfs(i,0);
      x=i;
      if(table[i])
        y=table[i]->x;
      else
        y=-1;
      if(w>b){
        diff[gs]=w-b;
        f[gs]=x;
        s[gs]=y;
      }
      else{
        diff[gs]=b-w;
        f[gs]=y;
        s[gs]=x;
      }
      idx[gs]=gs;
      gs++;
    }
  free(trace);
  clean_table();
  free(table);
  cdiff=(int*)malloc(gs*sizeof(int));
  c=(int*)malloc(gs*sizeof(int));
  for(i=sum=0,ans=200001;i<gs;i++){
    sum+=diff[i];
    cdiff[i]=diff[i];
    c[i]=1;
  }
  target=sum/2;
  sort_a2(diff,idx,gs);
  sort_a_ad(cdiff,c,gs,&ngs);
  remain=(int*)malloc(ngs*sizeof(int));
  if(!M || ngs==1){
    printf("%d %d\n",gs%2*cdiff[0],gs-1);
    for(i=0;i<gs-1;i++)
      printf("%d %d\n",f[i]+1,f[i+1]+1);
    return 0;
  }
  for(i=0;i<ngs;i++)
    if(i==0)
      remain[i]=c[i]*cdiff[i];
    else
      remain[i]=remain[i-1]+c[i]*cdiff[i];
  ans=solve(target,(sum+1)/2,ngs-1);
  cans=remain;
  memset(cans,0,ngs*sizeof(int));
  for(i=ngs-1;i>=0;i--){
    if(target<=0)
      break;
    if(i==0){
      cans[i]=(target-1)/cdiff[i]+1;
      break;
    }
    search(target,i,&cans[i]);
    if(cans[i]==-1){
      for(j=i;j>=0;j--)
        cans[j]=c[j];
      break;
    }
    target-=cans[i]*cdiff[i];
  }
  for(j=0,k=0;j<gs && k<ngs;k++){
    x=j+cans[k];
    for(;j<x;j++)
      mark[j]=1;
    while(diff[j]==cdiff[k] && j<gs)
      j++;
  }
  printf("%d %d\n",abss(2*ans-sum),gs-1);
  for(i=0;i<gs;i++)
    if(s[idx[i]]!=-1)
      k=i;
  for(i=0;i<gs;i++){
    if(i==k)
      continue;
    if(mark[i]!=mark[k])
      printf("%d %d\n",f[idx[i]]+1,f[idx[k]]+1);
    else
      printf("%d %d\n",f[idx[i]]+1,s[idx[k]]+1);
  }
  return 0;
}
int abss(int x){
  return (x<0)?-x:x;
}
void insert_edge(int x,int y,int w){
  lnode *t=malloc(sizeof(lnode));
  t->x=y;
  t->w=w;
  t->next=table[x];
  table[x]=t;
  t=malloc(sizeof(lnode));
  t->x=x;
  t->w=w;
  t->next=table[y];
  table[y]=t;
  return;
}
void dfs(int x,int c){
  lnode *p;
  trace[x]=1;
  if(c)
    b++;
  else
    w++;
  for(p=table[x];p;p=p->next)
    if(!trace[p->x])
      dfs(p->x,c^1);
  return;
}
void sort_a2(int*a,int*b,int size){
  if (size < 2)
    return;
  int m = (size+1)/2,i;
  int*left_a,*left_b,*right_a,*right_b;
  left_a=(int*)malloc(m*sizeof(int));
  right_a=(int*)malloc((size-m)*sizeof(int));
  left_b=(int*)malloc(m*sizeof(int));
  right_b=(int*)malloc((size-m)*sizeof(int));
  for(i=0;i<m;i++){
    left_a[i]=a[i];
    left_b[i]=b[i];
  }
  for(i=0;i<size-m;i++){
    right_a[i]=a[i+m];
    right_b[i]=b[i+m];
  }
  sort_a2(left_a,left_b,m);
  sort_a2(right_a,right_b,size-m);
  merge2(a,left_a,right_a,b,left_b,right_b,m,size-m);
  free(left_a);
  free(right_a);
  free(left_b);
  free(right_b);
  return;
}
void merge2(int*a,int*left_a,int*right_a,int*b,int*left_b,int*right_b,int left_size, int right_size){
  int i = 0, j = 0;
  while (i < left_size|| j < right_size) {
    if (i == left_size) {
      a[i+j] = right_a[j];
      b[i+j] = right_b[j];
      j++;
    } else if (j == right_size) {
      a[i+j] = left_a[i];
      b[i+j] = left_b[i];
      i++;
    } else if (left_a[i] <= right_a[j]) {
      a[i+j] = left_a[i];
      b[i+j] = left_b[i];
      i++;
    } else {
      a[i+j] = right_a[j];
      b[i+j] = right_b[j];
      j++;
    }
  }
  return;
}
void sort_a_ad(int*a,int*c,int size,int*new_size){
  if (size < 2){
    (*new_size)=size;
    return;
  }
  int m = (size+1)/2,i;
  int *left_a,*right_a,*left_c,*right_c;
  left_a=(int*)malloc(m*sizeof(int));
  right_a=(int*)malloc((size-m)*sizeof(int));
  left_c=(int*)malloc(m*sizeof(int));
  right_c=(int*)malloc((size-m)*sizeof(int));
  for(i=0;i<m;i++){
    left_a[i]=a[i];
    left_c[i]=c[i];
  }
  for(i=0;i<size-m;i++){
    right_a[i]=a[i+m];
    right_c[i]=c[i+m];
  }
  int new_l_size=0,new_r_size=0;
  sort_a_ad(left_a,left_c,m,&new_l_size);
  sort_a_ad(right_a,right_c,size-m,&new_r_size);
  merge_ad(a,left_a,right_a,c,left_c,right_c,new_l_size,new_r_size,new_size);
  free(left_a);
  free(right_a);
  free(left_c);
  free(right_c);
  return;
}
void merge_ad(int*a,int*left_a,int*right_a,int*c,int*left_c,int*right_c,int left_size, int right_size,int*new_size){
  int i = 0, j = 0,index=0;
  while (i < left_size|| j < right_size) {
    if (i == left_size) {
      c[index] = right_c[j];
      a[index++] = right_a[j];
      j++;
    } else if (j == right_size) {
      c[index] = left_c[i];
      a[index++] = left_a[i];
      i++;
    } else if (left_a[i] <= right_a[j]) {
      c[index] = left_c[i];
      a[index++] = left_a[i];
      i++;
    } else {
      c[index] = right_c[j];
      a[index++] = right_a[j];
      j++;
    }
    if(index>1&&a[index-2]==a[index-1]){
      c[index-2]+=c[index-1];
      index--;
    }
  }
  (*new_size)=index;
  return;
}
void insert(int target,int idx,int c,int a){
  int bucket=(target*200000LL+idx)%HASH_SIZE;
  node *t;
  t=(node*)malloc(sizeof(node));
  t->t=target;
  t->i=idx;
  t->c=c;
  t->a=a;
  t->next=hash[bucket];
  hash[bucket]=t;
  return;
}
int search(int target,int idx,int *c){
  int bucket=(target*200000LL+idx)%HASH_SIZE;
  node *t=hash[bucket];
  while(t){
    if(t->t==target && t->i==idx){
      *c=t->c;
      return t->a;
    }
    t=t->next;
  }
  return -1;
}
int solve(int target,int target2,int idx){
  if(target<=0)
    return 0;
  if(target>remain[idx])
    return -1;
  if(target==remain[idx]){
    insert(target,idx,-1,target);
    return target;
  }
  int t,ans=200000,ansc,i;
  if(idx==0){
    t=(target-1)/cdiff[idx]+1;
    return t*cdiff[idx];
  }
  t=search(target,idx,&w);
  if(t!=-1)
    return t;
  for(i=0;i<=c[idx];i++){
    t=solve(target-i*cdiff[idx],target2-i*cdiff[idx],idx-1);
    if(t!=-1){
      if(t+i*cdiff[idx]<ans){
        ans=t+i*cdiff[idx];
        ansc=i;
      }
      if(t+i*cdiff[idx]==target || t+i*cdiff[idx]==target2){
        insert(target,idx,i,t+i*cdiff[idx]);
        return t+i*cdiff[idx];
      }
    }
    if(target-i*cdiff[idx]<=0)
      break;
  }
  insert(target,idx,ansc,ans);
  return ans;
}
void clean_table(){
  int i;
  lnode *p,*pp;
  for(i=0;i<N;i++)
    if(table[i]){
      p=table[i];
      while(p){
        pp=p->next;
        free(p);
        p=pp;
      }
      table[i]=NULL;
    }
  return;
}
