#include <iostream>
#include <thread>
#include <mutex>
#include <chrono>
#include "include/PacketAnalyzer.h"
#include "include/ConnectionCache.h"

std::mutex cacheMutex;

[[noreturn]] void printConnections() {
    while (true) {
        std::this_thread::sleep_for(std::chrono::milliseconds(1));
        cacheMutex.lock();
        connectionCache.printConnections();
        cacheMutex.unlock();
    }
}

int main() {
    pcap_if_t *alldevs;
    char errbuf[PCAP_ERRBUF_SIZE];

    if (pcap_findalldevs(&alldevs, errbuf) == -1) {
        return 1;
    }

    const pcap_if_t *device = nullptr;
    for (const pcap_if_t *d = alldevs; d != nullptr; d = d->next) {
        if (d->description && std::string(d->description).find("Realtek") != std::string::npos) {
            device = d;
            break;
        }
    }

    if (device == nullptr) {
        pcap_freealldevs(alldevs);
        return 1;
    }

    pcap_t *handle = pcap_open_live(device->name, BUFSIZ, 1, 1000, errbuf);
    if (handle == nullptr) {
        pcap_freealldevs(alldevs);
        return 1;
    }
    pcap_freealldevs(alldevs);

    std::thread printerThread(printConnections);

    pcap_loop(handle, 0, packetHandler, nullptr);

    printerThread.join();

    pcap_close(handle);

    return 0;
}
