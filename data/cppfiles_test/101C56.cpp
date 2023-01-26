#include <bits/stdc++.h>
using namespace std;
string s;
long long n;
long long a[200005];
void solve() {
  cin >> n;
  for (int i = 1; i <= n; i++) {
    cin >> a[i];
  }
  cin >> s;
  vector<int> b, r;
  for (int i = 1; i <= n; i++) {
    if (s[i - 1] == 'B') {
      b.push_back(a[i]);
    } else if (s[i - 1] == 'R') {
      r.push_back(a[i]);
    }
  }
  sort(b.begin(), b.end());
  sort(r.begin(), r.end());
  for (int i = 0; i < b.size(); i++) {
    long long k = i + 1;
    if (k > b[i]) {
      cout << "NO" << endl;
      return;
    }
  }
  for (int i = 0; i < r.size(); i++) {
    long long k = b.size() + i + 1;
    if (k < r[i]) {
      cout << "NO" << endl;
      return;
    }
  }
  cout << "YES" << endl;
}
int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);
  int t = 1;
  cin >> t;
  while (t--) solve();
}
