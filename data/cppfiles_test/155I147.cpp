#include <bits/stdc++.h>
using namespace std;
int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(0);
  cout.tie(0);
  long long int t;
  cin >> t;
  while (t--) {
    long long int n, sum = 0, count = 0, ans = 0;
    string s;
    cin >> n;
    vector<int> v(n);
    for (int i = 0; i < n; i++) {
      cin >> v[i];
    }
    cin >> s;
    for (int i = 0; i < n; i++) {
      if (s[i] == '0') count = 1;
    }
    if (count == 0) {
      for (int i = 0; i < n; i++) cout << v[i] << " ";
      cout << endl;
    } else {
      vector<int> v2(n);
      map<int, int> m0, m1;
      for (int i = 0; i < n; i++) {
        if (s[i] == '0') {
          m0[v[i]] = i;
        } else
          m1[v[i]] = i;
      }
      int j = 1;
      for (auto it : m0) {
        int k = it.second;
        v2[k] = j;
        j++;
      }
      j -= 1;
      for (auto it : m1) {
        int k = it.second;
        v2[k] = j;
        j++;
      }
      for (int i = 0; i < n; i++) cout << v2[i] << " ";
      cout << endl;
    }
  done : {};
  }
  return 0;
}
