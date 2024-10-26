#ifndef CONNECTION_CACHE_H
#define CONNECTION_CACHE_H

#include <vector>
#include "ConnectionRecord.h"

class ConnectionCache {
public:
    ConnectionCache();
    void addConnection(const ConnectionRecord& record);
    void printConnections() const;

private:
    std::vector<ConnectionRecord> connections;
};

inline ConnectionCache connectionCache;

#endif // CONNECTION_CACHE_H
