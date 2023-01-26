#include <bits/stdc++.h>
using namespace std;
bool comp(pair<int, int> a, pair<int, int> b) { return (a.first > b.first); }
int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);
  int t;
  cin >> t;
  while (t--) {
    int n;
    cin >> n;
    vector<long long> a(n);
    for (long long i = 0; i < n; i++) cin >> a[i];
    if (n == 2) {
      if (abs(a[0] - a[1]) % 2 == 0) {
        cout << "0\n";
        continue;
      } else {
        cout << "1\n";
        continue;
      }
    }
    if (count(a.begin(), a.end(), a[0]) == n) {
      cout << 0 << "\n";
      continue;
    }
    sort(a.begin(), a.end());
    cout << abs((a[n - 1] - a[n - 2]) - a[0]) << "\n";
  }
  return 0;
}
