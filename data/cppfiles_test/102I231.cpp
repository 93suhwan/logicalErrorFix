#include <bits/stdc++.h>
#pragma GCC optimize("O2")
using namespace std;
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
long long int modmul(long long int a, long long int b) {
  return ((a % 1000000007) * (b % 1000000007)) % 1000000007;
}
long long int modadd(long long int a, long long int b) {
  return (((a % 1000000007) + (b % 1000000007))) % 1000000007;
}
long long modExpo(long long a, long long b, long long m) {
  long long result = 1;
  a = a % m;
  while (b > 0) {
    if (b % 2) {
      result = modmul(result, a);
      b--;
    } else {
      a = modmul(a, a);
      b /= 2;
    }
  }
  return result % m;
}
long long int gcd(long long int a, long long int b) {
  if (b == 0)
    return a;
  else
    return gcd(b, a % b);
}
class comp {
 public:
  bool operator()(int a, int b) const { return a > b; }
};
bool compa(pair<long long int, long long int> a,
           pair<long long int, long long int> b) {
  return a.first > b.first;
}
void answerNikalBc(long long int t1) {
  long long int n, m;
  cin >> n >> m;
  string s;
  cin >> s;
  long long int sz = s.size();
  vector<long long int> lr, ud;
  for (auto a : s) {
    if (a == 'L' || a == 'R') {
      lr.push_back(a);
    } else {
      ud.push_back(a);
    }
  }
  long long int maxil = 0, maxir = 0, maxiu = 0, maxid = 0;
  long long int lidx = -1, ridx = -1, uidx = -1, didx = -1;
  long long int szlr = lr.size();
  long long int szud = ud.size();
  for (long long int i = 0; i < szlr; i++) {
    long long int j = i;
    while (j + 1 < szlr && lr[j + 1] == lr[i]) {
      j++;
    }
    if (lr[i] == 'L') {
      if (maxil < j - i + 1) {
        maxil = min(m - 1, j - i + 1);
        lidx = i - 1;
      }
    } else {
      if (maxir < j - i + 1) {
        maxir = min(m - 1, j - i + 1);
        ridx = i - 1;
      }
    }
  }
  for (long long int i = 0; i < szud; i++) {
    long long int j = i;
    while (j + 1 < szud && ud[j + 1] == ud[i]) {
      j++;
    }
    if (ud[i] == 'U') {
      if (maxiu < j - i + 1) {
        maxiu = min(n - 1, j - i + 1);
        uidx = i - 1;
      }
    } else {
      if (maxid < j - i + 1) {
        maxid = min(n - 1, j - i + 1);
        didx = i - 1;
      }
    }
  }
  long long int r, c;
  if (ud.size() == 0) {
    r = 1;
  }
  if (lr.size() == 0) {
    c = 1;
  }
  if (lr.size() != 0) {
    long long int i;
    if (maxil > maxir) {
      c = maxil + 1;
      i = lidx;
    } else {
      c = m - maxir;
      i = ridx;
    }
    for (; i >= 0; i--) {
      if (lr[i] == 'R') {
        c--;
      } else {
        c++;
      }
    }
  }
  if (ud.size() != 0) {
    long long int i;
    if (maxiu > maxid) {
      r = maxiu + 1;
      i = uidx;
    } else {
      r = n - maxid;
      i = didx;
    }
    for (; i >= 0; i--) {
      if (ud[i] == 'U') {
        r++;
      } else {
        r--;
      }
    }
  }
  cout << r << " " << c << "\n";
}
int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  long long int t;
  t = 1;
  cin >> t;
  for (long long int i = 1; i <= t; i++) {
    answerNikalBc(t);
  }
  cerr << "time taken : " << (float)clock() / CLOCKS_PER_SEC << " secs" << endl;
  return 0;
}
