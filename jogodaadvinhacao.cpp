#include <iostream>
#include <cstdlib>
#include <ctime>
using namespace std;

int main() {
    // Mensagem de boas-vindas ao jogador
    cout << "*************************************" << endl;
    cout << "* Bem-vindos ao jogo da advinhação! *" << endl;
    cout << "*************************************" << endl;

    // Solicita ao jogador escolher o nível de dificuldade
    cout << "Escolha o seu nível de dificuldade: " << endl;
    cout << "Fácil (F), Médio (M) ou Difícil (D)" << endl;

    // Lê a opção do jogador e armazena na variável 'dificuldade'
    char dificuldade;
    cin >> dificuldade;

    // Define o número de tentativas de acordo com a dificuldade escolhida
    int numero_tentativas;
    if (dificuldade == 'F') {
        numero_tentativas = 15; // Mais chances para o jogador
    } else if (dificuldade == 'M') {
        numero_tentativas = 10; // Dificuldade intermediária
    } else {
        numero_tentativas = 5;  // Poucas chances, maior desafio
    }

    // Gera um número aleatório entre 0 e 99 e o armazena em NUMERO_SECRETO
    srand(time(NULL)); // Inicializa a semente para gerar números aleatórios diferentes a cada execução
    const int NUMERO_SECRETO = rand() % 100;

    // Variáveis para controlar o loop e calcular a pontuação
    bool nao_acertou = true; // Indica se o jogador ainda não acertou o número
    int tentativas = 0;      // Contador de tentativas
    double pontos = 1000.0;   // Pontuação inicial do jogador

    // Loop principal do jogo, executado até o jogador acertar o número ou esgotar as tentativas
    for (tentativas = 1; tentativas <= numero_tentativas; tentativas++) {
        // Solicita o chute do jogador
        cout << "Tentativa " << tentativas << endl;
        cout << "Qual o seu chute?" << endl;
        int chute;
        cin >> chute;

        // Calcula a perda de pontos com base na diferença entre o chute e o número secreto
        double pontos_perdidos = abs((chute - NUMERO_SECRETO) / 2.0);
        pontos -= pontos_perdidos;

        // Verifica se o jogador acertou, se o chute foi maior ou menor que o número secreto
        bool acertou = chute == NUMERO_SECRETO;
        bool maior = chute > NUMERO_SECRETO;

        if (acertou) {
            // Se acertou, finaliza o loop e exibe a mensagem de vitória
            cout << "Parabéns! Você acertou o número secreto!" << endl;
            nao_acertou = false;
            break;
        } else if (maior) {
            // Se o chute foi maior, informa o jogador
            cout << "Seu chute foi maior que o número secreto!" << endl;
        } else {
            // Se o chute foi menor, informa o jogador
            cout << "Seu chute foi menor que o número secreto!" << endl;
        }
    }

    // Mensagem final, informando se o jogador ganhou ou perdeu e sua pontuação
    cout << "Fim de jogo!" << endl;
    if (nao_acertou) {
        cout << "Você perdeu! Tente Novamente" << endl;
    } else {
        cout << "Você acertou o número secreto em " << tentativas << " tentativas." << endl;
        cout.precision(2);
        cout << fixed;
        cout << "Sua pontuação foi de " << pontos << "." << endl;
    }

    return 0;
}