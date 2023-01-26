#include <bits/stdc++.h>
using namespace std;
int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  long long t;
  cin >> t;
  while (t--) {
    long long i, j, k, l, m, n;
    cin >> n >> m;
    long long arr[n + 1];
    long long cnt[n];
    memset(cnt, 0, sizeof cnt);
    for (i = 1; i <= n; i++) {
      cin >> arr[i];
      long long pos = i, num = arr[i];
      if (pos >= num)
        cnt[pos - num] += 1;
      else
        cnt[n - num + pos] += 1;
    }
    vector<long long> ans;
    for (i = 0; i < n; i++) {
      long long a1 = cnt[i];
      long long rem = n - cnt[i];
      if (rem - 1 <= m)
        ans.push_back(i);
      else {
        if (rem / 2 + (rem % 2) <= m) {
          vector<long long> v2(n + 1, 0);
          vector<long long> v1(n + 1, 0);
          for (j = 1; j <= n; j++) {
            long long x = n - i + 1;
            if (j <= i)
              v1[j] = n - i + j;
            else
              v1[j] = j - i;
            if (arr[j] > n - i)
              v2[j] = i - (n - arr[j]);
            else
              v2[j] = arr[j] + i;
          }
          long long tw = 0;
          for (j = 1; j <= n; j++) {
            long long req = v1[j];
            long long gi = v2[j];
            if (req != gi) {
              if (arr[gi] == req) tw++;
            }
          }
          long long tot = tw / 2;
          if ((rem - tw)) tot += (rem - tw - 1);
          if (tot <= m) ans.push_back(i);
        }
      }
    }
    cout << (long long)ans.size() << " ";
    for (auto it : ans) cout << it << " ";
    cout << "\n";
  }
  return 0;
}
