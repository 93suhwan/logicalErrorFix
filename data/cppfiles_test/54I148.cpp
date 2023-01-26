#include <bits/stdc++.h>
using namespace std;
vector<int> parent, ele_count;
map<int, int> color;
int find(int i) {
  if (i == parent[i])
    return i;
  else {
    return parent[i] = find(parent[i]);
  }
}
void unite(int i, int j) {
  int i_parent = find(i);
  int j_parent = find(j);
  if (i_parent == j_parent)
    return;
  else {
    if (ele_count[i_parent] = ele_count[j_parent]) {
      parent[i_parent] = j_parent;
      ele_count[j_parent]++;
    } else if (ele_count[i_parent] < ele_count[j_parent]) {
      parent[i_parent] = j_parent;
    } else
      parent[j_parent] = i_parent;
  }
}
bool flag = true;
vector<set<int>> components;
void bfs(int i, vector<int> *edges, int par_color, int component_number) {
  if (!flag) return;
  if (color.find(i) != color.end()) {
    if (color[i] == par_color) {
      flag = false;
    }
    return;
  }
  if (par_color == -1) {
    color.insert({i, 1});
  } else if (par_color == 1) {
    color[i] = 2;
  } else {
    color[i] = 1;
  }
  components[component_number].insert(i);
  for (auto a : edges[i]) {
    if (color.find(a) == color.end()) bfs(a, edges, color[i], component_number);
  }
}
int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);
  long long t;
  cin >> t;
  while (t--) {
    long long n, m;
    cin >> n >> m;
    vector<set<pair<int, int>>> comments;
    color.clear();
    components.clear();
    comments.resize(2);
    int x, y;
    string str;
    for (int i = 0; i < m; i++) {
      cin >> x >> y >> str;
      if (str[0] == 'c') {
        comments[0].insert({x - 1, y - 1});
      } else
        comments[1].insert({x - 1, y - 1});
    }
    parent.clear();
    ele_count.clear();
    parent.resize(n);
    ele_count.resize(n);
    for (int i = 0; i < n; i++) {
      parent[i] = i;
      ele_count[i] = 0;
    }
    for (auto a : comments[0]) {
      unite(a.first, a.second);
    }
    flag = true;
    set<int> comps[n];
    for (int i = 0; i < n; i++) {
      int key = find(i);
      comps[key].insert(i);
    }
    vector<int> edges[n];
    for (auto a : comments[1]) {
      int x = a.first;
      int y = a.second;
      if (find(x) == find(y)) {
        flag = false;
        break;
      } else {
        edges[x].push_back(y);
        edges[y].push_back(x);
      }
    }
    int component_num = 0;
    for (int i = 0; i < n; i++) {
      if (parent[i] != i) continue;
      if (color.find(i) == color.end()) {
        set<int> temp;
        components.push_back(temp);
        bfs(i, edges, -1, component_num);
        component_num++;
      }
    }
    int ans = -1;
    if (flag) {
      ans = 0;
      for (auto a : components) {
        int size_1 = 0;
        int size_2 = 0;
        for (auto b : a) {
          if (color[b] == 1)
            size_1 += comps[b].size();
          else if (color[b] == 2)
            size_2 += comps[b].size();
        }
        ans += max(size_1, size_2);
      }
    }
    cout << ans << endl;
  }
  return 0;
}
