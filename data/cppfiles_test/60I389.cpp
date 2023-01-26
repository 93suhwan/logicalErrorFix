#include <bits/stdc++.h>
using namespace std;
int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);
  int t;
  cin >> t;
  while (t--) {
    int n, a, sum = 0, res = 0;
    cin >> n;
    multiset<int> s;
    int arr[n];
    for (int i = 0; i < n; i++) {
      cin >> a;
      sum += a;
      s.insert(a);
      arr[i] = a;
    }
    double k = sum * 1.0 / n;
    if (floor(k * 2) != k * 2) {
      cout << 0 << '\n';
      continue;
    }
    sort(arr, arr + n);
    for (int i = 0; i < n; i++) {
      res += s.count(k * 2 - arr[i]);
      if (k * 2 - arr[i] == arr[i]) res -= 1;
    }
    cout << res / 2 << '\n';
  }
}
