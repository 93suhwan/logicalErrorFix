#include <bits/stdc++.h>
#define vi vector<int>
#define pii pair<int, int>
using namespace std;

struct wall
{
    bool top = false, right = false, bottom = false, left = false;
    bool traversed = false;
    wall(int x)
    {
        if (x & 1)
            left = true;
        if ((x >> 1) & 1)
            bottom = true;
        if ((x >> 2) & 1)
            right = true;
        if ((x >> 3) & 1)
            top = true;
    }
};

void makeTransversed(vector<vector<wall>> &factory, int i, int j)
{
    factory[i][j].traversed = true;
}

int sizeOfRoom(vector<vector<wall>> &factory, int i, int j, string status = "start")
{
    if (factory[i][j].traversed == true)
        return 0;

    int size = 0;
    makeTransversed(factory, i, j);
    if (factory[i][j].top == false && status != "top")
    {
        // cout << "going top from ("<<i<<","<<j<<")" << endl;
        size += 1 + sizeOfRoom(factory, i - 1, j, "bottom");
    }
    if (factory[i][j].bottom == false && status != "bottom")
    {
        // cout << "going bottom from ("<<i<<","<<j<<")" << endl;
        size += 1 + sizeOfRoom(factory, i + 1, j, "top");
    }
    if (factory[i][j].right == false && status != "right")
    {
        // cout << "going right from ("<<i<<","<<j<<")" << endl;
        size += 1 + sizeOfRoom(factory, i, j + 1, "left");
    }
    if (factory[i][j].left == false && status != "left")
    {
        // cout << "going left from ("<<i<<","<<j<<")" << endl;
        size += 1 + sizeOfRoom(factory, i, j - 1, "right");
    }

    return size;
}

vector<int> rooms(vector<vector<wall>> &factory)
{
    vector<int> res;
    int n = factory.size();
    int m = (*(factory.begin())).size();
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            if (factory[i][j].traversed == false)
                res.push_back(sizeOfRoom(factory, i, j));
        }
    }
    return res;
}

int main()
{
    int n, m;
    cin >> n >> m;
    vector<vector<wall>> factory;
    for (int i = 0; i < n; i++)
    {
        vector<wall> row;
        for (int j = 0; j < m; j++)
        {
            int x;
            cin >> x;
            wall room(x);
            row.push_back(room);
        }
        factory.push_back(row);
    }
    vector<int> res;
    res = rooms(factory);
    sort(res.begin(),res.end(),greater<>());
    for(auto i = res.begin();i!=res.end();i++){
        cout<<(*i)+1<<" ";
    }
    return 0;
}