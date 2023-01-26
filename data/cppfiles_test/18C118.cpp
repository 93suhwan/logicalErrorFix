#include <bits/stdc++.h>
using namespace std;
int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  int t;
  cin >> t;
  while (t--) {
    int n, k;
    cin >> n >> k;
    vector<pair<int, int>> edges;
    unordered_set<int> seen;
    for (int i = 0; i < k; i++) {
      int u, v;
      cin >> u >> v;
      u--;
      v--;
      if (u > v) swap(u, v);
      edges.push_back(make_pair(u, v));
      seen.insert(u);
      seen.insert(v);
    }
    vector<int> rem;
    for (int i = 0; i < 2 * n; i++) {
      if (seen.count(i) == 0) rem.push_back(i);
    }
    int skp = (int)(rem).size() / 2;
    for (int i = 0; i < n - k; i++) {
      edges.push_back(make_pair(rem[i], rem[i + skp]));
    }
    int out = 0;
    for (int i = 0; i < n; i++)
      for (int j = i + 1; j < n; j++) {
        if (edges[i].first < edges[j].first &&
            edges[j].first < edges[i].second) {
          if (edges[j].second > edges[i].second) out++;
        } else if (edges[i].first < edges[j].first &&
                   edges[i].second < edges[j].first) {
          if (edges[j].second < edges[i].second &&
              edges[j].second < edges[i].second)
            out++;
        } else if (edges[i].first > edges[j].first) {
          if (edges[i].first < edges[j].second &&
              edges[j].second < edges[i].second)
            out++;
        }
      }
    cout << out << endl;
  }
}
