#include <bits/stdc++.h>
using namespace std;
using li = long long;
using ld = long double;
using pii = pair<int, int>;
const int INF = 1e9 + 13;
const int N = 2e5 + 13;
const int M = 1e9 + 7;
const int B = 600;
const int A = 256;
const ld e = 1e-8;
const int LOGN = 20;
mt19937 rnd(time(0));
void solve() {
  int n, k;
  cin >> n >> k;
  int cnt = (n + k - 1) / k;
  cout << cnt << endl;
  for (int i = 0; i < n; i++) {
    for (int j = i + 1; j < n; j++) {
      cout << (i / k == j / k ? cnt : j / k) << ' ';
    }
  }
  cout << endl;
}
int main() {
  int t = 1;
  while (t--) solve();
}
