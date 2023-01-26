#include <bits/stdc++.h>
using namespace std;
int yh() {
  int ret = 0;
  bool f = 0;
  char c = getchar();
  while (!isdigit(c)) {
    if (c == EOF) return -1;
    if (c == '-') f = 1;
    c = getchar();
  }
  while (isdigit(c)) ret = (ret << 3) + (ret << 1) + (c ^ 48), c = getchar();
  return f ? -ret : ret;
}
const int maxn = 3e5 + 5;
vector<int> a[10];
long long c[10];
long long w[10];
int n;
set<long long> il;
int hd[10];
struct ar {
  vector<int> a;
  long long val, hsh;
  bool operator<(const ar& A) const {
    return make_pair(val, hsh) < make_pair(A.val, A.hsh);
  }
};
void print(vector<int>& A) {
  for (int i = 0, iss = (n); i < iss; i++) cout << A[i] + 1 << " ";
  cout << endl;
}
int main() {
  n = yh();
  for (int i = 0, iss = (n); i < iss; i++) {
    c[i] = yh();
    a[i].resize(c[i]);
    for (int& x : a[i]) x = yh();
  }
  w[n - 1] = 1;
  for (int i = n - 2; i >= 0; i--) w[i] = w[i + 1] * c[i + 1];
  int m = yh();
  long long sum = 0, val = 0;
  for (int i = 0, iss = (m); i < iss; i++) {
    sum = 0;
    for (int j = 0, jss = (n); j < jss; j++) sum += w[j] * (yh() - 1);
    il.insert(sum);
  }
  sum = 0;
  set<ar> q;
  vector<int> tmp;
  tmp.resize(n);
  for (int i = 0, iss = (n); i < iss; i++)
    hd[i] = c[i] - 1, sum += hd[i] * w[i], tmp[i] = hd[i], val += a[i][hd[i]];
  q.insert((ar){tmp, val, sum});
  while (!q.empty()) {
    auto it = prev(q.end());
    tmp = it->a, val = it->val, sum = it->hsh;
    q.erase(it);
    if (!il.count(sum)) {
      print(tmp);
      return 0;
    }
    for (int i = 0, iss = (n); i < iss; i++)
      if (tmp[i]) {
        tmp[i]--;
        q.insert((ar){tmp, val + a[i][tmp[i]] - a[i][tmp[i] + 1], sum - w[i]});
        tmp[i]++;
      }
  }
  return 0;
}
