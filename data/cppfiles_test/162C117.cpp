#include <bits/stdc++.h>
using namespace std;
template <class A, class B>
ostream& operator<<(ostream& out, const pair<A, B>& p) {
  return out << "(" << p.first << ", " << p.second << ")";
}
template <class A>
ostream& operator<<(ostream& out, const vector<A>& v) {
  out << "[";
  for (int i = 0; i < int((v).size()); i++) {
    if (i) out << ", ";
    out << v[i];
  }
  return out << "]";
}
bool check(vector<long long>& a, long long tar) {
  vector<long long> r((a).begin(), (a).end());
  for (int i = int((a).size()) - 1; i >= 2; i--) {
    long long tt = max(0ll, min((r[i] - tar) / 3, a[i] / 3));
    r[i - 1] += tt;
    r[i - 2] += 2 * tt;
    r[i] -= 3 * tt;
  }
  bool res = 1;
  for (int i = 0; i < int((r).size()); i++) res &= r[i] >= tar;
  return res;
}
void solve() {
  int n;
  cin >> n;
  vector<long long> a(n);
  for (long long& i : a) cin >> i;
  long long l = 0, r = 1e9;
  long long mid, res = -1;
  while (l <= r) {
    mid = l + (r - l) / 2;
    if (check(a, mid))
      l = mid + 1, res = mid;
    else
      r = mid - 1;
  }
  cout << res << endl;
}
int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);
  int t;
  cin >> t;
  while (t--) {
    solve();
  }
  return 0;
}
