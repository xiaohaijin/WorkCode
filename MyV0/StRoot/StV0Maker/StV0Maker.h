#ifndef STV0MAKER_H
#define STV0MAKER_H

#include "TString.h"

#include "StMaker.h"
#include "StPhysicalHelixD.hh"
#include "StThreeVectorD.hh"

#include "StV0Dst.hpp"
#include "StV0Type.hpp"

class TFile;
class TTree;
class TH1D;
class TH2D;

class StMuDstMaker;
class StMuTrack;

class StV0Maker : public StMaker {
 public:
  ClassDef(StV0Maker, 1)

      StV0Maker(StMuDstMaker *maker, const char *name);
  virtual ~StV0Maker();

  virtual int Init() override;
  virtual int Make() override;
  virtual int Finish() override;

  void setHistogramFileName(const TString fileName);
  void setV0TreeFileName(const TString fileName);
  void setV0Type(StV0Type v0Type);
  void setRotate(bool rotate);
  void setSameSignPlus(bool value);
  void setSameSignMinus(bool value);
  const StV0Dst &getV0Dst() const;
  bool getPassEventCut() const;
  StPhysicalHelixD RotHelix(StPhysicalHelixD Helix, StThreeVectorD Pv, double degree, double magn, int charge);
  int index_for_p(float);

 private:
  void initParameter();
  void initConst();
  void initHist();
  void initTree();

  enum { NUMBERDEDXVALUE = 11901 };

  StMuDstMaker *muDstMaker;
  StV0Type v0Type = StV0Type::kLambda;

  bool rotate = false;
  bool sameSignPlus = false;
  bool sameSignMinus = false;
  bool DcaAlgorithmLong = false;

  double v0Mass;
  double firstDaughterMass;
  double secondDaughterMass;

  int v0Charge;
  int firstDaughterCharge;
  int secondDaughterCharge;

  double cutAbsVertexZLess;
  int cutNumberHitsGreat;
  int cutNumberHitsdEdxGreat;
  double cutPtGreat;

  double cutAbsNSigma2Less;
  double cutFirstDaughterDCAGreat;
  double cutSecondDaughterDCAGreat;

  double cutDCAFirstDaughterToSecondDaughterLess;
  double cutV0MassWidthLess;
  double cutDaughterPtArmLess;

  double cutAbsDaughtersPtShoulderDifferenceLess;
  double cutFirstDaughterDecayAngleGreat;
  double cutSecondDaughterDecayAngleGreat;
  double cutV0CoordinateDotMomentumGreat;
  double cutV0DCALess;
  double cutV0DecayLengthGreat;

  double cutDau1Dau2Ang3DLe;  ////????????????
  double cutFirstAndSecondDaughterDipAngleDifferenceLess;

  double rotateDegree;

  /*! histograms */
  TH1D *histPrimaryVertex;
  TH1D *histVertexZ;
  TH1D *histVertexZDifference;
  TH1D *histReferenceMultiplicity;
  TH1D *histMagneticField;

  TH2D *histProntonNSigma;
  TH2D *histPionNSigma;
  TH2D *histKaonNSigma;

  TH2D *histdEdxP;
  TH2D *histDcaP;
  TH2D *histMassP;
  TH2D *histInvBetaP;

  TH2D *histFirstDaughterdEdx;
  TH2D *histSecondDaughterdEdx;
  TH2D *histFirstDaughterZ;
  TH2D *histSecondDaughterZ;
  TH2D *histFirstDaughterMass;
  TH2D *histSecondDaughterMass;

  TH2D *histdau1InvBetaP;
  TH2D *histdau2InvBetaP;
  TH2D *histdau1DiffInvBetaP;
  TH2D *histdau2DiffInvBetaP;

  TH1D *histInvMass;

  double dEdx_firstDaughter_theory[NUMBERDEDXVALUE];
  double dEdx_secondDaughter_theory[NUMBERDEDXVALUE];

  /*! files and tree */
  TString histOutputFileName = "";
  TFile *histOutputFile = nullptr;
  TString v0TreeOutputFileName = "";
  TFile *v0TreeOutputFile = nullptr;

  TTree *v0Tree = nullptr;
  StV0Dst *v0Dst;

  /// ?????????????
  int eventsProcessed = 0;
  double testVz = 0.;
  int testNTrack = 0;
  bool passEventCut;

  std::vector<StMuTrack *> vecFirstDaughter;
  std::vector<StMuTrack *> vecSecondDaughter;
  std::vector<double> vecFirstDaughterDCA;
  std::vector<double> vecSecondDaughterDCA;
  std::vector<double> vecFirstDaughterZ;
  std::vector<double> vecSecondDaughterZ;
  std::vector<double> vecFirstDaughterMass;
  std::vector<double> vecSecondDaughterMass;
  std::vector<double> vecFirstDaughterBeta;
  std::vector<double> vecSecondDaughterBeta;
  std::vector<double> vecFirstDaughterDifferenceInverseBeta;
  std::vector<double> vecSecondDaughterDifferenceInverseBeta;
};

#endif  // STV0MAKER_H
