#include <bits/stdc++.h>
using namespace std;
int gcd(int a, int b) {
  if (b == 0) return a;
  a %= b;
  return gcd(b, a);
}
struct custom_hash {
  static uint64_t splitmix64(uint64_t x) {
    x += 0x9e3779b97f4a7c15;
    x = (x ^ (x >> 30)) * 0xbf58476d1ce4e5b9;
    x = (x ^ (x >> 27)) * 0x94d049bb133111eb;
    return x ^ (x >> 31);
  }
  size_t operator()(uint64_t x) const {
    static const uint64_t FIXED_RANDOM =
        chrono::steady_clock::now().time_since_epoch().count();
    return splitmix64(x + FIXED_RANDOM);
  }
};
void run() {
  string ans, temp;
  cin >> ans >> temp;
  int a = ans.size(), b = temp.size();
  if (b > a) {
    cout << "NO";
    return;
  }
  int end;
  if (b % 2 == 0)
    end = 1;
  else
    end = 0;
  int curr = 0, found = 0, start = 0;
  for (int i = 0; i < a; i++) {
    if (ans[i] == temp[start] and i % 2 == curr) {
      start++;
      if (start == b) {
        if (end != curr) found++;
        break;
      }
      if (curr == 0)
        curr = 1;
      else
        curr = 0;
    }
  }
  curr = 1, start = 0;
  for (int i = 0; i < a; i++) {
    if (ans[i] == temp[start] and i % 2 == curr) {
      start++;
      if (start == b) {
        if (end != curr) found++;
        break;
      }
      if (curr == 0)
        curr = 1;
      else
        curr = 0;
    }
  }
  if (found)
    cout << "YES";
  else
    cout << "NO";
}
int main() {
  int a;
  cin >> a;
  while (a--) {
    run();
    cout << endl;
  }
}
