#include <bits/stdc++.h>
using namespace std;
using ll = long long;
void test_case(const int& _tt) {
  int n;
  cin >> n;
  vector<int> a(n);
  int maxi = 0;
  for (int i = 0; i < n; ++i) {
    cin >> a[i];
    maxi = max(maxi, a[i]);
  }
  int count = 0;
  int last = -1;
  for (int i = n - 1; i >= 0; --i) {
    if (a[i] == maxi) break;
    if (a[i] <= last) continue;
    last = a[i];
    count++;
  }
  cout << count << "\n";
}
int main() {
  cin.tie(0)->sync_with_stdio(0);
  int TT = 1;
  cin >> TT;
  for (int _tt = 1; _tt <= TT; ++_tt) {
    test_case(_tt);
  }
  return 0;
}
