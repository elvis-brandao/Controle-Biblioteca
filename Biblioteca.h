/*classe biblioteca Elvis, Messias Ponte.*/

#pragma once
#ifndef BIBLIOTECA_H
#define BIBLIOTECA_H
#include <vector>
#include <ctime>
#include<fstream>
#include<string>

using namespace std;

struct aluno
{
	string matriculaAluno;
	string nomeAluno;
	int livrosAlugados[4];
	vector <string> diaDevolver;
	int diaAno[4];
};

struct livro
{
	string isbnLivro;
	string nomeLivro;
	int qtdeTotal;
	int qtdeDisponivel;
	string previsaoDia;
};

class Biblioteca
{
public:
	Biblioteca();
	~Biblioteca();

	int getMaxDias();
	void setMaxDias(int max);
	float getMulta();
	void setMulta(float mul);
	void cadastrarAluno(string matAluno, string nAluno); //cadastro de alunos
	int buscarCodAlunoNome(string nomeAluno); // fun?ao visualizar cadastro aluno fornecendo cod aluno
	int buscarCodAlunoMat(string matAluno);
	string getMatAluno(int num);
	string getNomeAluno(int num);
	void cadastrarLivro(string isbn, string nLivro, int qtde); //cadastro livro
	int buscarCodLivroNome(string nomeLivro);// fun?ao procurar livro
	int buscarCodLivroIsbn(string isbn);
	string getIsbnLivro (int num);
	string getNomeLivro (int num);
	int getQtdeLivro (int num);
	int alugarLivro(string aluno, string nLivro, string diaDev, int diaDevInt); //alugar livro
	float devolverLivro(string nAluno, string nLivro, int diaAnoAtual);
	void gravarCadAluno();
	void lerCadAluno();
	void gravarCadLivro();
	void lerCadLivro();

        void gravarConfgs();
	void lerConfgs();

	vector <aluno> cadAluno;
	vector <livro> cadLivro;
	int maxDias;
	float valorMulta;
private:

};

#endif