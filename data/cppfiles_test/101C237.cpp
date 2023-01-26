#include <bits/stdc++.h>
using namespace std;
void solve() {
  long long int n, z;
  cin >> n;
  long long int a[n + 1];
  string s;
  vector<long long int> v1, v2;
  for (int i = 0; i < n; i++) {
    cin >> a[i];
  }
  cin >> s;
  for (int i = 0; i < n; i++) {
    if (s[i] == 'R') {
      v1.push_back(a[i]);
    } else {
      v2.push_back(a[i]);
    }
  }
  sort(v1.begin(), v1.end(), greater<long long int>());
  sort(v2.begin(), v2.end());
  for (int i = 0; i < v2.size(); i++) {
    if (v2[i] < i + 1) {
      cout << "NO\n";
      return;
    }
  }
  for (int i = 0; i < v1.size(); i++) {
    if (v1[i] > n - i) {
      cout << "NO\n";
      return;
    }
  }
  cout << "YES\n";
}
int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  int T = 1;
  cin >> T;
  while (T--) {
    solve();
  }
}
