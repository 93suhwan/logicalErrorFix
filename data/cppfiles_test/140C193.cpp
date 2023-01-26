#include <bits/stdc++.h>
#pragma GCC optimize("03")
static const long long INFL = 0x3f3f3f3f3f3f3f3fLL;
using namespace std;
int main() {
  long long int t;
  cin >> t;
  while (t--) {
    long long int n;
    cin >> n;
    set<long long int> a;
    for (int i = 1; i * i <= n; i++) {
      a.insert(i * i);
    }
    for (int i = 1; i * i * i <= n; i++) {
      a.insert(i * i * i);
    }
    cout << a.size();
    cout << endl;
  }
  return 0;
}
