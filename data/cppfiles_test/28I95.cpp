#include <bits/stdc++.h>
using namespace std;
using cd = complex<double>;
mt19937 rnd(chrono::system_clock::now().time_since_epoch().count());
long long a[300005];
int main() {
  long long q;
  cin >> q;
  while (q--) {
    long long n, m;
    cin >> n >> m;
    for (long long i = 1; i <= n; i++) {
      cin >> a[i];
    }
    map<long long, long long> p;
    for (long long i = 1; i <= n; i++) {
      long long v = i - a[i];
      if (v < 0) v += n;
      p[v]++;
    }
    vector<long long> ans;
    for (auto i : p) {
      if (i.second >= n - m * 2) {
        ans.push_back(i.first);
      }
    }
    cout << ans.size() << " ";
    for (auto i : ans) {
      cout << i << " ";
    }
    cout << endl;
  }
}
