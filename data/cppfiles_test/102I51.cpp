#include <bits/stdc++.h>
using namespace std;
const int MAXN = (1 << 5) + 10;
const int P = 998244353;
int N, A, H, pa[MAXN];
map<int, vector<int>> mp;
int qpow(int a, int x) {
  int ret = 1;
  for (; x; x >>= 1, a = 1ll * a * a % P) x& 1 ? ret = 1ll * ret * a % P : 0;
  return ret;
}
void calc(int arr[], int S, bool lst_win) {
  int num[MAXN], nxt[MAXN], val = 0;
  for (int i = (0), iend = (1 << (N - 1)); i < iend; ++i) num[i] = arr[i];
  vector<int> rk;
  rk.resize(1 << (N - 1));
  for (int round = (0), roundend = (N - 1); round < roundend; ++round) {
    for (int j = 0; j < 1 << (N - round - 1); j += 2) {
      int wn = num[j], ls = num[j + 1];
      if (~S >> j & 1) swap(wn, ls);
      nxt[j >> 1] = wn;
      rk[ls - arr[0]] = (1 << (N - round - 1)) + 1;
    }
    S >>= (N - round - 2);
    memcpy(num, nxt, sizeof num);
  }
  if (lst_win)
    rk[num[0] - arr[0]] = 1;
  else
    rk[num[0] - arr[0]] = 2;
  for (int i = (0), iend = (1 << (N - 1)); i < iend; ++i)
    (val += 1ll * arr[i] * qpow(A, rk[arr[i] - arr[0]]) % P) %= P;
  if (lst_win) {
    if (mp.count((H - val + P) % P)) {
      vector<int> vec = mp[(H - val + P) % P];
      if (arr[0] != 1) swap(vec, rk);
      for (int i : rk) printf("%d ", i);
      for (int i : vec) printf("%d ", i);
      exit(0);
    }
  } else {
    mp[val] = rk;
  }
}
void work(bool tag) {
  int arr[MAXN];
  for (int i = (0), iend = (1 << (N - 1)); i < iend; ++i)
    arr[i] = i + 1 + (tag == 0 ? 0 : (1 << (N - 1)));
  for (int S = (0), Send = (1 << (1 << (N - 1))); S < Send; ++S)
    calc(arr, S, false);
  for (int i = (0), iend = (1 << (N - 1)); i < iend; ++i)
    arr[i] = i + 1 + (tag == 0 ? (1 << (N - 1)) : 0);
  for (int S = (0), Send = (1 << (1 << (N - 1))); S < Send; ++S)
    calc(arr, S, true);
  mp.clear();
}
int main() {
  scanf("%d %d %d", &N, &A, &H);
  pa[0] = A;
  for (int i = (1), iend = (MAXN); i < iend; ++i)
    pa[i] = 1ll * pa[i - 1] * pa[i - 1] % P;
  work(false);
  work(true);
  puts("-1");
  return 0;
}
