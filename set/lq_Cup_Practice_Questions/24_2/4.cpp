#include <iostream>  
#include <queue>  
#include <vector>  
using namespace std;  

// 计算数字的最大数位  
int getMaxDigit(int num) {  
    int maxDigit = 0;  
    while (num > 0) {  
        maxDigit = max(maxDigit, num % 10);  
        num /= 10;  
    }  
    return maxDigit;  
}  

int main() {  
    const int TARGET = 2024;  
    vector<bool> visited(TARGET + 1, false);  
    queue<pair<int, int>> q;  // {数字，代价}  
    
    // 初始状态  
    q.push({1, 0});  
    visited[1] = true;  
    
    while (!q.empty()) {  
        int num = q.front().first;  
        int cost = q.front().second;  
        q.pop();  
        
        if (num == TARGET) {  
            cout << cost << endl;  
            return 0;  
        }  
        
        // 操作1：+1  
        if (num + 1 <= TARGET && !visited[num + 1]) {  
            visited[num + 1] = true;  
            q.push({num + 1, cost + 1});  
        }  
        
        // 操作2：+最大数位  
        int maxDigit = getMaxDigit(num);  
        if (num + maxDigit <= TARGET && !visited[num + maxDigit]) {  
            visited[num + maxDigit] = true;  
            q.push({num + maxDigit, cost + 3});  
        }  
        
        // 操作3：*2  
        if (num * 2 <= TARGET && !visited[num * 2]) {  
            visited[num * 2] = true;  
            q.push({num * 2, cost + 10});  
        }  
    }  
    
    return 0;  //84 or 79?
}
