#include "NetworkStations.hpp"
#include <iostream>
#include <string>
#include <vector>

//Driver program
int main()
{
    NetworkStation::NetworkStationScenario *networkStation = new NetworkStation::NetworkStationScenario();

    int number_of_stations;
    int number_of_communication_link;
    int user_choice;

    std::cout << "Enter 1 for user input mode or Enter 2 for default test cases: ";

    std::cin >> user_choice ;

    if(user_choice == 1)
    {
        std::cout<<"Enter the number of switching stations: ";
        std::cin>>number_of_stations;

        std::cout<<"Enter the number of high-speed communication links: ";
        std::cin>>number_of_communication_link;
        std::cout << std::endl;

        std::vector<std::vector<int> > graph(number_of_stations, std::vector<int>(number_of_stations, 0));

        for(int i=0; i<number_of_communication_link; i++)
        {
            int a, b;
            std::cout<<"Enter station 1: ";
            std::cin>>a;
            std::cout<<"Enter station 2: ";
            std::cin>>b;
            graph[a][b] = 1;
            graph[b][a] = 1;
        }

        std::cout << std::endl;
        std::vector<std::vector<int>> station_list = networkStation->reachableStations(graph, number_of_stations);
        networkStation->printStations(station_list);
    }
    else if(user_choice == 2)
    {
        std::cout << "\n** TEST CASE 1 **" << std::endl;
        number_of_stations = 8;
        number_of_communication_link = 10;

        std::vector<std::vector<int> > graph(number_of_stations, std::vector<int>(number_of_stations, 0));

        graph[0][1] = 1;
        graph[1][0] = 1;
        graph[1][2] = 1;
        graph[2][1] = 1;
        graph[1][3] = 1;
        graph[3][1] = 1;
        graph[2][4] = 1;
        graph[4][2] = 1;
        graph[2][5] = 1;
        graph[5][2] = 1;
        graph[3][6] = 1;
        graph[6][3] = 1;
        graph[3][7] = 1;
        graph[7][3] = 1;
        graph[4][5] = 1;
        graph[5][4] = 1;
        graph[5][6] = 1;
        graph[6][5] = 1;
        graph[6][7] = 1;
        graph[7][6] = 1;

        std::vector<std::vector<int>> station_list = networkStation->reachableStations(graph, number_of_stations);
        networkStation->printStations(station_list);
        
        std::cout << "\n** TEST CASE 2 **" << std::endl;
        number_of_stations = 5;
        number_of_communication_link = 4;

        std::vector<std::vector<int> > graph_2(number_of_stations, std::vector<int>(number_of_stations, 0));
        graph_2[0][1] = 1;
        graph_2[1][0] = 1;
        graph_2[1][2] = 1;
        graph_2[2][1] = 1;
        graph_2[2][3] = 1;
        graph_2[3][2] = 1;
        graph_2[3][4] = 1;
        graph_2[4][3] = 1;

        std::vector<std::vector<int>> station_list_2 = networkStation->reachableStations(graph_2, number_of_stations);
        networkStation->printStations(station_list_2);
    }
    else
    {
        std::cout << "\n** PLEASE ENTER 1 OR 2**\n" << "** RERUN PROGRAM **"<< std::endl;
    }

    return 0;
}