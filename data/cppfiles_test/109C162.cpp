#include <bits/stdc++.h>
using namespace std;
int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  long long tc;
  cin >> tc;
  while (tc--) {
    long long n, m, i, j, k, l, x, y;
    cin >> n;
    string a;
    vector<long long> b;
    cin >> a;
    long long cnt = 0, ss = 0;
    for (i = 0; i < n; i++) {
      if (a[i] - '0') {
        cnt += 1;
        b.push_back(a[i] - '0');
      }
    }
    ss = cnt;
    if (a[n - 1] - '0') ss -= 1;
    sort(b.begin(), b.end());
    for (i = 0; i < cnt; i++) {
      ss += b[cnt - i - 1];
    }
    cout << ss;
    cout << endl;
    ;
  }
}
