#include <bits/stdc++.h>
using namespace std;
void solve() {
  long long n;
  cin >> n;
  long long a[n];
  long long c0 = 0;
  long long c1 = 0;
  for (int i = 0; i < n; ++i) {
    cin >> a[i];
    if (a[i] == 0) c0++;
    if (a[i] == 1) c1++;
  }
  cout << (long long)pow(2, c0) * c1 << "\n";
}
int main() {
  ios_base::sync_with_stdio(false), cin.tie(NULL), cout.tie(NULL);
  long long t = 1;
  cin >> t;
  while (t--) {
    solve();
  }
}
