#include <iostream>
#include "ListaDuplamenteEncadeada.cpp"


int main()
{
    int control = 0;
    while(control != -1)
    {
        ListaDuplamenteEncadeada lista;
        std::cout << "escolha dentre as opções: " << std::endl << "1 - Insirir" << std::endl << "2 - buscar" << std::endl << "3 - Imprimir" << std::endl;
        std::cin >> control;
        if(control == 1)
        {
            int num;
            std::cout << "Qual número deseja inserir?" << std::endl;
            std::cin >> num;
            lista.inserirNaCabeca(num);
        }
        else if(control == 2)
        {
            int num;
            std::cout << "Qual número deseja buscar?" << std::endl;
            std::cin >> num;
            lista.buscaCont(num);
        }
        else if(control == 3)
        {
            lista.imprimir();
        }
        else
        {
            std::cout << "Opção invalida" << std::endl;
        }
    }

}