#include <bits/stdc++.h>
using namespace std;
int main() {
  int t;
  cin >> t;
  while (t-- > 0) {
    int k;
    cin >> k;
    vector<int> v(k);
    string s;
    cin >> s;
    for (int i = 0; i < k; i++) {
      v[i] = (s[i] - '0');
    }
    bool found = false;
    int num[] = {0, 0, 0, 0, 0, 0, 0, 0, 0};
    for (int i = 0; i < k; i++) {
      num[v[i]]++;
      if (v[i] != 2 && v[i] != 3 && v[i] != 5 && v[i] != 7) {
        cout << 1 << endl;
        cout << v[i] << endl;
        found = true;
        break;
      } else if (num[v[i]] >= 2) {
        cout << 2 << endl;
        cout << v[i] * 10 + v[i] << endl;
        found = true;
        break;
      } else if (i != 0 && (v[i] == 5 || v[i] == 2)) {
        found = true;
        cout << 2 << endl;
        cout << v[i - 1] * 10 + v[i] << endl;
        break;
      }
    }
    if (!found) {
      cout << 2 << endl;
      cout << 27 << endl;
    }
  }
  return 0;
}
