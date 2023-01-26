#include <bits/stdc++.h>
using namespace std;
using namespace chrono;
template <typename T>
void _print(T t) {
  cerr << t;
}
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
void _print(unordered_set<T> v) {
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
int phi(int n) {
  int result = n;
  for (int i = 2; i * i <= n; i++) {
    if (n % i == 0) {
      while (n % i == 0) n /= i;
      result -= result / i;
    }
  }
  if (n > 1) result -= result / n;
  return result;
}
long long binexp(long long a, long long b, long long m) {
  long long ans = 1;
  while (b) {
    if (b & 1) {
      ans = (ans * 1LL * a) % m;
    }
    a = (a * 1LL * a) % m;
    b >>= 1;
  }
  return ans;
}
long long __gcd(long long a, long long b) {
  if (a > b) {
    return __gcd(b, a);
  }
  if (a == 0) {
    return b;
  }
  return __gcd(a, b % a);
}
long long lcm(long long a, long long b) { return (a * b) / __gcd(a, b); }
void Rasengan() {
  long long t;
  cin >> t;
  while (t--) {
    long long n, k;
    cin >> n >> k;
    vector<long long> negv, posv;
    for (int i = (0); i < (n); ++i) {
      long long x;
      cin >> x;
      if (x < 0) negv.push_back(-x);
      if (x > 0) posv.push_back(x);
    }
    long long ans = 0;
    sort((negv).begin(), (negv).end());
    sort((posv).begin(), (posv).end());
    ;
    ;
    long long better = 0;
    ;
    long long pos = 0, neg = 0;
    if (negv.size() > 0) {
      neg = *max_element((negv).begin(), (negv).end());
    }
    if (posv.size() > 0) {
      pos = *max_element((posv).begin(), (posv).end());
    };
    if (neg > pos) {
      ans += neg;
      better = -1;
    } else {
      ans += pos;
      better = 1;
    };
    if (better == -1) {
      long long temp = k;
      while (negv.size() > 0 && temp > 0) {
        negv.pop_back();
        temp--;
      }
    } else {
      long long temp = k;
      while (posv.size() > 0 && temp > 0) {
        posv.pop_back();
        temp--;
      }
    };
    ;
    vector<vector<long long>> final;
    final.push_back(negv);
    final.push_back(posv);
    for (int turn = (0); turn < (2); ++turn) {
      vector<long long> v = final[turn];
      if (v.size() > 0) {
        long long nn = v.size();
        long long ind = nn - 1;
        while (ind >= 0) {
          long long cur = v[ind];
          ans += (2LL * cur);
          ind -= k;
        }
      }
    }
    cout << ans << "\n";
  }
}
int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);
  auto start1 = high_resolution_clock::now();
  Rasengan();
  auto stop1 = high_resolution_clock::now();
  auto duration = duration_cast<microseconds>(stop1 - start1);
  return 0;
}
