/*
 * Device.h
 *
 *  Created on: 25 de nov de 2016
 *      Author: mathias
 */

#ifndef SENSOR_H_
#define SENSOR_H_

#define INFO_SIZE 12
#define IP_SIZE 15
#define DEFAULT_PORT 3333

#include "TCPBaseSocket.h"
#include "Database.h"
#include <parser_Ativo.h>
#include <iostream>
#include <sstream>
#include <cstdlib>
#include <ctime>
#include <stdio.h>
#include <string>

#define MAX_LEVEL 10

using namespace std;

class Device {
public:
	Device(const string & addr_broker, int port) {
        sock.connect(addr_broker, port);
    };
	virtual ~Device(){};
	bool publish(string msg, string topic);
    bool subscriber(string topic);
    bool unsubscriber(string topic);
    string notified();
private:
	TCPClientSocket sock;
    vector<string> Topics; 
};

#endif /* SENSOR_H_ */
