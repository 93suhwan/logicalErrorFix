#include <bits/stdc++.h>
using namespace std;
using vi = vector<long long>;
template <typename T>
std::istream& operator>>(std::istream& input, std::pair<T, T>& data) {
  input >> data.first >> data.second;
  return input;
}
template <typename T>
std::istream& operator>>(std::istream& input, std::vector<T>& data) {
  for (T& first : data) input >> first;
  return input;
}
template <typename T>
std::ostream& operator<<(std::ostream& output, const pair<T, T>& data) {
  output << "(" << data.first << "," << data.second << ")";
  return output;
}
template <typename T>
std::ostream& operator<<(std::ostream& output, const std::vector<T>& data) {
  for (const T& first : data) output << first << " ";
  return output;
}
std::ostream& operator<<(std::ostream& output, const __int128& first) {
  __int128 n = first;
  if (n == 0) {
    output << "0";
    return output;
  }
  if (n < 0) {
    n = -n;
    output << "-";
  }
  string s;
  while (n) {
    s += '0' + (n % 10);
    n /= 10;
  }
  reverse(s.begin(), s.end());
  cout << s;
  return output;
}
long long div_up(long long a, long long b) {
  return a / b + ((a ^ b) > 0 && a % b);
}
long long div_down(long long a, long long b) {
  return a / b - ((a ^ b) < 0 && a % b);
}
long long math_mod(long long a, long long b) { return a - b * div_down(a, b); }
template <class T>
using V = vector<T>;
template <class T>
bool ckmin(T& a, const T& b) {
  return b < a ? a = b, 1 : 0;
}
template <class T>
bool ckmax(T& a, const T& b) {
  return a < b ? a = b, 1 : 0;
}
long long gcd(long long a, long long b) {
  while (b) {
    tie(a, b) = make_pair(b, a % b);
  }
  return a;
}
long long Bit(long long mask, long long bit) { return (mask >> bit) & 1; }
signed main() {
  long long n;
  cin >> n;
  vi next(n + 1);
  for (long long i = (1); i < (n + 1); ++i) {
    {
      cout << "? ";
      for (long long j = (1); j < (n + 1); ++j) {
        if (i == j) {
          cout << 2 << ' ';
        } else {
          cout << 1 << ' ';
        }
      }
      cout << endl;
      long long ans;
      cin >> ans;
      if (ans && ans != i) {
        assert(ans < i);
        next[i] = ans;
      }
    }
    {
      cout << "? ";
      for (long long j = (1); j < (n + 1); ++j) {
        if (i == j) {
          cout << 1 << ' ';
        } else {
          cout << 2 << ' ';
        }
      }
      cout << endl;
      long long ans;
      cin >> ans;
      if (ans && ans != i) {
        assert(ans < i);
        next[ans] = i;
      }
    }
  }
  vi in(n + 1);
  for (long long i = (1); i < (n + 1); ++i) {
    in[next[i]] = 1;
  }
  long long one = -1;
  for (long long i = (1); i < (n + 1); ++i) {
    if (!in[i]) {
      one = i;
    }
  }
  vi ans(n + 1);
  long long u = one;
  for (long long val = (1); val < (n + 1); ++val) {
    ans[val] = u;
    u = next[u];
  }
  cout << "! ";
  for (long long i = (1); i < (n + 1); ++i) {
    cout << ans[i] << ' ';
  }
  cout << endl;
}
