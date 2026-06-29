class CountSquares {
public:
    map<int, vector<int>> mpX;
    map<int, vector<int>> mpY;
    map<pair<int,int>, int> pointHistory;
    CountSquares() {
        
    }
    
    void add(vector<int> point) {
        if(!mpX.count(point[0])){
            mpX[point[0]] = vector<int>();
        }
        if(!mpY.count(point[1])){
            mpY[point[1]] = vector<int>();
        }
        mpX[point[0]].push_back(point[1]);
        mpY[point[1]].push_back(point[0]);
        pointHistory[{point[0], point[1]}]++;
    }
    
    int count(vector<int> point) {
        if(!mpX.count(point[0])) return 0;
        if(!mpY.count(point[1])) return 0;
        
        vector<vector<pair<int,int>>> directions = {
            {{-1,0},{-1,-1},{0,-1}},
            {{1,0},{1,-1},{0,-1}},
            {{-1,0},{-1,1},{0,1}},
            {{1,0},{1,1},{0,1}}
        };

        set<int> unit;
        int res = 0;

        for(int y: mpX[point[0]]){
            unit.insert(abs(point[1]-y));
        }

        for(int x: mpY[point[1]]){
            unit.insert(abs(point[1]-x));
        }

        for(auto possibleDirs: directions){
            for(auto u: unit){
                int ongoing = 1;
                if(u == 0) continue;
                for(auto direction: possibleDirs){
                    auto [newX, newY] = direction;
                    ongoing*=pointHistory[{(point[0]+u*newX), (point[1]+u*newY)}];
                }
                res+=ongoing;
                //cout<<u<<" "<<res<<endl;
            }
        }
        return res;
    }
};
