#include <bits/stdc++.h>
using namespace std;
struct node {
  int a;
  int b;
};
struct cmp {
  bool operator()(node c, node d) {
    if (c.a < d.a) {
      return true;
    } else if (c.a == d.a) {
      if (c.b < d.b) {
        return true;
      }
      return false;
    }
    return false;
  }
};
int main() {
  int t;
  cin >> t;
  while (t--) {
    int n, i, j;
    cin >> n;
    unordered_map<int, vector<int>> m;
    priority_queue<node, vector<node>, cmp> p;
    for (i = 0; i < n; i++) {
      int z;
      cin >> z;
      if (z != 0) {
        m[z].push_back(i + 1);
        struct node nd;
        nd.a = z;
        nd.b = z;
        p.push(nd);
      }
    }
    vector<pair<int, int>> v;
    struct node r, s;
    while (p.size() != 1 && p.size() != 0) {
      r = p.top();
      p.pop();
      s = p.top();
      p.pop();
      int l = m[r.b].size();
      int k = m[r.b][l - 1];
      int x = m[s.b].size();
      int y = m[s.b][x - 1];
      if (r.b == s.b) {
        y = m[s.b][l - 2];
      }
      if (r.a < s.a) {
        for (i = 0; i < r.a; i++) {
          v.push_back({k, y});
        }
        m[r.b].pop_back();
        if (m[r.b].size() == 0) {
          m.erase(r.b);
        }
        s.a = s.a - r.a;
        p.push(s);
      } else if (r.a > s.a) {
        for (i = 0; i < s.a; i++) {
          v.push_back({y, k});
        }
        m[s.b].pop_back();
        if (m[s.b].size() == 0) {
          m.erase(s.b);
        }
        r.a = r.a - s.a;
        p.push(r);
      } else {
        for (i = 0; i < s.a; i++) {
          v.push_back({y, k});
        }
        m[s.b].pop_back();
        m[r.b].pop_back();
        if (m[r.b].size() == 0) {
          m.erase(r.b);
        }
        if (m.find(s.b) != m.end() && m[s.b].size() == 0) {
          m.erase(s.b);
        }
      }
    }
    cout << v.size() << endl;
    for (i = 0; i < v.size(); i++) {
      cout << v[i].first << " " << v[i].second << endl;
    }
  }
  return 0;
}
