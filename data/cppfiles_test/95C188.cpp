#include <bits/stdc++.h>
#pragma GCC optimize("O3")
#pragma GCC target("sse,sse2,sse3,ssse3,sse4,popcnt,abm,mmx")
const long long MAXN = 1e6 + 10;
const long long INF = 1e17;
const long long mod = 1000000007;
const long double eps = 1e-12;
using namespace std;
using cd = complex<double>;
auto seed = chrono::high_resolution_clock ::now().time_since_epoch().count();
mt19937_64 mt_rand(seed);
int n;
string s;
void solve(long long tta) {
  cin >> s >> n;
  reverse(s.begin(), s.end());
  vector<int> q;
  int pp = 1;
  for (int i = 0; i < s.size(); i++) {
    for (int j = 1; j <= s[i] - '0'; j++) q.push_back(pp);
    pp *= 10;
  }
  while (q.size() > n) {
    int t = q.back();
    q.pop_back();
    q.back() += t;
  }
  reverse(q.begin(), q.end());
  vector<int> p;
  while (q.size() + p.size() < n) {
    int t = q.back();
    q.pop_back();
    int val = t / 10;
    if (val)
      for (int i = 0; i < 9 && q.size() + p.size() + 1 < n; i++) {
        p.push_back(val);
        t -= val;
      }
    p.push_back(t);
    while (p.size() && p.back() >= 10) {
      q.push_back(p.back());
      p.pop_back();
    }
  }
  for (int i = 0; i < p.size(); i++) q.push_back(p[i]);
  for (int i = 0; i < q.size(); i++) cout << q[i] << " ";
  cout << "\n";
}
int main() {
  srand(time(NULL));
  ios::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);
  long long t;
  t = 1;
  cin >> t;
  cout << fixed << setprecision(10);
  for (long long i = 0; i < t; i++) {
    solve(i + 1);
  }
  return 0;
}
