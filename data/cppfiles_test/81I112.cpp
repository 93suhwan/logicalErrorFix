#include <bits/stdc++.h>
using namespace std;
const int N = 1e6 + 100;
int Tree[4 * N];
void update(int v, int l, int r, int idx, int x) {
  if (l == r) {
    Tree[v] = max(Tree[v], x);
    return;
  }
  if (idx <= (r + l) / 2) {
    update(v * 2, l, (r + l) / 2, idx, x);
  } else {
    update(v * 2 + 1, (r + l) / 2 + 1, r, idx, x);
  }
  Tree[v] = max(Tree[v * 2], Tree[v * 2 + 1]);
}
int get(int v, int l, int r, int al, int ar) {
  if (l >= al && r <= ar) {
    return Tree[v];
  }
  if (l <= ar && r >= al) {
    return max(get(v * 2, l, (r + l) / 2, al, ar),
               get(v * 2 + 1, (r + l) / 2 + 1, r, al, ar));
  }
  return 0;
}
signed main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);
  int n, d;
  cin >> n >> d;
  int ans = 0;
  vector<pair<int, int> > vec;
  vector<int> uniqa;
  for (int i = 0; i < n; i++) {
    int s, a;
    cin >> s >> a;
    if (s < d) {
      continue;
    }
    if (a <= d) {
      ans++;
    } else {
      vec.push_back({s, a});
      uniqa.push_back(a);
    }
  }
  sort(uniqa.begin(), uniqa.end());
  uniqa.resize(unique(uniqa.begin(), uniqa.end()) - uniqa.begin());
  n = (int)uniqa.size() + 1;
  vector<vector<int> > a_vec((int)uniqa.size() + 1);
  for (int i = 0; i < (int)vec.size(); i++) {
    int j =
        upper_bound(uniqa.begin(), uniqa.end(), vec[i].first) - uniqa.begin();
    a_vec[j].push_back(vec[i].second);
  }
  for (int i = 0; i < n; i++) {
    sort(a_vec[i].begin(), a_vec[i].end());
    int cnt = 0;
    for (auto a : a_vec[i]) {
      if (i == 0 && a <= d || i != 0 && a <= uniqa[i - 1]) {
        cnt++;
      }
    }
    cnt += get(1, 0, n - 1, 0, i);
    update(1, 0, n - 1, i, cnt);
    for (auto a : a_vec[i]) {
      if (i == 0 && a > d || i != 0 && a > uniqa[i - 1]) {
        int j = lower_bound(uniqa.begin(), uniqa.end(), a) - uniqa.begin();
        update(1, 0, n - 1, j + 1, cnt + 1);
      }
    }
  }
  cout << ans + Tree[1];
  return 0;
}
