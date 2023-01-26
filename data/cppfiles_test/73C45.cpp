#include <bits/stdc++.h>
using namespace std;
int testCase;
void solve() {
  long long n;
  cin >> n;
  vector<int> a(n);
  for (int i = 0; i < n; i++) cin >> a[i];
  ;
  int c = 0;
  while (!is_sorted(a.begin(), a.end())) {
    for (int i = c % 2; i < n - 1; i += 2) {
      if (a[i] > a[i + 1]) {
        swap(a[i], a[i + 1]);
      }
    }
    c++;
  }
  cout << c;
}
int main() {
  cin >> testCase;
  while (testCase--) {
    solve();
    cout << "\n";
  }
  return 0;
}
