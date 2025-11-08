#include <stdio.h>  
#include <string.h>  
#include <stdlib.h>  

#define MAX_POS 10000  

typedef struct {  
    int x, y;  
} Position;  

int main() {  
    int n;  
    scanf("%d", &n);  
    
    char moves[n + 1];  
    scanf("%s", moves);  
    
    // 方向数组，0: 北, 1: 东, 2: 南, 3: 西  
    int direction[4][2] = {{0, 1}, {1, 0}, {0, -1}, {-1, 0}};  
    
    // 记录小蓝的初始位置  
    Position positions[MAX_POS];  
    positions[0].x = 0;  
    positions[0].y = 0;  
    
    int current_direction = 0; // 初始方向为北  
    int pos_count = 1; // 记录位置的数量  
    
    // 模拟小蓝的移动  
    for (int i = 0; i < n; i++) {  
        char move = moves[i];  
        if (move == 'F') {  
            positions[pos_count].x = positions[pos_count - 1].x + direction[current_direction][0];  
            positions[pos_count].y = positions[pos_count - 1].y + direction[current_direction][1];  
            pos_count++;  
        } else if (move == 'L') {  
            current_direction = (current_direction + 3) % 4; // 左转  
            positions[pos_count].x = positions[pos_count - 1].x + direction[current_direction][0];  
            positions[pos_count].y = positions[pos_count - 1].y + direction[current_direction][1];  
            pos_count++;  
        } else if (move == 'R') {  
            current_direction = (current_direction + 1) % 4; // 右转  
            positions[pos_count].x = positions[pos_count - 1].x + direction[current_direction][0];  
            positions[pos_count].y = positions[pos_count - 1].y + direction[current_direction][1];  
            pos_count++;  
        }  
    }  
    
    // 使用集合来存储所有可能的位置  
    int unique_positions[MAX_POS][2];  
    int unique_count = 0;  
    
    // 记录原始路径的所有位置  
    for (int i = 0; i < pos_count; i++) {  
        unique_positions[unique_count][0] = positions[i].x;  
        unique_positions[unique_count][1] = positions[i].y;  
        unique_count++;  
    }  
    
    // 尝试改变每一步  
    for (int i = 0; i < n; i++) {  
        // 记录当前状态  
        int original_direction = current_direction;  
        Position original_position = positions[i];  
        
        // 尝试替换为 F  
        current_direction = original_direction;  
        positions[i] = original_position;  
        positions[i].x += direction[current_direction][0];  
        positions[i].y += direction[current_direction][1];  
        
        // 记录新位置  
        for (int j = 0; j < pos_count; j++) {  
            if (positions[j].x == positions[i].x && positions[j].y == positions[i].y) {  
                // 位置已存在，跳过  
                continue;  
            }  
            unique_positions[unique_count][0] = positions[j].x;  
            unique_positions[unique_count][1] = positions[j].y;  
            unique_count++;  
        }  
        
        // 尝试替换为 L  
        current_direction = (original_direction + 3) % 4; // 左转  
        positions[i] = original_position;  
        positions[i].x += direction[current_direction][0];  
        positions[i].y += direction[current_direction][1];  
        
        // 记录新位置  
        for (int j = 0; j < pos_count; j++) {  
            if (positions[j].x == positions[i].x && positions[j].y == positions[i].y) {  
                // 位置已存在，跳过  
                continue;  
            }  
            unique_positions[unique_count][0] = positions[j].x;  
            unique_positions[unique_count][1] = positions[j].y;  
            unique_count++;  
        }  
        
        // 尝试替换为 R  
        current_direction = (original_direction + 1) % 4; // 右转  
        positions[i] = original_position;  
        positions[i].x += direction[current_direction][0];  
        positions[i].y += direction[current_direction][1];  
        
        // 记录新位置  
        for (int j = 0; j < pos_count; j++) {  
            if (positions[j].x == positions[i].x && positions[j].y == positions[i].y) {  
                // 位置已存在，跳过  
                continue;  
            }  
            unique_positions[unique_count][0] = positions[j].x;  
            unique_positions[unique_count][1] = positions[j].y;  
            unique_count++;  
        }  
        
        // 恢复状态  
        positions[i] = original_position;  
        current_direction = original_direction;  
    }  
    
    // 输出不同位置的数量  
    printf("%d\n", unique_count);  
    
    return 0;  
}
