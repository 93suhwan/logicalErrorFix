#include <bits/stdc++.h>
using namespace std;
using namespace std::chrono;
void out(long long t) { cerr << t; }
void out(int t) { cerr << t; }
void out(string t) { cerr << t; }
void out(char t) { cerr << t; }
void out(double t) { cerr << t; }
template <class T, class V>
void out(pair<T, V> p);
template <class T>
void out(vector<T> v);
template <class T>
void out(set<T> v);
template <class T, class V>
void out(map<T, V> v);
template <class T>
void out(multiset<T> v);
template <class T, class V>
void out(pair<T, V> p) {
  cerr << "{";
  out(p.first);
  cerr << ",";
  out(p.second);
  cerr << "}";
}
template <class T>
void out(vector<T> v) {
  cerr << "[ ";
  for (T i : v) {
    out(i);
    cerr << " ";
  }
  cerr << "]";
}
template <class T>
void out(set<T> v) {
  cerr << "[ ";
  for (T i : v) {
    out(i);
    cerr << " ";
  }
  cerr << "]";
}
template <class T>
void out(multiset<T> v) {
  cerr << "[ ";
  for (T i : v) {
    out(i);
    cerr << " ";
  }
  cerr << "]";
}
template <class T, class V>
void out(map<T, V> v) {
  cerr << "[ ";
  for (auto i : v) {
    out(i);
    cerr << " ";
  }
  cerr << "]";
}
vector<long long> sieve(long long n) {
  vector<bool> prime(n + 1, true);
  for (long long p = 2; p * p <= n; p++)
    if (prime[p] == true)
      for (long long i = p * p; i <= n; i += p) prime[i] = false;
  vector<long long> v;
  for (long long p = 2; p <= n; p++) {
    if (prime[p]) v.push_back(p);
  }
  return v;
}
long long gcd(long long a, long long b) {
  if (b == 0) {
    return a;
  }
  return gcd(b, a % b);
}
long long nCr(int n, int r) {
  long long p = 1, k = 1;
  if (n - r < r) {
    r = n - r;
  }
  if (r != 0) {
    while (r) {
      p *= n;
      k *= r;
      long long m = gcd(p, k);
      p /= m;
      k /= m;
      n--;
      r--;
    }
  } else {
    p = 1;
  }
  return p;
}
void google(int t) {
  cout << "Case #" << t << ":"
       << " ";
}
int helper(int a[], int oe, int n) {
  int flag = 0;
  if (oe == 1) {
    for (int i = 1; i < n; i++) {
      if (i % 2 == 1) {
        if (a[i - 1] > a[i]) {
          swap(a[i - 1], a[i]);
          flag = 1;
        }
      }
    }
  } else {
    for (int i = 1; i < n; i++) {
      if (i % 2 == 0) {
        if (a[i - 1] > a[i]) {
          swap(a[i - 1], a[i]);
          flag = 1;
        }
      }
    }
  }
  return flag;
}
void solve(int test) {
  int n;
  cin >> n;
  int a[n];
  for (int i = 0; i < n; i++) {
    cin >> a[i];
  }
  int i = 1;
  int bflag = 0;
  while (true) {
    if (is_sorted(a, a + n)) {
      break;
    }
    int flag = 0;
    if (i % 2) {
      flag = helper(a, 1, n);
    } else {
      flag = helper(a, 0, n);
    }
    i++;
  };
  ;
  cout << i - 1 << '\n';
}
int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  auto start = high_resolution_clock::now();
  int t = 1;
  cin >> t;
  int x = t;
  while (t--) {
    solve(x - t);
  }
  auto stop = high_resolution_clock::now();
  auto duration = duration_cast<microseconds>(stop - start);
}
