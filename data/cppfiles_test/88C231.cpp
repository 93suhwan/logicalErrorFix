#include <bits/stdc++.h>
using namespace std;
const int N = 1e9;
const int mod = 1e9 + 7;
bool st[4000005];
template <typename... T>
static inline void gt(T&... args) {
  ((cin >> args), ...);
}
template <typename... T>
static inline void wt(T&&... args) {
  ((cout << args), ...);
}
template <typename... T>
static inline void wt_n(T&&... args) {
  ((cout << args), ...);
  cout << "\n";
}
long long int gcd(long long int a, long long int b) {
  if (b == 0) return a;
  return gcd(b, a % b);
}
long long int lcm(long long int a, long long int b) {
  return (a / gcd(a, b)) * b;
}
const int temp = (1 << 18);
vector<int> ht[2 * temp];
map<int, int> mp;
long long int solve3(string s) {
  string r = s;
  reverse(r.begin(), r.end());
  int sz1 = s.size();
  int dp[sz1 + 1][sz1 + 1];
  for (int i = 0; i <= sz1; i++) {
    dp[0][i] = 0;
    dp[i][0] = 0;
  }
  for (int i = 1; i <= sz1; i++) {
    for (int j = 1; j <= sz1; j++) {
      if (s[i - 1] == r[j - 1]) {
        dp[i][j] = dp[i - 1][j - 1] + 1;
      } else
        dp[i][j] = max(dp[i - 1][j], dp[i][j - 1]);
    }
  }
  return dp[sz1][sz1];
}
void solve() {
  long long int n;
  gt(n);
  long long int i;
  long long int arr[n];
  bool isComplete = false;
  for (i = 0; i < n; i++) {
    gt(arr[i]);
  }
  if (!(n % 2)) {
    wt_n("YES");
    return;
  }
  for (i = 1; i < n; i++) {
    if (arr[i - 1] >= arr[i]) {
      wt_n("YES");
      isComplete = true;
      return;
    }
  }
  if (!isComplete) {
    wt_n("NO");
  }
}
int main() {
  std::ios_base::sync_with_stdio(false);
  std ::cin.tie(0);
  ;
  long long int t;
  long long int i = 0;
  long long int cases = 1;
  std::cin >> t;
  while (t--) {
    solve();
  }
  return 0;
}
