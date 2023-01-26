#include <bits/stdc++.h>
using namespace std;
int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(0);
  cout.tie(0);
  int t;
  cin >> t;
  while (t--) {
    bool checker = true;
    bool chuj = false;
    long long sol = 0;
    int n;
    cin >> n;
    vector<int> a(n);
    for (int i = 0; i < n; i++) {
      cin >> a[i];
    }
    int x = 1;
    for (int x = 0; !is_sorted(a.begin(), a.end()); x++) {
      sol++;
      for (int i = x & 1; i + 1 < n; i += 2) {
        if (a[i] > a[i + 1]) {
          swap(a[i], a[i + 1]);
        }
      }
    }
    cout << sol << "\n";
  }
}
