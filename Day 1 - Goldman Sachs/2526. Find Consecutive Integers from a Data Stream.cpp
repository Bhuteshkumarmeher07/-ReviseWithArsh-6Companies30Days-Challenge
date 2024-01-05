class DataStream {
private:
    int val = 0; // value seen in the stream
    int count = 0; // count of last values
    int K = 0;    
public:
    DataStream(int value, int k) {
        val = value;
        count = 0;
        K=k;
    }
    
    bool consec(int num) {
        if(num == val){
            count++;
            return count >= K;
        }
        count=0;
        return false;
    }
};
