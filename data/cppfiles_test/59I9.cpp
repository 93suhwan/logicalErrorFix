#include <bits/stdc++.h>
using namespace std;
void sol() {
  long long n;
  cin >> n;
  vector<int> mon, tue, wed, thu, fri;
  for (int i = 1; i <= n; i++) {
    for (int j = 0; j < 5; j++) {
      long long x;
      cin >> x;
      if (x == 1 && j == 0) {
        mon.push_back(i);
      }
      if (x == 1 && j == 1) {
        tue.push_back(i);
      }
      if (x == 1 && j == 2) {
        wed.push_back(i);
      }
      if (x == 1 && j == 3) {
        thu.push_back(i);
      }
      if (x == 1 && j == 4) {
        fri.push_back(i);
      }
    }
  }
  if (mon.size() >= n / 2 && tue.size() >= n / 2) {
    set<int> s;
    for (int i = 0; i < mon.size(); i++) {
      s.insert(mon[i]);
    }
    for (int i = 0; i < tue.size(); i++) {
      s.insert(tue[i]);
    }
    if (s.size() >= n) {
      cout << "YES"
           << "\n";
      return;
    }
  } else if (mon.size() >= n / 2 && wed.size() >= n / 2) {
    set<int> s1;
    for (int i = 0; i < mon.size(); i++) {
      s1.insert(mon[i]);
    }
    for (int i = 0; i < wed.size(); i++) {
      s1.insert(wed[i]);
    }
    if (s1.size() >= n) {
      cout << "YES"
           << "\n";
      return;
    }
  }
  if (mon.size() >= n / 2 && thu.size() >= n / 2) {
    set<int> s2;
    for (int i = 0; i < mon.size(); i++) {
      s2.insert(mon[i]);
    }
    for (int i = 0; i < thu.size(); i++) {
      s2.insert(thu[i]);
    }
    if (s2.size() >= n) {
      cout << "YES"
           << "\n";
      return;
    }
  }
  if (mon.size() >= n / 2 && fri.size() >= n / 2) {
    set<int> s3;
    for (int i = 0; i < mon.size(); i++) {
      s3.insert(mon[i]);
    }
    for (int i = 0; i < fri.size(); i++) {
      s3.insert(fri[i]);
    }
    if (s3.size() >= n) {
      cout << "YES"
           << "\n";
      return;
    }
  }
  if (wed.size() >= n / 2 && tue.size() >= n / 2) {
    set<int> s4;
    for (int i = 0; i < wed.size(); i++) {
      s4.insert(wed[i]);
    }
    for (int i = 0; i < tue.size(); i++) {
      s4.insert(tue[i]);
    }
    if (s4.size() >= n) {
      cout << "YES"
           << "\n";
      return;
    }
  }
  if (thu.size() >= n / 2 && tue.size() >= n / 2) {
    set<int> s5;
    for (int i = 0; i < thu.size(); i++) {
      s5.insert(thu[i]);
    }
    for (int i = 0; i < tue.size(); i++) {
      s5.insert(tue[i]);
    }
    if (s5.size() >= n) {
      cout << "YES"
           << "\n";
      return;
    }
  }
  if (fri.size() >= n / 2 && tue.size() >= n / 2) {
    set<int> s6;
    for (int i = 0; i < fri.size(); i++) {
      s6.insert(fri[i]);
    }
    for (int i = 0; i < tue.size(); i++) {
      s6.insert(tue[i]);
    }
    if (s6.size() >= n) {
      cout << "YES"
           << "\n";
      return;
    }
  }
  if (wed.size() >= n / 2 && thu.size() >= n / 2) {
    set<int> s7;
    for (int i = 0; i < wed.size(); i++) {
      s7.insert(wed[i]);
    }
    for (int i = 0; i < thu.size(); i++) {
      s7.insert(thu[i]);
    }
    if (s7.size() >= n) {
      cout << "YES"
           << "\n";
      return;
    }
  }
  if (wed.size() >= n / 2 && fri.size() >= n / 2) {
    set<int> s8;
    for (int i = 0; i < wed.size(); i++) {
      s8.insert(wed[i]);
    }
    for (int i = 0; i < fri.size(); i++) {
      s8.insert(fri[i]);
    }
    if (s8.size() >= n) {
      cout << "YES"
           << "\n";
      return;
    }
  }
  if (thu.size() >= n / 2 && fri.size() >= n / 2) {
    set<int> s9;
    for (int i = 0; i < thu.size(); i++) {
      s9.insert(thu[i]);
    }
    for (int i = 0; i < fri.size(); i++) {
      s9.insert(fri[i]);
    }
    if (s9.size() >= n) {
      cout << "YES"
           << "\n";
      return;
    }
  }
  cout << "NO"
       << "\n";
}
int main() {
  long long t;
  cin >> t;
  while (t--) {
    sol();
  }
  return 0;
}
