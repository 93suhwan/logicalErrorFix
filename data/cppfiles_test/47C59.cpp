#include <bits/stdc++.h>
using namespace std;
void _print(long long t) { cerr << t; }
void _print(string t) { cerr << t; }
void _print(char t) { cerr << t; }
void _print(double t) { cerr << t; }
template <class T, class V>
void _print(pair<T, V> p);
template <class T>
void _print(vector<T> v);
template <class T>
void _print(set<T> v);
template <class T, class V>
void _print(map<T, V> v);
template <class T>
void _print(multiset<T> v);
template <class T, class V>
void _print(pair<T, V> p) {
  cerr << "{";
  _print(p.first);
  cerr << ",";
  _print(p.second);
  cerr << "}";
}
template <class T>
void _print(vector<T> v) {
  cerr << "[ ";
  for (T i : v) {
    _print(i);
    cerr << " ";
  }
  cerr << "]";
}
template <class T>
void _print(set<T> v) {
  cerr << "[ ";
  for (T i : v) {
    _print(i);
    cerr << " ";
  }
  cerr << "]";
}
template <class T>
void _print(multiset<T> v) {
  cerr << "[ ";
  for (T i : v) {
    _print(i);
    cerr << " ";
  }
  cerr << "]";
}
template <class T, class V>
void _print(map<T, V> v) {
  cerr << "[ ";
  for (auto i : v) {
    _print(i);
    cerr << " ";
  }
  cerr << "]";
}
long long mod_add(long long a, long long b, long long m) {
  a = a % m;
  b = b % m;
  return (((a + b) % m) + m) % m;
}
long long mod_mul(long long a, long long b, long long m) {
  a = a % m;
  b = b % m;
  return (((a * b) % m) + m) % m;
}
long long mod_sub(long long a, long long b, long long m) {
  a = a % m;
  b = b % m;
  return (((a - b) % m) + m) % m;
}
long long fact(long long n) {
  long long res = 1;
  for (long long i = 2; i <= n; i++) res = res * i;
  return res;
}
long long nCr(long long n, long long r) {
  return fact(n) / (fact(r) * fact(n - r));
}
void init_code() {}
long long gcd(long long a, long long b) {
  if (b == 0) {
    return a;
  } else {
    return gcd(b, a % b);
  }
}
long long lcm(long long a, long long b) { return (a * b) / (gcd(a, b)); }
long long or_query(long long x, long long y) {
  cout << "or"
       << " " << x << " " << y << endl;
  long long temp;
  cin >> temp;
  return temp;
}
long long and_query(long long x, long long y) {
  cout << "and"
       << " " << x << " " << y << endl;
  long long temp;
  cin >> temp;
  return temp;
}
void solve() {
  long long n, k;
  cin >> n >> k;
  vector<long long> AND(n + 1), OR(n + 1);
  for (long long i = 2; i < n + 1; i++) {
    AND[i] = and_query(1, i);
    OR[i] = or_query(1, i);
  }
  long long AND_23 = and_query(2, 3);
  long long OR_23 = or_query(2, 3);
  vector<long long> isset(32, -1);
  for (long long i = 0; i < 32; i++) {
    for (long long j = 2; j < n + 1; j++) {
      long long temp1 = AND[j] & (1ll << i);
      long long temp2 = OR[j] & (1ll << i);
      if (temp2 != 0 && temp1 != 0) {
        isset[i] = 1;
      }
      if (temp2 == 0 && temp1 == 0) {
        isset[i] = 0;
      }
    }
    if (isset[i] == -1) {
      long long temp1 = AND_23 & (1ll << i);
      long long temp2 = OR_23 & (1ll << i);
      if (temp2 != 0 && temp1 != 0) {
        isset[i] = 0;
      }
      if (temp2 == 0 && temp1 == 0) {
        isset[i] = 1;
      }
    }
  }
  vector<long long> ans(n + 1, 0);
  for (long long i = 0; i < 32; i++) {
    if (isset[i] == 1) {
      ans[1] += 1ll << i;
    }
  }
  for (long long i = 2; i < n + 1; i++) {
    for (long long j = 0; j < 32; j++) {
      long long temp1 = AND[i] & (1ll << j);
      long long temp2 = OR[i] & (1ll << j);
      if (temp1 != 0) {
        ans[i] += (1ll << j);
      }
      if (temp1 == 0 && temp2 != 0 && isset[j] == 0) {
        ans[i] += (1ll << j);
      }
    }
  }
  ans.erase(ans.begin());
  sort(ans.begin(), ans.end());
  cout << "finish"
       << " " << ans[k - 1] << "\n";
}
int32_t main() {
  cin.tie(0);
  cout.tie(0);
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  ;
  long long t;
  t = 1;
  while (t--) {
    solve();
  }
}
