#include <bits/stdc++.h>
using namespace std;
using li = long long;
using ld = long double;
using pii = pair<int, int>;
const int INF = 1e9 + 13;
const int N = 1e6 + 13;
const int M = 1e9 + 7;
const int B = 600;
const int A = 256;
const ld e = 1e-8;
const int LOGN = 20;
mt19937 rnd(time(0));
int sum(int a, int b) {
  a += b;
  return (a >= M ? a - M : a);
}
int dif(int a, int b) { return sum(a, M - b); }
int mul(int a, int b) { return a * 1ll * b % M; }
int pw[N];
void solve() {
  int n, k;
  cin >> n >> k;
  int ans = 0;
  int cur = 1;
  for (int i = k - 1; i >= 0; i--) {
    if (n % 2 == 0) {
      ans = sum(ans, mul(pw[i], cur));
      cur = mul(cur, dif(pw[n - 1], 1));
    } else {
      cur = mul(cur, sum(pw[n - 1], 1));
    }
  }
  cout << sum(ans, cur) << endl;
}
int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);
  pw[0] = 1;
  for (int i = 1; i < N; i++) pw[i] = mul(pw[i - 1], 2);
  int t;
  cin >> t;
  while (t--) solve();
}
