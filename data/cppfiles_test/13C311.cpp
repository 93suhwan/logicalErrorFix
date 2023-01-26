#include <bits/stdc++.h>
using namespace std;
const int N = 100005;
int n, m;
int t;
int a[N];
string s;
int main() {
  cin >> t;
  while (t--) {
    cin >> s;
    int c = 0;
    for (int i = 0; i < s.length(); i++) {
      if (s[i] == 'B') c++;
    }
    if (s.length() % 2 == 0 && c == s.length() / 2)
      puts("yes");
    else
      puts("no");
  }
  return 0;
}
