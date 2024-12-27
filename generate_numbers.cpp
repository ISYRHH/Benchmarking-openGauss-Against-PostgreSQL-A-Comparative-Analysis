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
    while(se.size()<1000000)
    {
        int nw=sc(rd);
        if(se.find(nw)==se.end())se.insert(nw);
    }
    for(set<int>::iterator ite=se.begin();ite!=se.end();ite++)
    {
        vec.push_back(*ite);
    }
    shuffle(vec.begin(),vec.end(),rd);
    for(vector<int>::iterator ite=vec.begin();ite!=vec.end();ite++)
    {
        printf("%d ",*ite);
    }
    return 0;
}