#include <iostream>
#include <time.h>

using namespace std;

    #define qntLinhas 5
    #define qntColunas 5
    #define qntBombas 7

int main()
{
    int contJogadas, contBombas, numLinha, numColuna, linhas, colunas;
    bool gameover, numInvalido, jogadaInvalida;
    char matrizApresentada[qntLinhas] [qntColunas], matrizControladora [qntLinhas] [qntColunas];
    
    contJogadas =0;
    contBombas = 0;
    gameover = false;
    numInvalido = false;
    jogadaInvalida = false;
    
    cout<<"Seja bem vindo ao Campo Minado"<<endl;
  
    system("clear");
    
    srand(time(NULL));
    
    if (qntLinhas < 2 || qntColunas < 2 || qntBombas < 2) {
        jogadaInvalida = true;
        cout<<"Jogada Invalida, verifique a quantidade de linhas e colunas";
    }
    
    if (jogadaInvalida == false) {
        for (numLinha = 0; numLinha<qntLinhas; numLinha++) {
            for (numColuna = 0; numColuna<qntColunas; numColuna++) {
                matrizApresentada [numLinha] [numColuna] = ' ';
                matrizControladora [numLinha] [numColuna] = '0';
            }
        }
        
        srand (time(NULL));
        for (contBombas = 0; contBombas<qntBombas; contBombas++) {
            do {
                numLinha = rand()%qntLinhas;
                numColuna = rand()%qntColunas;
                cout<<"Linha:" << numLinha << endl;
                cout<<"Coluna:" << numColuna << endl;
            } while (matrizControladora[numLinha] [numColuna] == 'x');
            matrizControladora [numLinha] [numColuna] = 'x';
        }
        for (numLinha = 0; numLinha<qntLinhas; numLinha++) {
            for (numColuna = 0; numColuna<qntColunas; numColuna++) {
                if (matrizControladora [numLinha] [numColuna] == 'x') {
                    if(numLinha - 1 >= 0) {
                        if (matrizControladora [numLinha - 1] [numColuna] != 'x') 
                            matrizControladora[numLinha - 1] [numColuna]++;
                    }
                    if (numLinha + 1 < qntLinhas) {
                        if (matrizControladora[numLinha + 1] [numColuna] != 'x') 
                            matrizControladora [numLinha + 1] [numColuna]++;
                    }
                    if (numColuna - 1 >= 0) {
                        if (matrizControladora [numLinha] [numColuna - 1] != 'x') 
                            matrizControladora [numLinha] [numColuna - 1]++;
                    }
                    if (numColuna + 1 < qntColunas) {
                        if (matrizControladora[numLinha] [numColuna + 1] != 'x') 
                            matrizControladora[numLinha] [numColuna + 1]++;
                    }
                    if (numLinha - 1 >= 0 && numColuna - 1 >= 0){
                        if (matrizControladora [numLinha - 1] [numColuna - 1] != 'x') 
                            matrizControladora [numLinha - 1] [numColuna - 1]++;
                    }
                    if (numLinha - 1 >= 0 && numColuna + 1 < qntColunas) {
                        if (matrizControladora [numLinha - 1] [numColuna + 1] != 'x') 
                            matrizControladora [numLinha - 1] [numColuna + 1]++;
                    }
                    if (numLinha + 1 <qntLinhas && numColuna + 1 < qntColunas) {
                        if (matrizControladora [numLinha + 1] [numColuna + 1] != 'x') 
                            matrizControladora [numLinha + 1] [numColuna + 1]++;
                    }
                    if(numLinha + 1 <= qntLinhas && numColuna - 1 >= 0) {
                        if (matrizControladora [numLinha + 1] [numColuna - 1] != 'x') 
                            matrizControladora [numLinha + 1] [numColuna - 1]++;
                    }
                }
            }
        }
            while(!gameover) {
                system("clear");
                cout<<"Numero de jogadas corretas: " << contJogadas << "\n\n";
                cout<< "   ";
                for (numColuna = 0; numColuna < qntColunas; numColuna++) {
                    cout<< " "<< numColuna;
                }
                for (numLinha = 0; numLinha<qntLinhas; numLinha++) {
                    cout<<"\n" << numLinha << "-";
                    for (numColuna = 0; numColuna<qntColunas; numColuna++) {
                        if (numColuna == qntColunas - 1) {
                            cout << "|" << matrizApresentada[numLinha] [numColuna] << "|";
                        } else {
                            cout << "|" << matrizApresentada [numLinha] [numColuna];
                        }
                    }
                }
                cout << endl;
                do {
                    numInvalido = false;
                    cout << "\nInforme um numero correspondente a uma linha: " << "\n";
                    cin >> linhas;
                    cout << "Informe um numero correspondente a uma coluna: " << "\n";
                    cin >> colunas;
                    
                    if (linhas>qntLinhas || linhas<0 || colunas>qntColunas || colunas < 0) {
                        cout << "Esse numero e invalido";
                        numInvalido = true;
                    }
                    if (matrizApresentada[linhas][colunas] == matrizControladora [linhas][colunas]) {
                        cout << "Jogada invalida.\n";
                        numInvalido = true;
                    }
                } while (numInvalido == true); 
                    matrizApresentada [linhas][colunas] = matrizControladora[linhas][colunas];
                    
                    if (matrizApresentada[linhas][colunas] == 'x'){
                        cout<<"   ";
                        for (numColuna = 0; numColuna<qntColunas;numColuna++) {
                            cout << " " << numColuna;
                        }
                        for (numLinha = 0; numLinha<qntLinhas;numLinha++) {
                            cout<< "\n " << numLinha << "-";
                            for (numColuna = 0; numColuna<qntColunas;numColuna++) {
                                if (numColuna == qntColunas - 1) {
                                    cout << "|" << matrizControladora [numLinha] [numColuna] << "|";
                                } else {
                                    cout << "|" << matrizControladora [numLinha] [numColuna];
                                }
                            }
                        }
                        cout << endl;
                        gameover = true;
                        contJogadas++;
                        cout << "Voce foi explodido, tente novamente!" << "\n";
                        cout << "Numero de jogadas realizadas:" << contJogadas << "\n";
                    } else {
                        contJogadas++;
                    }
                    if ((qntLinhas * qntColunas) - qntBombas == contJogadas && gameover == false) {
                        cout << "\n:";
                        for (numColuna = 0; numColuna<qntColunas; numColuna++) {
                            cout << " " << numColuna << "\n";
                        }
                        for (numLinha = 0; numLinha < qntLinhas; numLinha++) {
                            cout << " " << numLinha << "\n";
                        }
                        gameover = true;
                        cout << "Parabens, voce ganhou o jogo e nao foi explodido!" << "\n";
                        cout << "Numero de jogadas realizadas: " << contJogadas;
                    }
                }
            }
              return 0;
        }

