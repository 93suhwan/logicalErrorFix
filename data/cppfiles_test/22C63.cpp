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
const long long K = 300, N = 2e5 + 7;
long long n, m;
long long val[K][K];
long long add[N];
long long last[N];
void make(long long first, long long second, long long day, long long delta,
          long long now) {
  if (first + second < K) {
    for (long long pl = first; pl < first + second; ++pl) {
      val[first + second][(day + pl) % (first + second)] += delta;
    }
  } else {
    for (long long t = 1; day + (t - 1) * (first + second) + first <= m; ++t) {
      long long start = day + (t - 1) * (first + second) + first;
      long long fin = start + second;
      if (start <= now) {
        if (fin > now) {
          add[now] += delta;
          if (fin <= m) add[fin] -= delta;
        }
      } else {
        add[start] += delta;
        if (fin <= m) add[fin] -= delta;
      }
    }
  }
}
long long first[N], second[N];
signed main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  cin >> n >> m;
  for (long long i = (1); i < (n + 1); ++i) {
    cin >> first[i] >> second[i];
  }
  for (long long day = (1); day < (m + 1); ++day) {
    long long op, i;
    cin >> op >> i;
    if (op == 1) {
      last[i] = day;
      make(first[i], second[i], day, 1, day);
    } else {
      make(first[i], second[i], last[i], -1, day);
    }
    add[day] += add[day - 1];
    long long ans = add[day];
    for (long long mod = (1); mod < (K - 1 + 1); ++mod) {
      ans += val[mod][day % mod];
    }
    cout << ans << '\n';
  }
}
