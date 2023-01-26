#include <bits/stdc++.h>
using namespace std;
int main() {
  int y;
  cin >> y;
  while (y--) {
    string s, a;
    cin >> s >> a;
    long long ans[100000], f = 0;
    for (int i = 0; i < a.size(); i++) {
      for (int j = 0; j < 26; j++) {
        if (a[i] == s[j]) {
          ans[i] = j + 1;
        }
      }
    }
    for (int i = 0; i < a.size(); i++) {
      if (i == a.size() - 1) {
        break;
      }
      f += abs(ans[i] - ans[i + 1]);
    }
    cout << f << endl;
  }
}
