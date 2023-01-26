#include <bits/stdc++.h>
namespace {
using namespace std;
template <class T>
void chmax(T& a, const T& b) {
  a = max(a, b);
}
template <class T>
void chmin(T& a, const T& b) {
  a = min(a, b);
}
using ll = long long;
using P = pair<int, int>;
using VI = vector<int>;
using VVI = vector<VI>;
using VL = vector<ll>;
using VVL = vector<VL>;
bool s[10][10000];
int x[10];
int tmp[10000];
int hist[21];
int ans[10000];
int ptr[21];
}  // namespace
int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  int tt;
  cin >> tt;
  while (tt--) {
    int n, m;
    cin >> n >> m;
    for (int i = 0; i < int(n); ++i) cin >> x[i];
    for (int i = 0; i < int(n); ++i)
      for (int j = 0; j < int(m); ++j) {
        char c;
        cin >> c;
        s[i][j] = c == '1';
      }
    ll mx = -1;
    for (int b = 0; b < int(1 << n); ++b) {
      memset(tmp, 0, sizeof(int) * m);
      ll sm = 0;
      for (int i = 0; i < int(n); ++i) {
        if (b >> i & 1) {
          sm += x[i];
          for (int j = 0; j < int(m); ++j) tmp[j] -= s[i][j];
        } else {
          sm -= x[i];
          for (int j = 0; j < int(m); ++j) tmp[j] += s[i][j];
        }
      }
      memset(hist, 0, sizeof(int) * 21);
      for (int j = 0; j < int(m); ++j) hist[tmp[j] + 10]++;
      ptr[0] = 0;
      for (int i = 0; i < int(20); ++i) ptr[i + 1] = ptr[i] + hist[i];
      for (int j = 0; j < int(m); ++j) {
        sm += tmp[j] * (ptr[tmp[j] + 10]++ + 1);
      }
      if (sm > mx) {
        mx = sm;
        ptr[0] = 0;
        for (int i = 0; i < int(20); ++i) ptr[i + 1] = ptr[i] + hist[i];
        for (int j = 0; j < int(m); ++j) ans[j] = ptr[tmp[j] + 10]++ + 1;
      }
    }
    for (int j = 0; j < int(m); ++j) cout << ans[j] << " \n"[j + 1 == m];
  }
}
