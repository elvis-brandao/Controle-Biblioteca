//---------------------------------------------------------------------------

#include <vcl.h>
#pragma hdrstop

#include "untConfiguracoes.h"
//---------------------------------------------------------------------------
#pragma package(smart_init)
#pragma resource "*.dfm"
TfrmConfiguracoes *frmConfiguracoes;
//---------------------------------------------------------------------------
__fastcall TfrmConfiguracoes::TfrmConfiguracoes(TComponent* Owner)
        : TForm(Owner)
{
}

void getBibConfig(Biblioteca &b)
{
   p_bibConfg = &b;
}
//---------------------------------------------------------------------------
void __fastcall TfrmConfiguracoes::FormCreate(TObject *Sender)
{
edtAluguel->Text = IntToStr(p_bibConfg->getMaxDias());
edtMulta->Text = FloatToStr(p_bibConfg->getMulta()) + " R$/dia";
}
//---------------------------------------------------------------------------
void __fastcall TfrmConfiguracoes::btnAlterarClick(TObject *Sender)
{
edtAluguel->Text = "";
edtMulta->Text = "";
edtAluguel->Enabled = true;
edtMulta->Enabled = true;
btnSalvar->Enabled = true;
btnAlterar->Enabled = false;
edtAluguel->SetFocus();        
}
//---------------------------------------------------------------------------
void __fastcall TfrmConfiguracoes::btnSalvarClick(TObject *Sender)
{
AnsiString a = edtMulta->Text + " R$/dia";
p_bibConfg->setMaxDias(StrToInt(edtAluguel->Text));
p_bibConfg->setMulta(StrToFloat(edtMulta->Text));
edtAluguel->Enabled = false;
edtMulta->Enabled = false;
edtMulta->Text = a;
btnSalvar->Enabled = false;
btnAlterar->Enabled = true;
MessageBoxA(NULL, "Configurações salvas !", "Configurações", MB_OK);
}
//---------------------------------------------------------------------------

void __fastcall TfrmConfiguracoes::edtAluguelKeyUp(TObject *Sender,
      WORD &Key, TShiftState Shift)
{
if (Key < 8 || (Key > 8 && Key < 13) || (Key > 13 && Key < 48) || Key > 57)
{
        frmConfiguracoes->edtAluguel->Clear();
        MessageBoxA(NULL, "Favor digitar somente números", "Configurações", MB_OK);
}
}
//---------------------------------------------------------------------------


void __fastcall TfrmConfiguracoes::edtMultaKeyUp(TObject *Sender,
      WORD &Key, TShiftState Shift)
{
if (Key < 8 || (Key > 8 && Key < 13) || (Key > 13 && Key < 48) || (Key > 57 && Key < 188) || (Key > 188))
{
        frmConfiguracoes->edtMulta->Clear();
        MessageBoxA(NULL, "Favor digitar somente números", "Configurações", MB_OK);
}
}
//---------------------------------------------------------------------------

