#include <bits/stdc++.h>
using namespace std;
long long mod = ((1e9) + 7);
int modi = ((1e9) + 7);
int r[] = {0, 1, 0, -1};
int c[] = {1, 0, -1, 0};
int rr[8] = {-1, 0, 1, -1, 1, -1, 0, 1};
int cc[8] = {-1, -1, -1, 0, 0, 1, 1, 1};
void fast() {
  ios::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);
}
long long fpwm(long long base, long long power) {
  long long ans = 1;
  while (power > 0) {
    if (power & 1) ans = (ans * base);
    base = (base * base);
    power >>= 1;
  }
  return ans;
}
long long fp(long long base, long long power) {
  long long ans = 1;
  while (power > 0) {
    if (power & 1) ans = (ans * base) % mod;
    base = (base * base) % mod;
    power >>= 1;
  }
  return ans;
}
int main() {
  fast();
  long long k, val;
  cin >> k;
  val = fpwm(2, k);
  val -= 2;
  val = fp(4, val);
  val = (val * 6);
  val = (val % mod);
  cout << val;
  return 0;
}
