//uva12911
#include <iostream>
#include <unordered_map>

using namespace std;

int main() {
  int N, T;
  while (cin >> N >> T) {
    long long int num[45];
    for (int i = 0; i < N; ++i)
      cin >> num[i];
    // divide into two subset because enumerate the 2^40 subset is impossible
    long long int lNum = N / 2;
    if (lNum == 0)
      lNum = 1;
    long long int rNum = N - lNum;
    unordered_map<long long int, int> mL, mR; // sum maps to number of subsets
    // enumerate 1~2^(left)
    for (int i = 1; i < (1 << lNum); ++i) {
      long long int sum = 0;
      for (int j = 0; j < lNum; ++j) {
        if (i & (1 << j))
          sum += num[j];
      }
      ++mL[sum];
    }
    // enumerate 1~2^(right)
    for (int i = 1; i < (1 << rNum); ++i) {
      long long int sum = 0;
      for (int j = 0; j < rNum; ++j) {
        if (i & (1 << j))
          sum += num[lNum + j];
      }
      ++mR[sum];
    }
    long long int cnt = 0;
    for (auto itr : mL) {
      if (mR.find(T - itr.first) != mR.end())
        cnt += (long long)itr.second * mR[T - itr.first];
    }
    cout << cnt + mL[T] + mR[T] << endl;
  }
  return 0;
}