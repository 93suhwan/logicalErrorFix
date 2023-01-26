#include <bits/stdc++.h>
using namespace std;
const int N = 200010, INF = 0x3f3f3f3f;
vector<int> q[10];
int main() {
  int t;
  cin >> t;
  while (t--) {
    int n, m, k;
    cin >> n >> m >> k;
    if (n % 2 == 0) {
      int sum = (n / 2) * (m / 2);
      if (k > sum * 2) {
        puts("NO");
        continue;
      } else {
        if (k % 2 == 0)
          puts("YES");
        else
          puts("NO");
      }
    } else {
      int sum = (n / 2) * (m / 2) + m / 2;
      if (k > sum * 2 || k < m / 2) {
        puts("NO");
        continue;
      } else {
        if ((k - m / 2) % 2 != 0)
          cout << "NO" << endl;
        else
          cout << "YES" << endl;
      }
    }
  }
  return 0;
}
