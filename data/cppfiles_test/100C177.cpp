#include <bits/stdc++.h>
using namespace std;
const long long mod = 1e9 + 7;
int main() {
  int tc;
  cin >> tc;
  for (; tc--;) {
    int n;
    cin >> n;
    vector<long long> a(n);
    for (int i = 0; i < n; i++) cin >> a[i];
    sort(a.rbegin(), a.rend());
    long long diff = 0;
    long long mx = a.back();
    for (; a.size() > 1;) {
      long long getA = a[a.size() - 2], getB = a.back();
      long long hapus = a.back() + diff;
      a.pop_back();
      diff -= hapus;
      mx = max(mx, a.back() + diff);
    }
    cout << mx << endl;
  }
  return 0;
}
