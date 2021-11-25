//---------------------------------------------------------------------------

#ifndef untPrincipalH
#define untPrincipalH
//---------------------------------------------------------------------------
#include "Biblioteca.h"
#include <Classes.hpp>
#include <Controls.hpp>
#include <StdCtrls.hpp>
#include <Forms.hpp>
#include <Buttons.hpp>
#include <Menus.hpp>
#include <ExtCtrls.hpp>
#include <jpeg.hpp>
#include <CheckLst.hpp>
#include <Mask.hpp>

//---------------------------------------------------------------------------
class TfrmPrincipal : public TForm
{
__published:	// IDE-managed Components
        TBitBtn *btnCadAluno;
        TMainMenu *MainMenu1;
        TMenuItem *menuBtnCadastro;
        TMenuItem *menuBtnBuscas;
        TMenuItem *menuBtnAlugDevol;
        TMenuItem *menuBtnSair;
        TMenuItem *menuBtnSobre;
        TMenuItem *menuBtnCadAluno;
        TMenuItem *menuBtnCadLivro;
        TMenuItem *menuBtnBuscaAluno;
        TMenuItem *menuBtnBuscaLivro;
        TLabel *Label1;
        TImage *Image1;
        TLabel *Label2;
        TBitBtn *btnBuscaAluno;
        TLabel *Label3;
        TBitBtn *btnCadLivro;
        TLabel *Label4;
        TBitBtn *btnBuscaLivro;
        TLabel *Label5;
        TBitBtn *btnAlugar;
        TLabel *Label6;
        TBitBtn *btnConfig;
        TLabel *Label7;
        TLabel *Label8;
        void __fastcall btnCadAlunoClick(TObject *Sender);
        void __fastcall btnBuscaAlunoClick(TObject *Sender);
        void __fastcall FormCreate(TObject *Sender);
        void __fastcall FormClose(TObject *Sender, TCloseAction &Action);
        void __fastcall FormShow(TObject *Sender);
        void __fastcall btnCadLivroClick(TObject *Sender);
        void __fastcall btnBuscaLivroClick(TObject *Sender);
        void __fastcall btnAlugarClick(TObject *Sender);
        void __fastcall btnConfigClick(TObject *Sender);
        void __fastcall menuBtnCadAlunoClick(TObject *Sender);
        void __fastcall menuBtnBuscaAlunoClick(TObject *Sender);
        void __fastcall menuBtnCadLivroClick(TObject *Sender);
        void __fastcall menuBtnBuscaLivroClick(TObject *Sender);
        void __fastcall menuBtnAlugDevolClick(TObject *Sender);
        void __fastcall menuBtnSairClick(TObject *Sender);
        void __fastcall menuBtnSobreClick(TObject *Sender);
private:	// User declarations
public:		// User declarations
        __fastcall TfrmPrincipal(TComponent* Owner);
};
//---------------------------------------------------------------------------
extern PACKAGE TfrmPrincipal *frmPrincipal;
//---------------------------------------------------------------------------
#endif
