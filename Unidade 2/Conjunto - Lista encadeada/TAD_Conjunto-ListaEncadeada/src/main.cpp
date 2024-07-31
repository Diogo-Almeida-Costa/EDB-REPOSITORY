#include <iostream>
#include "../header/Conjunto.h"
#include "Conjunto.cpp"

int main() 
{
  int num;
  int deseja;

  Conjunto c;
  while (true) 
  {
    std::cout << "Digite um número inteiro positivo para adicionar ao conjunto, ou um número negativo para terminar o programa." << std::endl;
    std::cin >> num;
    std::cin >> deseja;
    if (num < 0) 
    {
      std::cout << "Terminando o programa." << std::endl;
      break;
    }
    c.inserir(num);
    if(deseja == 1)
    {
      c.removerRepetidos();
    }
    std::cout << "Adicionando " << num << " ao conjunto. Tamanho do conjunto: " << c.tamanho() << std::endl;
    c.imprimir();

  }
  return 0;
}
