#include <bits/stdc++.h>
using namespace std;
int main() {
  int t;
  cin >> t;
  while (t--) {
    vector<int> ans;
    int p = 0, flag = 0, n;
    string s;
    char ch;
    cin >> n >> ch;
    cin >> s;
    for (int i = 0; i < n; i++)
      if (s[i] != ch) {
        flag = 1;
        break;
      }
    if (!flag)
      cout << "0" << endl;
    else if (s[n - 1] != ch)
      cout << "2" << endl << n - 1 << " " << n << endl;
    else if (s[n - 1] == ch)
      cout << "1" << endl << n << endl;
  }
}
