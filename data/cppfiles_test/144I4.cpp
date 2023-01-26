#include <bits/stdc++.h>
using namespace std;
const long long MOD = 1e9 + 7;
const long long MxN = 1e6 + 5;
const long long INF = 1e18;
int dx[8] = {0, 1, 0, -1, 1, 1, -1, -1};
int dy[8] = {1, 0, -1, 0, 1, -1, 1, -1};
void solve(int tc) {
  long long n, m, K;
  cin >> n >> m >> K;
  long long b = n % m, s = m - n % m, pp = n / m;
  int p = 0;
  for (int i = 1; i <= K; i++) {
    for (int j = 1; j <= b; j++) {
      cout << pp + 1 << " ";
      for (int k = 1; k <= pp + 1; k++) {
        cout << p + 1 << " ";
        p = (p + 1) % n;
      }
      cout << '\n';
    }
    for (int j = 1; j <= s; j++) {
      cout << pp << " ";
      for (int k = 1; k <= pp; k++) {
        cout << p + 1 << " ";
        p = (p + 1) % n;
      }
    }
    cout << '\n';
  }
  cout << '\n';
}
int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  int t;
  cin >> t;
  int n = 1;
  while (t--) {
    solve(n++);
  }
}
