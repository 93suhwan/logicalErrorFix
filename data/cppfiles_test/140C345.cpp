#include <bits/stdc++.h>
using namespace std;
int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  long long t;
  cin >> t;
  while (t--) {
    long long n;
    cin >> n;
    set<long long> ans;
    for (int i = 1; i * i <= n; i++) {
      ans.insert(i * i);
    }
    for (int i = 1; i * i * i <= n; i++) {
      ans.insert(i * i * i);
    }
    cout << ans.size() << endl;
  }
  return 0;
}
