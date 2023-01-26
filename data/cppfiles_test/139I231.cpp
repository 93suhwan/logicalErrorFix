#include <bits/stdc++.h>
using namespace std;
int main() {
  long long t;
  cin >> t;
  for (int i = 0; i < t; i++) {
    long long n;
    cin >> n;
    set<long long> ans;
    for (long long l = 1; l * l <= n; l++) {
      ans.insert(l * l);
      if (l * l * l <= n) {
        ans.insert(l * l * l);
      }
    }
    cout << ans.size() << endl;
  }
}
