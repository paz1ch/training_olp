#include <iostream>
#include <vector>
#include <deque>
#include <algorithm>

using namespace std;

long long max_reward(int n, const vector<int>& values) {
    // Tạo mảng dp để lưu trữ phần thưởng lớn nhất có thể đạt được đến mỗi vị trí
    vector<long long> dp(n, 0);
    dp[0] = values[0];
    
    // Deque để lưu trữ các chỉ số của dp, giúp tối ưu hóa quá trình cập nhật
    deque<int> dq;
    dq.push_back(0);
    
    for (int i = 1; i < n; ++i) {
        // Loại bỏ các chỉ số trong deque mà giá trị tương ứng của chúng không lớn hơn hoặc bằng giá trị hiện tại
        while (!dq.empty() && values[dq.back()] > values[i]) {
            dq.pop_back();
        }
        
        // Lấy giá trị lớn nhất trong deque để cập nhật dp[i]
        if (!dq.empty()) {
            dp[i] = dp[dq.front()] + values[i];
        } else {
            dp[i] = values[i];
        }
        
        // Loại bỏ các giá trị trong deque mà tổng giá trị nhỏ hơn hoặc bằng dp[i]
        while (!dq.empty() && dp[dq.back()] <= dp[i]) {
            dq.pop_back();
        }
        
        // Thêm chỉ số hiện tại vào deque
        dq.push_back(i);
    }
    
    // Tìm giá trị lớn nhất trong dp
    return *max_element(dp.begin(), dp.end());
}

int main() {
    int n;
    cin >> n;
    vector<int> values(n);
    for (int i = 0; i < n; ++i) {
        cin >> values[i];
    }
    
    cout << max_reward(n, values) << endl;
    return 0;
}
