#include <bits/stdc++.h>
using namespace std;
#pragma GCC optimize("Ofast")
#pragma GCC optimize("unroll-loops")
using Vi = vector<int>;
using i64 = long long;
using ll = long long;
using Pi = pair<int, int>;
mt19937 mrand(time(0));
int rnd(int x) { return mrand() % x; }
const int N = 500005;
const int M = 40005;
int n;
Vi a, ans;
void soll(int x) {
  if (x > 1) {
    if (a[x] + a[x - 1] + a[x - 2] == 2) {
      ans.push_back(x - 2);
      a[x - 1] = a[x - 2] = a[x] = 0;
    }
    soll(x - 1);
  }
};
void solr(int x) {
  if (x < n - 2) {
    if (a[x] + a[x + 1] + a[x + 2] == 2) {
      ans.push_back(x);
      a[x] = a[x + 1] = a[x + 2] = 0;
    }
    solr(x + 1);
  }
};
int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  int T;
  cin >> T;
  while (T--) {
    cin >> n;
    a.resize(n);
    for (int i = 0; i < n; ++i) cin >> a[i];
    int l = 1000000001, r = -1;
    for (int i = 0; i < n; ++i)
      if (a[i]) l = min(l, i), r = max(r, i);
    if (r == -1) {
      cout << "YES" << endl << "0" << endl;
      continue;
    }
    for (int i = l; i < r - 1; ++i)
      if (a[l] == 1 && a[l + 1] == 0 && a[l + 2] == 0) a[l + 1] = a[l + 2] = 1;
    int zeros = 0;
    for (int i = l; i < r + 1; ++i)
      if (a[i] == 0) ++zeros;
    if ((zeros == 0 && l == 0 && r == n - 1) || ((r - l + 1 - zeros) & 1)) {
      cout << "NO" << endl;
      continue;
    }
    ans.clear();
    if (a[0] == 0)
      solr(0);
    else if (a[n - 1] == 0)
      soll(n - 1);
    else {
      int ones = 0;
      for (int i = 0; i < n; ++i) {
        if (a[i] == 0) {
          if (ones & 1) {
            ans.push_back(i - 1);
            a[i - 1] = a[i + 1] = 0;
            soll(i - 1);
            solr(i + 1);
          } else {
            ans.push_back(i - 2);
            a[i - 2] = a[i - 1] = 0;
            soll(i - 2);
            solr(i);
          }
          break;
        }
        ++ones;
      }
    }
    cout << "YES" << endl << (int)ans.size() << endl;
    for (auto i : ans) cout << i + 1 << " ";
    cout << endl;
  }
  return 0;
}
