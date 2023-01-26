#include <bits/stdc++.h>
using namespace std;
int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);
  int n, id = 0, id2 = 0, sum = 0;
  cin >> n;
  for (int i = 1; i <= n; i++) {
    string s;
    cin >> s;
    string a;
    cin >> a;
    for (int k = 0; k < a.size(); k++) {
      for (int j = 0; j < s.size(); j++) {
        if (s[j] == a[k]) {
          id = j;
        }
        if (s[j] == a[k + 1]) {
          id2 = j;
        }
      }
      sum += abs(id2 - id);
    }
    if (a.size() == 1) {
      cout << 0 << '\n';
    } else {
      cout << sum << '\n';
      sum = 0;
      id = 0;
      id2 = 0;
    }
  }
}
