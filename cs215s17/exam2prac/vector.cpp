#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main()
{
  vector <string> S;
  S.push_back ("computer");
  S.push_back ("science");
  S.push_back ("is great!");
  sort (S.begin(), S.end());
  for (int i = 0; i < S.size(); i++)
    cout << S[i] << ' ';
  cout <<S.size()<< endl;
  return 0;
}
