#include <bits/stdc++.h>
using namespace std;
int main() {
  long long testcases;
  cin >> testcases;
  while (testcases--) {
    int n;
    cin >> n;
    char p;
    cin >> p;
    string s;
    cin >> s;
    int flag = 0;
    int pos;
    for (int i = 0; i < n; i++) {
      if (s[i] == p)
        continue;
      else if (s[i] != p and flag == 0) {
        flag = 1;
        pos = i;
      } else
        flag = 2;
    }
    if (flag == 0)
      cout << 0;
    else if (flag == 1 and pos != n - 1)
      cout << 1 << endl << n;
    else if (flag == 1 and pos == n - 1)
      cout << 1 << endl << n - 1;
    else if (flag == 2 and s[n - 1] == p) {
      cout << 1 << endl << n;
    } else
      cout << 2 << endl << n - 1 << " " << n;
    cout << endl;
  }
}
