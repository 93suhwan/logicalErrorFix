#include <bits/stdc++.h>
using namespace std;
int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(nullptr);
  string s;
  cin >> s;
  if (s.length() == 1) {
    if (s[0] == '0' || s[0] == 'X' || s[0] == '_')
      cout << 1;
    else
      cout << 0;
    return 0;
  }
  if (s.length() == 2) {
    if (s[0] == 'X' && s[1] == 'X')
      cout << 0;
    else if ((s[0] == '2' || s[0] == '5' || s[0] == '7') && s[1] == 'X')
      cout << 1;
    else if ((s[0] != '2' || s[0] != '5' || s[0] != '7') && s[1] == 'X')
      cout << 0;
    else if (s[0] == 'X' && s[1] == '0')
      cout << 1;
    else if (s[0] == 'X' && s[1] == '5')
      cout << 2;
    else if (s[0] == 'X' && s[1] != '0' && s[1] != '5')
      cout << 0;
    else if (s[0] >= '0' && s[0] <= '9' && s[1] >= '0' && s[1] <= '9') {
      if (stoi(s) != 25 && stoi(s) != 50 && stoi(s) != 75)
        cout << 0;
      else
        cout << 1;
    } else if (s[0] >= '0' && s[0] <= '9' && s[1] == '_') {
      if (s[0] == '5')
        cout << 1;
      else if (s[0] == '2' || s[0] == '7')
        cout << 1;
      else
        cout << 0;
    } else if (s[0] == '_' && s[1] >= '0' && s[1] <= '9') {
      if (s[1] != 0 || s[1] != 5)
        cout << 0;
      else if (s[1] == 5)
        cout << 2;
      else if (s[1] == 0)
        cout << 1;
    } else if (s[0] == 'X' && s[1] == '_') {
      cout << 3;
    } else if (s[0] == '_' && s[1] == 'X')
      cout << 3;
    else if (s[0] == '_' && s[0] == '_')
      cout << 3;
    return 0;
  }
  bool ok = 1;
  for (int i = 0; i < s.length(); ++i)
    if (s[i] == '_' || s[i] == 'X') ok = 0;
  if (ok) {
    cout << (stoi(s) % 25 == 0 ? 1 : 0);
    return 0;
  }
  if (s[0] == 'X' && s[s.length() - 1] == 'X' && s[s.length() - 2] == 'X') {
    cout << 0;
    return 0;
  }
  if (s[s.length() - 1] == 'X') {
    if (s[s.length() - 2] == 'X') {
      int cnt_ = 0;
      for (int i = 0; i < s.length() - 2; ++i) {
        if (s[i] == '_') cnt_++;
      }
      if (s[0] == '_')
        cout << 9 * pow(10, cnt_ - 1);
      else
        cout << pow(10, cnt_);
    } else {
      int cnt_ = 0;
      bool haveX = 0;
      for (int i = 0; i < s.length() - 1; ++i) {
        if (s[i] == '_') cnt_++;
        if (s[i] == 'X') haveX = 1;
      }
      if (s[0] == 'X') {
        if (s[s.length() - 2] == '_') {
          cout << 2 * pow(10, cnt_ - 1);
        } else {
          if (s[s.length() - 2] != '7' && s[s.length() - 2] != '2')
            cout << 0;
          else
            cout << pow(10, cnt_);
        }
      } else {
        if (s[0] == '_') {
          int cnt_ = 0;
          bool haveX = 0;
          for (int i = 0; i < s.length() - 1; ++i) {
            if (s[i] == '_') cnt_++;
            if (s[i] == 'X') haveX = 1;
          }
          cout << 9 * pow(10, cnt_ - 1);
        } else
          cout << pow(10, cnt_);
      }
    }
  } else if (s[s.length() - 2] == 'X' && s[s.length() - 1] == '_') {
    int cnt_ = 0;
    for (int i = 0; i < s.length() - 1; ++i)
      if (s[i] == '_') cnt_++;
    if (s[0] == '_')
      cout << 9 * pow(10, cnt_ - 1) * 4;
    else if (s[0] == 'X')
      cout << pow(10, cnt_) * 3;
    else
      cout << 4 * pow(10, cnt_);
  } else if (s[s.length() - 2] == '_' && s[s.length() - 1] >= 0 &&
             s[s.length() - 1] <= '9') {
    int cnt_ = 0;
    bool haveX = 0;
    for (int i = 0; i < s.length() - 2; ++i) {
      if (s[i] == '_') cnt_++;
      if (s[i] == 'X') haveX = 1;
    }
    if (s[s.length() - 1] != '0' && s[s.length() - 1] != '5')
      cout << 0;
    else {
      if (s[0] == '_')
        cout << 9 * pow(10, cnt_ - 1) * 2 * (haveX ? 10 : 1);
      else if (s[0] == 'X')
        cout << 9 * pow(10, cnt_) * 2;
      else
        cout << pow(10, cnt_) * 2 * (haveX ? 10 : 1);
    }
  } else if (s[s.length() - 2] == '_' && s[s.length() - 1] == '_') {
    int cnt_ = 0;
    bool haveX = 0;
    for (int i = 0; i < s.length() - 2; ++i) {
      if (s[i] == '_') cnt_++;
      if (s[i] == 'X') haveX = 1;
    }
    if (s[0] == '_')
      cout << 9 * pow(10, cnt_ - 1) * 4 * (haveX ? 10 : 1);
    else if (s[0] == 'X')
      cout << 9 * pow(10, cnt_) * 4;
    else
      cout << pow(10, cnt_) * 4 * (haveX ? 10 : 1);
  } else if (s[s.length() - 2] == 'X' && s[s.length() - 1] != 'X' &&
             s[s.length() - 1] != '_') {
    if (s[s.length() - 1] != '0' && s[s.length() - 1] != '5')
      cout << 0;
    else if (s[s.length() - 1] != '_') {
      int cnt_ = 0;
      bool haveX = 0;
      for (int i = 0; i < s.length() - 1; ++i) {
        if (s[i] == '_') cnt_++;
        if (s[i] == 'X') haveX = 1;
      }
      if (s[0] == 'X') {
        cout << pow(10, cnt_);
      } else {
        if (s[0] == '_')
          cout << 2 * 9 * pow(10, cnt_ - 1);
        else
          cout << 2 * pow(10, cnt_);
      }
    } else {
      int cnt_ = 0;
      bool haveX = 0;
      for (int i = 0; i < s.length() - 1; ++i) {
        if (s[i] == '_') cnt_++;
        if (s[i] == 'X') haveX = 1;
      }
      if (s[0] == '_')
        cout << 9 * pow(10, cnt_ - 1) * 4;
      else if (s[0] == 'X')
        cout << pow(10, cnt_) * 3;
      else
        cout << pow(10, cnt_) * 4;
    }
  } else if (s[s.length() - 1] >= '0' && s[s.length() - 1] <= '9' &&
             s[s.length() - 2] >= '0' && s[s.length() - 2] <= '9') {
    if (s.substr(s.length() - 2) != "00" &&
        stoi(s.substr(s.length() - 2)) != 25 &&
        stoi(s.substr(s.length() - 2)) != 50 &&
        stoi(s.substr(s.length() - 2)) != 75)
      cout << 0;
    else {
      int cnt_ = 0;
      bool haveX = 0;
      for (int i = 0; i < s.length() - 1; ++i) {
        if (s[i] == '_') cnt_++;
        if (s[i] == 'X') haveX = 1;
      }
      if (s[0] == '_') {
        cout << 9 * pow(10, cnt_ - 1) * (haveX ? 10 : 1);
      } else if (s[0] == 'X')
        cout << pow(10, cnt_) * 9;
      else
        cout << pow(10, cnt_ + 1);
    }
  }
  return 0;
}
