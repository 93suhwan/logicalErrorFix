#include <bits/stdc++.h>
using namespace std;
int main() {
  int n;
  cin >> n;
  int num;
  string s, a, b;
  vector<int> v(n);
  for (int i = 0; i < n; ++i) {
    cin >> num;
    cin >> s;
    a = s;
    sort(s.begin(), s.end());
    int cnt = 0;
    for (int j = 0; j < s.size(); ++j) {
      if (a[j] != s[j]) {
        cnt++;
      }
    }
    v[i] = cnt;
  }
  for (int i = 0; i < n; ++i) {
    cout << v[i] << endl;
  }
  return 0;
}
