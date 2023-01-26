#include <bits/stdc++.h>
using namespace std;
int min(int a, int b) {
  if (a > b)
    return b;
  else
    return a;
}
int main() {
  int tc;
  cin >> tc;
  while (tc--) {
    long long int n;
    cin >> n;
    vector<int> a(n + 1, 0);
    vector<int> vis(n + 1, 0);
    for (int i = 1; i <= n; i++) cin >> a[i];
    vector<int> ans(n + 1, 0);
    string s;
    cin >> s;
    int one = 0;
    for (int i = 0; i < n; i++) {
      if (s[i] == '1') one++;
    }
    int max = n - one;
    for (int i = 1; i <= n; i++) {
      if (s[i - 1] == '1') {
        if (a[i] > max) {
          ans[i] = a[i];
          vis[a[i]] = 1;
        }
      }
    }
    vector<int> unvis;
    for (int i = max + 1; i <= n; i++) {
      if (vis[i] == 0) unvis.push_back(i);
    }
    int j = 0;
    for (int i = 1; i <= n; i++) {
      if (s[i - 1] == '1' && vis[a[i]] == 0) {
        ans[i] = unvis[j];
        j++;
      }
    }
    j = 1;
    for (int i = 1; i <= n; i++) {
      if (s[i - 1] == '0') {
        ans[i] = j;
        j++;
      }
    }
    for (int i = 1; i <= n; i++) cout << ans[i] << " ";
    cout << endl;
  }
  return 0;
}
