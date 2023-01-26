#include <bits/stdc++.h>
using namespace std;
constexpr long long N = 1000120;
constexpr long long D = 200;
constexpr double EPS = 1e-7;
ofstream fout;
ifstream fin;
long long n, m, sz;
long long k = 0, op;
int fl;
void solve() {
  long long a, c, b, d;
  string s;
  vector<int> v(30, 0);
  cin >> s;
  for (auto &x : (s)) v[x - 'a']++;
  c = 0;
  vector<int> res(30, -1);
  vector<int> ans;
  for (auto &x : (v))
    if (x) c++;
  d = c;
  vector<int> t(v);
  n = s.length();
  for (long long i = (n - 1); i >= (0); i--) {
    if (v[s[i] - 'a'])
      res[s[i] - 'a'] = c--, ans.push_back(s[i] - 'a'), v[s[i] - 'a'] = 0;
  }
  for (long long i = 0; i < (n); i++) {
    fl = 1;
    v[s[i] - 'a']++;
    for (long long i = 0; i < (30); i++)
      if (t[i] % res[i] != 0 || t[i] / res[i] != v[i]) fl = 0;
    k = i;
    if (fl) {
      break;
    }
  }
  reverse(ans.begin(), ans.end());
  string r;
  for (long long i = 0; i < (k + 1); i++) r.push_back(s[i]);
  int y = (k != n - 1 || d == 1);
  a = 0;
  int u = 0, o = k + 1;
  for (long long i = 0; i < (n); i++) {
    if (s[i] == r[a])
      a++;
    else {
      y = 0;
      break;
    }
    if (a == o) {
      string e;
      for (auto &x : (r))
        if (x != ans[u] + 'a') e.push_back(x);
      r = e;
      u++;
      a = 0;
      o = r.size();
    }
  }
  if (!y) {
    cout << "-1\n";
    return;
  }
  for (long long i = 0; i < (k + 1); i++) cout << s[i];
  cout << " ";
  for (auto &x : (ans)) cout << char(x + 'a');
  cout << "\n";
}
signed main(int argc, char *argv[]) {
  ios::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);
  cout.precision(14);
  cout.fixed;
  int t = 1;
  srand(time(0));
  cin >> t;
  while (t--) {
    solve();
  }
  fout.close();
  fin.close();
}
