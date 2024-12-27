#include<algorithm>
#include<random>
#include<cstdio>
#include<set>
using namespace std;
mt19937 rd(random_device{}());
uniform_int_distribution<int>sc(0,2147483647);
vector<int>vec;
set<int>se;
int main()
{
    freopen("1.out","w",stdout);
    for(int i=1;i<=1000000;i++)
    {
        int l=sc(rd),r=sc(rd);
        if(l>r)swap(l,r);
        printf("%d %d\n",l,r);
    }
    return 0;
}