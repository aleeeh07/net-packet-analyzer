#include "../include/PacketAnalyzer.h"
#include "../include/Utils.h"
#include "../include/ConnectionRecord.h"
#include "../include/ConnectionCache.h"
#include <chrono>

void packetHandler(u_char *userData, const struct pcap_pkthdr *pkthdr, const u_char *packet) {
    const u_short ethType = (packet[12] << 8) | packet[13];

    if (ethType == 0x0800) {
        const u_char *srcIP = &packet[26];
        const u_char *dstIP = &packet[30];
        const u_char protocol = packet[23];
        const int port = (protocol == 6 || protocol == 17) ? (packet[34] << 8 | packet[35]) : 0;

        const auto timeTaken = std::chrono::duration<double>(pkthdr->len);
        const size_t bytesSize = pkthdr->len;

        connectionCache.addConnection(ConnectionRecord(ipToString(srcIP), ipToString(dstIP), port, getProtocolName(protocol), timeTaken, bytesSize));
    }
}
