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

int get()
{
  TFile *file = new TFile("./TGBichselhe4.root");
  TGraph *old = static_cast<TGraph*>(file->Get("Graph"));
  ofstream output("./dedx_mean_He4.dat");
  
  const int MAXVALUE = 11901;

  for(int i = 0; i != MAXVALUE; ++i){
    output << old->GetX()[i]  << "    " << old->GetY()[i] * 1.0e-6 << "\n";
  }
  return 0;
}
