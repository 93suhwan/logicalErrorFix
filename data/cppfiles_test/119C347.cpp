#include <bits/stdc++.h>
using namespace std;
void fast() {
  ios::sync_with_stdio(false);
  cin.tie(0);
}
void testcase() {
  int n;
  cin >> n;
  long long sum = 0;
  for (int i = 0; i < n; i++) {
    int x;
    cin >> x;
    sum += x;
  }
  if (sum % n == 0) {
    cout << 0 << "\n";
    return;
  }
  cout << 1 << "\n";
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
