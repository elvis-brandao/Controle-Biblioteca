//---------------------------------------------------------------------------

#include <vcl.h>
#pragma hdrstop

#include "untAluguel.h"
#include "untPrincipal.h"
#include "Biblioteca.h"
//---------------------------------------------------------------------------
#pragma package(smart_init)
#pragma resource "*.dfm"
TfrmAluguel *frmAluguel;
//---------------------------------------------------------------------------
__fastcall TfrmAluguel::TfrmAluguel(TComponent* Owner)
        : TForm(Owner)
{
}

void getBibAlDevLivro(Biblioteca &b)
{
   p_bibADL = &b;
}
//---------------------------------------------------------------------------



void __fastcall TfrmAluguel::FormCreate(TObject *Sender)
{
dtAluguel->Date = dtAluguel->Date.CurrentDate();
dtDevolucao->Date = dtAluguel->Date.operator +=(p_bibADL->getMaxDias());
}
//---------------------------------------------------------------------------

void __fastcall TfrmAluguel::rdSelecioneClick(TObject *Sender)
{
if(rdSelecione->ItemIndex!=-1)
{
	edtNome->Enabled=true;
	edtLivro->Enabled=true;
	btnConfirmar->Enabled = true;
}
if(rdSelecione->ItemIndex == 0)
{
	btnConfirmar->Caption = "Alugar";
}
else
{
	btnConfirmar->Caption = "Devolver";
}
if(rdSelecione->ItemIndex == 1)
{
	gpDataDevolucao->Visible = false;
	gpDataAluguel->Caption = " Data Atual ";
}
}
//---------------------------------------------------------------------------

void __fastcall TfrmAluguel::btnConfirmarClick(TObject *Sender)
{

AnsiString nomeAluno = edtNome->Text;
AnsiString nomeLivro = edtLivro->Text;
AnsiString diaAluguel = dtAluguel->Date.DateString();
AnsiString diaDevolver = dtDevolucao->Date.DateString();
int diaDevolverInteiro = dtDevolucao->Date.operator int();
int diaHoje = dtAluguel->Date.operator int();

if (rdSelecione->ItemIndex == 0)
{
	int prova = p_bibADL->alugarLivro(nomeAluno.c_str(), nomeLivro.c_str(), diaDevolver.c_str(), diaDevolverInteiro);
	if (prova == -1)
	{
		MessageBoxA(NULL, "Verificar se o nome do livro est? correto ou se somente o cativo est? dispon?vel!", "Alugar livro", MB_OK);
	}
	if (prova == -2)
	{
		MessageBoxA(NULL, "Verifique se o Aluno est? cadastrado", "Aluguel de Livro", MB_OK);
	}
	if (prova == -3)
	{
		//p_bibADL->alugarLivro(nomeAluno.c_str(), nomeLivro.c_str(), diaDevolver.c_str(), diaDevolverInteiro);
		rdSelecione->ItemIndex = -1;
		edtNome->Text = "";
		edtLivro->Text = "";
		btnConfirmar->Enabled = false;
		//getBibPrincipal(p_bibADL);
		MessageBoxA(NULL, "Livro Alugado com sucesso!", "Aluguel de Livro", MB_OK);
	}
	if (prova == -4)
	{
		MessageBoxA(NULL, "O Aluno j? tem 4 livros alugados!", "Aluguel de Livro", MB_OK);
    }
}
if (rdSelecione->ItemIndex == 1)
{
	float prova = p_bibADL->devolverLivro(nomeAluno.c_str(), nomeLivro.c_str(), diaHoje);
	if (prova == -1)
	{
		MessageBoxA(NULL, "Verificar se o nome do livro est? correto!", "Devolver livro", MB_OK);
	}
	if (prova == -2)
	{
		MessageBoxA(NULL, "Verifique se o Aluno est? cadastrado", "Devolver Livro", MB_OK);
	}
	if (prova == -3)
	{
		MessageBoxA(NULL, "O Aluno n?o tem esse livro alugado!", "Devolver Livro", MB_OK);
	}
	if (prova > -1)
	{
		//p_bibADL->devolverLivro(nomeAluno.c_str(), nomeLivro.c_str(), diaHoje);

		rdSelecione->ItemIndex = -1;
		edtNome->Text = "";
		edtLivro->Text = "";
		btnConfirmar->Enabled = false;
		//getBibPrincipal(p_bibADL);
		edtMulta->Text = "R$ " + FloatToStr(prova);// IntToStr(prova);
		pnlMulta->Visible = true;
		MessageBoxA(NULL, "Livro Devolvido com sucesso! - Verifique se h? multa", "Devolver Livro", MB_OK);
    }

}

}
//---------------------------------------------------------------------------

