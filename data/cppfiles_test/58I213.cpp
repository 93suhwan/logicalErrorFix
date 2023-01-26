#include <bits/stdc++.h>
using namespace std;
long long int dp[1000001];
long long int dp1[1000001];
long long int inv[1000001];
void solve() {
  int n;
  cin >> n;
  string a, b;
  cin >> a >> b;
  for (int i = 0; i < n - 1; i++) {
    if (a[i] == '0' && b[i + 1] == '0') {
      cout << "YES";
      return;
    }
  }
  for (int i = n - 1; i >= 1; i--) {
    if (a[i] == '0' && b[i - 1] == '0') {
      cout << "YES";
      return;
    }
  }
  cout << "NO";
}
void read_input() {}
void case_number() {
  int t;
  cin >> t;
  for (int i = 1; i <= t; i++) {
    solve();
    cout << "\n";
  }
}
int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);
  ;
  read_input();
  case_number();
  return 0;
}
