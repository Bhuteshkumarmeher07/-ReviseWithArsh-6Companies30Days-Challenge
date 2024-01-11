#include <random>
#include <map>
#include <vector>

class Solution {
    std::random_device rd;
    std::mt19937 rand;
    std::map<int, int> map;
    int area;
    std::vector<std::vector<int>> rect;
public:
    Solution(std::vector<std::vector<int>>& rects) {
        rect = rects;
        rand = std::mt19937(rd());
        area = 0;
        for (int i = 0; i < rect.size(); i++) {
            area += (rect[i][2] - rect[i][0] + 1) * (rect[i][3] - rect[i][1] + 1);
            map.insert({ area, i });
        }
    }
    
    vector<int> pick() {
        int randVal = rand() % area;
        auto it = map.upper_bound(randVal);
        int key = it->first;
        int rectsIndex = it->second;
        std::vector<int> rects = rect[rectsIndex];
        int offset = key - randVal - 1;
        int width = rects[2] - rects[0] + 1; 
        
        int x = offset % width + rects[0];
        
        int y = offset / width + rects[1];
        return { x, y };
    }
};

// Java
// class Solution {
//     Random rand;
//     TreeMap<Integer, Integer> map;
//     int area;
//     int rect[][];

//     public Solution(int[][] rects) {
//         this.rect = rects;
//         rand = new Random();
//         area =0;
//         map = new TreeMap<>();

//         for(int i =0;i<rect.length;i++){
//             area += (rect[i][2] - rect[i][0]+1) * (rect[i][3] - rect[i][1]+1);
//             map.put(area,i);
//         }
//     }

//     public int[] pick() {
//         int randVal = rand.nextInt(area);
//         int key = map.higherKey(randVal);
//         int rects[] = rect[map.get(key)];

//         int offset = key - randVal - 1;
//         int width = rects[2] - rects[0] + 1; 

//         //  The modulo operation ensures that the result is within the range [0, width-1].
//         int x = offset % (width) + rects[0];
       
//         // The divide operation ensures that the result is within the range [0, width-1].
//         int y = offset / (width) + rects[1];

//         return new int[] { x, y};
//     }
// }
