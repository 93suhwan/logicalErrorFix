#include <bits/stdc++.h>
using namespace std;
void sol() {
  vector<int> x(3);
  for (int &n : x) cin >> n;
  sort(x.begin(), x.end());
  int a = x[0], b = x[1], c = x[2];
  if (a == b) {
    if (c % 2 == 0) {
      cout << "YES\n";
      return;
    }
  } else if (b == c) {
    if (a % 2 == 0) {
      cout << "YES\n";
      return;
    }
  } else {
    if (a + b == c) {
      cout << "YES\n";
      return;
    }
  }
  cout << "NO\n";
}
int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(0);
  cout.tie(0);
  int t;
  cin >> t;
  while (t--) sol();
  return 0;
}
