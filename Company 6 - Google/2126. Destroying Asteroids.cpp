class Solution {
public:
    bool asteroidsDestroyed(int mass, vector<int>& asteroids) {
        sort(asteroids.begin(), asteroids.end());
        long long m=mass;
        for (auto it : asteroids) {
            if (it > m) {
                return false;
            }
            m += it;
        }
        return true;
    }
};
