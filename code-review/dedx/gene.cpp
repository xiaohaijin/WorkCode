#include "TAxis.h"
#include "TArrow.h"
#include "TAttFill.h"
#include "TBranch.h"
#include "TCanvas.h"
#include "TChain.h"
#include "TColor.h"
#include "TDirectory.h"
#include "TF1.h"
#include "TF2.h"
#include "TFile.h"
#include "TGraph.h"
#include "TGraphErrors.h"
#include "TH1.h"
#include "TH1D.h"
#include "TH2.h"
#include "TH2D.h"
#include "TH3.h"
#include "TH3D.h"
#include "TLatex.h"
#include "TLeaf.h"
#include "TLegend.h"
#include "TLine.h"
#include "TMarker.h"
#include "TMath.h"
#include "TNamed.h"
#include "TPad.h"
#include "TProfile.h"
#include "TRandom.h"
#include "TSpectrum.h"
#include "TStyle.h"
#include "TTree.h"

using namespace std;

int gene()
{
  TFile *file = new TFile("TGBichselhe4.root", "recreate");
  double x[11901];
  double y[11901];

  ifstream input("./dedx_mean_He4.dat");
  if(!input.good()){
    cerr << "open errrrrrror";
    return 0;
  }

  double tempX = 0.;
  double tempY = 0.;

  for(int i = 0; i != 11901; ++i){
    input >> tempX >> tempY;
    x[i] = tempX;
    y[i] = tempY;
  }

  TGraph *Graph = new TGraph(11901, x, y);
  Graph->Write();
  
  return 0;
}
