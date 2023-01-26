#include <bits/stdc++.h>
using namespace std;
long long int M = 1e9 + 7;
long long int mE(long long int x, long long int n, long long int M) {
  long long int result = 1;
  while (n > 0) {
    if (n % 2 == 1) result = (result * x) % M;
    x = (x * x) % M;
    n = n / 2;
  }
  return result;
}
void light_yagami() {
  long long int n, a, b;
  cin >> n >> a >> b;
  long long int aa = a, bb = b;
  vector<long long int> v(n);
  for (int i = 0; i < n; i++) v[i] = i + 1;
  if (a == 0 && b == 0) {
    for (int i = 0; i < n; i++) cout << v[i] << " ";
    cout << endl;
  } else if (n % 2 == 0) {
    if (a >= (n / 2) || b >= (n / 2))
      cout << -1 << endl;
    else if (abs(a - b) > 1)
      cout << -1 << endl;
    else {
      if (a > b) {
        long long int i = n - 1ll;
        while (a--) {
          swap(v[i], v[i - 1]);
          i -= 2ll;
        }
      } else {
        long long int i = 1ll;
        while (b--) {
          swap(v[i], v[i - 1]);
          i += 2ll;
        }
      }
      if (aa == bb) swap(v[n - 1], v[n - 2]);
      for (int i = 0; i < n; i++) cout << v[i] << " ";
      cout << endl;
    }
  } else {
    if (a > ((n / 2)) || b > ((n / 2)))
      cout << -1 << endl;
    else if (a == n / 2 && b == n / 2)
      cout << -1 << endl;
    else if (abs(a - b) > 1)
      cout << -1 << endl;
    else {
      if (a > b) {
        long long int i = n - 1ll;
        while (a--) {
          swap(v[i], v[i - 1]);
          i -= 2ll;
        }
      } else {
        long long int i = 1ll;
        while (b--) {
          swap(v[i], v[i - 1]);
          i += 2ll;
        }
      }
      if (aa == bb) swap(v[n - 1], v[n - 2]);
      for (int i = 0; i < n; i++) cout << v[i] << " ";
      cout << endl;
    }
  }
}
int main() {
  int q;
  cin >> q;
  while (q--) {
    light_yagami();
  }
}
