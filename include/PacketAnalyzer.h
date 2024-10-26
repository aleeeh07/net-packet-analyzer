#ifndef PACKET_ANALYZER_H
#define PACKET_ANALYZER_H

#include <pcap.h>

void packetHandler(u_char *userData, const struct pcap_pkthdr *pkthdr, const u_char *packet);

#endif // PACKET_ANALYZER_H
