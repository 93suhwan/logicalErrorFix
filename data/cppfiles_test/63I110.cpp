#include <bits/stdc++.h>
using namespace std;
int parent[100005];
vector<int> adj[100005];
vector<vector<int>> grps;
vector<int> temp;
bool visited[100005];
void dfs(int node) {
  if (visited[node]) {
    return;
  }
  visited[node] = true;
  temp.push_back(node);
  for (auto it : adj[node]) {
    dfs(it);
  }
}
void join(int a, int b) {
  while (parent[a] > 0) {
    a = parent[a];
  }
  while (parent[b] > 0) {
    b = parent[b];
  }
  if (a == b) {
    return;
  }
  if (abs(parent[a]) > abs(parent[b])) {
    parent[a] += parent[b];
    parent[b] = a;
  } else {
    parent[b] += parent[a];
    parent[a] = b;
  }
}
int getparent(int a) {
  while (parent[a] > 0) {
    a = parent[a];
  }
  return a;
}
int main() {
  memset(visited, 0, sizeof(visited));
  memset(parent, -1, sizeof(parent));
  int n;
  cin >> n;
  int a, b;
  cin >> a >> b;
  for (int i = 0; i < a; i++) {
    int x, y;
    cin >> x >> y;
    adj[x].push_back(y);
    adj[y].push_back(x);
  }
  for (int i = 0; i < b; i++) {
    int x, y;
    cin >> x >> y;
    join(x, y);
  }
  for (int i = 1; i <= n; i++) {
    if (!visited[i]) {
      temp.clear();
      dfs(i);
      grps.push_back(temp);
    }
  }
  vector<pair<int, int>> ans;
  int x = grps.size();
  set<pair<int, int>> st;
  for (auto it : grps[0]) {
    st.insert({getparent(it), it});
  }
  for (int i = 1; i < x; i++) {
    bool flag = true;
    for (auto it : grps[i]) {
      if (st.begin()->first != getparent(it) && flag) {
        join(st.begin()->second, it);
        int x = st.begin()->second;
        st.erase(st.begin());
        st.insert({getparent(x), x});
        ans.push_back({x, it});
        flag = false;
      } else if ((--st.end())->first != getparent(it) && flag) {
        join((--st.end())->second, it);
        int x = (--st.end())->second;
        st.erase(--st.end());
        st.insert({getparent(x), x});
        ans.push_back({x, it});
        flag = false;
      }
      st.insert({getparent(it), it});
    }
  }
  cout << ans.size() << endl;
  for (auto it : ans) {
    cout << it.first << " " << it.second << endl;
  }
}
