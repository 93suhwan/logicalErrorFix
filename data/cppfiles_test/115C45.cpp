#include <bits/stdc++.h>
using namespace std;
long long n, h;
long long v[100005];
long long verif(long long k) {
  long long ans = k;
  for (int i = 1; i < n; i++) {
    ans += min(k, v[i + 1] - v[i]);
  }
  return ans;
}
void solve() {
  cin >> n >> h;
  for (int i = 1; i <= n; i++) cin >> v[i];
  long long st = 1, dr = (1LL << 61), mid, rasp = 0;
  while (st <= dr) {
    mid = (st + dr) / 2;
    if (verif(mid) >= h)
      rasp = mid, dr = mid - 1;
    else
      st = mid + 1;
  }
  cout << rasp << '\n';
}
int main() {
  int teste;
  cin >> teste;
  while (teste--) {
    solve();
  }
}
