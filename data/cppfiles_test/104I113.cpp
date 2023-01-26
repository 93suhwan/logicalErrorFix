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
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  long long t;
  cin >> t;
  for (long long _ = (0); _ < (t); ++_) {
    long long n;
    cin >> n;
    vi a(n);
    cin >> a;
    long long sum = 0;
    for (auto& e : a) {
      sum += e;
    }
    if (sum & 1) {
      cout << "NO" << '\n';
      continue;
    }
    long long pos = -1, l = 0;
    for (long long i = (0); i < (n); ++i) {
      if ((!a[i]) && l % 2 == 0) {
        pos = i;
        break;
      }
      l += a[i];
    }
    if (pos == -1) {
      cout << "NO" << '\n';
      continue;
    }
    auto solve = [&](vi r) {
      vi ans;
      for (long long i = 0; i < r.size(); i += 2) {
        long long p = r[i] + 1;
        while (p + 1 < r[i + 1]) {
          ans.push_back(p);
          p += 2;
        }
        if (p == r[i + 1]) {
          for (long long j = r[i]; j < r[i + 1]; j += 2) {
            ans.push_back(j);
          }
        } else {
          for (long long j = r[i + 1] - 1; j >= r[i]; j -= 2) {
            ans.push_back(j);
          }
        }
      }
      return ans;
    };
    vi r;
    for (long long i = pos + 1; i < n; ++i) {
      if (a[i]) {
        r.push_back(i - pos);
      }
    }
    vi lp;
    for (long long i = pos - 1; i >= 0; --i) {
      if (a[i]) {
        lp.push_back(pos - i);
      }
    }
    vi ans;
    for (auto& e : solve(r)) {
      ans.push_back(e + pos);
    }
    for (auto& e : solve(lp)) {
      ans.push_back(pos - e);
    }
    cout << "YES" << '\n' << ans.size() << '\n' << ans << '\n';
  }
}
