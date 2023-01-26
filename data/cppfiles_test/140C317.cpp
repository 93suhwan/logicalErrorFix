#include <bits/stdc++.h>
using namespace std;
const long double PI = 2 * acos(0.0);
const int MOD = 1e9 + 7;
const int MAXN = 2e5 + 5;
int main() {
  int t;
  cin >> t;
  while (t > 0) {
    int n;
    cin >> n;
    set<int> a;
    for (int i = 1; i * i <= n; i++) a.insert(i * i);
    for (int i = 1; i * i * i <= n; i++) a.insert(i * i * i);
    cout << a.size() << endl;
    t--;
  }
  return 0;
}
