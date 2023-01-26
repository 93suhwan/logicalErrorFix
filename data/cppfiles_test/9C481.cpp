#include <bits/stdc++.h>
using namespace std;
int main() {
  int t;
  cin >> t;
  while (t--) {
    string str;
    cin >> str;
    int n = str.length();
    int a = 0, b = 0;
    unordered_map<char, int> m;
    for (int i = 0; i < n; i++) m[str[i]]++;
    for (auto &it : m) {
      if (it.second > 1)
        a++;
      else if (it.second == 1)
        b++;
    }
    cout << a + b / 2 << endl;
  }
}
