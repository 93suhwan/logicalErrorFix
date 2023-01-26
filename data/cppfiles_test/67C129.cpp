#include <bits/stdc++.h>
using namespace std;
long long my_pow(long long a, long long b) {
  long long ans = 1;
  while (b > 0) {
    if (b & 1) ans = (ans * a);
    a = (a * a);
    b = b / 2;
  }
  return ans;
}
long long my_pow(long long a, long long b, long long m) {
  long long ans = 1;
  while (b > 0) {
    if (b & 1) ans = (ans * a) % m;
    a = (a * a) % m;
    b = b / 2;
  }
  return ans;
}
inline long long my_ceil(long long a, long long b) {
  return a % b == 0 ? (a / b) : (a / b + 1);
}
inline long long my_abs(long long a) { return a >= 0 ? a : -a; }
void solve_ans() {
  long long a, b, c;
  cin >> a >> b >> c;
  long long diff = abs(a - b);
  long long n = diff * 2;
  if (diff <= 1)
    cout << "-1\n";
  else if ((c > n || a > n || b > n))
    cout << "-1\n";
  else {
    if (c > diff)
      cout << (c - diff) << "\n";
    else
      cout << (c + diff) << "\n";
  }
}
int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);
  long long t;
  cin >> t;
  while (t--) {
    solve_ans();
  }
  return 0;
}
