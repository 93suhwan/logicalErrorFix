#include <bits/stdc++.h>
using namespace std;
long long int computeXOR(long long int n) {
  if (n % 4 == 0) return n;
  if (n % 4 == 1) return 1;
  if (n % 4 == 2) return n + 1;
  return 0;
}
signed main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  long long int t;
  cin >> t;
  while (t--) {
    long long int n;
    cin >> n;
    string s;
    cin >> s;
    long long int f = 0;
    for (long long int i = 0; i < n; i++) {
      long long int a = 0;
      long long int b = 0;
      long long int j;
      for (j = i; j < n; j++) {
        if (s[j] == 'a')
          a++;
        else {
          b++;
        }
        if (a == b) {
          cout << i + 1 << " " << j + 1 << endl;
          f = 1;
          break;
        }
      }
      if (f) break;
    }
    if (f == 0) {
      cout << "-1 -1" << endl;
    }
  }
}
