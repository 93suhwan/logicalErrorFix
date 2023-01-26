#include <bits/stdc++.h>
using namespace std;
template <class T1, class T2>
void maximize(T1 &a, T2 b) {
  if (b > a) a = b;
}
template <class T1, class T2>
void minimize(T1 &a, T2 b) {
  if (b < a) a = b;
}
template <class T>
void read(T &number) {
  bool negative = false;
  register int c;
  number = 0;
  c = getchar();
  while (c != '-' && !isalnum(c)) c = getchar();
  if (c == '-') {
    negative = true;
    c = getchar();
  }
  for (; (c > 47 && c < 58); c = getchar()) number = number * 10 + c - 48;
  if (negative) number *= -1;
}
template <class T, class... Ts>
void read(T &a, Ts &...args) {
  read(a);
  read(args...);
}
int n;
bool appear[1000001];
int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  int t;
  cin >> t;
  for (int _ = (1); _ <= (t); _++) {
    cin >> n;
    vector<long long> remain;
    for (int i = (1); i <= (n); i++) {
      int num;
      cin >> num;
      if (num > n or appear[num])
        remain.push_back(num);
      else
        appear[num] = true;
    }
    sort(remain.begin(), remain.end());
    int ptr = 1;
    bool oke = true;
    for (int num : remain) {
      while (appear[ptr]) ptr++;
      int val = num / 2 - (num % 2 == 0);
      if (val < ptr) {
        oke = false;
        break;
      }
    }
    if (not oke)
      cout << -1 << '\n';
    else
      cout << remain.size() << '\n';
    for (int i = (1); i <= (n); i++) appear[i] = false;
  }
}
