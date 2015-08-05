#include <iostream>
#include <list>


using namespace std;
class a
{

public:
    int min;
    a()
    {
        min=10;
    }
};

class b{
public:
b(a *obj)
{
    obj->min=30;
}
};

int main()
{
   list<a> ls;
   a obj;
   obj.min=10;
   ls.push_back(obj);
   obj.min=40;
   ls.push_back(obj);
   for(list<a>::iterator i=ls.begin();i!=ls.end();i++)
   {
        a gg;
        gg=(a)*i;
       cout <<gg.min<<"\n";
   }
    a oa;
    b ob(&oa);
    cout << oa.min<<"Hello world!" << endl;
    return 0;
}
