#include <bits/stdc++.h>
using namespace std;
const long long mod = 1e9 + 7;
const long long N = 1e5 + 5;
long long powm(long long a, long long b) {
  a %= mod;
  long long res = 1;
  while (b) {
    if (b & 1) res = res * a % mod;
    a = a * a % mod;
    b >>= 1;
  }
  return res;
}
int arr[N][5];
bool check(int x, int y) {
  int cnt = 0;
  for (int i = 0; i < 5; i++)
    if (arr[x][i] < arr[y][i]) cnt++;
  if (cnt >= 3) return true;
  return false;
}
void sol() {
  int n;
  cin >> n;
  set<int> s;
  for (int i = 0; i < n; i++) s.insert(i);
  for (int i = 0; i < n; i++) {
    for (int j = 0; j < 5; j++) {
      cin >> arr[i][j];
    }
  }
  while (((long long)s.size()) > 1) {
    auto pos = s.begin();
    int x = *pos;
    int y = *(++pos);
    if (check(x, y))
      s.erase(y);
    else
      s.erase(x);
  }
  int pos = *s.begin();
  for (int i = 0; i < n; i++) {
    if (i != pos && check(i, pos)) {
      cout << "-1\n";
      return;
    }
  }
  cout << pos + 1 << '\n';
}
int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  int t;
  cin >> t;
  while (t--) {
    sol();
  }
}
