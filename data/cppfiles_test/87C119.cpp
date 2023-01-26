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
    map<long long, long long> mp, vis;
    for (int i = 0; i < m; i++) {
      cin >> arr[i];
      b[i] = arr[i];
    }
    sort(arr, arr + m);
    for (int i = 0; i < m; i++) {
      mp[arr[i]] = i + 1;
    }
    vector<long long> v;
    vector<long long>::iterator low;
    for (int i = 0; i < m; i++) {
      long long d = mp[b[i]];
      mp[b[i]]--;
      for (int j = 1; j < d; j++) {
        if (vis[j]) sum++;
      }
      vis[d]++;
    }
    cout << sum << endl;
  }
}
