#include "../include/ConnectionCache.h"
#include <iostream>

ConnectionCache::ConnectionCache() {}

void ConnectionCache::addConnection(const ConnectionRecord& record) {
    connections.push_back(record);
}

void ConnectionCache::printConnections() const {
    for (const auto& conn : connections) {
        std::cout << "Source IP: " << conn.srcIP
                  << ", Destination IP: " << conn.dstIP
                  << ", Port: " << conn.port
                  << ", Protocol: " << conn.protocol
                  << ", Time Taken: " << conn.timeTaken.count() << "ms"
                  << ", Bytes Size: " << conn.bytesSize << " bytes\n";
    }
}
