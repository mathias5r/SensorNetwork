/*
 * Sensor.cc
 *
 *  Created on: 25 de nov de 2016
 *      Author: mathias
 */

#include "Sensor.h"

Sensor::Sensor(char * info, char * ip, TCPClientSocket & sock) : sock(sock) {
	this->info = info;
	this->ip = ip;
}

Sensor::~Sensor() {}

void Sensor::subscriber(){
	TAtivo pkt;
	TAtivo::Choice_id & id = pkt.get_id();
	TConnect co = id.get_connect();
	co.set_deviceType(true);
	co.set_deviceInfo(this->info);
	pkt.check_constraints();
	pkt.show();
	ostringstream output;
	TAtivo::XerSerializer encoder(output);
	encoder.serialize(pkt);
	string data = output.str();
    try{
	    cout << "Subscriber: " << this->sock.send(data) << " bytes de " << data.size() << endl;
        string msg = sock.recv(1024);
        // TESTAR QUE É UM CONFIRMAÇÃO DE REGISTRO
    }catch (TCPServerSocket::DisconnectedException e) {
        cout << e.what() << ": " << e.get_addr() << ':';
        cout << e.get_port()<< endl;
    }
}

int Sensor::get_value(){
    
    srand((unsigned)time(0)); //para gerar números aleatórios reais.
    int maior = 100;
    int menor = 1;
    int aleatorio = rand()%(maior-menor+1) + menor;
    return aleatorio;

}

void Sensor::send_value(){
    
    TAtivo pkt;
	TAtivo::Choice_id & id = pkt.get_id();
    TData da = id.get_data();
    da.set_info(this->info);
    char * aux = new char[10];
    sprintf(aux,"%d",get_value());
    da.set_payload(aux);
    pkt.check_constraints();
	pkt.show();
	ostringstream output;
	TAtivo::XerSerializer encoder(output);
	encoder.serialize(pkt);
	string data = output.str();
    try{
	    cout << "Data: " << this->sock.send(data) << " bytes de " << data.size() << endl;
    }catch (TCPServerSocket::DisconnectedException e) {
        cout << e.what() << ": " << e.get_addr() << ':';
        cout << e.get_port()<< endl;
    }
}




