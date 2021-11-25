//---------------------------------------------------------------------------

#ifndef untConfiguracoesH
#define untConfiguracoesH
//---------------------------------------------------------------------------
#include <Classes.hpp>
#include <Controls.hpp>
#include <StdCtrls.hpp>
#include <Forms.hpp>
#include <ExtCtrls.hpp>
#include <Buttons.hpp>
#include "Biblioteca.h"

Biblioteca *p_bibConfg;

void getBibConfig(Biblioteca &b);
//---------------------------------------------------------------------------
class TfrmConfiguracoes : public TForm
{
__published:	// IDE-managed Components
        TLabeledEdit *edtAluguel;
        TLabeledEdit *edtMulta;
        TBitBtn *btnAlterar;
        TBitBtn *btnSalvar;
        void __fastcall FormCreate(TObject *Sender);
        void __fastcall btnAlterarClick(TObject *Sender);
        void __fastcall btnSalvarClick(TObject *Sender);
        void __fastcall edtAluguelKeyUp(TObject *Sender, WORD &Key,
          TShiftState Shift);
        void __fastcall edtMultaKeyUp(TObject *Sender, WORD &Key,
          TShiftState Shift);
private:	// User declarations
public:		// User declarations
        __fastcall TfrmConfiguracoes(TComponent* Owner);
};
//---------------------------------------------------------------------------
extern PACKAGE TfrmConfiguracoes *frmConfiguracoes;
//---------------------------------------------------------------------------
#endif
