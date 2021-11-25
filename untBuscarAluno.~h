//---------------------------------------------------------------------------

#ifndef untBuscarAlunoH
#define untBuscarAlunoH
//---------------------------------------------------------------------------
#include <Classes.hpp>
#include <Controls.hpp>
#include <StdCtrls.hpp>
#include <Forms.hpp>
#include <Buttons.hpp>
#include <ExtCtrls.hpp>
#include <CheckLst.hpp>
#include <ComCtrls.hpp>
#include "Biblioteca.h"


Biblioteca *p_bibBA;
void getBibBusAluno(Biblioteca &b);
//---------------------------------------------------------------------------
class TfrmBuscarAluno : public TForm
{
__published:	// IDE-managed Components
        TRadioGroup *rdSelecione;
        TLabeledEdit *edtBusca;
        TBitBtn *btnBuscar;
        TGroupBox *gbResultado;
        TGroupBox *gbLivros;
        TBitBtn *BitBtn2;
        TBitBtn *btnAlugar;
        TRichEdit *listLivros;
        TRichEdit *listDatas;
        TLabel *Label1;
        TLabel *Label2;
        TLabel *Label3;
        TLabel *Label4;
        TEdit *edtMat;
        TEdit *edtNome;
        void __fastcall rdSelecioneClick(TObject *Sender);
        void __fastcall btnBuscarClick(TObject *Sender);
        void __fastcall btnAlugarClick(TObject *Sender);
private:	// User declarations
public:		// User declarations
        __fastcall TfrmBuscarAluno(TComponent* Owner);
};
//---------------------------------------------------------------------------
extern PACKAGE TfrmBuscarAluno *frmBuscarAluno;
//---------------------------------------------------------------------------
#endif
