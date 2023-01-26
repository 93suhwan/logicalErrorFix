#include <bits/stdc++.h>
using namespace std;
vector<pair<int, int>> factors[1000005];
vector<pair<int, int>> v[1000005];
vector<int> nex[1000005];
int arr[1000005];
char brr[1000005];
int sum[1000005];
int ans[1000005];
int pos[1000005];
void solve() {
  int n;
  cin >> n;
  for (int i = 0; i < 1000005; i++) ans[i] = n;
  for (int i = 1; i <= n; i++) {
    cin >> arr[i];
  }
  for (int i = 1; i <= n; i++) {
    cin >> brr[i];
  }
  for (int i = 1; i <= n; i++) {
    for (auto u : factors[arr[i]]) {
      if (brr[i] == '/') {
        sum[u.first] -= u.second;
      }
      if (brr[i] == '*') {
        sum[u.first] += u.second;
      }
      v[u.first].push_back({sum[u.first], i});
      if (sum[u.first] < 0) ans[u.first] = min(ans[u.first], i - 1);
    }
  }
  for (int i = 0; i < 1000005; i++) {
    if (v[i].empty()) continue;
    stack<int> st;
    st.push(v[i].size());
    v[i].push_back({-1e9, n + 1});
    for (int j = v[i].size() - 2; j >= 0; j--) {
      while (v[i][j] <= v[i][st.top()]) st.pop();
      nex[i].push_back(v[i][st.top()].second - 1);
      st.push(j);
    }
    reverse(nex[i].begin(), nex[i].end());
  }
  multiset<int> s;
  s.insert(n);
  for (int i = 0; i < 1000005; i++)
    if (v[i].size()) s.insert(ans[i]);
  long long res = *s.begin();
  for (int i = 2; i <= n; i++) {
    for (auto u : factors[arr[i - 1]]) {
      s.erase(s.find(ans[u.first]));
      ans[u.first] = nex[u.first][pos[u.first]];
      pos[u.first]++;
      s.insert(ans[u.first]);
    }
    res += max(0, *s.begin() - i + 1);
  }
  cout << res << endl;
}
int32_t main() {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);
  for (int i = 2; i < 1000005; i++) {
    if (factors[i].empty()) {
      for (int j = i; j < 1000005; j += i) {
        int tmp = j;
        int cnt = 0;
        while (tmp / i * i == tmp) {
          tmp /= i;
          cnt++;
        }
        factors[j].push_back({i, cnt});
      }
    }
  }
  int t = 1;
  while (t--) {
    solve();
  }
}
