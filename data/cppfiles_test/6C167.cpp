#include <bits/stdc++.h>
using namespace std;
int const N = 2e5 + 1;
int A[N], B[N];
int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(0x0);
  cout.tie(0x0);
  int n, m;
  cin >> n >> m;
  for (int i = 1; i <= m; ++i) {
    int a, b;
    cin >> a >> b;
    ++A[a], ++A[b];
    if (a < b)
      ++B[b];
    else
      ++B[a];
  }
  int R = 0, q;
  for (int i = 1; i <= n; ++i)
    if (A[i] == B[i]) ++R;
  cin >> q;
  while (q--) {
    int type;
    cin >> type;
    if (type == 3)
      cout << R << '\n';
    else {
      int u, v;
      cin >> u >> v;
      if (type == 1) {
        if (u < v) {
          ++A[v], ++B[v];
          ++A[u];
          if (A[u] - 1 == B[u])
            --R;
          else if (A[u] == B[u])
            ++R;
        } else {
          ++A[u], ++B[u];
          ++A[v];
          if (A[v] - 1 == B[v])
            --R;
          else if (A[v] == B[v])
            ++R;
        }
      } else {
        --A[u], --A[v];
        if (u < v) {
          --B[v];
          if (A[u] == B[u]) ++R;
          if (A[u] + 1 == B[u]) --R;
        } else {
          --B[u];
          if (A[v] == B[v]) ++R;
          if (A[v] + 1 == B[u]) --R;
        }
      }
    }
  }
  return 0;
}
