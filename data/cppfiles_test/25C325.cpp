#include <bits/stdc++.h>
using namespace std;
bool cmp(long long a, long long b) { return a > b; }
int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);
  long long n, m, i, j, t;
  cin >> t;
  while (t--) {
    string s, t, dup = "", dup1 = "";
    cin >> s >> t;
    n = s.size();
    long long ts = t.size();
    long long k;
    long long f = 0;
    for (i = 0; i < n; i++) {
      dup = "";
      for (j = i; j < n; j++) {
        dup += s[j];
        string dup1 = dup;
        if (dup1 == t) {
          f = 1;
          break;
        }
        for (k = j - 1; k >= 0; k--) {
          dup1 += s[k];
          if (dup1 == t) {
            f = 1;
            break;
          }
        }
      }
    }
    if (f)
      cout << "YES" << endl;
    else
      cout << "NO" << endl;
  }
}
