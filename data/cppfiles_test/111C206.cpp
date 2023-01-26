#include <bits/stdc++.h>
using namespace std;
mt19937_64 mt(chrono::steady_clock::now().time_since_epoch().count());
inline long long S(long long n, long long i = 1, long long d = 1) {
  return n & 1 ? (2 * i + d * (n - 1)) / 2 * n : n / 2 * (2 * i + d * (n - 1));
}
inline string ctos(char c) { return string(1, c); }
inline int popcnt(long long x) {
  int ans = 0;
  for (long long i = 0; i < 64; i++)
    if ((x >> i) & 1) ans++;
  return ans;
}
const int SEED = 1e9 + 7 + 7e7;
const int SIZE = 1e5 + 17;
const int M = 1000001917;
const int LOG = 9;
const int INF = 1e9 + 17;
const long long INF2 = 9e18 + 17;
const long long NEUTRAL = -2e18;
long long a[SIZE];
vector<string> solve1(long long n) {
  vector<string> v = vector<string>();
  for (long long i = 0; i < n; i++) {
    string ans = "", ans2 = "";
    for (long long j = 0; j < n; j++) {
      if ((i >> j) & 1)
        ans = ctos(')') + ans;
      else
        ans = ctos('(') + ans;
    }
    for (long long j = 0; j < n; j++) {
      ans2 = (ans[j] == '(' ? ctos(')') : ctos('(')) + ans2;
    }
    v.push_back(ans + ans2);
  }
  return v;
}
int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  cout.tie(0);
  long long t;
  cin >> t;
  while (t--) {
    long long n;
    cin >> n;
    for (long long i = 0; i < n; i++) {
      string ans = "", ans2 = "";
      for (long long j = 0; j < n; j++) {
        if ((i >> j) & 1)
          ans = ctos(')') + ans;
        else
          ans = ctos('(') + ans;
      }
      for (long long j = 0; j < n; j++) {
        ans2 = (ans[j] == '(' ? ctos(')') : ctos('(')) + ans2;
      }
      cout << ans + ans2 << endl;
    }
  }
}
