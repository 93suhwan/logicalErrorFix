#include <bits/stdc++.h>
using namespace std;
int const N = 1e5 + 123;
string s;
set<int> st;
int answer = 0;
void Try1(int i, int number, int fake) {
  int n = s.size();
  if (i == s.size()) {
    string tmp = to_string(number);
    if (tmp.size() == s.size() && number % 25 == 0) answer += 1;
    return;
  }
  if (i == n - 2) {
    if (s[i] == 'X') {
      if (fake == -1) {
        for (auto val : {0, 2, 5, 7}) {
          Try1(i + 1, number * 10 + val, val);
        }
      } else {
        if (fake != 0 && fake != 2 && fake != 5 && fake != 7) {
          return;
        }
        Try1(i + 1, number * 10 + fake, fake);
      }
    } else if (s[i] == '_') {
      for (int val : {0, 2, 5, 7}) {
        Try1(i + 1, number * 10 + val, fake);
      }
    } else if (s[i] >= '0' && s[i] <= '9') {
      Try1(i + 1, number * 10 + s[i] - '0', fake);
    }
  } else if (i == n - 1) {
    int last = number % 10;
    if (s[i] == 'X') {
      if (fake == -1) {
        if (last == 2)
          Try1(i + 1, number * 10 + 5, 5);
        else if (last == 0)
          Try1(i + 1, number * 10 + 0, 0);
        else if (last == 5)
          Try1(i + 1, number * 10 + 0, 0);
        else if (last == 7)
          Try1(i + 1, number * 10 + 5, 5);
      } else {
        if (fake != 0 && fake != 5) {
          return;
        }
        if (fake == 0) {
          if (last == 0 || last == 5) {
            Try1(i + 1, number * 10 + fake, fake);
          }
          return;
        } else if (fake == 5) {
          if (last == 2 || last == 7) {
            Try1(i + 1, number * 10 + fake, fake);
          }
          return;
        }
      }
    } else if (s[i] == '_') {
      if (last == 2)
        Try1(i + 1, number * 10 + 5, fake);
      else if (last == 0)
        Try1(i + 1, number * 10 + 0, fake);
      else if (last == 5)
        Try1(i + 1, number * 10 + 0, fake);
      else if (last == 7)
        Try1(i + 1, number * 10 + 5, fake);
      return;
    } else if (s[i] >= '0' && s[i] <= '9') {
      Try1(i + 1, number * 10 + s[i] - '0', fake);
    }
  } else {
    if (s[i] >= '0' && s[i] <= '9') {
      Try1(i + 1, number * 10 + s[i] - '0', fake);
    } else {
      if (s[i] == '_') {
        for (int value = 0; value <= 9; value += 1) {
          Try1(i + 1, number * 10 + value, fake);
        }
      } else if (s[i] == 'X') {
        if (fake != -1) {
          Try1(i + 1, number * 10 + fake, fake);
        } else {
          for (int value = 0; value <= 9; value += 1) {
            Try1(i + 1, number * 10 + value, value);
          }
        }
      }
    }
  }
}
void Try2(int i, int number, int fake) {
  int n = s.size();
  if (i == s.size()) {
    string tmp = to_string(number);
    if (number % 25 == 0) answer += 1;
    return;
  }
  if (i == n - 2) {
    if (s[i] == 'X') {
      if (fake == -1) {
        for (auto val : {0, 2, 5, 7}) {
          Try2(i + 1, number * 10 + val, val);
        }
      } else {
        if (fake != 0 && fake != 2 && fake != 5 && fake != 7) {
          return;
        }
        Try2(i + 1, number * 10 + fake, fake);
      }
    } else if (s[i] == '_') {
      for (int val : {0, 2, 5, 7}) {
        Try2(i + 1, number * 10 + val, fake);
      }
    } else if (s[i] >= '0' && s[i] <= '9') {
      Try2(i + 1, number * 10 + s[i] - '0', fake);
    }
  } else if (i == n - 1) {
    int last = number % 10;
    if (s[i] == 'X') {
      if (fake == -1) {
        if (last == 2)
          Try2(i + 1, number * 10 + 5, 5);
        else if (last == 0)
          Try2(i + 1, number * 10 + 0, 0);
        else if (last == 5)
          Try2(i + 1, number * 10 + 0, 0);
        else if (last == 7)
          Try2(i + 1, number * 10 + 5, 5);
      } else {
        if (fake != 0 && fake != 5) {
          return;
        }
        if (fake == 0) {
          if (last == 0 || last == 5) {
            Try2(i + 1, number * 10 + fake, fake);
          }
          return;
        } else if (fake == 5) {
          if (last == 2 || last == 7) {
            Try2(i + 1, number * 10 + fake, fake);
          }
          return;
        }
      }
    } else if (s[i] == '_') {
      if (last == 2)
        Try2(i + 1, number * 10 + 5, fake);
      else if (last == 0)
        Try2(i + 1, number * 10 + 0, fake);
      else if (last == 5)
        Try2(i + 1, number * 10 + 0, fake);
      else if (last == 7)
        Try2(i + 1, number * 10 + 5, fake);
      return;
    } else if (s[i] >= '0' && s[i] <= '9') {
      Try2(i + 1, number * 10 + s[i] - '0', fake);
    }
  } else {
    if (s[i] >= '0' && s[i] <= '9') {
      Try2(i + 1, number * 10 + s[i] - '0', fake);
    } else {
      if (s[i] == '_') {
        for (int value = 0; value <= 9; value += 1) {
          Try2(i + 1, number * 10 + value, fake);
        }
      } else if (s[i] == 'X') {
        if (fake != -1) {
          Try2(i + 1, number * 10 + fake, fake);
        } else {
          for (int value = 0; value <= 9; value += 1) {
            Try2(i + 1, number * 10 + value, value);
          }
        }
      }
    }
  }
}
void TestCase() {
  cin >> s;
  int cnt = 0;
  string tmp;
  string ss = s;
  if (s.size() > 1) {
    for (int i = 0; i < s.size() - 2; i++) {
      if (s[i] == '_') cnt += 1;
    }
    for (int i = 0; i < s.size() - 2; i++) {
      if (s[i] != '_') {
        tmp += s[i];
      }
    }
    if (s.size() - 2 >= 0) {
      for (int i = s.size() - 2; i < s.size(); i++) {
        tmp += s[i];
      }
    }
  } else
    tmp = s;
  s = tmp;
  int res = 1;
  if (cnt >= 1 && ss[0] == '_')
    res = 9 * pow(10, cnt - 1);
  else {
    res = pow(10, cnt);
  }
  if (ss[0] == '_' && ss.size() > 2) {
    Try2(0, 0, -1);
  } else {
    Try1(0, 0, -1);
  }
  cout << answer * res << '\n';
}
int main() {
  ios_base ::sync_with_stdio(false);
  cin.tie();
  cout.tie();
  int T = 1;
  while (T--) {
    TestCase();
  }
}
