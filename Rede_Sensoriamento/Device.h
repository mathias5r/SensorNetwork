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
#define DEFAULT_PORT 5555

#include "TCPBaseSocket.h"
#include "Database.h"
#include <parser_Ativo.h>
#include <iostream>
#include <sstream>
#include <cstdlib>
#include <ctime>
#include <stdio.h>
#include <string>

using namespace std;

class Device {
public:
	Device(TCPBaseSocket & sock) : sock(sock){};
	virtual ~Device(){};
	int publish(char * buffer, char * hierarchy);
    int subcriber(char * hierarchy);
    int unsubscriber(char * hierarchy);
    int receive(char * buffer);
private:
	TCPBaseSocket & sock;
};

#endif /* SENSOR_H_ */