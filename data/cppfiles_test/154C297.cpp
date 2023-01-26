#include <bits/stdc++.h>
using namespace std;
long long int mul(long long int a, long long int b) {
  return ((a % int(998244353)) * (b % int(998244353))) % int(998244353);
}
long long int add(long long int a, long long int b) {
  return ((a % int(998244353)) + (b % int(998244353))) % int(998244353);
}
long long int sub(long long int a, long long int b) {
  long long int ans =
      ((a % int(998244353)) - (b % int(998244353))) % int(998244353);
  return ans;
}
long long int mpow(long long int a, long long int b) {
  long long int ans = 1;
  long long int po = a;
  while (b != 0) {
    if (b % 2) {
      ans = ((ans % int(998244353)) * (po % int(998244353))) % int(998244353);
    }
    po = ((po % int(998244353)) * (po % int(998244353))) % int(998244353);
    b /= 2;
  }
  return ans;
}
struct custom_hash {
  static uint64_t splitmix64(uint64_t x) {
    x += 0x9e3779b97f4a7c15;
    x = (x ^ (x >> 30)) * 0xbf58476d1ce4e5b9;
    x = (x ^ (x >> 27)) * 0x94d049bb133111eb;
    return x ^ (x >> 31);
  }
  size_t operator()(uint64_t x) const {
    static const uint64_t FIXED_RANDOM =
        chrono::steady_clock::now().time_since_epoch().count();
    return splitmix64(x + FIXED_RANDOM);
  }
};
int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(0);
  cout.tie(0);
  long long int t = 1, n, q;
  cin >> t;
  while (t--) {
    long long int a, b, c;
    cin >> a >> b >> c;
    if (c == a + b || a == b + c || b == a + c) {
      cout << "YES\n";
    } else if ((a == b && c % 2 == 0) || (c == b && a % 2 == 0) ||
               (a == c && b % 2 == 0)) {
      cout << "YES\n";
    } else {
      cout << "NO\n";
    }
  }
  return 0;
}
