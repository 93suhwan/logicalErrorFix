#include <bits/stdc++.h>
using namespace std;
int T;
int N, Q;
string s;
int A[300301], S[300301];
vector<int> seg[1050000];
void Init(int n, int l, int r) {
  seg[n].clear();
  if (l == r) {
    seg[n] = {A[r] + S[r + 1] * 2};
    return;
  }
  int mid = l + r >> 1;
  Init(n << 1, l, mid);
  Init(n << 1 | 1, mid + 1, r);
  merge(seg[n << 1].begin(), seg[n << 1].end(), seg[n << 1 | 1].begin(),
        seg[n << 1 | 1].end(), back_inserter(seg[n]));
}
bool Query(int L, int R, int x, int n, int l, int r) {
  if (r < L || R < l) return false;
  if (L <= l && r <= R) {
    return binary_search(seg[n].begin(), seg[n].end(), x);
  }
  int mid = l + r >> 1;
  return (Query(L, R, x, n << 1, l, mid) ||
          Query(L, R, x, n << 1 | 1, mid + 1, r));
}
int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);
  cin.exceptions(ios::badbit | ios::failbit);
  cin >> T;
  while (T--) {
    cin >> N >> Q >> s;
    int sum = 0;
    A[N] = A[N + 1] = 0;
    S[N] = S[N + 1] = 0;
    for (int i = N - 1; i >= 0; i--) {
      if (s[i] == '+')
        A[i] = (i % 2 ? -1 : 1) * (+1);
      else
        A[i] = (i % 2 ? -1 : 1) * (-1);
      S[i] = S[i + 1] + A[i];
      sum += A[i];
    }
    Init(1, 0, N - 1);
    while (Q--) {
      int L, R;
      cin >> L >> R;
      L--;
      R--;
      int sum = S[L] - S[R + 1];
      if (sum == 0) {
        cout << "0\n";
      } else {
        bool ok = Query(L, R, sum + S[R + 1] * 2, 1, 0, N - 1);
        if (ok)
          cout << "1\n";
        else
          cout << "2\n";
      }
    }
  }
  return 0;
}
