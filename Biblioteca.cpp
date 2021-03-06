#include "Biblioteca.h"
#include <stdio.h>
#include <iostream>
#include <fstream>
#include <ctime>
#include <string>


Biblioteca::Biblioteca()
{
}

Biblioteca::~Biblioteca()
{
}

/*abaixo as fun??es de cadastro de livros, alunos ,aluguel e devolu??es de livros,
com as devidas verifica??es de nomes de livros ou alunos escritos de forma correta
tamb?m verifica??o de quantidade m?xima permitida de livros por aluno (4), e verifica??o
da quantidade de livros no estoque com a quantidade devolvida, pois sem essa verifica??o
poderiam haver mais devolu??es de livros do que a quantidade dispon?vel no acervo*/

int Biblioteca::getMaxDias()
{
	return maxDias;
}
void Biblioteca::setMaxDias(int max)
{
	maxDias = max;
}
float Biblioteca::getMulta()
{
	return valorMulta;
}
void Biblioteca::setMulta(float mul)
{
	valorMulta = mul;
}
void Biblioteca::cadastrarAluno(string matAluno, string nAluno)//fun??o de cadastrar aluno
{
	aluno x;
	x.matriculaAluno = matAluno;
	x.nomeAluno = nAluno;

	int i;
	for (i = 0; i < 4; i++)
	{
		x.livrosAlugados[i] = -1;
		x.diaDevolver.push_back("-1");
		x.diaAno[i]=-1;
	}
	cadAluno.push_back(x);
}
int Biblioteca::buscarCodAlunoNome(string nAluno) //fun??o de buscar aluno com retorno da posi??o do aluno no vector cadAluno
{
	int i;
	for (i = 0; i < cadAluno.size() ; i++)
	{
		if (cadAluno[i].nomeAluno == nAluno)
		{
			return i;
		}
	}
	return -1;
}
int Biblioteca::buscarCodAlunoMat(string matAluno)
{
	int i;
	for (i = 0; i < cadAluno.size(); i++)
	{
		if (cadAluno[i].matriculaAluno == matAluno)
		{
			return i;
		}
	}
	return -1;
}
string Biblioteca::getMatAluno(int num)
{
	if (num == -1)
		return "Aluno n?o cadastrado!";
	else
		return cadAluno[num].matriculaAluno;
}
string Biblioteca::getNomeAluno(int num)
{
	if (num == -1)
		return "Aluno n?o cadastrado!";
	else
		return cadAluno[num].nomeAluno;
}
void Biblioteca::cadastrarLivro(string isbn, string nLivro, int qtde)//fun??o de cadastrar livro
{
	livro y;
	y.isbnLivro = isbn;
	y.nomeLivro = nLivro;
	y.qtdeTotal = qtde;
	y.qtdeDisponivel = qtde;
	y.previsaoDia = "-1";
	cadLivro.push_back(y);
}
int Biblioteca::buscarCodLivroNome(string nLivro)
{
	int i;
	for (i = 0; i < cadLivro.size(); i++)
	{
		if (cadLivro[i].nomeLivro == nLivro)
		{
			return i;
		}
	}
	return -1;
}
int Biblioteca::buscarCodLivroIsbn(string isbn)
{
	int i;
	for (i = 0; i < cadLivro.size(); i++)
	{
		if (cadLivro[i].isbnLivro == isbn)
		{
			return i;
		}
	}
	return -1;
}
string Biblioteca::getIsbnLivro(int num)
{
	if (num == -1)
		return "Livro n?o nadastrado!";
	else
		return cadLivro[num].isbnLivro;
}
string Biblioteca::getNomeLivro(int num)
{
	if (num == -1)
		return "Livro n?o nadastrado!";
	else
		return cadLivro[num].nomeLivro;
}
int Biblioteca::getQtdeLivro(int num)
{
    if (num == -1)
		return 0;
	else
		return cadLivro[num].qtdeDisponivel;
}
int Biblioteca::alugarLivro(string aluno, string nLivro, string diaDev, int diaDevInt)//fun??o de buscar livro, que, como na busca por aluno, retorna a posi??o
{
	int posAluno = buscarCodAlunoNome(aluno);
	int posLivro = buscarCodLivroNome(nLivro);

	if ((posLivro == -1) || (cadLivro[posLivro].qtdeDisponivel==1))
	{
		return -1; //se o livro n?o existir ou tiver somente o cativo
	}
	else
	{
		if (posAluno == -1)
		{
			return -2; //se o aluno n?o for cadastrado retorna false
		}
		else
		{
			int i;
			for (i = 0; i < 4; i++)
			{
				if (cadAluno[posAluno].livrosAlugados[i] == -1)
				{
					//time_t now;
					//time(&now); //guarda a data atual na vari?vel now
					//struct tm *timeinfo;
					//timeinfo = localtime(&now);//guarda o valor de now numa struct tm

					cadAluno[posAluno].livrosAlugados[i] = posLivro;//guarda o c?digo do livro alugado pelo aluno
					cadLivro[posLivro].qtdeDisponivel = cadLivro[posLivro].qtdeDisponivel-1;//diminui 1 do estoque

					//gravando o dia de devolver em string
					cadAluno[posAluno].diaDevolver[i] = diaDev;

					//gravando o dia de devolver em inteiro
					cadAluno[posAluno].diaAno[i] = diaDevInt;

					//define menor previs?o de entrega pro livro
                    if (cadLivro[posLivro].previsaoDia == "-1")
					{
						cadLivro[posLivro].previsaoDia = diaDev;
					}
					if (cadLivro[posLivro].previsaoDia > diaDev)
					{
						cadLivro[posLivro].previsaoDia = diaDev;
					}
					return -3; //se houver possibilidade de aluguel (-1) o aluguel ? feito e retorna true, encerrando a fun??o
								//impedindo de cadastrar esse aluguel em mais de uma posi??o permitida
				}
			}
		}
	}
	return -4; //este false  s? ocorre se o aluno j? tiver 4 livros alugados, (isso acontece se o for chegar ? 4)
}
float Biblioteca::devolverLivro(string nAluno, string nLivro, int diaAnoAtual)
{
	int livroDevolvido = buscarCodLivroNome(nLivro);
	int alunoDevolvendo=buscarCodAlunoNome(nAluno);

	//time_t now;
	//time(&now); //guarda a data atual na vari?vel now
	//struct tm *timeinfo;
	//timeinfo = localtime(&now);//guarda o valor de now numa struct tm

	if (livroDevolvido == -1)
	{
		return -1; //se o livro n?o existir ou houver algum erro de digita??o
	}
	else
	{
		if (alunoDevolvendo == -1)
		{
			return -2; //se o aluno n?o for cadastrado ou erro de digita??o retorna false
		}
		else
		{
			int i;
			for (i = 0; i < 4; i++)
			{
				if (cadAluno[alunoDevolvendo].livrosAlugados[i] == livroDevolvido)
				{
					if ((diaAnoAtual - cadAluno[alunoDevolvendo].diaAno[i]) <= maxDias)//verifica se o aluno est? devolvendo o livro no prazo
					{
						//"zerando" os dados, para permitir novo aluguel
						cadAluno[alunoDevolvendo].livrosAlugados[i] = -1;
						cadAluno[alunoDevolvendo].diaDevolver[i] = "-1";
						cadAluno[alunoDevolvendo].diaAno[i] = -1;
						cadLivro[livroDevolvido].qtdeDisponivel = cadLivro[livroDevolvido].qtdeDisponivel+1;
						cadLivro[livroDevolvido].previsaoDia = "-1";
						return 0; //para que a fun??o n?o zere todos os alugueis
					}
					else//caso n?o, calcula o valor da multa a ser paga
					{
						//calcula o valor de multa baseado na diferen?a de dias
						float multa = (diaAnoAtual - cadAluno[alunoDevolvendo].diaAno[i])*valorMulta;
						//"zera" os valores, permitindo novo aluguel
						cadAluno[alunoDevolvendo].livrosAlugados[i] = -1;
						cadAluno[alunoDevolvendo].diaDevolver[i] = "-1";
						cadAluno[alunoDevolvendo].diaAno[i] = -1;
						cadLivro[livroDevolvido].qtdeDisponivel = cadLivro[livroDevolvido].qtdeDisponivel+1;
						cadLivro[livroDevolvido].previsaoDia = "-1";
						return multa; //retorna o valor da multa a pagar
					}
				}
			}
		}
	}
	return -3; //este false  s? ocorre se o aluno n?o tiver o livro em quest?o alugado
}
void Biblioteca::gravarCadAluno()
{
	ofstream fout("dataAlunos.txt");
	if (!fout.is_open())
		return;
	fout << cadAluno.size() << endl;
	for (int i = 0; i < cadAluno.size(); i++)
	{
		fout << cadAluno[i].matriculaAluno << 'x' << endl <<cadAluno[i].nomeAluno << 'x' << endl;

		fout << cadAluno[i].livrosAlugados[0] << endl;
		fout << cadAluno[i].livrosAlugados[1] << endl;
		fout << cadAluno[i].livrosAlugados[2] << endl;
		fout << cadAluno[i].livrosAlugados[3] << endl;

		fout << cadAluno[i].diaDevolver[0] << endl;
		fout << cadAluno[i].diaDevolver[1] << endl;
		fout << cadAluno[i].diaDevolver[2] << endl;
		fout << cadAluno[i].diaDevolver[3] << endl;

		fout << cadAluno[i].diaAno[0] << endl;
		fout << cadAluno[i].diaAno[1] << endl;
		fout << cadAluno[i].diaAno[2] << endl;
		fout << cadAluno[i].diaAno[3] << endl;
	}
	fout.close();
}
void Biblioteca::lerCadAluno()
{
	cadAluno.clear();

	ifstream fin("dataAlunos.txt");
        if (!fin.is_open() || fin.eof())
		return;
	int tamanho;
	fin >> tamanho;
	aluno temp;
	for (int j = 0; j < 4; j++)
	{
		temp.diaDevolver.push_back("-1");
	}
	for (int i = 0; i < tamanho; i++)
	{
                string tempMat;
		getline(fin, tempMat, 'x');
                tempMat = tempMat.erase(tempMat.begin()+0);
                temp.matriculaAluno = tempMat;

                string tempNome;
		getline(fin, tempNome, 'x');
                tempNome = tempNome.erase(tempNome.begin()+0);
                temp.nomeAluno=tempNome;

		fin >> temp.livrosAlugados[0];
		fin >> temp.livrosAlugados[1];
		fin >> temp.livrosAlugados[2];
		fin >> temp.livrosAlugados[3];

		fin >> temp.diaDevolver[0];
		fin >> temp.diaDevolver[1];
		fin >> temp.diaDevolver[2];
		fin >> temp.diaDevolver[3];

		fin >> temp.diaAno[0];
		fin >> temp.diaAno[1];
		fin >> temp.diaAno[2];
		fin >> temp.diaAno[3];
		cadAluno.push_back(temp);
	}
}
void Biblioteca::gravarCadLivro()
{
	ofstream fout("dataLivros.txt");
	if (!fout.is_open())
		return;
	fout << cadLivro.size() << endl;
	for (int i = 0; i < cadLivro.size(); i++)
	{
                fout << cadLivro[i].isbnLivro << 'x' << endl <<cadLivro[i].nomeLivro << 'x' << endl << cadLivro[i].previsaoDia << 'x' << endl;
		fout << cadLivro[i].qtdeTotal << endl;
		fout << cadLivro[i].qtdeDisponivel << endl;
	}
	fout.close();
}
void Biblioteca::lerCadLivro()
{
	cadLivro.clear();

	ifstream fin("dataLivros.txt");
        if (!fin.is_open() || fin.eof())
        	return;
	int tamanho;
	fin >> tamanho;
	livro temp;
	for (int i = 0; i < tamanho; i++)
	{
		string tempIsbn;
		getline(fin, tempIsbn, 'x');
                tempIsbn = tempIsbn.erase(tempIsbn.begin()+0);
		temp.isbnLivro = tempIsbn;

		string tempNomeLivro;
		getline(fin, tempNomeLivro, 'x');
                tempNomeLivro = tempNomeLivro.erase(tempNomeLivro.begin()+0);
		temp.nomeLivro = tempNomeLivro;

                string tempPrevisao;
		getline(fin, tempPrevisao, 'x');
                tempPrevisao = tempPrevisao.erase(tempPrevisao.begin()+0);
		temp.previsaoDia = tempPrevisao;

		fin >> temp.qtdeTotal;
		fin >> temp.qtdeDisponivel;

		cadLivro.push_back(temp);
	}
}
void Biblioteca::gravarConfgs()
{
    ofstream foutConfgs("dataConfgs.txt");
	if (!foutConfgs.is_open())
		return;
    foutConfgs << getMaxDias() << endl;
    foutConfgs << getMulta();
}
void Biblioteca::lerConfgs()
{
    ifstream finConfgs("dataConfgs.txt");
        if (!finConfgs.is_open() || finConfgs.eof())
        	return;
    int max;
    finConfgs >> max;
    setMaxDias(max);

    float mult;
    finConfgs >> mult;
    setMulta(mult);
}
