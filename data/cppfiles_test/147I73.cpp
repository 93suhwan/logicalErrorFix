#include <bits/stdc++.h>
using namespace std;
int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);
  int T = 1;
  cin >> T;
  while (T--) {
    string str;
    cin >> str;
    bool ans = 1;
    int n = str.size();
    ans = ans && (str[n - 1] == str[0]);
    cout << (ans ? "YES" : "NO") << endl;
  }
}
