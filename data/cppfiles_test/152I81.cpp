#include <stdio.h>
#include <stdint.h>
#include <iostream>
#include <vector>
#include <cstdio>
#include <variant>
#include <list>
#include <initializer_list>
#include <unordered_map>

using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    size_t nn;
    cin >> nn;

    using EntryL = list<uint32_t>;
    using EntryV = variant<uint32_t, EntryL>;
    unordered_map<uint32_t, EntryV> data;

    uint32_t n = 0;
    for (size_t i = 0; i < nn; ++i) {
        uint32_t cmd, x, y;
        cin >> cmd;
        if(cmd == 1) {
            cin >> x;
            auto ep = data.try_emplace(x, n);
            if (!ep.second) {
                auto& r = ep.first->second;
                if (r.index()) {
                    get<1>(r).push_back(n);
                } else {
                    r = EntryV(initializer_list<uint32_t>{get<0>(r), n});
                }
            }
            ++n;
        } else if (cmd == 2) {
            cin >> x >> y;
            if (x == y) continue;
            auto it = data.find(x);
            if (it == data.end()) {
                continue;
            }

            auto jt = data.find(y);
            if (jt == data.end()) {
                auto nh = data.extract(it);
                nh.key() = y;
                data.insert(move(nh));
            } else {
                auto& rx = it->second;
                auto& ry = jt->second;
                switch (rx.index()*2 + ry.index()) {
                case 0:
                    ry = EntryV(initializer_list<uint32_t>{get<0>(rx), get<0>(ry)});
                    break;
                case 1:
                    get<1>(ry).push_back(get<0>(rx));
                    break;
                case 2:
                    get<1>(rx).push_back(get<0>(ry));
                    swap(rx, ry);
                    break;
                case 3:
                    get<1>(ry).splice(get<1>(ry).end(), move(get<1>(rx)));
                    break;
                }
                data.erase(it);
            }
        }
    }

    vector<uint32_t> res;
    res.resize(n);
    for (auto& kv : data) {
        uint32_t k = kv.first;
        if(kv.second.index()) {
            for (uint32_t v : get<1>(kv.second)) {
                res[v] = k;
            }
        } else {
            res[get<0>(kv.second)] = k;
        }
    }
    bool spc = false;
    for (uint32_t x : res) {
        if (spc) cout << ' ';
        cout << x;
        spc = true;
    }
    cout << endl;
    return 0;
}
