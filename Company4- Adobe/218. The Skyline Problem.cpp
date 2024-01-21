class Solution {
    struct KeyPoint {
        int key;
        int height;
        KeyPoint* next;

        KeyPoint(int k, int h) : key(k), height(h), next(nullptr) {}
    };

public:
    std::vector<std::vector<int>> getSkyline(std::vector<std::vector<int>>& buildings) {
        std::vector<std::vector<int>> result;
        KeyPoint dummy(-1, 0); // dummy head
        KeyPoint* pre = &dummy;

        for (const auto& bd : buildings) {
            int L = bd[0];
            int R = bd[1];
            int H = bd[2];

            while (pre->next != nullptr && pre->next->key <= L)
                pre = pre->next;

            int preH = pre->height;

            if (pre->key == L)
                pre->height = std::max(pre->height, H);
            else if (pre->height < H) {
                KeyPoint* next = pre->next;
                pre->next = new KeyPoint(L, H);
                pre = pre->next;
                pre->next = next;
            }

            KeyPoint* preIter = pre;
            KeyPoint* curIter = pre->next;
            while (curIter != nullptr && curIter->key < R) {
                preH = curIter->height;
                curIter->height = std::max(curIter->height, H);

                if (curIter->height == preIter->height)
                    preIter->next = curIter->next;
                else
                    preIter = curIter;

                curIter = curIter->next;
            }

            if (preIter->height != preH && preIter->key != R && (curIter == nullptr || curIter->key != R)) {
                KeyPoint* next = preIter->next;
                preIter->next = new KeyPoint(R, preH);
                preIter->next->next = next;
            }
        }

        KeyPoint* first = &dummy;
        KeyPoint* second = dummy.next;
        while (second != nullptr) {
            if (second->height != first->height)
                result.push_back({second->key, second->height});
            first = first->next;
            second = second->next;
        }

        return result;
    }
};
