#include "../include/Utils.h"
#include <iostream>

std::string ipToString(const u_char *ip) {
    return std::to_string(ip[0]) + "." + std::to_string(ip[1]) + "." +
           std::to_string(ip[2]) + "." + std::to_string(ip[3]);
}

std::string getProtocolName(const u_char protocol) {
    switch (protocol) {
        case 1:  return "ICMP";
        case 2:  return "IGMP";
        case 6:  return "TCP";
        case 17: return "UDP";
        case 41: return "IPv6";
        case 50: return "ESP";
        case 51: return "AH";
        case 89: return "OSPF";
        default: return "Unknown Protocol";
    }
}
