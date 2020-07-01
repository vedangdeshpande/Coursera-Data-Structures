#include <iostream>
#include <string>
#include <vector>
#include <bits/stdc++.h>

using std::string;
using namespace std;
// typedef unsigned long long ull;

// struct Data {
//     string pattern, text;
// };

// Data read_input() {
//     Data data;
//     std::cin >> data.pattern >> data.text;
//     return data;
// }

// void print_occurrences(const std::vector<int>& output) {
//     for (size_t i = 0; i < output.size(); ++i)
//         std::cout << output[i] << " ";
//     std::cout << "\n";
// }

// std::vector<int> get_occurrences(const Data& input) {
//     const string& s = input.pattern, t = input.text;
//     std::vector<int> ans;
//     for (size_t i = 0; i + s.size() <= t.size(); ++i)
//         if (t.substr(i, s.size()) == s)
//             ans.push_back(i);
//     return ans;
// }


// int main() {
//     std::ios_base::sync_with_stdio(false);
//     print_occurrences(get_occurrences(read_input()));
//     return 0;
// }


#define ll long long
#define pb push_back

int main()
{
    ios_base::sync_with_stdio(false);

    string pat,text;
    ll i,j,k,n1,n2;

    cin>>pat;
    cin>>text;
    // cout<<pat<<"  "<<text<<endl;

    std::vector<ll> v;
    n1 = pat.length();
    n2 = text.length();

    // cout<<n1<<" "<<n2<<"\n";

    int t,p,h;
    p = t = 0;
    h = 1;

    for(i=0; i<n1-1; i++)
    {
        h = (h * 256) % 101;
    }

    for(i=0; i<n1; i++)
    {
        p = ((p * 256) + pat[i]) % 101;
        t = ((t * 256) + text[i]) % 101;
    }

    for(i=0; i<=n2-n1; i++)
    {
        // cout<<pat.at(0)<<" "<<y<<endl;

        if(p == t)
        {
               // cout<<i<<endl;
                k = i;
                int flag = 1;
                for(j=0; j<n1; j++)
                {
                    if(text[k] != pat[j])
                    {
                        flag = 0;
                        break;
                    }
                    k++;
                }
                if(flag == 1)
                {
                    // cout<<i<<endl;
                    v.pb(i);
                }
        }
        
        if(i < n2-n1)
        {
            t = (256 * (t - text[i]*h) + text[i+n1]) % 101;

            if(t < 0)
            {
                t = t + 101;
            }
        }
    }

    for(i=0; i<v.size(); i++)
    {
        cout<<v[i]<<" ";
    }
    cout<<"\n";

    return 0;
}
