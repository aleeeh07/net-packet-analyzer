#ifndef CONNECTION_RECORD_H
#define CONNECTION_RECORD_H

#include <string>
#include <chrono>

struct ConnectionRecord {
    std::string srcIP;
    std::string dstIP;
    int port;
    std::string protocol;
    std::chrono::duration<double> timeTaken;
    size_t bytesSize;

    ConnectionRecord(const std::string src, const std::string dst, const int p, const std::string proto, const std::chrono::duration<double> time, const size_t size)
        : srcIP(src), dstIP(dst), port(p), protocol(proto), timeTaken(time), bytesSize(size) {}
};

#endif // CONNECTION_RECORD_H
