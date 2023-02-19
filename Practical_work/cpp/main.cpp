/**
 * @file main.cpp
 * @author Carlos Jedwab
 * @brief Main function creating default medias, the server, listening to the port and handling the requests
 * @version 0.1
 * @date 2023-02-19
 * 
 * @copyright Copyright (c) 2023
 * 
 */

#include <iostream>
#include <memory>
#include "Encapsulator.h"
#include "Photo.h"
#include "tcpserver.h"
#include "handle_request.cpp"

using namespace std;

const int PORT = 3331;

/**
 * @brief Main function creating default medias, the server, listening to the port and handling the requests
 * 
 * @param argc 
 * @param argv 
 * @return int 
 */
int main(int argc, const char* argv[]) {
    // create encapsulator
    Encapsulator* encapsulator = new Encapsulator(); /*< Encapsulator object */

    // create a default existing photos
    encapsulator->createPhoto("cat", "cat.jpg", 100, 100);
    encapsulator->createPhoto("lenna", "lenna.jpg", 100, 100);
    // create a default existing video
    encapsulator->createVideo("rain", "Raindrops_Videvo.mp4", 10);
    // create a default existing movie
    encapsulator->createMovie("notlionking", "lion.mp4", 10, new vector<int> {1, 5, 4});

    // cree le TCPServer
    auto* server =
    new TCPServer( [&](std::string const& request, std::string& response) {

        // the request sent by the client to the server
        std::cout << "request: " << request << std::endl;

        // process the request
        response = handle_request(request, encapsulator);

        // return false would close the connecytion with the client
        return true;
    });


    // lance la boucle infinie du serveur
    std::cout << "Starting Server on port " << PORT << std::endl;

    int status = server->run(PORT);

    // en cas d'erreur
    if (status < 0) {
        std::cerr << "Could not start Server on port " << PORT << std::endl;
        return 1;
    }

    return 0;
}
