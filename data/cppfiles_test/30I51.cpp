#include <bits/stdc++.h>
using namespace std;
int f[1000005];
int a[150000];
vector<int> v[1000005];
int root[1000005];
int parent[150000];
int find(int n) {
  if (parent[n] != n) parent[n] = find(parent[n]);
  return parent[n];
}
vector<pair<int, int> > all;
int main() {
  int i, j, k;
  for (i = 2; i <= 1000004; i++) {
    if (f[i] == 0) {
      for (j = i; j <= 1000004; j += i) f[j] = i;
    }
  }
  int n, q;
  scanf("%d %d", &n, &q);
  for (i = 0; i < n; i++) {
    scanf("%d", &a[i]);
    int t = a[i];
    while (t > 1) {
      v[f[t]].push_back(i);
      t /= f[t];
    }
  }
  for (i = 0; i < n; i++) parent[i] = i;
  for (i = 2; i <= 1000004; i++) {
    for (j = 1; j < v[i].size(); j++) {
      int x = find(v[i][j]), y = find(v[i][j - 1]);
      if (x != y) parent[x] = y;
    }
  }
  memset(root, -1, sizeof(root));
  for (i = 0; i < n; i++) {
    int t = a[i];
    while (t > 1) {
      root[f[t]] = find(i);
      t /= f[t];
    }
  }
  for (i = 0; i < n; i++) {
    int t = a[i];
    vector<int> p;
    while (t > 1) {
      p.push_back(f[t]);
      t /= f[t];
    }
    t = a[i] + 1;
    while (t > 1) {
      p.push_back(f[t]);
      t /= f[t];
    }
    sort(p.begin(), p.end());
    p.resize(unique(p.begin(), p.end()) - p.begin());
    for (j = 0; j < p.size(); j++) {
      for (k = j + 1; k < p.size(); k++)
        all.push_back(make_pair(root[p[j]], root[p[k]]));
    }
  }
  sort(all.begin(), all.end());
  all.resize(unique(all.begin(), all.end()) - all.begin());
  int s, t;
  for (i = 0; i < q; i++) {
    scanf("%d %d", &s, &t);
    s--, t--;
    if (find(s) == find(t))
      printf("0\n");
    else if (binary_search(
                 all.begin(), all.end(),
                 make_pair(min(find(s), find(t)), max(find(s), find(t)))))
      printf("1\n");
    else
      printf("2\n");
  }
  return 0;
}
