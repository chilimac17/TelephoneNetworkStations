#include "NetworkStations.hpp"
#include <queue>

namespace NetworkStation {
   
    //--------------------------------------------------------------------------------------------------------------------
    std::vector<std::vector<int>> NetworkStationScenario::reachableStations(std::vector<std::vector<int> > graph, int n)
    {
        std::vector<std::vector<int>> station_list;
        std::vector<int> reachable_stations;
        std::queue<int> queue;

        for(int i = 0; i < n; i++)
        {
            bool visited_list[n];
            for(int i=0; i<n; i++)
            {
                visited_list[i] = false;
            }

            visited_list[i] = true;
            reachable_stations.push_back(i);
            queue.push(i);

            int link_count = 0;
            while(!queue.empty())
            {
                int vertex = queue.front();
                queue.pop();

                if(visited_list[vertex] == true && link_count > 4)
                {
                    break;
                }
                else
                {
                    bool added_to_queue = false;

                    for(int v=0; v<n; v++)
                    {
                        if(graph[vertex][v] == 1 && !visited_list[v])
                        {
                            added_to_queue = true;
                            visited_list[v] = true;
                            queue.push(v);
                            reachable_stations.push_back(v);
                        }
                    }

                    if(added_to_queue == true)
                    {
                        link_count++;
                    }
                }

            }

            station_list.emplace_back(reachable_stations);
            reachable_stations.clear();
            while(!queue.empty()) queue.pop();
        }
        return station_list;
    }

    //--------------------------------------------------------------------------------------------------------------------
    void NetworkStationScenario::printStations(std::vector<std::vector<int>> station_list)
    {
        for(int i = 0; i < station_list.size(); i++)
        {
            std::cout << "Reachable stations from Station " << i << " = {"; 
            for(int j = 0; j < station_list[i].size(); j++)
            {
                if(j == station_list[i].size() - 1)
                {
                    std::cout << station_list[i][j];
                }
                else
                {
                    std::cout << station_list[i][j] << ", ";
                }
               
            }

            std::cout << "} " << std::endl;
        }
    }
}