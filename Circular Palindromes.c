#include <stdio.h>
#include <stdlib.h>
#include <string.h>
void solve(char *str,int *a);
void init( int n );
void range_increment( int i, int j, int val );
int query( int i );
int max(int x,int y);
void update(int x,int y,int z);
void sort_a2(int*a,int*b,int size);
void merge2(int*a,int*left_a,int*right_a,int*b,int*left_b,int*right_b,int left_size, int right_size);
char str[1000001]={0};
int N,NN,a[2000004],tree[2000000],ans[500000],b[500000],c[500000];

int main(){
  int i,j;
  scanf("%d%s",&NN,str);
  strncpy(str+NN,str,NN);
  solve(str,a);
  init(NN);
  for(i=0;i<4*NN;i++)
    if(a[i])
      if(i%2)
        update(i/2-a[i]/2,i/2+a[i]/2,a[i]);
      else
        update(i/2-a[i]/2,i/2+a[i]/2-1,a[i]);
  for(i=0;i<NN;i++){
    ans[i]=query(i);
    b[i]=ans[i];
    c[i]=i;
  }
  sort_a2(b,c,NN);
  for(i=NN;i>=0;i--){
    for(j=c[i];1;j=(j-1+NN)%NN)
      if(ans[j]-ans[(j-1+NN)%NN]>2)
        ans[(j-1+NN)%NN]=ans[j]-2;
      else
        break;
    for(j=c[i];1;j=(j+1)%NN)
      if(ans[j]-ans[(j+1)%NN]>2)
        ans[(j+1)%NN]=ans[j]-2;
      else
        break;
  }
  for(i=0;i<NN;i++)
    printf("%d\n",ans[i]);
  return 0;
}
void solve(char *str,int *a){
  char *p;
  int len,R,Ri,i,j,mi;
  len=strlen(str);
  p=(char*)malloc(2*(len+1)*sizeof(char));
  for(i=0;i<len;i++){
    p[2*i]='#';
    p[2*i+1]=str[i];
  }
  p[2*i]='#';
  p[2*i+1]=0;
  a[0]=R=Ri=0;
  for(i=1;i<=len*2;i++)
    if(i>=R){
      if(p[i]!='#')
        a[i]=1;
      else
        a[i]=0;
      for(j=i+1;1;j++)
        if(j<=2*len && 2*i-j>=0 && p[j]==p[2*i-j]){
          if(p[j]!='#')
            a[i]+=2;
        }
        else{
          Ri=i;
          R=j-1;
          break;
        }
    }
    else{
      mi=2*Ri-i;
      if(i+a[mi]>=R || mi==a[mi]){
        a[i]=R-i;
        for(j=R+1;1;j++)
          if(j<=2*len && 2*i-j>=0 && p[j]==p[2*i-j]){
            if(p[j]!='#')
              a[i]+=2;
          }
          else{
            Ri=i;
            R=j-1;
            break;
          }
      }
      else
        a[i]=a[mi];
    }
  free(p);
  return;
}
void init( int n ){
  N = 1;
  while( N < n ) N *= 2;
  int i;
  for( i = 1; i < N + n; i++ ) tree[i] = 0;
}
void range_increment( int i, int j, int val ){
  for( i += N, j += N; i <= j; i = ( i + 1 ) / 2, j = ( j - 1 ) / 2 )
  {
    if( i % 2 == 1 ) tree[i] = max(tree[i],val);
    if( j % 2 == 0 ) tree[j] = max(tree[j],val);
  }
}
int query( int i ){
  int ans = 0,j;
  for( j = i + N; j; j /= 2 ) ans = max(ans,tree[j]);
  return ans;
}
int max(int x,int y){
  return (x>y)?x:y;
}
void update(int x,int y,int z){
  if(z>NN){
    int m=x+z/2;
    if(z%2)
      if(NN%2)
        update(m-NN/2,m+NN/2,NN);
      else
        update(m-NN/2+1,m+NN/2-1,NN-1);
    else
      if(NN%2)
        update(m-NN/2,m+NN/2-1,NN-1);
      else
        update(m-NN/2,m+NN/2-1,NN);
  }
  if(y<NN){
    range_increment(0,x,z);
    range_increment(y+1,NN-1,z);
  }
  else
    range_increment(y-NN+1,x,z);
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
