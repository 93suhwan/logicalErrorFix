#include <bits/stdc++.h>
using namespace std;
int main() {
  ios_base::sync_with_stdio(false), cin.tie(NULL);
  int t;
  cin >> t;
  while (t--) {
    int n;
    cin >> n;
    int a[n], i;
    set<int> s;
    bool f = 0;
    for (i = 0; i < n; i++) {
      cin >> a[i];
      s.insert(a[i]);
      if (i != 0) {
        if (a[i] < a[i - 1]) f = 1;
      }
    }
    if (f == 0 && s.size() == n)
      cout << "NO"
           << "\n";
    else
      cout << "YES"
           << "\n";
  }
  return 0;
}
