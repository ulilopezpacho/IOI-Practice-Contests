#include "parrots.h"
#include "parrots.cpp"

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_N 1000
#define MAX_M 10000

static int message[MAX_N];
static int N, NN;
static int encoded_message[MAX_M];
static int M;
static int output_message[MAX_N];
static int O;

void send(int x) {
  printf("M = %d, send(%d)\n", M, x);
  if (M == MAX_M) {
    printf("Encoded message too long\n");
    exit(0);
  }
  encoded_message[M] = x;
  M++;
}

int read_data() {
  if (NN == M) {
    printf("Read too many encoded message\n");
    exit(0);
  }
  NN++;
  return encoded_message[NN - 1];
}

void output(int y) {
  if (O == N)
    O++;
  if (O > N)
    return;
  output_message[O] = y;
  O++;
}

static void random_shuffle() {
  int i, t, p;
  for (i = 0; i < M - 1; i++) {
    p = rand() % (M - i);
    t = encoded_message[i];
    encoded_message[i] = encoded_message[i + p];
    encoded_message[i + p] = t;
  }
}

static int check_output() {
  int i;

  if (O != N)
    return 0;
  for (i = 0; i < N; i++)
    if (message[i] != output_message[i])
      return 0;
  return 1;
}


int main() {

  scanf("%d", &N);
  for (int i = 0; i < N; i++)
    scanf("%d", &message[i]);

  M = 0;
  encode(N, message);
  random_shuffle();

  NN = 0;
  O = 0;
  decode(N, M, encoded_message);

  if (!check_output()) {
    printf("Incorrect\n");
    exit(0);
  }

  printf("Correct.\n");
  printf("%f\n", (float)M / N);
  return 0;
}
