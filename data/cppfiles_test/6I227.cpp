#include <bits/stdc++.h>
using namespace std;
vector<set<int>> adj(200001);
vector<set<int>> vec(20001);
bool vis[200001];
int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);
  int n, m;
  unordered_set<int> st, st1;
  cin >> n >> m;
  for (int i = 1; i <= n; i++) st1.insert(i);
  while (m--) {
    int a, b;
    cin >> a >> b;
    if (a < b)
      st1.erase(a);
    else
      st1.erase(b);
    adj[a].insert(b);
    adj[b].insert(a);
  }
  cin >> m;
  vec = adj;
  st = st1;
  bool flag = false;
  while (m--) {
    int x;
    cin >> x;
    if (x == 3) {
      cout << st.size() << endl;
    }
    if (x == 2) {
      flag = true;
      int a, b;
      cin >> a >> b;
      if (a > b) swap(a, b);
      vec[a].erase(b);
      vec[b].erase(a);
      if (vec[a].size() && *vec[a].rbegin() < a) st.insert(a);
    }
    if (x == 1) {
      flag = true;
      int a, b;
      cin >> a >> b;
      vec[a].insert(b);
      vec[b].insert(a);
      if (a < b)
        st.erase(a);
      else
        st.erase(b);
    }
  }
  return 0;
}
