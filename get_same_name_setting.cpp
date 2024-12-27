#include<iostream>
#include<fstream>
#include<string>
#include<assert.h>
#include<map>
using namespace std;
map<string,string>se;
string s;
int main()
{
    ifstream fin,fni;
    ofstream fout;
    fin.open("Result_15.csv");
    fni.open("Result_10.csv");
    fout.open("1.out");
    while(getline(fin,s))
    {
        string ss;
        for(int i=0;i<s.length();i++)
        {
            if(s[i]==',')break;
            ss.push_back(s[i]);
        }
        assert(se.find(ss)==se.end());
        se[ss]=s;
    }
    while(getline(fni,s))
    {
        string ss;
        for(int i=0;i<s.length();i++)
        {
            if(s[i]==',')break;
            ss.push_back(s[i]);
        }
        map<string,string>::iterator ite=se.find(ss);
        if(ite!=se.end())
        {
            fout<<ite->second+'\n'+s+'\n'+'\n';
        }
    }
    return 0;
}