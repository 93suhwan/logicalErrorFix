#include <bits/stdc++.h>
using namespace std;
const int P = 13331;
const int N = 2e5 + 10, M = 2 * N, p = 1e9 + 7;
int n, m, k;
long long base[N];
void solve() {
  base[1] = 1;
  for (int i = 2; i < N; i++) base[i] = (base[i - 1] * i) % p;
  cin >> n;
  cout << (base[2 * n] + 1) / 2 << '\n';
}
int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  cout.tie(nullptr);
  int T;
  cin >> T;
  while (T--) {
    solve();
  }
  return 0;
}
