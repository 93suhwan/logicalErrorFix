#include <bits/stdc++.h>
using namespace std;
void print(vector<long long>& v) {
  for (auto element : v) {
    cout << element << " ";
  }
  cout << '\n';
}
void print(vector<vector<long long> >& v) {
  for (auto vec : v) {
    print(vec);
  }
}
void print(vector<vector<vector<long long> > >& v) {
  for (auto vec : v) {
    print(vec);
  }
}
void print(pair<long long, long long>& p) {
  cout << "(" << p.first << "," << p.second << ") ";
}
void print(pair<long long, char>& p) {
  cout << "(" << p.first << "," << p.second << ") ";
}
void print(vector<pair<long long, long long> >& v) {
  for (auto p : v) {
    print(p);
  }
  cout << '\n';
}
void print(vector<pair<long long, char> >& v) {
  for (auto p : v) {
    print(p);
  }
  cout << '\n';
}
void print(vector<vector<pair<long long, long long> > >& v) {
  for (auto p : v) {
    print(p);
  }
  cout << '\n';
}
void print(vector<string>& v) {
  for (auto s : v) {
    cout << s << '\n';
  }
}
void print(vector<bool>& v) {
  for (auto b : v) {
    cout << b << " ";
  }
  cout << '\n';
}
void print(vector<vector<bool> >& v) {
  for (auto b : v) {
    print(b);
  }
}
void print(unordered_set<long long>& u) {
  for (auto i = u.begin(); i != u.end(); ++i) cout << (*i) << " ";
  cout << '\n';
}
void print(vector<unordered_set<long long> >& v) {
  for (auto u : v) {
    print(u);
  }
}
long long gcd(long long a, long long b) {
  if (a == 0) return b;
  return gcd(b % a, a);
}
long long powerMOD(long long x, long long y) {
  long long result = 1;
  while (y) {
    if (y & 1) result = result * x % 1000000007;
    y = y / 2;
    x = x * x % 1000000007;
  }
  return result;
}
void build_checkPrime(vector<bool>& checkPrime) {
  checkPrime[0] = checkPrime[1] = false;
  for (int i = 2; i < checkPrime.size(); ++i) {
    if (checkPrime[i] == true) {
      for (int j = i * 2; j < checkPrime.size(); j += i) {
        checkPrime[j] = false;
      }
    }
  }
}
bool isPrime(long long n) {
  if ((n + 1) % 6 != 0 && (n - 1) % 6 != 0) return false;
  double s = sqrt(n);
  if (s * s == n) return false;
  long long f = s;
  long long l = f * f;
  for (long i = f + 1; i < l; ++i) {
    long long p = i - sqrt(i * i - n);
    long long q = n / p;
    if (p < 2 || q < 2) return false;
    if (p * q == n) return false;
    return true;
  }
  return false;
}
bool isPrime(vector<bool>& prime, long long n) {
  if (n < prime.size()) return prime[n];
  if ((n + 1) % 6 != 0 && (n - 1) % 6 != 0) return false;
  double s = sqrt(n);
  if (s * s == n) return false;
  long long f = s;
  long long l = f * f;
  for (long i = f + 1; i < l; ++i) {
    long long p = i - sqrt(i * i - n);
    long long q = n / p;
    if (p < 2 || q < 2) return false;
    if (p * q == n) return false;
    return true;
  }
  return false;
}
void solve() {
  long long N;
  cin >> N;
  vector<long long> A(N);
  for (int i = 0; i < N; ++i) cin >> A[i];
  vector<pair<long long, long long> > result;
  result.reserve(accumulate(A.begin(), A.end(), (long long)0) >> 1);
  priority_queue<pair<long long, long long> > value;
  for (int i = 0; i < N; ++i) {
    if (A[i] > 0) value.push({A[i], i + 1});
  }
  while (value.size() >= 2) {
    pair<long long, long long> p1, p2;
    p1 = value.top();
    value.pop();
    p2 = value.top();
    value.pop();
    result.push_back({p1.second, p2.second});
    p1.first--;
    p2.first--;
    if (p1.first > 0) value.push(p1);
    if (p2.first > 0) value.push(p2);
  }
  cout << result.size() << '\n';
  for (auto r : result) {
    cout << r.first << " " << r.second << '\n';
  }
}
int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);
  int T = 1;
  cin >> T;
  while (T--) {
    solve();
  }
  return 0;
}
