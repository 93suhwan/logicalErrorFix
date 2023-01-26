#include <bits/stdc++.h>
using namespace std;
int main() {
  int t;
  cin >> t;
  while (t--) {
    int k;
    cin >> k;
    int cnt = 0;
    vector<int> v;
    for (int i = 1; i <= (k + cnt); i++) {
      if (i % 10 == 3 || i % 3 == 0)
        cnt++;
      else
        v.push_back(i);
    }
    if (v.size() >= k) cout << v.back() << "\n";
  }
  return 0;
}
