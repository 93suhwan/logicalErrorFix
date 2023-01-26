#include <bits/stdc++.h>
using namespace std;
const int inf = 1e9 + 10;
void test_case() {
  int n;
  cin >> n;
  if (n == 1) {
    cout << 1 << " " << 0 << "\n";
    return;
  }
  if (n == 2) {
    cout << 0 << " " << 1 << "\n";
    return;
  }
  int ok = n / 3;
  if (n % 3 == 1)
    cout << ok + 1 << " " << ok << "\n";
  else if (n % 3 == 2)
    cout << ok << " " << ok + 1 << "\n";
  else
    cout << ok << " " << ok << "\n";
}
int32_t main(int argc, char** gv) {
  ios_base::sync_with_stdio(false);
  cin.tie(0);
  int t;
  cin >> t;
  while (t--) test_case();
}
