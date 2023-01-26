#include <bits/stdc++.h>
using namespace std;
const long long N = 1e6;
long long a[N];
signed main() {
  long long T;
  cin >> T;
  while (T--) {
    long long n;
    cin >> n;
    string stl, str;
    cin >> stl >> str;
    bool f = 0;
    for (long long i = 0; i < n; i++) {
      if (stl[i] == '1' && str[i] == '1') f = 1;
    }
    if (f)
      cout << "NO" << endl;
    else
      cout << "YES" << endl;
  }
}
