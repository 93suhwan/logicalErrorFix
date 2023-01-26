#include <bits/stdc++.h>
using namespace std;
void fast() {
  ios::sync_with_stdio(false);
  cin.tie(0);
}
void testcase() {
  int n;
  cin >> n;
  std::deque<int> a(n);
  for (int i = 0; i < n; i++) {
    cin >> a[i];
  }
  sort(a.rbegin(), a.rend());
  for (int i = 0; i < n; i++) {
    for (int j = i + 1; j < n; j++) {
      if (abs(a[i] - a[j]) > 1) {
        long long z = a[i] - a[j];
        a[i] -= z - 1;
        a[j] += z - 1;
      }
    }
  }
  sort(a.rbegin(), a.rend());
  cout << a[0] - a[n - 1] << "\n";
}
int main() {
  fast();
  int t;
  cin >> t;
  while (t--) {
    testcase();
  }
  return 0;
}
