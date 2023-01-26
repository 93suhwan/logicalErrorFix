#include <bits/stdc++.h>
using namespace std;
const int maxn = 1005;
int N;
vector<int> ev, od;
set<int> in;
int sm[15000005];
int b1 = 0, b2 = 0;
void dfs(int n, int len, int msk = 0, int sum = 0) {
  if (b1 || b2) return;
  if (!n) {
    if (sm[sum]) {
      b1 = sm[sum];
      b2 = msk;
      return;
    }
    sm[sum] = msk;
    return;
  }
  if (len) dfs(n - 1, len - 1, msk | (1 << n - 1), sum + od[n - 1]);
  if (n > len) dfs(n - 1, len, msk, sum);
}
int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);
  cin >> N;
  for (int X, i = 1; i <= N; ++i) {
    cin >> X;
    if (X & 1)
      od.push_back(X);
    else
      ev.push_back(X);
    in.insert(X);
  }
  if ((int)in.size() != N) {
    cout << "YES\n";
    for (auto x : in) cout << x << ' ';
    for (int i = 0; i < N - in.size(); ++i) cout << 0 << ' ';
    return 0;
  }
  if (ev.size() >= 3 || (ev.size() >= 1 && od.size() >= 2)) {
    cout << "YES\n";
    int A[3], S = 0;
    if (ev.size() >= 3) {
      for (int i = 0; i < 3; ++i) {
        A[i] = ev.back();
        ev.pop_back();
      }
    } else {
      A[0] = ev.back();
      ev.pop_back();
      A[1] = od.back();
      od.pop_back();
      A[2] = od.back();
      od.pop_back();
    }
    S = (A[0] + A[1] + A[2]) / 2;
    for (int i = 0; i < 3; ++i) {
      A[i] = S - A[i];
      cout << A[i] << ' ';
    }
    while (!od.empty()) {
      cout << od.back() - A[0] << ' ';
      od.pop_back();
    }
    while (!ev.empty()) {
      cout << ev.back() - A[0] << ' ';
      ev.pop_back();
    }
    return 0;
  }
  if (od.size() <= 1) {
    cout << "NO\n";
    return 0;
  }
  dfs(min((int)od.size(), 28), min((int)od.size() / 2, 14));
  if (!b1) {
    cout << "NO\n";
    return 0;
  }
  int same = b1 & b2;
  b1 ^= same;
  b2 ^= same;
  cout << "YES\n";
  cout << 0 << ' ';
  int a0 = 0, i1 = 0, i2 = 0;
  while (b1) {
    for (; i1 < 28; ++i1)
      if (b1 >> i1 & 1) {
        a0 = od[i1] - a0;
        cout << a0 << ' ';
        od[i1] = 0;
        b1 ^= (1 << i1);
        break;
      }
    if (!b1) break;
    for (; i2 < 28; ++i2)
      if (b2 >> i2 & 1) {
        a0 = od[i2] - a0;
        cout << a0 << ' ';
        od[i2] = 0;
        b2 ^= (1 << i2);
        break;
      }
  }
  for (; i2 < 28; ++i2)
    if (b2 >> i2 & 1) {
      a0 = od[i2] - a0;
      cout << a0 << ' ';
      od[i2] = 0;
      b2 ^= (1 << i2);
    }
  for (int x : od)
    if (x) cout << x << ' ';
  return 0;
}
