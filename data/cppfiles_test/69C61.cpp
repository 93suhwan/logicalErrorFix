#include <bits/stdc++.h>
using namespace std;
const int N = 20;
const int M = 60;
const int INF = 1e9;
int tc;
string n;
string val[M + 2];
int solve(string s, string t) {
  int cnt = 0;
  for (int i = 0; i < s.length() && cnt < t.length(); i++) {
    cnt += (s[i] == t[cnt]);
  }
  return s.length() + t.length() - 2 * cnt;
}
int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);
  cin >> tc;
  for (long long i = 0, pw = 1; i <= M; i++, pw *= 2) {
    val[i] = to_string(pw);
  }
  while (tc--) {
    cin >> n;
    int ans = INF;
    for (int i = 0; i <= M; i++) {
      ans = min(ans, solve(n, val[i]));
    }
    cout << ans << '\n';
  }
  return 0;
}
