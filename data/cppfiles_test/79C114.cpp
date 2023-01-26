#include <bits/stdc++.h>
using namespace std;
int N, a[300001], b[300001], f[300001], dep[300001], pre[300001], pre2[300001];
int get() {
  int x = 0, f = 1;
  char c = getchar();
  while (c < '0' || c > '9') c == '-' && (f = -1), c = getchar();
  while (c >= '0' && c <= '9') x = x * 10 + c - '0', c = getchar();
  return x * f;
}
void print(int x) {
  if (x != N) print(pre[x]), cout << pre2[x] << ' ';
}
int getf(int x) { return f[x] == x ? x : f[x] = getf(f[x]); }
int main() {
  N = get();
  for (int i = 1; i <= N; i++) a[i] = get(), f[i] = i;
  for (int i = 1; i <= N; i++) b[i] = get();
  for (int i = 0; i <= N; i++) dep[i] = -1;
  dep[N] = 0;
  queue<int> q;
  q.push(N);
  while (!q.empty()) {
    int u = q.front();
    q.pop();
    if (a[u] == u) {
      cout << dep[u] + 1 << '\n';
      print(u);
      cout << "0\n";
      return 0;
    }
    for (int i = getf(u - a[u]); i < u; i = getf(i + 1)) {
      f[getf(i)] = getf(i + 1);
      if (dep[i + b[i]] == -1)
        dep[i + b[i]] = dep[u] + 1, pre[i + b[i]] = u, pre2[i + b[i]] = i;
      q.push(i + b[i]);
    }
  }
  cout << "-1\n";
  return 0;
}
