#include <bits/stdc++.h>
using namespace std;
const long long N = 2e5 + 5, INF = 1e9, mod = 1e9 + 7;
int arr[N], f[N], f2[N];
int main() {
  ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);
  int t;
  cin >> t;
  while (t--) {
    memset(arr, 0, N);
    memset(f, 0, N);
    memset(f2, 0, N);
    int in, n, k;
    cin >> n >> k;
    map<int, vector<int>> make_pair;
    for (int i = 1; i <= n; i++) {
      cin >> in;
      make_pair[in].push_back(i);
    }
    vector<pair<int, int>> v;
    for (auto i : make_pair) v.push_back({i.second.size(), i.first});
    sort(v.rbegin(), v.rend());
    int cnt = 0;
    for (int i = 0; i < v.size(); i++) {
      if (v[i].first >= k) {
        for (int j = 0; j < k; j++) {
          arr[make_pair[v[i].second][j]] = (cnt % k) + 1;
          cnt++;
        }
      } else {
        for (int j = 0; j < v[i].first; j++) {
          arr[make_pair[v[i].second][j]] = (cnt % k) + 1;
          cnt++;
        }
      }
    }
    int mi = INF;
    for (int i = 1; i <= n; i++) f[arr[i]]++;
    for (int i = 1; i <= n; i++)
      if (f[i]) mi = min(mi, f[i]);
    for (int i = 1; i <= n; i++) {
      f2[arr[i]]++;
      if (f2[arr[i]] > mi) arr[i] = 0;
    }
    for (int i = 1; i <= n; i++) cout << arr[i] << " ";
    cout << '\n';
  }
}
