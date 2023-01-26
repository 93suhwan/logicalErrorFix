#include <bits/stdc++.h>
const long long mod = 1000 * 1000 * 1000 + 7;
const long long mod1 = 998244353;
const long long INF = 1ll * 1000 * 1000 * 1000 * 1000 * 1000 * 1000 + 7;
using namespace std;
long long power(long long x, long long y) {
  long long res = 1;
  while (y > 0) {
    if (y & 1) res = (long long)(res * x);
    y = y >> 1;
    x = (long long)(x * x);
  }
  return res;
}
template <typename F, typename S>
ostream& operator<<(ostream& ostream, pair<F, S>& p) {
  cout << p.first << " " << p.second;
  return ostream;
}
template <typename T>
ostream& operator<<(ostream& ostream, vector<T>& v) {
  for (auto& element : v) {
    cout << element << " ";
  }
  return ostream;
}
template <typename T>
ostream& operator<<(ostream& ostream, vector<vector<T>>& v) {
  for (auto& row : v) {
    for (auto& cell : row) {
      cout << cell << " ";
    }
    cout << "\n";
  }
  return ostream;
}
template <typename F, typename S>
istream& operator>>(istream& istream, pair<F, S>& p) {
  cin >> p.first >> p.second;
  return istream;
}
template <typename T>
istream& operator>>(istream& istream, vector<T>& v) {
  for (auto& element : v) {
    cin >> element;
  }
  return istream;
}
int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);
  long long T;
  cin >> T;
  while (T--) {
    long long n;
    cin >> n;
    vector<long long> act(n);
    cin >> act;
    long long l = 1, r = 1e9l;
    while (l < r) {
      long long mid = (l + r + 1) / 2;
      bool flag = true;
      vector<long long> temp(n);
      temp = act;
      for (long long(i) = (n - 1); (i) >= (2); --(i)) {
        if (temp[i] < mid) {
          flag = false;
          break;
        }
        long long can_give = (temp[i] - mid) / 3;
        can_give *= 3;
        if (can_give > act[i]) {
          can_give = act[i] / 3;
          can_give *= 3;
        }
        temp[i] -= can_give;
        temp[i - 1] += can_give / 3;
        temp[i - 2] += (2 * can_give) / 3;
      }
      if (temp[0] < mid || temp[1] < mid) flag = false;
      if (flag)
        l = mid;
      else
        r = mid - 1;
    }
    cout << l << "\n";
  }
  return 0;
}
