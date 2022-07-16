#include "grader.h"
#include <stdio.h>
#include <stdlib.h>

#define MAX_N 1000000
#define MAX_M 1000000

static int N,L,M;
static int X[MAX_N];
static int ii[MAX_M];
static int yy[MAX_M];

void read_input()
{
  int i;
  scanf("%d %d %d",&N,&L,&M);
  for(i=0; i<N; i++)
	scanf("%d",&X[i]);
  for(i=0; i<M; i++)
    scanf("%d %d",&ii[i],&yy[i]);
}

int _main(initFunction init, updateFunction update)
{
  int i, ans;

  read_input();
  init(N,L,X);
  for(i=0; i<M; i++) {
    ans = update(ii[i],yy[i]);
    printf("%d\n", ans);
  }
  return 0;
}
