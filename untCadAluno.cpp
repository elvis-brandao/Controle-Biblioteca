//---------------------------------------------------------------------------

#include <vcl.h>
#pragma hdrstop

#include "untCadAluno.h"
#include "untPrincipal.h"
#include "Biblioteca.h"
//---------------------------------------------------------------------------
#pragma package(smart_init)
#pragma resource "*.dfm"
TfrmCadAluno *frmCadAluno;
//---------------------------------------------------------------------------
__fastcall TfrmCadAluno::TfrmCadAluno(TComponent* Owner)
        : TForm(Owner)
{
}

void getBibCadAluno(Biblioteca &b)
{
   p_bibCA = &b;
}
//---------------------------------------------------------------------------

void __fastcall TfrmCadAluno::btnConfirmarClick(TObject *Sender)
{
if ((edtMatAluno->Text == "") || (edtNomeAluno->Text== ""))
{
	MessageBoxA(NULL, "Favor preencher os campos MATR?CULA e NOME", "Cadastro de Aluno", MB_OK);
}
else
{
AnsiString mat, nome;
mat=edtMatAluno->Text;
//mat.operator +=('x');
nome=edtNomeAluno->Text;
//nome.operator +=('x');

p_bibCA->cadastrarAluno(mat.c_str(),nome.c_str());
edtMatAluno->Text="";
edtNomeAluno->Text="";
//p_bibCA->gravarCadAluno();
//getBibPrincipal(p_bibCA);
//frmPrincipal->btnBuscarAluno->Enabled = true;
//frmPrincipal->Alunos1->Enabled = true;
MessageBoxA(NULL, "Aluno cadastrado com sucesso", "Cadastro de Aluno", MB_OK);
}
}
//---------------------------------------------------------------------------

void __fastcall TfrmCadAluno::FormShow(TObject *Sender)
{
edtMatAluno->SetFocus();
}
//---------------------------------------------------------------------------


void __fastcall TfrmCadAluno::edtMatAlunoKeyUp(TObject *Sender, WORD &Key,
      TShiftState Shift)
{
if (Key < 8 || (Key > 8 && Key < 13) || (Key > 13 && Key < 48) || Key > 57)
{
        frmCadAluno->edtMatAluno->Clear();
        MessageBoxA(NULL, "Favor digitar somente n?meros", "CadastrarAlunos", MB_OK);
}
}
//---------------------------------------------------------------------------

