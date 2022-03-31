#include <iostream>
#include <set>
#include <vector>
using namespace std;

vector<set<string>> p(10);
void run(int len)
{
    if (len == 0){
        p[0].emplace("");
        return;
    }
    if (len == 2){
        p[0].emplace("");
        p[1].emplace("()");
        return;
    }
    for (int i = 2; i <= len/2; i += 2){
        if (p[i/2].empty())
            run(i);
        if (p[len/2 - i/2].empty())
            run(len - i);
        for (const string& s1: p[i/2])
            for (const string& s2: p[len/2 - i/2]){
                p[len/2].emplace(s1 + s2);
                if (s1 + s2 != s2 + s1)
                    p[len/2].emplace(s2 + s1);
                if (i == 2)
                    p[len/2].emplace('(' + s2 + ')');
            }
    }
}

int main() {
    int n; cin >> n;
    run(n);
    for (int i = 0; i <= n/2; i++)
        for (const string& s: p[i])
            cout << s << '\n';
}

