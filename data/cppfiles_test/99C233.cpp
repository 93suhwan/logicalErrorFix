#include <bits/stdc++.h>
using namespace std;
template <typename T, typename T1>
T amax(T &a, T1 b) {
  if (b > a) a = b;
  return a;
}
template <typename T, typename T1>
T amin(T &a, T1 b) {
  if (b < a) a = b;
  return a;
}
template <typename T>
std::istream &operator>>(std::istream &input, std::vector<T> &data) {
  for (T &x : data) input >> x;
  return input;
}
template <typename T>
std::ostream &operator<<(std::ostream &output, const std::pair<T, T> &data) {
  output << "(" << data.first << "," << data.second << ")";
  return output;
}
template <typename T>
std::ostream &operator<<(std::ostream &output, const std::vector<T> &data) {
  for (const T &x : data) output << x << " ";
  return output;
}
vector<long long> pre(long long x) {
  vector<long long> steps;
  long long i = 1;
  long long ans = x;
  while (i <= 4) {
    if (ans & 1) {
      ans += (i);
    } else
      ans -= (i);
    i++;
    steps.push_back(ans);
  }
  return steps;
}
void Here_We_Go() {
  long long n, x;
  cin >> x >> n;
  vector<long long> steps = pre(x);
  long long rem = n % 4;
  if (!rem) {
    for (long long i = 0; i < 4; i++) rem++;
    long long ans = x;
    for (long long i = 0; i < 4; i++) {
      ans += (ans & 1 ? i + 1 : -i - 1);
    }
    cout << steps[rem - 1] << '\n';
    return;
  }
  if (rem == 2) {
    cout << steps[1] << '\n';
    return;
  }
  n -= 1;
  if (rem == 1) {
    long long ans = steps[0];
    if (x & 1)
      ans += ((n / 4) * 4);
    else
      ans -= ((n / 4) * 4);
    cout << ans << '\n';
    return;
  }
  long long ans = steps[rem - 1];
  if (!(x & 1))
    ans += ((n / 4) * 4);
  else
    ans -= ((n / 4) * 4);
  cout << ans << '\n';
  return;
}
int32_t main() {
  ios::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);
  long long tc = 1;
  cin >> tc;
  for (long long i = 1; i < tc + 1; i++) {
    Here_We_Go();
  }
}
