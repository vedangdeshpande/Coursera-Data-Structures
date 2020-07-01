#include <iostream>
#include <vector>
#include <string>
#include <bits/stdc++.h>

using std::string;
using std::vector;
using std::cin;
using namespace std;

// struct Query {
//     string type, name;
//     int number;
// };

// vector<Query> read_queries() {
//     int n;
//     cin >> n;
//     vector<Query> queries(n);
//     for (int i = 0; i < n; ++i) {
//         cin >> queries[i].type;
//         if (queries[i].type == "add")
//             cin >> queries[i].number >> queries[i].name;
//         else
//             cin >> queries[i].number;
//     }
//     return queries;
// }

// void write_responses(const vector<string>& result) {
//     for (size_t i = 0; i < result.size(); ++i)
//         std::cout << result[i] << "\n";
// }

// vector<string> process_queries(const vector<Query>& queries) {
//     vector<string> result;
//     // Keep list of all existing (i.e. not deleted yet) contacts.
//     vector<Query> contacts;
//     for (size_t i = 0; i < queries.size(); ++i)
//         if (queries[i].type == "add") {
//             bool was_founded = false;
//             // if we already have contact with such number,
//             // we should rewrite contact's name
//             for (size_t j = 0; j < contacts.size(); ++j)
//                 if (contacts[j].number == queries[i].number) {
//                     contacts[j].name = queries[i].name;
//                     was_founded = true;
//                     break;
//                 }
//             // otherwise, just add it
//             if (!was_founded)
//                 contacts.push_back(queries[i]);
//         } else if (queries[i].type == "del") {
//             for (size_t j = 0; j < contacts.size(); ++j)
//                 if (contacts[j].number == queries[i].number) {
//                     contacts.erase(contacts.begin() + j);
//                     break;
//                 }
//         } else {
//             string response = "not found";
//             for (size_t j = 0; j < contacts.size(); ++j)
//                 if (contacts[j].number == queries[i].number) {
//                     response = contacts[j].name;
//                     break;
//                 }
//             result.push_back(response);
//         }
//     return result;
// }

// int main() {
//     write_responses(process_queries(read_queries()));
//     return 0;
// }


#define ll long long
#define pb push_back
#define ss second
#define ff first
#define MAX 100005
#define mk make_pair

map<ll, string>mp;

int main()
{
	// ios_base::sync_with_stdio(NULL);
	// cin.tie(NULL);

	ll i,j,k,l,n,ph;
	std::vector<string> ans;

	cin>>n;
	while(n--)
	{
		string s1,s2;
		cin>>s1>>ph;
		if(s1 == "add")
		{
			cin>>s2;
			mp[ph] = s2;
		}
		else
		{
			if(s1 == "del")
			{
				mp.erase(ph);
			}
			else
			{
				std::map<ll, string>::iterator it;
				it = mp.find(ph);
				if(it == mp.end())
				{
					ans.pb("not found");
				}
				else
				{
					ans.pb(it->ss);
				}
			}
		}
	}

	for(i=0; i<ans.size(); i++)
	{
		cout<<ans[i]<<"\n";
	}

	return 0;
}










