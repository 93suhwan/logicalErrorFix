#include <bits/stdc++.h>
using namespace std;
struct dish {
  long long a, b, m, e_a, e_b;
};
void solve() {
  int n, m;
  cin >> n >> m;
  vector<dish> task;
  task.resize(n);
  long long tot_a = 0, tot_b = 0, tot_m = 0;
  for (int i = 0; i < n; i++) {
    cin >> task[i].a >> task[i].b;
    task[i].m = m;
    long long tmp = task[i].b;
    if (task[i].a < m) {
      task[i].e_b = m - task[i].a;
      task[i].b -= m - task[i].a;
    }
    if (tmp < m) {
      task[i].e_a = m - tmp;
      task[i].a -= m - tmp;
    }
    task[i].m -= (task[i].e_a + task[i].e_b);
    tot_a += task[i].a;
    tot_b += task[i].b;
    tot_m += task[i].m;
  }
  long long e_a = 0, e_b = 0;
  if (abs(tot_a - tot_b) <= tot_m) {
    if (tot_a > tot_b) {
      e_a = tot_a - tot_b;
      tot_a = tot_b;
    } else {
      e_b = tot_b - tot_a;
      tot_b = tot_a;
    }
    tot_m -= e_a + e_b;
    tot_a -= tot_m / 2;
    e_a += tot_m / 2;
    tot_m -= tot_m / 2;
    tot_b -= tot_m;
    e_b += tot_m;
    tot_m = 0;
    cout << abs(tot_a - tot_b) << "\n";
  } else {
    if (tot_a > tot_b) {
      tot_a -= tot_m;
      e_a += tot_m;
      tot_m = 0;
    } else {
      tot_b -= tot_m;
      e_b += tot_m;
      tot_m = 0;
    }
    cout << abs(tot_a - tot_b) << "\n";
  }
  for (int i = 0; i < n; i++) {
    long long m_a = min(e_a, task[i].m);
    task[i].a -= m_a;
    task[i].e_a += m_a;
    e_a -= m_a;
    task[i].m -= m_a;
    long long m_b = min(e_b, task[i].m);
    task[i].b -= m_b;
    task[i].e_b += m_b;
    e_b -= m_b;
    task[i].m -= m_b;
  }
  for (int i = 0; i < n; i++) {
    cout << task[i].e_a << " " << task[i].e_b << "\n";
  }
}
int main() {
  int n;
  cin >> n;
  for (int i = 0; i < n; i++) {
    solve();
  }
}
