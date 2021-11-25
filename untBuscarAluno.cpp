//---------------------------------------------------------------------------

#include <vcl.h>
#pragma hdrstop

#include "untBuscarAluno.h"
#include "untPrincipal.h"
#include "untAluguel.h"
#include "Biblioteca.h"
//---------------------------------------------------------------------------
#pragma package(smart_init)
#pragma resource "*.dfm"
TfrmBuscarAluno *frmBuscarAluno;
//---------------------------------------------------------------------------
__fastcall TfrmBuscarAluno::TfrmBuscarAluno(TComponent* Owner)
        : TForm(Owner)
{
}

void getBibBusAluno(Biblioteca &b)
{
   p_bibBA = &b;
}
//---------------------------------------------------------------------------
void __fastcall TfrmBuscarAluno::rdSelecioneClick(TObject *Sender)
{
if(rdSelecione->ItemIndex!=-1)
{
	edtBusca->Enabled=true;
	btnBuscar->Enabled=true;
	if (btnBuscar->Enabled == true)
	{
		btnAlugar->Enabled = false;
	}
	if (btnBuscar->Enabled == false)
	{
		btnAlugar->Enabled = true;
	}
	edtBusca->SetFocus();
}        
}
//---------------------------------------------------------------------------
void __fastcall TfrmBuscarAluno::btnBuscarClick(TObject *Sender)
{
string busca = edtBusca->Text.c_str();
int mat;

if (rdSelecione->ItemIndex==0)
{
	mat = p_bibBA->buscarCodAlunoMat(busca);
}

if (rdSelecione->ItemIndex==1)
{
	mat = p_bibBA->buscarCodAlunoNome(busca);
}

if (mat<0)
{
	MessageBoxA(NULL, "Aluno não cadastrado!", "Busca de Aluno", MB_OK);
}
else
{
	string matricula = p_bibBA->getMatAluno(mat);
	string nome = p_bibBA->getNomeAluno(mat);
	//AnsiString mat2 = AnsiString(matricula.c_str());
	//AnsiString nome2 = AnsiString(nome.c_str());
	edtMat->Text = matricula.c_str();
	edtNome->Text = nome.c_str();
	for (int i = 0; i < 4; i++)
	{
		int tempCodLivros = p_bibBA->cadAluno[mat].livrosAlugados[i];

		if (tempCodLivros == -1)
		{
			listLivros->Lines->Add("Possibilidade de Aluguel");
		}
		else
		{
			string nomeLivro = p_bibBA->getNomeLivro(tempCodLivros);
			listLivros->Lines->Add(nomeLivro.c_str());
		}


		AnsiString tempDatas = p_bibBA->cadAluno[mat].diaDevolver[i].c_str();
		if (tempDatas == "-1")
		{
			listDatas->Lines->Add("--/--/----");
		}
		else
		{
			listDatas->Lines->Add(tempDatas.c_str());
		}
	}
	rdSelecione->ItemIndex = -1;
	edtBusca->Enabled=false;
	btnBuscar->Enabled=false;
	btnAlugar->Enabled = true;
	edtBusca->Text="";
}        
}
//---------------------------------------------------------------------------
void __fastcall TfrmBuscarAluno::btnAlugarClick(TObject *Sender)
{
frmAluguel = new TfrmAluguel(Application);
frmAluguel->edtNome->Text = edtNome->Text;
frmBuscarAluno->Close();
frmAluguel->ShowModal();
delete frmAluguel;
}
//---------------------------------------------------------------------------

