#include <parser_Ativo.h>
#include <iostream>
#include <sstream>
#include "TCPBaseSocket.h"

using namespace std;

int main() {

  TAtivo pkt;

  // definindo os valores de varios campos 
  TAtivo::Choice_id & id = pkt.get_id();

  pkt.set_type(1234);
  pkt.set_idBroker(1111);
  pkt.set_idDevice(2222);

  TLooking lo = id.get_looking();
  lo.set_handshake("Ola");
  pkt.check_constraints();

  // mostra a estrutura de dados na tela
  cout << "Estrutura de dados em memória (antes de codificação XER):" << endl;
  pkt.show();

  // cria o codificador
  //ofstream out("pkt.data");
  //TAtivo::DerSerializer encoder(out);
  ostringstream output;
  TAtivo::XerSerializer encoder(output);

  // codifica a estrutura de dados
  encoder.serialize(pkt);
  //out.close();

  // cria o decodificador
//  ifstream arq("pkt.data");
//  TAtivo::DerDeserializer decoder(arq);

  TCPClientSocket sock;
  sock.connect("127.0.0.1", 5555);
  cout << "TESTE 1" << endl;
  string data = output.str();
  cout << "Sent: " << sock.send(data) << " bytes de " << data.size() << endl;
  sleep(1);

  sock.close();
}