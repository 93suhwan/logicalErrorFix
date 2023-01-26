#include <bits/stdc++.h>
using namespace std;
long long const mod = 998244353;
int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);
  long long t;
  cin >> t;
  while (t--) {
    long long n, m, sum = 0;
    cin >> n >> m;
    long long arr[m], b[m];
    map<long long, long long> mp, cnt;
    for (int i = 0; i < m; i++) {
      cin >> arr[i];
      b[i] = arr[i];
    }
    sort(arr, arr + m);
    for (int i = 0; i < m; i++) {
      if (!mp[arr[i]]) mp[arr[i]] = i + 1;
      cnt[arr[i]]++;
    }
    vector<long long> v;
    vector<long long>::iterator low;
    for (int i = 0; i < m; i++) {
      mp[b[i]] = mp[b[i]] + cnt[b[i]] - 1;
      cnt[b[i]]--;
      low = lower_bound(v.begin(), v.end(), mp[b[i]]);
      sum += (low - v.begin());
      v.push_back(mp[b[i]]);
    }
    cout << sum << endl;
  }
}
