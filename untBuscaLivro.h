//---------------------------------------------------------------------------

#ifndef untBuscaLivroH
#define untBuscaLivroH
//---------------------------------------------------------------------------
#include <Classes.hpp>
#include <Controls.hpp>
#include <StdCtrls.hpp>
#include <Forms.hpp>
#include <Buttons.hpp>
#include <ExtCtrls.hpp>
#include "Biblioteca.h"

Biblioteca *p_bibBL;
void getBibBusLivro(Biblioteca &b);
//---------------------------------------------------------------------------
class TfrmBuscaLivro : public TForm
{
__published:	// IDE-managed Components
        TRadioGroup *rdOpcao;
        TLabeledEdit *edtBusca;
        TBitBtn *btnBuscar;
        TGroupBox *gbResultado;
        TLabel *Label3;
        TLabel *Label4;
        TEdit *edtISBN;
        TEdit *edtNome;
        TBitBtn *BitBtn2;
        TBitBtn *btnAlugar;
        TEdit *edtVolumes;
        TLabel *Label1;
        TEdit *edtDevolucao;
        TLabel *Label2;
        void __fastcall rdOpcaoClick(TObject *Sender);
        void __fastcall btnBuscarClick(TObject *Sender);
        void __fastcall btnAlugarClick(TObject *Sender);
private:	// User declarations
public:		// User declarations
        __fastcall TfrmBuscaLivro(TComponent* Owner);
};
//---------------------------------------------------------------------------
extern PACKAGE TfrmBuscaLivro *frmBuscaLivro;
//---------------------------------------------------------------------------
#endif
