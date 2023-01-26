#include <bits/stdc++.h>
using namespace std;
bool prime(long long x) {
  if (x == 2) {
    return true;
  }
  if (x <= 1) {
    return false;
  }
  for (int i = 2; i < sqrt(x); i++) {
    if (x % i == 0) {
      return false;
    }
  }
  return true;
}
void printv(vector<long long> v) {
  for (int i = 0; i < v.size(); i++) {
    cout << v[i] << " ";
  }
  cout << endl;
}
string Y = "YES\n";
string N = "NO\n";
signed main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);
  int t;
  cin >> t;
  for (int pop = 0; pop < t; pop++) {
    long long q, m;
    cin >> q >> m;
    vector<int> arr;
    vector<int> arr1;
    for (int i = 0; i < q * m; i++) {
      long long el;
      cin >> el;
      arr.push_back(el);
      arr1.push_back(el);
    }
    sort(arr.begin(), arr.end());
    map<int, priority_queue<vector<int>>> mp;
    for (int i = 0; i < q * m; i++) {
      int x = i / m;
      x = q - x;
      int y = i % m;
      mp[arr[i]].push({y, x});
    }
    int res = 0;
    bool vis[q][m];
    memset(vis, false, sizeof(vis));
    for (int i = 0; i < q * m; i++) {
      vector<int> kl = mp[arr1[i]].top();
      mp[arr1[i]].pop();
      int x = q - kl[1];
      int y = kl[0];
      vis[x][y] = true;
      for (int j = 0; j < y; j++) {
        if (vis[x][j]) {
          res++;
        }
      }
    }
    cout << res << endl;
  }
  return 0;
}
