#include <bits/stdc++.h>
using namespace std;
int a[100100];
int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  ;
  int tt;
  cin >> tt;
  while (tt--) {
    long long n;
    cin >> n;
    multiset<long long> mls;
    for (int i = 0; i < n; ++i) {
      cin >> a[i];
      mls.insert(a[i]);
    }
    long long ans = 0;
    for (int i = n; i > 0; --i) {
      if (mls.find(i) != mls.end()) {
        mls.erase(mls.find(i));
      } else {
        ans++;
        long long x = *(--mls.end());
        mls.erase(mls.find(x));
        if (2 * i >= x) {
          ans = -1;
          break;
        }
      }
    }
    cout << ans << '\n';
  }
}
