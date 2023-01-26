#include <iostream>
#include <cstdio>
#include <string>
#include <algorithm>
#include <cmath>
#include <vector>
#include <queue>
#include <stack>
#include <deque>
#include <set>
#include <map>
#include <climits>
#include <cstdlib>
#include <string.h>

using namespace std;

#define For(i,i1,i2) for(int i=(int)i1 ; i<=(int)i2 ; i++)
#define Rof(i,i1,i2) for(int i=(int)i1 ; i>=(int)i2 ; i--)
#define int long long
#define NMAX 1000006
#define MODU 1000000007
#define pii pair<int,int>
#define xx first
#define yy second
#define mp make_pair
#define pb push_back

struct QR
{
    int l,k,id;
    QR() {l=0;k=0;id=0;}
    QR(int _l,int _k ,int _id)
    {
        this->l = _l;
        this->k = _k;
        this->id = _id;
    }
};

vector <QR> qrhold[NMAX];

struct Node
{
    int cnt,left,right,high,fa,total;
    pii val;
}BST[2*NMAX];

vector<int> adj[NMAX];
int n,HEAD,_node,nqr;
int a[NMAX],occ[NMAX],ans[NMAX];


int new_node(int u,pii k)
{
    _node++;
    BST[_node].val = k;
    BST[_node].cnt = 1;
    BST[_node].total = 1;
    BST[_node].fa = u;
    BST[_node].high = 1;
    return _node;
}

void comb(int node)
{
    int L = BST[node].left;
    int R = BST[node].right;
    BST[node].total = BST[node].cnt + BST[L].total + BST[R].total;
    BST[node].high = max(BST[L].high,BST[R].high)+1;
}

void change_child(int u,int v2,int side)
{
    BST[v2].fa = u;
    if (u==0)
    {
        HEAD = v2;
        return;
    }
    if (side==1) BST[u].right = v2;
    else BST[u].left = v2;

    comb(u);
}

void balance(int node)
{
    int anc = BST[node].fa;
    int L = BST[node].left;
    int R = BST[node].right;
    int newr = node;

    if (BST[L].high > BST[R].high+1)
    {
        int LL = BST[L].left;
        int LR = BST[L].right;
        if (BST[LL].high > BST[LR].high)
        {
            change_child(node,LR,-1);
            change_child(L,node,1);
            newr = L;
        }
        else if (BST[LL].high < BST[LR].high)
        {
            change_child(L,BST[LR].left,1);
            change_child(LR,L,-1);
            change_child(node,BST[LR].right,-1);
            change_child(LR,node,1);
            newr = LR;
        }
    }

    else if (BST[L].high < BST[R].high+1)
    {
        int RL = BST[R].left;
        int RR = BST[R].right;
        if (BST[RL].high > BST[RR].high)
        {
            change_child(R,BST[RL].right,-1);
            change_child(RL,R,1);
            change_child(node,BST[RL].left,1);
            change_child(RL,node,-1);
            newr = RL;
        }
        else if (BST[RL].high < BST[RR].high)
        {
            change_child(node,RL,1);
            change_child(R,node,-1);
            newr = R;
        }
    }
    if (newr == node) return;
    if (BST[anc].left == node) change_child(anc,newr,-1);
    else change_child(anc,newr,1);
}

void add(pii k,int node)
{
    if (HEAD==0)
    {
        HEAD = new_node(0,k);
        return;
    }

    int L = BST[node].left;
    int R = BST[node].right;
    if (BST[node].val > k)
    {
        if (L == 0) L = BST[node].left = new_node(node,k);
        else add(k,L);
    }

    if (BST[node].val < k)
    {
        if (R == 0) R = BST[node].right = new_node(node,k);
        else add(k,R);
    }
    if (BST[node].val == k)
        BST[node].cnt++;

    comb(node);
    balance(node);
}

int minValueNode(int node)
{
    int L = BST[node].left;
    if (L!=0)
        return minValueNode(L);
    return node;
}

void rmv(pii k,int node)
{
    if (node==0)
        return;

    int L = BST[node].left;
    int R = BST[node].right;
    if (BST[node].val > k)
    {
        rmv(k,L);
    }
    if (BST[node].val < k)
    {
        rmv(k,R);
    }
    if (BST[node].val == k)
    {
        int u = BST[node].fa;
        if (L==0 && R==0)
        {
            if (BST[u].left == node)
                BST[u].left = 0;
            if (BST[u].right == node)
                BST[u].right = 0;
            if (u!=0)
                BST[u].total--;
            if (node==HEAD)
                HEAD = 0;
        }
        if (L==0 || R==0)
        {
            int v = max(L,R);
            BST[node].val = BST[v].val;
            BST[node].total--;
            BST[node].left = BST[node].right = 0;
        }
        if (L!=0 && R!=0)
        {
            int v = minValueNode(R);
            BST[node].val = BST[v].val;
            rmv(BST[v].val,R);
        }
    }

    comb(node);
    balance(node);
}

int get_kth(int k,int node)
{
    if (k>BST[node].total) return 0;
    if (node==0) return 0;
    int L = BST[node].left;
    int R = BST[node].right;

    if (L!=0 && BST[L].total >= k)
        return get_kth(k,L);
    if (L!=0)
        k -= BST[L].total;
    if (k==1) return BST[node].val.yy;
    k--;
    return get_kth(k,R);
}

void destructor()
{
    For(i,0,_node)
    {
        BST[i].cnt = 0;
        BST[i].val = mp(0,0);
        BST[i].fa = 0;
        BST[i].high = 0;
        BST[i].total = 0;
        BST[i].left = 0;
        BST[i].right = 0;
}
    _node = 0;
    HEAD = 0;
}

int cntlower(int occur,int node)
{
    if (node==0) return 0;
    int L = BST[node].left;
    int R = BST[node].right;

    if (BST[node].val.xx<occur)
        return 1 + BST[L].total + cntlower(occur,R);
    if (BST[node].val.xx>occur)
        return cntlower(occur,L);
    if (BST[node].val.xx==occur)
        return BST[L].total;
}

void dfs(int u)
{
    rmv(mp(occ[a[u]],a[u]),HEAD);
    occ[a[u]]++;
    add(mp(occ[a[u]],a[u]),HEAD);

    for(QR qr:qrhold[u])
    {
        int l = qr.l;
        int k = qr.k;
        int offset = cntlower(l,HEAD);
        int t = get_kth(k+offset,HEAD);
        if (t==0)
        {
            ans[qr.id] = -1;
            continue;
        }
        if (occ[t]<l)
        {
            ans[qr.id] = -1;
            continue;
        }
        ans[qr.id] = t;
    }

    for(int v:adj[u])
        dfs(v);

    rmv(mp(occ[a[u]],a[u]),HEAD);
    occ[a[u]]--;
    if (occ[a[u]]!=0)
        add(mp(occ[a[u]],a[u]),HEAD);
}

void solve()
{
    For(i,1,n)
    {
        occ[i] = 0;
        ans[i] = 0;
    }

    dfs(1);
    For(i,1,nqr)
        printf("%I64d ",ans[i]);
    printf("\n");
}

main()
{
    #ifndef ONLINE_JUDGE
    freopen("a.inp","r",stdin);
    #endif // ONLINE_JUDGE

    int t,x,v,l,k;
    scanf("%I64d",&t);
    For(ncase,1,t)
    {
        scanf("%I64d%I64d",&n,&nqr);
        For(i,1,n)
        {
            scanf("%I64d\n",&a[i]);
            adj[i].clear();
            qrhold[i].clear();
        }

        For(i,2,n)
        {
            scanf("%I64d",&x);
            adj[x].pb(i);
        }
        For(i,1,nqr)
        {
            scanf("%I64d%I64d%I64d",&v,&l,&k);
            qrhold[v].pb(QR(l,k,i));
        }
        solve();
        destructor();
    }
}
