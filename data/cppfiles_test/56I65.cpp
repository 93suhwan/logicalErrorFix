#include <bits/stdc++.h>
using namespace std;
void invector(vector<long long> p) {
  cout << " in p : ";
  for (auto x : p) {
    cout << x << " ";
  }
  cout << "\n";
}
long long gcd(long long a, long long b) {
  if (b == 0) return a;
  return gcd(b, a % b);
}
const long long mod = 1e9 + 7;
long long power1(long long a, long long b) {
  if (b == 0) return 1;
  long long c = b / 2;
  c = power1(a, c) % mod;
  c = (c * c) % mod;
  if (b % 2 == 1) c = (c * a) % mod;
  return c;
}
vector<long long> dske[6];
map<char, long long> mau;
map<long long, vector<long long> > ds;
signed main() {
  srand(time(NULL));
  ios::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);
  long long k, n;
  cin >> k >> n;
  for (long long i = 0; i < 6; i++) {
    for (long long j = 0; j < 6; j++) {
      if (i == j || i + j == 5) {
        continue;
      }
      dske[i].push_back(j);
    }
  }
  mau['w'] = 0;
  mau['y'] = 5;
  mau['g'] = 1;
  mau['b'] = 4;
  mau['r'] = 2;
  mau['o'] = 3;
  for (long long i = 0; i < n; i++) {
    long long id;
    string x1;
    cin >> id >> x1;
    long long x = mau[x1[0]];
    ds[id].resize(6, 0);
    ds[id][x] = 1;
  }
  long long dem = (1 << k) - 1;
  long long ans = 0;
  while (!ds.empty()) {
    auto p = ds.end();
    dem--;
    p--;
    auto [x, y] = *p;
    if (x == 1) {
      for (long long i = 0; i < 6; i++) {
        ans += y[i];
      }
      break;
    }
    if (!ds.count(x / 2)) {
      vector<long long> temp(6, 1);
      for (long long i = 0; i < 6; i++) {
        long long sum = 0;
        for (auto ke : dske[i]) {
          sum += y[ke];
        }
        temp[i] *= sum;
      }
      ds[x / 2] = temp;
    } else {
      for (long long i = 0; i < 6; i++) {
        long long sum = 0;
        for (auto ke : dske[i]) {
          sum += y[ke];
        }
        ds[x / 2][i] *= sum;
      }
    }
    ds.erase(p);
  }
  ans = ans * power1(4, dem);
  cout << ans % mod << "\n";
}
