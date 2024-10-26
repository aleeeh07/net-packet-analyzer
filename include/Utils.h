#ifndef UTILS_H
#define UTILS_H

#include <string>
#include <pcap.h>

std::string ipToString(const u_char *ip);
std::string getProtocolName(u_char protocol);

#endif // UTILS_H
