#include <bits/stdc++.h>
using namespace std;
const long long INF = 1e17;
const long long NINF = (-1) * INF;
long long i, j;
long long prime_flag[1000000];
void calculate_prime_flag() {
  prime_flag[0] = prime_flag[1] = 1;
  for (i = 2; i < 1000000; i++) {
    if (prime_flag[i] == 0) {
      for (j = i * i; j < 1000000; j += i) {
        prime_flag[j] = 1;
      }
    }
  }
}
long long unsigned int power(long long unsigned int x, long long unsigned int y,
                             long long unsigned int p) {
  int res = 1;
  x = x % p;
  if (x == 0) return 0;
  while (y > 0) {
    if (y & 1) res = (res * x) % p;
    y = y >> 1;
    x = (x * x) % p;
  }
  return res;
}
void solve() {
  string str;
  cin >> str;
  string T;
  cin >> T;
  map<char, long long> mp;
  for (auto &value : str) mp[value]++;
  string rem = "";
  for (auto &value : mp) {
    if (value.first != 'a' && value.first != 'b' && value.first != 'c') {
      for (int i = 1; i <= value.second; i++) rem += value.first;
    }
  }
  if (mp['a'] == 0 || mp['b'] == 0 || mp['c'] == 0) {
    for (auto &value : mp) {
      for (int i = 1; i <= value.second; i++) cout << value.first;
    }
    cout << "\n";
    return;
  } else {
    for (auto &value : mp) {
      if (value.first == 'a') {
        for (int i = 1; i <= value.second; i++) {
          cout << value.first;
        }
      }
    }
    if (T[1] == 'b') {
      for (auto &value : mp) {
        if (value.first == 'c') {
          for (int i = 1; i <= value.second; i++) {
            cout << value.first;
          }
        }
      }
      for (auto &value : mp) {
        if (value.first == 'b') {
          for (int i = 1; i <= value.second; i++) {
            cout << value.first;
          }
        }
      }
    } else {
      for (auto &value : mp) {
        if (value.first == 'b') {
          for (int i = 1; i <= value.second; i++) {
            cout << value.first;
          }
        }
      }
      for (auto &value : mp) {
        if (value.first == 'c') {
          for (int i = 1; i <= value.second; i++) {
            cout << value.first;
          }
        }
      }
    }
    for (auto &value : rem) cout << value;
    cout << "\n";
    return;
  }
}
int main() {
  long long T;
  cin >> T;
  while (T-- > 0) {
    solve();
  }
  return 0;
}
