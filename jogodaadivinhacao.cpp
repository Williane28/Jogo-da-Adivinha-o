#include <iostream>
#include <cstdlib>
#include <ctime>

using namespace std;

int main(void)
{
    cout << "**************************************" << endl;
    cout << "* Bem-vindos ao jogo da adivinhacao! *" << endl; 
    cout << "**************************************" << endl;

    cout << "Escolha o seu nivel de dificuldade: " << endl;
    cout << "Facil (F), Medio (M) ou Dificil (D)" << endl;

    char dificuldade;
    cin >> dificuldade;

    int numero_de_tentativas;

    if (dificuldade == 'F')
    {
        numero_de_tentativas = 15;
    }

    else if (dificuldade == 'M')
    {
        numero_de_tentativas = 10;
    }

    else 
    {
        numero_de_tentativas = 5;
    }
   
    srand(time(0));
    const int NUMERO_SECRETO = rand() % 100;

    bool nao_acertou = true;

    int tentativas = 0;

    double pontos = 1000.0;

    for (tentativas = 1;tentativas <= numero_de_tentativas; tentativas++)
    {
        cout << "Tentativa " << tentativas << endl;
        int chute;
        cout << "Qual seu chute? ";
        cin >> chute;
        cout << "O valor do seu chute e: " << chute << endl;   

        double pontos_perdidos = abs(chute - NUMERO_SECRETO) / 2.0;
        pontos -= pontos_perdidos;

        bool acertou = chute == NUMERO_SECRETO;
        bool maior = chute > NUMERO_SECRETO;

        if (acertou)
        {
            cout << "Parabens! voce acertou o numero secreto!\n" << endl;
            nao_acertou = false;
            break;
        } 
    
        else if (maior)
        {
            cout << "Seu numero foi maior que o numero secreto\n" << endl;
        }

        else
        {
            cout << "Seu numero foi menor que o numero secreto\n" << endl;
        }
    }
    cout << "Fim de Jogo! obrigada por jogar." << endl;
    if (nao_acertou)
    {
        cout << "Voce estorou o numero de tentativas. Tente novamente." << endl;
    }

    else
    {
        cout.precision(2);
        cout << "Voce acertou o jogo em " << tentativas << " tentativas" << endl;
        cout << fixed;
        cout << "Seu total de pontos: " << pontos << endl;
    }
}