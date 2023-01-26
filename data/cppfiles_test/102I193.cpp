#include <bits/stdc++.h>
#pragma GCC optimize("Ofast")
#pragma GCC target("avx,avx2,fma")
#pragma GCC optimization("unroll-loops")
using namespace std;
const long double Pi = 3.141592653;
const long long mod = 1e9 + 7;
long long INF = 1000000000000000000;
struct mycmp {
  bool operator()(pair<int, int> a, pair<int, int> b) const {
    return (a.first < b.first) || (a.first == b.first && a.second > b.second);
  }
};
int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);
  int t = 1;
  cin >> t;
  while (t--) {
    long long n, m;
    cin >> n >> m;
    string s;
    cin >> s;
    long long x = 1, y = 1;
    vector<long long> xv, yv;
    long long x_min = 1, x_max = 1;
    long long y_min = 1, y_max = 1;
    for (int i = 0; i < s.length(); i++) {
      int cnt = 0;
      if (s[i] == 'U')
        --x, ++cnt;
      else if (s[i] == 'D')
        ++x, ++cnt;
      else if (s[i] == 'R')
        ++y, --cnt;
      else
        --y, --cnt;
      if (cnt > 0)
        xv.push_back(x);
      else
        yv.push_back(y);
      x_min = min(x_min, x);
      x_max = max(x, x_max);
      y_min = min(y_min, y);
      y_max = max(y_max, y);
    }
    sort(xv.begin(), xv.end());
    sort(yv.begin(), yv.end());
    long long cnt = 0, xfin = 1;
    for (int i = 1; i <= n; i++) {
      int j = upper_bound(xv.begin(), xv.end(), n - i + 1) - xv.begin();
      int h = upper_bound(xv.begin(), xv.end(), -i + 1) - xv.begin();
      if (j - h > cnt) {
        cnt = j - h;
        xfin = i;
      }
    }
    cnt = 0;
    long long yfin = 1;
    for (int i = 1; i <= m; i++) {
      int j = upper_bound(yv.begin(), yv.end(), m - i + 1) - yv.begin();
      int h = upper_bound(yv.begin(), yv.end(), -i + 1) - yv.begin();
      if (j - h > cnt) {
        cnt = j - h;
        yfin = i;
      }
    }
    cout << xfin << " " << yfin << "\n";
  }
}
