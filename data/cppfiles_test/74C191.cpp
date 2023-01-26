#include <bits/stdc++.h>
using namespace std;
int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  long long t = 100;
  cin >> t;
  while (t--) {
    long long a, b;
    cin >> a >> b;
    if (a > b) {
      swap(a, b);
    }
    set<long long> ans;
    if ((a + b) % 2 == 1) {
      ans.insert((a + b) / 2);
      ans.insert((a + b) / 2 + 1);
      for (long long i = (a + b) / 2 + 2, cnt = 0; cnt < a; cnt++, i++) {
        ans.insert(i);
      }
      for (long long i = (a + b) / 2 - 1, cnt = 0; cnt < a; cnt++, i--) {
        ans.insert(i);
      }
    } else {
      long long x = (a + b) / 2;
      for (long i = x - a; i <= x + a; i += 2) {
        ans.insert(i);
      }
    }
    cout << ans.size() << "\n";
    for (long long x : ans) {
      cout << x << " ";
    }
    cout << "\n";
  }
}
