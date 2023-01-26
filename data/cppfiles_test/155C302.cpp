#include <bits/stdc++.h>
unsigned int X;
__attribute__((constructor)) void setRandSeed() {
  struct timeval now;
  gettimeofday(&now, 0);
  X = now.tv_sec ^ now.tv_usec | 1;
  return;
}
static inline int pRand(int max) { return (X *= 3) % max; }
void shuffle(void *arrayPointer, int len, int size) {
  char *array = (char *)arrayPointer;
  char tmp[size];
  for (int i = len - 1; i >= 1; --i) {
    int randIndice = pRand(i);
    memcpy(tmp, &array[i * size], size);
    memcpy(&array[i * size], &array[randIndice * size], size);
    memcpy(&array[randIndice * size], tmp, size);
  }
  return;
}
void sort(void *array, int num, int size,
          int (*cmp)(const void *, const void *)) {
  shuffle(array, num, size);
  qsort(array, num, size, cmp);
  return;
}
int ascPair(const void *pa, const void *pb) {
  int *a = (int *)pa;
  int *b = (int *)pb;
  if (a[0] == b[0])
    return a[1] - b[1];
  else
    return a[0] - b[0];
}
int a[200000][2];
int likes[200000][2];
int dislikes[200000][2];
int ans[200000];
char str[200000 + 1];
void testcase() {
  int n;
  scanf("%d", &n);
  for (int i = 0; i < n; ++i) {
    scanf("%d", &a[i][0]);
    a[i][1] = i;
  }
  scanf("%s", str);
  int likesLen = 0;
  int dislikesLen = 0;
  for (int i = 0; i < n; ++i) {
    if (str[i] == '1') {
      likes[likesLen][0] = a[i][0];
      likes[likesLen][1] = a[i][1];
      ++likesLen;
    } else {
      dislikes[dislikesLen][0] = a[i][0];
      dislikes[dislikesLen][1] = a[i][1];
      ++dislikesLen;
    }
  }
  sort(likes, likesLen, sizeof(likes[0]), ascPair);
  sort(dislikes, dislikesLen, sizeof(dislikes[0]), ascPair);
  int rank = n;
  for (int i = likesLen - 1; i >= 0; --i) {
    ans[likes[i][1]] = rank--;
  }
  for (int i = dislikesLen - 1; i >= 0; --i) {
    ans[dislikes[i][1]] = rank--;
  }
  for (int i = 0; i < n; ++i) {
    printf("%d ", ans[i]);
  }
  printf("\n");
  return;
}
int main() {
  int t;
  scanf("%d", &t);
  for (int i = 0; i < t; ++i) testcase();
  return 0;
}
