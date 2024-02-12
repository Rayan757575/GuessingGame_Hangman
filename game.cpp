#include <stdio.h>
#include <iostream>
#include <stdlib.h>
#include <Windows.h>

using namespace std;

//palavra[identificardor de palavra][numero de caracteres da palavra]

void exibicao(void){ // exibe uma informação na tela por 1 segundo
	Sleep(1000);
	system("cls");
}
void comoJogar(void){ // informações iniciais de como jogar
		int comecar = 0;
		cout << "Ola, bem vindo ao 'roda roda ganhei' onde voce podera jogar um jogo de adicinhação com seus amigos!\n";
		cout << "\nFunciona assim :\n\n1 - Sao tres rodadas - um melhor de tres - onde voce ira inserir 3 palavras para seu amigo adivinhar e vice-versa.\n2 - A cada rodada sera sorteada uma das palavras para o outro adivinhar";
		cout << "\n3 - O que errar menos chutes de letras vence a rodada.\n4 - o que vencer mais rodadas ganha a partida.";
		cout << "\n5 - Ao final do jogo voces poderao escolher se irao ou nao jogar mais uma partida.\n6 - OBS: as palavras deverao ser inseridas sem acentos ou cedilha.\n7 - Devera ser inserida uma letra por vez\n\n";
		cout << "\nVamos comecar? Insira qualquer numero para inciar: ";
	
		cin >> comecar;
		exibicao();
		cout << "Bom jogo!";
		exibicao();
}
void tracejado(int qtd){ //imprime os tracejados de cada palavra
	for(int i = 0; i < qtd; i ++){
		cout << "_ ";
	}
	cout<< "\n";
}
void informe(int player, int rodada, int outroP){ // uma perfumaria para indicar quem é o player da vez
	printf("Player %d sua vez! \nAdivinhe a %d palavra do player %d", player, rodada + 1, outroP);
}
void sorteio(int &sorteada, int vez, int *ja_foi_sorteada){ // sorteia uma das palavras inseridas
		sorteada = rand() % 3;
		while(sorteada == ja_foi_sorteada[0] || sorteada == ja_foi_sorteada[1] || sorteada == ja_foi_sorteada[2]){
			sorteada = rand () % 3;
		}
		ja_foi_sorteada[vez] = sorteada;
}
char entrada(string *dica, char palavra[3][12]){ //Fução de Entrada das palavras
	for(int i = 0; i < 3; i ++){
		printf("Informe sua %d palavra de no maximo 12 letras: ", i + 1);
		scanf("%s", palavra[i]);
		cout<< "Insira uma dica para a palavra: ";
		cin >> dica[i];
		system("cls");
	}
}
int adivinhacao(char palavra[3][12], string * dica, int sorteada){
	//declaração de variaveis
	bool acertou;	
	int acertos[12] = {2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2}; //cada letra que acertou
	int quantidade_l;
	char letra;
	int pontos;
	
	for(int i = 0; i < 12; i++){
		if(palavra[sorteada][i] != 2){
			quantidade_l = i;
		}
	}
		
	do{
		//chute de letras
		cout << "\nA dica da palavra e "<< dica[sorteada] << endl;
		cout <<"Insira uma letra: ";
		cin>> letra;
		system("cls");
			
		//checagem da letra
		for( int i = 0; i < quantidade_l; i ++){ 
			if(palavra[sorteada][i] == letra){
				cout << letra <<" ";
				acertos[i] = 1;
			}else if(acertos[i] == 1){
				cout << palavra[sorteada][i] << " ";
			}else{
				cout << "  ";
				pontos = pontos + 10;
			}	
		}
		cout<< "\n";
		tracejado(quantidade_l);
			
		// checagem pra  ver se a pessoa acertou a palavra
		for(int i = 0; i < quantidade_l; i ++){
			if(acertos[i] == 1 ){
				acertou = true;
			}else{
			 	acertou = false;
			 	break;
			}
		}
		if(acertou == true){
			exibicao();
			cout << "Voce acertou! ";
			exibicao();
			for(int i = 0; i < 12; i++){ // zera todos os valores de acertos [12], para nao entregar a proxima palavra
				acertos[1] = 2;
			}
		}
	}while(acertou != true);
	acertou = false; // zera a variavel acertou
	return pontos;
}
void start(){
	//declaração de variáveis
	int rodadaP1;
	int rodadaP2;
	char palavraP1[3][12] = {{2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2}, {2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2}, {2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2}} ;//palavra digitada do player 1
	char palavraP2[3][12] = {{2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2}, {2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2}, {2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2}} ;//palavra digitada do player 2
	string dicaP1[3]; 
	string dicaP2[3];
	int decrescemosP1; // a cada erro da tentativa o player perde 10 pontos, a cada rodada o que perder menos pontos leva a rodada e o que levar 2 ou mais ganha a partida, ou seja uma melhor de 3
	int decrescemosP2;
	int ja_foi_sorteada[3]; // verifica se o numero ja foi sorteado
	int sorteada; // sorteia uma das palavras
	
	cout << "Player 1, informe suas tres palavras:\n";
	entrada(dicaP1, palavraP1);
	cout << "Player 2, informe suas tres palavras:\n";
	entrada(dicaP2, palavraP2);
	
	for(int cont = 0; cont < 3; cont ++){
		cout << "A " << cont + 1 << " rodada vai comecar!\n";
		sorteio(sorteada, cont, ja_foi_sorteada);
		informe(2, cont, 1);
		decrescemosP1 =	adivinhacao(palavraP1, dicaP1, sorteada);
		informe(1, cont, 2);
		decrescemosP2 = adivinhacao(palavraP2, dicaP2, sorteada);
			
		if(decrescemosP1 < 	decrescemosP2){
			rodadaP1 = rodadaP1 + 1;
			cout << "O player 1 venceu a rodada!";
			exibicao();
		}else if(decrescemosP2 < decrescemosP1){
			rodadaP2 = rodadaP2 +1;
			cout << "O player 2 venceu a rodada!";
			exibicao();
		}else {
			cout << "A rodada terminou empatada!";
			exibicao();
		}
	}
	if(rodadaP1 > rodadaP2){
		cout << "Parabéns Player 1, voce venceu!";
		exibicao();
	}else if(rodadaP2 > rodadaP1){
		cout << "Parabéns Player 2, voce venceu!";
		exibicao();
	}else{
		cout << "Por algum acaso do destino terminou em empate!";
	}
}
int main(){	char continuar;

	comoJogar();
	do{
		start();
		cout << "Querem jogar mais uma partida? " << endl;
		cout << "Informe 's' para e 'n' para nao: ";
		cin >> continuar;
		exibicao();
	}while(continuar != 'n');
	
	return 0;
}
