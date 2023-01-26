#include <bits/stdc++.h>
using namespace std;
int main() {
  long long t;
  cin >> t;
  while (t--) {
    long long n;
    cin >> n;
    int a[n], b[n];
    for (int i = 0; i < n; i++) cin >> a[i];
    string s;
    cin >> s;
    vector<pair<long long, pair<long long, long long>>> c(n);
    for (int i = 0; i < n; i++) {
      c[i].second.first = a[i];
      c[i].second.second = i;
      c[i].first = (s[i] - '0');
    }
    sort(c.begin(), c.end());
    long long cnt = 1;
    for (int i = 0; i < n; i++) {
      b[c[i].second.second] = cnt;
      cnt++;
    }
    for (int i = 0; i < n; i++) {
      cout << b[i] << " ";
    }
    cout << endl;
  }
}
