#include <bits/stdc++.h>
int asc(const void *pa, const void *pb) { return *(int *)pa - *(int *)pb; }
int a[50];
int orig[50];
void testcase() {
  int ans[50][3];
  int ansLen = 0;
  int n;
  scanf("%d", &n);
  for (int i = 0; i < n; ++i) scanf("%d", &a[i]);
  for (int i = 0; i < n; ++i) orig[i] = a[i];
  qsort(a, n, sizeof(a[0]), asc);
  printf("%d\n", n);
  for (int i = 0; i < n; ++i) {
    int idx;
    for (int j = i; j < n; ++j) {
      if (a[i] == orig[j]) {
        idx = j;
        break;
      }
    }
    if (i == idx) continue;
    int last = orig[idx];
    for (int j = idx; j > i; --j) {
      orig[j] = orig[j - 1];
    }
    orig[i] = last;
    ans[ansLen][0] = i + 1;
    ans[ansLen][1] = idx + 1;
    ans[ansLen][2] = idx - i;
    ++ansLen;
  }
  printf("%d\n", ansLen);
  for (int i = 0; i < ansLen; ++i)
    printf("%d %d %d\n", ans[i][0], ans[i][1], ans[i][2]);
  return;
}
int main() {
  int t;
  scanf("%d", &t);
  for (int i = 0; i < t; ++i) testcase();
  return 0;
}
