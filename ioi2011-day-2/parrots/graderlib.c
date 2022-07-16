#include "grader.h"
#include <stdio.h>
#include <stdlib.h>

#define MAX_N  1000
#define MAX_M 10000

static int message[MAX_N];
static int N, NN;
static int encoded_message[MAX_M];
static int M;
static int output_message[MAX_N];
static int O;
static int max_expansion, channel_range;

void send(int x)
{
  if(M == MAX_M) {
    printf("Encoded message too long\n");
    exit(0);
  }
  encoded_message[M] = x;
  M++;
}

int read_data()
{
  if(NN == M) {
    printf("Read too many encoded message\n");
    exit(0);
  }
  NN++;
  return encoded_message[NN-1];
}

void output(int y)
{
  if(O == N)
    O++;
  if(O > N)
    return;
  output_message[O] = y;
  O++;
}

static void sort_message(int d)
{
  int i, j, b, bi, t;
  for(i=0; i<M-1; i++) {
    bi = i;
    b = encoded_message[i];
    for(j=i+1; j<M; j++)
      if(((d==0) && (encoded_message[j] < b)) ||
     ((d==1) && (encoded_message[j] > b))) {
    b = encoded_message[j];
    bi = j;
      }
    t = encoded_message[i];
    encoded_message[i] = encoded_message[bi];
    encoded_message[bi] = t;
  }
}

static void random_shuffle()
{
  int i, t, p;
  for(i=0; i<M-1; i++) {
    p = rand()%(M-i);
    t = encoded_message[i];
    encoded_message[i] = encoded_message[i+p];
    encoded_message[i+p] = t;
  }    
}

static void shuffle(int method)
{
  if(method==0)
    sort_message(0);
  else if(method==1)
    sort_message(1);
  else
    random_shuffle();
}

static void check_encoded_message()
{
  int i;
  if(M > max_expansion * N) {
    printf("Encoded message too long.");
    exit(0);
  }
  for(i=0; i < M; i++)
    if((encoded_message[i] < 0) || 
       (encoded_message[i] > channel_range)) {
      printf("Bad encoded integer\n");
      exit(0);
    }
}

static int check_output()
{
  int i;

  if(O!=N)
    return 0;
  for(i = 0; i < N; i++)
    if(message[i] != output_message[i])
      return 0;
  return 1;
}

int _main(encodeFunction encode, decodeFunction decode)
{
  int i,tt,t,p,r;

  scanf("%d",&tt);
  scanf("%d %d",&max_expansion,&channel_range);

  scanf("%d",&r);
  srand(r);

  for(t=0; t<tt; t++) {
    scanf("%d",&N);
    for(i = 0; i < N; i++)
      scanf("%d",&message[i]);

    M = 0;
    encode(N,message);

    check_encoded_message();
    
    scanf("%d",&p);
    shuffle(p);
    
    NN = 0;
    O = 0;
    decode(N,M,encoded_message);
    
    if(!check_output()) {
      printf("Incorrect\n");
      exit(0);
    }
  }
  printf("Correct.\n");
  printf("%f\n",(float)M/N);
  return 0;
}
