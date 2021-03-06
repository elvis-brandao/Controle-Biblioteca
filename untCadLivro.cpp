//---------------------------------------------------------------------------

#include <vcl.h>
#pragma hdrstop

#include "untCadLivro.h"
#include "untPrincipal.h"
//---------------------------------------------------------------------------
#pragma package(smart_init)
#pragma resource "*.dfm"
TfrmCadLivro *frmCadLivro;
//---------------------------------------------------------------------------
__fastcall TfrmCadLivro::TfrmCadLivro(TComponent* Owner)
        : TForm(Owner)
{
}

void getBibCadLivro(Biblioteca &b)
{
   p_bibCL = &b;
}
//---------------------------------------------------------------------------
void __fastcall TfrmCadLivro::btnConfirmarClick(TObject *Sender)
{
if (edtISBN->Text == "" || edtNome->Text=="" || edtQTDE->Text=="")
{
	MessageBoxA(NULL, "Favor preencher os campos ISBN, NOME e QTDE", "Cadastro de Livro", MB_OK);
}
else
{
AnsiString isbn, nome;
isbn=edtISBN->Text;
nome=edtNome->Text;
int qtde = StrToInt(edtQTDE->Text);

p_bibCL->cadastrarLivro(isbn.c_str(), nome.c_str(), qtde);
edtISBN->Text="";
edtNome->Text="";
edtQTDE->Text="";
//getBibPrincipal(p_bibCL);
//frmPrincipal->btnBuscarLivro->Enabled = true;
//frmPrincipal->Livros1->Enabled = true;
MessageBoxA(NULL, "Livro cadastrado com sucesso", "Cadastro de Livro", MB_OK);
}
}
//---------------------------------------------------------------------------
void __fastcall TfrmCadLivro::FormCreate(TObject *Sender)
{
//edtISBN->SetFocus();
}
//---------------------------------------------------------------------------
void __fastcall TfrmCadLivro::FormShow(TObject *Sender)
{
edtISBN->SetFocus();        
}
//---------------------------------------------------------------------------
