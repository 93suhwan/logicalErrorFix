#include <bits/stdc++.h>
#pragma GCC optimize("unroll-loops")
#pragma GCC optimize("O3")
#pragma GCC target("avx2")
using namespace std;
void solve() {
  long long n;
  cin >> n;
  vector<long long> arr(n);
  for (long long i = 0; i < n; i++) cin >> arr[i];
  long long L[n], R[n];
  L[0] = -1;
  R[n - 1] = n;
  long long l = -1;
  for (long long i = 1; i < n; i++) {
    if (arr[i] > arr[i - 1]) l = i - 1;
    L[i] = l;
  }
  for (long long i = n - 2; i >= 0; i--) {
    if (arr[i + 1] < arr[i]) l = i + 1;
    R[i] = l;
  }
  long long lp = 0, rp = n - 1;
  bool la = (arr[0] > arr[n - 1]);
  long long al = 1;
  while (lp < rp) {
    if (la) {
      if (L[lp] != -1) {
        if (R[rp] != -1) {
          al ^= 1;
          break;
        } else {
          la = 0;
          continue;
        }
      }
      if (rp >= R[lp] && (R[lp] - lp - 1) % 2 == 0)
        break;
      else {
        if (R[rp] == -1)
          rp--;
        else {
          break;
        }
        if (arr[rp] < arr[lp])
          la = 1;
        else
          la = 0;
      }
    } else {
      if (R[rp] != -1) {
        if (L[lp] != -1) {
          al ^= 1;
          break;
        } else {
          la = 1;
          continue;
        }
      }
      if (lp <= L[rp] && (rp - L[rp] - 1) % 2 == 0)
        break;
      else {
        if (L[lp] == -1)
          lp++;
        else {
          break;
        }
        if (arr[rp] < arr[lp])
          la = 1;
        else
          la = 0;
      }
    }
    al ^= 1;
  }
  if (al)
    cout << "Alice\n";
  else
    cout << "Bob\n";
  return;
}
int32_t main() {
  ios_base::sync_with_stdio(false);
  cin.tie(0);
  cout.tie(0);
  long long tc = 1;
  for (long long i = 0; i < tc; i++) solve();
}
