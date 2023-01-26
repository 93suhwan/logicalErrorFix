#include <bits/stdc++.h>
using namespace std;
const long long mxlli = 1e18;
const int mod = 1e9 + 7;
const int msize = 2e5 + 2;
int solv() {
  int n, i;
  cin >> n;
  string s;
  cin >> s;
  long long p = 0;
  for (i = 0; i < n; i++) {
    if (s[i] > '0' && i != n - 1) {
      p++;
    }
    p += s[i] - '0';
  }
  cout << p << "\n";
  return 0;
}
int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  int testcases = 1;
  cin >> testcases;
  while (testcases--) {
    solv();
  }
}
