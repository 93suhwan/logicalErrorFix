#include <bits/stdc++.h>
using namespace std;
int main() {
  int t;
  int n;
  string a;
  int p;
  vector<int> v;
  cin >> t;
  while (t--) {
    p = 0;
    int c[26] = {0};
    cin >> n;
    cin >> a;
    for (int i = 0; i < n; i++) {
      c[a[i] - 'a']++;
    }
    for (int i = 0; i < 26; i++) {
      if (c[i] > 0) {
        p++;
      }
    }
    if (p == 1) {
      v.push_back(0);
    } else if (p % 2 > 1) {
      v.push_back(p - 1);
    } else
      v.push_back(p - (p % 2));
  }
  for (int i = 0; i < v.size(); i++) {
    cout << v[i] << "\n";
  }
  return 0;
}
