#include <bits/stdc++.h>
using namespace std;
inline long long toint(string s) {
  long long v;
  istringstream sin(s);
  sin >> v;
  return v;
}
template <class T>
inline string toString(T x) {
  ostringstream sout;
  sout << x;
  return sout.str();
}
template <class T>
inline T sqr(T x) {
  return x * x;
}
const double EPS = 1e-10;
const double PI = acos(-1.0);
const long long INF = 4e18;
const long long NINF = 1 - INF;
struct POINT {
  double x;
  double y;
};
long long gcd(long long x, long long y) { return y ? gcd(y, x % y) : x; }
long long lcm(long long a, long long b) { return (a / gcd(a, b)) * b; }
long long nCr(long long n, long long r) {
  if (r * 2 > n) r = n - r;
  long long dividend = 1;
  long long divisor = 1;
  for (unsigned int i = 1; i <= r; ++i) {
    dividend *= (n - i + 1);
    divisor *= i;
  }
  return dividend / divisor;
}
template <class T>
pair<T, long long> maxP(vector<T> a, long long size) {
  pair<T, long long> p;
  long long ind = 0;
  T mx = NINF;
  for (long long i = (0); i < (size); ++i) {
    if (mx < a[i]) {
      mx = a[i];
      ind = i;
    }
  }
  p.first = mx;
  p.second = ind;
  return p;
}
template <class T>
pair<T, long long> minP(vector<T> a, long long size) {
  pair<T, long long> p;
  T mn = INF;
  long long ind = 0;
  for (long long i = (0); i < (size); ++i) {
    if (mn > a[i]) {
      mn = a[i];
      ind = i;
    }
  }
  p.first = mn;
  p.second = ind;
  return p;
}
template <class T>
T sumL(vector<T> a, long long size) {
  T sum = 0;
  for (long long i = (0); i < (size); ++i) {
    sum += a[i];
  }
  return sum;
}
long long counT(vector<long long> a, long long left, long long right,
                long long t) {
  return upper_bound(a.begin() + left, a.begin() + right, t) -
         lower_bound(a.begin() + left, a.begin() + right, t);
}
long long kiriage(long long a, long long b) { return a / b + (a % b != 0); }
long long search(vector<long long> &a, long long n) {
  std::vector<long long>::iterator iter = std::find(a.begin(), a.end(), n);
  size_t index = distance(a.begin(), iter);
  return index;
}
int getdigit(long long n) { return log10(n) + 1; }
vector<long long> toBinary(long long bina) {
  vector<long long> ans;
  for (long long i = 0; bina > 0; i++) {
    ans.push_back(bina % 2);
    bina = bina / 2;
  }
  return ans;
}
long long n, m;
long long h, w, k;
string s;
vector<long long> A, B;
map<long long, long long> p;
long long v, e;
int main() {
  long long t;
  cin >> t;
  while (t--) {
    string s;
    cin >> s;
    map<char, long long> p;
    for (long long i = (0); i < (s.size()); ++i) {
      p[s[i]]++;
    }
    if (p['B'] != p['A'] + p['C']) {
      cout << "NO" << endl;
      continue;
    }
    long long fl = 0;
    for (long long i = (0); i < (s.size()); ++i) {
      if (s[i] == 'A') {
        long long I = i;
        while (I < s.size() && I - i >= 2 && s[I] != 'B') {
          I++;
        }
        if (I == s.size()) {
          fl = 1;
          break;
        }
        s[I] = 'D';
        s[i] = 'D';
      } else if (s[i] == 'B') {
        long long I = i;
        while (I < s.size() && I - i >= 2 && (s[I] != 'A' || s[I] != 'C')) {
          I++;
        }
        if (I == s.size()) {
          fl = 1;
          break;
        }
        s[I] = 'D';
        s[i] = 'D';
      } else if (s[i] == 'C') {
        long long I = i;
        while (I < s.size() && I - i >= 2 && s[I] != 'B') {
          I++;
        }
        if (I == s.size()) {
          fl = 1;
          break;
        }
        s[I] = 'D';
        s[i] = 'D';
      } else {
      }
    }
    for (long long i = (0); i < (s.size()); ++i) {
      if (s[i] != 'D') {
        fl = 1;
        break;
      }
    }
    if (fl) {
      cout << "NO" << endl;
      continue;
    } else {
      cout << "YES" << endl;
      continue;
    }
  }
  return 0;
}
