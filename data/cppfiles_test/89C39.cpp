#include <bits/stdc++.h>
using namespace std;
int main() {
  int t;
  cin >> t;
  for (int itr = 0; itr < t; itr++) {
    int n;
    vector<int> s;
    cin >> n;
    for (int i = 1; i <= n; i++) {
      int tmp;
      cin >> tmp;
      s.push_back(tmp);
    }
    int token = 0;
    for (int i = 0; i < s.size(); i++) {
      int flag = 0;
      for (int j = 2; j <= 2 + i; j++) {
        if (s[i] % j != 0) {
          flag = 1;
          break;
        }
      }
      if (flag == 0) {
        token = 1;
        break;
      }
    }
    if (token == 1)
      cout << "NO\n";
    else
      cout << "YES\n";
  }
}
