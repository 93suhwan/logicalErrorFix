#include <bits/stdc++.h>
using namespace std;
const int N = 23;
const int A = 26;
const int S = 20043;
int n;
string inp[N];
char buf[S];
int cnt[N][A];
const int MOD = 998244353;
int add(int x, int y) {
  x += y;
  while (x >= MOD) x -= MOD;
  while (x < 0) x += MOD;
  return x;
}
int sub(int x, int y) { return add(x, -y); }
int mul(int x, int y) { return (x * 1ll * y) % MOD; }
void flip_all(vector<int>& a) {
  int msk = (1 << n) - 1;
  for (int i = 0; i < (1 << (n - 1)); i++) swap(a[i], a[i ^ msk]);
}
int val[S];
int* where[S];
int cur = 0;
void change(int& x, int y) {
  where[cur] = &x;
  val[cur] = x;
  x = y;
  cur++;
}
void rollback() {
  --cur;
  (*where[cur]) = val[cur];
}
void zeta_transform(vector<int>& a) {
  for (int i = 0; i < n; i++) {
    for (int j = 0; j < (1 << n); j++)
      if ((j & (1 << i)) == 0) a[j ^ (1 << i)] = add(a[j ^ (1 << i)], a[j]);
  }
}
void mobius_transform(vector<int>& a) {
  for (int i = n - 1; i >= 0; i--) {
    for (int j = (1 << n) - 1; j >= 0; j--)
      if ((j & (1 << i)) != 0) a[j] = sub(a[j], a[j ^ (1 << i)]);
  }
}
int cur_max[A];
vector<int> mask_cnt;
void rec(int depth, int mask) {
  if (depth == n) {
    mask_cnt[mask] = 1;
    for (int i = 0; i < A; i++)
      mask_cnt[mask] = mul(mask_cnt[mask], cur_max[i] + 1);
  } else {
    int state = cur;
    for (int i = 0; i < A; i++)
      change(cur_max[i], min(cur_max[i], cnt[depth][i]));
    rec(depth + 1, mask + (1 << depth));
    while (state != cur) rollback();
    rec(depth + 1, mask);
  }
}
int main() {
  scanf("%d", &n);
  for (int i = 0; i < n; i++) {
    scanf("%s", buf);
    inp[i] = buf;
    for (auto x : inp[i]) cnt[i][x - 'a']++;
  }
  for (int i = 0; i < A; i++) cur_max[i] = S;
  mask_cnt.resize(1 << n);
  rec(0, 0);
  flip_all(mask_cnt);
  mobius_transform(mask_cnt);
  flip_all(mask_cnt);
  int sum = 0;
  for (int i = 0; i < (1 << n); i++) sum = add(sum, mask_cnt[i]);
  zeta_transform(mask_cnt);
  vector<int> res(1 << n);
  for (int i = 0; i < (1 << n); i++)
    res[i] = sub(sum, mask_cnt[((1 << n) - 1) ^ i]);
  long long ans = 0;
  for (int i = 0; i < (1 << n); i++) {
    int c = 0, s = 0;
    for (int j = 0; j < n; j++) {
      if (i & (1 << j)) {
        c++;
        s += j + 1;
      }
    }
    ans ^= res[i] * 1ll * c * 1ll * s;
  }
  printf("%lld\n", ans);
}
