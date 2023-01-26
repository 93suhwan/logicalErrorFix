#include <bits/stdc++.h>
using namespace std;
using ll = long long int;
using vl = vector<ll>;
using vvl = vector<vector<ll>>;
using vb = vector<bool>;
using vs = vector<string>;
using mll = map<ll, ll>;
using mlb = map<ll, bool>;
using mcl = map<char, ll>;
using msl = map<string, ll>;
using sl = stack<ll>;
using ql = queue<ll>;
using stl = set<ll>;
using stc = set<char>;
using sts = set<string>;
using pll = pair<ll, ll>;
using pql = priority_queue<ll>;
using rpql = priority_queue<ll, vector<ll>, greater<ll>>;
vector<string> p2;
void testCase() {
  string s;
  cin >> s;
  int n = ((int)(s.size()));
  ll ans = LONG_LONG_MAX;
  for (ll i = (0); i < (((int)(p2.size()))); i++) {
    int a = 0;
    int b = 0;
    int m = ((int)(p2[i].size()));
    while (a < n && b < m) {
      if (s[a] == p2[i][b]) b++;
      a++;
    }
    ll t = abs(n - b) + (m - b);
    ans = min(ans, t);
  }
  cout << ans << "\n";
}
int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  ;
  unsigned long long ans = 1;
  p2.push_back("1");
  for (ll i = (1); i < (63); i++) {
    ans = ans << 1;
    string s;
    unsigned long long t = ans;
    while (t > 0) {
      int r = t % 10;
      s.push_back(r + '0');
      t = t / 10;
    }
    reverse(s.begin(), s.end());
    p2.push_back(s);
  }
  ll t;
  cin >> t;
  while (t--) testCase();
  return 0;
}
