#include <bits/stdc++.h>
using namespace std;
void yes() {
  cout << "Yes"
       << "\n";
}
void no() {
  cout << "No"
       << "\n";
}
const long long MAXN = 1e5 + 5, MOD = 1e9 + 7, INF = 1e18;
void solve() {
  int n;
  cin >> n;
  long long sum = 0;
  for (int i = 0; i < n; i++) {
    int x;
    cin >> x;
    sum += x;
  }
  cout << (sum % n == 0 ? 0 : 1) << "\n";
}
int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  int T = 1;
  cin >> T;
  for (; T; T--) solve();
}
