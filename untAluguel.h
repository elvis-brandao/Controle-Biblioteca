//---------------------------------------------------------------------------

#ifndef untAluguelH
#define untAluguelH
//---------------------------------------------------------------------------
#include <Classes.hpp>
#include <Controls.hpp>
#include <StdCtrls.hpp>
#include <Forms.hpp>
#include <ExtCtrls.hpp>
#include <Buttons.hpp>
#include <ComCtrls.hpp>
#include "Biblioteca.h"

Biblioteca *p_bibADL;
void getBibAlDevLivro(Biblioteca &b);
//---------------------------------------------------------------------------
class TfrmAluguel : public TForm
{
__published:	// IDE-managed Components
        TRadioGroup *rdSelecione;
        TEdit *edtNome;
        TEdit *edtLivro;
        TLabel *Label1;
        TLabel *Label2;
        TGroupBox *gpDataAluguel;
        TDateTimePicker *dtAluguel;
        TGroupBox *gpDataDevolucao;
        TDateTimePicker *dtDevolucao;
        TBitBtn *btnConfirmar;
        TBitBtn *BitBtn2;
        TPanel *pnlMulta;
        TLabel *lblMulta;
        TEdit *edtMulta;
        void __fastcall FormCreate(TObject *Sender);
        void __fastcall rdSelecioneClick(TObject *Sender);
        void __fastcall btnConfirmarClick(TObject *Sender);
private:	// User declarations
public:		// User declarations
        __fastcall TfrmAluguel(TComponent* Owner);
};
//---------------------------------------------------------------------------
extern PACKAGE TfrmAluguel *frmAluguel;
//---------------------------------------------------------------------------
#endif
