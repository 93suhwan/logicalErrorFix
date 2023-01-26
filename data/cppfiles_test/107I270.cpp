#include<bits/stdc++.h>
using namespace std;
int main()
{
    int t;
    cin>>t;
    while(t--)
    {
        int n,a,b;
        int i,j;
        cin>>n>>a>>b;
        int arr[n]={0};
        int flag=0;
        if(abs(a-b)>1||(a+b)>n-2)
        {
            flag=1;
            cout<<"-1"<<endl;
            continue;
        }
        if(a==0&&b==0)
        {
            for(i=0;i<n;i++)
            {
              arr[i]=i+1;
            }
        }
        else if(b==0)
        {
            arr[1]=n;
            arr[0]=n-1;
            int x=n-2;
            for(i=2;i<n;i++)
            {
                arr[i]=x;
                x--;
            }
        }
        else if(a==0)
        {
            arr[1]=1;
            arr[0]=2;
            int x=3;
            for(i=2;i<n;i++)
            {
                arr[i]=x;
                x++;
            }
        }
        else
        {
            
            if(a>b)
            {
                int x=n;
                int x1=1;
                int y=a;
                int end=0;
                for(i=1;i<n-1;i+=2)
                {
                    if(y==1)
                    {
                        break;
                    }
                     end=i;
                    arr[i]=x;
                    x--;
                   y--;
                }
                arr[n-2]=x;
                x--;
                for(i=2;i<end;i+=2)
                {
                    arr[i]=x1;
                    x1++;
                }
                for(i=end+1;i<n-2;i++)
                {
                    arr[i]=x;
                    x--;
                }
                
                arr[0]=x1;
                x1++;
                arr[n-1]=x1;
            }
            else if(b>a)
            {
                
                int x=1;
                int y=n;
                int end=0;
                for(i=1;i<n-1;i+=2)
                {
                    if(b==1)
                    {
                        break;
                    }
                    arr[i]=x;
                    x++;
                    end=i;
                    b--;
                }
                arr[n-2]=x;
                x++;
                for(i=2;i<end;i+=2)
                {
                    arr[i]=y;
                    y--;
                }
                for(i=end+1;i<n-2;i++)
                {
                    arr[i]=x;
                    x++;
                }
                
                arr[0]=y;
                y--;
                arr[n-1]=y;
            }
            else
            {
                int x=n;
                int y=1;
                int end=0;
                for(i=1;i<n-1;i+=2)
                {
                    if(a==0)
                    {
                        break;
                    }
                    arr[i]=x;
                    x--;
                    a--;
                    end=i;
                }
                for(i=0;i<end;i+=2)
                {
                    arr[i]=y;
                    y++;
                }
                for(i=end+1;i<n;i++)
                {
                 arr[i]=y++;   
                }
                swap(arr[end+1],arr[n-2]);
            }
        }
       if(flag==0)
       {
           for(i=0;i<n;i++)
           {
               cout<<arr[i]<<" ";
           }
           cout<<endl;
       }
    }
}