#include<pqxx/pqxx>
#include<iostream>
#include<iomanip>
#include<vector>
#include<cstdio>
#include<chrono>
using namespace pqxx;
using namespace std;
vector<int>vec;
int in;
inline double get_num(const char* s)
{
    double res=0,base=1;
    bool on_float=false;
    while(*s)
    {
        if(*s=='.')on_float=true;
        else if(*s>='0'&&*s<='9')
        {
            res=res*10+(*s^48);
            if(on_float)base*=10;
        }
        s++;
    }
    return res/base;
}
inline double get_time(const result &r)
{
    return get_num(r.back().front().c_str());
}
int main()
{
    freopen("in2.txt","r",stdin);
    for(int i=1;i<=1500;i++)
    {
        scanf("%d",&in);
        vec.push_back(in);
    }
    try
    {
        connection C1("dbname = pro3 user = gaussdb password = Abc@1234 host = localhost port = 15432");
        double tot1=0,tot2=0;
        if(C1.is_open())
        {
            for(int i=0;i<1500;i+=3)
            {
                transaction W(C1);
                tot1+=get_time(W.exec("explain analyse update a set id = ( select min(id) from a where id between "+to_string(vec[i])+" and "+to_string(vec[i+1])+" ) where id between "+to_string(vec[i+2])+" and "+to_string(vec[i+2]+10)+";"));
                W.abort();
            }
        }
        connection C2("dbname = pro3 user = postgres password = 123456 host = localhost port = 25432");
        if(C2.is_open())
        {
            for(int i=0;i<1500;i+=3)
            {
                transaction W(C2);
                tot2+=get_time(W.exec("explain analyse update a set id = ( select min(id) from a where id between "+to_string(vec[i])+" and "+to_string(vec[i+1])+" ) where id between "+to_string(vec[i+2])+" and "+to_string(vec[i+2]+10)+";"));
                W.abort();
            }
        }
        printf("Runtime of openGauss : %f ms\nRuntime of PostgreSQL : %f ms\n",tot1,tot2);
    }
    catch(const std::exception& e)
    {
        std::cerr<<e.what()<<'\n';
    }
    return 0;
}