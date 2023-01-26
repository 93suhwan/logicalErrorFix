#include <bits/stdc++.h>
using namespace std;
int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  cout.tie(0);
  int t;
  cin >> t;
  while (t--) {
    int n;
    cin >> n;
    vector<int> a(n);
    for (long long i = 0; i < (n); i++) {
      cin >> a[i];
    }
    sort(a.begin(), a.end());
    for (int i = 0, j = n - 1; i < j; i++, j--) {
      if ((a[i] + a[j]) % 2 == 0) {
        int cur = (a[i] + a[j]) / 2;
        a[i] = cur;
        a[j] = cur;
      } else {
        int cur = (a[i] + a[j]) / 2;
        a[i] = cur;
        a[j] = cur + 1;
      }
    }
    cout << *max_element(a.begin(), a.end()) - *min_element(a.begin(), a.end())
         << '\n';
  }
  return 0;
}
