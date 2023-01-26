#include <bits/stdc++.h>
#pragma pack(1)
#pragma GCC target("avx,avx2")
#pragma GCC optimization("O3")
#pragma GCC optimization("unroll-loops")
using namespace std;
int main() {
  long long int t;
  cin >> t;
  while (t--) {
    long long int n;
    cin >> n;
    string a[n - 2];
    for (long long int i = 0; i < n - 2; ++i) {
      cin >> a[i];
    }
    string s;
    s += a[0];
    for (long long int i = 1; i < n - 2; ++i) {
      if (a[i][0] != s[s.size() - 1]) {
        s += a[i];
      } else {
        s += a[i][1];
      }
    }
    while (s.size() != n) {
      s += 'a';
    }
    cout << s << endl;
  }
  return 0;
}
