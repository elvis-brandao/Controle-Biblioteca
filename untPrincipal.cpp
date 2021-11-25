//---------------------------------------------------------------------------

#include <vcl.h>
#pragma hdrstop

#include "Biblioteca.h"
#include "untPrincipal.h"
#include "untCadAluno.h"
#include "untBuscarAluno.h"
#include "untCadLivro.h"
#include "untBuscaLivro.h"
#include "untAluguel.h"
#include "untConfiguracoes.h"
#include "untSobre.h"
//---------------------------------------------------------------------------
#pragma package(smart_init)
#pragma resource "*.dfm"
TfrmPrincipal *frmPrincipal;
Biblioteca bib;
//---------------------------------------------------------------------------
__fastcall TfrmPrincipal::TfrmPrincipal(TComponent* Owner)
        : TForm(Owner)
{
}
//---------------------------------------------------------------------------

void __fastcall TfrmPrincipal::btnCadAlunoClick(TObject *Sender)
{
getBibCadAluno(bib);
frmCadAluno = new TfrmCadAluno(Application);
frmCadAluno->ShowModal();
delete frmCadAluno;
}
//---------------------------------------------------------------------------


void __fastcall TfrmPrincipal::btnBuscaAlunoClick(TObject *Sender)
{
getBibBusAluno(bib);
getBibAlDevLivro(bib);
frmBuscarAluno = new TfrmBuscarAluno(Application);
frmBuscarAluno->ShowModal();
delete frmBuscarAluno;
}
//---------------------------------------------------------------------------

void __fastcall TfrmPrincipal::FormCreate(TObject *Sender)
{
bib.lerCadAluno();
bib.lerCadLivro();
bib.lerConfgs();
}
//---------------------------------------------------------------------------

void __fastcall TfrmPrincipal::FormClose(TObject *Sender,
      TCloseAction &Action)
{
bib.gravarCadAluno();
bib.gravarCadLivro();
bib.gravarConfgs();
}
//---------------------------------------------------------------------------

void __fastcall TfrmPrincipal::FormShow(TObject *Sender)
{
//bib.lerCadAluno();
}
//---------------------------------------------------------------------------

void __fastcall TfrmPrincipal::btnCadLivroClick(TObject *Sender)
{
getBibCadLivro(bib);
frmCadLivro = new TfrmCadLivro(Application);
frmCadLivro->ShowModal();
delete frmCadLivro;
}
//---------------------------------------------------------------------------

void __fastcall TfrmPrincipal::btnBuscaLivroClick(TObject *Sender)
{
getBibBusLivro(bib);
getBibAlDevLivro(bib);
frmBuscaLivro = new TfrmBuscaLivro(Application);
frmBuscaLivro->ShowModal();
delete frmBuscaLivro;
}
//---------------------------------------------------------------------------

void __fastcall TfrmPrincipal::btnAlugarClick(TObject *Sender)
{
getBibAlDevLivro(bib);
frmAluguel = new TfrmAluguel(Application);
frmAluguel->ShowModal();
delete frmAluguel;
}
//---------------------------------------------------------------------------

void __fastcall TfrmPrincipal::btnConfigClick(TObject *Sender)
{
getBibConfig(bib);
frmConfiguracoes = new TfrmConfiguracoes(Application);
frmConfiguracoes->ShowModal();
delete frmConfiguracoes;
}
//---------------------------------------------------------------------------

void __fastcall TfrmPrincipal::menuBtnCadAlunoClick(TObject *Sender)
{
getBibCadAluno(bib);
frmCadAluno = new TfrmCadAluno(Application);
frmCadAluno->ShowModal();
delete frmCadAluno;
}
//---------------------------------------------------------------------------

void __fastcall TfrmPrincipal::menuBtnBuscaAlunoClick(TObject *Sender)
{
getBibBusAluno(bib);
getBibAlDevLivro(bib);
frmBuscarAluno = new TfrmBuscarAluno(Application);
frmBuscarAluno->ShowModal();
delete frmBuscarAluno;
}
//---------------------------------------------------------------------------

void __fastcall TfrmPrincipal::menuBtnCadLivroClick(TObject *Sender)
{
getBibCadLivro(bib);
frmCadLivro = new TfrmCadLivro(Application);
frmCadLivro->ShowModal();
delete frmCadLivro;
}
//---------------------------------------------------------------------------

void __fastcall TfrmPrincipal::menuBtnBuscaLivroClick(TObject *Sender)
{
getBibBusLivro(bib);
getBibAlDevLivro(bib);
frmBuscaLivro = new TfrmBuscaLivro(Application);
frmBuscaLivro->ShowModal();
delete frmBuscaLivro;
}
//---------------------------------------------------------------------------

void __fastcall TfrmPrincipal::menuBtnAlugDevolClick(TObject *Sender)
{
getBibAlDevLivro(bib);
frmAluguel = new TfrmAluguel(Application);
frmAluguel->ShowModal();
delete frmAluguel;        
}
//---------------------------------------------------------------------------

void __fastcall TfrmPrincipal::menuBtnSairClick(TObject *Sender)
{
frmPrincipal->Close();
}
//---------------------------------------------------------------------------

void __fastcall TfrmPrincipal::menuBtnSobreClick(TObject *Sender)
{
frmSobre = new TfrmSobre(Application);
frmSobre->ShowModal();
delete frmSobre;
}
//---------------------------------------------------------------------------





