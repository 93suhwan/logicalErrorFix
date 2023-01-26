#include <bits/stdc++.h>
using namespace std;
const int MAXN = 4e6 + 10;
int N, P, arr[MAXN], diff[MAXN];
inline void add(int& a, int b) { a = a + b >= P ? a + b - P : a + b; }
inline void sub(int& a, int b) { a = a - b < 0 ? a - b + P : a - b; }
int main() {
  scanf("%d %d", &N, &P);
  arr[1] = 1;
  int sum = 1;
  for (int j = 2; j <= N; ++j) {
    add(diff[j], 1);
    sub(diff[j + j], 1);
  }
  for (int i = (2), iend = (N + 1); i < iend; ++i) {
    add(diff[i], diff[i - 1]);
    add(arr[i], sum);
    int tmp = arr[i];
    add(tmp, diff[i]);
    for (int j = 2; i * j <= N; ++j) {
      add(diff[i * j], tmp);
      sub(diff[j * i + j], tmp);
    }
    add(sum, tmp);
  }
  int ans = arr[N];
  add(ans, diff[N]);
  printf("%d\n", ans);
  return 0;
}
