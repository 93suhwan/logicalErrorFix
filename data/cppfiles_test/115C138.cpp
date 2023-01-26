#include <bits/stdc++.h>
using namespace std;
const long long INF = 0x3fffffff;
const long long MOD = 1000000007;
const long long MS = 20000;
long long arr[110];
long long times, hp, damage;
bool iskill(long long damage) {
  long long total = 0;
  for (int index = (1); index < (times); index++)
    if (arr[index] - arr[index - 1] < damage)
      total += arr[index] - arr[index - 1];
    else
      total += damage;
  total += damage;
  if (total >= hp)
    return true;
  else
    return false;
}
int main() {
  cin.tie(nullptr), cout.tie(nullptr), ios::sync_with_stdio(false);
  int n;
  cin >> n;
  while (n--) {
    cin >> times >> hp;
    for (int index = (0); index < (times); index++) cin >> arr[index];
    long long b, e;
    for (b = 1, e = 1e18; b < e;) {
      long long mid = (b + e) / 2;
      if (iskill(mid))
        e = mid;
      else
        b = mid + 1;
    }
    cout << e << endl;
  }
}
