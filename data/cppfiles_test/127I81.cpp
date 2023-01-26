#include <bits/stdc++.h>
using namespace std;
long long int modx(long long int a, long long int b) {
  long long int ans = 1;
  while (b) {
    if (b & 1 == 1) {
      ans *= a;
    }
    ans %= 1000000007;
    b = b >> 1;
    a *= a;
    a %= 1000000007;
  }
  ans %= 1000000007;
  return ans;
}
vector<long long int> sieve(long long int n) {
  vector<long long int> vec;
  vector<bool> v(n + 1, false);
  for (long long int i = 2; i * i <= n; i++) {
    for (long long int j = i * i; j <= n; j += i) {
      v[j] = true;
    }
  }
  for (long long int i = 2; i <= n; i++) {
    if (v[i] == false) {
      vec.push_back(i);
    }
  }
  return vec;
}
long long int gcd(long long int a, long long int b) {
  if (b > a) {
    return gcd(b, a);
  }
  if (b == 0) {
    return a;
  }
  return gcd(b, a % b);
}
long long int is_prime(long long int x) {
  if (x < 2) {
    return false;
  } else {
    for (long long int i = 2; i * i <= x; i++) {
      if (x % i == 0) {
        return false;
      }
    }
  }
  return true;
}
long long int binexpo(long long int a, long long int b, long long int c) {
  long long int ans = 1;
  while (b) {
    if (b & 1) {
      ans *= a;
      ans %= c;
    }
    a *= a;
    a %= c;
    b >>= 1;
  }
  return ans;
}
void solve() {
  string s, t;
  cin >> s >> t;
  long long int a = 0;
  long long int b = 0;
  long long int c = 0;
  string ans = "";
  for (long long int i = 0; i < s.size(); i++) {
    if (s[i] == 'a') {
      a++;
    } else if (s[i] == 'b') {
      b++;
    } else if (s[i] == 'c') {
      c++;
    } else {
      ans.push_back(s[i]);
    }
  }
  sort(ans.begin(), ans.end());
  if (t[0] == 'a') {
    if (t[1] == 'b') {
      if (a == 0) {
        while (c--) {
          ans = "c" + ans;
        }
        while (b--) {
          ans = "b" + ans;
        }
      } else {
        while (b--) {
          ans = "b" + ans;
        }
        while (c--) {
          ans = "c" + ans;
        }
        while (a--) {
          ans = "a" + ans;
        }
      }
    } else {
      while (c--) {
        ans = "c" + ans;
      }
      while (b--) {
        ans = "b" + ans;
      }
      while (a--) {
        ans = "a" + ans;
      }
    }
  } else {
    while (a--) {
      ans = "a" + ans;
    }
    while (b--) {
      ans = "b" + ans;
    }
    while (c--) {
      ans = "c" + ans;
    }
  }
  cout << ans << '\n';
}
int32_t main() {
  ios::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);
  ;
  long long int t;
  cin >> t;
  while (t--) {
    solve();
  }
  return 0;
}
