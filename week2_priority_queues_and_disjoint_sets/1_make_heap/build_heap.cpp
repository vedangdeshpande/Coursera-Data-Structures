#include <iostream>
#include <vector>
#include <algorithm>
#include <bits/stdc++.h>

using std::vector;
using std::cin;
using std::cout;
using std::swap;
using std::pair;
using std::make_pair;
using namespace std;

class HeapBuilder {
 public:
  vector<int> data_;
  vector< pair<int, int> > swaps_;

  void WriteResponse() const {
    cout << swaps_.size() << "\n";
    for (int i = 0; i < swaps_.size(); ++i) {
      cout << swaps_[i].first << " " << swaps_[i].second << "\n";
    }
  }

  void ReadData() {
    int n;
    cin >> n;
    data_.resize(n);
    for(int i = 0; i < n; ++i)
      cin >> data_[i];
  }

  void GenerateSwaps() {
    swaps_.clear();
    // The following naive implementation just sorts 
    // the given sequence using selection sort algorithm
    // and saves the resulting sequence of swaps.
    // This turns the given array into a heap, 
    // but in the worst case gives a quadratic number of swaps.
    //
    // TODO: replace by a more efficient implementation
    // for (int i = 0; i < data_.size(); ++i)
    //   for (int j = i + 1; j < data_.size(); ++j) {
    //     if (data_[i] > data_[j]) {
    //       swap(data_[i], data_[j]);
    //       swaps_.push_back(make_pair(i, j));
    //     }
    //   }

    // int i,n;
    // n = data_.size();
    // int heap[n];
    // for(i=0; i<n; i++)
    // {
    //   heap[i] = data_[i];
    //   adjustheap(heap, i);
    // }

    // for(i=0; i<n; i++)
    // {
    //   cout<<heap[i]<<" ";
    // }
    // cout<<"\n";


    for(int i = data_.size()/2; i >= 0; i--) 
    {
      SiftDown(i);
    }

  }

  // void adjustheap(int heap[], int n)
  // {
  //   int p = (n+1)/2;
  //   if(p != 0)
  //   {
  //      p--;
  //   }
  //   while(heap[p] > heap[n])
  //   {
  //     // heapify(heap, n);
  //     swap(heap[p], heap[n]);
  //     swaps_.push_back(make_pair(p, n));
  //     n = p;
  //     p = (n+1)/2;
  //     if(p != 0)
  //     {
  //       p--;
  //     }
  //   }
  // }

  
  void SiftDown(int i) 
  {
    int minindex = i;
    int l = 2*i + 1;
    if(l < data_.size() && data_[l] < data_[minindex])
    {
      minindex = l;
    }
    int r = 2*i + 2;
    if(r < data_.size() && data_[r] < data_[minindex])
    {
      minindex = r;
    }
    if(i!=minindex) 
    {
      swap(data_[i], data_[minindex]);
      swaps_.push_back(make_pair(i, minindex));
      SiftDown(minindex);
    }
  }


 public:
  void Solve() {
    ReadData();
    GenerateSwaps();
    WriteResponse();
  }
};

int main() {
  std::ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  HeapBuilder heap_builder;
  heap_builder.Solve();
  return 0;
}
