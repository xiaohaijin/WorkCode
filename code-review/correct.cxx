#include "drawdedx.cxx"
#include "drawbeta.cxx"

using namespace std;
using namespace RooFit;

void correct()
{
	gStyle->SetOptTitle(0);
	gStyle->SetPadTickX(1);
	gStyle->SetPadTickY(1);

	TFile *input11 = new TFile("../output/la_total.root","read");
	TFile *input12 = new TFile("../output/ala_total.root","read");

	TTree *tree11  = (TTree*)input11->Get("mytree");
	TTree *tree12  = (TTree*)input12->Get("mytree");

	TCanvas *c = new TCanvas("signal","signal",1600,950);
	c->Divide(2,2);
	

	RooRealVar v0mass_corr("v0mass_corr","v0mass_corr",2.975,3.007);
	const int Nbin = 16;
	v0mass_corr.setBins(Nbin);

//==============================================================================	
//two-body hypertrion
//==============================================================================	
	RooDataSet v0mass_corrset11("v0mass_corr11","v0mass_corr11",RooArgSet(v0mass_corr),Import(*tree11));

	RooWorkspace w11("w11");
	w11.import(v0mass_corr);

	w11.factory("a0[0,-1000,1000]");
	w11.factory("a1[0,-1000,1000]");
	w11.factory("nSignal[10,0,1000]");
	w11.factory("nBackg[10,0,1000]");
	w11.factory("Gaussian:g(v0mass_corr,mean[2.991,2.980,3.00],sigma[1.0,0,5])");
	w11.factory("Polynomial:bkg(v0mass_corr,{a0,a1})");
	w11.factory("SUM::pdf(nSignal*g,nBackg*bkg)");
	
	RooPlot *pl11 = v0mass_corr.frame(Nbin);
	v0mass_corrset11.plotOn(pl11,DataError(RooAbsData::SumW2),MarkerColor(kViolet+2),LineColor(kViolet+2),MarkerSize(1.5),LineWidth(1));
	RooFitResult *r11 = w11.pdf("pdf")->fitTo(v0mass_corrset11,Save(true),Minimizer("OldMinuit","migrad"));
	w11.pdf("pdf")->plotOn(pl11,LineColor(kRed),LineWidth(1));

	double chi11 = pl11->chiSquare("pdf_Norm[v0mass_corr]","h_v0mass_corr11",6);

	RooRealVar *Roopara11_mean     = (RooRealVar*)r11->floatParsFinal().find("mean");
	RooRealVar *Roopara11_sigma    = (RooRealVar*)r11->floatParsFinal().find("sigma");
	double mean11                  = Roopara11_mean->getValV();
	double errs11_mean             = Roopara11_mean->getError();
	double sigma11                 = Roopara11_sigma->getValV();
	double errs11_sigma            = Roopara11_sigma->getError();

//	TString string_para11_mean   = TString::Format("#splitline{Mass:}{%.2f #pm %.2f MeV/c^{2}}",mean11*1000,errs11_mean*1000);
	TString string_para11_sigma  = TString::Format("#splitline{Sigma:}{%.2f #pm %.2f MeV/c^{2}}",sigma11*1000,errs11_sigma*1000);

	TString string_para11_mean   = TString::Format("#splitline{Mass:}{2,990.80 #pm 0.12 MeV/c^{2}}");
	TString string_chi11 = TString::Format("#chi^{2}/NDF = %0.2f",chi11);

	pl11->GetXaxis()->SetRangeUser(2.975,3.007);
	pl11->GetXaxis()->SetDecimals();

	TObject *obj0_11 = pl11->findObject(pl11->nameOf(0));
	TObject *obj1_11 = pl11->findObject(pl11->nameOf(1));

	TLegend *lg11 = new TLegend(0.65,0.55,0.90,0.75);
	lg11->AddEntry(obj0_11,"Signal candidates");
	lg11->AddEntry(obj1_11,"Unbinned ML fit");
	lg11->SetLineWidth(0);
	lg11->SetTextSize(0.055);
	lg11->SetTextFont(42);

	pl11->GetXaxis()->SetTitle("{}^{3}_{#Lambda}H invariant mass (GeV/c^{2})");
	pl11->GetXaxis()->SetTitleSize(0.07);
	pl11->GetXaxis()->SetTitleFont(42);
	pl11->GetXaxis()->SetDecimals();
	pl11->GetXaxis()->CenterTitle(true);
	pl11->GetXaxis()->SetLabelSize(0.05);

	pl11->GetYaxis()->SetTitle("Counts / (2MeV/c^{2})");
	pl11->GetYaxis()->SetTitleSize(0.07);
	pl11->GetYaxis()->SetTitleFont(42);
	pl11->GetYaxis()->SetDecimals();
	pl11->GetYaxis()->CenterTitle(true);
	pl11->GetYaxis()->SetTitleOffset(0.8);
	pl11->GetYaxis()->SetLabelSize(0.05);
	pl11->GetXaxis()->SetTitleOffset(0.8);

	TPad *pad11 = (TPad*)c->cd(3);
	pad11->SetLeftMargin(0.12);
	pad11->SetRightMargin(0.01);
	pad11->SetTopMargin(0.04);
	pad11->SetBottomMargin(0.15);

	pl11->Draw();
	lg11->Draw("same");
//==============================================================================
//three-body hypertriton
//==============================================================================	
	RooDataSet v0mass_corrset12("v0mass_corr12","v0mass_corr12",RooArgSet(v0mass_corr),Import(*tree12));

	RooWorkspace w12("w12");
	w12.import(v0mass_corr);

	w12.factory("a0[0,-1000,1000]");
	w12.factory("a1[0,-1000,1000]");
	w12.factory("nSignal[10,0,1000]");
	w12.factory("nBackg[10,0,1000]");
	w12.factory("Gaussian:g(v0mass_corr,mean[2.991,2.980,3.00],sigma[1.0,0,5])");
	w12.factory("Polynomial:bkg(v0mass_corr,{a0,a1})");
	w12.factory("SUM::pdf(nSignal*g,nBackg*bkg)");
	
	RooPlot *pl12 = v0mass_corr.frame(Nbin);
	v0mass_corrset12.plotOn(pl12,DataError(RooAbsData::SumW2),MarkerColor(kViolet+2),LineColor(kViolet+2),MarkerSize(1.5),LineWidth(1));
	RooFitResult *r12 = w12.pdf("pdf")->fitTo(v0mass_corrset12,Save(true),Minimizer("OldMinuit","migrad"));
	w12.pdf("pdf")->plotOn(pl12,LineColor(kRed),LineWidth(1));

	double chi12 = pl12->chiSquare("pdf_Norm[v0mass_corr]","h_v0mass_corr12",6);

	RooRealVar *Roopara12_mean    = (RooRealVar*)r12->floatParsFinal().find("mean");
	RooRealVar *Roopara12_sigma   = (RooRealVar*)r12->floatParsFinal().find("sigma");
	double mean12                 = Roopara12_mean->getValV();
	double errs12_mean            = Roopara12_mean->getError();
	double sigma12                = Roopara12_sigma->getValV();
	double errs12_sigma           = Roopara12_sigma->getError();

//	TString string_para12_mean = TString::Format("#splitline{Mass:}{(%.2f #pm %.2f) MeV/c^{2}}",mean12*1000,errs12_mean*1000);
	TString string_para12_sigma = TString::Format("#splitline{Sigma:}{(%.2f #pm %.2f) MeV/c^{2}}",sigma12*1000,errs12_sigma*1000);

	TString string_para12_mean = TString::Format("#splitline{Mass:}{2,990.62 #pm 0.27 MeV/c^{2}}");
	TString string_chi12 = TString::Format("#chi^{2}/NDF = %0.2f",chi12);

	pl12->GetXaxis()->SetRangeUser(2.975,3.007);
	pl12->GetXaxis()->SetDecimals();

	TObject *obj0_12 = pl12->findObject(pl12->nameOf(0));
	TObject *obj1_12 = pl12->findObject(pl12->nameOf(1));

	TLegend *lg12 = new TLegend(0.65,0.55,0.90,0.75);
	lg12->AddEntry(obj0_12,"Signal candidates");
	lg12->AddEntry(obj1_12,"Unbinned ML fit");
	lg12->SetLineWidth(0);
	lg12->SetTextSize(0.055);
	lg12->SetTextFont(42);

	pl12->GetXaxis()->SetTitle("{}^{3}_{#bar{#Lambda}}#bar{H} invariant mass (GeV/c^{2})");
	pl12->GetXaxis()->SetTitleSize(0.07);
	pl12->GetXaxis()->SetTitleFont(42);
	pl12->GetXaxis()->SetDecimals();
	pl12->GetXaxis()->SetDecimals();
	pl12->GetXaxis()->CenterTitle(true);
	pl12->GetXaxis()->SetLabelSize(0.05);

	pl12->GetYaxis()->SetTitle("Counts / (2MeV/c^{2})");
	pl12->GetYaxis()->SetTitleSize(0.07);
	pl12->GetYaxis()->SetTitleFont(42);
	pl12->GetYaxis()->SetDecimals();
	pl12->GetYaxis()->SetDecimals();
	pl12->GetYaxis()->CenterTitle(true);
	pl12->GetYaxis()->SetTitleOffset(0.8);
	pl12->GetYaxis()->SetLabelSize(0.05);
	pl12->GetXaxis()->SetTitleOffset(0.8);

	TPad *pad12 = (TPad*)c->cd(4);
	pad12->SetLeftMargin(0.12);
	pad12->SetRightMargin(0.01);
	pad12->SetTopMargin(0.04);
	pad12->SetBottomMargin(0.15);

	pl12->Draw();
	lg12->Draw("same");
//==============================================
	TLatex *lat_fit = new TLatex();
	lat_fit->SetNDC();
	if(0)
	{
		lat_fit->SetTextFont(42);
		lat_fit->SetTextSize(0.055);
		lat_fit->SetTextColor(kRed);
		c->cd(3);
		lat_fit->DrawLatex(0.165,0.85,string_para11_mean.Data());
//		lat_fit->DrawLatex(0.165,0.70,string_para11_sigma.Data());
//		lat_fit->DrawLatex(0.165,0.58,string_chi11.Data());
		c->cd(4);
		lat_fit->DrawLatex(0.165,0.85,string_para12_mean.Data());
//		lat_fit->DrawLatex(0.165,0.70,string_para12_sigma.Data());
//		lat_fit->DrawLatex(0.165,0.58,string_chi12.Data());

	}

	pl11->Print();
	pl12->Print();

	cout<<"chi^2 11:"<<chi11<<endl;
	cout<<"chi^2 12:"<<chi12<<endl;
//==============================================================================
	TPad *pad21 = (TPad*)c->cd(1);
	pad21->SetLeftMargin(0.12);
	pad21->SetRightMargin(0.1015);
	pad21->SetTopMargin(0.06);
	pad21->SetBottomMargin(0.15);
	pad21->SetLogz();

	drawdedx();

	TPad *pad22 = (TPad*)c->cd(2);
	pad22->SetLeftMargin(0.12);
	pad22->SetRightMargin(0.1015);
	pad22->SetTopMargin(0.06);
	pad22->SetBottomMargin(0.15);
	pad22->SetLogz();

	drawbeta();
//===============================================================================


	TLatex *lat_label = new TLatex();
	lat_label->SetNDC();
	if(1)
	{
		lat_label->SetTextFont(42);
		lat_label->SetTextSize(0.08);
		lat_label->SetTextColor(kBlack);

		c->cd(1);
		lat_label->DrawLatex(0.02,0.94,"a");
		c->cd(2);
		lat_label->DrawLatex(0.02,0.94,"b");
		c->cd(3);
		lat_label->DrawLatex(0.02,0.94,"c");
		c->cd(4);
		lat_label->DrawLatex(0.02,0.94,"d");
	}

	return;
}
