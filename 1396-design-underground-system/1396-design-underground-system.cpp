class UndergroundSystem {
public:

    unordered_map<int,pair<string,int>> CheckInMap;  
    unordered_map<string,pair<double,int>> RouteMap; 

    UndergroundSystem() {}
    
    void checkIn(int id, string stationName, int t) {
        CheckInMap[id] = {stationName,t};
    }
    
    void checkOut(int id, string stationName, int t) {
        auto checkedInUser = CheckInMap[id];
        CheckInMap.erase(id);
        RouteMap[checkedInUser.first + "->" + stationName].first += t - checkedInUser.second;
        RouteMap[checkedInUser.first + "->" + stationName].second += 1;
    }
    
    double getAverageTime(string startStation, string endStation) {
        return RouteMap[startStation + "->"+ endStation].first / RouteMap[startStation + "->"+ endStation].second;
    }
};

/**
 * Your UndergroundSystem object will be instantiated and called as such:
 * UndergroundSystem* obj = new UndergroundSystem();
 * obj->checkIn(id,stationName,t);
 * obj->checkOut(id,stationName,t);
 * double param_3 = obj->getAverageTime(startStation,endStation);
 */