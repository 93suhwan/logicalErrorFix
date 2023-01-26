#include <bits/stdc++.h>
using namespace std;
int N;
int L[1003], R[1003];
int main() {
  int T;
  scanf("%d", &T);
  while (T--) {
    scanf("%d", &N);
    for (int i = 1; i <= N; ++i) scanf("%d %d", L + i, R + i);
    for (int i = 1; i <= N; ++i) {
      int d = L[i];
      for (int j = 1; j <= N; ++j)
        if (L[j] == L[i] && R[j] < R[i]) d = max(d, R[j] + 1);
      printf("%d %d %d\n", L[i], R[i], d);
    }
    puts("");
  }
  return 0;
}
