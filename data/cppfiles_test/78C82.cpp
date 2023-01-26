#include <bits/stdc++.h>
using namespace std;
const double PI = acos(-1);
const int INF = INT_MAX;
const long long LLINF = 1000000000000000000LL;
const long long MAX = 200005;
const long long MOD = 998244353;
long long N;
long long A[MAX];
long long gcd(long long a, long long b) {
  if (a > b) {
    swap(a, b);
  }
  if (a == 0) return b;
  return gcd(b % a, a);
}
void solve() {
  cin >> N;
  for (int i = 0; i < N; i++) {
    cin >> A[i];
  }
  long long x = 0;
  for (int j = 0; j <= 30; j++) {
    long long cnt = 0;
    for (int i = 0; i < N; i++) {
      if ((A[i] >> j) & 1) {
        ++cnt;
      }
    }
    x = gcd(x, cnt);
  }
  for (int i = 1; i <= N; i++) {
    if (x % i == 0) {
      cout << i << " ";
    }
  }
  cout << "\n";
}
int main() {
  std::ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);
  ;
  int tc;
  cin >> tc;
  while (tc--) {
    solve();
  }
  return 0;
}
