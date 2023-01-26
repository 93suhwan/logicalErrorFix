#include<cstdio>
#include<iostream>
#include<cstdlib>
#include<cstring>
#include<string>
#include<algorithm>
#include<cmath>
#include<set>

using namespace std;

typedef long long ll;

struct dd
{
    int data;
    int wei;
};

bool cmp(struct dd a,struct dd b)
{
    return (a.data<b.data);
}

int main()
{
    ios::sync_with_stdio(false);
    int t;
    cin>>t;
    while(t--)
    {
        int k=0,i,j,n;
        cin>>n;
        struct dd a[n+3]={0};
        string s;
        cin>>s;
        for(i=0;i<s.size();i++)
        {
            a[i].data=s[i];
            a[i].wei=i;
        }
        sort(a,a+n,cmp);
        for(i=0;i<n;i++)
        {
           if(i!=a[i].wei)
                k++;
        }
        cout<<k<<endl;
    }
    return 0;
}