class Solution {
public:
    int maxNumberOfFamilies(int n, vector<vector<int>>& reservedSeats) {
        map<int,vector<int>>reserved;
        for(auto seat: reservedSeats){
            //mapping each row as key and column that is seat as value
            reserved[seat[0]].push_back(seat[1]);
        }
        //each row can have maximu 2 group
        int emptyrowgroup = 2*(n-reserved.size());
        //finding the possible four group that can be made
        int group =0;
        for(auto seat: reserved){
            vector<int>seatbooked(11,0);
            for(int i:seat.second){
                //marking the seat which are booked for each row
                seatbooked[i]=1;
            }

            //for each row the possible 4-person groups can be in following columns
			 //2 , 3 , 4 , 5  or 6 , 7 , 8 , 9 
			 //or 4 , 5 , 6 , 7

			//  checking if 2 , 3 , 4 , 5  group is possible

            if(!seatbooked[2]&& !seatbooked[3] && !seatbooked[4]&& !seatbooked[5]){
                group++;
                //if we alread boooked 2,3,4,5
				//then we shouldnt be able to book 4,5,6,7
                seatbooked[5]=1;
            }

            if(!seatbooked[6]&& !seatbooked[7] && !seatbooked[8]&& !seatbooked[9]){
                group++;
                //if we alread boooked 6 , 7 , 8 , 9 
				//then we shouldnt be able to book 4,5,6,7

                seatbooked[6]=1;
            }
            //  checking if 4 , 5 , 6 , 7  group is possible
         if(!seatbooked[4]&& !seatbooked[5] && !seatbooked[6]&& !seatbooked[7]){
                group++;
                
            }
        }
        return emptyrowgroup + group;
    }
};
