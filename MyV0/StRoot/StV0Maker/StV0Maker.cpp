#include <iostream>

#include "TFile.h"
#include "TH1.h"
#include "TH2.h"
#include "TObjArray.h"
#include "TTree.h"

#include "StDcaGeometry.h"
#include "StMessMgr.h"

#include "StDcaService.h"
#include "StV0Maker.h"

#define XIAOHAI
#ifndef XIAOHAI
#  include "StBTofUtil/tofPathLength.hh"
#  include "StEvent/StBTofHeader.h"
#  include "StMuDSTMaker/COMMON/StMuBTofHit.h"
#  include "StMuDSTMaker/COMMON/StMuBTofPidTraits.h"  //TOF Info.
#  include "StMuDSTMaker/COMMON/StMuDstMaker.h"
#  include "StMuDSTMaker/COMMON/StMuEvent.h"
#  include "StMuDSTMaker/COMMON/StMuTrack.h"
#  include "StStrangeMuDstMaker/StStrangeMuDstMaker.h"
#  include "StStrangeMuDstMaker/StV0MuDst.hh"
#  include "StarClassLibrary/PhysicalConstants.h"
#  include "StarClassLibrary/SystemOfUnits.h"
#else
#  include "COMMON/StMuBTofHit.h"
#  include "COMMON/StMuBTofPidTraits.h"
#  include "COMMON/StMuDstMaker.h"
#  include "COMMON/StMuEvent.h"
#  include "COMMON/StMuTrack.h"
#  include "StStrangeMuDstMaker.h"
#  include "StV0MuDst.hh"
#  include "tofPathLength.hh"
#endif

StV0Maker::StV0Maker(StMuDstMaker *maker, const char *name) : StMaker(name) {
  muDstMaker = maker;
}

StV0Maker::~StV0Maker() {
}

int StV0Maker::Init() {
  initConst();
  initParameter();

  if (histOutputFileName == "") {
    std::cout << "StV0Maker: Please specify the histrogram output file." << std::endl;
    exit(-1);
  } else {
    histOutputFile = new TFile(histOutputFileName, "recreate");
  }
  initHist();

  if (v0TreeOutputFileName == "") {
    std::cout << "StV0Maker: The V0 tree output file is not specified! output is smeared!" << std::endl;
  } else {
    v0TreeOutputFile = new TFile(v0TreeOutputFileName, "recreate");
  }
  initTree();

  vecFirstDaughter.clear();
  vecSecondDaughter.clear();
  vecFirstDaughterDCA.clear();
  vecSecondDaughterDCA.clear();
  vecFirstDaughterZ.clear();
  vecSecondDaughterZ.clear();
  vecFirstDaughterMass.clear();
  vecSecondDaughterMass.clear();
  vecFirstDaughterBeta.clear();
  vecSecondDaughterBeta.clear();
  vecFirstDaughterDifferenceInverseBeta.clear();
  vecSecondDaughterDifferenceInverseBeta.clear();

  return 0;
}

ClassImp(StV0Maker)
