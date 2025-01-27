#include <enet/enet.h>
#include <iostream>
#include <string>

int main() {
    if (enet_initialize() != 0) {
        std::cerr << "Failed to initialize ENet!\n";
        return EXIT_FAILURE;
    }
    atexit(enet_deinitialize);

    // Create client
    ENetHost* client = enet_host_create(nullptr, 1, 2, 0, 0);
    if (!client) {
        std::cerr << "Failed to create ENet client!\n";
        return EXIT_FAILURE;
    }

    // Connect to server
    ENetAddress address;
    ENetPeer* peer;
    enet_address_set_host(&address, "127.0.0.1");  // Connect to localhost
    address.port = 12345;

    peer = enet_host_connect(client, &address, 2, 0);
    if (!peer) {
        std::cerr << "Failed to connect to server!\n";
        return EXIT_FAILURE;
    }

    std::cout << "Connected to server!\n";

    // Client loop
    ENetEvent event;
    while (true) {
        // Send message
        std::string message;
        std::getline(std::cin, message);

        if (!message.empty()) {
            ENetPacket* packet = enet_packet_create(
                message.c_str(), message.size() + 1, ENET_PACKET_FLAG_RELIABLE);
            enet_peer_send(peer, 0, packet);
        }

        // Handle events
        while (enet_host_service(client, &event, 1000) > 0) {
            switch (event.type) {
                case ENET_EVENT_TYPE_RECEIVE:
                    std::cout << "Server: " << (char*)event.packet->data << "\n";
                    enet_packet_destroy(event.packet);
                    break;

                case ENET_EVENT_TYPE_DISCONNECT:
                    std::cout << "Disconnected from server.\n";
                    return 0;

                default:
                    break;
            }
        }
    }

    enet_host_destroy(client);
    return 0;
}
