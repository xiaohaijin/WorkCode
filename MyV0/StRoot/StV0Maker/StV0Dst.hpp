#ifndef STV0DST_HPP
#define STV0DST_HPP

const int MAX_NUM_V0 = 3000;

class StV0Dst {
 public:
  int referenceMultiplicity;
  double primaryVertexX;
  double primaryVectexY;
  double primaryVectexZ;
  double vpdVertexZ;
  double magnetic;
  int numV0;
  long int eventId;
  long int runId;

  double v0Mass[MAX_NUM_V0];
  double v0Pt[MAX_NUM_V0];
  double v0Rapidity[MAX_NUM_V0];
  double v0Eta[MAX_NUM_V0];

  double v0X[MAX_NUM_V0];
  double v0Y[MAX_NUM_V0];
  double v0Z[MAX_NUM_V0];

  double v0Px[MAX_NUM_V0];
  double v0Py[MAX_NUM_V0];
  double v0Pz[MAX_NUM_V0];

  double v0PathX[MAX_NUM_V0];
  double v0PathY[MAX_NUM_V0];
  double v0PathZ[MAX_NUM_V0];

  double v0PathPx[MAX_NUM_V0];
  double v0PathPy[MAX_NUM_V0];
  double v0PathPz[MAX_NUM_V0];

  double v0DecayLenght[MAX_NUM_V0];
  double v0DecaylenH[MAX_NUM_V0];  //????????????
  double v0DCA[MAX_NUM_V0];
  double v0CoordinateDotMomentum[MAX_NUM_V0];
  double v0SinTheta[MAX_NUM_V0];
  double v0Theta[MAX_NUM_V0];
  double DCAFirstToSecond[MAX_NUM_V0];

  /*! The information of first daughter particle */
  int firstDaughterId[MAX_NUM_V0];
  double firstDaughterDCA[MAX_NUM_V0];
  double firstDaughterNSigma[MAX_NUM_V0];

  int firstDaughterNumberHitsFit[MAX_NUM_V0];
  int firstDaughterNumberHitsdEdx[MAX_NUM_V0];
  int firstDaughterNumberHitsPossible[MAX_NUM_V0];

  double firstDaughterMass[MAX_NUM_V0];
  double firstDaughterEta[MAX_NUM_V0];
  double firstDaughterPt[MAX_NUM_V0];
  double firstDaughterPx[MAX_NUM_V0];
  double firstDaughterPy[MAX_NUM_V0];
  double firstDaughterPz[MAX_NUM_V0];
  double firstDaughterBeta[MAX_NUM_V0];

  double firstDaughterdEdx[MAX_NUM_V0];
  double firstDaughterZ[MAX_NUM_V0];

  double firstDaughterDifferenceInverseBeta[MAX_NUM_V0];
  double firstDaughterTOFLocayY[MAX_NUM_V0];
  double firstDaughterTOFLocayZ[MAX_NUM_V0];

  /*! The information of second daughter particle */
  int secondDaughterId[MAX_NUM_V0];
  double secondDaughterDCA[MAX_NUM_V0];
  double secondDaughterNSigma[MAX_NUM_V0];

  int secondDaughterNumberHitsFit[MAX_NUM_V0];
  int secondDaughterNumberHitsdEdx[MAX_NUM_V0];
  int secondDaughterNumberHitsPossible[MAX_NUM_V0];

  double secondDaughterMass[MAX_NUM_V0];
  double secondDaughterEta[MAX_NUM_V0];
  double secondDaughterPt[MAX_NUM_V0];
  double secondDaughterPx[MAX_NUM_V0];
  double secondDaughterPy[MAX_NUM_V0];
  double secondDaughterPz[MAX_NUM_V0];
  double secondDaughterBeta[MAX_NUM_V0];

  double secondDaughterdEdx[MAX_NUM_V0];
  double secondDaughterZ[MAX_NUM_V0];

  double secondDaughterDifferenceInverseBeta[MAX_NUM_V0];
  double secondDaughterTOFLocayY[MAX_NUM_V0];
  double secondDaughterTOFLocayZ[MAX_NUM_V0];
};

#endif  // STV0DST_HPP
