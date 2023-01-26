#include <bits/stdc++.h>
using namespace std;
long long n, starting, neg, pos, both;
string second[100005];
long long GCD(long long a, long long b, long long &x, long long &y) {
  if (b == 0) {
    x = 1;
    y = 0;
    return a;
  }
  long long x1, y1, gcd = GCD(b, a % b, x1, y1);
  x = y1;
  y = x1 - (long long)(a / b) * y1;
  return gcd;
}
long long modfact(long long x) {
  long long result = 1;
  while (x > 1) {
    result = result * x % 998244353;
    x -= 1;
  }
  return result;
}
long long modmult(long long a, long long b) { return a * b % 998244353; }
long long inverse(long long a) {
  long long x, y;
  GCD(a, 998244353, x, y);
  return x;
}
long long choose(long long x, long long k) {
  if (k > x || k < 0) {
    return 0;
  }
  if (k == 0 || k == x) {
    return 1;
  }
  return (modmult(modmult(modfact(x), inverse(modfact(k))),
                  inverse(modfact(x - k))) +
          998244353) %
         998244353;
}
int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  cin >> n;
  for (int i = 0; i < n; i++) {
    cin >> second[i];
    if (second[i] == "W?" || second[i] == "?W") {
      neg++;
    }
    if (second[i] == "B?" || second[i] == "?B") {
      pos++;
    }
    if (second[i] == "??") {
      both++;
    }
    if (second[i] == "BB") {
      starting++;
    }
    if (second[i] == "WW") {
      starting--;
    }
  }
  long long goal = -1 * starting;
  long long x, y;
  long long ans;
  if (both == 0) {
    ans = (choose(neg + pos, neg) * choose(2 * both, goal + both)) % 998244353;
  } else {
    x = choose(neg + pos, 0);
    y = choose(2 * both, goal + neg + both);
    ans = (x * y) % 998244353;
    for (int i = -neg + 1; i <= pos; i++) {
      x = (x * (neg + pos - i - neg + 1)) % 998244353;
      x = ((x * inverse(i + neg)) % 998244353 + 998244353) % 998244353;
      y = (y * (goal - i + both + 1)) % 998244353;
      y = ((y * inverse(2 * both - goal + i - both)) % 998244353 + 998244353) %
          998244353;
      cout << x << " " << y << endl;
      ans += (x * y) % 998244353;
      ans %= 998244353;
    }
  }
  long long none = 1;
  for (int i = 0; i < n; i++) {
    if (second[i] == "??") {
      none *= 2;
    }
    if (second[i] == "BB") {
      none = 0;
    }
    if (second[i] == "WW") {
      none = 0;
    }
  }
  ans -= none;
  bool allbw = true;
  for (int i = 0; i < n; i++) {
    if (!(second[i] == "??" || second[i] == "BW" || second[i] == "B?" ||
          second[i] == "?W")) {
      allbw = false;
    }
  }
  if (allbw) {
    ans++;
  }
  bool allwb = true;
  for (int i = 0; i < n; i++) {
    if (!(second[i] == "??" || second[i] == "WB" || second[i] == "W?" ||
          second[i] == "?B")) {
      allwb = false;
    }
  }
  if (allwb) {
    ans++;
  }
  cout << ans << endl;
  cout.flush();
  return 0;
}
