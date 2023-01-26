#include <bits/stdc++.h>
using namespace std;
const int maxA = 3e5 + 5;
long long sum[maxA], cnt[maxA];
void updateSum(int pos, long long val) {
  pos++;
  while (pos < maxA) {
    sum[pos] += val;
    pos += pos & (-pos);
  }
}
long long querySum(int pos) {
  pos++;
  long long ans = 0;
  while (pos > 0) {
    ans += sum[pos];
    pos -= pos & (-pos);
  }
  return ans;
}
void updateCnt(int pos, long long val) {
  pos++;
  while (pos < maxA) {
    cnt[pos] += val;
    pos += pos & (-pos);
  }
}
long long queryCnt(int pos) {
  pos++;
  long long ans = 0;
  while (pos > 0) {
    ans += cnt[pos];
    pos -= pos & (-pos);
  }
  return ans;
}
int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);
  int n;
  cin >> n;
  fill(sum, sum + maxA, 0);
  fill(cnt, cnt + maxA, 0);
  long long a[n];
  for (int x = 0; x < n; x++) {
    cin >> a[x];
  }
  long long ans = 0, sum = 0;
  for (int x = 0; x < n; x++) {
    ans += sum + a[x] * x + querySum(a[x]);
    for (int y = a[x]; y < maxA; y += a[x]) {
      updateSum(y, -a[x]);
      ans -= (queryCnt(maxA - 3) - queryCnt(y - 1)) * a[x];
    }
    updateCnt(a[x], 1);
    sum += a[x];
    if (x > 0) cout << " ";
    cout << ans;
  }
  cout << "\n";
  return 0;
}
