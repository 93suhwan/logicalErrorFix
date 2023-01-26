#include <bits/stdc++.h>
using namespace std;
const int N = 3e5 + 5;
long long t, n, anss, ans, bal, sum, m, k, ver, idx, idx1;
vector<long long> v;
string second[N];
long long tetr, shav, mwvn, wit;
int get(char ch) { return (int)(ch - 'a' + 1); }
int main() {
  cin >> t;
  while (t--) {
    cin >> n >> m >> k;
    ans = 0;
    tetr = 0;
    shav = 0;
    mwvn = 0;
    wit = 0;
    if (!n % 2 && !m % 2 && !k % 2) {
      cout << "YES" << endl;
      continue;
    }
    if (!n % 2 && !m % 2 && k % 2 == 1) {
      cout << "NO" << endl;
      continue;
    }
    idx = idx1 = 0;
    for (int i = 1; i <= n; i++) {
      if (i % 2 == 1) {
        if (idx)
          tetr += m / 2, shav += (m + 1) / 2, idx = 0;
        else
          tetr += (m + 1) / 2, shav += (m / 2), idx = 1;
      }
      if (i % 2 == 0) {
        if (idx1)
          mwvn += m / 2, wit += (m + 1) / 2, idx1 = 0;
        else
          mwvn += (m + 1) / 2, wit += (m / 2), idx1 = 1;
      }
    }
    if (abs(tetr - mwvn) % 2 == k % 2) {
      cout << "YES" << endl;
    } else
      cout << "NO" << endl;
  }
}
