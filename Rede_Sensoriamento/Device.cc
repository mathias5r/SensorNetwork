/*
 * Device.cc
 *
 *  Created on: 25 de nov de 2016
 *      Author: mathias
 */

#include "Device.h"

int Device::publish(char * buffer, char * hierarchy){
    
    TAtivo pkt;
    TAtivo::Choice_id & id = pkt.get_id();
    TPublish p = id.get_publish();

    p.set_hierarchy(hierarchy);
    p.set_data(buffer);
    
    pkt.check_constraints();
    pkt.show();

    ostringstream output;
    TAtivo::XerSerializer encoder(output);
    encoder.serialize(pkt);
    string data = output.str();

    try{
        cout << "Publish: " << this->sock.send(data) << " bytes de " << data.size() << endl;
    }catch (TCPServerSocket::DisconnectedException e) {
        cout << e.what() << ": " << e.get_addr() << ':';
        cout << e.get_port()<< endl;
        return -1;
    }
    
    return data.size();
}

int Device::subcriber(char * hierarchy){

    TAtivo pkt;
    TAtivo::Choice_id & id = pkt.get_id();
    TSubscriber s = id.get_subcriber();

    s.set_hierarchy(hierarchy);

    pkt.check_constraints();
    pkt.show();

    ostringstream output;
    TAtivo::XerSerializer encoder(output);
    encoder.serialize(pkt);
    string data = output.str();

    try{
        cout << "Subscriber: " << this->sock.send(data) << " bytes de " << data.size() << endl;
    }catch (TCPServerSocket::DisconnectedException e) {
        cout << e.what() << ": " << e.get_addr() << ':';
        cout << e.get_port()<< endl;
        return -1;
    }
    
    return data.size();
}

int Device::unsubscriber(char * hierarchy){

    TAtivo pkt;
    TAtivo::Choice_id & id = pkt.get_id();
    TUnsubscriber s = id.get_unsubscriber();

    s.set_hierarchy(hierarchy);

    pkt.check_constraints();
    pkt.show();

    ostringstream output;
    TAtivo::XerSerializer encoder(output);
    encoder.serialize(pkt);
    string data = output.str();

    try{
        cout << "Usubscriber: " << this->sock.send(data) << " bytes de " << data.size() << endl;
    }catch (TCPServerSocket::DisconnectedException e) {
        cout << e.what() << ": " << e.get_addr() << ':';
        cout << e.get_port()<< endl;
        return -1;
    }
    
    return data.size();

}


int Device::receive(char * buffer){

    stringstream input;
    TAtivo::XerDeserializer decoder(input);

    string msg;
    
    try{
        msg = sock.recv(1024);
        cout << "Recebeu " << msg.size() << " bytes" << endl;
    }catch (TCPServerSocket::DisconnectedException e) {
        cout << e.what() << ": " << e.get_addr() << ':';
        cout << e.get_port()<< endl;
        return -1;
    }

    input.write(msg.c_str(), msg.size()); 

    TAtivo * other = decoder.deserialize();
    TAtivo::Choice_id & id = other->get_id();
    TNotify n = id.get_notify();

    buffer = (char *)n.get_data().c_str();
  
    return msg.size();
}
    
