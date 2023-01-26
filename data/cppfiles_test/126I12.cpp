#include <algorithm>
#include <array>
#include <bitset>
#include <cassert>
#include <chrono>
#include <cmath>
#include <cstring>
#include <functional>
#include <iomanip>
#include <iostream>
#include <map>
#include <numeric>
#include <queue>
#include <random>
#include <set>
#include <vector>
using namespace std;

// http://www.open-std.org/jtc1/sc22/wg21/docs/papers/2016/p0200r0.html
template<class Fun> class y_combinator_result {
    Fun fun_;
public:
    template<class T> explicit y_combinator_result(T &&fun): fun_(std::forward<T>(fun)) {}
    template<class ...Args> decltype(auto) operator()(Args &&...args) { return fun_(std::ref(*this), std::forward<Args>(args)...); }
};
template<class Fun> decltype(auto) y_combinator(Fun &&fun) { return y_combinator_result<std::decay_t<Fun>>(std::forward<Fun>(fun)); }


template<typename A, typename B> ostream& operator<<(ostream &os, const pair<A, B> &p) { return os << '(' << p.first << ", " << p.second << ')'; }
template<typename T_container, typename T = typename enable_if<!is_same<T_container, string>::value, typename T_container::value_type>::type> ostream& operator<<(ostream &os, const T_container &v) { os << '{'; string sep; for (const T &x : v) os << sep << x, sep = ", "; return os << '}'; }

void dbg_out() { cerr << endl; }
template<typename Head, typename... Tail> void dbg_out(Head H, Tail... T) { cerr << ' ' << H; dbg_out(T...); }
#ifdef NEAL_DEBUG
#define dbg(...) cerr << "(" << #__VA_ARGS__ << "):", dbg_out(__VA_ARGS__)
#else
#define dbg(...)
#endif

const int INF = int(1e9) + 5;

// Warning: when choosing flow_t, make sure it can handle the sum of flows, not just individual flows.
template<typename flow_t>
struct dinic {
    struct edge {
        int node, rev;
        flow_t capacity;

        edge() {}

        edge(int _node, int _rev, flow_t _capacity) : node(_node), rev(_rev), capacity(_capacity) {}
    };

    int V = -1;
    vector<vector<edge>> adj;
    vector<int> dist;
    vector<int> edge_index;
    bool flow_called;

    dinic(int vertices = -1) {
        if (vertices >= 0)
            init(vertices);
    }

    void init(int vertices) {
        V = vertices;
        adj.assign(V, {});
        dist.resize(V);
        edge_index.resize(V);
        flow_called = false;
    }

    void _add_edge(int u, int v, flow_t capacity1, flow_t capacity2) {
        assert(0 <= u && u < V && 0 <= v && v < V);
        assert(capacity1 >= 0 && capacity2 >= 0);
        edge uv_edge(v, int(adj[v].size()) + (u == v ? 1 : 0), capacity1);
        edge vu_edge(u, int(adj[u].size()), capacity2);
        adj[u].push_back(uv_edge);
        adj[v].push_back(vu_edge);
    }

    void add_directional_edge(int u, int v, flow_t capacity) {
        _add_edge(u, v, capacity, 0);
    }

    void add_bidirectional_edge(int u, int v, flow_t capacity) {
        _add_edge(u, v, capacity, capacity);
    }

    edge &reverse_edge(const edge &e) {
        return adj[e.node][e.rev];
    }

    void bfs_check(queue<int> &q, int node, int new_dist) {
        if (new_dist < dist[node]) {
            dist[node] = new_dist;
            q.push(node);
        }
    }

    bool bfs(int source, int sink) {
        dist.assign(V, INF);
        queue<int> q;
        bfs_check(q, source, 0);

        while (!q.empty()) {
            int top = q.front(); q.pop();

            for (edge &e : adj[top])
                if (e.capacity > 0)
                    bfs_check(q, e.node, dist[top] + 1);
        }

        return dist[sink] < INF;
    }

    flow_t dfs(int node, flow_t path_cap, int sink) {
        if (node == sink)
            return path_cap;

        if (dist[node] >= dist[sink])
            return 0;

        flow_t total_flow = 0;

        // Because we are only performing DFS in increasing order of dist, we don't have to revisit fully searched edges
        // again later.
        while (edge_index[node] < int(adj[node].size())) {
            edge &e = adj[node][edge_index[node]];

            if (e.capacity > 0 && dist[node] + 1 == dist[e.node]) {
                flow_t path = dfs(e.node, min(path_cap, e.capacity), sink);
                path_cap -= path;
                e.capacity -= path;
                reverse_edge(e).capacity += path;
                total_flow += path;
            }

            // If path_cap is 0, we don't want to increment edge_index[node] as this edge may not be fully searched yet.
            if (path_cap == 0)
                break;

            edge_index[node]++;
        }

        return total_flow;
    }

    flow_t flow(int source, int sink) {
        assert(V >= 0);
        flow_t total_flow = 0;

        while (bfs(source, sink)) {
            edge_index.assign(V, 0);
            total_flow += dfs(source, numeric_limits<flow_t>::max(), sink);
        }

        flow_called = true;
        return total_flow;
    }

    vector<bool> reachable;

    void reachable_dfs(int node) {
        reachable[node] = true;

        for (edge &e : adj[node])
            if (e.capacity > 0 && !reachable[e.node])
                reachable_dfs(e.node);
    }

    // Returns a list of {capacity, {from_node, to_node}} representing edges in the min cut.
    vector<pair<flow_t, pair<int, int>>> min_cut(int source) {
        assert(flow_called);
        reachable.assign(V, false);
        reachable_dfs(source);
        vector<pair<flow_t, pair<int, int>>> cut;

        for (int node = 0; node < V; node++)
            if (reachable[node])
                for (edge &e : adj[node])
                    if (!reachable[e.node])
                        cut.emplace_back(reverse_edge(e).capacity, make_pair(node, e.node));

        return cut;
    }

    edge *find_edge(int a, int b) {
        for (edge &e : adj[a])
            if (e.node == b)
                return &e;

        return nullptr;
    }
};

template<typename T_vector>
void output_vector(const T_vector &v, bool add_one = false, int start = -1, int end = -1) {
    if (start < 0) start = 0;
    if (end < 0) end = int(v.size());

    for (int i = start; i < end; i++)
        cout << v[i] + (add_one ? 1 : 0) << (i < end - 1 ? ' ' : '\n');
}


const int64_t INF64 = int64_t(2e18) + 5;

int main() {
    ios::sync_with_stdio(false);
#ifndef NEAL_DEBUG
    cin.tie(nullptr);
#endif

    int N, M;
    cin >> N >> M;
    vector<int64_t> A(N);

    for (auto &a : A)
        cin >> a;

    vector<int64_t> sorted = A;
    sort(sorted.begin(), sorted.end());
    sorted.erase(unique(sorted.begin(), sorted.end()), sorted.end());
    int S = int(sorted.size());
    vector<vector<int>> adj(N);

    for (int i = 0; i < M; i++) {
        int u, v;
        cin >> u >> v;
        u--; v--;
        adj[u].push_back(v);
    }

    vector<int64_t> B(N, sorted.front());
    int64_t total = 0;

        int V = N + 2;
        int source = V - 2, sink = V - 1;
        dinic<int64_t> graph(V);

        for (int i = 0; i < N; i++)
            for (int j : adj[i])
                graph.add_directional_edge(j, i, INF64);

    vector<bool> status(N, true);

    for (int i = 0; i < N; i++) {
        graph.add_directional_edge(i, sink, 0);
    }

    int64_t flow = 0;

    for (int s = 0; s < S - 1; s++) {
        int64_t lower = sorted[s];
        int64_t upper = sorted[s + 1];

        for (int i = 0; i < N; i++)
            if (A[i] == lower) {
                // find i -> sink and remove the flow
                // add source -> i
                auto e = graph.find_edge(i, sink);
                int64_t cap = e->capacity;
                int64_t rev_cap = graph.adj[sink][e->rev].capacity;
                e->capacity = 0;
                graph.adj[sink][e->rev].capacity = 0;
                flow -= graph.dfs(i, rev_cap, source);
                graph.add_directional_edge(source, i, upper - lower);
            }

        // vector<int64_t> cost_lower(N, 0), cost_upper(N, 0);

        // for (int i = 0; i < N; i++) {
        //     if (A[i] <= lower)
        //         cost_upper[i] = upper - lower;

        //     if (A[i] >= upper)
        //         cost_lower[i] = upper - lower;
        // }

        // for (int i = 0; i < N; i++)
        //     if (B[i] >= lower) {
        //         if (cost_upper[i] > 0) graph.add_directional_edge(source, i, cost_upper[i]);
        //         if (cost_lower[i] > 0) graph.add_directional_edge(i, sink, cost_lower[i]);
        //     } else {
        //         // graph.add_directional_edge(source, i, INF64);
        //         // graph.add_directional_edge(i, sink, cost_lower[i]);
        //         total += cost_lower[i];
        //     }

        total += graph.flow(source, sink);
        graph.reachable.assign(V, false);
        graph.reachable_dfs(source);
        // auto cut = graph.min_cut(source);

        // for (auto &cut_edge : cut) {
        //     auto edge = cut_edge.second;

        //     if (edge.first == source)
        //         B[edge.second] = max(B[edge.second], upper);
        // }

        for (int i = 0; i < N; i++)
            if (B[i] >= lower && !graph.reachable[i])
                B[i] = max(B[i], upper);

        // for (auto &e : graph.adj[source])
        //     if (!graph.reachable[e.node])
        //         B[e.node] = max(B[e.node], upper);
    }

    output_vector(B);
    int64_t diff = 0;

    for (int i = 0; i < N; i++)
        diff += abs(A[i] - B[i]);

    cerr << diff << ' ' << total << endl;
    // assert(total == diff);
}
