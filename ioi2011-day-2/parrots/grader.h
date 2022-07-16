#ifndef __GRADER_H__
#define __GRADER_H__

#ifdef __cplusplus
extern "C" {
#endif

void decode(int N, int L, int X[]);
void encode(int N, int M[]);


typedef void (*decodeFunction)(int, int, int[]);
typedef void (*encodeFunction)(int, int[]);
void output(int b);
void send(int a);


#ifdef __cplusplus
}
#endif

#endif /* __GRADER_H__ */
