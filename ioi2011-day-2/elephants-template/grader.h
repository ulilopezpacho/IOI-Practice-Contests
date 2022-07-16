#ifndef __GRADER_H__
#define __GRADER_H__

#ifdef __cplusplus
extern "C" {
#endif

void init(int N, int L, int X[]);
int update(int i, int y);

typedef void (*initFunction)(int N, int L, int X[]);
typedef int (*updateFunction)(int i, int y);

#ifdef __cplusplus
}
#endif

#endif /* __GRADER_H__ */
