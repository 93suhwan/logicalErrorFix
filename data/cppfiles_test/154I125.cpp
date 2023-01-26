#include <bits/stdc++.h>
using namespace std;
const int INF = 1000000007;
const int N = 150000;
int main() {
  ios_base ::sync_with_stdio(0);
  cin.tie(0);
  int T;
  cin >> T;
  while (T--) {
    int a, b, c;
    cin >> a >> b >> c;
    if ((a + b + c) % 2 == 0) {
      cout << "Yes"
           << "\n";
    } else
      cout << "No"
           << "\n";
  }
  return 0;
}
