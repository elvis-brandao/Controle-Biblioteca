//---------------------------------------------------------------------------

#include <vcl.h>
#pragma hdrstop

#include "untBuscaLivro.h"
#include "untPrincipal.h"
#include "untAluguel.h"
//---------------------------------------------------------------------------
#pragma package(smart_init)
#pragma resource "*.dfm"
TfrmBuscaLivro *frmBuscaLivro;
//---------------------------------------------------------------------------
__fastcall TfrmBuscaLivro::TfrmBuscaLivro(TComponent* Owner)
        : TForm(Owner)
{
}

void getBibBusLivro(Biblioteca &b)
{
   p_bibBL = &b;
}
//---------------------------------------------------------------------------
void __fastcall TfrmBuscaLivro::rdOpcaoClick(TObject *Sender)
{
if(rdOpcao->ItemIndex!=-1)
{
	edtBusca->Enabled=true;
	btnBuscar->Enabled=true;
	if (btnBuscar->Enabled == true)
	{
		btnAlugar->Enabled = false;
	}
	else
	{
		btnAlugar->Enabled = true;
	}
	edtBusca->SetFocus();
}        
}
//---------------------------------------------------------------------------
void __fastcall TfrmBuscaLivro::btnBuscarClick(TObject *Sender)
{
AnsiString procura = edtBusca->Text;
int res;

if (rdOpcao->ItemIndex==0)
{
	res = p_bibBL->buscarCodLivroIsbn(procura.c_str());
}

if (rdOpcao->ItemIndex==1)
{
	res = p_bibBL->buscarCodLivroNome(procura.c_str());
}

if (res<0)
{
	MessageBoxA(NULL, "Livro não cadastrado!", "Busca de Livro", MB_OK);
}
else
{
	string isbn = p_bibBL->getIsbnLivro(res);
	string nomeL = p_bibBL->getNomeLivro(res);
	int qtdeL = p_bibBL->getQtdeLivro(res);
	AnsiString isbnS = AnsiString(isbn.c_str());
	AnsiString nomeLS = AnsiString(nomeL.c_str());
	edtVolumes->Text = IntToStr(qtdeL);
	edtISBN->Text = isbnS.c_str();
	edtNome->Text = nomeLS.c_str();
	if (p_bibBL->cadLivro[res].previsaoDia == "-1")
	{
		edtDevolucao->Text = "--/--/----";
	}
	else
	{
		edtDevolucao->Text = p_bibBL->cadLivro[res].previsaoDia.c_str();
	}
	rdOpcao->ItemIndex = -1;
	edtBusca->Enabled = false;
	btnBuscar->Enabled = false;
	btnAlugar->Enabled = true;
	edtBusca->Text = "";
}
}
//---------------------------------------------------------------------------
void __fastcall TfrmBuscaLivro::btnAlugarClick(TObject *Sender)
{
frmAluguel = new TfrmAluguel(Application);
frmAluguel->edtLivro->Text = edtNome->Text;
frmBuscaLivro->Close();
frmAluguel->ShowModal();
delete frmAluguel;
}
//---------------------------------------------------------------------------

