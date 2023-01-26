#include <bits/stdc++.h>
using namespace std;
void speed_func() {
  cin.tie(0);
  cout.tie(0);
  ios_base::sync_with_stdio(false);
}
signed main() {
  speed_func();
  long long t;
  cin >> t;
  while (t) {
    t--;
    long long n;
    cin >> n;
    vector<long long> a(n);
    for (long long& i : a) {
      cin >> i;
    }
    long long cnt = 0;
    long long m = 0;
    for (long long i = n - 1; i > -1; i--) {
      if (a[i] > m) {
        m = a[i];
        cnt++;
      }
    }
    cout << cnt - 1 << endl;
  }
}
