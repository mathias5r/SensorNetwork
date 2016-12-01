#include <iostream>
#include "Device.h"

using namespace std;

int main() {
 
    char * broker_ip = new char[15];
    char * hierarchy = new char[20];
   
    broker_ip = (char*)"127.0.0.1";
    hierarchy = (char*)"1.1";   
    
    TCPClientSocket sock;
    sock.connect(broker_ip, DEFAULT_PORT);

    Device central(sock);
   
    central.subcriber(hierarchy);

    char * buffer = new char[256];

    while(1){
        central.receive(buffer);
        cout << buffer << endl;
    }
}