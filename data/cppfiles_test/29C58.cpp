#include <bits/stdc++.h>
using namespace std;
struct FT {
  vector<long long> s;
  FT(int n) : s(n) {}
  void update(int pos, long long dif) {
    for (; pos < (int)(s).size(); pos |= pos + 1) s[pos] += dif;
  }
  long long query(int pos) {
    long long res = 0;
    for (; pos > 0; pos &= pos - 1) res += s[pos - 1];
    return res;
  }
  long long query(int l, int r) { return query(r) - query(l); }
};
int main() {
  cin.tie(0)->sync_with_stdio(0);
  cin.exceptions(cin.failbit);
  int n;
  cin >> n;
  vector<int> a(n);
  for (int i = 0; i < (n); ++i) cin >> a[i];
  int MAX_A = *(max_element(begin(a), end(a)));
  FT A(MAX_A + 1);
  FT B(MAX_A + 1);
  long long p = 0;
  long long pref_sum = 0;
  for (int i = 0; i < n; i++) {
    p += pref_sum;
    p += (long long)i * a[i];
    p -= A.query(a[i] + 1);
    for (int j = a[i]; j <= MAX_A; j += a[i]) {
      int l = j, r = min(MAX_A + 1, j + a[i]);
      p -= B.query(l, r) * j;
      A.update(l, a[i]);
    }
    B.update(a[i], 1);
    cout << p << " ";
    pref_sum += a[i];
  }
  return 0;
}
