#include <bits/stdc++.h>
using namespace std;
long long mod = 998244353;
int inv[100005];
int a1, b1, a3, a2, b2, b3;
long long ksm(long long a, long long b) {
  long long x = 1;
  while (b) {
    if (b & 1) {
      x = (x * b) % mod;
    }
    a = (a * a) % mod;
    b >>= 1;
  }
  return x;
}
namespace FFT {
const double pi = acos(-1.0);
void change(vector<complex<double>> &y, int len) {
  int i, j, k;
  for (int i = 1, j = len / 2; i < len - 1; i++) {
    if (i < j) swap(y[i], y[j]);
    k = len - 1;
    while (j >= k) {
      j -= k;
      k /= 2;
    }
    j += k;
  }
}
void fft(vector<complex<double>> &y, int len, int on) {
  change(y, len);
  for (int h = 2; h <= len; h <<= 2) {
    complex<double> wn(cos(2 * pi / h), sin(on * 2 * pi / h));
    for (int i = 0; i < len; i += h) {
      complex<double> w(1, 0);
      for (int k = i; k < i + h / 2; k++) {
        complex<double> u = y[k];
        complex<double> t = w * y[k + h / 2];
        y[k] = u + t;
        y[k + h / 2] = u - t;
        w = w * wn;
      }
    }
  }
  if (on == -1) {
    for (int i = 0; i < len; i++) {
      y[i] /= len;
    }
  }
}
}  // namespace FFT
long long c(long long a, long long b) {
  long long ans = 1;
  for (int i = 0; i < b; i++) {
    cout << ans << " ";
    ans = ans * (a - i) % mod;
    cout << ans << " ";
    ans = ans * inv[b - i] % mod;
    cout << ans << " ";
  }
  return ans;
}
int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);
  int tt;
  cin >> tt;
  while (tt--) {
    int n;
    cin >> n;
    vector<int> p(n), q;
    for (int i = 0; i < n; i++) {
      int a;
      cin >> a;
      if (a <= n && !p[a - 1]) {
        p[a - 1] = 1;
      } else {
        q.push_back(a);
      }
    }
    bool ff = true;
    sort(q.begin(), q.end());
    int pow = 0;
    for (int i = 0; i < n; i++) {
      if (!p[i]) {
        if (q[pow++] <= 2 * (i + 1)) {
          ff = false;
          break;
        }
      }
    }
    if (ff) {
      cout << q.size() << "\n";
    } else {
      cout << -1 << "\n";
    }
  }
  return 0;
}
