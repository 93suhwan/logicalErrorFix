#include <bits/stdc++.h>
#pragma GCC optimize("Ofast")
#pragma GCC target("sse,sse2,sse3,ssse3,sse4,avx,avx2")
#pragma GCC optimization("O3")
#pragma GCC optimization("unroll-loops")
using namespace std;
void pre() {}
int arr[2][200001];
string s;
vector<pair<char, int>> d;
void dfs(int i) {
  if (arr[0][i] != -1) dfs(arr[0][i]);
  d.push_back({s[i], i});
  if (arr[1][i] != -1) dfs(arr[1][i]);
}
bool is_marked[200001]{0};
bool is_doubled[200001]{0};
int tot_b;
void dfs2(int i, int cost, bool &is_child_marked) {
  if (i == -1) return;
  bool is_m = 0;
  dfs2(arr[0][i], cost + 1, is_m);
  is_child_marked = is_m;
  if (!is_m && is_marked[i] && cost <= tot_b) {
    tot_b -= cost;
    is_child_marked = 1;
    is_doubled[i] = 1;
  } else if (is_m) {
    is_doubled[i] = 1;
  }
  if (is_child_marked) {
    dfs2(arr[1][i], 1, is_m);
  }
}
void solve() {
  int n, k, a, b;
  cin >> n >> tot_b;
  cin >> s;
  for (int i = 0; i < n; i++) {
    cin >> arr[0][i] >> arr[1][i];
    arr[0][i]--;
    arr[1][i]--;
  }
  dfs(0);
  for (int i = 0; i < n - 1; i++) {
    if (d[i].first >= d[i + 1].first) {
      continue;
    }
    is_marked[d[i].second] = 1;
    for (int j = i - 1; j >= 0; j--) {
      if (d[j].first != d[i].first) break;
      is_marked[d[j].second] = 1;
    }
  }
  bool asdaa = 0;
  dfs2(0, 1, asdaa);
  for (int i = 0; i < n; i++) {
    cout << d[i].first;
    if (is_doubled[d[i].second]) cout << d[i].first;
  }
  cout << "\n";
}
int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  pre();
  long long int num = 1;
  for (long long int i = 0; i < num; i++) {
    solve();
  }
}
