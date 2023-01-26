#include <bits/stdc++.h>
using namespace std;
const long long mod = 1e9 + 7;
long long a[100007];
signed main() {
  long long t;
  cin >> t;
  while (t--) {
    long long n;
    string s;
    cin >> n >> s;
    string s1;
    cin >> s1;
    long long flag = 0;
    long long j = -1;
    for (long long i = 0; i < s1.size(); i++) {
      if (s1[i] != s[0]) {
        flag = 1;
        j = i;
        break;
      }
    }
    long long po = -1;
    for (long long i = n / 2; i < n; i++) {
      if (s1[i] == s[0]) {
        po = i + 1;
        break;
      }
    }
    if (po != -1) {
      cout << 1 << endl << po << endl;
      continue;
    }
    if (flag == 0) {
      cout << 0 << endl;
      continue;
    }
    if (j == s1.size() - 1) {
      cout << 1 << endl;
      cout << n - 1 << endl;
      continue;
    }
    if (s1[s1.size() - 1] == s[0]) {
      cout << 1 << endl << n << endl;
      continue;
    }
    cout << 2 << endl << n - 1 << " " << n << endl;
  }
}
