#include <bits/stdc++.h>
using namespace std;
int main() {
  int q;
  cin >> q;
  while (q--) {
    int n;
    cin >> n;
    string s;
    cin >> s;
    vector<char> v;
    for (int i = 0; i < n; i++) {
      v.push_back(s[i]);
    }
    sort(v.begin(), v.end());
    int cnt = 0;
    for (int i = 0; i < n; i++) {
      if (s[i] != v[i]) cnt++;
    }
    cout << cnt << endl;
  }
  return 0;
}
