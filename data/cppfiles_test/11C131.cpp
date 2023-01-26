#include <bits/stdc++.h>
#pragma GCC optimize("Ofast")
#pragma GCC optimize("unroll-loops")
#pragma GCC target("sse,sse2,sse3,ssse3,sse4,popcnt,abm,mmx,avx,tune=native")
using namespace std;
int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);
  int casi;
  cin >> casi;
  while (casi--) {
    int n;
    cin >> n;
    vector<string> v(n);
    int maxi = 0;
    for (int i = 0; i < n; i++) cin >> v[i];
    for (char c = 'a'; c <= 'z'; c++) {
      vector<int> tmp;
      for (int i = 0; i < n; i++) {
        int cnt = 0;
        for (char x : v[i])
          if (x == c)
            cnt++;
          else
            cnt--;
        tmp.push_back(cnt);
      }
      sort(tmp.begin(), tmp.end());
      reverse(tmp.begin(), tmp.end());
      int sum = 0, i = -1;
      while (i + 1 < n && sum + tmp[i + 1] > 0) {
        i++;
        sum += tmp[i];
      }
      maxi = max(maxi, i + 1);
    }
    cout << maxi << '\n';
  }
}
