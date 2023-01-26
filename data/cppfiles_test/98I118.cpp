#include <bits/stdc++.h>
using namespace std;
const int N = 3e5 + 10;
using namespace std;
void jivan() {
  long long n;
  cin >> n;
  string s;
  cin >> s;
  long long ct1 = 0, ct2 = 0;
  bool f = 1;
  char ch = s[0];
  if (n == 1)
    cout << -1 << " " << -1 << endl;
  else {
    for (long long i = 0; i < n; i++) {
      if (i == 0) continue;
      if (s[i] != ch) {
        cout << i << " " << i + 1 << endl;
        f = 0;
        break;
      }
    }
    if (f == 1) cout << -1 << " " << -1;
  }
}
int main() {
  long long t;
  cin >> t;
  while (t--) jivan();
  return 0;
}
