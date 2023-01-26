#include <bits/stdc++.h>
using namespace std;
constexpr long long N = 2000050;
constexpr long long D = 2000010;
constexpr long double EPS = 1e-8;
ofstream fout;
ifstream fin;
int flag = 1;
long long n, m, k;
void solve() {
  cin >> n;
  vector<long long> v(n);
  vector<long long> t;
  for (auto &x : (v)) cin >> x, t.push_back(x);
  long long b = 0;
  for (auto &x : (v)) {
    b = max(b, x / 3);
    x %= 3;
  }
  int a = 0, c = 0;
  if (count(v.begin(), v.end(), 1)) a++;
  if (count(v.begin(), v.end(), 2)) c++;
  sort(t.begin(), t.end()),
      (t).resize(unique(t.begin(), t.end()) - (t).begin());
  reverse(t.begin(), t.end());
  b += a + c;
  if (t[0] % 3 == 1 && c && t.back() != 1) {
    if (t[1] <= t[0] - 2) b--;
  }
  if (t[0] % 3 == 0 && a && c) b--;
  cout << b << "\n";
}
signed main(signed argc, char *argv[]) {
  ios::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);
  cout.precision(9);
  cout.fixed;
  srand(time(0));
  fout.precision(14);
  fout.fixed;
  int tt = 1;
  cin >> tt;
  while (tt--) {
    solve();
  }
  fout.close();
  fin.close();
}
