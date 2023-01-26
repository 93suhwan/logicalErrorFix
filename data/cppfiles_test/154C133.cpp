#include <bits/stdc++.h>
#pragma comment(linker, "/STACK:102400000,102400000")
const int INF = 0x7fffffff;
const double PI = 3.14159265359;
using namespace std;
int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  cout.tie(0);
  int t;
  cin >> t;
  while (t--) {
    int flag = 0;
    int l1, l2, l3;
    cin >> l1 >> l2 >> l3;
    if (l1 == l2 + l3) flag = 1;
    if (l2 == l1 + l3) flag = 1;
    if (l3 == l1 + l2) flag = 1;
    if (l1 == l2 && l3 % 2 == 0) flag = 1;
    if (l2 == l3 && l1 % 2 == 0) flag = 1;
    if (l1 == l3 && l2 % 2 == 0) flag = 1;
    if (l1 == 0 || l2 == 0 || l3 == 0) flag = 0;
    if (flag == 1)
      cout << "YES"
           << "\n";
    else
      cout << "NO"
           << "\n";
  }
}
