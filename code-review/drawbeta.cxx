#include<iostream>
#include<TH1D.h>
#include<TFile.h>

using namespace std;

void drawbeta()
{
	gStyle->SetOptStat(0);
	gStyle->SetOptTitle(0);

	TFile *input = new TFile("deuteron.histo.root","read");

	TH2F *h2 = 0;

	input->GetObject("InvBetaP",h2);

//	h2->Rebin2D(1,4);

	const double xrange_low    = -3.0;
	const double xrange_high   =  3.0;
	const double yrange_low    =  0.9;
	const double yrange_high   =  2.0;


	//don't change the following code.==========================================================
	h2->GetYaxis()->SetRangeUser(yrange_low,yrange_high);
	h2->GetXaxis()->SetRangeUser(xrange_low,xrange_high);


	TF1 *pion                 = new TF1("pion","sqrt(x*x+0.13957061*0.13957061)/x",0.15,xrange_high);
	TF1 *antipion             = new TF1("antipion","sqrt(x*x+0.13957061*0.13957061)/fabs(x)",xrange_low,-0.15);

	TF1 *kaon                 = new TF1("kaon","sqrt(x*x+0.493677*0.493677)/x",0,xrange_high);
	TF1 *antikaon             = new TF1("antikaon","sqrt(x*x+0.493677*0.493677)/fabs(x)",xrange_low,0.0);

	TF1 *proton               = new TF1("proton","sqrt(x*x+0.938272081*0.938272081)/x",0,xrange_high);
	TF1 *antiproton           = new TF1("antiproton","sqrt(x*x+0.938272081*0.938272081)/fabs(x)",xrange_low,0.0);

	TF1 *deuteron             = new TF1("deuteron","sqrt(x*x+1.875612928*1.875612928)/x",0.0,xrange_high);
	TF1 *antideuteron         = new TF1("antideuteron","sqrt(x*x+1.875612928*1.875612928)/fabs(x)",xrange_low,0.0);

	TF1 *triton               = new TF1("triton","sqrt(x*x+2.808921112*2.808921112)/x",0,xrange_high);
	TF1 *antitriton           = new TF1("antitriton","sqrt(x*x+2.808921112*2.808921112)/fabs(x)",xrange_low,0.0);

	TF1 *he3                  = new TF1("he3","0.5*sqrt(4.0*x*x+2.808391586*2.808391586)/x",0,xrange_high);
	TF1 *antihe3              = new TF1("antihe3","0.5*sqrt(4.0*x*x+2.808391586*2.808391586)/fabs(x)",xrange_low,0.0);

	h2->GetYaxis()->SetTitle("1/#beta");
	h2->GetXaxis()->SetTitle("p/q (GeV/c)");
	h2->GetYaxis()->CenterTitle(true);
	h2->GetXaxis()->CenterTitle(true);
	h2->GetYaxis()->SetTitleSize(0.07);
	h2->GetYaxis()->SetTitleFont(42);
	h2->GetXaxis()->SetTitleSize(0.07);
	h2->GetXaxis()->SetTitleFont(42);
	h2->GetZaxis()->SetTitleSize(0.07);
	h2->GetZaxis()->SetTitleFont(42);
	h2->GetYaxis()->SetLabelSize(0.05);
	h2->GetXaxis()->SetLabelSize(0.05);
	h2->GetZaxis()->SetLabelSize(0.05);
	h2->GetYaxis()->SetTitleOffset(0.6);
	h2->GetXaxis()->SetTitleOffset(0.7);
	h2->GetYaxis()->SetDecimals();
	h2->GetXaxis()->SetDecimals();
	h2->GetZaxis()->SetDecimals();

	h2->Draw("colz");

	proton->SetLineWidth(1);
	antiproton->SetLineWidth(1);
	pion->SetLineWidth(1);
	antipion->SetLineWidth(1);
	kaon->SetLineWidth(1);
	antikaon->SetLineWidth(1);
	deuteron->SetLineWidth(1);
	antideuteron->SetLineWidth(1);
//	triton->SetLineWidth(1);
//	antitriton->SetLineWidth(1);
	he3->SetLineWidth(1);
	antihe3->SetLineWidth(1);

	proton->Draw("same");
	antiproton->Draw("same");
	pion->Draw("same");
	antipion->Draw("same");
	kaon->Draw("same");
	antikaon->Draw("same");
	deuteron->Draw("same");
	antideuteron->Draw("same");
//	triton->Draw("same");
//	antitriton->Draw("same");
	he3->Draw("same");
	antihe3->Draw("same");
	
	//Create the latex for each particels.
	TLatex *lat = new TLatex();
	lat->SetNDC();
	lat->SetTextFont(42);
	lat->SetTextSize(0.070);
	lat->SetTextColor(kBlack);

	lat->DrawLatex(0.56,0.25,"#pi^{+}");
	lat->DrawLatex(0.61,0.35,"K^{+}");
	lat->DrawLatex(0.66,0.44,"p");
	lat->DrawLatex(0.73,0.59,"d");
//	lat->DrawLatex(0.80,0.67,"t");
	lat->DrawLatex(0.69,0.49,"^{3}He");
	
	lat->DrawLatex(0.43,0.25,"#pi^{-}");
	lat->DrawLatex(0.38,0.35,"K^{-}");
	lat->DrawLatex(0.34,0.44,"#bar{p}");
	lat->DrawLatex(0.27,0.59,"#bar{d}");
//	lat->DrawLatex(0.21,0.67,"#bar{t}");
	lat->DrawLatex(0.23,0.42,"{}^{3}#bar{He}");

}
