#include <bits/stdc++.h>
using namespace std;
long long int M = 1e9 + 7;
long long int gcd(long long int a, long long int b) {
  if (b == 0) return a;
  return gcd(b, a % b);
}
void setdecimals(long long int x) { cout << fixed << setprecision((int)x); }
void print(int a) { cerr << a; }
void print(long long int a) { cerr << a; }
void print(char a) { cerr << a; }
void print(string a) { cerr << a; }
void print(bool a) { cerr << a; }
template <class T, class X>
void print(pair<T, X> p);
template <class T>
void print(vector<T> v);
template <class T>
void print(set<T> v);
template <class T, class X>
void print(map<T, X> v);
template <class T>
void print(multiset<T> v);
template <class T, class X>
void print(pair<T, X> p) {
  cerr << "{";
  print(p.first);
  cerr << ",";
  print(p.second);
  cerr << "}";
}
template <class T>
void print(vector<T> v) {
  cerr << "[ ";
  for (T i : v) {
    print(i);
    cerr << " ";
  }
  cerr << "]";
}
template <class T>
void print(set<T> v) {
  cerr << "[ ";
  for (T i : v) {
    print(i);
    cerr << " ";
  }
  cerr << "]";
}
template <class T>
void print(multiset<T> v) {
  cerr << "[ ";
  for (T i : v) {
    print(i);
    cerr << " ";
  }
  cerr << "]";
}
template <class T, class X>
void print(map<T, X> v) {
  cerr << "[ ";
  for (auto i : v) {
    print(i);
    cerr << " ";
  }
  cerr << "]";
}
long long int fact(long long int x) {
  long long int ans = 1;
  for (long long int i = 1; i < x + 1; i++) {
    ans *= i;
  }
  return ans;
}
vector<long long int> prime(long long int n) {
  vector<long long int> sieve(n + 1, 1);
  vector<long long int> arr;
  for (long long int i = 2; i * i <= n; i++) {
    for (long long int j = i * i; j <= n; j = j + i) {
      if (sieve[j] == 1) sieve[j] = 0;
    }
  }
  for (long long int i = 1; i < n + 1; i++) {
    if (sieve[i]) arr.push_back(i);
  }
  return arr;
}
void input() {}
void solve() {
  long long int n;
  cin >> n;
  vector<pair<long long int, long long int> > v(n);
  for (long long int i = 0; i < n; i++) {
    long long int k;
    cin >> k;
    long long int mx = INT_MIN;
    for (long long int j = 0; j < k; j++) {
      long long int x;
      cin >> x;
      mx = max(mx, x - j);
    }
    v[i] = {mx, k};
  }
  sort(v.begin(), v.end());
  long long int l = 1, h = 1e9;
  while (l <= h) {
    long long int mid = (l + h) / 2;
    long long int pow = mid;
    long long int flag = 1;
    for (auto i : v) {
      if (pow <= i.first) {
        flag = 0;
        break;
      } else
        pow += i.second;
    }
    if (flag) {
      h = mid - 1;
    } else
      l = mid + 1;
  }
  cout << l << "\n";
}
int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  input();
  long long int t, i;
  cin >> t;
  i = 1;
  while (i <= t) {
    solve();
    i++;
  }
  return 0;
}
