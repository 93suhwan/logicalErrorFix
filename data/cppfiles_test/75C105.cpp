#include <bits/stdc++.h>
using namespace std;
using vi = vector<int>;
int n, mx;
vi a;
vi dpr, dpl, dpf;
map<int, int> L;
map<int, int> R;
int right(int i) {
  int& ans = dpr[i];
  if (ans != -1) return ans;
  ans = 0;
  if (i == 0 or a[i] >= a[i - 1])
    ans = true;
  else
    ans = not right(i - 1);
  return ans;
}
int left(int i) {
  int& ans = dpl[i];
  if (ans != -1) return ans;
  ans = 0;
  if (i == n - 1 or a[i] >= a[i + 1])
    ans = true;
  else
    ans = not left(i + 1);
  return ans;
}
int f(int i) {
  int g = a[i];
  if (g == mx) return false;
  int l = L[g];
  int r = R[g];
  int& winner = dpf[i];
  if (winner != -1) return winner;
  winner = 0;
  if (r - l + 1 <= 2) winner = true;
  if (a[l] >= a[r] and left(l)) {
    winner = true;
  } else {
    if (a[l] < a[l + 1])
      winner |= not f(l);
    else
      winner |= not right(r);
  }
  if (a[r] >= a[l] and right(r)) {
    winner = true;
  } else {
    if (a[r] < a[r - 1])
      winner |= not f(r);
    else
      winner |= not left(l);
  }
  return winner;
}
int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);
  cin >> n;
  dpl = dpr = dpf = vi(n + 1, -1);
  mx = 0;
  a = vi(n);
  set<int> S;
  for (int i = 0; i < n; ++i) {
    cin >> a[i];
    S.insert(a[i]);
    mx = max(mx, a[i]);
  }
  int l = 0;
  int r = n - 1;
  for (int g : S) {
    if (g == mx) break;
    while (a[l] <= g) ++l;
    while (a[r] <= g) --r;
    L[g] = l;
    R[g] = r;
  }
  if (n <= 2) {
    cout << "Alice" << endl;
  } else {
    int ans0 = (a[0] >= a[n - 1] and left(0)) or
               (a[0] >= a[1] and a[n - 1] > a[0] and not right(n - 1)) or
               not f(0);
    int ansf = (a[n - 1] >= a[0] and right(n - 1)) or
               (a[n - 1] >= a[n - 2] and a[0] > a[n - 1] and not left(0)) or
               not f(n - 1);
    int ans = ans0 or ansf;
    cout << (ans ? "Alice" : "Bob") << endl;
  }
}
