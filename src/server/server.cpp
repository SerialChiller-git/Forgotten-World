#include <enet/enet.h>
#include <iostream>
#include <string>

int main() {
    if (enet_initialize() != 0) {
        std::cerr << "Failed to initialize ENet!\n";
        return EXIT_FAILURE;
    }
    atexit(enet_deinitialize);

    // Create server host
    ENetAddress address;
    ENetHost* server;
    address.host = ENET_HOST_ANY;  // Bind to all available addresses
    address.port = 12345;         // Server port

    server = enet_host_create(&address, 32, 2, 0, 0);  // Allow up to 32 clients
    if (!server) {
        std::cerr << "Failed to create ENet server!\n";
        return EXIT_FAILURE;
    }
    std::cout << "Server started on port 12345.\n";

    // Server loop
    ENetEvent event;
    while (true) {
        while (enet_host_service(server, &event, 1000) > 0) {
            switch (event.type) {
                case ENET_EVENT_TYPE_CONNECT:
                    std::cout << "A client connected from "
                              << event.peer->address.host << ":" << event.peer->address.port << ".\n";
                    break;

                case ENET_EVENT_TYPE_RECEIVE:
                    std::cout << "Message from client: " << (char*)event.packet->data << "\n";

                    // Broadcast the message to all clients
                    enet_host_broadcast(server, 0, event.packet);
                    enet_packet_destroy(event.packet);
                    break;

                case ENET_EVENT_TYPE_DISCONNECT:
                    std::cout << "Client disconnected.\n";
                    break;

                default:
                    break;
            }
        }
    }

    enet_host_destroy(server);
    return 0;
}
