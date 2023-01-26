#include <bits/stdc++.h>
using namespace std;
const int N = 1e5 + 10;
long long a[N], b[1050], c[N];
int cnt = 0;
void init() {
  cnt = 0;
  for (int i = 1; i < N - 50; i++) a[cnt++] = i * i;
  cnt = 0;
  for (int i = 1; i < 1010; i++) b[cnt++] = i * i * i;
  int u = 0, t = 0;
  cnt = 0;
  while (a[u] && b[t]) {
    if (a[u] < b[t]) {
      c[cnt++] = a[u++];
    } else if (a[u] == b[t]) {
      c[cnt++] = a[u++];
      t++;
    } else
      c[cnt++] = b[t++];
  }
}
int main() {
  init();
  int T;
  cin >> T;
  while (T--) {
    int n;
    scanf("%d", &n);
    int i = 0;
    while (c[i] <= n) {
      i++;
    }
    printf("%d\n", i);
  }
  return 0;
}
