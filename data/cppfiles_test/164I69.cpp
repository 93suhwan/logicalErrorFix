#include <bits/stdc++.h>
using namespace std;
const int MAX = 2e5 + 10;
int n, k;
char arr[MAX];
int L[MAX], R[MAX];
vector<int> order;
char nxt[MAX];
int mark[MAX], dep[MAX];
void dfs(int node) {
  if (L[node]) {
    dep[L[node]] = dep[node] + 1;
    dfs(L[node]);
  }
  order.push_back(node);
  if (R[node]) {
    dep[R[node]] = dep[node] + 1;
    dfs(R[node]);
  }
}
void dfs2(int node, int last) {
  if (L[node]) {
    dfs2(L[node], last);
    if (mark[L[node]]) mark[node] = 1;
  }
  cout << arr[node];
  if (mark[node] || (k >= dep[node] - last && arr[node] < nxt[node])) {
    mark[node] = 1;
    cout << arr[node];
    k -= (dep[node] - last);
    last = dep[node];
  } else
    last = -1e9;
  if (R[node]) {
    dfs2(R[node], last);
  }
}
int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  cin >> n >> k;
  for (int i = 1; i <= n; ++i) cin >> arr[i];
  for (int i = 1; i <= n; ++i) cin >> L[i] >> R[i];
  dep[1] = 1;
  dfs(1);
  nxt[order[n - 1]] = 'a';
  for (int i = n - 2; i >= 0; --i) {
    if (arr[order[i]] == arr[order[i + 1]])
      nxt[order[i]] = nxt[order[i + 1]];
    else
      nxt[order[i]] = arr[order[i + 1]];
  }
  dfs2(1, 0);
  return 0;
}
