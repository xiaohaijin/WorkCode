#include "TH1.h"
#include "TMath.h"
#include "TF1.h"
#include "TLegend.h"
#include "TCanvas.h"
#include <iostream>     // std::cout
#include <fstream>      // std::ifstream

TLatex* drawLatex(Double_t x, Double_t y, char* text, Int_t textFont, Double_t textSize, Int_t colorIndex){
				TLatex *latex = new TLatex(x,y,text);
				latex->SetNDC();
				latex->SetTextFont(textFont);
				latex->SetTextSize(textSize);
				latex->SetTextColor(colorIndex);
				latex->Draw("same");
				return latex;
}

void GetExpext(char *filename,TH1F *h1){
//get dedx for particles
	std::ifstream ifs (filename, std::ifstream::in);
	float p = -999;
	double weight = -999;
  while (ifs.good()) {
		ifs>>p;
		ifs>>weight;
		weight = weight * 1.e-6;
		h1->Fill(p,weight);
  }

  ifs.close();
}
void GetAntiExpext(char *filename,TH1F *h1){
//get dedx for anti particles
	std::ifstream ifs (filename, std::ifstream::in);
	float p = -999;
	double weight = -999;
  while (ifs.good()) {
		ifs>>p;
		ifs>>weight;
		p = 0-p;
		weight = weight* 1.e-6;
		h1->Fill(p,weight);
  }

  ifs.close();
}

void GetAntiExpext2(char *filename,TH1F *h1){
//get dedx for anti particles
	std::ifstream ifs (filename, std::ifstream::in);
	float p = -999;
	double weight = -999;
  while (ifs.good()) {
		ifs>>p;
		ifs>>weight;
		p = (0-p)/2.;
		weight = weight* 1.e-6;
		h1->Fill(p,weight);
  }

  ifs.close();
}
void GetExpext2(char *filename,TH1F *h1){
//get dedx for particles
	std::ifstream ifs (filename, std::ifstream::in);
	float p = -999;
	double weight = -999;
  while (ifs.good()) {
		ifs>>p;
		ifs>>weight;
		p = p/2.;
		weight = weight * 1.e-6;
		h1->Fill(p,weight);
  }

  ifs.close();
}

void SetErr(TH1F *h1){
//set all error to 0
				int nbins = h1->GetNbinsX(); 
				for(int i=0; i<(nbins+1); i++){
					h1->SetBinError(i,0);
				}
}

void SetTH1Style(TH1F *h1,int Marker,int colorIndex, float size){
//set TH1 style 
//marker style, color and size
		h1->SetMarkerStyle(Marker);
		h1->SetMarkerColor(colorIndex);;
		h1->SetMarkerSize(size);
}


void dEdx(){

	gStyle->SetOptStat(0000000);
	TCanvas *c1 = new TCanvas("c1");
	TFile *f1 = new TFile("alpha.histo.root","read"); 
	TH2F *dEdxP = (TH2F*)f1->Get("dEdxP");
	c1->cd();
	c1->SetLogz(1);
	dEdxP->GetXaxis()->SetRangeUser(-4,4);
	dEdxP->GetXaxis()->SetTitleOffset(1.0);
	dEdxP->GetYaxis()->SetTitleOffset(.9);
	dEdxP->SetXTitle("charge*p (GeV/c)");
	dEdxP->SetYTitle("dE/dx");
	dEdxP->SetTitle("dE/dx v.s. charge*p");
	dEdxP->Draw("colz");

	float marksize = 0.02;

	char buff[512];
	TH1F *Proton = new TH1F("Proton","dedx",12001,-0.0005,12.0005);
	sprintf(buff,"/Users/qian/work/analysis/antimatter/dedx/dedx4particle/dedx_mean_proton.dat");
	GetExpext(buff,Proton);
	SetErr(Proton);
	SetTH1Style(Proton,21,1,marksize);
	Proton->Draw("p same");


	TH1F *AntiProton = new TH1F("AntiProton","dedx",12001,-12.0005,.0005);
	sprintf(buff,"/Users/qian/work/analysis/antimatter/dedx/dedx4particle/dedx_mean_proton.dat");
	GetAntiExpext(buff,AntiProton);
	SetErr(AntiProton);
	SetTH1Style(AntiProton,21,1,marksize);
	AntiProton->Draw("p same");

	TH1F *Pion = new TH1F("Pion","dedx",12001,-0.0005,12.0005);
	sprintf(buff,"/Users/qian/work/analysis/antimatter/dedx/dedx4particle/dedx_mean_pi.dat");
	GetExpext(buff,Pion);
	SetErr(Pion);
	SetTH1Style(Pion,21,2,marksize);
	Pion->Draw("P same");

	TH1F *AntiPion = new TH1F("AntiPion","dedx",12001,-12.0005,.0005);
	sprintf(buff,"/Users/qian/work/analysis/antimatter/dedx/dedx4particle/dedx_mean_pi.dat");
	GetAntiExpext(buff,AntiPion);
	SetErr(AntiPion);
	SetTH1Style(AntiPion,21,2,marksize);
	AntiPion->Draw("P same");


	TH1F *Kaon = new TH1F("Kaon","dedx",12001,-0.0005,12.0005);
	sprintf(buff,"/Users/qian/work/analysis/antimatter/dedx/dedx4particle/dedx_mean_kaon.dat");
	GetExpext(buff,Kaon);
	SetErr(Kaon);
	SetTH1Style(Kaon,21,4,marksize);
	Kaon->Draw("P same");

	TH1F *AntiKaon = new TH1F("AntiKaon","dedx",12001,-12.0005,.0005);
	sprintf(buff,"/Users/qian/work/analysis/antimatter/dedx/dedx4particle/dedx_mean_kaon.dat");
	GetAntiExpext(buff,AntiKaon);
	SetErr(AntiKaon);
	SetTH1Style(AntiKaon,21,4,marksize);
	AntiKaon->Draw("P same");

	TH1F *deutron = new TH1F("deutron","dedx",12001,-0.0005,12.0005);
	sprintf(buff,"/Users/qian/work/analysis/antimatter/dedx/dedx4particle/dedx_mean_deuteron.dat");
	GetExpext(buff,deutron);
	SetErr(deutron);
	SetTH1Style(deutron,21,6,marksize);
	deutron->Draw("P same");

	TH1F *Antideutron = new TH1F("Antideutron","dedx",12001,-12.0005,.0005);
	sprintf(buff,"/Users/qian/work/analysis/antimatter/dedx/dedx4particle/dedx_mean_deuteron.dat");
	GetAntiExpext(buff,Antideutron);
	SetErr(Antideutron);
	SetTH1Style(Antideutron,21,6,marksize);
	Antideutron->Draw("P same");

	TH1F *triton = new TH1F("triton","dedx",12001,-0.0005,12.0005);
	sprintf(buff,"/Users/qian/work/analysis/antimatter/dedx/dedx4particle/dedx_mean_triton.dat");
	GetExpext(buff,triton);
	SetErr(triton);
	SetTH1Style(triton,21,kRed-2,marksize);
	triton->Draw("P same");

	TH1F *Antitriton = new TH1F("Antitriton","dedx",12001,-12.0005,.0005);
	sprintf(buff,"/Users/qian/work/analysis/antimatter/dedx/dedx4particle/dedx_mean_triton.dat");
	GetAntiExpext(buff,Antitriton);
	SetErr(Antitriton);
	SetTH1Style(Antitriton,21,kRed-2,marksize);
	Antitriton->Draw("P same");

	TH1F *He3 = new TH1F("He3","dedx",12001,-0.0005,6.0005);
	sprintf(buff,"/Users/qian/work/analysis/antimatter/dedx/dedx4particle/dedx_mean_helium3.dat");
	GetExpext2(buff,He3);
	SetErr(He3);
	SetTH1Style(He3,21,46,marksize);
	He3->Draw("P same");

	TH1F *AntiHe3 = new TH1F("AntiHe3","dedx",12001,-6.0005,.0005);
	sprintf(buff,"/Users/qian/work/analysis/antimatter/dedx/dedx4particle/dedx_mean_helium3.dat");
	GetAntiExpext2(buff,AntiHe3);
	SetErr(AntiHe3);
	SetTH1Style(AntiHe3,21,46,marksize);
	AntiHe3->Draw("P same");



}