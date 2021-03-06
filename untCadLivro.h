//---------------------------------------------------------------------------

#ifndef untCadLivroH
#define untCadLivroH
//---------------------------------------------------------------------------
#include <Classes.hpp>
#include <Controls.hpp>
#include <StdCtrls.hpp>
#include <Forms.hpp>
#include <Buttons.hpp>
#include "Biblioteca.h"

Biblioteca *p_bibCL;
void getBibCadLivro(Biblioteca &b);
//---------------------------------------------------------------------------
class TfrmCadLivro : public TForm
{
__published:	// IDE-managed Components
        TLabel *Label1;
        TLabel *Label2;
        TBitBtn *btnConfirmar;
        TBitBtn *BitBtn2;
        TEdit *edtISBN;
        TEdit *edtNome;
        TLabel *Label3;
        TEdit *edtQTDE;
        void __fastcall btnConfirmarClick(TObject *Sender);
        void __fastcall FormCreate(TObject *Sender);
        void __fastcall FormShow(TObject *Sender);
private:	// User declarations
public:		// User declarations
        __fastcall TfrmCadLivro(TComponent* Owner);
};
//---------------------------------------------------------------------------
extern PACKAGE TfrmCadLivro *frmCadLivro;
//---------------------------------------------------------------------------
#endif
