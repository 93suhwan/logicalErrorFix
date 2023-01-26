#include <bits/stdc++.h>
using namespace std;
vector<string> v;
vector<int> id;
bool comp(int &a, int &b) { return v[a].compare(v[b]) < 0; }
int main() {
  int n, m;
  ios_base::sync_with_stdio(false);
  cin >> n >> m;
  v = vector<string>(n);
  id = vector<int>(n);
  for (int i = 0; i < n; ++i) id[i] = i;
  for (int i = 0; i < n; ++i) cin >> v[i];
  for (int i = 0; i < n; ++i)
    for (int j = 1; j < m; j += 2) v[i][j] = 'Z' - (v[i][j] - 'A');
  sort(id.begin(), id.end(), comp);
  for (int i = 0; i < n; ++i) cout << id[i] + 1 << (i == n - 1 ? '\n' : ' ');
  return 0;
}
