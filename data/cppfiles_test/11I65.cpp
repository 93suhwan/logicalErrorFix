#include <bits/stdc++.h>
using namespace std;
const long long mod = 1e9 + 7;
const long long maxN = 300005;
const long long oo = 1e18 + 7;
long long n, a[maxN];
long long x, y, z, k;
long long indu[maxN];
inline bool comp(pair<long long, long long> p1, pair<long long, long long> p2) {
  if (p1.first != p2.first) return p1.first < p2.first;
  return p1.second > p2.second;
}
signed main() {
  ios_base::sync_with_stdio(0);
  cin.tie(NULL);
  cout.tie(NULL);
  cin >> n;
  vector<pair<long long, long long> > ele;
  for (long long i = 1; i <= n; ++i) {
    cin >> x;
    if (x <= i) {
      ele.push_back(pair<long long, long long>(x, i - x));
    }
  }
  sort(ele.begin(), ele.end(), comp);
  vector<long long> lis;
  lis.push_back(-oo);
  long long bonus = 0;
  for (pair<long long, long long> ccc : ele) {
    long long cc = bonus + ccc.second;
    ++bonus;
    if (cc > lis.back())
      lis.push_back(cc);
    else {
      x = lower_bound(lis.begin(), lis.end(), cc) - lis.begin();
      lis[x] = cc;
    }
  }
  cout << lis.size() - 1 << "\n";
}
