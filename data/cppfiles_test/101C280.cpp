#include <bits/stdc++.h>
using namespace std;
const int mm = 2e5 + 100;
long long int d[mm];
long long int n, m;
vector<long long int> v0, v1;
int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  long long int i, j, t, a, b, c, p, k, kk;
  cin >> t;
  while (t--) {
    cin >> n;
    v0.clear();
    v1.clear();
    for (i = 1; i <= n; i++) cin >> d[i];
    string s;
    cin >> s;
    for (i = 0; i < s.size(); i++) {
      if (s[i] == 'B') {
        v0.push_back(d[i + 1]);
      } else {
        v1.push_back(d[i + 1]);
      }
    }
    sort(v0.begin(), v0.end());
    sort(v1.begin(), v1.end());
    p = 0;
    for (i = 0; i < v0.size(); i++) {
      if (v0[i] < i + 1) {
        p = 1;
      }
    }
    for (i = 0; i < v1.size(); i++) {
      if (n - v1[i] + 1 < (long long int)v1.size() - (i + 1) + 1) {
        p = 1;
      }
    }
    if (p)
      cout << "NO" << endl;
    else
      cout << "YES" << endl;
  }
}
