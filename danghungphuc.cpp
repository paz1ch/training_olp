#include <iostream>
#include <vector>
#include <unordered_map>

using namespace std;

long long countSubarraysWithAtMostKDistinct(int n, int k, const vector<int>& arr) {
    unordered_map<int, int> freq; 
    long long count = 0; 
    int start = 0; 

    for (int end = 0; end < n; ++end) {
        // Thêm phần tử vào dãy con
        freq[arr[end]]++;

        while (freq.size() > k) {
            freq[arr[start]]--;
            if (freq[arr[start]] == 0) {
                freq.erase(arr[start]);
            }
            start++;
        }

        count += (end - start + 1);
    }

    return count;
}

int main() {
    int n, k;
    cin >> n >> k;
    vector<int> arr(n);

    for (int i = 0; i < n; ++i) {
        cin >> arr[i];
    }

    cout << countSubarraysWithAtMostKDistinct(n, k, arr) << endl;

    return 0;
}
