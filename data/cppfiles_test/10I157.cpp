#include <bits/stdc++.h>
using namespace std;
int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);
  int t;
  cin >> t;
  while (t--) {
    int n, k;
    cin >> n >> k;
    int a[n], c[n];
    map<int, int> mp1, mp2, flag;
    for (int i = 0; i < n; ++i) {
      cin >> a[i];
      mp1[a[i]]++;
      mp2[a[i]]++;
      flag[a[i]] = 0;
    }
    int ans = 0, j;
    for (int i = 0; i < n; ++i) {
      if (mp1[a[i]] > k) mp1[a[i]] = k;
      ans += mp1[a[i]];
      mp1[a[i]] = 0;
    }
    ans = ans / k;
    int cnt[k + 1];
    for (int i = 0; i < k + 1; ++i) cnt[i] = 0;
    for (int i = 0; i < n; ++i) {
      if (flag[a[i]] == 0) {
        mp2[a[i]] = 1;
        flag[a[i]] = 1;
      }
      j = mp2[a[i]];
      while (j <= k && cnt[j] >= ans) j++;
      if (j == (k + 1))
        j = 0;
      else
        cnt[j]++;
      c[i] = j;
      mp2[a[i]] = j;
      if (mp2[a[i]] > 0) mp2[a[i]]++;
    }
    for (int i = 0; i < n; ++i) cout << c[i] << " ";
    cout << "\n";
  }
  return 0;
}
