#include <bits/stdc++.h>
using namespace std;
const int N = 1e5 + 5;
long long s[N], a[N];
void solve() {
  int n;
  cin >> n;
  long long sum = 0;
  for (int i = 0; i < n; i++) {
    cin >> s[i];
    sum += s[i];
  }
  long long c = 1LL * n * (n + 1) / 2;
  if (sum % c) {
    cout << "NO\n";
    return;
  }
  sum /= c;
  for (int i = 0; i < n; i++) {
    long long T = s[(i + 1) % n] - s[i];
    if ((sum - T) % n) {
      cout << "NO\n";
      return;
    }
    a[(i + 1) % n] = (sum - T) / n;
    if (a[(i + 1) % n] <= 0) {
      cout << "NO\n";
      return;
    }
  }
  cout << "YES\n";
  for (int i = 0; i < n; i++) cout << a[i] << " ";
  cout << "\n";
}
int main() {
  ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);
  int tc;
  cin >> tc;
  while (tc--) {
    solve();
  }
}
