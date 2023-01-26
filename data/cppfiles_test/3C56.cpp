#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using pii = pair<int, int>;
constexpr int INF = 0x3f3f3f3f;
bool Ok(string a, string b) {
  if (a.size() != b.size()) {
    return false;
  }
  char x = '?';
  for (int i = 0; i < (int)a.size(); ++i) {
    if (a[i] == b[i] || b[i] == '_') {
      continue;
    }
    if (b[i] == 'X') {
      if (x == '?') {
        x = a[i];
      }
      if (x != a[i]) {
        return false;
      }
      continue;
    }
    return false;
  }
  return true;
}
int BF(const string& s) {
  int res = 0;
  for (int i = 0; i < 100; i += 25) {
    if (Ok(to_string(i), s)) {
      ++res;
    }
  }
  return res;
}
pair<ll, int> Calc(char f, char a, char b) {
  if (f == '0') {
    return {0, 0};
  }
  if (a == 'X' && b == 'X') {
    if (f == 'X') {
      return {0, 0};
    }
    return {1, 1};
  }
  if (a == '_' && b == '_') {
    return {4, -1};
  }
  if (a == '_' && b == 'X') {
    if (f == 'X') {
      return {2, 1};
    }
    return {4, 2};
  }
  if (a == 'X' && b == '_') {
    if (f == 'X') {
      return {3, 3};
    }
    return {4, 4};
  }
  if (a == '_') {
    if (b != '5' && b != '0') {
      return {0, 0};
    }
    return {2, -1};
  }
  if (a == 'X') {
    if (b != '5' && b != '0') {
      return {0, 0};
    }
    if (f == 'X' && b == '0') {
      return {1, 1};
    }
    return {2, 2};
  }
  if (b == '_') {
    if (a != '2' && a != '5' && a != '7' && a != '0') {
      return {0, 0};
    }
    return {1, -1};
  }
  if (b == 'X') {
    if (a != '2' && a != '5' && a != '7' && a != '0') {
      return {0, 0};
    }
    if (f == 'X' && (a == '5' || a == '0')) {
      return {0, 0};
    }
    return {1, 1};
  }
  string s;
  s += a;
  s += b;
  if (stoi(s) % 25 != 0) {
    return {0, 0};
  }
  return {1, -1};
}
void SolveTask() {
  string s;
  cin >> s;
  if (s.size() < 3) {
    cout << (BF(s)) << '\n';
    return;
    ;
  }
  auto [ans, x] = Calc(s[0], s[s.size() - 2], s[s.size() - 1]);
  s.pop_back();
  s.pop_back();
  if (x == -1) {
    if (s[0] == 'X') {
      x = 9;
    } else {
      x = 10;
    }
  } else {
    x = 1;
  }
  if (s[0] == '_') {
    ans *= 9;
  }
  if (s[0] == 'X') {
    ans *= x;
    x = 1;
  }
  for (int i = 1; i < (int)s.size(); ++i) {
    if (s[i] == 'X') {
      ans *= x;
      x = 1;
    } else if (s[i] == '_') {
      ans *= 10;
    }
  }
  cout << ans << "\n";
}
int main() {
  std::ios_base::sync_with_stdio(false);
  std::cin.tie(nullptr);
  int test_cases = 1;
  for (int yt = 1; yt <= test_cases; ++yt) {
    SolveTask();
  }
  return 0;
}
