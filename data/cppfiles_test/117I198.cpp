/*_आशीष_*/
// उतिष्ठत। जाग्रत। प्राप्य वरान्निबोधत।
#include <bits/stdc++.h>
using namespace std;

#include<ext/pb_ds/assoc_container.hpp>
#include<ext/pb_ds/tree_policy.hpp>
using namespace __gnu_pbds;

#define oset tree<int, null_type, less<int>, rb_tree_tag, tree_order_statistics_node_update>

#define M                    1000000007
#define pi                   3.14159265358979323846
#define cel(x,a)             (((x) + (a) - 1) / (a))
#define ll                   long long
#define pii                  pair<int,int>
#define pb                   push_back
#define lb                   lower_bound
#define ub                   upper_bound
#define Uchchaihshrava       ios::sync_with_stdio(0); cin.tie(0);
#define ps(x,y)              fixed<<setprecision(y)<<x
#define pf(x,y)              setfill('x')<<setw(y)
#define mem(a,b)             memset(a,b,sizeof(a))
#define F                    first
#define S                    second
#define countofbits(n)       __builtin_popcount(n)
#define lcm(m, n)            (((m) / __gcd((m), (n)))*(n))
#define all(v)               v.begin(), v.end()

//bool sortbyi(const tuple<int, int, int>& a,const tuple<int, int, int>& b)
//      {   return (get<i>(a) < get<i>(b));}

//bool sortby(const pair<ll,ll> &a,const pair<ll,ll> &b)
//{return (a.F<b.F);}
//struct sort_pred {
//    bool operator()(const std::pair<int,int> &left, const std::pair<int,int> &right) {
//        return left.second < right.second;
//    }
//};
void cline()          { cout << '\n';}
template <typename T, typename... V>
void cline(T t, V... v) {cout << t; if (sizeof...(v))cout << ' '; cline(v...);}
void cspc()          { cout << ' ';}
template <typename T, typename... V>
void cspc(T t, V... v) {cout << t; if (sizeof...(v))cout << ' '; cspc(v...);}

const int N = 1e6 + 4;
int n, m;
vector<string> s;
map<pii, bool> vis;
bool block(int i, int j)
{
    if (i >= n || i < 0 || j < 0 || j >= m || s[i][j] == '#' || s[i][j] == 'L' || s[i][j] == '+')
        return 1;
    else return 0;
}
//1-lef,2-rit,3-up,4-bot



void bfs(int si,int sj)
{   queue<pair<int,pii>>q;
    q.push({si,{sj,-1}});
    vis[{si,sj}] = 1;
    while (!q.empty())
    {
       pair<int,pii>  p = q.front();
        q.pop();
        int i=p.F;
        int j=p.S.F;
        //cline(i,j);
        vis[{i,j}]=1;
        if (i >= n || i < 0 || j < 0 || j >= m||s[i][j]=='+')continue;
        if(s[i][j]=='L'||s[i][j]=='#'){

        }
        else{
            int swi=p.S.S;
            if(swi==1)
            {
                bool flag=0;
                if(block(i+1,j)&&block(i-1,j))flag=1;
                if(block(i+1,j)&&block(i,j+1))flag=1;
                if(block(i-1,j)&&block(i,j+1))flag=1;
                if(flag)s[i][j]='+';
            }
            else if(swi==2)
            {
                 bool flag=0;
                if(block(i+1,j)&&block(i-1,j))flag=1;
                if(block(i+1,j)&&block(i,j-1))flag=1;
                if(block(i-1,j)&&block(i,j-1))flag=1;
                if(flag)s[i][j]='+';
            }
            else if(swi==4)
            {
                 bool flag=0;
                if(block(i,j-1)&&block(i-1,j))flag=1;
                if(block(i,j-1)&&block(i,j+1))flag=1;
                if(block(i-1,j)&&block(i,j+1))flag=1;
                if(flag)s[i][j]='+';
            }
            else{
                 bool flag=0;
                if(block(i+1,j)&&block(i,j-1))flag=1;
                if(block(i+1,j)&&block(i,j+1))flag=1;
                if(block(i,j-1)&&block(i,j+1))flag=1;
                if(flag)s[i][j]='+';
            }
        }
      //  cspc(s[i][j],i,j,"---");
        if(s[i][j]=='+'||s[i][j]=='L')
        {
            if(vis[{i+1,j}]==0){
            q.push({i+1,{j,3}});}
            if(vis[{i-1,j}]==0){
             q.push({i-1,{j,4}});}
             if(vis[{i,j-1}]==0){
              q.push({i,{j-1,2}});}
              if(vis[{i,j+1}]==0){
               q.push({i,{j+1,1}});}
        }
    }
}

int32_t main()
{
    Uchchaihshrava

//    freopen("input.txt", "r", stdin);
//    freopen("output.txt", "w", stdout);

    int q; cin >> q;
    while (q--)
    {
        cin >> n >> m;
        for (int i = 0; i < n; i++)
        {
            string cur;
            cin >> cur;
            s.pb(cur);
        }
        int runtime=2;
        while(runtime>0){
        for(int i=0; i<n; i++)
            for(int j=0; j<m; j++)
                if(s[i][j]=='L')bfs(i,j);
            vis.clear();
            runtime--;
        }

           for(int i=0; i<n; i++){
            for(int j=0; j<m; j++)cout<<s[i][j];
                cline();
            } 

        s.clear();
        vis.clear();
    }

    return 0;
}
