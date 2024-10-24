/**
    Estrutura inicial para um jogo
    versão: 0.1 (Prof. Alex,  Adaptado Prof. Felski)
*/
#include <iostream>
#include <fstream>
#include <windows.h>
#include <conio.h>
#include <thread>
#include <chrono>
#include <string>
#include <vector>
#include <algorithm>
using namespace std::this_thread;
using namespace std::chrono;
using namespace std;

// Estrutura que representa o jogador
struct Jogador {
    string nome;
    int pontuacao;
    double tempo;
};

// Função de comparação para ordenar o ranking
bool compararJogadores(const Jogador&a, const Jogador&b) {
    if (a.pontuacao == b.pontuacao) {
        return a.tempo < b.tempo; // Se a pontuação for igual, ordena pelo menor tempo
    }
    return a.pontuacao > b.pontuacao; // Caso contrário, ordena pela maior pontuação
}

// Função para salvar os dados do jogador no arquivo
void salvarJogada(const Jogador& jogador) {
    ofstream arquivo("ranking.txt", ios::app); // Abre o arquivo em modo de adição

    if (arquivo.is_open()) {
        // Escreve o nome, pontuação e tempo no arquivo
        arquivo << jogador.nome << " "
                << jogador.pontuacao << " "
                << jogador.tempo << endl;
        arquivo.close();
    } else {
        cout << "Erro ao abrir o arquivo de ranking!" << endl;
    }
}

// Função para carregar o ranking do arquivo
vector<Jogador> carregarRanking() {
    ifstream arquivo("ranking.txt");
    vector<Jogador> ranking;
    string nome;
    int pontuacao;
    double tempo;

    while (arquivo >> nome >> pontuacao >> tempo) {
        Jogador jogador;
        jogador.nome = nome;
        jogador.pontuacao = pontuacao;
        jogador.tempo = tempo;
        ranking.push_back(jogador);
    }
    return ranking;
}

// Função para exibir o ranking ordenado
void exibirRanking(const vector<Jogador>& ranking) {
    cout << "Ranking Atualizado:" << endl;
    int posicao = 1;
    for (const Jogador& jogador : ranking) {
        cout << posicao << "º Lugar: "
             << "Nome: " << jogador.nome
             << " | Pontuação: " << jogador.pontuacao
             << " | Tempo: " << jogador.tempo << " segundos" << endl;
        posicao++;
    }
}


int difficulty(int &diffChange) {
    system("cls||clear");
    int diffOp = 0;
    cout << "Escolha a dificuldade!" << endl << "1 - Easy" << endl << "2 - Medium" << endl << "3 - Hard" << endl;
    cin >> diffOp;

    switch(diffOp) {
        default:
            diffOp = 2;
            break;
        case 1:
            system("cls||clear"); 
            diffChange = 35;
            //cout << "\tDificuldade: Easy\t" << endl << endl;
            break;
        case 2:
            system("cls||clear"); 
            diffChange = 25;
            //cout << "\tDificuldade: Medium\t" << endl << endl;
            break;
        case 3:
            system("cls||clear"); 
            diffChange = 15;
            //cout << "\tDificuldade: Hard\t" << endl << endl;
            break;
        case 4:
            system("cls||clear");
            diffChange = 5;
            //cout << "\tDificuldade: POR QUE VOCÊ ESCOLHEU ESSA DIFICULDADE?\t" << endl << endl;
            break;
        case 5:
            system("cls||clear");
            diffChange = 0;
            //cout << "\tDificuldade: BOA SORTE.\t" << endl << endl;
            break;
    }
    return(diffChange);

}

void menufunction (bool &isRunning, string &name) {
    bool menu = true;
    while (menu){
    int diffMode = 0;
    int op = 0;
    cout << "digite um numero para selecionar uma opcao:\n";
    cout << "1 - Start"<<endl;
    cout << "2 - Sobre"<<endl;
    cout << "3 - Dificuldade"<<endl;
    cout << "4 - Placar" <<endl;
    cout << "5 - Jogar Sozinho"<<endl;
    cout << "6 - Mudar Tema" << endl;
    cin >> op;
    switch (op){
case 1:
    system("cls||clear");
    cout << "Digite seu nome." << endl;
    cin >> name;
     isRunning = true;
     menu = false;
     break;
case 2:
    system("cls||clear");
    cout << "Nome dos criadores/Alunos e suas participações:"<<endl;
    cout << "Felipe Potratz Redondo De Menezes: Menus e Fisica da Bola" << endl;
    cout << "Bernardo Siqueira Amaro: Paddle, Fisica da Bola e Design do Jogo" << endl;
    cout << "Gustavo da Silva Bormanieri: Design do Jogo e Fisica da Bola" << endl;
    cout << " como o jogo funciona? : o usuario controlara uma raquete que deve rebater" << "\n" <<
    "uma bola, a qual deve acertar os blocos quebraveis, vence o jogo quando o usuario quebrar todos os blocos!"<< endl;
    cout << "controles: A e D, ou as duas setas Horizontais" << endl << endl;
    system("pause");
    break;
case 3:
    difficulty(diffMode);
    break;
case 4:

    system("cls||clear");
    system("pause");
    system("cls||clear");
    break;

case 5:
    system("cls||clear");
    name = "Demo";
    isRunning = true;
    menu = false;
    break;
case 6:
    int themeOp = 0;
    cout << "Qual tema gostaria? (1 - Azul | 2 - Vermelho | 3 - Verde | 4 - Branco)" << endl;
    cin >> themeOp;
    switch (themeOp)
    {
    case 1:
        system("Color 9");
        break;
    case 2:
        system("Color C");
        break;
    case 3:
        system("Color A");
        break;
    case 4:
        system("Color 7");
        break;
    case 5:
        system("Color 97");
        break;
    default:
        system("Color 7");
        break;
    }
    }

}
}

int contarBlocosQuebraveis(int m[18][21]) {
    //contador de blocos quebrados, usado para a condição de vitória.
    int contador = 0;
    for (int i = 0; i < 18; i++) {
        for (int j = 0; j < 21; j++) {
            if (m[i][j] == 2) {
                contador++;
            }
        }
    }
    return contador;
}


void aleatorizarblocos (int m [18][21]){
    srand(time(0));
    int count2 = 0;
    int count4 = 0;
    int inicioi = 0; int fimi = 7;
    int inicioj = 0; int fimj = 21;
    for (int i = inicioi; i <= fimi; i++){
        for (int j = inicioj; j <= fimj; j++){
              if (m [i][j] == 2 || m [i][j] == 4){
                  int randomnum = rand () % 3 * 2;
                 m [i][j] = randomnum; 
                 if (m [i][j] == 4){
                     count4++;
                     if (count4 > 5){
                        randomnum = rand () % 2 * 2; 
                 m[i][j] = randomnum;}
                 }
                 if (m [i][j] == 2 ) {
                   count2++;  
                   if (count2 > 40){
                    randomnum = 0;
                    m[i][j] = randomnum;}
                       }
                  }
                  }
}
}
void reset_game(int m[18][21], int mR[18][21], int &pontuacao, int &life) {
     for(int i = 0 ; i < 18 ; i++) {
                        for(int j = 0 ; j < 21 ; j++) {
                            m[i][j] = mR[i][j];
                        }
                    }
                    aleatorizarblocos(m);
                    life = 5;
                    pontuacao = 0;
}
int main() {
    system("cls||clear");
    ///ALERTA: NAO MODIFICAR O TRECHO DE CODIGO, A SEGUIR.
        //INICIO: COMANDOS PARA QUE O CURSOR NAO FIQUE PISCANDO NA TELA
        HANDLE out = GetStdHandle(STD_OUTPUT_HANDLE);
        CONSOLE_CURSOR_INFO     cursorInfo;
        GetConsoleCursorInfo(out, &cursorInfo);
        cursorInfo.bVisible = false; // set the cursor visibility
        SetConsoleCursorInfo(out, &cursorInfo);
        //FIM: COMANDOS PARA QUE O CURSOR NAO FIQUE PISCANDO NA TELA
        //INICIO: COMANDOS PARA REPOSICIONAR O CURSOR NO INICIO DA TELA
        short int CX=0, CY=0;
        COORD coord;
        coord.X = CX;
        coord.Y = CY;
        //FIM: COMANDOS PARA REPOSICIONAR O CURSOR NO INICIO DA TELA
    ///ALERTA: NAO MODIFICAR O TRECHO DE CODIGO, ACIMA.

    int m[18][21]={ 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1,
                    1, 0, 0, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 0, 0, 1,
                    1, 0, 0, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 0, 0, 1,
                    1, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 1,
                    1, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 1,
                    1, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 1,
                    1, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 1,
                    1, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 1,
                    1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1,
                    1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1,
                    1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1,
                    1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1,
                    1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1, 
                    1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1, 
                    1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1, 
                    1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1,
                    1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1,                   
                    1, 3, 3, 3, 3, 3, 3, 3, 3, 3, 3, 3, 3, 3, 3, 3, 3, 3, 3, 3, 1};

    int mR[18][21]={ 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1,
                    1, 0, 0, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 0, 0, 1,
                    1, 0, 0, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 0, 0, 1,
                    1, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 1,
                    1, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 1,
                    1, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 1,
                    1, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 1,
                    1, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 1,
                    1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1,
                    1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1,
                    1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1,
                    1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1,
                    1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1, 
                    1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1, 
                    1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1, 
                    1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1,
                    1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1,                   
                    1, 3, 3, 3, 3, 3, 3, 3, 3, 3, 3, 3, 3, 3, 3, 3, 3, 3, 3, 3, 1};

    aleatorizarblocos (m);
    //Posicao inicial do personagem no console
    int x=14, y=9, bX = 11, bY = 9;
    int moveBx = 1, moveBy = 1, life = 5;
     int moveSx = 1;
    int Sx = -1; 
    int Sy = -1; 
     //Variavel para tecla pressionada
    char tecla;
    bool isRunning = false, retry = false;
    int diff = 0;
    double tempo = 0;
    string name;
    int pontuacao = 0;  // Variável global para armazenar a pontuação
    int level = 1;
    menufunction(isRunning, name);
    difficulty(diff);
    while(isRunning == true){
        ///Posiciona a escrita no iicio do console
        SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), coord);

        ///Imprime o jogo: mapa e personagem.
        for(int i=0;i<18;i++){
            for(int j=0;j<21;j++){
                if(i==x && j==y || i==x && j==y+1 || i==x && j==y-1 || i==x && j==y+2 || i==x && j==y-2){
                    cout<<char(223); //personagem
                    } else if(i==bX && j==bY) {
                    cout<<char(79); // bola
                } else {
                    switch (m[i][j]){
                        case 0: cout<<" "; break; //caminho
                        case 1: cout<<char(219); break;//parede
                        case 2: cout<<char(178); break;//parede quebravel
                        case 3: cout<<char(176); break;//verificação
                        case 4: cout<<char(178); break;
                        case 6: cout<<char(64); break;
                        case 7: cout<<char(63); break;
                        case 8: cout<<char(62); break;
                        //default: cout<<"-"; //erro
                    } //fim switch
            }
            }
                cout<<"\n";
        } //fim for mapa

        ///executa os movimentos
         if ( _kbhit() ){
            tecla = _getch();
            switch(tecla)
            {
                case 75:case 'a': ///esquerda    
                    if(m[x][y-3] == 0 && name != "Demo") {
                        y -= 2;
                    }
                break;
                case 77: case 'd': ///direita
                    if(m[x][y+3] == 0 && name != "Demo") {
                    y += 2;
                }
                break;
                case 'z': //código ultra secreto de programador :)
                    life = 9999999;
                    break;
            }
         }
         if(name == "Demo") {

            y = bY;
            if(retry == true) {
                moveBx = 1;
                retry = false;
            }

         }

                 bX += moveBx; //muda o vertical da bola
                 bY += moveBy; //muda o horizontal da bola
                sleep_for(milliseconds(diff));

                //verificação da direção da bola
                if(m[bX+1][bY] != 0 || m[bX-1][bY] != 0 || bX+1 == x && bY == y || bX+1 == x && bY == y-1 || bX+1 == x && bY == y+1 || bX+1 == x && bY == y-2 || bX+1 == x && bY == y+2) {
                   //A bola inverte a posição vertical dela depois de bater em alguma das paredes
                    moveBx = moveBx * -1;
                }
                if (bX+1 == x && bY == y) {
                    int random = rand() % 3 + 1;
                    moveBy = 0;
                    if(name == "Demo") {
                        switch(random) {
                        case 1:
                        moveBy = -1;
                        break;
                        case 2:
                        moveBy = 0;
                        break;
                        case 3:
                        moveBy = 1;
                        break;
                    }
                    }
                    
                } else if (bX+1 == x && bY == y-1 || bX+1 == x && bY == y-2) {
                    //verificação se a bola está encostando na esquerda do paddle, para inverter o horizontal da bola
                    moveBy = -1;
                   
                } else if (bX+1 == x && bY == y+1 || bX+1 == x && bY == y+2) {
                    //verificação se a bola está encostando na direita do paddle, para inverter o horizontal da bola
                    moveBy = 1; //a bola vai pra direita.
                    
                }
                if(m[bX][bY+1] != 0 || m[bX][bY-1] != 0) {
                    moveBy = moveBy * -1;
                  
                }
                //fim da verificação da direção da bola
                //inicio da verificação de quebra das paredes
                if(m[bX][bY] == 2 ) {

                    m[bX][bY] = 0;
                    pontuacao += 10;
                }
                else if(m[bX+1][bY] == 2) {

                    m[bX+1][bY] = 0; 
                    pontuacao += 10;
                }
                else if(m[bX-1][bY] == 2) {

                    m[bX-1][bY] = 0;
                    pontuacao += 10;
                }
                else if(m[bX][bY+1] == 2) {

                    m[bX][bY+1] = 0;
                    pontuacao += 10;
               }
                else if(m[bX][bY-1] == 2) {
                    
                    m[bX][bY-1] = 0;
                    pontuacao += 10;
               }
              
                if(m[bX][bY] == 4 ) {
                    m[bX][bY] = 0;
                    pontuacao += 10;
                    int randomnum = rand () % 3 + 6;
                    m [bX][bY] = randomnum;
                    Sx = bX;
                    Sy = bY;
            
                }
                else if(m[bX+1][bY] == 4) {
                    m[bX+1][bY] = 0; 
                    pontuacao += 10;
                    int randomnum = rand () % 3 + 6;
                    m[bX+1][bY] = randomnum;
                    Sx = bX+1;
                    Sy = bY;
                    
                }
                else if(m[bX-1][bY] == 4) {
                    m[bX-1][bY] = 0;
                    pontuacao += 10;
                    int randomnum = rand () % 3 + 6;
                    m[bX-1][bY] = randomnum;
                    Sx = bX-1;
                    Sy = bY;
                   
                }
                else if(m[bX][bY+1] == 4) {
                    m[bX][bY+1] = 0;
                    pontuacao += 10;
                    int randomnum = rand () % 3 + 6;
                    m[bX][bY+1] = randomnum;
                    Sx = bX;
                    Sy = bY+1;
                    
               }
                else if(m[bX][bY-1] == 4) {
                    m[bX][bY-1] = 0;
                    pontuacao += 10;
                    int randomnum = rand () % 3 + 6;
                    m[bX][bY-1] = randomnum;
                    Sx = bX;
                    Sy = bY-1;

               }
               if (Sx != -1 && Sy != -1) {  // Verifica se existe um power-up ativo
        // Se a posição abaixo do power-up estiver vazia (ou seja, 0), move o power-up para lá
        if (m[Sx + 1][Sy] == 0) {
            m[Sx + 1][Sy] = m[Sx][Sy]; // Move o power-up para a posição abaixo
            m[Sx][Sy] = 0;  // Limpa a posição anterior
            
            Sx++;  // Atualiza a nova posição do power-up
        }
        // Se o power-up atingir o chão ou um bloco, ele para
        else if (m[Sx + 1][Sy] == 3) {
            Sx = -1;
            Sy = -1;  // Reseta a posição do power-up, pois ele parou
        }
    }
               //fim da verificação de quebra das paredes

            
                if(m[bX+1][bY] == 3) {
                    //verificação do chão(onde o jogador perde)
                    life -= 1;
                    retry = true;                     
                }
                if(retry == true) {
                // verificação do booleano para grudar a bola na raquete, dando ao jogador mais uma chance.
                        bX = x-2; 
                        bY = y;
                        moveBx = 0;
                        moveBy = 0;
                    if(tecla == ' ') {
                        moveBx = 1;
                        retry = false;
                    }
                }
                  
                if (pontuacao == 450){
                    //isRunning = false;
                    system("cls||clear");
                    retry = true;
                    level++;
                    reset_game(m, mR, pontuacao, life);
                    //cout << "    Voce ganhou!! PARABENS!!   " << endl << "\t" << name << "\t" << endl << "\t" << "Score:" << pontuacao << endl; 
                    

                    }
                if(life == 0) {
                    //isRunning = false;
                    system("clear||cls");
                    cout << "   Voce perdeu!!    " << endl << "\t" << name << "\t" << endl << "\t" << "Score:" << pontuacao << endl;
                    system("pause");
                    system("clear||cls");
                   
                    menufunction(isRunning, name);
                    reset_game(m, mR, pontuacao, life);
                   
                   } 
                   

               // Exibir vidas, nome e pontuação.
                 cout << name << endl; 
                 cout << "Vidas restantes: " << life << endl;
                 cout << "Score: " << pontuacao << endl;
                 cout << "Time: " << tempo << endl;
                 cout << "Level: " << level << endl;
                 cout << "Dificuldade: " << diff << endl;
 } //fim do laco do jogo
  
   return 0;
}

