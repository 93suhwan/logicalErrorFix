#include <bits/stdc++.h>
using namespace std;
const long long mx = 1e5 + 9, INF = 1e9 + 7;
long long T, N, K, A[mx];
void open() {
  if (fopen("aa.inp", "r")) {
    freopen("aa.inp", "r", stdin);
    freopen("aa.out", "w", stdout);
  }
}
void solve() {
  cin >> T;
  while (T--) {
    cin >> N;
    long long K;
    if (N % 2 == 0) {
      K = (N - 1) / 2;
      for (long long i = 1; i <= K; ++i) {
        cout << "a";
      }
      cout << "b";
      for (long long i = 1; i <= K + 1; ++i) {
        cout << "a";
      }
      cout << "\n";
      continue;
    }
    K = (N - 2) / 2;
    for (long long i = 1; i <= K; ++i) {
      cout << "a";
    }
    cout << "bc";
    for (long long i = 1; i <= K + 1; ++i) {
      cout << "a";
    }
    cout << "\n";
  }
}
int main() {
  open();
  solve();
  return 0;
}
