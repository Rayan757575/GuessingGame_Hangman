# 🎮 GuessingGame_Hangman

[![educational-project](https://img.shields.io/badge/Projeto-Educacional-blue)](https://github.com/)

Um simples jogo de adivinhação feito em C++.

## 📜 Descrição
Este projeto foi desenvolvido para um trabalho escolar de lógica e programação.  
O jogo foi feito em C++ utilizando algumas bibliotecas da linguagem C. Ele é inspirado no clássico jogo da "Forca" e no programa de televisão "Roda Roda Jequiti".

É um jogo para **dois jogadores**, onde cada um irá inserir três palavras para o outro tentar adivinhar. As palavras são sorteadas aleatoriamente, e o formato do jogo é uma **melhor de três rodadas**.

---

## 🎯 Como Jogar

- É necessário apenas um **compilador de C++** para rodar o jogo.
- Cada jogador deverá inserir **três palavras** (sem acentos, cedilhas, números ou caracteres especiais).
- Durante a adivinhação, os jogadores devem inserir **uma letra por vez**.
- **Importante:** as palavras devem ter no máximo **12 letras**.

---

## 🏆 Sistema de Vitória

- Cada erro (letra inserida que não pertence à palavra) faz o jogador **perder 10 pontos**.
- Vence a rodada quem errar menos durante a adivinhação da palavra.
- Vence a partida quem ganhar **mais rodadas**.

---

## 🚀 Tecnologias

- C++
- Bibliotecas C padrão (`stdio.h`, `stdlib.h`)
- `Windows.h` (para comandos como limpar a tela e pausar o jogo)

---

## 📋 Observações

- Este projeto foi desenvolvido para fins educacionais.
- Funciona apenas em sistemas **Windows**, devido ao uso da biblioteca `Windows.h`.
  