#include <bits/stdc++.h>
using namespace std;
int main() {
  long long n;
  cin >> n;
  vector<long long> a(n);
  for (auto &i : a) cin >> i;
  vector<long long> back;
  vector<long long> front;
  int prev = -1;
  map<long long, long long> posf, posb;
  for (int i = 0; i < n; i++) {
    if (prev < a[i]) {
      front.push_back(a[i]);
      prev = a[i];
      posf[a[i]] = i;
    } else {
      break;
    }
  }
  prev = -1;
  for (int i = n - 1; i >= 0; i--) {
    if (prev < a[i]) {
      back.push_back(a[i]);
      prev = a[i];
      posb[a[i]] = n - 1 - i;
    } else {
      break;
    }
  }
  if (front.size() == n || back.size() == n) {
    cout << "Alice";
    return 0;
  }
  deque<long long> deq;
  for (auto &i : a) deq.push_back(i);
  int parity = 0;
  prev = -1;
  while (true) {
    if (deq.size() == 1) {
      if (parity)
        cout << "Bob";
      else
        cout << "Alice";
      return 0;
    }
    long long ff = deq.front();
    long long bb = deq.back();
    if (ff <= prev && bb <= prev) {
      if (parity)
        cout << "Alice";
      else
        cout << "Bob";
      return 0;
    }
    if (ff > bb) {
      int ch = front.size() - posf[ff];
      if (ch % 2) {
        if (parity)
          cout << "Bob";
        else
          cout << "Alice";
        return 0;
      } else if (bb > prev) {
        prev = bb;
        deq.pop_back();
      } else {
        if (parity)
          cout << "Alice";
        else
          cout << "Bob";
        return 0;
      }
    } else {
      int ch = back.size() - posb[bb];
      if (ch % 2) {
        if (parity)
          cout << "Bob";
        else
          cout << "Alice";
        return 0;
      } else if (ff > prev) {
        prev = ff;
        deq.pop_front();
      } else {
        if (parity)
          cout << "Alice";
        else
          cout << "Bob";
        return 0;
      }
    }
    parity = 1 - parity;
  }
}
