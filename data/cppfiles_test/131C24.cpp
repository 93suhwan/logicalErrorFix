#include <bits/stdc++.h>
using namespace std;
void solve() {
  long long n;
  cin >> n;
  vector<pair<string, long long>> a(n);
  for (long long i = 0; i < (n); i++) {
    long long x;
    cin >> x;
    a[i].second = i;
    if (x > 0) {
      long long k = 0;
      while ((x & 1LL) == 0) x >>= 1, k++;
      x >>= 1, k++;
      a[i].first.push_back((char)k);
      while (x > 0) {
        k = 0;
        long long b = x & 1LL;
        while ((x & 1LL) == b) x >>= 1, k++;
        a[i].first.push_back((char)k);
      }
    }
  }
  sort((a).begin(), (a).end());
  long long bestx, besty, bestm = -1;
  vector<pair<long long, long long>> m(32, make_pair(-1, -1));
  m[a[0].first.size()] = make_pair(a[0].first.size(), a[0].second);
  for (long long i = 1; i <= (n - 1); i++) {
    long long cp = 0;
    for (; cp < max(a[i].first.size(), a[i - 1].first.size()); cp++) {
      if (a[i].first[cp] != a[i - 1].first[cp]) break;
    }
    for (long long j = 0; j < (a[i - 1].first.size() + 1); j++) {
      long long tm = -1;
      if (m[j].first >= 0) {
        tm = a[i].first.size() + m[j].first - 2 * min(j, cp);
        if (tm > bestm) bestm = tm, bestx = m[j].second, besty = a[i].second;
      }
    }
    pair<long long, long long> mcp = make_pair(-1, -1);
    for (long long j = cp; j <= a[i - 1].first.size(); j++) {
      if (m[j].first > mcp.first) mcp = m[j];
    }
    m[cp] = mcp;
    m[a[i].first.size()] = make_pair(a[i].first.size(), a[i].second);
  }
  cout << bestx + 1 << " " << besty + 1 << " " << bestm << endl;
}
int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(0);
  ifstream ifs;
  if (""[0]) cin.rdbuf((ifs = ifstream("")).rdbuf());
  ;
  ofstream ofs;
  if (""[0]) cout.rdbuf((ofs = ofstream("")).rdbuf());
  ;
  ofstream lfs;
  if (""[0]) clog.rdbuf((lfs = ofstream("")).rdbuf());
  ;
  int t = 1;
  for (int i = 1; i <= t; i++) {
    solve();
  }
}
