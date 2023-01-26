#include <bits/stdc++.h>
using namespace std;
class Offset {
 public:
  multiset<long long> st;
  long long delta;
  long long fetch() { return (*st.begin()) + delta; }
  void decrease(long long x) { delta -= x; }
  void add(long long x) { st.insert(x - delta); }
  void rem() { st.erase(st.begin()); }
};
int32_t main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  long long tt;
  cin >> tt;
  while (tt--) {
    long long n;
    cin >> n;
    vector<long long> a(n);
    for (long long i = 0; i < n; i++) {
      cin >> a[i];
    }
    multiset<long long> ms(a.begin(), a.end());
    Offset obj;
    for (long long i = 0; i < n; i++) {
      obj.add(a[i]);
    }
    sort(a.begin(), a.end());
    long long res = a[0];
    for (long long i = 0; i < n; i++) {
      long long temp = obj.fetch();
      res = max(res, temp);
      obj.decrease(temp);
      obj.rem();
    }
    cout << res << '\n';
  }
  return 0;
}
