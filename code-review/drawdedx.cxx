#include<iostream>
#include<cstring>
#include<TFile.h>
#include<TH1F.h>
#include<TGraph.h>

using namespace std;

void drawdedx()
{
  gStyle->SetOptStat(0);
  gStyle->SetOptTitle(0);

  TFile *input = new TFile("deuteron.histo.root","read");

  TH2F *h2 = 0;
  input->GetObject("dEdxP",h2);

  //	h2->Rebin2D(1,2);

  h2->GetYaxis()->SetRangeUser(0,40);
  h2->GetXaxis()->SetRangeUser(-3.0,3.0);

  // float factor = 1.0E6;//This parameter is for changing the unit of energy loss.
  float factor = 1.0;

  //=======================Don't change the following code=================================
  //Read dE/dx rootfile
  TFile *pioninput      = new TFile("./dedx/TGBichselpi.root","read");
  TFile *kaoninput      = new TFile("./dedx/TGBichselk.root","read");
  TFile *protoninput    = new TFile("./dedx/TGBichselp.root","read");
  TFile *deuteroninput  = new TFile("./dedx/TGBichseld.root","read");
  TFile *tritoninput    = new TFile("./dedx/TGBichselt.root","read");
  TFile *he3input       = new TFile("./dedx/TGBichselhe3.root","read");
  TFile *he4input       = new TFile("./dedx/TGBichselhe4.root", "read");
  TFile *he6input       = new TFile("./dedx/TGBichselhe6.root", "read");
  TFile *li6input       = new TFile("./dedx/TGBichselli6.root", "read");

  TGraph *temppioncurve     = 0;
  TGraph *tempkaoncurve     = 0;
  TGraph *tempprotoncurve   = 0;
  TGraph *tempdeuteroncurve = 0;
  TGraph *temptritoncurve   = 0;
  TGraph *temphe3curve      = 0;
  TGraph *temphe4curve      = 0;
  TGraph *temphe6curve      = 0;
  TGraph *templi6curve      = 0;

  //Read dE/dx theoretical values.
  pioninput         ->GetObject("Graph",temppioncurve);
  kaoninput         ->GetObject("Graph",tempkaoncurve);
  protoninput       ->GetObject("Graph",tempprotoncurve);
  deuteroninput     ->GetObject("Graph",tempdeuteroncurve);
  tritoninput       ->GetObject("Graph",temptritoncurve);
  he3input          ->GetObject("Graph",temphe3curve);
  he4input          ->GetObject("Graph",temphe4curve);
  he6input          ->GetObject("Graph",temphe6curve);
  li6input          ->GetObject("Graph",templi6curve);

  	// cout<<pioncurve      ->GetN()<<endl;
  	// cout<<kaoncurve      ->GetN()<<endl;
  	// cout<<protoncurve    ->GetN()<<endl;
  	// cout<<deuteroncurve  ->GetN()<<endl;
  	// cout<<tritoncurve    ->GetN()<<endl;
  	// cout<<he3curve       ->GetN()<<endl;

  Double_t pionpointx[11901];
  Double_t kaonpointx[11901];
  Double_t protonpointx[11901];
  Double_t deuteronpointx[11901];
  Double_t tritonpointx[11901];
  Double_t he3pointx[11901];
  Double_t he4pointx[11901];
  Double_t he6pointx[11901];
  Double_t li6pointx[11901];
  Double_t pionpointy[11901];
  Double_t kaonpointy[11901];
  Double_t protonpointy[11901];
  Double_t deuteronpointy[11901];
  Double_t tritonpointy[11901];
  Double_t he3pointy[11901];
  Double_t he4pointy[11901];
  Double_t he6pointy[11901];
  Double_t li6pointy[11901];

  //Read the dE/dx information to arrays.
  for(int i=0;i<temppioncurve->GetN();i++){temppioncurve->GetPoint(i,pionpointx[i],pionpointy[i]);}
  for(int i=0;i<tempkaoncurve->GetN();i++){tempkaoncurve->GetPoint(i,kaonpointx[i],kaonpointy[i]);}
  for(int i=0;i<tempprotoncurve->GetN();i++){tempprotoncurve->GetPoint(i,protonpointx[i],protonpointy[i]);}
  for(int i=0;i<tempdeuteroncurve->GetN();i++){tempdeuteroncurve->GetPoint(i,deuteronpointx[i],deuteronpointy[i]);}
  for(int i=0;i<temptritoncurve->GetN();i++){temptritoncurve->GetPoint(i,tritonpointx[i],tritonpointy[i]);}
  for(int i=0;i<temphe3curve->GetN();i++){temphe3curve->GetPoint(i,he3pointx[i],he3pointy[i]);}
  for(int i=0;i<temphe4curve->GetN();i++){temphe4curve->GetPoint(i,he4pointx[i],he4pointy[i]);}
  for(int i=0;i<temphe6curve->GetN();i++){temphe6curve->GetPoint(i,he6pointx[i],he6pointy[i]);}
  for(int i=0;i<templi6curve->GetN();i++){templi6curve->GetPoint(i,li6pointx[i],li6pointy[i]);}

  //Change the dE/dx unit.(GeV/cm or keV/cm)
  for(int i=0;i<11901;i++)
    {
      pionpointy[i]         = factor*pionpointy[i];
      kaonpointy[i]         = factor*kaonpointy[i];
      protonpointy[i]       = factor*protonpointy[i];
      deuteronpointy[i]     = factor*deuteronpointy[i];
      tritonpointy[i]       = factor*tritonpointy[i];
      he3pointy[i]          = factor*he3pointy[i];
      he4pointy[i]          = factor*he4pointy[i];
      he6pointy[i]          = factor*he6pointy[i];
      li6pointy[i]          = factor*li6pointy[i];
    }

  //Recreate the curve with new unit.
  TGraph *pioncurve     = new TGraph(temppioncurve->GetN(),pionpointx,pionpointy);
  TGraph *kaoncurve     = new TGraph(tempkaoncurve->GetN(),kaonpointx,kaonpointy);
  TGraph *protoncurve   = new TGraph(tempprotoncurve->GetN(),protonpointx,protonpointy);
  TGraph *deuteroncurve = new TGraph(tempdeuteroncurve->GetN(),deuteronpointx,deuteronpointy);
  TGraph *tritoncurve   = new TGraph(temptritoncurve->GetN(),tritonpointx,tritonpointy);
  TGraph *he3curve      = new TGraph(temphe3curve->GetN(),he3pointx,he3pointy);
  TGraph *he4curve      = new TGraph(temphe4curve->GetN(),he4pointx,he4pointy);
  TGraph *he6curve      = new TGraph(temphe6curve->GetN(),he6pointx,he6pointy);
  TGraph *li6curve      = new TGraph(templi6curve->GetN(),li6pointx,li6pointy);

  //Create the curve for negative side.
  for(int i=0;i<temppioncurve->GetN();i++){ pionpointx[i] = -1.0 * pionpointx[i];}
  for(int i=0;i<tempkaoncurve->GetN();i++){ kaonpointx[i] = -1.0 * kaonpointx[i];}
  for(int i=0;i<tempprotoncurve->GetN();i++){ protonpointx[i] = -1.0 * protonpointx[i];}
  for(int i=0;i<tempdeuteroncurve->GetN();i++){ deuteronpointx[i] = -1.0 * deuteronpointx[i];}
  for(int i=0;i<temptritoncurve->GetN();i++){ tritonpointx[i] = -1.0 * tritonpointx[i];}
  for(int i=0;i<temphe3curve->GetN();i++){ he3pointx[i] = -1.0 * he3pointx[i];}
  for(int i=0;i<temphe4curve->GetN();i++){ he4pointx[i] = -1.0 * he4pointx[i];}
  for(int i=0;i<temphe6curve->GetN();i++){ he6pointx[i] = -1.0 * he6pointx[i];}
  for(int i=0;i<templi6curve->GetN();i++){ li6pointx[i] = -1.0 * li6pointx[i];}

  TGraph *antipioncurve     = new TGraph(temppioncurve->GetN(),pionpointx,pionpointy);
  TGraph *antikaoncurve     = new TGraph(tempkaoncurve->GetN(),kaonpointx,kaonpointy);
  TGraph *antiprotoncurve   = new TGraph(tempprotoncurve->GetN(),protonpointx,protonpointy);
  TGraph *antideuteroncurve = new TGraph(tempdeuteroncurve->GetN(),deuteronpointx,deuteronpointy);
  TGraph *antitritoncurve   = new TGraph(temptritoncurve->GetN(),tritonpointx,tritonpointy);
  TGraph *antihe3curve      = new TGraph(temphe3curve->GetN(),he3pointx,he3pointy);
  TGraph *antihe4curve      = new TGraph(temphe4curve->GetN(),he4pointx,he4pointy);
  TGraph *antihe6curve      = new TGraph(temphe6curve->GetN(),he6pointx,he6pointy);
  TGraph *antili6curve      = new TGraph(templi6curve->GetN(),li6pointx,li6pointy);

  //set draw style.

  h2->GetYaxis()->SetTitle("#LTdE/dx#GT (keV/cm)");
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

  pioncurve          ->SetLineColor(810);
  kaoncurve          ->SetLineColor(810);
  protoncurve        ->SetLineColor(810);
  deuteroncurve      ->SetLineColor(810);
  tritoncurve        ->SetLineColor(810);
  he3curve           ->SetLineColor(810);
  he4curve           ->SetLineColor(810);
  he6curve           ->SetLineColor(810);
  li6curve           ->SetLineColor(810);
  antipioncurve      ->SetLineColor(810);
  antikaoncurve      ->SetLineColor(810);
  antiprotoncurve    ->SetLineColor(810);
  antideuteroncurve  ->SetLineColor(810);
  antitritoncurve    ->SetLineColor(810);
  antihe3curve       ->SetLineColor(810);
  antihe4curve       ->SetLineColor(810);
  antihe6curve       ->SetLineColor(810);
  antili6curve       ->SetLineColor(810);
  pioncurve          ->SetLineWidth(1);
  kaoncurve          ->SetLineWidth(1);
  protoncurve        ->SetLineWidth(1);
  deuteroncurve      ->SetLineWidth(1);
  tritoncurve        ->SetLineWidth(1);
  he3curve           ->SetLineWidth(1);
  he4curve           ->SetLineWidth(1);
  he6curve           ->SetLineWidth(1);
  li6curve           ->SetLineWidth(1);
  antipioncurve      ->SetLineWidth(1);
  antikaoncurve      ->SetLineWidth(1);
  antiprotoncurve    ->SetLineWidth(1);
  antideuteroncurve  ->SetLineWidth(1);
  antitritoncurve    ->SetLineWidth(1);
  antihe3curve       ->SetLineWidth(1);
  antihe4curve       ->SetLineWidth(1);
  antihe6curve       ->SetLineWidth(1);
  antili6curve       ->SetLineWidth(1);

  h2->Draw("colz");
  pioncurve          ->Draw("same");
  kaoncurve          ->Draw("same");
  protoncurve        ->Draw("same");
  deuteroncurve      ->Draw("same");
  tritoncurve        ->Draw("same");
  he3curve           ->Draw("same");
  he4curve           ->Draw("same");
  //he6curve           ->Draw("same");
  //li6curve           ->Draw("same");
  antipioncurve      ->Draw("same");
  antikaoncurve      ->Draw("same");
  antiprotoncurve    ->Draw("same");
  antideuteroncurve  ->Draw("same");
  antitritoncurve    ->Draw("same");
  //antihe3curve       ->Draw("same");
  //antihe4curve       ->Draw("same");
  //antihe6curve       ->Draw("same");
  //antili6curve       ->Draw("same");

  //Create the latex for each particels.
  TLatex *lat = new TLatex();
  lat->SetNDC();
  lat->SetTextFont(42);
  lat->SetTextSize(0.070);
  lat->SetTextColor(kBlack);

  lat->DrawLatex(0.5183284,0.138088,"#pi^{+}");
  lat->DrawLatex(0.526393,0.2063733,"K^{+}");
  lat->DrawLatex(0.5461877,0.3201821,"p");
  lat->DrawLatex(0.5975073,0.2867982,"d");
  lat->DrawLatex(0.5975073,0.5417299,"t");
  lat->DrawLatex(0.6195015,0.4597876,"^{3}He");
  lat->DrawLatex(0.6282991,0.6009105,"^{4}He");
  //lat->DrawLatex(0.73, 0.5431998, "^{6}He");
  //lat->DrawLatex(0.78, 0.71998, "^{6}Li ?");

  lat->DrawLatex(0.4545455,0.1335357,"#pi^{-}");
  lat->DrawLatex(0.4501466,0.2048558,"K^{-}");
  lat->DrawLatex(0.4391496,0.3110774,"#bar{p}");
  lat->DrawLatex(0.3826979,0.276176,"#bar{d}");
  lat->DrawLatex(0.3922287,0.5311077,"#bar{t}");
  //lat->DrawLatex(0.3115836,0.4415781,"{}^{3}#bar{He}");
  //lat->DrawLatex(0.3211144,0.599393,"^{4}#bar{He}");

  TBox *box = new TBox(-0.15,2,0.15,39.99);
  box->SetFillColor(kWhite);
  box->Draw("same");
}
