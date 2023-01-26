#include <bits/stdc++.h>
using namespace std;
long long int BIT[500];
void update(long long int index, long long int value) {
  while (index <= 305) {
    BIT[index] += value;
    index += (index & -index);
  }
  return;
}
long long int sum(long long int index) {
  long long int s = 0;
  while (index > 0) {
    s += BIT[index];
    index -= (index & -index);
  }
  return s;
}
int32_t main() {
  long long int t;
  cin >> t;
  while (t--) {
    memset(BIT, 0, sizeof(BIT));
    long long int n;
    cin >> n;
    long long int m;
    cin >> m;
    vector<pair<long long int, long long int> > v1;
    long long int arr[n * m];
    for (long long int i = 0; i < n * m; i++) {
      cin >> arr[i];
      v1.push_back(make_pair(arr[i], -i));
    }
    map<long long int, vector<long long int> > m1;
    sort(v1.begin(), v1.end());
    for (long long int i = 0; i < v1.size(); i++) {
      v1[i].second = -v1[i].second;
      m1[v1[i].first].push_back(v1[i].second);
    }
    long long int answer = 0;
    for (long long int i = 0; i < n; i++) {
      long long int index = i * m;
      memset(BIT, 0, sizeof(BIT));
      vector<pair<long long int, long long int> > storage;
      for (long long int j = 0; j < m; j++) {
        long long int ind = index + j;
        long long int x = v1[ind].first;
        long long int y = m1[v1[ind].first][m1[v1[ind].first].size() - 1];
        m1[v1[ind].first].pop_back();
        storage.push_back(make_pair(x, -y));
      }
      sort(storage.begin(), storage.end());
      for (long long int j = 0; j < storage.size(); j++) {
        storage[j].second = -storage[j].second;
      }
      for (long long int j = 0; j < storage.size(); j++) {
        answer += sum(storage[j].second + 1 - 1);
        update(storage[j].second + 1, 1);
      }
    }
    cout << answer << endl;
  }
}
