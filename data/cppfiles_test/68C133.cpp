#include <bits/stdc++.h>
using namespace std;
void print(vector<int> &a) {
  for (int i = 0; i < a.size(); i++) {
    cout << a[i] << " ";
  }
}
bool safe(int x, int y, int n, int m, vector<vector<bool>> &v) {
  if (x >= 0 && y >= 0 && x < n && y < m && v[x][y] == 0) return true;
  return false;
}
int sumof(int n) {
  int ans = 0;
  while (n) {
    int temp = n % 10;
    ans += temp;
    n /= 10;
  }
  return ans;
}
void solve() {
  long long k;
  cin >> k;
  double chk = (double)sqrt(k);
  if (chk == (int)chk) {
    cout << chk << " " << 1 << "\n";
    return;
  }
  long long n = (long long)chk + 1;
  if ((long long)n * (n - 1) + 1ll == k) {
    cout << n << " " << n << "\n";
    return;
  } else {
    long long corner = (long long)n * (n - 1) + 1ll;
    if (k > corner) {
      long long diff = k - corner;
      cout << n << " " << n - diff << "\n";
    } else {
      long long diff = corner - k;
      cout << n - diff << " " << n << "\n";
    }
  }
}
int main() {
  ios::sync_with_stdio(false);
  cin.tie(0), cout.tie(0);
  int t = 1;
  cin >> t;
  while (t--) {
    solve();
  }
  return 0;
}
