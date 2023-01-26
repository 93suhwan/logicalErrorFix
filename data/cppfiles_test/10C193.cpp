#include <bits/stdc++.h>
using namespace std;
struct node {
  int pos, val;
} s[200005];
int colored[200005];
int cnt[200005];
vector<int> color;
vector<int> position[200005];
vector<int> tocolor;
bool cmp(node i, node k) { return i.val < k.val; }
int main() {
  int t;
  scanf("%d", &t);
  while (t--) {
    int n, m;
    scanf("%d%d", &n, &m);
    color.clear();
    tocolor.clear();
    memset(colored, 0, sizeof(colored));
    for (int i = 0; i < n; i++) {
      scanf("%d", &s[i].val);
      s[i].pos = i;
    }
    sort(s, s + n, cmp);
    int cnt1 = 0, cnt2 = 0, num = 0;
    position[num].clear();
    position[num].push_back(s[0].pos);
    color.push_back(s[0].val);
    cnt[0] = 1;
    for (int i = 1; i < n; i++) {
      if (s[i].val == s[i - 1].val)
        cnt[num]++;
      else {
        color.push_back(s[i].val);
        if (cnt[num] >= m) {
          cnt1++;
        } else {
          cnt2 += cnt[num];
        }
        num++;
        position[num].clear();
        cnt[num] = 1;
      }
      position[num].push_back(s[i].pos);
    }
    if (cnt[num] >= m) {
      cnt1++;
    } else
      cnt2 += cnt[num];
    for (int i = 0; i < color.size(); i++) {
      if (cnt[i] >= m) {
        for (int j = 0; j < m; j++) {
          colored[position[i][j]] = j + 1;
        }
      } else {
        for (int j = 0; j < position[i].size(); j++) {
          tocolor.push_back(position[i][j]);
        }
      }
    }
    for (int i = 0; i < tocolor.size() / m; i++) {
      for (int j = 0; j < m; j++) {
        colored[tocolor[i * m + j]] = j + 1;
      }
    }
    for (int i = 0; i < n; i++) printf("%d ", colored[i]);
    printf("\n");
  }
  return 0;
}
