//---------------------------------------------------------------------------

#ifndef untCadAlunoH
#define untCadAlunoH
//---------------------------------------------------------------------------
#include <Classes.hpp>
#include <Controls.hpp>
#include <StdCtrls.hpp>
#include <Forms.hpp>
#include <Buttons.hpp>
#include "Biblioteca.h"
#include <Mask.hpp>

Biblioteca *p_bibCA;
void getBibCadAluno(Biblioteca &b);
//---------------------------------------------------------------------------
class TfrmCadAluno : public TForm
{
__published:	// IDE-managed Components
        TBitBtn *btnConfirmar;
        TBitBtn *BitBtn2;
        TLabel *Label1;
        TLabel *Label2;
        TEdit *edtNomeAluno;
        TEdit *edtMatAluno;
        void __fastcall btnConfirmarClick(TObject *Sender);
        void __fastcall FormShow(TObject *Sender);
        void __fastcall edtMatAlunoKeyUp(TObject *Sender, WORD &Key,
          TShiftState Shift);
private:	// User declarations
public:		// User declarations
        __fastcall TfrmCadAluno(TComponent* Owner);
};
//---------------------------------------------------------------------------
extern PACKAGE TfrmCadAluno *frmCadAluno;
//---------------------------------------------------------------------------
#endif
