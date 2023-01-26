#include <bits/stdc++.h>
using namespace std;
const int maxn = 2e5 + 10;
bool vis[maxn];
int main() {
  int t;
  cin >> t;
  while (t--) {
    int n;
    cin >> n;
    int num[maxn];
    for (int i = 0; i < n; i++) {
      cin >> num[i];
    }
    string s;
    cin >> s;
    int cnt = 0;
    int cnt1 = 0;
    int cnt2 = 0;
    for (int i = 0; i < n; i++) {
      if (num[i] == 1 && s[i] == 'B')
        cnt1 = 1;
      else if (num[i] == n && s[i] == 'R')
        cnt2 = 1;
      else
        cnt++;
    }
    if (cnt < n - cnt1 - cnt2)
      cout << "NO" << endl;
    else
      cout << "YES" << endl;
  }
  return 0;
}
