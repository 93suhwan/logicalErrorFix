#include <bits/stdc++.h>
using namespace std;
int main() {
  ios::sync_with_stdio(0);
  int T;
  cin >> T;
  while (T--) {
    string s;
    cin >> s;
    string b;
    cin >> b;
    int ans[500];
    for (int i = 0; i < b.length(); i++)
      for (int j = 0; j < 26; j++)
        if (s[j] == b[i]) ans[i] = j + 1;
    int finalans = 0;
    for (int i = 1; i < b.length(); i++) finalans += abs(ans[i] - ans[i - 1]);
    cout << finalans << endl;
  }
}
