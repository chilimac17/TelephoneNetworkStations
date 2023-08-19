#pragma once

#include <iostream>
#include <vector>

namespace NetworkStation {
    
class NetworkStationScenario
{
public:
  
    NetworkStationScenario()
    {}

    ~NetworkStationScenario() 
    {}

    std::vector<std::vector<int>> reachableStations(std::vector<std::vector<int> > graph, int n);

    void printStations(std::vector<std::vector<int>> station_list);

};

}
