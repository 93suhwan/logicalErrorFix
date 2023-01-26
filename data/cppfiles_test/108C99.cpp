#include <bits/stdc++.h>
using namespace std;
bool isrange(int second, int first, int n, int m) {
  if (0 <= second && second < n && 0 <= first && first < m) return true;
  return false;
}
int dy[4] = {1, 0, -1, 0}, dx[4] = {0, 1, 0, -1},
    ddy[8] = {1, 0, -1, 0, 1, 1, -1, -1}, ddx[8] = {0, 1, 0, -1, 1, -1, 1, -1};
const int MAX = 1e5 + 100;
int A[MAX], B[MAX], vis[MAX];
set<pair<int, int> > a, b;
void del(int k) {
  a.erase(make_pair(A[k], k));
  b.erase(make_pair(B[k], k));
}
void solve(int tc) {
  int n;
  cin >> n;
  a.clear();
  b.clear();
  for (int e = 1; e <= n; e++) {
    vis[e] = 0;
    cin >> A[e];
    a.insert(make_pair(A[e], e));
  }
  for (int e = 1; e <= n; e++) {
    cin >> B[e];
    b.insert(make_pair(B[e], e));
  }
  int pos1 = prev(a.end())->second;
  int pos2 = prev(b.end())->second;
  del(pos1);
  del(pos2);
  vector<int> candi;
  candi.push_back(pos1);
  candi.push_back(pos2);
  int st = 0;
  while ((int)candi.size() != n) {
    int lim = (int)candi.size();
    bool flag = false;
    for (int p = st; p < lim; p++) {
      int pos = candi[p];
      set<pair<int, int> >::iterator lo1 = a.lower_bound(make_pair(A[pos], -1));
      vector<int> res;
      for (; lo1 != a.end(); lo1++) {
        res.push_back(lo1->second);
      }
      for (int e = 0; e < (int)res.size(); e++) {
        flag = true;
        candi.push_back(res[e]);
        del(res[e]);
      }
      set<pair<int, int> >::iterator lo2 = b.lower_bound(make_pair(B[pos], -1));
      res.clear();
      for (; lo2 != b.end(); lo2++) {
        res.push_back(lo2->second);
      }
      for (int e = 0; e < (int)res.size(); e++) {
        flag = true;
        candi.push_back(res[e]);
        del(res[e]);
      }
    }
    if (!flag) break;
    st = lim;
  }
  for (int e = 0; e < (int)candi.size(); e++) vis[candi[e]] = 1;
  for (int e = 1; e <= n; e++) cout << vis[e];
  cout << "\n";
}
int main(void) {
  ios_base ::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);
  int tc = 1;
  cin >> tc;
  for (int test_number = 1; test_number <= tc; test_number++) {
    solve(test_number);
  }
  return 0;
}
