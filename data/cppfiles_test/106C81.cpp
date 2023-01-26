#include <bits/stdc++.h>
using namespace std;
int lwb(vector<int>& a, int b) {
  return int(lower_bound((a).begin(), (a).end(), b) - a.begin());
}
int upb(vector<int>& a, int b) {
  return int(upper_bound((a).begin(), (a).end(), b) - a.begin());
}
long long updiv(long long a, long long b) {
  return a / b + ((a ^ b) > 0 && a % b);
}
long long downdiv(long long a, long long b) {
  return a / b - ((a ^ b) < 0 && a % b);
}
void solve() {
  int n;
  cin >> n;
  if (n == 1) {
    cout << "1"
         << "\n";
    return;
  }
  if (n == 2) {
    cout << "2 3"
         << "\n";
    return;
  }
  for (int i = 2; i <= n + 1; i++) cout << i << " ";
  cout << "\n";
}
int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);
  cout.flush();
  int t = 1;
  cin >> t;
  while (t--) {
    solve();
  }
  return 0;
}
