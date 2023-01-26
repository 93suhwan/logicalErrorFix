#include <bits/stdc++.h>
using namespace std;
long long binpow(long long a, long long b, long long MOD = long long(9e18)) {
  long long res = 1;
  a %= MOD;
  while (b) {
    if (b & 1) res *= a;
    a *= a;
    b >>= 1;
    a %= MOD;
    res %= MOD;
  }
  return res % MOD;
}
template <typename T>
void umax(T& a, T b) {
  a = max(a, b);
}
template <typename T>
void umin(T& a, T b) {
  a = min(a, b);
}
clock_t startTime;
double getTime() { return (double)(clock() - startTime) / CLOCKS_PER_SEC; }
template <typename T>
ostream& operator<<(ostream& s, vector<T>& v) {
  for (auto el : v) {
    s << el;
  }
  return s;
}
const long long mod = 998244353;
const long double eps = 1e-8;
int T = 1;
long long n, m, k;
long long a[400001];
long long x[400001];
long long y[400001];
long long pX[400001];
long long pY[400001];
pair<long long, long long> p[400001];
pair<long long, long long> psX[400001];
pair<long long, long long> psY[400001];
void solve() {
  cin >> n >> m >> k;
  vector<int> nums;
  for (int i = (0); i < (n); i++) {
    cin >> x[i];
  }
  for (int i = (0); i < (m); i++) {
    cin >> y[i];
  }
  for (int i = (0); i < (k); i++) {
    cin >> pX[i] >> pY[i];
    nums.push_back(pX[i]);
    nums.push_back(pY[i]);
    p[i] = {pX[i], pY[i]};
  }
  sort(x, x + n);
  sort(y, y + m);
  sort(pX, pX + k);
  sort(pY, pY + k);
  x[n] = int(1e6);
  y[m] = int(1e6);
  long long ans = 0;
  map<int, vector<int> > posX;
  map<int, vector<int> > posY;
  for (int i = (0); i < (k); i++) {
    posX[p[i].first].push_back(p[i].second);
    posY[p[i].second].push_back(p[i].first);
  }
  sort((nums).begin(), (nums).end());
  nums.erase(unique((nums).begin(), (nums).end()), nums.end());
  for (int i : nums) {
    sort((posX[i]).begin(), (posX[i]).end());
    sort((posY[i]).begin(), (posY[i]).end());
  }
  for (int i = (0); i < (k); i++) {
    int idX = lower_bound(x, x + n, p[i].first) - x;
    int idY = lower_bound(y, y + m, p[i].second) - y;
    if (x[idX] == p[i].first && y[idX] == p[i].second) {
      continue;
    }
    if (x[idX] == p[i].first) {
      int b = y[idY];
      idY--;
      int l;
      if (idY < 0)
        l = 0;
      else
        l = y[idY];
      long long cnt = 0;
      long long idL = upper_bound(pY, pY + k, l) - pY;
      long long idR = lower_bound(pY, pY + k, b) - pY;
      idR--;
      cnt = max(0ll, idR - idL + 1);
      long long d = 0;
      idL =
          upper_bound((posX[p[i].first]).begin(), (posX[p[i].first]).end(), l) -
          posX[p[i].first].begin();
      idR =
          lower_bound((posX[p[i].first]).begin(), (posX[p[i].first]).end(), b) -
          posX[p[i].first].begin();
      idR--;
      d = max(0LL, idR - idL + 1);
      cnt -= d;
      ans += cnt;
    } else {
      int b = x[idX];
      idX--;
      int l;
      if (idX < 0)
        l = 0;
      else
        l = x[idX];
      long long cnt = 0;
      long long idL = upper_bound(pX, pX + k, l) - pX;
      long long idR = lower_bound(pX, pX + k, b) - pX;
      idR--;
      cnt = max(0ll, idR - idL + 1);
      long long d = 0;
      idL = upper_bound((posY[p[i].second]).begin(), (posY[p[i].second]).end(),
                        l) -
            posY[p[i].second].begin();
      idR = lower_bound((posY[p[i].second]).begin(), (posY[p[i].second]).end(),
                        b) -
            posY[p[i].second].begin();
      idR--;
      d = max(0LL, idR - idL + 1);
      cnt -= d;
      ans += cnt;
    }
  }
  cout << ans / 2;
}
int main() {
  startTime = clock();
  ios_base::sync_with_stdio(false);
  cin.tie(0);
  cout.tie(0);
  cin >> T;
  while (T--) {
    solve();
    cout << "\n";
  };
  return 0;
}
