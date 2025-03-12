#include <iostream>
using namespace std;
#include <algorithm>
#include <cstring>
#include <cmath>
#include <stack>
#include <map>
map<char, int> m;

int main()
{
    m.insert(make_pair('0', 0));
    m.insert(make_pair('1', 1));
    m.insert(make_pair('2', 2));
    m.insert(make_pair('3', 3));
    m.insert(make_pair('4', 4));
    m.insert(make_pair('5', 5));
    m.insert(make_pair('6', 6));
    m.insert(make_pair('7', 7));
    m.insert(make_pair('8', 8));
    m.insert(make_pair('9', 9));
    m.insert(make_pair('A', 10));
    m.insert(make_pair('B', 11));
    m.insert(make_pair('C', 12));
    m.insert(make_pair('D', 13));
    m.insert(make_pair('E', 14));
    m.insert(make_pair('F', 15));

    string str;
    while(cin >> str)
    {
        int ans = 0;
        int len = str.size();
        for(int i = 2; i < len; ++i)
        {
            map<char, int>::iterator it = m.find(str[i]);
            ans += (*it).second * pow(16, len - 1 - i);
        }
        cout << ans << endl;
    }
    

    
    
}