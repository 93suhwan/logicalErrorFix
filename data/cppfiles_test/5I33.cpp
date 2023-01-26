#include <bits/stdc++.h>
using namespace std;
void hrithik() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);
}
int main() {
  hrithik();
  long long int t;
  cin >> t;
  while (t--) {
    long long n, i;
    cin >> n;
    string a, b;
    cin >> a;
    cin >> b;
    long long ans = 0;
    for (i = 0; i < n; i++) {
      if (b[i] == '1' && a[i] == '0') {
        ans++;
      } else if (i < n - 1 && b[i] == '1' && a[i + 1] == '1') {
        ans++;
      } else if (i > 0 && b[i] == '1' && a[i - 1] == '1') {
        ans++;
      }
    }
    cout << ans << "\n";
  }
  return 0;
}
