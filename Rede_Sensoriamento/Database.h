/*
 * Device.h
 *
 *  Created on: 25 de nov de 2016
 *      Author: mathias
 */

#ifndef DATABASE_H_
#define DATABASE_H_

class Database {
public:
    enum Begin{Sala1 = 1,Sala2};
    enum Sala1{Janela1 = 1, Porta1, Armario1};
    enum Sala2{Janela2 = 1, Porta2, Armario2};
	Database(){};
	virtual ~Database(){};	
private:

};


#endif /* DATABASE_H_ */
