#include <bits/stdc++.h>
using namespace std;
using vi = vector<int>;
using vl = vector<long long>;
using pii = pair<int, int>;
char el = '\n';
char esp = ' ';
template <class T>
bool ckmin(T& a, const T& b) {
  return b < a ? a = b, 1 : 0;
}
template <class T>
bool ckmax(T& a, const T& b) {
  return a < b ? a = b, 1 : 0;
}
ostream& operator<<(ostream& os, const vector<int>& v) {
  for (auto const& i : v) {
    os << i << " ";
  }
  os << '\n';
  return os;
}
string yes = "YES";
string no = "NO";
const int oo = 1e9 + 7;
const int N = 1e4 + 5;
int n;
int v[N];
const int maxr = 2005;
int dp[N][maxr];
int go(int i, int j) {
  if (j < 0 || j >= maxr) return oo;
  if (i == n) return j;
  int& ans = dp[i][j];
  if (ans == -1) {
    ans = max(j, min(go(i + 1, j - v[i]), go(i + 1, j + v[i])));
  }
  return ans;
}
int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);
  ;
  int tc;
  cin >> tc;
  while (tc--) {
    cin >> n;
    for (int i = 0; i < n; i++) {
      cin >> v[i];
    }
    for (int i = 0; i <= n; i++) {
      for (int j = 0; j < maxr; j++) {
        dp[i][j] = -1;
      }
    }
    int ans = oo;
    for (int i = 0; i < maxr; i++) {
      ckmin(ans, go(0, i));
    }
    cout << ans << el;
  }
}
