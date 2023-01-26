#include <bits/stdc++.h>
using namespace std;
const long long int mod = 1e9 + 7;
const long long int mod2 = 998244353;
const long double error = 2e-6;
const long double PI = acosl(-1);
inline long long int MOD(long long int x, long long int m = mod) {
  long long int y = x % m;
  return (y >= 0) ? y : y + m;
}
const int inf = 1e9;
const long long int infl = 1061109567;
const int nmax = 1000 + 10;
void solve() {
  int n;
  cin >> n;
  std::vector<int> vc, cvc;
  map<int, int> mp, mp1;
  int i, j;
  for (i = 0; i < n; i++) {
    int xx;
    cin >> xx;
    mp[xx]++;
    mp1[xx]++;
    if (mp[xx] == 1) vc.push_back(xx);
  }
  sort(vc.begin(), vc.end());
  for (i = 0; i < vc.size(); i++) cvc.push_back(mp[vc[i]]);
  std::vector<int> ans(n + 5, -1), tpx(n + 5, 0);
  stack<int> st;
  for (i = 0; i <= n; i++) {
    if (mp[i] > 0) {
      tpx[i + 1] = tpx[i];
      mp[i]--;
      for (j = 1; j <= mp[i]; j++) st.push(i);
    } else {
      if (st.empty() == 1) {
        tpx[i + 1] = -1;
        for (j = i + 1; j <= n; j++) tpx[j + 1] = -1;
        break;
      }
      int fs = st.top();
      st.pop();
      tpx[i + 1] = tpx[i] + abs(i - fs);
    }
  }
  for (i = 0; i <= n; i++) {
    int ans = tpx[i];
    if (ans == -1)
      cout << -1 << " ";
    else
      cout << ans + mp1[i] << " ";
  }
  cout << endl;
}
int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);
  int t;
  cin >> t;
  for (int i = 1; i <= t; i++) {
    solve();
  }
}
