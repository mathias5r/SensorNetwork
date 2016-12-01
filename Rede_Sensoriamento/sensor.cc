#include <iostream>	
#include <cstdlib>
#include <ctime>
#include "Device.h"
#include "Database.h"

using namespace std;

int main() {
 
    char * broker_ip = new char[15];
    char * hierarchy = new char[20];
    
    broker_ip = (char*)"127.0.0.1";
    hierarchy = (char*)"1.1";    

    TCPClientSocket sock;
    sock.connect(broker_ip, DEFAULT_PORT);

    Device sensor(sock);
   
    char * buffer = new char[256];

    while(1){
        srand((unsigned)time(0)); //para gerar números aleatórios reais.
        int maior = 100;
        int menor = 30;
        int aleatorio = rand()%(maior-menor+1) + menor;
        std::cout << "Value = " << aleatorio << std::endl;
        sprintf(buffer,"%d",aleatorio);
        sensor.publish(buffer,hierarchy);
        sleep(5000);
    }
}
