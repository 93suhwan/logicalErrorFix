#include <bits/stdc++.h>
using namespace std;
void fast() {
  ios_base::sync_with_stdio(false);
  cin.tie(0);
  cout.tie(0);
}
void ran() { srand(chrono::steady_clock::now().time_since_epoch().count()); }
long long get_rand() {
  long long a = rand();
  long long b = rand();
  return a * (RAND_MAX + 1ll) + b;
}
void usaco() {
  freopen("problem.in", "r", stdin);
  freopen("problem.out", "w", stdout);
}
template <typename T>
using min_pq = priority_queue<T, vector<T>, greater<T>>;
int n;
const int MXN = 100005;
int xco[MXN], yco[MXN], col[MXN];
int ans() {
  int r = 0;
  vector<int> cols = {1, 2, 3};
  map<int, vector<int>> lr;
  map<int, vector<pair<int, int>>> td;
  for (int i = 1; i <= n; i++)
    lr[xco[i]].push_back(col[i]), td[yco[i]].push_back({xco[i], col[i]});
  vector<vector<int>> tr;
  vector<vector<pair<int, int>>> le;
  for (auto x : lr) tr.push_back(x.second);
  for (auto x : td) le.push_back(x.second);
  do {
    int L = cols[0], M = cols[1], R = cols[2];
    int midleft = n / 3;
    int leftf = 0, rightf = 0;
    int lpt = 0, rpt = tr.size() - 1;
    for (int k = 1; k <= n / 3; k++) {
      while (lpt < tr.size() && leftf < k) {
        for (auto m : tr[lpt]) {
          if (m == L) {
            leftf++;
          } else if (m == M) {
            midleft--;
          }
        }
        lpt++;
      }
      while (rpt >= 0 && rightf < k) {
        for (auto m : tr[rpt]) {
          if (m == R) {
            rightf++;
          } else if (m == M) {
            midleft--;
          }
        }
        rpt--;
      }
      if (leftf >= k && rightf >= k && midleft >= k) r = max(r, k);
    }
    midleft = n / 3;
    lpt = 0;
    int inbucket = INT_MIN / 4;
    min_pq<int> rightitems;
    priority_queue<int> leftitems;
    for (int k = n / 3; k >= 1; k--) {
      while (lpt < le.size()) {
        if (inbucket == INT_MIN / 4) {
          inbucket = 0;
          for (auto j : le[lpt]) {
            if (j.second == M) {
              inbucket++;
            }
          }
        }
        if (midleft - inbucket < k) {
          break;
        }
        for (auto j : le[lpt]) {
          if (j.second == L) leftitems.push(j.first);
          if (j.second == R) rightitems.push(j.first);
        }
        midleft -= inbucket;
        lpt++;
        inbucket = INT_MIN / 4;
      }
      while (leftitems.size() > k) leftitems.pop();
      while (rightitems.size() > k) rightitems.pop();
      if (leftitems.size() == k && rightitems.size() == k &&
          leftitems.top() < rightitems.top())
        r = max(r, k);
    }
  } while (next_permutation(cols.begin(), cols.end()));
  return r;
}
signed main() {
  ran();
  fast();
  cin >> n;
  for (int i = 1; i <= n; i++) {
    cin >> xco[i] >> yco[i] >> col[i];
  }
  int r = 0;
  for (int j = 0; j < 4; j++) {
    r = max(r, ans());
    for (int i = 1; i <= n; i++) {
      swap(xco[i], yco[i]);
      xco[i] *= -1;
    }
  }
  cout << r * 3 << '\n';
}
