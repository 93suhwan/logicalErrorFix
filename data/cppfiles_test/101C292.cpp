#include <bits/stdc++.h>
using namespace std;
int main() {
  long long t;
  cin >> t;
  while (t--) {
    long long n;
    cin >> n;
    pair<char, long long> p[n];
    for (long long i = 0; i < n; i++) cin >> p[i].second;
    string s;
    cin >> s;
    for (long long i = 0; i < n; i++) {
      p[i].first = s[i];
    }
    sort(p, p + n);
    bool ok = true;
    for (long long i = 0; i < n; i++) {
      if ((p[i].first == 'B' && p[i].second < i + 1) ||
          (p[i].first == 'R' && p[i].second > i + 1))
        ok = false;
    }
    if (ok)
      cout << "YES\n";
    else
      cout << "NO\n";
  }
}
