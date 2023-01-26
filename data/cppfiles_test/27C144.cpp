#include <bits/stdc++.h>
using namespace std;
void testCase() {
  long long n, m, k;
  cin >> n >> m >> k;
  long long mostEdges = n * max((n - 1), 0LL) / 2;
  if (m < n - 1 || m > mostEdges) {
    cout << "NO" << endl;
    return;
  }
  if (k <= 1)
    cout << "NO" << endl;
  else if (k == 2)
    cout << (n == 1 ? "YES" : "NO") << endl;
  else if (k == 3)
    cout << (m == mostEdges ? "YES" : "NO") << endl;
  else
    cout << "YES" << endl;
}
int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);
  int T = 1;
  cin >> T;
  while (T--) {
    testCase();
  }
  return 0;
}
