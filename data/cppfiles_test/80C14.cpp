#include <bits/stdc++.h>
using namespace std;
vector<int> seg(1000050 * 12, 0);
vector<int> lazy(1000050 * 12, 0);
void update(int node, int start, int end, int rangemin, int rangemax, int val) {
  if (lazy[node] != 0) {
    seg[node] += lazy[node];
    lazy[node * 2 + 1] += lazy[node];
    lazy[node * 2 + 2] += lazy[node];
    lazy[node] = 0;
  }
  if (start >= rangemin && end <= rangemax) {
    seg[node] += val;
    lazy[node * 2 + 1] += val;
    lazy[node * 2 + 2] += val;
    return;
  }
  if (start > rangemax || end < rangemin) {
    return;
  }
  int mid = (start + end) / 2;
  update(node * 2 + 1, start, mid, rangemin, rangemax, val);
  update(node * 2 + 2, mid + 1, end, rangemin, rangemax, val);
  seg[node] = min(seg[node * 2 + 1], seg[node * 2 + 2]);
}
int query(int node, int start, int end, int rangemin, int rangemax) {
  if (lazy[node] != 0) {
    seg[node] += lazy[node];
    lazy[node * 2 + 1] += lazy[node];
    lazy[node * 2 + 2] += lazy[node];
    lazy[node] = 0;
  }
  if (start >= rangemin || end <= rangemax) {
    return seg[node];
  }
  if (start > rangemax || end < rangemin) {
    return -1;
  }
  int mid = (start + end) / 2;
  return min(query(node * 2 + 1, start, mid, rangemin, rangemax),
             query(node * 2 + 2, mid + 1, end, rangemin, rangemax));
}
void update(int b, int c, vector<int> &fenwick) {
  int temp = b + 1;
  while (temp < fenwick.size()) {
    fenwick[temp] += c;
    temp += temp & (-temp);
  }
}
int getsum(int a, int b, vector<int> &fenwick) {
  int temp = b + 1;
  int total = 0;
  while (temp != 0) {
    total += fenwick[temp];
    temp -= temp & (-temp);
  }
  int idk = a;
  while (idk != 0) {
    total -= fenwick[idk];
    idk -= idk & (-idk);
  }
  return total;
}
long long solve(vector<int> vect1) {
  vector<int> fenwick(vect1.size() + 5, 0);
  int n = vect1.size();
  vector<int> compress = vect1;
  sort(compress.begin(), compress.end());
  for (int i = 0; i < vect1.size(); i++) {
    vect1[i] = 1 + lower_bound(compress.begin(), compress.end(), vect1[i]) -
               compress.begin();
  }
  long long ans = 0;
  for (int i = 0; i < n; i++) {
    ans += getsum(vect1[i] + 1, n + 2, fenwick);
    update(vect1[i], 1, fenwick);
  }
  return ans;
}
void find() {
  int n, m;
  cin >> n >> m;
  for (int i = 0; i < 5 * (n); i++) {
    seg[i] = 0;
    lazy[i] = 0;
  }
  int input;
  vector<pair<int, int> > vect1 = {{-1, -1}};
  vector<int> temp;
  vector<int> vect2;
  for (int i = 0; i < n; i++) {
    cin >> input;
    vect1.push_back({input, i});
    temp.push_back(input);
    update(0, 0, n, 0, i, 1);
  }
  for (int i = 0; i < m; i++) {
    cin >> input;
    vect2.push_back(input);
  }
  sort(vect1.begin(), vect1.end());
  reverse(vect1.begin(), vect1.end());
  sort(vect2.begin(), vect2.end());
  reverse(vect2.begin(), vect2.end());
  vect2.push_back(-1);
  int curr = 0;
  long long ans = 0;
  deque<int> q1;
  for (int i = 0; i < vect2.size() - 1; i++) {
    while (vect1[curr].first >= vect2[i]) {
      update(0, 0, n, 0, vect1[curr].second, -1);
      if (vect1[curr].first != vect2[i]) {
        update(0, 0, n, vect1[curr].second + 1, n, 1);
      } else {
        q1.push_back(vect1[curr].second);
      }
      curr++;
    }
    int mini = query(0, 0, n, 0, n);
    ans += mini;
    if (vect2[i] != vect2[i + 1]) {
      for (auto k : q1) {
        update(0, 0, n, k + 1, n, 1);
      }
      q1.clear();
    }
  }
  cout << ans + solve(temp) << "\n";
}
int32_t main() {
  ios::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);
  int t;
  cin >> t;
  while (t--) {
    find();
  }
}
