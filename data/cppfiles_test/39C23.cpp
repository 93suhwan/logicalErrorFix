#include <bits/stdc++.h>
using namespace std;
bool comp(pair<long long, char> aa, pair<long long, char> bb) {
  if (aa.first != bb.first) return aa.first > bb.first;
  return aa.second < bb.second;
}
bool comp1(pair<long long, char> aa, pair<long long, char> bb) {
  if (aa.first != bb.first) return aa.first < bb.first;
  return aa.second > bb.second;
}
bool comp2(pair<long long, long long> aa, pair<long long, long long> bb) {
  if (aa.first != bb.first) return aa.first > bb.first;
  return aa.second < bb.second;
}
bool comp3(pair<long long, long long> aa, pair<long long, long long> bb) {
  if (aa.first != bb.first) return aa.first < bb.first;
  return aa.second > bb.second;
}
long long rup(long long ik, long long ikk) {
  if (ik % ikk == 0)
    return ik / ikk;
  else
    return (ik / ikk) + 1;
}
long long gcd(long long a, long long b) {
  if (b == 0) return a;
  return gcd(b, a % b);
}
long long lcm(long long a, long long b) { return (a * b) / gcd(a, b); }
long long modpow(long long x, long long n, long long m) {
  if (n == 0) return 1 % m;
  long long u = modpow(x, n / 2, m);
  u = (u * u) % m;
  if (n % 2 == 1) u = (u * x) % m;
  return u;
}
long long nm(long long a, long long b) { return (b + (a % b)) % b; }
struct hp {
  template <class T1, class T2>
  size_t operator()(const pair<T1, T2>& p) const {
    auto hash1 = hash<T1>{}(p.first);
    auto hash2 = hash<T2>{}(p.second);
    return hash1 ^ hash2;
  }
};
bool yo(string yy) {
  long long jh = yy.length() - 1;
  long long k = 0;
  long long f = 0;
  while (k < jh) {
    if (yy[k] != yy[jh]) {
      f++;
      break;
    }
    k++;
    jh--;
  }
  if (f == 0)
    return true;
  else
    return false;
}
int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);
  long long t = 1;
  while (t--) {
    long long n;
    cin >> n;
    long long i;
    long long j;
    long long k;
    long long f = 0;
    long long v[105];
    for (i = 2; i <= n; i = i + 1) {
      cout << "? ";
      for (j = 1; j <= n - 1; j = j + 1) cout << i << " ";
      cout << 1 << "\n";
      cout.flush();
      cin >> k;
      if (k != 0) f++;
    }
    long long pp = f + 1;
    v[n] = pp;
    for (i = 1; i <= n; i = i + 1) {
      if (i == pp) continue;
      long long jh = abs(i - pp);
      if (i < pp) {
        cout << "? ";
        for (j = 1; j <= n - 1; j = j + 1) cout << 1 + jh << " ";
        cout << 1 << "\n";
        cout.flush();
        cin >> k;
        v[k] = pp - jh;
      } else {
        cout << "? ";
        for (j = 1; j <= n - 1; j = j + 1) cout << 1 << " ";
        cout << 1 + jh << "\n";
        cout.flush();
        cin >> k;
        v[k] = pp + jh;
      }
    }
    cout << "! ";
    for (i = 1; i <= n; i = i + 1) cout << v[i] << " ";
    cout << "\n";
    cout.flush();
  }
}
