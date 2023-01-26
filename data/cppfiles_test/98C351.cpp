#include <bits/stdc++.h>
using namespace std;
const long long _INF = 1e18;
const long long INF = 1e9;
const int MOD = 1000000007;
const int MAX = 1000005;
int dx[4] = {0, 0, -1, 1};
int dy[4] = {-1, 1, 0, 0};
struct P {
  long long x;
  long long y;
  long long cnt;
};
struct compare {
  bool operator()(P& a, P& b) {
    if (a.x != b.x) return a.x > b.x;
    return a.y > b.y;
  }
};
bool cmp(const P& a, const P& b) {
  if (a.x < b.x)
    return true;
  else if (a.x == b.x) {
    if (a.y < b.y) return true;
  }
  return false;
}
int gcd(int a, int b) {
  while (b != 0) {
    int r = a % b;
    a = b;
    b = r;
  }
  return a;
}
int ccw(int x1, int y1, int x2, int y2, int x3, int y3) {
  int temp = x1 * y2 + x2 * y3 + x3 * y1;
  temp = temp - y1 * x2 - y2 * x3 - y3 * x1;
  if (temp > 0)
    return 1;
  else if (temp < 0)
    return -1;
  else
    return 0;
}
int combination(int n, int r) {
  if (n == r || r == 0)
    return 1;
  else
    return combination(n - 1, r - 1) + combination(n - 1, r);
}
int GCP(int a, int b) {
  int c;
  while (b != 0) {
    c = a % b;
    a = b;
    b = c;
  }
  return a;
}
int LCM(int a, int b) { return a * b / GCP(a, b); }
vector<pair<int, int>> dijkstraGraph[11];
vector<int> dijkstra(int start, int vertex) {
  vector<int> distance(vertex, INF);
  distance[start] = 0;
  priority_queue<pair<int, int>, vector<pair<int, int>>,
                 greater<pair<int, int>>>
      pq;
  pq.push({0, start});
  while (!pq.empty()) {
    int cost = pq.top().first;
    int cur = pq.top().second;
    pq.pop();
    if (distance[cur] < cost) continue;
    for (int i = 0; i < dijkstraGraph[cur].size(); i++) {
      int neighbor = dijkstraGraph[cur][i].first;
      int neighborDistance = cost + dijkstraGraph[cur][i].second;
      if (distance[neighbor] > neighborDistance) {
        distance[neighbor] = neighborDistance;
        pq.push({neighborDistance, neighbor});
      }
    }
  }
  return distance;
}
int parent[15] = {
    0,
};
void init(int N) {
  for (int i = 0; i < (N + 1); i++) parent[i] = i;
}
int Find(int x) {
  if (parent[x] == x) return x;
  return parent[x] = Find(parent[x]);
}
void Union(int x, int y) {
  x = Find(x);
  y = Find(y);
  if (x < y)
    parent[y] = x;
  else
    parent[x] = y;
}
int manacher[11];
void manachers(string S, int N) {
  int r = 0, p = 0;
  for (int i = 0; i < N; i++) {
    if (i <= r)
      manacher[i] = min(manacher[2 * p - i], r - i);
    else
      manacher[i] = 0;
    while (i - manacher[i] - 1 >= 0 && i + manacher[i] + 1 < N &&
           S[i - manacher[i] - 1] == S[i + manacher[i] + 1])
      manacher[i]++;
    if (r < i + manacher[i]) {
      r = i + manacher[i];
      p = i;
    }
  }
}
vector<long long> tree(41);
vector<long long> lazy(41);
long long arr[11];
long long init(int node, int start, int end) {
  if (start == end) {
    return tree[node] = arr[start];
  } else {
    return tree[node] = init(node * 2, start, (start + end) / 2) +
                        init(node * 2 + 1, (start + end) / 2 + 1, end);
  }
}
void updateLazy(int node, int start, int end) {
  if (lazy[node] != 0) {
    tree[node] += (end - start + 1) * lazy[node];
    if (start != end) {
      lazy[node * 2] += lazy[node];
      lazy[node * 2 + 1] += lazy[node];
    }
    lazy[node] = 0;
  }
}
void updateRange(int node, int start, int end, int left, int right,
                 long long diff) {
  updateLazy(node, start, end);
  if (right < start || end < left) {
    return;
  } else if (left <= start && end <= right) {
    tree[node] += (end - start + 1) * diff;
    if (start != end) {
      lazy[node * 2] += diff;
      lazy[node * 2 + 1] += diff;
    }
    return;
  }
  updateRange(node * 2, start, (start + end) / 2, left, right, diff);
  updateRange(node * 2 + 1, (start + end) / 2 + 1, end, left, right, diff);
  tree[node] = tree[node * 2] + tree[node * 2 + 1];
  return;
}
long long sum(int node, int start, int end, int left, int right) {
  updateLazy(node, start, end);
  if (right < start || end < left) {
    return 0;
  } else if (left <= start && end <= right) {
    return tree[node];
  }
  return sum(node * 2, start, (start + end) / 2, left, right) +
         sum(node * 2 + 1, (start + end) / 2 + 1, end, left, right);
}
void solved() {
  int t;
  cin >> t;
  while (t--) {
    string s;
    cin >> s;
    string tmp;
    cin >> tmp;
    vector<int> ans;
    for (int i = 0; i < tmp.size(); i++) {
      char temp;
      temp = tmp[i];
      for (int j = 0; j < s.size(); j++) {
        if (temp == s[j]) {
          ans.push_back({j + 1});
          break;
        }
      }
    }
    int ret = 0;
    for (int i = 0; i < ans.size() - 1; i++) {
      ret += abs(ans[i + 1] - ans[i]);
    }
    cout << ret << "\n";
  }
}
int main(int argc, char** argv) {
  ios::sync_with_stdio(0);
  cin.tie(0);
  solved();
  return 0;
}
