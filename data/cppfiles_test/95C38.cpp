#include <bits/stdc++.h>
using namespace std;
int a[1000005], L_min[1000005], L_max[1000005], R_min[1000005], R_max[1000005];
char ans[1000005];
int n, m;
int index(int r, int c) { return (r * m + c); }
int main() {
  int t;
  scanf("%d", &t);
  while (t--) {
    scanf("%d %d", &n, &m);
    for (int i = 0; i < n; i++) {
      for (int j = 0; j < m; j++) {
        scanf("%d", &a[index(i, j)]);
      }
    }
    for (int i = 0; i < n; i++) {
      for (int j = 0; j < m; j++) {
        int ind = index(i, j);
        int mi = a[ind], ma = a[ind];
        if (j > 0) {
          int ind1 = index(i, j - 1);
          ma = max(ma, L_max[ind1]);
          mi = min(mi, L_min[ind1]);
        }
        L_min[ind] = mi;
        L_max[ind] = ma;
        ind = index(i, m - 1 - j);
        ma = a[ind];
        mi = a[ind];
        if (j > 0) {
          int ind1 = index(i, m - j);
          ma = max(ma, R_max[ind1]);
          mi = min(mi, R_min[ind1]);
        }
        R_min[ind] = mi;
        R_max[ind] = ma;
      }
    }
    bool found = false;
    for (int i = 0; i < m - 1; i++) {
      multiset<int> L_blue, L_red;
      multiset<int> R_blue, R_red;
      vector<pair<int, int> > left;
      for (int j = 0; j < n; j++) {
        left.push_back({L_max[index(j, i)], j});
        L_red.insert(L_min[index(j, i)]);
        R_red.insert(R_max[index(j, i + 1)]);
      }
      sort(left.begin(), left.end());
      for (int j = 0; j < left.size() - 1; j++) {
        int L_ind = index(left[j].second, i);
        int R_ind = index(left[j].second, i + 1);
        L_red.erase(L_red.find(L_min[L_ind]));
        R_red.erase(R_red.find(R_max[R_ind]));
        L_blue.insert(L_max[L_ind]);
        R_blue.insert(R_min[R_ind]);
        if (*L_blue.rbegin() < *L_red.begin() &&
            *R_red.rbegin() < *R_blue.begin()) {
          found = true;
          puts("YES");
          for (int k = 0; k < left.size(); k++) {
            if (k <= j) {
              ans[left[k].second] = 'B';
            } else {
              ans[left[k].second] = 'R';
            }
          }
          ans[left.size()] = '\0';
          printf("%s %d\n", ans, i + 1);
          break;
        }
      }
      if (found) break;
    }
    if (!found) puts("NO");
  }
  return 0;
}
