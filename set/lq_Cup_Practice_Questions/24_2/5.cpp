#include <iostream>  
#include <vector>  
using namespace std;  

int main() {  
    vector<int> nums = {534, 386, 319, 692, 169, 338, 521, 713, 640, 692, 969, 362, 311, 349, 308, 357,   
                       515, 140, 591, 216, 57, 252, 575, 630, 95, 274, 328, 614, 18, 605, 17, 980, 166,   
                       112, 997, 37, 584, 64, 442, 495, 821, 459, 453, 597, 187, 734, 827, 950, 679, 78,   
                       769, 661, 452, 983, 356, 217, 394, 342, 697, 878, 475, 250, 468, 33, 966, 742, 436,   
                       343, 255, 944, 588, 734, 540, 508, 779, 881, 153, 928, 764, 703, 459, 840, 949, 500,   
                       648, 163, 547, 780, 749, 132, 546, 199, 701, 448, 265, 263, 87, 45, 828, 634};  
    
    // dp[i]表示余数为i的最大和  
    vector<long long> dp(24, -1);  
    dp[0] = 0;  
    
    // 对每个数进行处理  
    for(int num : nums) {  
        vector<long long> new_dp = dp;  
        for(int i = 0; i < 24; i++) {  
            if(dp[i] != -1) {  
                int new_remainder = (i + num) % 24;  
                new_dp[new_remainder] = max(new_dp[new_remainder], dp[i] + num);  
            }  
        }  
        // 单独这个数也可以作为一个新的和  
        int remainder = num % 24;  
        new_dp[remainder] = max(new_dp[remainder], (long long)num);  
        dp = new_dp;  
    }  
    
    cout << dp[0] << endl;  //49176
    
    return 0;  
}
