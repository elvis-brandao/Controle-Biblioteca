//---------------------------------------------------------------------------

#include <vcl.h>
#pragma hdrstop
//---------------------------------------------------------------------------
USEFORM("untPrincipal.cpp", frmPrincipal);
USEFORM("untCadAluno.cpp", frmCadAluno);
USEFORM("untBuscarAluno.cpp", frmBuscarAluno);
USEFORM("untCadLivro.cpp", frmCadLivro);
USEFORM("untBuscaLivro.cpp", frmBuscaLivro);
USEFORM("untAluguel.cpp", frmAluguel);
USEFORM("untConfiguracoes.cpp", frmConfiguracoes);
USEFORM("untSobre.cpp", frmSobre);
//---------------------------------------------------------------------------
WINAPI WinMain(HINSTANCE, HINSTANCE, LPSTR, int)
{
        try
        {
                 Application->Initialize();
                 Application->Title = "Gerenciamento Biblioteca";
                 Application->CreateForm(__classid(TfrmPrincipal), &frmPrincipal);
                 Application->Run();
        }
        catch (Exception &exception)
        {
                 Application->ShowException(&exception);
        }
        catch (...)
        {
                 try
                 {
                         throw Exception("");
                 }
                 catch (Exception &exception)
                 {
                         Application->ShowException(&exception);
                 }
        }
        return 0;
}
//---------------------------------------------------------------------------
