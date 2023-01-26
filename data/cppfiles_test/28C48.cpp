#include <bits/stdc++.h>
using namespace std;
using ll = long long;
vector<int> par;
int findSet(int u) {
  if (u == par[u]) return u;
  return par[u] = findSet(par[u]);
}
void unionSet(int u, int v) {
  u = findSet(u);
  v = findSet(v);
  if (u != v) {
    par[u] = v;
  }
}
int minSwaps(vector<int> arr, int n, int k) {
  for (int i = 0; i < n; i++) {
    par[i] = i;
  }
  for (int i = 0; i < n; i++) {
    unionSet((i - k + n) % n, arr[i]);
  }
  set<int> s;
  for (int i = 0; i < n; i++) {
    s.insert(findSet(i));
  }
  return n - (s.size());
}
int main() {
  int t;
  cin >> t;
  while (t--) {
    int n, m;
    cin >> n >> m;
    par.assign(n + 1, 0);
    for (int i = 0; i < n; i++) {
      par[i] = i;
    }
    vector<int> arr(n), v;
    for (int i = 0; i < n; i++) {
      cin >> arr[i];
      arr[i]--;
    }
    vector<int> inPos(n, 0);
    for (int i = 0; i < n; i++) {
      inPos[(i - arr[i] + n) % n]++;
    }
    for (int i = 0; i < n; i++) {
      if (inPos[i] >= n - 2 * m && minSwaps(arr, n, i) <= m) {
        v.push_back(i);
      }
    }
    cout << v.size() << " ";
    for (int i : v) {
      cout << i << " ";
    }
    cout << endl;
  }
  return 0;
}
